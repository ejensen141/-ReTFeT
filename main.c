/*
 *  Copyright (c) Elijah Jensen 2015. All Rights Reserved.
 *  See LICENSE file (MIT).
 *  ReTFeT/main.c
 */


#include "numc.h"
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <time.h>


const double TwoPi = 6.283185307179586;
const double pi = 3.141592;


void computeDFT(double *x, double complex *X, int N)
{
int n =0;
double constant = -1*TwoPi/N;

do{


	for ( int k =0; k<N/2; k++)
	{
		X[k] = X[k] + x[n]*cexp(constant*k*n*I);
	}

	n++;
	}while(n<N);


}


int main()
{

	// Define memory
	int N = 2048;
	double  *x = zeros(N);
	double complex *X = zeros(N);


//Define the signal here (for testing purposes only)
	FILE * fs = fopen("signal.dat","w");

	for ( int i =0; i<N; i++)
	{
		x[i] = 0.5*cos(2*pi*i/50.0) + 0.5*sin(2*pi*i/60.0);
		// test signal ... two out of phase (90 degree) signals at different frequencies.

		fprintf(fs,"%f \n", x[i]); // save to file

	}
	fclose(fs);


	computeDFT(x,X,N); // run transform


	FILE *fp;
	fp = fopen("data.dat","w");



	for ( int i =0; i<N/2; i++)
	{
	// compute magnitude and output to file
	fprintf(fp,"%f \n", sqrt(creal(X[i])*creal(X[i]) + cimag(X[i])*cimag(X[i])));

	}
	fclose(fp);


return 0;
}










