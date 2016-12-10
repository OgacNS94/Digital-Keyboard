#include <REGx52.h>
#include <intrins.h> //FOR NOP

#define C     P0_0
#define CIS   P0_1
#define D     P0_2
#define DIS   P0_3
#define E     P0_4
#define F     P0_5
#define FIS   P0_6
#define G     P0_7
#define GIS   P2_7
#define A     P2_6
#define AIS   P2_5
#define B     P2_4
#define H     P2_3
#define C2    P2_2
#define output P1

unsigned char i=0;
unsigned char p=0;
code unsigned char signal[128] = {0x7f, 0xa0, 0xbe, 0xd8, 0xec, 0xf8, 0xfe, 0xfd, 0xf8, 0xf0, 0xe6, 0xde, 
0xd6, 0xd2, 0xd0, 0xd1, 0xd3, 0xd6, 0xd8, 0xd9, 0xd8, 0xd6, 0xd2, 0xcd, 0xc8, 0xc3, 0xc0, 0xbd, 0xbc, 
0xbc, 0xbd, 0xbe, 0xbe, 0xbd, 0xbc, 0xb9, 0xb5, 0xb1, 0xad, 0xaa, 0xa7, 0xa5, 0xa4, 0xa4, 0xa4, 0xa4,
0xa4, 0xa3, 0xa1, 0x9e, 0x9a, 0x96, 0x93, 0x90, 0x8d, 0x8c, 0x8c, 0x8b, 0x8b, 0x8b, 0x8a, 0x88, 0x86, 
0x83, 0x7f, 0x7b, 0x78, 0x76, 0x74, 0x73, 0x73, 0x73, 0x72, 0x72, 0x71, 0x6e, 0x6b, 0x68, 0x64, 0x60, 
0x5d, 0x5b, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x59, 0x57, 0x54, 0x51, 0x4d, 0x49, 0x45, 0x42, 0x41, 0x40, 
0x40, 0x41, 0x42, 0x42, 0x41, 0x3e, 0x3b, 0x36, 0x31, 0x2c, 0x28, 0x26, 0x25, 0x26, 0x28, 0x2b, 0x2d, 
0x2e, 0x2c, 0x28, 0x20, 0x18, 0x0e, 0x06, 0x01, 0x00, 0x06, 0x12, 0x26, 0x40, 0x5e};

void Initialization(void) {

	P0=0xFF; // so that loading from this port could be possible
	P2=0xFF; // so that loading from this port could be possible

}

void main(void) {

	Initialization();

	while (1) {							 

		i=0;

		while (!C) {//asserted low!!!
				//The while loop lasts for 25 machine cycles, and for the C note and
				//fosc=18.432MHz => time before two samples has to be 46 machine cycles
				//		the NOP loop has to last 21 machine cycle

				
				if(i>127)
					i=0;
				else {
					_nop_();
					_nop_();
					_nop_();
					_nop_();
				}
				output = signal[i++];

				//NOP, MOV - ONE MACHINE CYCLE
				//DJNZ - TWO MACHINE CYCLES
				//46=25+21
				//21=1+4*5

				p = 5;

				_nop_ ();
				
				do {
				
					_nop_ ();
					_nop_ ();

				}while(--p);
		
		}

		
		while (!CIS) {//asserted low!!!
				//The while loop lasts for 25 machine cycles, and for the CIS note and
				//fosc=18.432MHz => time before two samples has to be 43 machine cycles
				//		the NOP loop has to last 18 machine cycles

				
				if(i>127)
					i=0;
				else {
					_nop_();
					_nop_();
					_nop_();
					_nop_();
				}
				output = signal[i++];

				//NOP, MOV - ONE MACHINE CYCLE
				//DJNZ - TWO MACHINE CYCLES
				//43=25+18
				//18=2+4*4

				p = 4;

				_nop_ ();
				_nop_ ();
				
				do {
				
					_nop_ ();
					_nop_ ();

				}while(--p);
		
		}

		while (!D) {//asserted low!!!
				//The while loop lasts for 25 machine cycles, and for the D note and
				//fosc=18.432MHz => time before two samples has to be 41 machine cycles
				//		the NOP loop has to last 16 machine cycles

				
				if(i>127)
					i=0;
				else {
					_nop_();
					_nop_();
					_nop_();
					_nop_();
				}
				output = signal[i++];

				//NOP, MOV - ONE MACHINE CYCLE
				//DJNZ - TWO MACHINE CYCLES
				//41=25+16
				//16=4*4

				p = 4;
				
				do {
				
					_nop_ ();
					_nop_ ();

				}while(--p);
		
		}

		while (!DIS) {//asserted low!!!
				//The while loop lasts for 25 machine cycles, and for the DIS note and
				//fosc=18.432MHz => time before two samples has to be 39 machine cycles
				//		the NOP loop has to last 14 machine cycles

				
				if(i>127)
					i=0;
				else {
					_nop_();
					_nop_();
					_nop_();
					_nop_();
				}
				output = signal[i++];

				//NOP, MOV - ONE MACHINE CYCLE
				//DJNZ - TWO MACHINE CYCLES
				//39=25+14
				//14=2+3*4

				p = 3;

				_nop_ ();
				_nop_ ();
				
				do {
				
					_nop_ ();
					_nop_ ();

				}while(--p);
		
		}

		while (!E) {//asserted low!!!
				//The while loop lasts for 25 machine cycles, and for the E note and
				//fosc=18.432MHz => time before two samples has to be 36 machine cycles
				//		the NOP loop has to last 11 machine cycles

				
				if(i>127)
					i=0;
				else {
					_nop_();
					_nop_();
					_nop_();
					_nop_();
				}
				output = signal[i++];

				//NOP, MOV - ONE MACHINE CYCLE
				//DJNZ - TWO MACHINE CYCLES
				//36=25+11
				//11=3+2*4

				p = 2;

				_nop_ ();
				_nop_ ();
				_nop_ ();
				
				do {
				
					_nop_ ();
					_nop_ ();

				}while(--p);
		
		}

		while (!F) {//asserted low!!!
				//The while loop lasts for 25 machine cycles, and for the F note and
				//fosc=18.432MHz => time before two samples has to be 34 machine cycles
				//		the NOP loop has to last 9 machine cycles

				
				if(i>127)
					i=0;
				else {
					_nop_();
					_nop_();
					_nop_();
					_nop_();
				}
				output = signal[i++];

				//NOP, MOV - ONE MACHINE CYCLE
				//DJNZ - TWO MACHINE CYCLES
				//34=25+9
				//9=1+2*4

				p = 2;

				_nop_ ();
				
				do {
				
					_nop_ ();
					_nop_ ();

				}while(--p);
		
		}

		while (!FIS) {//asserted low!!!
				//The while loop lasts for 25 machine cycles, and for the G note and
				//fosc=18.432MHz => time before two samples has to be 32 machine cycles
				//		the NOP loop has to last 7 machine cycles

				
				if(i>127)
					i=0;
				else {
					_nop_();
					_nop_();
					_nop_();
					_nop_();
				}
				output = signal[i++];

				//NOP, MOV - ONE MACHINE CYCLE
				//DJNZ - TWO MACHINE CYCLES
				//32=25+7
				//7=3+1*4

				p = 1;

				_nop_ ();
				_nop_ ();
				_nop_ ();
				
				do {
				
					_nop_ ();
					_nop_ ();

				}while(--p);
		
		}

		while (!G) {//asserted low!!!
				//The while loop lasts for 25 machine cycles, and for the G note and
				//fosc=18.432MHz => time before two samples has to be 31 machine cycles
				//		the NOP loop has to last 6 machine cycles

				
				if(i>127)
					i=0;
				else {
					_nop_();
					_nop_();
					_nop_();
					_nop_();
				}
				output = signal[i++];

				//NOP, MOV - ONE MACHINE CYCLE
				//DJNZ - TWO MACHINE CYCLES
				//31=25+6
				//6=2+1*4

				p = 1;

				_nop_ ();
				_nop_ ();
				
				do {
				
					_nop_ ();
					_nop_ ();

				}while(--p);
		
		}

		while (!GIS) {//asserted low!!!
				//The while loop lasts for 25 machine cycles, and for the GIS note and
				//fosc=18.432MHz => time before two samples has to be 29 machine cycles
				//		the NOP loop has to last 4 machine cycles

				
				if(i>127)
					i=0;
				else {
					_nop_();
					_nop_();
					_nop_();
					_nop_();
				}
				output = signal[i++];

				//NOP, MOV - ONE MACHINE CYCLE
				//DJNZ - TWO MACHINE CYCLES
				//29=25+4
				//4=0+1*4

				p = 1;

				do {
				
					_nop_ ();
					_nop_ ();

				}while(--p);
		
		}
		
		while (!A) {//asserted low!!!
				//The while loop lasts for 25 machine cycles, and for the A note and
				//fosc=18.432MHz => time before two samples has to be 27 machine cycles
				//		the NOP loop has to last 2 machine cycles

				
				if(i>127)
					i=0;
				else {
					_nop_();
					_nop_();
					_nop_();
					_nop_();
				}
				output = signal[i++];

				//NOP, MOV - ONE MACHINE CYCLE
				//DJNZ - TWO MACHINE CYCLES
				//27=23+2+2
				//2+2=1+1+1+1

			  	//two nops instead of p=0;
				_nop_ ();
				_nop_ ();

				_nop_ ();
				_nop_ ();

				//no do while loop 
		
		}

		while (!AIS) {//asserted low!!!
				//The while loop lasts for 25 machine cycles, and for the AIS note and
				//fosc=18.432MHz => time before two samples has to be 26 machine cycles
				//		the NOP loop has to last 1 machine cycles

				
				if(i>127)
					i=0;
				else {
					_nop_();
					_nop_();
					_nop_();
					_nop_();
				}
				output = signal[i++];

				//NOP, MOV - ONE MACHINE CYCLE
				//DJNZ - TWO MACHINE CYCLES
				//26=23+2+1
				//2+1=1+1+1

			  	//two nops instead of p=0;
				_nop_ ();
				_nop_ ();

				_nop_ ();

				//no do while loop 
		
		}

		while (!AIS) {//asserted low!!!
				//The while loop lasts for 25 machine cycles, and for the B note and
				//fosc=18.432MHz => time before two samples has to be 24 machine cycles
				//		the NOP loop has to last -1 machine cycles

				
				if(i>127)
					i=0;
				else {
					_nop_();
					_nop_();
					_nop_();
					_nop_();
				}
				output = signal[i++];

				//NOP, MOV - ONE MACHINE CYCLE
				//DJNZ - TWO MACHINE CYCLES
				//24=23+1
				//1=1

			  	//one nop instead of p=0; -> 2-1=1
				_nop_ ();

				//no do while loop 
		
		}

		while (!C2) {//asserted low!!!
				//The while loop lasts for 25 machine cycles, and for the C2 note and
				//fosc=18.432MHz => time before two samples has to be 23 machine cycles
				//		the NOP loop has to last -2 machine cycles

				
				if(i>127)
					i=0;
				else {
					_nop_();
					_nop_();
					_nop_();
					_nop_();
				}
				output = signal[i++];

				//NOP, MOV - ONE MACHINE CYCLE
				//DJNZ - TWO MACHINE CYCLES
				//23=23+0

			  	//no nops instead of p=0; 2-2=0

				//no do while loop 
		
		}

	};

}
