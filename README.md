# Midterm-I Parallel-Programming
This repository contains solutions for the first exam of the Parallel Programming course. It includes implementations using Pthreads, OpenMP, and MPI for parallel execution of functions, dependency handling, and message passing. The repository also features performance comparisons.

# Compilation Instructions

To compile each program using `gcc`, use the following commands:

## OMP tagged programs:
```sh
gcc -fopenmp -o <exec_name> <program_name.c>
```

## Pthreads tagged programs:
```sh
gcc -pthread -o <exec_name> <program_name.c>
```

## Some questions
1.	Realice una implementación usando Pthreads y otra usando openMP realice comparaciones en términos de cantidad de líneas y tiempo de ejecución.
* Cantidad de líneas: la cantidad de líneas no presento una variación realmente grande a pesar de que la sintaxis de openMP es claramente más simple que la de Pthreads. El programa en openMP de hecho tuvo 134 líneas de código mientras que la versión en Pthreads tuvo 127 lineas.
* Tiempo de ejecución: un detalle particular al observar los tiempos de ejecución es que en openMP cuando se crean los hilos de A, B y C para correrse en paralelo el tiempo de inicio de CPU es idéntico, es decir, son creados e inician a correr en simultaneo. Mientras que en Pthreads no se observa este comportamiento con una diferencia en los tiempos de estas 3 funciones, que se da en el mismo orden en el que están programadas sus funciones de creación del hilo. Además es fácil observar que el tiempo de ejecución total de Pthreads es ampliamente mejor al de openMP, el programa en openMP se tardó 200 veces más que la ejecución en Pthreads.


1. ¿Cuál es el resultado de este programa si se compila sin el flag de compilación -fopenmp?
* Aparece el error:
```sh
/tmp/ccdmghNc.o: In function `fillColumn':
matrix.c:(.text+0x15): undefined reference to `omp_get_thread_num'
collect2: error: ld returned 1 exit status
```
Esto nos indica que el compilador no encuentra la función omp_get_thread_num(). Esto ocurre porque esa función es parte de la biblioteca de OpenMP, y sin el flag -fopenmp, el compilador no la incluye.

2. ¿Cuál es el resultado de este programa si se compila con el flag de compilación -fopenmp? Explique el por qué el resultado difiere.
* Si el programa se compila con -fopenmp, las directivas de OpenMP se activarán y el código ejecutará ciertas partes en paralelo. Se crearán NUM_OF_COLUMNS - 1 hilos para ejecutar fillColumn(0). Luego, en el for, cada columna de la matriz será llenada en paralelo con fillColumn(j). Cada hilo escribirá su propio número de hilo en la matriz, lo que significa que las celdas de amtrx contendrán valores diferentes, dependiendo del número de hilo que haya ejecutado cada iteración.
