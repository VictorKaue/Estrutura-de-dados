#include <stdio.h>


typedef struct{
    int codigo;
    char nome[30];
    float preco;
}Produto;

typedef struct{
    Produto produto;
    int quantidade;
}Carrinho;

void menu();
Produto *cadastrarProduto(Produto produtos[50], int posicao);


int main(){
    Produto produtos[50];
    Carrinho carrinho[50];

    
    return 0;
}

void menu(){
        
}

Produto *cadastrarProduto(Produto *produto, int posicao){
    printf("Digite o nome do produto: ");
    fgets(produto[posicao].nome, 30, stdin);

    printf("Digite o preço: ");
    scanf("%f", produto[posicao].preco);

    return produto;
}