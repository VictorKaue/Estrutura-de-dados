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
    int vetor[tamanho], i, j, menor_posicao;
    for (i = 0; i < tamanho-1; i++){
        vetor[i] = rand() %10 + 1;
    }
    
    for (i = 0; i < tamanho-1; i++){
        menor_posicao = vetor[i];
        for (j = 0; j < tamanho-1-i; j++){
            if(menor_posicao < vetor[i]){
                
            }
        }
    }
     
    return 0;
}