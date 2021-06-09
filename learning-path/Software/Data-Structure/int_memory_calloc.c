#include <stdio.h>
#include <stdlib.h>

#define NULL 0

/*
 * OBSERVATION: Using calloc the memory allocated contains the value zero
 */

void main(){
    int i, n, sum;

    //Allocating memory space for two-integer pointers variable
    int *ptr, *ele;
    printf("\nEnter the number of the element(s) to be added = ");
    scanf("%d", &n); //Enter the number of elements

    //Allocating memory space for n integers of int type to *ptr
    ptr = (int *) calloc(n, sizeof(int));

    //Checking whether the memory is allocated successfully
    if(ptr == NULL) {
        printf("\n\nMemory allocation is failed!");
        exit(0);
    }

    //Reading the elements to the pointer variable *ele
    for(ele=ptr, i=1; ele<(ptr+n); ele++,i++) {
        printf("Enter the %d element: ", i);
        scanf("%d", ele);
    }

    //Finding the sum of n elements
    for(ele=ptr, sum=0; ele<(ptr+n); ele++) {
        sum = sum+(*ele);
    }

    printf("\n\nThe SUM of no(s) is = %d\n\n", sum);

    //Deallocating the memory
    free(ptr); 
    exit(0);
}