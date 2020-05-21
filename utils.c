/*
 *File containing several functions to be called in main program
 *****************************************************************************
 * Author       Dept.           Date            Notes
 *****************************************************************************
 *Ben M         Soft Eng        Mar 30  2020    Began work on general structure
 *Ben M         Soft Eng	Mar 31	2020	Wrote functionalities for both functions 
 *Ben M         Soft Eng 	Mar 31  2020	Commenting and bug fixes
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "polyfunctions.h"

void parse(char* string, int *a, int *b){
	char* coef = strtok(string, " ");
	char* exp = strtok(NULL, " ");
	int c,e;
	int *cp,*ep;
	if(sscanf(coef,"%d",&c)){
		cp = a;
		*cp = c;
	}	
	if(sscanf(exp,"%d",&e)){
		ep = b;
		*ep = e;
	}	
}

int powi(int x, int exp){
	int i = 0;
	int result = 1;

	while(i < exp){
		result *= x;
		i++;
	}	

	return result;
}
