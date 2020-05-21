/*
 *Program to read and evaulate a polynomial
 *****************************************************************************
 * Author	Dept.		Date		Notes
 *****************************************************************************
 *Ben M		Soft Eng	Mar 30  2020	Began work on general structure
 *Ben M		Soft Eng	Mar 31  2020	Added file handling	
 *Ben M		Soft Eng 	Mar 31  2020	Bug fixes and commenting
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h> 
#include "polyfunctions.h"

int main(int argc, char* argv[]){
	if(argc == 1){
		printf("Error: no file provided\n");
		return -1;
	}	

	char *file = argv[1];
	FILE *polyFile = fopen(file,"r");
	if(!polyFile){
		printf("Error: invalid file\n");
		return -2;
	}	
	char curLine[1024];
	while(fgets(curLine,1024,polyFile) != NULL){
		int* coP = (int*)malloc(sizeof(int*));
		int* exP = (int*)malloc(sizeof(int*));
		parse(curLine,coP,exP);	
		addPolyTerm(*coP,*exP);
		free(coP);
		free(exP);
	}		
	fclose(polyFile);
	
	displayPolynomial();
	
	int x;
	for(x = -2; x < 3; x++){
		int y = evaluatePolynomial(x);
		printf("for x=%d, y=%d\n",x,y); 
	}	
	return 0;
}
