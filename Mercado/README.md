# Sistema de Carrinho de Compras em C

Este projeto é um sistema simples de carrinho de compras, desenvolvido em C. Ele oferece funcionalidades para cadastrar produtos, visualizar itens disponíveis, adicionar produtos ao carrinho, conferir o carrinho, finalizar pedidos (gerando uma nota fiscal) e esvaziar o carrinho.

## Como Navegar no Sistema

Após compilar e executar o código, você verá um menu interativo. Basta seguir as instruções na tela para realizar as diferentes operações. Aqui estão as opções disponíveis:

1. **Cadastrar produtos**: Adicione novos produtos ao sistema.
2. **Listar produtos**: Veja todos os produtos que foram cadastrados.
3. **Comprar produto**: Adicione produtos ao seu carrinho.
4. **Visualizar carrinho**: Confira os produtos que estão no carrinho.
5. **Fechar pedido**: Gere uma nota fiscal, veja o preço total e esvazie o carrinho.
6. **Sair do sistema**: Encerre o programa.

### Navegação Passo a Passo

- Após escolher uma opção, siga as instruções que aparecem no console, como digitar o código do produto ou confirmar suas ações.
- Para cadastrar um produto, você precisará informar um código, nome e preço.
- Para comprar um produto, basta inserir o código correspondente.
- Quando finalizar uma compra, o sistema criará um arquivo chamado `Nota_Fiscal.txt` com um resumo da sua compra.

## Explicação das Funções

Aqui estão as principais funções do sistema e uma breve explicação de cada uma:

### `main()`
A função principal onde tudo começa. Aqui o sistema é inicializado, o carrinho é esvaziado e o menu de opções é exibido para o usuário.

### `menu()`
Exibe o menu principal e gerencia a navegação, chamando as funções apropriadas conforme a opção selecionada.

### `cadastrarProduto()`
Permite que novos produtos sejam cadastrados. O usuário insere o código, nome e preço do produto, e a função valida essas informações antes de realizar o cadastro.

### `listarProdutos()`
Lista todos os produtos cadastrados, mostrando o código, nome e preço de cada um.

### `comprarProduto()`
Adiciona produtos ao carrinho. O usuário informa o código do produto desejado, e a função verifica se ele existe. Se o produto já estiver no carrinho, a quantidade é aumentada; caso contrário, o produto é adicionado.

### `visualizarCarrinho()`
Mostra os produtos que estão no carrinho, incluindo código, nome, preço e quantidade de cada item.

### `pegarProdutoPorCodigo()`
Procura um produto pelo seu código e retorna a posição dele na lista de produtos. Se não encontrar, retorna `-1`.

### `temNoCarrinho()`
Verifica se um produto específico já está no carrinho, retornando sua posição se estiver. Se não estiver, retorna `-1`.

### `esvaziarCarrinho()`
Reseta o carrinho, zerando as quantidades e códigos dos produtos após a finalização de um pedido.

### `notaFiscal()`
Gera um arquivo `Nota_Fiscal.txt` que contém a lista de produtos comprados, suas quantidades e o total da compra. Essa função é chamada ao fechar o pedido.

### `fecharPedido()`
Calcula o total da compra, chama a função `notaFiscal()` para gerar o recibo e, por fim, esvazia o carrinho.

---

Esse sistema representa uma implementação básica, mas funcional, de um carrinho de compras em C. Ele permite uma interação fácil pelo terminal e gera uma nota fiscal ao finalizar uma compra, oferecendo uma experiência simples e direta para o usuário.
