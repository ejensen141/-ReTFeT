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
#include "retfet.h"

void signalgen()
{

int N = 20000;

FILE * fp = fopen("signal.out","w");

for(int i =0; i<N; i++)
{

fprintf(fp,"%f \n", 2*sin(i*1/10.0)+sin(i*10)+sin(i/1.0));


}

fclose(fp);

}






int main(int argc, char * argv[])
{



	signalgen();

	// Define memory
	int N = 2048;

	double  *x = zeros(N);
	double  *X = zeros(N);

	char buff[255];
//Define the signal here (for testing purposes only) 
	FILE * fs = fopen(argv[1],"r");
	
	if(fs)
	
	{
	for ( int i =0; i<N; i++)
	{
	//	x[i] = 0.5*cos(2*pi*i/50.0) + 0.5*sin(2*pi*i/60.0); 
		// test signal ... two out of phase (90 degree) signals at different frequencies. 
		
		//fprintf(fs,"%f \n", x[i]); // save to file
		
		fscanf(fs,"%s", buff);
		x[i] = atof(buff);
			
	}
	

	
	}
	
	fclose(fs);

	
	RTDFT(x,X,N,0,N/2); // run transform 
	
	



	//computeDFT(x,X,N); // run transform



	FILE *fp;
	fp = fopen("data.dat","w");



	for ( int i =0; i<N/2; i++)
	{


		fprintf(fp,"%f \n", X[i]);


	}
	fclose(fp);


return 0;
}










