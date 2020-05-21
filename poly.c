/*
 *File containing several functions to perform operations on the polynomial data structure
 *****************************************************************************
 * Author       Dept.           Date            Notes
 *****************************************************************************
 *Ben M         Soft Eng        Mar 30  2020    Began work on general structure
 *Ben M         Soft Eng	Mar 31  2020	Adjusted addpolyterm for improved case handling        
 *Ben M         Soft Eng	Mar 31  2020	Commenting and bug fixes 
*/

#include <stdio.h>
#include <stdlib.h>
#include "polyfunctions.h"

//global pointer to head of list
struct PolyTerm *head = NULL;

//structure of the polyterm
struct PolyTerm{
        int coeff;
        int expo;
        struct PolyTerm *next;
};

//method to add terms in order of exponent value
int addPolyTerm(int x, int exp){
	struct PolyTerm *newTerm = (struct PolyTerm *) malloc(sizeof(struct PolyTerm));
	//check for error
	if(newTerm == NULL) return -1;

	newTerm->coeff = x;
        newTerm->expo = exp;
	if(head == NULL){
		head = newTerm;
		return 0;
	}

	struct PolyTerm *curT, *nextT;
	int curExp;
	
	curT =  head;
	curExp = curT->expo;
	//check if new element is smallest
	if(exp < curExp){
		head = newTerm;
		head->next = curT;
		return 0;
	}	
	//special case for list size of 1
	if(curT->next == NULL){
		//check for dupicate exponent
		if(curT->expo == exp){
			curT->coeff += x;
			return 0;
		}	
		curT->next = newTerm;
		newTerm->next = NULL;
		return 0;
	}	

	nextT = curT->next;
	
	//iterate through list until correct place
	while(exp >= nextT->expo){
		//check for end of list	
		if(nextT->next == NULL){
			nextT->next = newTerm;
			newTerm->next = NULL;
			return 0;
		}
		//iterate down list	
		curT = nextT;
		nextT = nextT->next;
	}
	
	//check for dupliucate exponent
	if(exp == curT->expo){
		curT->coeff += x;
		return 0;
	}	
	curT->next = newTerm;
	newTerm->next = nextT;
	return 0;
}	


//displays the polynomial
void displayPolynomial(){
	struct PolyTerm *curT = head->next;
	
	//check for empty list
	if(head == NULL){
		printf("There is nothing to print\n");
		exit(-1);
	}	
	
	//print first element
	printf("%dx%d",head->coeff, head->expo);

	//iterate through list
	while(curT != NULL){
		if(curT->coeff >= 0) printf("+");
		printf("%dx%d",curT->coeff, curT->expo);
		curT = curT->next;
	}	
	//new line
	printf("\n");
}	

//evaluates the polynomial for an integer x
int evaluatePolynomial(int x){
	int result = 0;
	struct PolyTerm *curT = head;
	
	//iterate through list and incriment result
	while(curT != NULL){
		result += (curT->coeff * powi(x,curT->expo));
		curT=curT->next;
	}	
	return result;
}
