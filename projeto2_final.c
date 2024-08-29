#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define max 15

struct voo
{
    int cod, escala;
    char ori[50], dest[50], cid_escala[5][50];
};

int conferecod(struct voo aux[],int total, int codigo)
{
    int i;
    for(i=0;i<total;i++)
    {
        if(aux[i].cod==codigo)
        {
            return 1;
        }
    }
    return 0;
}

void incluir(struct voo aux[], int *cont)
{
    int x, i, j;
    char opcao;

    do
    {
        printf("\n-----------------------------------------------------\n");
        printf("OPÇÃO 1: INCLUIR VOO(S)");
        printf("\n-----------------------------------------------------\n");
        do
        {
            printf("\nQuantos voos deseja adicionar? ");
            scanf("%d", &x);
            x += *cont;

            if(x>max)
            {
                printf("\nA quantidade máxima de voos a serem inseridos é 15.\n");
            }
        }while(x>max);

        for (i=*cont; i<x; i++)
        {
            printf("\n-----------------------------------------------------\n");
            printf("\n\tVOO %d\n", i+1);

            do
            {
                printf("\n\tInsira o código do voo: ");
                scanf("%d", &aux[i].cod);
                if(conferecod(aux, *cont, aux[i].cod))
                {
                    printf("\nEste código já esta sendo usado em outro voo!\n");
                }
            } while(conferecod(aux, *cont, aux[i].cod));

            printf("\tInsira a cidade origem: ");
            fflush(stdin);
            gets(aux[i].ori);
            strupr(aux[i].ori);
            printf("\tInsira a cidade destino: ");
            fflush(stdin);
            gets(aux[i].dest);
            strupr(aux[i].dest);
            do
            {
                printf("\tDigite a quantidade de escalas: ");
                scanf("%d", &aux[i].escala);
                if(aux[i].escala>5)
                {
                    printf("\n\tO valor máximo de escalas é 5.\n\n");
                }
            }while (aux[i].escala<0 || aux[i].escala>5);

            if (aux[i].escala>0)
            {
                for (j=0; j<aux[i].escala; j++)
                {
                    printf("\t| %d° escala: ", j+1);
                    fflush(stdin);
                    gets(aux[i].cid_escala[j]);
                    strupr(aux[i].cid_escala[j]);
                }
            }
            (*cont)++;
        }
        printf("\n\nVoo(s) inserido(s)!");
        printf("\n-----------------------------------------------------\n");
        printf("Adcionar mais voos? [S|N]: ");
        fflush(stdin);
        scanf("%c", &opcao);
        printf("\n\n\n");
        system("cls");
    }while(toupper(opcao)=='S');
}

void alterar (struct voo aux[], int  *cont)
{
    int alterna, i, op;
    char opcao;

    if(*cont==0)
    {
        system("cls");
        printf("\n-----------------------------------------------------\n");
        printf("Não existem voos cadastrados.\nVocê será redirecionado ao MENU.");
        printf("\n-----------------------------------------------------\n");
        fflush(stdin);
        getchar();
        system("cls");
    }
    else
    {
        do
        {
            printf("\n-----------------------------------------------------\n");
            printf("OPÇÃO 2: ALTERAR VOO(S)");
            printf("\n-----------------------------------------------------\n");

            do
            {
                printf("Qual dos voos deseja alterar? [1 a %d]: ", (*cont));
                scanf("%d", &alterna);
                printf("-----------------------------------------------------\n");

            }while(alterna < 1 || alterna > (*cont));

            printf("\n\tVOO %d\n", alterna);
            printf("\n\tCódigo do voo: %d", aux[alterna-1].cod);
            printf("\n\tCidade origem: %s", aux[alterna-1].ori);
            printf("\n\tCidade destino: %s", aux[alterna-1].dest);
            printf("\n\tQuantidade de escalas: %d", aux[alterna-1].escala);

            if(aux[alterna-1].escala>0)
            {
                for(i=0; i<aux[alterna-1].escala; i++)
                {
                    printf("\n\t|[%d] %s", i+1, aux[alterna-1].cid_escala[i]);
                }
            }

            printf("\n\n-----------------------------------------------------\n");
            printf("Qual dos itens deseja alterar?\n");
            printf(" [1] Código do voo.\n");
            printf(" [2] Cidade origem.\n");
            printf(" [3] Cidade destino.\n");
            printf(" [4] Cidades escalas.");
            printf("\n-----------------------------------------------------\n");
            printf("Opção: ");
            scanf("%d", &op);

            switch(op)
            {
                case 1:
                    printf("Digite o novo código do voo: ");
                    scanf("%d", &aux[alterna-1].cod);
                    break;
                case 2:
                    printf("Digite a nova cidade origem: ");
                    fflush(stdin);
                    gets(aux[alterna-1].ori);
                    strupr(aux[alterna-1].ori);
                    break;
                case 3:
                    printf("Digite a nova cidade destino: ");
                    fflush(stdin);
                    gets(aux[alterna-1].dest);
                    strupr(aux[alterna-1].dest);
                    break;
                case 4:
                    do
                    {
                        printf("Digite a nova quantidade de escalas: ");
                        scanf("%d", &aux[alterna-1].escala);

                        if(aux[i].escala>5)
                        {
                            printf("\n\tO valor máximo de escalas é 5.\n\n");
                        }
                    }while (aux[alterna-1].escala < 0 || aux[alterna-1].escala > 5);

                    if (aux[alterna-1].escala > 0)
                    {
                        for (i=0; i<aux[alterna-1].escala; i++)
                        {
                            printf("\t| %d° escala: ", i+1);
                            fflush(stdin);
                            gets(aux[alterna-1].cid_escala[i]);
                            strupr(aux[alterna-1].cid_escala[i]);
                        }
                    }
                    break;
            }
            printf("\n\nVoo alterado!");
            printf("\n-----------------------------------------------------\n");
            printf("Deseja alterar mais voos? [S|N]: ");
            fflush(stdin);
            scanf("%c", &opcao);
            printf("\n\n\n");
        }while(toupper(opcao)=='S');
        system("cls");
    }
}

void apagar (struct voo aux[], int *cont)
{
    int apaga, i, j;
    char opcao;

    if(*cont==0)
    {
        system("cls");
        printf("\n-----------------------------------------------------\n");
        printf("Não existem voos cadastrados.\nVocê será redirecionado ao MENU.");
        printf("\n-----------------------------------------------------\n");
        fflush(stdin);
        getchar();
        system("cls");
    }
    else
    {
        do
        {
            printf("\n-----------------------------------------------------\n");
            printf("OPÇÃO 3: APAGAR VOO(S)");
            printf("\n-----------------------------------------------------\n");

            do
            {
                printf("\n\nQual dos voos deseja apagar? [1 a %d]:", *cont);
                scanf("%d", &apaga);
            }while (apaga<1 || apaga>*cont);

            if(apaga>*cont || apaga<=0)
            {
                printf("\nVoo inexistente.");
            }
            else
            {
                apaga--;
                for(i=apaga;i<*cont;i++)
                {
                    aux[i]=aux[i+1];
                }
                (*cont)--;
                printf("\n\nVoo excluido!");
            }

            printf("\n-----------------------------------------------------\n");
            printf("Deseja apagar mais voos? [S|N]: ");
            fflush(stdin);
            scanf("%c", &opcao);
            printf("\n\n\n");
            system("cls");
        }while(toupper(opcao)=='S');
    }
}

void imprimir (struct voo aux[], int *cont)
{
    int i, j;
    char opcao;

    if(*cont==0)
    {
        system("cls");
        printf("\n-----------------------------------------------------\n");
        printf("Não existem voos cadastrados.\nVocê será redirecionado ao MENU.");
        printf("\n-----------------------------------------------------\n");
        fflush(stdin);
        getchar();
        system("cls");
    }
    else
    {
        do
        {
            printf("\n-----------------------------------------------------\n");
            printf("OPÇÃO 4: IMPRIMIR VOO(S)");
            printf("\n-----------------------------------------------------\n");
            printf("Voo(s) registrado(s): ");
            for(i=0;i<*cont;i++)
            {
                printf("\n-----------------------------------------------------\n");
                printf("\n\tVOO %d\n", i+1);
                printf("\n\tCódigo do voo: %d", aux[i].cod);
                printf("\n\tCidade origem: %s", aux[i].ori);
                printf("\n\tCidade destino: %s", aux[i].dest);
                printf("\n\tQuantidade de escalas: %d", aux[i].escala);
                if(aux[i].escala>0)
                {
                    for(j=0; j<aux[i].escala;j++)
                    {
                        printf("\n\t|[%d] %s", j+1, aux[i].cid_escala[j]);
                    }
                }
            }
            printf("\n\n-----------------------------------------------------\n");
            printf("Voltar para o menu? [S|N]: ");
            fflush(stdin);
            scanf("%c", &opcao);
            printf("\n\n\n");
        }while(toupper(opcao)=='N');
        system("cls");
    }
}

void origem (struct voo aux[], int *cont)
{
    int i, qt=0;
    char opcao, cidade[50];

    if(*cont==0)
    {
        system("cls");
        printf("\n-----------------------------------------------------\n");
        printf("Não existem voos cadastrados.\nVocê será redirecionado ao MENU.");
        printf("\n-----------------------------------------------------\n");
        fflush(stdin);
        getchar();
        system("cls");
    }
    else
    {
        do
        {
            printf("\n-----------------------------------------------------\n");
            printf("OPÇÃO 5: PESQUISAR ORIGEM");
            printf("\n-----------------------------------------------------\n");
            printf("Digite a cidade de origem para pesquisa: ");
            fflush(stdin);
            gets(cidade);
            strupr(cidade);

            for(i=0; i<=*cont; i++)
            {
                if(strcmp(aux[i].ori, cidade)==0)
                {
                    qt++;
                }
            }
            printf("\n%d voo(s) saem de %s.", qt, cidade);
            printf("\n-----------------------------------------------------\n");
            printf("Escolher outra cidade origem? [S|N]: ");
            fflush(stdin);
            scanf("%c", &opcao);
            printf("\n\n\n");
            system("cls");
        }while(toupper(opcao)=='S');
    }
}

void escala (struct voo aux[], int *cont)
{
    int i, j, escala=99, menor=-1, opcao;
    char origem[50], destino[50];

    if(*cont==0)
    {
        system("cls");
        printf("\n-----------------------------------------------------\n");
        printf("Não existem voos cadastrados.\nVocê será redirecionado ao MENU.");
        printf("\n-----------------------------------------------------\n");
        fflush(stdin);
        getchar();
        system("cls");
    }
    else
    {
        do
        {
            printf("\n-----------------------------------------------------\n");
            printf("OPÇÃO 6: MENOR ESCALA");
            printf("\n-----------------------------------------------------\n");
            printf("Cidade origem: ");
            fflush(stdin);
            gets(origem);
            strupr(origem);
            printf("Cidade destino: ");
            fflush(stdin);
            gets(destino);
            strupr(destino);

            for(i=0; i<*cont; i++)
            {
                if ((strcmp(origem, aux[i].ori))==0 && (strcmp(destino, aux[i].dest))==0)
                {
                    if(aux[i].escala<escala)
                    {
                        escala=aux[i].escala;
                        menor=i;
                    }
                }
            }

            if(menor!=-1)
            {
                printf("Voo com menor número de escala saindo de %s com destino em %s: ", origem, destino);
                printf("\n\tVOO %d\n", i);
                printf("\n\tCódigo do voo: %d", aux[menor].cod);
                printf("\n\tCidade origem: %s", aux[menor].ori);
                printf("\n\tCidade destino: %s", aux[menor].dest);
                printf("\n\tQuantidade de escalas: %d", aux[menor].escala);

                for(j=0; j<aux[menor].escala; j++)
                {
                    printf("\n\t|[%d]: %s", j+1, aux[menor].cid_escala[j]);
                }
            }
            else
            {
                printf("Não exitem voos com origem em %s e destino em %s", origem, destino);
            }

            printf("\n-----------------------------------------------------\n");
            printf("Deseja escolher outro voo? [S|N]: ");
            fflush(stdin);
            scanf("%c", &opcao);
            printf("\n\n\n");
            system("cls");
        }while(toupper(opcao)=='S');
    }
}

void destino(struct voo aux[], int *cont)
{
    int i;
    char destino[50], opcao;

    if(*cont==0)
    {
        system("cls");
        printf("\n-----------------------------------------------------\n");
        printf("Não existem voos cadastrados.\nVocê será redirecionado ao MENU.");
        printf("\n-----------------------------------------------------\n");
        fflush(stdin);
        getchar();
        system("cls");
    }
    else
    {
        do
        {
            printf("\n-----------------------------------------------------\n");
            printf("OPÇÃO 7: PESQUISAR DESTINO");
            printf("\n-----------------------------------------------------\n");
            printf("Digite a cidade de destino para pesquisa: ");
            fflush(stdin);
            gets(destino);
            strupr(destino);

            for(i=0; i<*cont; i++)
            {
                if(strcmp(destino, aux[i].dest)==0)
                {
                    printf("VOO %d > Origem: %s\n", i+1, aux[i].ori);
                }
            }

            printf("\n-----------------------------------------------------\n");
            printf("Deseja escolher outra cidade destino? [S|N]: ");
            fflush(stdin);
            scanf("%c", &opcao);
            printf("\n\n\n");
            system("cls");
        }while(toupper(opcao)=='S');
    }
}

int main ()
{
    setlocale(LC_ALL, "portuguese");
    struct voo dados [max];
    int num, i, viagem=0;

    do
    {
        do
        {
            printf("\n\n\t\tVoe Sempre, Voe Feliz\n");
            printf("\n-----------------------------------------------------\n");
            printf("\t\t\tMENU\n");
            printf("-----------------------------------------------------\n\n");
            printf("1. Incluir voos.\n\n");
            printf("2. Alterar as informações sobre um determinado voo.\n\n");
            printf("3. Apagar um voo \n\n");
            printf("4. Imprimir os voos cadastrados. \n\n");
            printf("5. Dada a cidade origem, determinar quantos voos saem\n   dessa cidade.\n\n");
            printf("6. Dada a cidade origem e destino, determinar o voo\n   com menor número de escalar e imprimir todas as\n   informações sobre esse voo.\n\n");
            printf("7. Dada a cidade destino, determinar todos os voos\n   com a respectiva cidade origem que chegam nesse\n   destino.\n\n");
            printf("8. Sair do sistema.\n\n");
            printf("-----------------------------------------------------\n\n");
            printf("Insira sua opção: ");
            scanf("%d", &num);
            system("cls");
        }while (num<1 || num>8);

        switch (num)
        {
        case 1:
            incluir (dados, &viagem);
            break;
        case 2:
            alterar (dados, &viagem);
            break;
        case 3:
            apagar (dados, &viagem);
            break;
        case 4:
            imprimir(dados, &viagem);
            break;
        case 5:
            origem (dados, &viagem);
            break;
        case 6:
            escala (dados, &viagem);
            break;
        case 7:
            destino (dados, &viagem);
            break;
        }

    }while (num != 8);

    if(num==8)
    {
        printf("\n-----------------------------------------------------\n");
        printf("OPÇÃO 8: SAIR");
        printf("\n-----------------------------------------------------\n");

        printf("Saindo...\n");
        printf("Boa viagem!\n\n");
    }
    return 0;
}
