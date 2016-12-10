#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SAMPLE_NUMBER 128 //16

struct quantization_info{

    int level_number;
    double *level;
    double level_amplitude;
    double decision_amplitude;
    double max_amplitude;
    int bit_number;

};

struct quantized_signal{

    double samples_dec[SAMPLE_NUMBER];
    int samples_hex[SAMPLE_NUMBER];

};

//FUNCTION THAT CREATES BASIC INFO ABOUT THE QUANTIZATION PROCESS
void quant_info_calculator(struct quantization_info *quant_info, double max_amplitude, int bit_number) {

    quant_info->level_number = pow(2, bit_number)-1; //because of the simetry aroud zero
    quant_info->level = (double *)malloc((quant_info->level_number)*sizeof(double));
    //the whole amplitude range divided by the number of levels minus one (because it is the distance between levels)
    quant_info->level_amplitude = (max_amplitude-(-max_amplitude))/((quant_info->level_number) - 1);
    quant_info->decision_amplitude = (quant_info->level_amplitude)/2;
    quant_info->max_amplitude = max_amplitude;
    quant_info->bit_number = bit_number;

};

//FUNCTION THAT CALCULATES THE QUANTIZATION LEVELS
void level_calculator (struct quantization_info *quant_info) {

    int i=0;
    FILE* levels_file;
    printf("level amplitude = %.18lf\n", (quant_info->level_amplitude));
    quant_info->level[0]=-(quant_info->max_amplitude);
    for (i=1; i<(quant_info->level_number); i++) {

        quant_info->level[i] = quant_info->level[i-1] + quant_info->level_amplitude;

    }

    levels_file = fopen("levels.txt", "w");
    if(levels_file==NULL) {

		printf("Error during the opening of file!\n");

	}
    for (i=0; i<quant_info->level_number; i++) {

        fprintf(levels_file, "level[%d]=%.18lf\n", i, quant_info->level[i]);
        fprintf(levels_file, "level[%d] in hex: %x\n", i, i);

    }

    fclose(levels_file);

}

//FUNCTION THAT QUANTIZES AND CODES THE SAMPLES (CODE - MOVED BINARY CODE)
void quantization_and_coding (struct quantized_signal *signal_q, double *signal, struct quantization_info *quant_info) {

    int i, j;

    for(i=0; i<SAMPLE_NUMBER; i++)
        for(j=0; j<quant_info->level_number; j++) {

            if(signal[i] <= (quant_info->level[j] + quant_info->decision_amplitude)){

                signal_q->samples_dec[i] = quant_info->level[j];
                signal_q->samples_hex[i] = j;
                break;

            }

        }

};

//FUNCTION THAT LOADS THE SIGNAL SAMPLES FROM A FILE
void signal_loader (double * signal) {

	FILE *signal_file;
    int i;

    signal_file = fopen("signal.txt", "r");

    for(i = 0; i < SAMPLE_NUMBER; i++){

        fscanf(signal_file, "%lf", &signal[i]);
        //printf("Signal[%d]=%.15f\n", i, signal[i]);

        if(i>=SAMPLE_NUMBER) {
			printf("Too much signal samples!\n");
			break;

		}
    }

    fclose(signal_file);

}

//FUNCTION THAT PRINTS QUANTIZED SAMPLES INTO A FILE
void quantized_signal_printer (struct quantized_signal *signal_q) {

	FILE* quantized_signal_file;

	quantized_signal_file = fopen("quantized_signal.txt", "w");

    if(quantized_signal_file==NULL) {

		printf("Error during the opening of file!\n");

	}

	int i;

    for (i=0; i<SAMPLE_NUMBER; i++) {

        fprintf(quantized_signal_file, "quantized_sample[%d]=%.18lf\n", i, signal_q->samples_dec[i]);
        fprintf(quantized_signal_file, "quantized_sample[%d] in hex: %x\n", i, signal_q->samples_hex[i]);

    }

    fclose(quantized_signal_file);


}

int main()
{
    struct quantization_info *q_info = malloc(sizeof(struct quantization_info));
    quant_info_calculator(q_info, 0.842982750824474, 8);
    level_calculator(q_info);

    double signal[SAMPLE_NUMBER];
    signal_loader(signal);

    struct quantized_signal *signal_quant = malloc(sizeof(struct quantized_signal));
    quantization_and_coding(signal_quant, signal, q_info);

    quantized_signal_printer(signal_quant);

    free(q_info);
    free(signal_quant);

    return 0;
}
