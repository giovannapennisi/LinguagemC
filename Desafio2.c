/*
NOMES: Giovanna Santana Pennisi
                  &
       Sofia Clementino dos Santos

CURSO: ADS Noturno - 2° CICLO
*/

#include <stdio.h>

/*Escreva um programa que tem a estrutura de dados abaixo. O programa tem as seguintes opções de menu:
    1 – Entrada de dados.
    2 – Lista todas todos os dados na tela.
    3 – Pesquisar um medico pelo nome completo e mostra na tela
    4 – Pesquisar um celular pelo nome completo
    5 – Pesquisar pela data da consulta.
    6 – Altera dados. Pesquisa pelo nome completo.
    7 – Exclui dados. Pesquisa pelo nome completo.
    8 – Saída pelo usuário
Estrutura: medico, celular, data_consulta
A única estrutura de dados do programa deve ser uma variável local na função main(). Portanto a passagem
da estrutura para as funções utiliza ponteiro.
Cada uma das opções do menu é uma função no programa.*/

struct var
    {
    char medico[50];
    char celular[15];
    char data_consulta[11];
    };


RecebeDados(struct var *p)
{   int op;

    do
    {
    printf("\nCadastre os dados do medico desejado: \n");
    printf("Nome: ");
    fflush(stdin);
    gets(p->medico);
    printf("Celular: ");
    gets(p->celular);
    printf("Data da consulta (formato dd/mm/aaaa): ");
    gets(p->data_consulta);

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "a");
    fwrite(p, sizeof(*p), 1, dadosarquivo);
    fclose(dadosarquivo);

    printf("\nVoce deseja continuar cadastrando novos dados?\nDigite '1' para sim ou qualquer outro numero para parar: \n");
    scanf("%d", &op);
    }
    while (op == 1);
}

ImprimeDados(struct var *p)
{   int i, cont = 0;

    for (i = 0; (ImprimeInfo(p, i)) != 0; i++)
    {
        if (p->medico[0] != '*')
    {
        printf("\nDados: " );
        printf("\nNome: %s", (p) -> medico);
        printf("\nCelular: %s", (p) -> celular);
        printf("\nData da consulta: %s\n", (p) -> data_consulta);
        cont++;
    }

    }
    if(cont == 0)
    {
    printf("\nNao ha dados cadastrados.");
    }
}

int ImprimeInfo(struct var *p, int i)
{
    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "r");

    if(dadosarquivo == NULL)
        {
        printf("\nO arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }
    else
        {
        fseek(dadosarquivo, i*sizeof(*p), 0);
        int bytes = fread(p, sizeof(*p), 1, dadosarquivo);
        fclose(dadosarquivo);

        return bytes;
        }
}

int ComparaDados(char *c1, char *c2)
{
    for (int i = 0; c1[i] != '\0' || c2[i] != '\0'; i++)
    {
        if (c1[i] != c2[i])
        {
            return 0;
        }
    }
    return 1;
}

int PesquisaDados(struct var *p)
{
    char procura[50];
    int bytes, i, cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "r");

    if(dadosarquivo == NULL)
        {
        printf("O arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome completo do medico que deseja buscar os dados: \n");
    fflush(stdin);
    gets(procura);

        for (i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->medico))
            {
            printf("\nInformacoes encontradas: " );
            printf("\nNome: %s", (p) -> medico);
            printf("\nCelular: %s", (p) -> celular);
            printf("\nData da consulta: %s\n", (p) -> data_consulta);
             cont++;
            }
        }

        if(cont == 0)
            {
            printf("\nNao foi possivel encontrar nenhum registro correspondente." );
            }

        fclose(dadosarquivo);
}

int PesquisaCelular(struct var *p)
{
 char procura[50];
    int bytes, i, cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "r");

    if(dadosarquivo == NULL)
        {
        printf("O arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome completo do medico que deseja buscar o celular: \n");
    fflush(stdin);
    gets(procura);

        for (i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->medico))
            {
            printf("\nInformacoes encontradas: " );
            printf("\nNome: %s", (p) -> medico);
            printf("\nCelular: %s", (p) -> celular);
             cont++;
            }
        }

        if(cont == 0)
            {
            printf("\nNao foi possivel encontrar nenhum registro correspondente." );
            }

        fclose(dadosarquivo);
}

int PesquisaData(struct var *p)
{
  char procura[11];
    int bytes, i, cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "r");

    if(dadosarquivo == NULL)
        {
        printf("O arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise a data de consulta que deseja consultar (formato: dd/mm/aaaa): \n");
    fflush(stdin);
    gets(procura);

        for (i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->data_consulta))
            {
            printf("\nInformacoes encontradas: " );
            printf("\nNome: %s", (p) -> medico);
            printf("\nCelular: %s", (p) -> celular);
            printf("\nData da consulta: %s\n", (p) -> data_consulta);
             cont++;
            }
        }

        if(cont == 0)
            {
            printf("\nNao foi possivel encontrar nenhum registro correspondente." );
            }

        fclose(dadosarquivo);
}

AlteraDados(struct var *p)
{
    char procura[50];
    int cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "r+");

    if(dadosarquivo == NULL)
        {
        printf("O arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome completo do medico desejado para buscar os dados: \n");
    fflush(stdin);
    gets(procura);

        for (int i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->medico))
            {
            printf("\nAltere as seguintes informacoes: \n\n");
            printf("Novo nome: ");
            fflush(stdin);
            gets(p->medico);
            printf("Novo celular: ");
            gets(p->celular);
            printf("Nova data de consulta (formato dd/mm/aaaa): ");
            gets(p->data_consulta);
            cont++;
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fwrite(p, sizeof(*p), 1, dadosarquivo);
            }
        }
            fclose(dadosarquivo);

        if(cont == 0)
        {
        printf("\nNao foi possivel encontrar nenhum registro correspondente." );
        }
}

ExcluiDados(struct var *p)
{
    char procura[50];
    int cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "r+");

    if(dadosarquivo == NULL)
        {
        printf("\nO arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome completo do medico desejado para excluir os dados: \n");
    fflush(stdin);
    gets(procura);

        for (int i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->medico))
            {
            p->medico[0] = '*';
            p->celular[0] = '*';
            p->data_consulta[0] = '*';

            printf("\nOs dados foram excluidos com sucesso.");
            cont++;
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fwrite(p, sizeof(*p), 1, dadosarquivo);
            }
        }
            fclose(dadosarquivo);

        if(cont == 0)
        {
        printf("\nNao foi possivel encontrar nenhum registro correspondente." );
        }
}

main()
{
    char opcao;

    struct var dados;
    struct var *p;

    p = &dados;

   do
    {
    printf("\n\n[1] Incluir dados\n");
    printf("[2] Listar todos os dados\n");
    printf("[3] Pesquisar dados pelo nome completo do medico\n");
    printf("[4] Pesquisar um celular pelo nome completo do medico\n");
    printf("[5] Pesquisar pela data da consulta\n");
    printf("[6] Alterar dados\n");
    printf("[7] Excluir dados\n");
    printf("[8] Sair\n\n");
    printf("\nDigite a opcao desejada: ");
    scanf(" %c", &opcao);

        if (opcao == '1')
        {
            RecebeDados(p);
        }
        else
        if(opcao == '2')
        {
            ImprimeDados(p);
        }
        else
        if(opcao == '3')
        {
            PesquisaDados(p);
        }
        else
        if(opcao == '4')
        {
            PesquisaCelular(p);
        }
        else
        if(opcao == '5')
        {
            PesquisaData(p);
        }
        else
        if(opcao == '6')
        {
            AlteraDados(p);
        }
        else
        if(opcao == '7')
        {
            ExcluiDados(p);
        }
        else
        if(opcao == '8')
        {
        printf("\nPrograma encerrado.\n");
        exit(0);
        }
        else
        {
            printf("\nOpcao invalida.\n");
        }
    }
        while (opcao!= '1' || opcao!= '2' || opcao!= '3');
}
