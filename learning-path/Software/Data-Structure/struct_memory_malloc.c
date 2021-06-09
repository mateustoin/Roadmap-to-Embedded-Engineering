#include <stdio.h>
#include <stdlib.h>

#define NULL 0

/*
 * OBSERVATION: Using malloc the memory allocated contains garbage values
 */

struct Employee {
	int Emp_Code;
    char Emp_Name[50];
    float Emp_Salary;
};

void main(){
    int i, n;

    //Allocating memory space for two-integer pointers variable
    struct Employee *ptr, *ele;
    printf("\nEnter the number of the employee(s) to be added = ");
    scanf("%d", &n); //Enter the number of elements

    //Allocating memory space for n integers of int type to *ptr
    ptr = (struct Employee *) malloc(n*sizeof(struct Employee));

    //Checking whether the memory is allocated successfully
    if(ptr == NULL) {
        printf("\n\nMemory allocation is failed!");
        exit(0);
    }

    //Reading the elements to the pointer variable *ele
    for(ele=ptr, i=1; ele<(ptr+n); ele++,i++) {
        printf("Enter the Employee n-%d code: ", i);
        scanf("%d", &(ele)->Emp_Code);
        printf("\nEnter the Employee n-%d name: ", i);
        scanf("%s", (ele)->Emp_Name);
        printf("\nEnter the Employee n-%d salary: ", i);
        scanf("%f", &(ele)->Emp_Salary);
    }

    //Printing registration elements
    printf("List of registred employee(s)\n");
    for(ele=ptr, i=1; ele<(ptr+n); ele++, i++) {
        printf("Employee n-%d: %d", i, ele->Emp_Code);
        printf("\nName: %s", ele->Emp_Name);
        printf("\nSalary: %.2f\n", ele->Emp_Salary);
    }

    //Deallocating the memory
    free(ptr); 
    exit(0);
}