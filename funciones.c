#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct productos{
    char nombre[50];
    char cantidad[100];
    char precio[50];
    char codigo[10];
}productos[10];


void desplegarMenu(int *selector){

    printf("---INVENTARIO DE PRODUCTOS---\n\n");
    printf("1. Agregar Productos\n2. Listar Productos\n3. Modificar Precio\n4. Modificar cantidad\n5. Eliminar producto\n6. Salir\n\n");
    printf("Ingrese una opcion: ");
    scanf("%i", &*selector);
}


void agregarProductos(char *controlador){

    FILE *f;
    f = fopen("productos.txt", "a");
    int i = 0;

    do{

        fflush(stdin);
        printf("---AGREGANDO PRODUCTOS---\n\n"); 

        printf("Nombre del producto: ");
        fgets(productos[i].nombre, 50, stdin);
        fwrite(productos[i].nombre, 1, strlen(productos[i].nombre) - 1, f);
        fprintf(f, ",");

        printf("Cantidad del producto: ");
        fgets(productos[i].cantidad, 100, stdin);
        fwrite(productos[i].cantidad, 1, strlen(productos[i].cantidad) - 1, f);
        fprintf(f, ",");

        printf("Precio del producto: ");
        fgets(productos[i].precio, 50, stdin);
        fwrite(productos[i].precio, 1, strlen(productos[i].precio) - 1, f);
        fprintf(f, ",");

        printf("Codigo del producto: ");
        fgets(productos[i].codigo, 10, stdin);
        fwrite(productos[i].codigo, 1, strlen(productos[i].codigo) - 1, f);
        fprintf(f, ",");
        fprintf(f, "\n");

        i++;
        printf("Desea continuar [ s ] | [ n ]: ");
        scanf("%c", &*controlador);
        system("clear");
    }while(*controlador == 's');
    
    fclose(f);
}

int cargarProductos(){

    int nProductos = 0, campo;
    FILE *f;
    f = fopen("productos.txt", "r");
    char cadena[255];
    char delimitador[] = ",";
    
    while(feof(f) == 0){

        fgets(cadena, 255, f);
        char *token = strtok(cadena, delimitador);

        if(token != NULL){
            campo = 1;
            while(token != NULL){
                if(campo == 1){
                    strcpy(productos[nProductos].nombre, token);
                }else if(campo == 2){
                    strcpy(productos[nProductos].cantidad, token);
                }else if(campo == 3){
                    strcpy(productos[nProductos].precio, token);
                }else if(campo == 4){
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


void listarProductos(int nProductos){

    char c;

    printf("---LISTAR PRODUCTOS---\n\n"); 
    printf("\n+----------------------------+------------+-------------+--------+\n");
    printf("|           Nombre           |  Cantidad  |    Precio   | Codigo |");
    for(size_t i = 0; i < nProductos; i++){
        printf("\n+----------------------------+------------+-------------+--------+\n");
        printf("| %-26s | %-10s | %-11s | %-6s |", productos[i].nombre, productos[i].cantidad, productos[i].precio, productos[i].codigo);
    }
    printf("\n+----------------------------+------------+-------------+--------+\n");
    fflush(stdin);
    printf("Continuar... ");
    c = getchar();
    system("clear");
}


int eliminarProducto(int nProductos){

    //File principal
    FILE *f;
    f = fopen("productos.txt", "w");

    //Declaracion de la funcion para verificar que exista el producto
    int verificarExistencia(int verificacion, int nProductos);

    //Variables locales
    int existencia, i;
    int verificar;
    printf("Ingrese el codigo del producto: ");
    scanf("%i", &verificar);
    
    //Funcion verificar existencia del producto
    existencia = verificarExistencia(verificar, nProductos);
    
    if(existencia == 1){
        for(size_t i = 0; i < nProductos; i++){
            if(atoi(productos[i].codigo) == verificar){
                
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
    }else{
        for(size_t i = 0; i < nProductos; i++){
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
    
    fclose(f);
    return existencia;
}


int modificarPrecio(int nProductos){

    FILE *f;
    f = fopen("productos.txt", "w");

    //Declaracion de la funcion para verificar que exista el producto
    int verificarExistencia(int verificacion, int nProductos);

    //Variables locales
    int existencia, i;
    int verificar;
    printf("Ingrese el codigo del producto: ");
    scanf("%i", &verificar);
    
    //Funcion verificar existencia del producto
    existencia = verificarExistencia(verificar, nProductos);
    
    if(existencia == 1){
        for(size_t i = 0; i < nProductos; i++){
            if(atoi(productos[i].codigo) == verificar){
                
                fflush(stdin);

                fwrite(productos[i].nombre, 1, strlen(productos[i].nombre), f);
                fprintf(f, ",");

                fwrite(productos[i].cantidad, 1, strlen(productos[i].cantidad), f);
                fprintf(f, ",");

                printf("Precio del producto: ");
                fgets(productos[i].precio, 50, stdin);
                fwrite(productos[i].precio, 1, strlen(productos[i].precio) - 1, f);
                fprintf(f, ",");

                fwrite(productos[i].codigo, 1, strlen(productos[i].codigo), f);
                fprintf(f, ",");
                fprintf(f, "\n");
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
    }else{
        for(size_t i = 0; i < nProductos; i++){
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
    
    fclose(f);
    return existencia;
}


int modificarCantidad(int nProductos){
     //File principal
    FILE *f;
    f = fopen("productos.txt", "w");

    //declaraacion de la funcion para verificar que exista el producto
    int verificarExistencia(int verificacion, int nProductos);

    //Variables locales
    int existencia, i;
    int verificar;
    printf("Ingrese el codigo del producto: ");
    scanf("%i", &verificar);
    
    //Funcion verificar existencia del producto
    existencia = verificarExistencia(verificar, nProductos);
    
    if(existencia == 1){
        for(size_t i = 0; i < nProductos; i++){
            if(atoi(productos[i].codigo) == verificar){
                
                
                fflush(stdin);

                fwrite(productos[i].nombre, 1, strlen(productos[i].nombre), f);
                fprintf(f, ",");

                printf("Cantidad del producto: ");
                fgets(productos[i].cantidad, 100, stdin);
                fwrite(productos[i].cantidad, 1, strlen(productos[i].cantidad) - 1, f);
                fprintf(f, ",");

                fwrite(productos[i].precio, 1, strlen(productos[i].precio), f);
                fprintf(f, ",");

                fwrite(productos[i].codigo, 1, strlen(productos[i].codigo), f);
                fprintf(f, ",");
                fprintf(f, "\n");
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
    }else{
        for(size_t i = 0; i < nProductos; i++){
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
    
    fclose(f);
    return existencia;
}


int verificarExistencia(int verificacion, int nProductos){
    int existente;
    for(size_t i = 0; i < nProductos; i++){
        if(atoi(productos[i].codigo) == verificacion){
            existente = 1;
            break;
        }else{
            existente = 0;
        }
    }
    return existente;
}