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

void insetionsort(int *vetor, int tamanho){
    int i, j, aux;
    
    for(i= 1; i < tamanho; i++){
        aux = vetor[i];
        for (j = i-1; j >= 0 && aux < vetor[j] ;j--){
            vetor[j+1] = vetor[j];
        }
        vetor[j+1] = aux;
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
	insetionsort(vetor, tamanho);
    printf("\nVetor depois: \n\n");
    imprimir_vetor(vetor, tamanho);

    return 0;
}