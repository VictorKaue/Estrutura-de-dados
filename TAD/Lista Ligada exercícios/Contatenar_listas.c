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
    if(novoNo == NULL){
        printf("Error at alloc memory and insert at beggining!\n");
        exit(1);
    }
    if((*lista) == NULL){
        (*lista) = novoNo;
        return;
    }
    novoNo->valor = valor;
    novoNo->proximo = (*lista);
    (*lista) = novoNo;
}

void inserirNoFinal(No **lista, int valor){
    No *novoNo = criarNovoNo(valor);
    if(novoNo == NULL){
        printf("Error at alloc memory and insert at beggining!\n");
        exit(1);
    }
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

void concatenarListas(No *lista1, No *lista2){
    while (lista1->proximo != NULL){
        lista1 = lista1->proximo;
    }
    lista1->proximo = lista2;
}

void exibirLista(No *lista){
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
    
    No *lista2 = NULL;
    inserirNoFinal(&lista2, 80);
    inserirNoFinal(&lista2, 20);
    inserirNoFinal(&lista2, 50);
    inserirNoInicio(&lista2 ,10);
    concatenarListas(lista, lista2);
    exibirLista(lista);
    destruirLista(&lista);
    
    return 0;
}