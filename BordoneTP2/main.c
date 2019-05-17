#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>
#define VACIO 1
#define OCUPADO 0
#define MAXEMPLOYEES 1000
#include "arrayEmployees.h"
#include "inputsBordone.h"



int main()
{
    eEmployee employeeList[MAXEMPLOYEES];
    eEmployee* pEmployeeList;
    pEmployeeList = employeeList;

    int init;
    init = initEmployees(employeeList,MAXEMPLOYEES);

    int answ;
    int validate;

    int r;
    char newName[51];
    char newLastName[51];
    float newSalary;
    int newSector,i,idEmployee;
    int flagAdd = 0;
    int order;

if(init == 0){

    do{

        system("cls");
        printf("1.Alta\t2.Modificar\t3.Baja\t4.INFORMAR");
        validate = getNum(&answ,"Ingrese opcion[1-4]","Error: opcion invalida [1-4]",1,4);

        switch(answ){
        case 1:

                do{
                system("cls");
                for(i=0;i<MAXEMPLOYEES;i++){
                    if(employeeList[i].isEmpty == VACIO){
                            idEmployee = i+1;
                            printf("\nIngrese nombre\n");
                            scanf("%s",newName);
                            printf("\nIngrese apellido\n");
                            scanf("%s",newLastName);
                            printf("\nIngrese Salario\n");
                            scanf("%f",&newSalary);
                            printf("\nIngrese id de Sector\n");
                            scanf("%d",&newSector);
                            r = addEmployees(pEmployeeList,MAXEMPLOYEES,idEmployee,newName,newLastName,newSalary,newSector);
                            flagAdd = 1;
                            /*
                            printf("%s",pEmployeeList[i].name);
                            printf("%s",employeeList[i].name);
                            getch();
                            */
                            break;
                        }

                    }
                 }while (r == -1);
                 break;
        case 2:
            if(flagAdd == 0){
                printf("\nNingun usuario dado de alta\n");
                getch();
            }else if(flagAdd == 1){
                    modifyEmployees(pEmployeeList,MAXEMPLOYEES);
                }

            break;
        case 3:

             if(flagAdd == 0){
                printf("\nError: Ningun usuario dado de alta\n");
                getch();
            }

            if(flagAdd == 1){

                do{
                    int indiceRetornado;
                    char respuesta;
                    system("cls");
                    printf("\nIngrese legajo de empleado a eliminar\n");
                    scanf("%d",&idEmployee);
                    indiceRetornado = findEmployeeById(pEmployeeList,MAXEMPLOYEES,idEmployee);
                    while(indiceRetornado ==-1){
                        printf("\nError, legajo inexistente. Ingrese otro n° de legajo:\n");
                        scanf("%d",&idEmployee);
                        indiceRetornado = findEmployeeById(pEmployeeList,MAXEMPLOYEES,idEmployee);
                    }


                    if(r == -1){
                        printf("\nError. Vuelva al comienzo.");
                        getch();
                    }
                    if(r != -1){
                        r = showEmployee(pEmployeeList,indiceRetornado);
                        r = getAB(&respuesta,"Es este el empleado que desea eliminar?[S/N]","Error, respuesta iinvalida [S/N]",'S','N');
                        if(respuesta == 'S'){
                            r = removeEmployee(pEmployeeList,MAXEMPLOYEES,idEmployee);
                        }
                    }
                }while(r==-1);
            }
            break;

        case 4:
            if(flagAdd == 1){
                do{
                    system("cls");
                    printf("De que forma desea ordenar?\n 1.Ascendente 2.Descendente");
                    validate = getNum(&order,"Seleccione opcion[1/2]","Error: Opcion inexistente [1/2]",1,2);
                    if(order == 2){
                        order = 0;
                    }
                    r = sortEmployeeByName(employeeList,MAXEMPLOYEES,order);
                }while(validate == 1 && r==-1);
            }
            if(flagAdd == 0){
                printf("\nError: Ningun usuario dado de alta\n");
                getch();
            }
            getch();
            break;
        }

    }while(validate == 1 || answ != 5 || validate == 1);

}
    return 0;
}
