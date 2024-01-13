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
        printf("| %-26s | %-10s | %-11s | %-5s |", productos[i].nombre, productos[i].cantidad, productos[i].precio, productos[i].codigo);
    }
    printf("\n+----------------------------+------------+-------------+--------+\n");
    system("pause");
    system("clear");
}

// Modificar Precio




#endif