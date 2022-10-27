#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define SIZE 200

// Declaração das Estruturas a serem utilizadas
typedef struct enderecoStruct {
    char rua[40];
    char bairro[30];
    char numero[6];
    char cep[8];
    char cidade[20];
    char estado[20];
} Endereco;

typedef struct CadastroPessoaStruct {
    char nome[40];
    char reg[12];
    char rg[10];
    char telefone[11];
    Endereco end;
} Pessoa;

// Declaração das variáveis
int input = 0;
int opcao = 0;
int qtdClientes;
int tamClientes;
Pessoa *clientes;
FILE *arquivo;
char clientes_dir[] = "Clientes.bin";

// variaveis funcionario
int qtdFuncionario;
int tamFuncionario;
Pessoa *Funcionario;
FILE *arquivo;
char Funcionario_dir[] = "Funcionario.bin";

// Declaração dos Procedimentos e Funções a serem utilizados
void menuPrincipal();

void menuClientes();

void menuAlterarCliente();

void removerQuebraLinha();

Pessoa receberCliente();

Endereco receberEndereco();

void inserirCliente();

void buscarCliente();

void alterarEndereco();

void alterarNomeCliente();

void alterarTelefoneCliente();

int removerCliente();

void listarClientes();

/// variaveis de funcionarios
void menuFuncionario();

void menuAlterarFuncionario();

void removerQuebraLinha();

Pessoa receberFuncionario();

Endereco receberEndereco();

void inserirFuncionario();

Pessoa *buscarFuncionario();

void alterarEndereco();

void alterarNomeFuncionario();

void alterarTelefoneFuncionario();

int removerFuncionario();

void listarFuncionario();

// Início do main
int main(int argc, char **argv) {
    telaLogin();
    return 0;
}

void telaLogin() {
    menuPrincipal();

//    char login[15] = "teste";
//    char login1[15];
//    char senha[15] = "teste";
//    char senha1[15];
//
//    printf("Digite o Login: ");
//    scanf("%s", login1);
//
//    printf("Digite a Senha: ");
//    scanf("%s", senha1);
//
//    if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0) {
//
//        printf("\n\nLOGADO!\n\n");
//
//    } else
//
//        printf("\n\nDADOS INVALIDOS!\n\n");
}

void erro(char *nome_arquivo) {
    printf("Nao foi possivel abrir o arquivo %s\n", nome_arquivo);
}

void sucesso() {
    system("cls");
    printf("Operacao realizada com sucesso!");
}

void menuPrincipal() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|\t 1 - Cliente          |\n");
        printf("\t\t\t|\t 2 - Funcionario      |\n");
        printf("\t\t\t|\t 3 - Relatorios       |\n");
        printf("\t\t\t|\t 4 - Vendas           |\n");
        printf("\t\t\t|\t 0 - Sair             |\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t===============================\n");
        printf("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch (input) {
            case 1:
                menuClientes();
                break;
            case 2:
                menuFuncionario();
                break;
            case 3:
                buscarCliente();
                break;
            case 4:
                break;
            case 0:
                exit(EXIT_SUCCESS);
            default:
                printf("\n\t\t\tOpcao invalida!\n\n");
                fflush(stdin);
        }
    } while (input != 0);
    system("cls");
}

void menuClientes() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Cadastrar Cliente      |\n");
        printf("\t\t\t|    2 - Buscar Cliente       |\n");
        printf("\t\t\t|    3 -     |\n");
        printf("\t\t\t|    4 - Alterar Cadastro     |\n");
        printf("\t\t\t|    5 - Excluir Cadastro     |\n");
        printf("\t\t\t|    6 - Menu Principal       |\n");
        printf("\t\t\t|    0 - Sair                 |\n");
        printf("\t\t\t|                             |\n");
        printf("\t\t\t===============================\n");
        printf("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch (input) {
            case 1:
                fflush(stdin);
                inserirCliente();
                break;
            case 2:
                buscarCliente();
                break;
            case 3:
                break;
            case 4:
                menuAlterarCliente();
                break;
            case 5:
                removerCliente(qtdClientes, clientes_dir);
                break;
            case 6:
                menuPrincipal();
                break;
            case 0:
                exit(EXIT_SUCCESS);
            default:
                printf("\n\t\t\tOpcao invalida!\n\n");
                fflush(stdin);
        }
    } while (input != 0);
    system("cls");
}

void menuAlterarCliente() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Alterar Nome         |\n");
        printf("\t\t\t|    2 - Alterar Telefone     |\n");
        printf("\t\t\t|    3 - Alterar Endereco     |\n");
        printf("\t\t\t|    4 - Menu Principal       |\n");
        printf("\t\t\t|    0 - Sair                 |\n");
        printf("\t\t\t|                             |\n");
        printf("\t\t\t===============================\n");
        printf("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch (input) {
            case 1:
                alterarNomeCliente();
                break;
            case 2:
                alterarTelefoneCliente();
                break;
            case 3:
                alterarEndereco();
                break;
            case 4:
                menuPrincipal();
                break;
            case 0:
                exit(EXIT_SUCCESS);
            default:
                printf("\n\t\t\tOpcao invalida!\n\n");
                fflush(stdin);
        }
    } while (input != 0);
    system("cls");
}

void removerQuebraLinha(char *string) {
    if (string != NULL && strlen(string) > 0) {
        short tamanho = strlen(string);
        if (string[tamanho - 1] == '\n') {
            string[tamanho - 1] = '\0';
        }
    }
}

void receberString(char *string_destino, int quantidade_caracteres) {
    fgets(string_destino, quantidade_caracteres, stdin);
    removerQuebraLinha(string_destino);
}

Pessoa receberCliente() {
    Pessoa p;

    printf("Nome: ");
    receberString(p.nome, 39);
    printf("CPF: ");
    receberString(p.reg, 13);
    fflush(stdin);
    printf("RG: ");
    receberString(p.rg, 11);
    fflush(stdin);
    printf("Telefone: ");
    receberString(p.telefone, 12);
    fflush(stdin);

    p.end = receberEndereco();

    sucesso();
    return p;
}

Endereco receberEndereco() {
    Endereco e;

    printf("Rua: ");
    receberString(e.rua, 39);
    fflush(stdin);
    printf("Numero: ");
    receberString(e.numero, 5);
    fflush(stdin);
    printf("CEP: ");
    receberString(e.cep, 9);
    fflush(stdin);
    printf("Bairro: ");
    receberString(e.bairro, 29);
    printf("Cidade: ");
    receberString(e.cidade, 20);
    printf("Estado: ");
    receberString(e.estado, 20);

    sucesso();
    return e;
}

void inserirCliente() {

    Pessoa pessoa;
    FILE *file;
    file = fopen("teste.txt", "a+");
    if (file == NULL) {
        printf("ERRO!");
        exit(1);
    }

    printf("Entre com o Nome: ");
    scanf("%s", pessoa.nome);
    printf("Entre com o RG: ");
    scanf("%s", pessoa.rg);
    printf("Entre com o Endereco: ");
    scanf("%s", pessoa.telefone);

    fprintf(file, "%s;%s;%s;", pessoa.nome, pessoa.rg, pessoa.telefone);
    fclose(file);
    exit(1);
}

void listarClientes() {
    int n;
    char nome[20];
    printf("Digite numero de linhas desejada: ");
    scanf("%d", &n);
    FILE *file;
    file = fopen("teste.txt", "r+");
    for (int i = 0; i < n; ++i) {
        fscanf(file, "%s", nome);
        printf("%s\n", nome);
    }
}


void buscarCliente() {
    int i;
    char nome[20];
    FILE *file;
    file = fopen("teste.txt", "r");
    while (1) {
        i = fgetc(file);
        if (feof(file)) {
            break;
        }

        printf("%c", i);
    }
    fclose(file);
}

void alterarNomeCliente() {
    int i;
    char cpf[11], nome[40];
    printf("Digite o CPF do cliente a ter o nome alterado: ");
    fgets(cpf, 11, stdin);
    printf("Digite o novo nome: ");
    fgets(nome, 39, stdin);
    for (i = 0; i < qtdClientes; i++) {
        if (strcmp(clientes[i].reg, cpf) == 0) {
            strcpy(clientes[i].nome, nome);
            break;
        }
    }
}

void alterarTelefoneCliente() {
    int i;
    char cpf[11], fone[11];
    printf("Digite o CPF do cliente a ter o telefone alterado: ");
    fgets(cpf, 11, stdin);
    printf("Digite o novo numero: ");
    fgets(fone, 11, stdin);
    for (i = 0; i < qtdClientes; i++) {
        if (strcmp(clientes[i].reg, cpf) == 0) {
            strcpy(clientes[i].telefone, fone);
            break;
        }
    }
}

void alterarEndereco() {
    int i;
    char cpf[12];
    printf("Digite o CPF do cliente a ter o endereco alterado: ");
    fgets(cpf, 11, stdin);
    Endereco e;
    e = receberEndereco();
    for (i = 0; i < qtdClientes; i++) {
        if (strcmp(clientes[i].reg, cpf) == 0) {
            clientes[i].end = e;
            break;
        }
    }
}


int removerCliente(int qtd, char *dir) {
    int i, CPF, sucess = 0;
    printf("Digite o CPF do cliente que deseja remover: ");
    scanf("%d", &CPF);
    for (i = 0; i < qtd; i++) {
        if ((clientes[i].reg - CPF) == 0) {
            while (i < qtd - 1) {
                clientes[i] = clientes[i + 1];
                i++;
            }
            qtd--;
            sucess = 1;
            break;
        } else {
            erro(dir);
        }
    }
}

/// FUNCIONARIO

void menuFuncionario() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===================================\n");
        printf("\t\t\t|\t                           |\n");
        printf("\t\t\t|    1 - Listar Funcionarios       |\n");
        printf("\t\t\t|    2 - Buscar Funcionarios       |\n");
        printf("\t\t\t|    3 - Cadastrar Funcionarios    |\n");
        printf("\t\t\t|    4 - Alterar Cadastro          |\n");
        printf("\t\t\t|    5 - Excluir Cadastro          |\n");
        printf("\t\t\t|    6 - Menu Principal            |\n");
        printf("\t\t\t|    0 - Sair                      |\n");
        printf("\t\t\t|                                  |\n");
        printf("\t\t\t===================================\n");
        printf("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch (input) {
            case 1:
                listarFuncionario();
                break;
            case 2:
                buscarFuncionario();
                break;
            case 3:
                fflush(stdin);
                inserirFuncionario(receberFuncionario());
                break;
            case 4:
                menuAlterarFuncionario();
                break;
            case 5:
                removerFuncionario(qtdFuncionario, Funcionario_dir);
                break;
            case 6:
                menuPrincipal();
                break;
            case 0:
                exit(EXIT_SUCCESS);
            default:
                printf("\n\t\t\tOpcao invalida!\n\n");
                fflush(stdin);
        }
    } while (input != 0);
    system("cls");
}

void menuAlterarFuncionario() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Alterar Nome         |\n");
        printf("\t\t\t|    2 - Alterar Telefone     |\n");
        printf("\t\t\t|    3 - Alterar Endereco     |\n");
        printf("\t\t\t|    4 - Menu Principal       |\n");
        printf("\t\t\t|    0 - Sair                 |\n");
        printf("\t\t\t|                             |\n");
        printf("\t\t\t===============================\n");
        printf("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch (input) {
            case 1:
                alterarNomeFuncionario();
                break;
            case 2:
                alterarTelefoneFuncionario();
                break;
            case 3:
                alterarEndereco();
                break;
            case 4:
                menuPrincipal();
                break;
            case 0:
                exit(EXIT_SUCCESS);
            default:
                printf("\n\t\t\tOpcao invalida!\n\n");
                fflush(stdin);
        }
    } while (input != 0);
    system("cls");
}

Pessoa receberFuncionario() {
    Pessoa p;

    printf("Nome: ");
    receberString(p.nome, 39);
    printf("CPF: ");
    receberString(p.reg, 13);
    fflush(stdin);
    printf("RG: ");
    receberString(p.rg, 11);
    fflush(stdin);
    printf("Telefone: ");
    receberString(p.telefone, 12);
    fflush(stdin);

    p.end = receberEndereco();

    sucesso();
    return p;
}

void inserirFuncionario(Pessoa p) {
    if (qtdFuncionario == tamFuncionario) {
        tamFuncionario *= 1.5;
        Funcionario = realloc(Funcionario, tamFuncionario * sizeof(Pessoa));
    }
    clientes[qtdFuncionario] = p;
    qtdFuncionario++;
}

void listarFuncionario() {
    int c;
    printf("\nListando %d funcionario cadastrados\n", qtdFuncionario);
    for (c = 0; c < qtdFuncionario; c++) {
        printf("-----------------------------------\n");
        printf("(%d)\n", c + 1);
        printf("Nome  = %s\n", Funcionario[c].nome);
        printf("CPF = %s\n", Funcionario[c].reg);
        printf("RG = %s\n", Funcionario[c].rg);
        printf("Telefone = %s\n", Funcionario[c].telefone);
        printf("Endereco = %s", Funcionario[c].end.rua);
        printf(" - %s,", Funcionario[c].end.numero);
        printf(" %s,", Funcionario[c].end.bairro);
        printf(" %s", Funcionario[c].end.cidade);
        printf(" - %s.", Funcionario[c].end.estado);
    }
}

void alterarNomeFuncionario() {
    int i;
    char cpf[11], nome[40];
    printf("Digite o CPF do cliente a ter o nome alterado: ");
    fgets(cpf, 11, stdin);
    printf("Digite o novo nome: ");
    fgets(nome, 39, stdin);
    for (i = 0; i < qtdFuncionario; i++) {
        if (strcmp(Funcionario[i].reg, cpf) == 0) {
            strcpy(Funcionario[i].nome, nome);
            break;
        }
    }
}

void alterarTelefoneFuncionario() {
    int i;
    char cpf[11], fone[11];
    printf("Digite o CPF do cliente a ter o telefone alterado: ");
    fgets(cpf, 11, stdin);
    printf("Digite o novo numero: ");
    fgets(fone, 11, stdin);
    for (i = 0; i < qtdFuncionario; i++) {
        if (strcmp(Funcionario[i].reg, cpf) == 0) {
            strcpy(Funcionario[i].telefone, fone);
            break;
        }
    }
}

Pessoa *buscarFuncionario() {
    Pessoa *p = NULL;
    int i;
    char cpf[12];
    printf("Digite o CPF do cliente a ser buscado: ");
    fgets(cpf, 11, stdin);
    for (i = 0; i < qtdFuncionario; i++) {
        if (strcmp(Funcionario[i].reg, cpf) == 0) {
            p = &Funcionario[i];
            break;
        }
    }
    return p;
}

int removerFuncionario(int qtd, char *dir) {
    int i, CPF, sucess = 0;
    printf("Digite o CPF do cliente que deseja remover: ");
    scanf("%d", &CPF);
    for (i = 0; i < qtd; i++) {
        if ((Funcionario[i].reg - CPF) == 0) {
            while (i < qtd - 1) {
                Funcionario[i] = Funcionario[i + 1];
                i++;
            }
            qtd--;
            sucess = 1;
            break;
        } else {
            erro(dir);
        }
    }

    return sucess;
}