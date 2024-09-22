#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>

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
void comprarProduto(Produto *produtos, Carrinho *carrinho, int quanti_cadastrados, int *itens_carrinho);
void visualizarCarrinho(Carrinho *carrinho, int itens_carrinho);
int temNoCarrinho(Carrinho *carrinho, int *itens_carrinho);
void fecharPedido(Carrinho *carrinho, int *itens_carrinho);

int main(){
    // setlocale(LC_ALL, "Portuguese");

    Produto produtos[50];
    Carrinho carrinho[50];
    int i;
    for(i=0; i < 50; i++){ // inicializando para não haver lixo de memória.
        carrinho[i].produto.codigo = -1;
        carrinho[i].quantidade = 0;
    }

    menu(produtos, carrinho);
    return 0;
}

void menu(Produto *produtos, Carrinho *carrinho){
    int op = 0;
    int quanti_cadastrados = 0;
    int itens_carrinho = 0;
    do{
        puts("");
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
             comprarProduto(produtos, carrinho, quanti_cadastrados, &itens_carrinho);
            break;
        case 4:
            visualizarCarrinho(carrinho, itens_carrinho);
            break;
        case 5:
            fecharPedido(carrinho, &itens_carrinho);
            break;
        case 6:
            printf("Saindo do sistema!\n");
            break;
        }
    }while (op != 6);
}

void cadastrarProduto(Produto *produtos, int *quanti_cadastrados){
    if(produtos[*quanti_cadastrados].preco > 0){
        ++*quanti_cadastrados;
    }
    do{
        printf("Digite o código do produto: ");
        scanf("%d", &produtos[*quanti_cadastrados].codigo);
        setbuf(stdin, 0);
        printf("Digite o nome do produto: ");
        fgets(produtos[*quanti_cadastrados].nome, 30, stdin);
        produtos[*quanti_cadastrados].nome[strcspn(produtos[*quanti_cadastrados].nome, "\n")] = '\0';
        //setbuf(stdin, 0);
        printf("Digite o preço: ");
        scanf("%f", &produtos[*quanti_cadastrados].preco);
        setbuf(stdin, 0);
    }while(quanti_cadastrados <= 0);
}

void listarProdutos(Produto *produtos, int quanti_cadastrados) {
    int i;
    if(quanti_cadastrados > 0){
        printf("Produtos: \n\n");
        for (i = 0; i < quanti_cadastrados; i++) {
            printf("%d - Código: %d\n", i + 1, produtos[i].codigo);
            printf("    Nome: %s\n", produtos[i].nome);
            printf("    Preço: %.2f\n\n", produtos[i].preco);
        }
    }
    sleep(4);
}


 void comprarProduto(Produto *produtos, Carrinho *carrinho, int quanti_cadastrados, int *itens_carrinho){
	int i, j, codigo;
	char op = ' ';
	do{
        printf("Digite o código do produto que você deseja: ");
        scanf(" %d", &codigo);
		for(i=0; i < quanti_cadastrados; i++){
			if(produtos[i].codigo == codigo){
                for(j=0; j < 50; j++){
                    if(carrinho[j].produto.codigo == codigo){
                        carrinho[j].quantidade++;
                    } else if(carrinho[j].produto.codigo == -1){
                        carrinho[j].produto = produtos[i];
                        carrinho[j].quantidade++;
                    }
                }
				break;
			} else {
				puts("Este código digita não existe. Tente novamente!");
			}
		}
		printf("Deseja continuar a comprar? [S/N]\n");
		scanf(" %c", &op);
	}while(op != 'N' || op != 'n');
}

void visualizarCarrinho(Carrinho *carrinho, int itens_carrinho){
    int i;
    printf("Carrinho: \n\n");
    for (i = 0; i < itens_carrinho; i++) {
    printf("%d - Código: %d\n", i + 1, carrinho[i].produto.codigo);
    printf("    Nome: %s\n", carrinho[i].produto.nome);
    printf("    Preço: %.2f\n\n", carrinho[i].produto.preco);
    printf("    Quantidade: %d", carrinho[i].quantidade);
    }
    sleep(4);
}

int temNoCarrinho(Carrinho *carrinho, int *itens_carrinho){
    int codigo = 0, i;
    
    return codigo;
}

void fecharPedido(Carrinho *carrinho, int *itens_carrinho){
    int i;
    float preco_total = 0;

    for (i = 0; i < *itens_carrinho; i++){
        preco_total += carrinho[i].produto.preco;
    }
}

