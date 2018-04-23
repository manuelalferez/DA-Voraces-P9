/* 
 * File:   main.c
 * Author: Manuel Alférez Ruiz
 * Created on 23 de abril de 2018, 8:42
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Algoritmo de selección: Selecciona el elemento menor de dos posiciones
 *        generadas aleatoriamente
 * @param arch El vector de archivos
 * @param num_archivos Número de archivos
 * @return Devuelve la posición donde se ubica el elemento menor entre los dos
 *         comparados
 */
int seleccion(int arch[], int num_archivos) {

    int pos_aleatorio1 = rand() % num_archivos; //Posición aleatoria número uno
    int pos_aleatorio2 = rand() % num_archivos; //Posición aleatoria número dos 

    //Enviamos el de menor valor
    if (arch[pos_aleatorio1] > arch[pos_aleatorio2]) return pos_aleatorio2;
    else return pos_aleatorio1;
}

/**
 * @brief Borra una posición de un vector
 * @param v El vector donde se encuentre el elemento que deseamos eliminar
 * @param pos Posición donde se ubica el elemento a eliminar
 * @param tama Tamaño del vector
 */
void borraPosicion(int v[], int pos, int tama) {
    v[pos] = v[tama - 1];
    tama--;
}

/**
 * @brief Función voraz: Dado un conjunto de archivos debemos de seleccionarlos
 *        de manera que maximice el número de archivos que puedan llegar a 
 *        almacenarse en el dispotivo de almacenamiento
 * @param arch El vector que simboliza los archivos 
 * @param solucion El vector solución con el conjunto de archivos a copiar en el
 *                 dispositivo de almacenamiento
 * @param num_archivos Tamaño de nuestro vector de archivos
 * @param capacidad Capacidad en Megabytes de nuestro dispositivo de 
 *                  almacenamiento
 */
void funcionVoraz(int arch[], int solucion[], int num_archivos, int capacidad) {

    int tam_solucion = 0; // Número de elementos en el vector solución
    int capacidad_solucion = 0; //Capacidad total del vector solución (Megabytes)
    int elem; //Elemento que seleccionamos
    int posicion; //Posición del candidato

    while (tam_solucion < 50 || capacidad_solucion < capacidad) {
        posicion = seleccion(arch, num_archivos);
        elem = arch[posicion];
        borraPosicion(arch, elem, num_archivos);
        if ((elem + capacidad_solucion) <= capacidad) {
            solucion[tam_solucion] = elem;
            tam_solucion++;
        }
    }
}

/*
 * @brief Función principal
 * @param argc Número de parámetros por línea de ordenes
 * @param argv Parámetros por líneas de órdenes
 */
int main(int argc, char** argv) {
    //Datos del problema 
    int archivos[50];
    int solucion[50];
    int num = 50;
    int capacidad_almacenamiento = 1000;

    //Inicializamos el vector de archivos con números aleatorios entre 1 y 100
    for (int i = 0; i < num; i++) archivos[i] = rand() % 100 + 1;

    //Inicializamos el vector solucion con 0
    for (int i = 0; i < num; i++) solucion[i] = 0;

    funcionVoraz(archivos, solucion, num, capacidad_almacenamiento);

    if (solucion[0] == 0) printf("No hay solucion");
    else {
        printf("Hay solucion.\n");
        for (int i = 0; i < num; i++) {
            printf("%d   ", solucion[i]);
        }
    }
    return (EXIT_SUCCESS);
}
