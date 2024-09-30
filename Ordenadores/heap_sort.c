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

void heapify(int *vetor, int tamanho, int i){
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
    if(esquerda < tamanho && vetor[esquerda] > vetor[maior]){
        maior = esquerda;
    }

    if(direita < tamanho && vetor[direita] > vetor[maior]){
        maior = direita;
    }

    if(maior != i){
        int aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;
        heapify(vetor, tamanho, maior);
    }
}

void heapsort(int *vetor, int tamanho){
    int i;
    for(i = tamanho/ 2 - 1; i >= 0; i--){
        heapify(vetor, tamanho, i);
    }
    
    for(int i = tamanho-1; i > 0; i--){
        int aux = vetor[i];
        vetor[i] = vetor[0];
        vetor[0] = aux;
        heapify(vetor, i, 0);
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
    heapsort(vetor, tamanho);
    printf("\nVetor depois: \n\n");
    imprimir_vetor(vetor, tamanho);
}