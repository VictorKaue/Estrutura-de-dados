#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void imprimir_vetor(int *vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        printf("%dª posição: %d\n", i+1, vetor[i]);
    }
    printf("\n");
}

void shellsort(int *vetor, int tamanho){
    int gap, aux, i, j;
    
    for(gap = tamanho/2; gap > 0; gap /= 2){

        for(i = gap; i < tamanho; i++){
            aux = vetor[i];
            for(j=i; j >= gap && vetor[j-gap] > aux; j-=gap){
                vetor[j] = vetor[j - gap];
            }
            vetor[j] = aux;
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int vetor[6], i;
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    printf("tamanho: %d \n", tamanho);

    for (i = 0; i < tamanho; i++){
        vetor[i] = rand() %100 + 1;
    }
    printf("Vetor antes: \n\n");
    imprimir_vetor(vetor, tamanho);
	shellsort(vetor, tamanho);
    printf("\nVetor depois: \n\n");
    imprimir_vetor(vetor, tamanho);

    return 0;
}