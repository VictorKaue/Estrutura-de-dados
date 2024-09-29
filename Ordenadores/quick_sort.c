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

void quicksort(int *vetor, int esquerda, int direita){
    int pivo = esquerda;
    int menor, aux, posicao;

    for(posicao = esquerda+1; posicao <= direita; posicao++){
        aux = posicao;
        if(vetor[aux] < vetor[pivo]){
            menor = vetor[aux];
            while (aux > pivo){
                vetor[aux] = vetor[aux-1];
                aux--;
            }
            vetor[aux] = menor;
            pivo++;
        }
    }   
    if(pivo-1 >= esquerda){
        quicksort(vetor, esquerda, direita-1);
    }
    if(pivo+1 <= direita){
        quicksort(vetor, pivo+1, direita);
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
    quicksort(vetor, 0, tamanho-1);
    printf("\nVetor depois: \n\n");
    imprimir_vetor(vetor, tamanho);
}