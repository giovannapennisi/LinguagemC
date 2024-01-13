/*
NOMES: Giovanna Santana Pennisi
                  &
       Sofia Clementino dos Santos

CURSO: ADS Noturno - 2° CICLO
*/

#include <stdio.h>
#define ex3

#ifdef ex1
/*Escreva um programa que tem uma estrutura da dados com os membros abaixo. Receba dados
via teclado em uma funcao e imprima estes conteudos no video, em outra funcao, no seguinte
formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int,
                unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long
*/
struct var {
    char caracter;
    int inteiro;
    long longo;
    float flt;
    double dbl;
    unsigned char csemsinal;
    unsigned int isemsinal;
    unsigned long lsemsinal;
    };

struct var numeros;

RecebeDados()
{
    fflush(stdin);
    printf("\ndigite um caracter: ");
    scanf("%c", &numeros.caracter);
    printf("\ndigite um num inteiro: ");
    scanf("%i", &numeros.inteiro);
    printf("\ndigite um num longo: ");
    scanf("%ld", &numeros.longo);
    printf("\ndigite um num float: ");
    scanf("%e", &numeros.flt);
    printf("\ndigite um num double: ");
    scanf("%le", &numeros.dbl);
    printf("\ndigite um caractere sem sinal: ");
    scanf("%u", &numeros.csemsinal);
    printf("\ndigite um num inteiro sem sinal: ");
    scanf("%u", &numeros.isemsinal);
    printf("\ndigite um num longo inteiro: ");
    scanf("%lu", &numeros.lsemsinal);
}

ImprimeDados()
{
    printf("    %c", numeros.caracter);
    printf("         %-11i", numeros.inteiro);
    printf("%-11ld", numeros.longo);
    printf("        %-8.1e", numeros.flt);
    printf("            %-8.1le", numeros.dbl);
    printf("\n          %-3u", numeros.csemsinal);
    printf("                 %-10u", numeros.isemsinal);
    printf("          %-10lu", numeros.lsemsinal);
}

main()
{
    char exec;

    do
{
    RecebeDados();
    printf("\n        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    ImprimeDados();


    printf("\n\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);

}
while (exec=='s');

}
#endif // ex1

#ifdef ex2
/*Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao
    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Faça um menu com uma opcao para saida do programa.
		estrutura: nome, end, cidade, estado, cep*/

struct var
{
    char nome [20];
    char end [30];
    char cidade [20];
    char estado [20];
    char cep[11];
};

    struct var dados[4];

 int i=0;

RecebeDados()
{
    for (i=0; i<4; i++)
    {
    fflush(stdin);
    printf("\nInsira dados de 4 pessoas diferentes abaixo: \n\n");
    printf("nome: ");
    scanf("%s", &dados[i].nome[0]);
    fflush(stdin);
    printf("endereco: ");
    scanf("%s", &dados[i].end[0]);
    fflush(stdin);
    printf("cidade: ");
    scanf("%s", &dados[i].cidade[0]);
    fflush(stdin);
    printf("estado: ");
    scanf("%s", &dados[i].estado[0]);
    fflush(stdin);
    printf("cep (com o traco): ");
    scanf("%s", &dados[i].cep[0]);
    }
}

ImprimeDados()
{
    for (i=0; i<4; i++)
    {
    printf("\nDados : \n");
    printf("nome: %s", dados[i].nome);
    printf("\nendereco: %s", dados[i].end);
    printf("\ncidade: %s", &dados[i].cidade);
    printf("\nestado: %s", &dados[i].estado);
    printf("\ncep (com o traco): %s\n\n", &dados[i].cep);
    }
}

main()
{
    char opcao;

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
#endif // ex2

#ifdef ex3
/*Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado na funcao main(). Faca uma funcao que calcule o numero de dias
    entre elas e mostre o resultado no video na funcao main().
    Utilize vetor de estruturas.
                estrutura: dia, mes, ano*/
struct var
{
    int dia;
    int mes;
    int ano;
};

struct var datas[2];


int CalculaDia()
{
    int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int diasInicio, diasFim, i;

    diasInicio = datas[0].ano * 365 + datas[0].dia;
    for (i = 1; i < datas[0].mes; i++) {
        diasInicio += diasMes[i];
        if (i == 2 && ((datas[0].ano % 4 == 0 && datas[0].ano % 100 != 0) || (datas[0].ano % 400 == 0))) //Verifica se o ano e' bissexto.
            {
            diasInicio++;
            }
    }

    diasFim = datas[1].ano * 365 + datas[1].dia;
    for (i = 1; i < datas[1].mes; i++) {
        diasFim += diasMes[i];
        if (i == 2 && ((datas[1].ano % 4 == 0 && datas[1].ano % 100 != 0) || (datas[1].ano % 400 == 0))) //Verifica se o ano e' bissexto.
            {
            diasFim++;
            }
    }
    return diasInicio - diasFim;
}

main()
{
    int resultado;
    char exec;

    do
    {
    printf("\nInsira uma data inicial: \n\n");
    printf("dia: ");
    scanf("%d", &datas[0].dia);
    printf("mes: ");
    scanf("%d", &datas[0].mes);
    printf("ano: ");
    scanf("%d", &datas[0].ano);

    printf("\nInsira uma data final: \n\n");
    printf("dia: ");
    scanf("%d", &datas[1].dia);
    printf("mes: ");
    scanf("%d", &datas[1].mes);
    printf("ano: ");
    scanf("%d", &datas[1].ano);

    resultado = CalculaDia();

    printf("\nNumero de dias entre as datas: %d \n", resultado);


    printf("\n\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);
    }
    while (exec=='s');
}
#endif // ex3

#ifdef ex4
/*Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faça um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados
    3 - calcula o IMC de todas as pessoas.
    4 - sair
        Calculo do IMC = peso/(altura*altura).
        estrutura: nome, peso, altura*/


struct var
{
    char nome [20];
    float peso;
    float altura;
};

struct var dadospeso[4];

 int i=0;
 float IMC;

RecebeDados()
{
    for (i=0; i<4; i++)
    {
    fflush(stdin);
    printf("\nInsira dados de 4 pessoas diferentes abaixo: \n\n");
    printf("nome: ");
    scanf("%s", &dadospeso[i].nome[0]);
    printf("peso: ");
    scanf("%f", &dadospeso[i].peso);
    printf("altura: ");
    scanf("%f", &dadospeso[i].altura);
    }
}

ImprimeDados()
{
    for (i=0; i<4; i++)
    {
    printf("\nDados %d: \n", 1+i);
    printf("nome: %s", dadospeso[i].nome);
    printf("\npeso: %.2f kg", dadospeso[i].peso);
    printf("\naltura: %.2f cm\n", dadospeso[i].altura);
    }
}

CalculaIMC()
{
     for (i=0; i<4; i++)
    {
    IMC = dadospeso[i].peso/(dadospeso[i].altura*dadospeso[i].altura);
    printf("\no IMC de %s e: %.2f\n", dadospeso[i].nome, IMC);
    }
}

main()
{
    char opcao;

   do
    {
    printf("\n\n[1] Entrada de dados\n");
    printf("[2] Exibir dados\n");
    printf("[3] Calcular IMC:\n");
    printf("[4] Sair\n\n");
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
            CalculaIMC();
        }
        else
        if(opcao == '4')
        {
        printf("\nPrograma encerrado.\n");
        exit(0);
        }
        else
        {
            printf("Opcao invalida.\n");
        }
    }
        while (opcao!= '1' || opcao!= '2' || opcao!= '3' || opcao!= '4');
    }
#endif // ex4

