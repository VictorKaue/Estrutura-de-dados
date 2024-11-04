#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int valor;
    struct no *proximo;
} No;

No *criarNovoNo(int valor){
    No *novoNo = (No *) malloc(sizeof(No));
    if(novoNo == NULL){
        printf("Falha ao alocar novo nó!\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirNoInicio(No **lista, int valor){
    No *novoNo = criarNovoNo(valor);
    novoNo->proximo = (*lista);
    (*lista) = novoNo;
}

void inserirNoFinal(No **lista, int valor){
    No *novoNo = criarNovoNo(valor);
    if((*lista) == NULL){
        (*lista) = novoNo;
        return;
    }
    
    No *ultimo = *lista;
    while(ultimo->proximo != NULL){
        ultimo = ultimo->proximo;
    }

    ultimo->proximo = novoNo;
}

void exibirLista(No *lista){
    if(lista == NULL){
        printf("A lista está vazia!\n");
        return;
    }
    while(lista != NULL){
        printf("%d -> ", lista->valor);
        lista = lista->proximo;
    }
    printf("NULL\n");
}

void destruirLista(No **lista){
    No *temp;
    while(*lista != NULL){
        temp = *lista;
        *lista = (*lista)->proximo;
        free(temp);
    }
    *lista = NULL;  
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    No *lista = NULL;
    inserirNoInicio(&lista ,10);
    inserirNoFinal(&lista, 50);
    inserirNoFinal(&lista, 20);
    inserirNoFinal(&lista, 80);
    printf("Antes de destruir a lista: \n");
    exibirLista(lista);
    destruirLista(&lista);
    printf("Depois de destruir a lista: \n");
    exibirLista(lista);
    return 0;
}