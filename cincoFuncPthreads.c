#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define UPPERBOUND 1000000

clock_t finCpuA, finCpuB, finCpuC, finCpuD, finCpuE;
time_t finReA, finReB, finReC, finReD, finReE;

void* funcionA(void* arg) {
    finCpuA = clock();
    finReA = time(NULL);
    int limSuperior = rand() % UPPERBOUND;
    long long int ans = 0;
    int i;
    for(i = 0; i<limSuperior; i++){
        ans += i;
    }
    printf("Funcion A terminada. El resultado es %lld\n", ans);
    return NULL;
}

void* funcionB(void* arg) {
    finCpuB = clock();
    finReB = time(NULL);
    int limSuperior = rand() % UPPERBOUND;
    long long int ans = 0;
    int i;
    for(i = 0; i<limSuperior; i++){
        ans -= i;
    }
    printf("Funcion B terminada. El resultado es %lld\n", ans);
    return NULL;
}

void* funcionC(void* arg) {
    finCpuC = clock();
    finReC = time(NULL);
    int limSuperior = rand() % UPPERBOUND;
    long long int ans = 10;
    int i;
    for(i = 0; i<limSuperior; i++){
        if(i % 2 == 0) ans += 1;
    }
    printf("Funcion C terminada. El resultado es %lld\n", ans);
    return NULL;
}

void* funcionD(void* arg) {
    finCpuD = clock();
    finReD = time(NULL);
    int limSuperior = rand() % UPPERBOUND;
    long long int ans = 0;
    int i;
    for(i = 0; i<limSuperior; i++){
        ans += i*i;
    }
    printf("Funcion D terminada. El resultado es %lld\n", ans);
    return NULL;
}

void* funcionE(void* arg) {
    finCpuE = clock();
    finReE = time(NULL);
    int limSuperior = rand() % UPPERBOUND;
    long long int ans = 0;
    int i;
    for(i = 0; i<limSuperior; i++){
        ans += i*i*i;
    }
    printf("Funcion E terminada. El resultado es %lld\n", ans);
    return NULL;
}

int main() {
    pthread_t threadA, threadB, threadC, threadD, threadE;
    clock_t iniCpu = clock();
    time_t iniReal = time(NULL);
    
    printf("\nRESULTADOS:\n");
    // Ejecutar A, B y C en paralelo
    pthread_create(&threadA, NULL, funcionA, NULL); 
    pthread_create(&threadB, NULL, funcionB, NULL);
    pthread_create(&threadC, NULL, funcionC, NULL);
    
    // Esperar a que A, B y C terminen
    pthread_join(threadA, NULL); 
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    // Ejecutar D después de B y C
    pthread_create(&threadD, NULL, funcionD, NULL); 
    pthread_join(threadD, NULL); 

    // Ejecutar E después de A y D
    pthread_create(&threadE, NULL, funcionE, NULL); 
    pthread_join(threadE, NULL);  

    printf("\nTIEMPOS:\n");
    printf("Funcion A:          Tiempo de inicio (CPU) %f\n", (double)(finCpuA - iniCpu) / CLOCKS_PER_SEC);
    printf("Funcion B:          Tiempo de inicio (CPU) %f\n", (double)(finCpuB - iniCpu) / CLOCKS_PER_SEC);
    printf("Funcion C:          Tiempo de inicio (CPU) %f\n", (double)(finCpuC - iniCpu) / CLOCKS_PER_SEC);
    printf("Funcion D:          Tiempo de inicio (CPU) %f\n", (double)(finCpuD - iniCpu) / CLOCKS_PER_SEC);
    printf("Funcion E:          Tiempo de inicio (CPU) %f\n", (double)(finCpuE - iniCpu) / CLOCKS_PER_SEC);
    return 0;
}
