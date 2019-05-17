#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>
#define VACIO 1
#define OCUPADO 0
#include "inputsBordone.h"

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;


///FUNCION AÑADIR EMPLEADOS
///brief permite añadir un empleado en la primer posicion vacía del array
///param pEmployeeList puntero al primer elemento del array de esutrcutras
///param len int con el numero max de empleados posibles
///param name[] nombre del nuevo empleado a dar de alta
///param lastName[] apellido del nuevo empleado a dar de alta
///param salary sueldo del nuevo empleado a dar de alta
///param sector id del sector del nuevo empleado a dar de alta}
///return (-1) si el puntero apunta a NULL - (0) si se realizo el alta con exito
int addEmployees(eEmployee* pEmployeeList, int len, int id, char name[], char lastName[], float salary, int sector);


///FUNCION MODIFICAR EMPLEADOS
///brief permite modificar a un empleado existente, buscandolo por su numero de legajo. Modifica un parametro a la vez.
///param pEmployeeList puntero al primer elemento del array de esutrcutras
///param len int con el numero max de empleados posibles
///return void
void modifyEmployees(eEmployee* pEmployeeList, int len);


///FUNCION  ENCONTRAR EMPLEADO
///brief permite encontrar un empleado existente, buscandolo por numero de legajo
///param pEmployeeList puntero al primer elemento del array de esutrcutras
///param len int del numero max de empleados posibles
///param int id numero de legajo del empleado a buscar
///return (-1) si el empleado no ha sido encontrado - (i) si el empleado fue encontrado retorna i, siendo i el indice del array que ocupa ese empleado
int findEmployeeById(eEmployee* pEmployeeList,int len ,int id);


///FUNCION INICIALIZAR EMPLEADOS
///brief inicializa todos los parametros isEmpty de toda la longitud del array de estructuras en "VACIO" (macro definido como 1)
///param pEmployeeList puntero al primer elemento del array de esutrcutras
///param len int del numero max de empleados posibles
///return (-1) si el puntero apunta a NULL - (0) si la inicialización se ha hecho correctamente
int initEmployees(eEmployee* pEmployeeList, int len);


///FUNCION ORDENAR EMPLEADOS POR NOMBRE
///brief ordena los empleados por nombre de forma ascdendente (si order es 1) o descendente (si order es 0)
///param pEmployeeList puntero al primer elemento del array de esutrcutras
///param len int del numero max de empleados posibles
///param order define si el ordenamiento sera ascendente o descendente
///return (-1) si el puntero apunta a NULL - (0) si el ordenamiento se realizo con exito
int sortEmployeeByName(eEmployee* pEmployeeList, int len, int order);


///FUNCION MOSTRAR EMPLEADO
///brief imprime un empleado en una linea con todos sus datos, basandose en el indice (de puntero) que ocupa el empleado
///param len int del numero max de empleados posibles
///param order define si el ordenamiento sera ascendente o descendente
///return (-1) si el puntero apunta a NULL - (0) si la impresion ha sido exitosa
int showEmployee(eEmployee* pEmployeeList, int num);

///FUNCION MOSTRAR TODOS LOS EMPLEADOS
///brief Muestra todos los empleados en el orden en el que estan sus indices (de puntero), llamando una vez por empleado a la funcion "mostrar empleado"
///param len int del numero max de empleados posibles
///param order define si el ordenamiento sera ascendente o descendente
///return (-1) si el puntero apunta a NULL - (0) si la impresion ha sido exitosa
int showAllEmployees(eEmployee* pEmployeeList, int len);


///FUNCION ELIMINAR EMPLEADO
///brief elimina de forma lógica (mediante el parametro isEmpty) a un empleado existente, buscandolo por su legajo
///param len int del numero max de empleados posibles
///param order define si el ordenamiento sera ascendente o descendente
///param id legajo del empleado
///return (-1) si el puntero apunta a NULL - (0) si la eliminación ha sido exitosa
int removeEmployee(eEmployee* pEmployeeList, int len, int id);


