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

void menu(Produto *produtos, Carrinho *carrinho);
void cadastrarProduto(Produto *produtos, int posicao);
void listarProdutos(Produto *produtos, int posicao);
void comprarProduto(Produto *produtos, Carrinho *carrinho, int posicao);
void visualizarCarrinho(Carrinho *carrinho, int posicao);
void fecharPedido(Carrinho *carrinho, int posicao);

int main(){
    Produto produtos[50];
    Carrinho carrinho[50];

    
    return 0;
}

void menu(Produto *produtos, Carrinho *carrinho){
    int op = 0, posicao = 0;
    while (op != 6){
        puts("1 - Cadastrar produtos");
        puts("2 - Listar produtos");
        puts("3 - Comprar produto");
        puts("4 - Visualizar carrinho");
        puts("5 - Fechar pedido");
        puts("6 - sair do sistema:");
        puts("Digite a opereção que deseja: ");
        switch (op){
        case 1:
            cadastrarProduto(produtos, posicao);
            break;
        
        case 2:
            listarProdutos(produtos, posicao);
            break;
        case 3:
            comprarProduto(produtos, carrinho, posicao);
            break;
        case 4:
            visualizarCarrinho(carrinho, posicao);
            break;
        case 5:
            fecharPedido(carrinho, posicao);
            break;
        case 6:
            printf("Saindo do sistema!\n");
            break;
        }
    }
}

void cadastrarProduto(Produto *produto, int posicao){
    printf("Digite o código do produto: ");
    scanf("%d", produto[posicao].codigo);

    printf("Digite o nome do produto: ");
    fgets(produto[posicao].nome, 30, stdin);

    printf("Digite o preço: ");
    scanf("%f", produto[posicao].preco);

}

void listarProdutos(Produto *produtos, int posicao){
    int i;
    printf("Produtos: \n\n");
    for (i = 0; i < posicao; i++){
        printf("Código: %d\n", produtos[posicao].codigo);
        printf("Nome: %s\n", produtos[posicao].nome);
        printf("Preço: %.2f", produtos[posicao].preco);
    }
}