#include <stdio.h>
#include <string.h>

int i = 0;
char lnx;

struct game
{
    char nome[50];
    float preco;
    char desenv[50];
    int lanc;
    char tipo[50];
};

void consulta(struct game *jogo, int *total);
void listar(struct game *jogo, int *total);
void atualizar(struct game *jogo, int *total);
void remover(struct game *jogo, int *total);
void consultatipo(struct game *jogo, int *total);
void inserir(struct game *jogo, int *total);

int main()
{
    int x = 1;
    int n;
    int total = 0;

    int menu;
    struct game jogo[30];

    printf("-------Biblioteca Virtual de Games-------");

    do
    {

        printf("\n             ----Menu----\n");
        printf("\nCadastrar             [1]\nListagem              [2]\nConsulta              [3]\nAtualizacao de preco  [4]      \nRemocao               [5]\nConsulta tipo         [6]");
        printf("\nInserir               [7]");
        printf("\nDigite a opcao:");
        scanf("%i", &menu);

        switch (menu)
        {
        case 1:

            printf("\nDigite a quantidade de jogos que deseja cadastrar:");
            scanf("%i", &n);

            for (i = 0; i < n; i++)
            {

                printf("\n*Game[%i]*", i);

                printf("\nDigite o preco:");
                scanf("%f", &jogo[i].preco);

                printf("Digite o nome do jogo:");
                //lnx = fgetc(stdin);
                fflush(stdin);
                fgets(jogo[i].nome, 50, stdin);

                printf("Digite o modo de jogo(multiplayer ou solo):");
                //lnx = fgetc(stdin);
                fflush(stdin);
                fgets(jogo[i].tipo, 50, stdin);

                printf("Digite o nome da desenvolvedora:");
                //lnx = fgetc(stdin);
                fflush(stdin);
                fgets(jogo[i].desenv, 50, stdin);

                printf("Digite o ano em que lancou:");
                scanf("%i", &jogo[i].lanc);

                total += 1;

                printf("\n*Game[%i] finalizado*\n", i);
            }
            break;

        case 2:
            listar(jogo, &total);
            break;

        case 3:
            consulta(jogo, &total);
            break;

        case 4:
            atualizar(jogo, &total);
            break;

        case 5:
            remover(jogo, &total);
            break;

        case 6:
            consultatipo(jogo, &total);
            break;

        case 7:
            inserir(jogo, &total);
            break;

        default:
            printf("\nOpcao nao existe.\n");
        }

        printf("\n----------------\nDeseja parar?\nSim[1]\nNao[0]\n");
        scanf("%i", &x);

    } while (x == 0);
}

void consulta(struct game *jogo, int *total)
{

    float consultaP;
    int c = 0;

    printf("\n------------------------\n");
    printf("Digite o preco:");
    scanf("%f", &consultaP);

    for (i = 0; i < *total; i++)
    {
        if (jogo[i].preco == consultaP)
        {
            c = 1;
            printf("\nNome:%s", jogo[i].nome);
            printf("Tipo:%s", jogo[i].tipo);
            printf("Preco:%.2f\n", jogo[i].preco);
            printf("Desenvolvedora:%s", jogo[i].desenv);
            printf("Ano de lancamento:%i\n", jogo[i].lanc);
        }

        if (c == 0)
            printf("\nJogo nao encontrado.");
    }
}

void listar(struct game *jogo, int *total)
{
    for (int i = 0; i < *total; i++)
    {
        printf("\n------------------------\n");
        printf("\n*Game[%i]*", i);
        printf("\nNome:%s", jogo[i].nome);
        printf("Tipo:%s", jogo[i].tipo);
        printf("Preco:R$%.2f", jogo[i].preco);
        printf("\nDesenvolvedora:%s", jogo[i].desenv);
        printf("Ano do lancamento:%i", jogo[i].lanc);
        printf("\n------------------------\n");
    }
}

void atualizar(struct game *jogo, int *total)
{
    char procuranome[50];
    int c = 0;

    printf("\nDigite o nome do jogo:");
    lnx = fgetc(stdin);
    fflush(stdin);
    fgets(procuranome, 50, stdin);

    for (i = 0; i < *total; i++)
    {
        if (strcmp(jogo[i].nome, procuranome) == 0)
        {
            printf("Digite o novo preco:");
            scanf("%f", &jogo[i].preco);

            printf("\nNovo preco do jogo %s:R$%0.2f", jogo[i].nome, jogo[i].preco);
        }

        else
            c++;
    }

    if (c == *total)
        printf("\nJogo nao encontrado.");
}

void remover(struct game *jogo, int *total)
{
    int pos, c = 0;

    printf("\n------------------------\n");
    printf("Posicao que deseja excluir:");
    scanf("%i", &pos);
    int i = 0;

    for (i = pos; i < *total; i++)
    {
        c = 1;
        if (i == pos)
        {
            jogo[i] = jogo[i + 1];
        }
    }

    if (c == 1)
    {
        *total -= 1;
    }

    if (c == 0)
    {
        printf("Invalido");
    }
}

void consultatipo(struct game *jogo, int *total)
{

    char modo[50];

    printf("\nDigite o modo de jogo:");
    lnx = fgetc(stdin);
    fflush(stdin);
    fgets(modo, 50, stdin);

    for (i = 0; i < *total; i++)
    {
        if (strcmp(jogo[i].tipo, modo) == 0)
        {
            printf("\n------------------------\n");
            printf("\nNome:%s", jogo[i].nome);
            printf("Preco:%.2f\n", jogo[i].preco);
            printf("Desenvolvedora:%s", jogo[i].desenv);
            printf("Ano de lancamento:%i\n", jogo[i].lanc);
            printf("\n------------------------\n");
        }
    }
}

void inserir(struct game *jogo, int *total)
{

    int t = 0;

    printf("\nDigite a quantidade de jogos que deseja cadastrar:");
    scanf("%i", &t);

    t = t + *total;

    for (i = *total; i < t; i++)
    {
        printf("\nde %i ate %i", i, t);

        printf("\n*Game[%i]*", i);

        printf("\nDigite o preco:");
        scanf("%f", &jogo[i].preco);

        printf("Digite o nome do jogo:");
        //lnx = fgetc(stdin);
        fflush(stdin);
        fgets(jogo[i].nome, 50, stdin);

        printf("Digite o modo de jogo(multiplayer ou solo):");
        //lnx = fgetc(stdin);
        fflush(stdin);
        fgets(jogo[i].tipo, 50, stdin);

        printf("Digite o nome da desenvolvedora:");
        //lnx = fgetc(stdin);
        fflush(stdin);
        fgets(jogo[i].desenv, 50, stdin);

        printf("Digite o ano em que lancou:");
        scanf("%i", &jogo[i].lanc);
        *total += 1;

        printf("\n*Game[%i] finalizado*\n", *total);
    }
}
