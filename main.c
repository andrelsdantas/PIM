#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <time.h>
//Acima temos as BIBLIOTECAS

//--------------------------------------------

#define SIZE 200
//Acima temos uma DECLARACAO DE CONSTANTE
//Quando o programa é compilado, o compilador substitui as ocorrências das constantes definidas pelo valor declarado.
//As constantes tem duas vantagens principais:
//1 – facilitam a modificação do programa
//2 – tornam o programa mais legível.

//--------------------------------------------

//Structs, também conhecidas como Registros, definem tipos de dados que agrupam variáveis sob um mesmo tipo de dado.
//A ideia de usar uma struct é permitir que, ao armazenar os dados de uma mesma entidade, isto possa ser feito com uma única variável.

typedef struct CadastroPessoaStruct {
    char nome[40];  // variavel que recebe o nome do cliente / ou funcionario
    char reg[12];  // variavel que recebe o CPF do cliente / ou funcionario
    char rg[10];  // variavel que recebe o RG do cliente / ou funcionario
    char telefone[11];  // variavel que recebe o telefone do cliente / ou funcionario
    char rua[40];  // variavel que recebe a rua do Endereco do Cliente / ou funcionario
    char bairro[30];  // variavel que recebe o bairro do Endereco do Cliente / ou funcionario
    char numero[6];  // variavel que recebe o numero do Endereco do Cliente / ou funcionario
    char num[6];  // variavel que recebe o numero residencial do endereco do Cliente ou funcionario
    char cep[8];  // variavel que recebe o CEP do cliente/ ou funcionario
    char cidade[20];  // variavel que recebe a cidade do cliente/ ou funcionario
    char estado[20];  // variavel que recebe o estado do cliente / ou funcionario

} Pessoa; //a struct criou o objeto que carrega todas as info acima.
// Para criar essa estrutura foi necessario o estudo e pesquisa sobre orientacao a objetos.
// Acima temos a Declaracao da estrutura a ser utilizada.

//--------------------------------------------

int input = 0;
int opcao = 0;

// Acima temos a Declaração das variáveis
//--------------------------------------------

//Obs: void quer dizer VAZIO, ou seja: ele nos permite fazer funcoes que nao retornam nada e funcoes que nao tem parametros!
void menuPrincipal();
void menuClientes();
void inserirCliente();
void buscarCliente();

// Acima temos a Declaracao dos Procedimentos e Funcoes a serem utilizados no MenuPrincipal e MenuClientes
//--------------------------------------------

// CATALOGO <-
void menuCatalogo();
void menuAR();
void menuAR2();
void menuCozinha();
void menuPortas();
void menuBanheiro();
void menuSala();

//--------------------------------------------

// CATALOGO PARA SALVAR VENDAS
void menuCatalogo2();

//--------------------------------------------

// RELATORIO <-
void menuRelatorio();

//--------------------------------------------

//VENDAS <-
void menuVendas();
void inserirVendas();
void buscarVendas();

//--------------------------------------------
// Variaveis de funcionarios <-

void menuFuncionario();
void inserirFuncionario();

//--------------------------------------------
// Início do MAIN

int main(int argc, char **argv) {
    telaLogin();
    return 0;
}
void telaLogin() { // ESTRUTURA DA TELA DE LOGIN

    char login[15] = "teste";
    char login1[15];
    char senha[15] = "teste";
    char senha1[15];

      printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t DIGITE SEU LOGIN:    |\n");
        printf("\t\t\t===============================\n");
        printf("\n\n");
        scanf("%s", login1);

      printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t DIGITE SUA SENHA:    |\n");
        printf("\t\t\t===============================\n");
        printf("\n\n");
    scanf("%s", senha1);

    if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0) {
//--------------------------------------------
//comparacao das strings digitadas a variavel login1 e senha1 usando STRCMP,
//A função strcmp compara duas strings e devolve um valor inteiro que lhe diz qual das strings vem antes no código ASCII:
//Sintaxe: strcmp (string1, string2);
//--------------------------------------------
        printf("\n\nLOGADO!\n\n");
        system("cls"); // LIMPA O TERMINAL <---
        menuPrincipal(); // após o LOGIN ser efetivado com sucesso com login e senha corretos e chamado o menuPrincipal pro nosso sistema.

    } else

        printf("\n\nDADOS INVALIDOS!\n\n"); //caso usuario e senha nao corresponderem ao correto sera emitido essa mensagem e nao conseguira acessar o sistema.
}

void sucesso() {
    system("cls");
    printf("Operacao realizada com sucesso!");
}

void menuPrincipal() { //Estrutura do menu PRINCIPAL
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|\t 1 - Cliente          |\n");
        printf("\t\t\t|\t 2 - Funcionario      |\n");
        printf("\t\t\t|\t 3 - Relatorios       |\n");
        printf("\t\t\t|\t 4 - Catalogo de Prod.|\n");
        printf("\t\t\t|\t 5 - Vendas           |\n");
        printf("\t\t\t|\t 0 - Sair             |\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t===============================\n");
        printf("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch (input) { // Foi necessario o estudo do metodo do switch case que e basicamente uma forma de reduzir o uso de varios IF.
            case 1:
                menuClientes(); //caso o usuario entre com 1 e chamado a tela de menu clientes.
                break;
            case 2:
                menuFuncionario(); //caso o usuario entre com 2 e chamado a tela de menu funcionario.
                break;
            case 3:
                menuRelatorio(); //caso o usuario entre com 3 e chamado a tela de menu relatorio.
                break;
            case 4:
                menuCatalogo(); //caso o usuario entre com 4 e chamado a tela de menu catalogo.
                break;
            case 5:
                menuVendas(); //caso o usuario entre com 5 e chamado a tela de menu vendas.
                break;
            case 0: //caso o usuario entre com 0 o programa encerrara.
                exit(EXIT_SUCCESS);
            default:
                printf("\n\t\t\tOpcao invalida!\n\n");
                fflush(stdin);
        }
    } while (input != 0);
    system("cls");
}
//--------------------------------------------
// Daqui para frente todo MENU tera a mesma logica citada no menu PRINCIPAL
//--------------------------------------------
//RELATORIO
//--------------------------------------------
void menuRelatorio() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t================================\n");
        printf("\t\t\t|\t                       |\n");
        printf("\t\t\t|    1 - Relatorio Clientes    |\n");
        printf("\t\t\t|    2 - Relatorio Funcionarios|\n");
        printf("\t\t\t|    3 - Relatorio Produtos    |\n");
        printf("\t\t\t|    4 - Relatorio Vendas      |\n");
        printf("\t\t\t|    5 - Menu Principal        |\n");
        printf("\t\t\t|    0 - Sair                  |\n");
        printf("\t\t\t|                              |\n");
        printf("\t\t\t================================\n");
        printf("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch (input) {
            case 1:
                buscarCliente();
                break;
            case 2:
                buscarFuncionario();
                break;
            case 3:
                menuCatalogo();
            case 4:
                buscarVendas();
                break;
            case 5:
                menuPrincipal(); // RETORNA PRO MENU PRINCIPAL
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
//--------------------------------------------
// VENDAS
//--------------------------------------------
 void menuVendas() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Cadastrar Vendas     |\n");
        printf("\t\t\t|    2 - Lista de Vendas      |\n");
        printf("\t\t\t|    3 - Menu Principal       |\n");
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
                inserirVendas();
                break;
            case 2:
                buscarVendas();
                break;
            case 3:
                menuPrincipal();
                break;
            case 0:
                exit(EXIT_SUCCESS);
            default:
                printf("\n\t\t\tOpcao invalida!\n\n");
                fflush(stdin); //fflush() é normalmente usado apenas para fluxo de saída.
                //Sua finalidade é limpar (ou liberar) o buffer de saída e mover os dados do buffer para o console.
        }
    } while (input != 0);
    system("cls"); // Faz a limpeza do terminal.
}

void inserirVendas() { //Criado para inserir no relatorio novos dados.

    Pessoa pessoa;
    FILE *filex;
    filex = fopen("vendas.txt", "a+"); // o "a+" abre o arquivo para gravacao e leitura, e CRIA o arquivo se ele nao existir.
    if (filex == NULL) {
        printf("ERRO!");
        menuPrincipal(); //chama o menu principal de volta
    }

    printf("Digite o Nome do Cliente: "); //Printar na tela para o usuario digita
    scanf("%s", pessoa.nome);             //Ler a string e colocar dentro da variavel nome pertecente ao OBJETO pessoa
    printf("Digite o CPF do Cliente: ");
    scanf("%s", pessoa.reg);            //Ler a string e colocar dentro da variavel reg pertecente ao OBJETO pessoa
    fprintf(filex, "Nome do Cliente:%s\nCPF:%s\n", pessoa.nome, pessoa.reg);
    fclose(filex);
    //o fprintf printa/escreve os dados no ARQUIVO.
    printf("Selecione o produto vendido: ");
    menuCatalogo2();
    system("cls"); // Faz a limpeza do terminal.
    menuPrincipal(); //chama o menu principal de volta
}


void buscarVendas() { //Criado para abrir o relatorio de vendas
    int x;
    char nome[20];
    FILE *filex;
    filex = fopen("vendas.txt", "r"); // o "r" abre o arquivo para gravacao e leitura, porem o arquivo ja deve estar criado.
    while (1) {
        x = fgetc(filex);
        if (feof(filex)) {
            break;
        }

        printf("%c", x);
    }
    fclose(filex);
}

//--------------------------------------------
// CATALOGO
//--------------------------------------------

void menuCatalogo() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Aut. Cozinha         |\n");
        printf("\t\t\t|    2 - Aut. Ar Condiconado  |\n");
        printf("\t\t\t|    3 - Aut. Portas/Portões  |\n");
        printf("\t\t\t|    4 - Aut. Banheiros       |\n");
        printf("\t\t\t|    5 - Aut. Sala de estar   |\n");
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
                menuCozinha();
                break;
            case 2:
                menuAR();
                break;
            case 3:
                menuPortas();
                break;
            case 4:
                menuBanheiro();
                break;
            case 5:
                menuSala();
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
void menuCatalogo2() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Armarios inteligentes|\n");
        printf("\t\t\t|    2 - Chama do Fogao       |\n");
        printf("\t\t\t|    3 - Robo Lava-loucas     |\n");
        printf("\t\t\t|    4 - Cervejeira/Geladeira |\n");
        printf("\t\t\t|    5 - Integracao do AR     |\n");
        printf("\t\t\t|    6 - Controle a distancia |\n");
        printf("\t\t\t|    7 - Climax               |\n");
        printf("\t\t\t|    8 - Fech. Leitor bio     |\n");
        printf("\t\t\t|    9 - Fech.  Leitor Facial |\n");
        printf("\t\t\t|   10 - Fech. Senha          |\n");
        printf("\t\t\t|   11 - Portao Inteligente   |\n");
        printf("\t\t\t|   12 - Banheira Remota      |\n");
        printf("\t\t\t|   13 - Desodorizador Remoto |\n");
        printf("\t\t\t|   14 - Sauna Remota         |\n");
        printf("\t\t\t|   15 - Sofa TECH            |\n");
        printf("\t\t\t|   16 - Suporte Inteligente  |\n");
        printf("\t\t\t|   17 - LED TECH             |\n");
        printf("\t\t\t|    0 - Sair                 |\n");
        printf("\t\t\t|                             |\n");
        printf("\t\t\t===============================\n");
        printf("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
                FILE *filex;
                filex = fopen("vendas.txt", "a+");
        switch (input) {
            case 1:
                fprintf(filex,"Produto vendido: Armarios integrados\nValor: R$ 5950,00.\n-------------------------------------\n");
                break;
            case 2:
                fprintf(filex, "Produto vendido: Fogao\nValor: R$ 2650,00.\n-------------------------------------\n");
                break;
            case 3:
                fprintf(filex,"Produto vendido: Robo lava loucas\nValor: R$ 2450,00.\n-------------------------------------\n");
                break;
            case 4:
                fprintf(filex,"Produto vendido: Cervejeira/geladeira\nValor: R$ 4730,00.\n-------------------------------------\n");
                break;
            case 5:
                fprintf(filex,"Produto vendido: Integracao AR\nValor: R$ 350,00.\n-------------------------------------\n");
                break;
            case 6:
                fprintf(filex,"Produto vendido: Controle de temperatura\nValor: R$ 1650,00.\n-------------------------------------\n");
                break;
            case 7:
                menuAR2();
                break;
            case 8:
                fprintf(filex,"Produto vendido: Fechadura com leitor biometrico/digital.\nValor: R$ 650,00.\n-------------------------------------\n");
                break;
            case 9:
                printf(filex,"Produto vendido: Fechadura com leitor de perfil/facial.\nValor: R$ 1050,00.\n-------------------------------------\n");
                break;
            case 10:
                fprintf(filex,"Produto vendido: Fechadura com senha.\nValor: R$ 350,00.\n-------------------------------------\n");
                break;
            case 11:
                fprintf(filex,"Produto vendido: Sistema de ativacao de portao da garagem via celular.\nValor: R$ 750,00.\n-------------------------------------\n");
                break;
            case 12:
                fprintf(filex, "Produto vendido: Sistema da banheira\nValor: R$ 1650,00.\n-------------------------------------\n");
                break;
            case 13:
                fprintf(filex,"Produto vendido: Desodorizador de ambiente\nValor: R$ 350,00.\n-------------------------------------\n");
                break;
            case 14:
                fprintf(filex, "Produto vendido: Sistema da sauna\nValor: R$ 1350,00.\n-------------------------------------\n");
                break;
            case 15:
                fprintf(filex,"Produto vendido: Sofa retratil com climatizador\nValor: R$ 6350,00.\n-------------------------------------\n");
                break;
            case 16:
                fprintf(filex,"Produto vendido: Suporte pra TV HOUSE TECH\nValor: R$ 650,00.\n-------------------------------------\n");
                break;
            case 17:
                fprintf(filex,"Produto vendido: Iluminacao personalizada HOUSE TECH\nValor: R$ 2750,00.\n-------------------------------------\n");
                break;
            case 0:
                exit(EXIT_SUCCESS);
            default:
                printf("\n\t\t\tOpcao invalida!\n\n");
                fflush(stdin);
        }
    fclose(filex);
    system("cls"); // Faz a limpeza do terminal.
    printf("VENDA CADASTRADA COM SUCESSO!");
    menuPrincipal(); //chama o menu principal de volta
    } while (input != 0);
    system("cls");
}
void menuAR2()  {
        do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - 9000 BTUS            |\n");
        printf("\t\t\t|    2 - 12000 BTUS           |\n");
        printf("\t\t\t|    3 - 18000 BTUS           |\n");
        printf("\t\t\t|    0 - Sair                 |\n");
        printf("\t\t\t|                             |\n");
        printf("\t\t\t===============================\n");
        printf("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
                FILE *filex;
                filex = fopen("vendas.txt", "a+");
                switch (input) {
            case 1:
                fprintf(filex, "AR 9000 BTUS\nAlem de contar com o design exclusivo de nossos produtos.\n Valor: R$ 5950,00 incluso instalacao.");
                break;
            case 2:
                printf(filex, "AR 12000 BTUS\nValor: R$ 2650,00.");
                break;
            case 3:
                fprintf(filex, "AR 18000 BTUS\nValor: R$ 2450,00.");
                break;
            case 0:
                exit(EXIT_SUCCESS);
            default:
                printf("\n\t\t\tOpcao invalida!\n\n");
                fflush(stdin);
        }
    }while (input != 0);
    system("cls");
}

void menuCozinha() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Armarios inteligentes|\n");
        printf("\t\t\t|    2 - Chama do Fogao       |\n");
        printf("\t\t\t|    3 - Robo Lava-loucas     |\n");
        printf("\t\t\t|    4 - Cervejeira/Geladeira |\n");
        printf("\t\t\t|    5 - Menu Principal       |\n");
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
                printf("Armarios integrados, com abetura e fechamento por controle remoto em um raio de ate 20km.\nAlem de contar com o design exclusivo de nossos produtos.\n Valor: R$ 5950,00 incluso instalacao.");
                break;
            case 2:
                printf("Fogao com acionamento de chama por voz e altura da chama regulavel por controle de voz.\nValor: R$ 2650,00 com instalacao");
                break;
            case 3:
                printf("Robo lava/seca loucas, com velocidade superior a qualquer um do mercado e exclusiva tecnologia House TECH.\nValor: R$ 2450,00 com instalacao");
                break;
            case 4:
                printf("Cervejeira/geladeira com controle remoto de temperatura que pode ser acionado em um raio de ate 20km.\n Valor: R$ 4730,00 com instalacao");
                break;
            case 5:
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

void menuAR() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Integracao           |\n");
        printf("\t\t\t|    2 - Controle a distancia |\n");
        printf("\t\t\t|    3 - Climax               |\n");
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
                printf("Integracao do funcionamento de todos aparelhos de ar condicionado da residencia.\nValor: R$ 350,00 por aparelho.");
                break;
            case 2:
                printf("Controle remoto que controla a temperatura da residencia em um raio de ate 20km.\n Obs: Para que todos funcionem simultaneamente e necessario realizar a integracao dos aparelhos de sua residencia.\nValor: R$ 1650,00 com instalacao");
                break;
            case 3:
                printf("O CLIMAX e o ar condicionado inteligente exclusivo da HOUSE TECH que alem de deixar a sua casa na temperatura agradavel ideal, prioriza a economia de energia.\nValor: R$ 2750,00 com instalacao para 9000BTUS\nValor: R$ 3750,00 com instalacao para 12000BTUS\nValor: R$ 5750,00 com instalacao para 18000BTUS\n");
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
//--------------------------------------------

void menuPortas() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Fech. Leitor bio     |\n");
        printf("\t\t\t|    2 - Fech.  Leitor Facial |\n");
        printf("\t\t\t|    3 - Fech. Senha          |\n");
        printf("\t\t\t|    4 - Portao Inteligente   |\n");
        printf("\t\t\t|    5 - Menu Principal       |\n");
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
                printf("Fechadura com leitor biometrico/digital.\nValor: R$ 650,00 por porta.");
                break;
            case 2:
                printf("Fechadura com leitor de perfil/facial.\nValor: R$ 1050,00 por porta.");
                break;
            case 3:
                printf("Fechadura com senha.\nValor: R$ 350,00 por porta.");
                break;
            case 4:
                printf("Sistema de ativacao de portao da garagem via celular.\nValor: R$ 750,00 por portao.");
                break;
            case 5:
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
//--------------------------------------------

void menuBanheiro() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Banheira Remota      |\n");
        printf("\t\t\t|    2 - Desodorizador Remoto |\n");
        printf("\t\t\t|    3 - Sauna Remota         |\n");
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
                printf("Sistema adicionavel a sua banheira para que voce encha ou esvazie ela estando em um raio de ate 20km.\n Ativacao por Celular.\nValor: R$ 1650,00 com instalacao.");
                break;
            case 2:
                printf("Desodorizador de ambiente ativavel via celular em um raio de ate 20km.\nValor: R$ 350,00.");
                break;
            case 3:
                printf("Sistema para acionar/desligar via celular a sua sauna estando em um raio de ate 20km.\nValor: R$ 1350,00.");
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
//--------------------------------------------

void menuSala() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Sofa TECH            |\n");
        printf("\t\t\t|    2 - Suporte Inteligente  |\n");
        printf("\t\t\t|    3 - LED TECH             |\n");
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
                printf("Sofa retratil com climatizador interno controlado via CELULAR pelo sistema HOUSE TECH\nValor: R$ 6350,00.");
                break;
            case 2:
                printf("Suporte pra TV que por controle remoto a coloca em qualquer angulo possivel\nValor: R$ 650,00 com instalacao.");
                break;
            case 3:
                printf("Iluminacao personalizada HOUSE TECH toda controlada via Smartphone.\nSUA SALA TECH!\nValor: R$ 2750,00 com instalacao.");
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
//--------------------------------------------
// CLIENTES
//--------------------------------------------

void menuClientes() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Cadastrar Cliente    |\n");
        printf("\t\t\t|    2 - Lista de Clientes    |\n");
        printf("\t\t\t|    3 - Menu Principal       |\n");
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
//--------------------------------------------

void inserirCliente() { //Usado para inserir/gravar o cliente no arquivo txt

    Pessoa pessoa;
    FILE *file;
    file = fopen("clientes.txt", "a+");
    if (file == NULL) {
        printf("ERRO!");
        menuPrincipal(); //chama o menu principal de volta;
    }

    printf("Digite o Nome: ");
    scanf("%s", pessoa.nome);
    printf("Digite o CPF: ");
    scanf("%s", pessoa.reg);
    printf("Digite Numero de telefone: ");
    scanf("%s", pessoa.telefone);
    printf("Digite o RG: ");
    scanf("%s", pessoa.rg);
    printf("Digite o CEP: ");
    scanf("%s", pessoa.cep);
    printf("Digite a Rua: ");
    scanf("%s", pessoa.rua);
    printf("Digite o Bairro: ");
    scanf("%s", pessoa.bairro);
    printf("Digite o Numero: ");
    scanf("%s", pessoa.num);
    printf("Digite a Cidade: ");
    scanf("%s", pessoa.cidade);
    printf("Digite o Estado: ");
    scanf("%s", pessoa.estado);

    fprintf(file,
            "Nome:%s\nCPF:%s\nTelefone:%s\nRG:%s\nCEP:%s\nRua:%s\nBarrio:%s\nNumero:%s\nCidade:%s\nEstado:%s\n-------------------------------------\n",
            pessoa.nome, pessoa.reg, pessoa.telefone, pessoa.rg, pessoa.cep, pessoa.rua, pessoa.bairro, pessoa.num,
            pessoa.cidade, pessoa.estado);
    fclose(file);
    system("cls"); // Faz a limpeza do terminal.
    printf("CLIENTE CADASTRADO COM SUCESSO!");    //Mensagem de cadastro realizado com sucesso.
    menuPrincipal(); //chama o menu principal de volta
}
//--------------------------------------------

void buscarCliente() { //Busca a lista de Clientes cadastrados
    int i;
    char nome[20];
    FILE *file;
    file = fopen("clientes.txt", "r");
    while (1) {
        i = fgetc(file);
        if (feof(file)) {
            break;
        }

        printf("%c", i);
    }
    fclose(file);
}
//--------------------------------------------
// FUNCIONARIOS
//--------------------------------------------

void menuFuncionario() {
    do {
        printf("\n");
        printf("\t\t\t\t  HOUSE TECH!\n");
        printf("\t\t\t===============================\n");
        printf("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Cadastrar Funcionario|\n");
        printf("\t\t\t|    2 - Lista de Funcionarios|\n");
        printf("\t\t\t|    3 - Menu Principal       |\n");
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
                inserirFuncionario();
                break;
            case 2:
                buscarFuncionario();
                break;
            case 3:
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
//--------------------------------------------

void inserirFuncionario() { //Adiciona ao arquivo txt o cadastro de um novo funcionario

    Pessoa pessoa;
    FILE *filef;
    filef = fopen("funcionario.txt", "a+");
    if (filef == NULL) {
        printf("ERRO!");
        exit(1);
    }

    printf("Digite o Nome: ");
    scanf("%s", pessoa.nome);
    printf("Digite o CPF: ");
    scanf("%s", pessoa.reg);
    printf("Digite Numero de telefone: ");
    scanf("%s", pessoa.telefone);
    printf("Digite o RG: ");
    scanf("%s", pessoa.rg);
    printf("Digite o CEP: ");
    scanf("%s", pessoa.cep);
    printf("Digite a Rua: ");
    scanf("%s", pessoa.rua);
    printf("Digite o Bairro: ");
    scanf("%s", pessoa.bairro);
    printf("Digite o Numero: ");
    scanf("%s", pessoa.num);
    printf("Digite a Cidade: ");
    scanf("%s", pessoa.cidade);
    printf("Digite o Estado: ");
    scanf("%s", pessoa.estado);

    fprintf(filef,
            "Nome:%s\nCPF:%s\nTelefone:%s\nRG:%s\nCEP:%s\nRua:%s\nBarrio:%s\nNumero:%s\nCidade:%s\nEstado:%s\n-------------------------------------\n",
            pessoa.nome, pessoa.reg, pessoa.telefone, pessoa.rg, pessoa.cep, pessoa.rua, pessoa.bairro, pessoa.num,
            pessoa.cidade, pessoa.estado);
    fclose(filef);
    system("cls"); // Faz a limpeza do terminal.
    printf("FUNCIONARIO CADASTRADO COM SUCESSO!");    //Mensagem de cadastro realizado com sucesso.
    menuPrincipal(); //chama o menu principal de volta
}
//--------------------------------------------

void buscarFuncionario() { // Busca e mostra a lista de funcionarios cadastrados.
    int f;
    char nome[20];
    FILE *filef;
    filef = fopen("funcionario.txt", "r");
    while (1) {
        f = fgetc(filef);
        if (feof(filef)) {
            break;
        }
        printf("%c", f);
    }
    fclose(filef);
    return 0;
}
//--------------------------------------------
