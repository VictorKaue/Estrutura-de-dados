#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanho 6

void imprimir_vetor(int *vetor){
    int i;
    for(i = 0; i < tamanho; i++){
        printf("%dª posição: %d\n", i+1, vetor[i]);
    }
}

int main(){
    srand(time(NULL));
    int vetor[tamanho], i, j, aux;
    
    for (i = 0; i < tamanho-1; i++){
        vetor[i] = rand() %10 + 1;
    }
    printf("Vetor antes: \n\n");
    imprimir_vetor(vetor);

    for (i = 0; i < tamanho - 1; i++){
        for (j = 0; j < tamanho-1-i; j++){
            if (vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
    printf("Vetor depois: \n\n");
    imprimir_vetor(vetor);
}