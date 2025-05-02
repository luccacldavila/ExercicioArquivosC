#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct cliente {
    int codigo;
    char nome[100];
    char endereco[200];
};

struct Recebimento {
    int num_doc;
    float valordoc;
    int codcli;
    struct tm data_emissao;
    struct tm data_vencimento;
};

// Função para abrir arquivos
FILE *abrir_arquivo(const char *nome, const char *modo) {
    FILE *f = fopen(nome, modo);
    if (f == NULL && modo[0] != 'w') {
        printf("Erro ao abrir %s\n", nome);
        exit(1);
    }
    return f;
}

// Função para calcular vencimento 10 dias depois
struct tm calcular_vencimento(struct tm emissao) {
    time_t raw_time = mktime(&emissao);
    raw_time += 10 * 24 * 60 * 60; // adiciona 10 dias
    return *localtime(&raw_time);
}

// Alterar cliente
void alterar_cliente(int codigo) {
    struct cliente c;
    FILE *f = abrir_arquivo("clientes.dat", "rb+");

    fseek(f, (codigo - 1) * sizeof(struct cliente), SEEK_SET);

    printf("Novo nome: ");
    fgets(c.nome, sizeof(c.nome), stdin);
    printf("Novo endereço: ");
    fgets(c.endereco, sizeof(c.endereco), stdin);
    c.codigo = codigo;

    fseek(f, (codigo - 1) * sizeof(struct cliente), SEEK_SET);
    fwrite(&c, sizeof(struct cliente), 1, f);
    fclose(f);
    printf("Cliente alterado com sucesso!\n");
}

// Alterar recebimento
void alterar_recebimento(int doc) {
    struct Recebimento r;
    FILE *f = abrir_arquivo("recebimentos.dat", "rb+");

    fseek(f, (doc - 1) * sizeof(struct Recebimento), SEEK_SET);
    fread(&r, sizeof(struct Recebimento), 1, f);

    printf("Novo valor: ");
    scanf("%f", &r.valordoc);
    getchar();

    time(&r.data_emissao);
    r.data_vencimento = calcular_vencimento(r.data_emissao);

    fseek(f, (doc - 1) * sizeof(struct Recebimento), SEEK_SET);
    fwrite(&r, sizeof(struct Recebimento), 1, f);
    fclose(f);
    printf("Recebimento alterado com sucesso!\n");
}

// Deletar arquivos
void deletar_arquivos() {
    remove("clientes.dat");
    remove("recebimentos.dat");
    printf("Todos os clientes e recebimentos foram apagados.\n");
}

int main() {
    int op, codCliente, docCodigo;
    struct cliente c, aux;
    struct Recebimento r;
    FILE *cli, *rec;
    char continuar = 's';

    printf("Bem-vindo ao cadastro do local\n");

    while (continuar != 'n' && continuar != 'N') {
        printf("\nMenu:\n");
        printf("[1] Criar cliente\n");
        printf("[2] Criar documento\n");
        printf("[3] Alterar cliente\n");
        printf("[4] Alterar recebimento\n");
        printf("[5] Deletar todos os dados\n");
        printf("Escolha: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1: {
                int codigo = 1;
                cli = fopen("clientes.dat", "rb");
                if (cli != NULL) {
                    fseek(cli, -sizeof(struct cliente), SEEK_END);
                    fread(&aux, sizeof(struct cliente), 1, cli);
                    codigo = aux.codigo + 1;
                    fclose(cli);
                }

                printf("Nome: ");
                fgets(c.nome, sizeof(c.nome), stdin);
                printf("Endereco: ");
                fgets(c.endereco, sizeof(c.endereco), stdin);
                c.codigo = codigo;

                cli = abrir_arquivo("clientes.dat", "ab");
                fwrite(&c, sizeof(struct cliente), 1, cli);
                fclose(cli);

                printf("Cliente cadastrado com código %d.\n", c.codigo);
                break;
            }
            case 2: {
                printf("Código do cliente: ");
                scanf("%d", &codCliente);
                getchar();

                cli = abrir_arquivo("clientes.dat", "rb");
                int encontrado = 0;

                while (fread(&c, sizeof(struct cliente), 1, cli)) {
                    if (c.codigo == codCliente) {
                        encontrado = 1;
                        break;
                    }
                }
                fclose(cli);

                if (!encontrado) {
                    printf("Cliente não encontrado.\n");
                    break;
                }

                r.codcli = codCliente;
                r.num_doc = codCliente; // ou outra lógica
                printf("Valor do documento: ");
                scanf("%f", &r.valordoc);
                getchar();

                time_t agora = time(NULL);
                r.data_emissao = *localtime(&agora);
                r.data_vencimento = calcular_vencimento(r.data_emissao);

                rec = abrir_arquivo("recebimentos.dat", "ab");
                fwrite(&r, sizeof(struct Recebimento), 1, rec);
                fclose(rec);

                printf("Recebimento cadastrado com sucesso.\n");
                break;
            }
            case 3:
                printf("Código do cliente para alterar: ");
                scanf("%d", &codCliente);
                getchar();
                alterar_cliente(codCliente);
                break;

            case 4:
                printf("Código do recebimento para alterar: ");
                scanf("%d", &docCodigo);
                getchar();
                alterar_recebimento(docCodigo);
                break;

            case 5:
                deletar_arquivos();
                break;

            default:
                printf("Opcao invalida.\n");
        }

        printf("Deseja continuar? [s/n]: ");
        scanf(" %c", &continuar);
        getchar();
    }

    return 0;
}
