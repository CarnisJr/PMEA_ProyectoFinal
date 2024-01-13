#include "funciones.h" 

int main(void){

    //variables
    int selector, numProductos, aux;
    char controlador;
    int existencia;

    numProductos = cargarProductos();
    //aux = verificarExistencia(numProductos);
    //printf("%d\n", aux);
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
            existencia = eliminarProducto(numProductos);
            if(existencia == 1){
                printf("Existe\n");
                numProductos = cargarProductos();
            }else
                printf("No existe\n");
            break;
        case 6:
            printf("SALIENDO\n\n");
            break;
        default:
            printf("OPCION NO VALIDA\n\n");
            break;
        }
    }while(selector != 6);
    
    system("pause");
    return 0;
}