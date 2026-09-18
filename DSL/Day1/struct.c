#include<stdio.h>
#include<string.h>

struct saptami{
    int id;
    char nm[20], desg[20];
    float bs, hra, da;
}

void main(){
    int n;
    printf("Enter number of entries: ");
    scanf("%d", &n);
    struct saptami shw[n];

    for(int i=0; i<n; i++){
        printf("Enter Employee ID: ");
        scanf("%d",&shw[i].id);
        printf("Enter Employee Name: ");
        scanf("%s",shw[i].nm);
        printf("Enter Employee Designation: ");
        scanf("%s",shw[i].desg);
        printf("Enter Basic Salary: ");
        scanf("%f",&shw[i].bs);
        printf("Enter HRA Percentage: ");
        scanf("%f",&shw[i].hra);
        printf("Enter DA Percentage: ");
        scanf("%f",&shw[i].da);
    }

    printf("\nThe Employee Details are:");
    printf("\nEmp_ID\t\tEmp_Name\t\tDesignation\t\tBasic_Salary\t\tHRA\t\tDA\n");

    for(int i=0; i<n; i++){
        printf("%d\t\t%s\t\t%s\t\t%f\t\t%f\t\t%f", shw[i].id, shw[i].nm, shw[i].desg, shw[i].bs, shw[i].hra, shw[i].da);
    }
    printf("\n\n");
}
