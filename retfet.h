#ifndef _ReTFeT
#define _ReTFeT

#include "numc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



const double TwoPi = 6.283185307179586;
const double pi = 3.141592653589793238;
     

void computeDFT(double *x, double complex *X, int N, int start, int end)
{
double *Xr=zeros(N);
double *Xi=zeros(N);


int n =0; 
double constant = -1*TwoPi/N;


	do{
	for ( int k =start; k<end; k++)
	{
		Xr[k] = Xr[k] +  x[n]*cos(constant*k*n);
		Xi[k]= Xi[k] + x[n]*sin(constant*k*n);
		
		X[k] = sqrt(Xr[k]*Xr[k] + Xi[k]*Xi[k]);
	}
	
	n++;
	}while(n<N);
}


inline void RTDFTest(double x, double complex *X, int N,int n)
{
double constant = -1*TwoPi/N;	
	for ( int k =0; k<N/2; k++)
	{
		X[k] = X[k] + x*cexp(constant*k*n*I);
	}
}


void RTDFT(double *x, double *X, int N, int start, int end)
{
double *Xr=zeros(N);
double *Xi=zeros(N);


int n =0; 
double constant = -1*TwoPi/N;


	do{
	for ( int k =start; k<end; k++)
	{
		Xr[k] = Xr[k] +  x[n]*cos(constant*k*n);
		Xi[k]= Xi[k] + x[n]*sin(constant*k*n);
		
		X[k] = sqrt(Xr[k]*Xr[k] + Xi[k]*Xi[k]);
	}
	
	n++;
	}while(n<N);


}




















#endif
