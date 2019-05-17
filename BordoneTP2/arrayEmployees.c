
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>
#define VACIO 1
#define OCUPADO 0
#define MAXEMPLOYEES 1000
#include "arrayEmployees.h"
#include "inputsBordone.h"

int initEmployees(eEmployee* pEmployeeList, int len){
int i;
int returnV = -1;
if(pEmployeeList != NULL){
    for(i=0;i<len;i++){
        pEmployeeList[i].isEmpty = VACIO;
        returnV = 0;
    }
}
return returnV;
}


int addEmployees(eEmployee* pEmployeeList, int len, int id, char name[], char lastName[], float salary, int sector){

        int returnValue = -1;
        if(pEmployeeList != NULL){
            if(len == MAXEMPLOYEES){
                int i = id-1;
                pEmployeeList[i].id = id;
                strcpy(pEmployeeList[i].name,name);
                strcpy(pEmployeeList[i].lastName,lastName);
                pEmployeeList[i].salary = salary;
                pEmployeeList[i].sector = sector;
                pEmployeeList[i].isEmpty = OCUPADO;
                returnValue = 0;
                /*
                printf("%s",pEmployeeList[i].name);
                getch();
                */
            }
        }
return returnValue;

}

int findEmployeeById(eEmployee* pEmployeeList,int len ,int id){
    int i,returnV=-1;
    if(pEmployeeList != NULL){
        for(i=0;i<len;i++){
            if (id == pEmployeeList[i].id){
                returnV = i;
                break;
            }
        }
    }
    return returnV;
}

void modifyEmployees(eEmployee* pEmployeeList, int len){
            int indiceRetornado, r,validate,validarSeleccion,seleccionDato;
            int employeeId;
            char respuesta;
            do{
                system("cls");
                printf("\nIngrese legajo de empleado a modificar\n");
                scanf("%d",&employeeId);
                indiceRetornado = findEmployeeById(pEmployeeList,MAXEMPLOYEES,employeeId);
                while(indiceRetornado ==-1){
                    printf("\nError, legajo inexistente. Ingrese otro n° de legajo:\n");
                    scanf("%d",&employeeId);
                    indiceRetornado = findEmployeeById(pEmployeeList,MAXEMPLOYEES,employeeId);
                }

                r = showEmployee(pEmployeeList,indiceRetornado);
                if(r == -1){
                    printf("\nError. Vuelva al comienzo.");
                    getch();
                }
                if(r != -1){
                    r = getAB(&respuesta,"Es este el empleado que desea modificar?[S/N]","Error, respuesta iinvalida [S/N]",'S','N');
                    if(respuesta == 'S'){

                        printf("\n1.Apellido 2.Nombre 3.Salario 4.Id Sector\n");
                        do{
                        validarSeleccion = getNum(&seleccionDato,"Ingrese dato a Modificar [1-4]","Opcion Inexistente[1-4]",1,4);
                        }while(validarSeleccion == 1);

                        if(validarSeleccion == 0){
                            char apellidoNuevo[52];
                            char nombreNuevo[52];
                            int salarioNuevo;
                            int sectorNuevo;

                           switch(seleccionDato){



                            ///MODIFICAR APELLIDO
                            case 1:
                                do{
                                        validate = getCharLen(apellidoNuevo,"Ingresar apellido nuevo","Error en cantidad de caracteres: [1-51]",1,51);
                                            if(validate == 0){
                                                strcpy(pEmployeeList[indiceRetornado].lastName,apellidoNuevo);
                                            }
                                }while(validate == 1);


                                printf("\nApellido modificado con exito!\n");
                                getch();
                                break;


                            ///MODIFICAR NOMBRE
                            case 2:
                                do{
                                        validate = getCharLen(nombreNuevo,"Ingresar nombre nuevo","Error en cantidad de caracteres: [1-51]",1,51);
                                        if(validate == 0){
                                            strcpy(pEmployeeList[indiceRetornado].name,nombreNuevo);
                                        }
                                }while(validate == 1);


                                printf("\nNombre modificado con exito!\n");
                                getch();
                                break;


                            ///MODIFICAR SALARIO
                            case 3:
                                do{
                                        validate = getNum(&salarioNuevo,"Ingresar nuevo salario","Error: salario no puede ser 0",1,500000);
                                        if(validate == 0){
                                            pEmployeeList[indiceRetornado].salary = salarioNuevo;
                                        }
                                }while (validate ==1);
                                printf("\nSalario modificado con exito\n");
                                getch();
                                break;


                            ///MODIFICAR SECTOR
                            case 4:
                                do{
                                    validate = getNum(&sectorNuevo,"Ingrese nuevo codigo de sector","Seleccion invalida",1,10);
                                    if(validate == 0){
                                        pEmployeeList[indiceRetornado].sector = sectorNuevo;
                                    }
                                    printf("\nId de sector modificado con exito!\n");
                                    getch();
                                    break;

                                }while (validate == 1);
                                break;
                           }
                        }

                    }
                }
            }while(r == -1 || respuesta == 'N');
            printf("Empleado modificado con éxito!");
            getch();
}


int removeEmployee(eEmployee* pEmployeeList, int len, int id){
    int i,returnValue;
    if(pEmployeeList == NULL){
        returnValue = -1;
    }
    if(pEmployeeList != NULL){
        i = findEmployeeById(pEmployeeList,len,id);
        pEmployeeList[i].isEmpty = VACIO;
        printf("\nUsuario eliminado con exito\n");
        getch();
        returnValue = 0;
    }

    return returnValue;
}

int showEmployee(eEmployee* pEmployeeList, int num){
            printf("\nId: %d Apellido: %s Nombre: %s Salario: %.2f Id de Sector: %d\n",
                    pEmployeeList[num].id , pEmployeeList[num].lastName,
                    pEmployeeList[num].name, pEmployeeList[num].salary,pEmployeeList[num].sector);


    return 0;
}

int showAllEmployees(eEmployee* pEmployeeList, int len){
    int i;
    for(i=0;i<len;i++){
        /*
        printf("%d",i);
        getch();
        */
        if(pEmployeeList[i].isEmpty == OCUPADO){
            showEmployee(pEmployeeList,i);
        }
        if(pEmployeeList[i].isEmpty == VACIO){
            break;
        }
    }
    return 0;

}


int sortEmployeeByName(eEmployee* pEmployeeList, int len, int order){
    int i, j, returnValue = 0;
    eEmployee auxList;

    if(pEmployeeList == NULL){
        returnValue = -1;
    }
    if(pEmployeeList != NULL){
        for(i=0;i<len-1;i++){
            for(j=i+1;j<len;j++)
                if(pEmployeeList[i].isEmpty == OCUPADO && pEmployeeList[j].isEmpty == OCUPADO){
                    if(order == 1){
                        if(strcmp(pEmployeeList[i].lastName,pEmployeeList[j].lastName) > 0){
                            if(pEmployeeList[i].sector > pEmployeeList[j].sector){
                                auxList = pEmployeeList[i];
                                pEmployeeList[i] = pEmployeeList[j];
                                pEmployeeList[j] = auxList;

                            }
                        }
                    }

                    if(order == 0){
                        if(strcmp(pEmployeeList[i].lastName,pEmployeeList[j].lastName) < 0){
                            if(pEmployeeList[i].sector < pEmployeeList[j].sector){
                                auxList = pEmployeeList[i];
                                pEmployeeList[i] = pEmployeeList[j];
                                pEmployeeList[j] = auxList;

                            }
                        }
                    }
                }
        }
    showAllEmployees(pEmployeeList,len);
}




return returnValue;
}
