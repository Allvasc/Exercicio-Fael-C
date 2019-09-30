#include <stdio.h>

#include <string.h>

#include <locale.h>


// Criando um struct vendas
typedef struct {
    char cliente[200], produto[200];
    int quant, codigo;
    float vlr;
}
vendas;

// Inicializando vetor
vendas V[50];

// Inicialização das variaveis e atribução de valores
int posicao, op, i = 0, cod = 1, cont = 0;
char produto[200];
float total_geral;

// Criação das funções de cadastro e pesquisa
int cadastro(void);
int pesquisa(void);

// Função principal
int main(void) {

    setlocale(LC_ALL, "portuguese");

    cadastro();
    pesquisa();

    printf(" \n total de itens pesquisados: %d", cont);
    printf(" \n Soma geral: %2.0f", total_geral);
    printf(" \n ------------------------------------------------------------------------");

    return 0;
}

// Inicio da função cadastro
int cadastro(void) {

    for (i = 0; i < 20; i++) {
        strcpy(V[i].cliente, "NULL");
        strcpy(V[i].produto, "NULL");
        V[i].quant = 0;
        V[i].vlr = 0.0;
    }

    for (i = 0; i < 20; i++) {
        printf(" \n -------------------------- CADASTRO DE VENDA");
        printf(" %d ", cod);
        printf("-------------------------\n");
        printf(" Digite o nome do produto: ");
        scanf("%s%*c", & V[i].produto);
        printf(" Digite a quantidade: ");
        scanf("%d%*c", & V[i].quant);
        printf(" Digite o valor unitario: ");
        scanf("%f%*c", & V[i].vlr);
        printf(" Digite o nome do cliente: ");
        scanf("%s%*c", & V[i].cliente);

        V[i].codigo = cod++;
        printf(" \n ------------------------------------------------------------------------\n");
    }

};

// Inicio da função pesquisa
int pesquisa() {
   	
    do {
        printf(" \n -------------------------OPÇÕES DE PESQUISA-----------------------------\n");
        printf("\n Digite 1 para pesquisar venda por produto\n");
        printf("\n Digite 2 para total de vendas\n");
        scanf(" \n %d*c ", & op);
        printf(" \n ------------------------------------------------------------------------\n");

        switch (op) {
        case 1:
			
            printf(" \n Digite o nome do produto: ");
            scanf("%s%*c", produto);

            for (i = 0; i < 20; i++) {
                if (strcmp(produto, V[i].produto) == 0) {
                	
                    printf(" \n Codigo da venda: %d ", V[i].codigo);
                    printf(" \n Nome do produto: %s ", V[i].produto);
                    printf(" \n Nome do cliente: %s ", V[i].cliente);
                    printf(" \n ------------------------------------------------------------------------");
                }
            };
            break;
        case 2:

            for (i = 0; i < 20; i++) {
                printf(" \n Codigo da venda: %d ", V[i].codigo);
                printf(" \n Nome do produto: %s ", V[i].produto);
                printf(" \n Quantidade: %d ", V[i].quant);
                printf(" \n Valor do produto: %2.0f ", V[i].vlr);
                printf(" \n total da venda: %2.0f", V[i].quant * V[i].vlr);
                printf(" \n ------------------------------------------------------------------------");

                total_geral = total_geral + V[i].quant * V[i].vlr;
                cont++;
            }
            break;
        default:
            printf(" \n Opção invalida! ");
            break;
        }

    } while (op == 1);
};


