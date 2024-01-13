/*
NOMES: Giovanna Santana Pennisi
                  &
       Sofia Clementino dos Santos

CURSO: ADS Noturno - 2° CICLO
*/

#include <stdio.h>
#define ex6

#ifdef ex1
/*Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las usando ponteiros e retorne como resultado se
    sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
    Imprima o resultado na funcao main(). Declare os vetores como variavel global*/

char exec, string1[10], string2[10], *ps1, *ps2;

int Compara()
{
    int i = 0;

    for (i=0; ps1[i] != '\0';i++)
        {
        if (ps1[i] != ps2[i])
        {
        return 0;
        }
        }
        if (ps1[i] == '\0' && ps2[i] == '\0')
        {
        return 1;
        }
        else
        {
        return 0;
        }
}

main()
{

do{

    ps1 = string1;
    ps2 = string2;

    fflush(stdin);
    printf("digite a string 1: ");
    scanf("%s", ps1);

    fflush(stdin);
    printf("digite a string 2: ");
    scanf("%s", ps2);


 int comparar = Compara();

        if(comparar == 0)
        {
        printf("\na string e diferente\n");
        }
        else
            if(comparar == 1)
        {
            printf("\n a string e igual");
        }

printf("\n\nvoce deseja continuar a execucao(s/n) ");
scanf(" %c", &exec);

}
while (exec=='s');
}

#endif // ex1

#ifdef ex2
/*Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/

char vetletras[13] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};
int i;

int PesquisaC(char *pl)
{
       for(i=0; i<13; i++)
       {
        if (pl == vetletras[i])
            {
            return 1;
            }
       }
}

main()
{   char exec, l, *pl;
    do
    {
    fflush(stdin);
    pl = &l;
    printf("\ndigite uma letra: ");
    scanf ("%c", pl);

    printf("\na letra pertence ao conjunto = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'}? \n");
    int Pesquisar = PesquisaC( *pl);

    if(Pesquisar == 1)
    {
        printf("\na letra '%c' pertence ao conjunto, e se encontra na posicao %d dentro do conjunto!!!", *pl, i+1);
    }
    else
    {
        printf("\na letra '%c' nao pertence ao conjunto", *pl);
    }


    printf("\n\nvoce deseja continuar a execucao(s/n) ");
    scanf(" %c", &exec);

    }
while (exec=='s');
}


#endif // ex2

#ifdef ex3
/*Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char*/

    char caracter, *pc, exec;
    int inteiro, *pi;
    long longo, *pl;
    unsigned semsinal, *pu;
    float fl, *pf;
    double dbl, *pd;
    unsigned long lsemsinal, *pul;
    unsigned char csemsinal, *puc;

main()
{
    do
    {

    pc = &caracter;
    pi = &inteiro;
    pl = &longo;
    pu = &semsinal;
    pf = &fl;
    pd = &dbl;
    pul = &lsemsinal;
    puc = &csemsinal;

    printf("\ndigite um num inteiro: ");
    scanf("%d", pi);
    printf("\ndigite um num longo: ");
    scanf("%ld", pl);
    printf("\ndigite um num unsigned: ");
    scanf("%lu", pu);
    printf("\ndigite um num float: ");
    scanf("%e", pf);
    printf("\ndigite um num double: ");
    scanf("%le",pd);
    printf("\ndigite um caracter: ");
    scanf(" %c", pc);
    printf("\ndigite um num longo sem sinal: ");
    scanf("%lu", pul);
    printf("\ndigite um caractere sem sinal: ");
    scanf("%u", puc);

    char exec;


    /*Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char*/

        printf("        10        20        30        40        50        60\n");
        printf("123456789012345678901234567890123456789012345678901234567890\n");


    printf("    %-11d", *pi);
    printf("         %-11ld", *pl);
    printf("         %-10u", *pu);
    printf("\n              %-8.1e", *pf);
    printf("            %-8.1le", *pd);
    printf("            %c", *pc);
    printf("\n         %-10lu", *pul);
    printf("          %-3u", *puc);

    printf("\n\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);
}
while (exec=='s');

}
#endif // ex3

#ifdef ex4
/*Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.*/

main()
{
char exec;
int num, cont=0, soma=0, *pn, *pc, *ps;
float media, *pm;

pn = &num;
pc = &cont;
ps = &soma;
pm = &media;

do
{
    do
    {

    printf("digite numeros positivos (quando o numero for negativo o programa ira parar): ");
    scanf("%d", pn);

    if (*pn>=0)
    {
    (*ps)=(*ps)+(*pn);
    (*pc)++;
    }

    }
    while(*pn>=0);

    (*pm)=((float)*ps)/(*pc);

    printf("\na media dos positivos e: %.2f", *pm);


    printf("\nvoce quer continuar a execucao(s/n)? ");
    scanf (" %c", &exec);

    if (exec=='s');
    {
        *pc=0;
        *ps=0;   //verificar se o prof quer que zere o programa ao continuar a exec. ou nao, caso nao so apagar isso
    }
}
while (exec=='s');
}

#endif // ex4

#ifdef ex5
/*Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa usando ponteiros. Utilize um comando de loop.
    O vetor de estruturas deve ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep*/

struct var
{
    char nome[20];
    char end[30];
    char cidade[20];
    char estado[20];
    char cep[11];
};
struct var dados[4];
struct var *p;

int i=0;

RecebeDados()
{
    for (i=0; i<4; i++)
    {
    fflush(stdin);
    printf("\nInsira dados de 4 pessoas diferentes abaixo: \n\n");
    printf("nome: ");
    scanf("%s", &(p+i) ->nome[0]);
    fflush(stdin);
    printf("endereco: ");
    scanf("%s", &(p+i) ->end[0]);
    fflush(stdin);
    printf("cidade: ");
    scanf("%s", &(p+i) ->cidade[0]);
    fflush(stdin);
    printf("estado: ");
    scanf("%s", &(p+i) ->estado[0]);
    fflush(stdin);
    printf("cep (com o traco): ");
    scanf("%s", &(p+i) ->cep[0]);
    }
}

ImprimeDados()
{
    for (i=0; i<4; i++)
    {
    printf("\nDados : \n");
    printf("nome: %s", (p+i) -> nome);
    printf("\nendereco: %s", (p+i) -> end);
    printf("\ncidade: %s", (p+i) -> cidade);
    printf("\nestado: %s", (p+i) -> estado);
    printf("\ncep (com o traco): %s\n\n", (p+i) -> cep);
    }
}

main()
{
    char opcao;
    p = &dados[0];

   do
    {
    printf("\n\n[1] Entrada de dados\n");
    printf("[2] Exibir dados\n");
    printf("[3] Sair\n\n");
    printf("Digite a opcao desejada: ");
    scanf(" %c", &opcao);


        if (opcao == '1')
        {
            RecebeDados();
        }
        else
        if(opcao == '2')
        {
            ImprimeDados();
        }
        else
        if(opcao == '3')
        {
        printf("\nPrograma encerrado.\n");
        exit(0);
        }
        else
        {
            printf("Opcao invalida.\n");
        }
    }
        while (opcao!= '1' || opcao!= '2' || opcao!= '3');
}
#endif // ex5

#ifdef ex6
/*Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
    	estrutura: dia, mes e ano*/
struct var
{
    int dia;
    int mes;
    int ano;
};

struct var datas[2];
struct var *p;


int CalculaDia()
{
    int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int diasInicio, diasFim, i;

    diasInicio = (p+0)->ano * 365 + (p+0)->dia;
    for (i = 1; i < (p+0)->mes; i++) {
        diasInicio += diasMes[i];
    if (i == 2 && (((p+0)->ano % 4 == 0 && (p+0)->ano % 100 != 0) || (p+0)->ano % 400 == 0)) //Verifica se o ano e' bissexto.
            {
            diasInicio++;
            }
    }

    diasFim = (p+1)->ano * 365 + (p+1)->dia;
    for (i = 1; i < (p+1)->mes; i++) {
        diasFim += diasMes[i];
        if (i == 2 && (((p+1)->ano % 4 == 0 && (p+1)->ano % 100 != 0) || (p+1)->ano % 400 == 0)) //Verifica se o ano e' bissexto.
            {
            diasFim++;
            }
    }
    return diasInicio - diasFim;
}

main()
{
    int resultado;
    p = &datas[0];
    char exec;

    do
    {
    printf("\nInsira uma data inicial: \n\n");
    printf("dia: ");
    scanf("%d", &(p+0) -> dia);
    printf("mes: ");
    scanf("%d", &(p+0) -> mes);
    printf("ano: ");
    scanf("%d", &(p+0) -> ano);

    printf("\nInsira uma data final: \n\n");
    printf("dia: ");
    scanf("%d", &(p+1) -> dia);
    printf("mes: ");
    scanf("%d", &(p+1) -> mes);
    printf("ano: ");
    scanf("%d", &(p+1) -> ano);

    resultado = CalculaDia();

    printf("\nNumero de dias entre as datas: %d \n", resultado);

    printf("\n\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);
    }
    while (exec=='s');
}
#endif // ex6
