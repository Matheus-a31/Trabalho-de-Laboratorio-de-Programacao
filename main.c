#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUTOS 100
#define MAX_FORNECEDORES 5

typedef struct {
    char nome[100];
    float preco_sugerido;
    int prazo_entrega; // em dias
}Fornecedor;

typedef struct {
    char nome[100];
    int ref;
    Fornecedor fornecedores[MAX_FORNECEDORES];
    int num_fornecedores;
    float preco_venda;
    int estoque_existente;
}Produto;

void criarProduto(Produto produtos[], int *num_produtos) {
    Produto novo_produto;

    printf("Digite o nome do produto: ");
    scanf("%s", novo_produto.nome);
    printf("%s\n", novo_produto.nome);

    printf("Digite a referencia do produto: ");
    scanf("%d", &novo_produto.ref);
    printf("%d\n", novo_produto.ref);

    novo_produto.num_fornecedores = 0;

    printf("Digite o preco de venda do produto: ");
    scanf("%f", &novo_produto.preco_venda);
    printf("%f\n", novo_produto.preco_venda);

    printf("Digite a quantidade do estoque do produto: ");
    scanf("%d", &novo_produto.estoque_existente);
    printf("%d\n", novo_produto.estoque_existente);

    produtos[*num_produtos] = novo_produto;
    (*num_produtos)++;

    for (int i = 0; i < *num_produtos - 1; i++) {
        for (int j = i + 1; j < *num_produtos; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                Produto temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }
}

void adicionarFornecedor(Produto produtos[], int num_produtos) {
    // verificar o nome do produto que quer adicionar o fornecedor 
    char nome_produto[100];
    printf("Digite o nome do produto para adicionar o fornecedor: ");
    scanf("%s", nome_produto);
    // verificar se já tem fornecedores máximos
    for (int i = 0; i < num_produtos; i++) {
        if (strcmp(produtos[i].nome, nome_produto) == 0) {
            if (produtos[i].num_fornecedores >= MAX_FORNECEDORES) {
                printf("Não foi possível adicionar fornecedores, pois já tem o limite.");
            }
        }

    
        //pedir dados para o novo fornecedor
        Fornecedor novo_fornecedor;

        printf("Digite o nome do novo fornecedor: ");
        scanf("%s", novo_fornecedor.nome);

        printf("Digite o preco sugerido do novo fornecedor: ");
        scanf("%f", &novo_fornecedor.preco_sugerido);

        printf("Digite o prazo de entrega do novo fornecedor: ");
        scanf("%d", &novo_fornecedor.prazo_entrega);

        produtos[i].fornecedores[produtos[i].num_fornecedores] = novo_fornecedor;
        produtos[i].num_fornecedores++;
    }
}

void listarProdutos(Produto produtos[], int num_produtos) {
    for (int i = 0; i < num_produtos; i++) {
        printf("Nome: %s | Referencia: %d | Preco Venda: %.2f | Estoque: %d\n", produtos[i].nome, produtos[i].ref, produtos[i].preco_venda, produtos[i].estoque_existente);
    }
}

void retirarProdutos(Produto produtos[], int *num_produtos) {
    // verificar nome do produto para ser retirado
    char nome_produto[100];
    printf("Digite o nome do produto para ser retirado: ");
    scanf("%s", nome_produto);
    // verificar se nome_produto é igual a um produto da lista e removê-lo
    for (int i = 0; i < *num_produtos; i++) {
        if (strcmp(produtos[i].nome, nome_produto) == 0)  {
            for (int j = i; j < *num_produtos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*num_produtos)--;
        }
        printf("O produto foi retirado com sucesso!");
    }

}

void alterarPrecoSugerido(Produto produtos[], int num_produtos) {
    char nome_produto[100];
    char nome_fornecedor[100];
    printf("Digite o nome do produto que quer acessar o fornecedor: ");
    scanf("%s", nome_produto);

    for (int i = 0; i < num_produtos; i++) {
        if (strcmp(produtos[i].nome, nome_produto) == 0) {
            printf("Digite o nome do fornecedor: ");
            scanf("%s", nome_fornecedor);

            for (int j = 0; j< produtos[i].num_fornecedores; j++) {
                if (strcmp(produtos[i].fornecedores[j].nome, nome_fornecedor) == 0) {
                    printf("Digite o novo valor sugerido para o fornecedor digitado: ");
                    scanf("%f", &produtos[i].fornecedores[j].preco_sugerido);
                    printf("Preco sugerido atualizado");            
                }
            }
            printf("Não foi possível encontrar o fornecedor");
        }
    }
}


void alterarPrecoVenda(Produto produtos[], int num_produtos) {
    char nome_produto[100];
    printf("Digite o nome do produto: ");
    scanf("%s", nome_produto);

    for (int i = 0; i < num_produtos; i++) {
        if (strcmp(produtos[i].nome, nome_produto) == 0) {
            printf("Digite o novo preco de venda: ");
            scanf("%f", &produtos[i].preco_venda);
            printf("Preco de venda atualizado!");
        }
    }
}

void pesquisarMelhorFornedor() {
}

void pesquisarProdutoMaiorLucro() {
}

void verificarSatisfacaoEncomenda() {
}
// lista_produtos = [ [produto], [produto], ... ]
// [produto] = ['nome', 'preco', 'prazo']
int main() {
    Produto produtos[MAX_PRODUTOS];
    int num_produtos = 0;
    int opcao;

    do {
        printf("Menu de Opcoes: \n");
        printf("1 - Acrescentar Produto: \n");
        printf("2 - Adicionar Fornecedor: \n");
        printf("3 - Listar Produtos \n");
        printf("4 - Retirar Produtos \n");
        printf("5 - Alterar Preco Sugerido \n");
        printf("6 - Alterar Preco de Venda \n");
        printf("0 - Sair \n");
        printf("Escolha uma Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                criarProduto(produtos, &num_produtos);
                break;
            case 2:
                adicionarFornecedor(produtos, num_produtos);
            case 3: 
                listarProdutos(produtos, num_produtos);
                break;
            case 4:
                retirarProdutos(produtos, &num_produtos);
                break;
            case 5: 
                alterarPrecoSugerido(produtos, num_produtos);
                break;
            case 6: 
                alterarPrecoVenda(produtos, num_produtos);
            case 0: 
                break;  
            default:
                printf("Opcao invalida!");
                break;
        }
    } while (opcao != 0);
}