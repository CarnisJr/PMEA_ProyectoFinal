#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct productos{
    char nombre[50];
    char cantidad[100];
    char precio[50];
    char codigo[5];
}productos[10];

//Desplegar Menu

void desplegarMenu(int *selector){

    printf("---INVENTARIO DE PRODUCTOS---\n\n");
    printf("1. Agregar Productos\n2. Listar Productos\n3. Modificar Precio\n4. Modificar cantidad\n\n");
    printf("Ingrese una opcion: ");
    scanf("%i", &*selector);
}

//Agregar productos

void agregarProductos(char *controlador){

    FILE *f;
    f = fopen("productos.txt", "a");
    int i = 0;

    do{

        fflush(stdin);
        printf("---AGREGANDO PRODUCTOS---\n\n"); 

        printf("Nombre del producto: ");
        gets(productos[i].nombre);
        fwrite(productos[i].nombre, 1, strlen(productos[i].nombre), f);
        fprintf(f, ",");

        printf("Cantidad del producto: ");
        gets(productos[i].cantidad);
        fwrite(productos[i].cantidad, 1, strlen(productos[i].cantidad), f);
        fprintf(f, ",");

        printf("Precio del producto: ");
        gets(productos[i].precio);
        fwrite(productos[i].precio, 1, strlen(productos[i].precio), f);
        fprintf(f, ",");

        printf("Codigo del producto: ");
        gets(productos[i].codigo);
        fwrite(productos[i].codigo, 1, strlen(productos[i].codigo), f);
        fprintf(f, ",");
        fprintf(f, "\n");

        i++;
        printf("Desea continuar [ s ] | [ n ]: ");
        scanf("%c", &*controlador);
        system("clear");
    }while(*controlador == 's');
    
    fclose(f);
}

//Cargar empleados

int cargarProductos(){

    int nProductos = 0, campo;
    FILE *f;
    f = fopen("productos.txt", "r");
    char cadena[255];
    char delimitador[] = ",";
    
    while(feof(f) == 0){

        fgets(cadena, 255, f);
        char *token = strtok(cadena, delimitador);

        if (token != NULL){
            campo = 1;
            while (token != NULL){
                if (campo == 1){
                    strcpy(productos[nProductos].nombre, token);
                }else if (campo == 2){
                    strcpy(productos[nProductos].cantidad, token);
                }else if (campo == 3){
                    strcpy(productos[nProductos].precio, token);
                }else if (campo == 4){
                    strcpy(productos[nProductos].codigo, token);
                }
                
                campo++;
                token = strtok(NULL, delimitador);
            }
        }
        nProductos++;
    }
    fclose(f);
    return --nProductos;
}

// Listar Productos

void listarEmpleados(int nProductos){

    printf("---LISTAR PRODUCTOS---\n\n"); 
    printf("\n+----------------------------+------------+-------------+--------+\n");
    printf("|           Nombre           |  Cantidad  |    Precio   | Codigo |");
    for(size_t i = 0; i < nProductos; i++){
        printf("\n+----------------------------+------------+-------------+--------+\n");
        printf("| %-26s | %-10s | %-11s | %-6s |", productos[i].nombre, productos[i].cantidad, productos[i].precio, productos[i].codigo);
    }
    printf("\n+----------------------------+------------+-------------+--------+\n");
    system("pause");
    system("clear");
}

// Eliminar producto

int eliminarProducto(int nProductos){

    FILE *f;
    f = fopen("productos.txt", "w");
    int verificarExistencia(char *verificacion, int nProductos);

    //Variables locales
    int existencia, i;
    char verificacion[5];
    printf("Ingrese la id del empleado: ");
    scanf("%s", verificacion);
    printf("---ELIMINAR PRODUCTO---\n\n");
    
    //Funcion verificar existencia del producto
    existencia = verificarExistencia(verificacion, nProductos);
    
    if(existencia == 1){
        for(size_t i = 0; i < nProductos; i++){
            if(strncmp(productos[i].codigo, verificacion, 2) == 0){

                continue;
            }else{

                fflush(stdin);

                fwrite(productos[i].nombre, 1, strlen(productos[i].nombre), f);
                fprintf(f, ",");

                fwrite(productos[i].cantidad, 1, strlen(productos[i].cantidad), f);
                fprintf(f, ",");

                fwrite(productos[i].precio, 1, strlen(productos[i].precio), f);
                fprintf(f, ",");

                fwrite(productos[i].codigo, 1, strlen(productos[i].codigo), f);
                fprintf(f, ",");
                fprintf(f, "\n");
            }
        }    
    }    
    
    fclose(f);
    return existencia;
}

//  Verificar codigo de producto

int verificarExistencia(char *verificacion, int nProductos){

    for(size_t i = 0; i < nProductos; i++){
        if(strncmp(productos[i].codigo, verificacion, 2) == 0){
            return 1;
            break;
        }else
            return 0;
        
    }
}


#endif