#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct cliente{

int codigo;
    char nome[100];
    char endereco[200];
};

struct Recebimento{
int num_doc;
float valordoc;
int data_emissao;
int data_vencimento;
int codcli;


};

//struct Recebimento verificar_documento(FILE *r)
//void alterar_cliente(FILE *i, int n);
//void alterar_documento(FILE *j, int n);

int main()
{
    int cadTotal = 1,docu = 1, op, opCase;
    char d;
    struct cliente c, aux;
    struct Recebimento r;

    FILE *cli,*rec;

    printf("Bem-vindo ao cadTotalastro do local\n\n");

    do {
        printf("Criar cliente [1] Criar documento [2] Adicionar recebimento [3] Alterar Cliente [4] Alterar Recebimento [5] Deletar Clientes e Recebimentos: ");
        scanf("%i", &op);
        getchar();

        switch(op) {
            case 1:
                // Verifica se já existe cliente
                cli = fopen("clientes.dat", "rb");

                if (cli != NULL) {
                    // Vai até o último cliente para pegar o último código
                    fseek(cli, -sizeof(struct cliente), SEEK_END);
                    fread(&aux, sizeof(struct cliente), 1, cli);
                    cadTotal = aux.codigo + 1;
                    fclose(cli);
                }

                // Coleta dados do cliente
                printf("Digite o nome: ");
                fgets(c.nome, sizeof(c.nome), stdin);

                printf("Endereco: ");
                fgets(c.endereco, sizeof(c.endereco), stdin);

                c.codigo = cadTotal;

                // Grava novo cliente
                cli = fopen("clientes.dat", "ab");
                fwrite(&c, sizeof(struct cliente), 1, cli);
                fclose(cli);

                printf("Cliente %d cadTotalastrado com sucesso.\n", c.codigo);
                break;

            default:
                printf("Opcao invalida\n");

                  case 2:

            printf("-----Area para criar novo recebimento-----\n\n");
            printf("Digite o numero do cliente que tera esse recebimento\n");
            scanf("%i",&opCase);
            if(cli = fopen("clientes.dat","rb") == NULL)
            {
                printf("O arquivo nao existe!\n");
                break;
            }
            else{
                while(!feof(rec))
                {
                    fread(&c,sizeof(struct cliente),1,cli);

                    if(c.codigo == opCase)
                    {
                        printf("O cliente foi achado, seu numero e %i\n\n",c.codigo);
                        printf("Agora digite o valor do documento\n");
                        scanf("%f",&r.valordoc);
                        r.codcli = c.codigo;

                        break;
                    }
                }

            }


    //    case 3:

  //      case 4:

//        case 5:

        }



        printf("Deseja continuar? [s/n]: ");
        scanf(" %c", &d);
        getchar(); // limpa o buffer

    } while(d != 'n' && d != 'N');

    // Exibe os clientes cadTotalastrados
    cli = fopen("clientes.dat", "rb");

    if (cli != NULL) {
        printf("\nLista de clientes:\n\n");
        while (fread(&aux, sizeof(struct cliente), 1, cli)) {
            printf("Codigo: %i\n", aux.codigo);
            printf("Nome: %s", aux.nome);
            printf("Endereco: %s\n", aux.endereco);
            printf("----------------------------\n");
        }
        fclose(cli);
    }



    return 0;
}
void alterar_cliente(FILE *i, int n) //função que altera o cliente
{
    struct cliente c;
    fseek(i,n*sizeof(struct cliente),SEEK_SET);
    i = fopen("clientes.dat","rb+");
    c.codigo = n;
    printf("Digite o nome: ");
                fgets(c.nome, sizeof(c.nome), stdin);

                printf("Endereco: ");
                fgets(c.endereco, sizeof(c.endereco), stdin);

    fwrite(&c,sizeof(struct cliente),1,i);

    fclose(i);


}
/*
void alterar_documento(FILE *j, int n){ //função que altera o recebimento


     struct Recebimento r;
    fseek(j,n*sizeof(struct Recebimento),SEEK_SET);
    j = fopen("Recebimento.dat","rb+");

    printf("Digite o nome: ");
                fgets(c.nome, sizeof(c.nome), stdin);

                printf("Endereco: ");
                fgets(c.endereco, sizeof(c.endereco), stdin);

    fwrite(&c,sizeof(struct Recebimento),1,j);

     fclose(j);

}
struct Recebimento verificar_documento(FILE *r){ //função que verifica o documento e retorna o número do documento

struct Recebimento rec;
if(r.open("recebimentos.dat","rb") == NULL)
{
    printf("Arquivo nao existe!\n");
    return 1;
}
else
{
    while(!feof(r))
    {
        fread(rec,sizeof(struct Recebimento),1,r);
        return rec;

    }
}


}
*/
