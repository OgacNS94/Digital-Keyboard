clear all;
clc;
%%%%%%%%%%%%%%%%%%%RZSDMK%%%%%%%%%%%%%%%%%%%%%

%DEFINING THE SIGNAL FOR ROM MEMORY

%Amplitude
A=0.5;
%Frequency, only for Matlab
fo=440;
fs=128*fo;
%number of signal samples that will be written into ROM, it has to satisfy
%the sampling theorem, in this case fs=128*fo, and the maximal frequency in
%the spectrum is 9*fo, hence fs>2*9*fo, so the sampling theorem is
%satisfied
n = 0:127;

x = A*sin(2*pi*(fo/fs)*n)+A/2*sin(2*pi*2*(fo/fs)*n)+A/3*sin(2*pi*3*(fo/fs)*n)+A/4*sin(2*pi*4*(fo/fs)*n)+...
    A/5*sin(2*pi*5*(fo/fs)*n)+A/6*sin(2*pi*6*(fo/fs)*n)+A/7*sin(2*pi*7*(fo/fs)*n)+A/8*sin(2*pi*8*(fo/fs)*n)+...
    A/9*sin(2*pi*9*(fo/fs)*n);

figure;
plot(x);

figure;
stem (0:127, x); %0:15

a= max(x);

save('signal.txt', 'x', '-ASCII', '-append');
