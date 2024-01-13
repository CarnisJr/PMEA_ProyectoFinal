#include "funciones.h" 

int main(void){

    //variables
    int selector, numProductos;
    char controlador;

    numProductos = cargarProductos();
    //printf("%d\n", numProductos);
    do{
        desplegarMenu(&selector);
        system("clear");
        switch(selector){
        case 1: agregarProductos(&controlador);
            numProductos = cargarProductos();
            break;
        case 2: listarEmpleados(numProductos);
            break;
        case 3:
            printf("---MODIFICAR PRECIO---\n\n"); 
            break;
        case 4:
            printf("---MODIFICAR CANTIDAD---\n\n"); 
            break;
        case 5:
            printf("SALIENDO\n\n");
            break;
        default:
            printf("OPCION NO VALIDA\n\n");
            break;
        }
    }while(selector != 5);
    
    system("pause");
    return 0;
}