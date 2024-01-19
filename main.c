#include "funciones.h" 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

    //variables
    int selector, numProductos;
    char controlador, c;
    int existencia;

    numProductos = cargarProductos();
    do{
        desplegarMenu(&selector);
        system("clear");
        switch(selector){
        case 1: agregarProductos(&controlador);
            numProductos = cargarProductos();
            break;
        case 2: listarProductos(numProductos);
            break;
        case 3:
            printf("---MODIFICAR PRECIO---\n\n"); 
            existencia = modificarPrecio(numProductos);
            if(existencia == 1){
                printf("Cambio realizado\n");
                numProductos = cargarProductos();
            }else
                printf("No existe\n");

            fflush(stdin);
            printf("Continuar... ");
            c = getchar();
            system("clear");
            break;
        case 4:
            printf("---MODIFICAR CANTIDAD---\n\n"); 
            existencia = modificarCantidad(numProductos);
            if(existencia == 1){
                printf("Cambio realizado\n");
                numProductos = cargarProductos();
            }else
                printf("No existe\n");

            fflush(stdin);
            printf("Continuar... ");
            c = getchar();
            system("clear");
            break;
        case 5: 
            printf("---ELIMINAR PRODUCTO---\n\n");
            existencia = eliminarProducto(numProductos);
            if(existencia == 1){
                printf("Producto eliminado\n");
                numProductos = cargarProductos();
            }else
                printf("No existe\n");

            fflush(stdin);
            printf("Continuar... ");
            c = getchar();
            system("clear");
            break;
        case 6:
            printf("SALIENDO\n\n");
            break;
        default:
            printf("OPCION NO VALIDA\n\n");
            break;
        }
    }while(selector != 6);
    
    return 0;
}