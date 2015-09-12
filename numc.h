#ifndef _NUMC_H
#define _NUMC_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function for making an array and zeroing it

void * zeros(int N )
{
  void *var =(void*) calloc(N,sizeof(double));

return var;
}  // remember to call free(varname ) when done
//Usage:   double *A = zeros(100);


// Function for making an array
void * array(int N)
{
  void *var =(void*) malloc(N);

return var;
}  // remember to call free(varname ) when done
//Usage:   double *A = array(100);





//****************BEGIN VECTORS CODE*********************//

typedef struct
{
  double r;
  double phi;
  double theta;
}svect;


typedef struct
{

   double x;
	 double y;
	 double z;
   double t;
	 double r; // magnitude
	 double length;

}vect;


vect v_add(vect v1, vect v2)
{

vect v3;

v3.x = v1.x + v2.x;
v3.y = v1.y + v2.y;
v3.z = v1.z + v2.z;


return v3;
}



vect v_sub(vect v1, vect v2)  //v1-v2
{

vect v3;

v3.x = v1.x - v2.x;
v3.y = v1.y - v2.y;
v3.z = v1.z - v2.z;


return v3;
}


vect v_const(double constant, vect v1)
{

vect v3;

v3.x = v1.x*constant;
v3.y = v1.y*constant;
v3.z = v1.z*constant;


return v3;
}


vect v_eq(vect v1)
{

vect v3;

v3.x = v1.x;
v3.y = v1.y;
v3.z = v1.z;


return v3;
}


double v_dot(vect v1, vect v2)
{

double dot;

dot = v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;

return dot;
}

vect v_cross(vect v1,vect v2)
{
	vect output;

	output.x = (v1.y*v2.z - v2.y*v1.z);
	output.y = -1*(v1.x*v2.z - v2.x*v1.z);
	output.z = (v1.x*v2.y - v2.x*v1.y);


return output;
}

double v_mag(vect v1)
{

  return sqrt(v_dot(v1,v1));

}

// END VECTORS CODE ****************************//



#endif
