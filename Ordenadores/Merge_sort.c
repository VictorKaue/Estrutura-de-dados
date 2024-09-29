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

void merge(int *vetor, int esquerda, int meio, int direita){
    int i,j,k, tamanho, p1, p2;
    int fim1 = 0, fim2 =0;
    tamanho = direita - esquerda + 1;
    int aux[tamanho];
    p1 = esquerda;
    p2 = meio + 1;
    for(i=0; i < tamanho; i++){
        if(!fim1 && !fim2){
            if(vetor[p1] < vetor[p2]){
                aux[i] = vetor[p1++];
            }else{
                aux[i] = vetor[p2++];
            }
            if(p1 > meio) fim1 = 1;
            if(p2 > direita) fim2 = 1;
        } else{
            if(!fim1){
                aux[i] = vetor[p1++];
            }else{
                aux[i] = vetor[p2++];
            }
        }
    }
    for(j=0, k = esquerda; j < tamanho; j++, k++){
        vetor[k] = aux[j];
    }
}

void mergesort(int *vetor, int esquerda, int direita){
    if(esquerda < direita){
        int meio = (direita+esquerda)/2;
        mergesort(vetor, esquerda, meio);
        mergesort(vetor, meio+1, direita);
        merge(vetor, esquerda, meio, direita);
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
    mergesort(vetor, 0, tamanho-1);
    printf("\nVetor depois: \n\n");
    imprimir_vetor(vetor, tamanho);
}