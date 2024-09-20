#include <stdio.h>
#include <string.h>
#include <locale.h>

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
void cadastrarProduto(Produto *produtos, int *quanti_cadastrados);
void listarProdutos(Produto *produtos, int quanti_cadastrados);
void comprarProduto(Produto *produtos, Carrinho *carrinho, int quanti_cadastrados);
//void visualizarCarrinho(Carrinho *carrinho, int quanti_cadastrados);
//void fecharPedido(Carrinho *carrinho, int quanti_cadastrados);

int main(){
    setlocale(LC_ALL, "");

    Produto produtos[50];
    Carrinho carrinho[50];

    menu(produtos, carrinho);
    return 0;
}

void menu(Produto *produtos, Carrinho *carrinho){
    int op = 0;
    static int quanti_cadastrados = 0;
    do{
        puts("1 - Cadastrar produtos");
        puts("2 - Listar produtos");
        puts("3 - Comprar produto");
        puts("4 - Visualizar carrinho");
        puts("5 - Fechar pedido");
        puts("6 - sair do sistema:");
        puts("Digite a opereção que deseja: ");
        scanf("%d", &op);
        switch (op){
        case 1:
            cadastrarProduto(produtos, &quanti_cadastrados);
            break;
        
        case 2:
            listarProdutos(produtos, quanti_cadastrados);
            break;
        case 3:
             comprarProduto(produtos, carrinho, quanti_cadastrados);
            break;
        case 4:
            // visualizarCarrinho(carrinho, quanti_cadastrados);
            break;
        case 5:
            // fecharPedido(carrinho, quanti_cadastrados);
            break;
        case 6:
            printf("Saindo do sistema!\n");
            break;
        }
    }while (op != 6);
}

void cadastrarProduto(Produto *produtos, int *quanti_cadastrados){
    printf("Digite o código do produto: ");
    scanf("%d", &produtos[*quanti_cadastrados].codigo);
    fflush(stdin);
    printf("Digite o nome do produto: ");
    fgets(produtos[*quanti_cadastrados].nome, 30, stdin);
    produtos[*quanti_cadastrados].nome[strcspn(produtos[*quanti_cadastrados].nome, "\n")] = '\0';
    printf("Digite o preço: ");
    scanf("%f", &produtos[*quanti_cadastrados].preco);
    fflush(stdin);
    ++*quanti_cadastrados;
}

void listarProdutos(Produto *produtos, int quanti_cadastrados) {
    int i;
    puts("");
    printf("Produtos: \n\n");
    
    for (i = 0; i < quanti_cadastrados; i++) {
        printf("%d - Código: %d\n", i + 1, produtos[i].codigo);
        printf("    Nome: %s\n", produtos[i].nome);
        printf("    Preço: %.2f\n\n", produtos[i].preco);
    }
}


 void comprarProduto(Produto *produtos, Carrinho *carrinho, int quanti_cadastrados){
	int i, codigo;
	char op = ' ';
	printf("Digite o código do produto que você deseja: ");
	scanf("%d", &codigo);
	do{
		for(i=0; i < quanti_cadastrados; i++){
			if(produtos[i].codigo == codigo){
				break;
			} else {
				puts("Este código digita não existe. Tente novamente!");
			}
		}
        
		printf("Deseja continuar a comprar? [S/N]");
		scanf("%c", &op);
	}while(op != 'S', op != 's', op != 'N', op != 'n');
}
