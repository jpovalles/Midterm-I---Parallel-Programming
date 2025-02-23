#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define UPPERBOUND 1000000

clock_t finCpuA, finCpuB, finCpuC, finCpuD, finCpuE;
time_t finReA, finReB, finReC, finReD, finReE;

void funcionA() {
    finCpuA = clock();
    finReA = time(NULL);
    int limSuperior = rand() % UPPERBOUND;
    long long int ans = 0;
    int i;
    for(i = 0; i<limSuperior; i++){
        ans += i;
    }
    printf("Funcion A terminada. El resultado es %lld\n", ans);
}

void funcionB() {
    finCpuB = clock();
    finReB = time(NULL);
    int limSuperior = rand() % UPPERBOUND;
    long long int ans = 0;
    int i;
    for(i = 0; i<limSuperior; i++){
        ans -= i;
    }
    printf("Funcion B terminada. El resultado es %lld\n", ans);
}

void funcionC() {
    finCpuC = clock();
    finReC = time(NULL);
    int limSuperior = rand() % UPPERBOUND;
    long long int ans = 0;
    int i;
    for(i = 0; i<limSuperior; i++){
        if(i % 2 == 0) ans += 1;
    }
    printf("Funcion C terminada. El resultado es %lld\n", ans);
}

void funcionD() {
    finCpuD = clock();
    finReD = time(NULL);
    int limSuperior = rand() % UPPERBOUND;
    long long int ans = 0;
    int i;
    for(i = 0; i<limSuperior; i++){
        ans += i*i;
    }
    printf("Funcion D terminada. El resultado es %lld\n", ans);
}

void funcionE() {
    finCpuE = clock();
    finReE = time(NULL);
    int limSuperior = rand() % UPPERBOUND;
    long long int ans = 0;
    int i;
    for(i = 0; i<limSuperior; i++){
        ans += i*i*i;
    }
    printf("Funcion E terminada. El resultado es %lld\n", ans);
}

int main() {
    clock_t iniCpu = clock();
    time_t iniReal = time(NULL);
	
    printf("\nRESULTADOS:\n");
    // Ejecutar A, B y C en paralelo
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            funcionA();
        }
        #pragma omp section
        {
            funcionB();
        }
        #pragma omp section
        {
            funcionC();
        }
    }

    // Ejecutar D después de B y C
    funcionD();

    // Ejecutar E al final
    funcionE();

    printf("\nTIEMPOS:\n");
    printf("Funcion A:          Tiempo de inicio (CPU) %f\n", (double)(finCpuA - iniCpu) / CLOCKS_PER_SEC);
    printf("Funcion B:          Tiempo de inicio (CPU) %f\n", (double)(finCpuB - iniCpu) / CLOCKS_PER_SEC);
    printf("Funcion C:          Tiempo de inicio (CPU) %f\n", (double)(finCpuC - iniCpu) / CLOCKS_PER_SEC);
    printf("Funcion D:          Tiempo de inicio (CPU) %f\n", (double)(finCpuD - iniCpu) / CLOCKS_PER_SEC);
    printf("Funcion E:          Tiempo de inicio (CPU) %f\n", (double)(finCpuE - iniCpu) / CLOCKS_PER_SEC);
    return 0;
}
