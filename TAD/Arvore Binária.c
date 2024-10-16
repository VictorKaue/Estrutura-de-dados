#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Arvore{
    int numero;
    struct Arvore *esquerda;
    struct Arvore *direita;
}Arvore;

void imprimir_vetor(int *vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        printf("%dª posição: %d\n", i+1, vetor[i]);
    }
    printf("\n");
}

Arvore *criarNo(int numero){
    Arvore *arvore = (Arvore *) malloc(sizeof(Arvore));
    if()
    arvore->numero = numero;
    arvore->esquerda = NULL;
    arvore->direita = NULL;
    return arvore;
}

void criarArvore(Arvore *raiz, int *vetor, int tamanho){
    int i;
    raiz = criarNo(vetor[0]);
    for(i=1; i < tamanho; i++){
        if()
    }
}

int main(){
    srand(time(NULL));
    Arvore *raiz = NULL;
    int vetor[15], i;
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    
    for (i = 0; i < tamanho; i++){
        vetor[i] = rand() %100 + 1;
    }

    

    return 0;
}