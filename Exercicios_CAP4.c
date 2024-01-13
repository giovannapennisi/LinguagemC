/*
NOMES: Giovanna Santana Pennisi
                  &
       Sofia Clementino dos Santos

CURSO: ADS Noturno - 2° CICLO
*/

#include <stdio.h>
#define ex5

#ifdef ex1
/*Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
decomponha em dois outros vetores. Um tera´ as componentes de ordem impar
e o outro tera´ as componentes de ordem par.
Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa
deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.*/
int N[10], cont, P[10], S[10], contp, conts;
char exec;

main()
{

do
{
    for (cont=0;cont<10;cont++)
    {
        printf("digite um numero: ");
        scanf("%d", &N[cont]);
    }


    for (cont=0;cont<10;cont++)
 {
        if(cont % 2 == 0)
        {
            P[contp] = N[cont];

            contp++;
        }
        else
        {
            S[conts] = N[cont] ;

            conts++;
        }
 }

    for (cont = 0; cont < 5; cont++)
        {
        printf("\nvetor de indice par: %d", P[cont]);
        }

        printf("\n");

    for (cont = 0; cont < 5; cont++)
        {
        printf("\nvetor de indice impar: %d", S[cont]);
        }

         printf("\n\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);
}
while (exec=='s');
}
#endif // ex1

#ifdef ex2
/* Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
decomponha em dois outros vetores. Um tera´ as componentes de valor impar
e o outro tera´ as componentes de valor par.
Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}.*/
int N[10], cont, P[10], S[10], contp, conts;
char exec;

main()
{

do
{
    for (cont=0;cont<10;cont++)
    {
        printf("digite um numero: ");
        scanf("%d", &N[cont]);
    }


    for (cont=0;cont<10;cont++)
 {
        if(N[cont] % 2 == 0)
        {
            P[contp] = N[cont];

            contp++;
        }
        else
        {
            S[conts] = N[cont] ;

            conts++;
        }
 }

    for (cont = 0; cont < contp; cont++)
        {
        printf("\npar: %d", P[cont]);
        }

        printf("\n");

    for (cont = 0; cont < conts; cont++)
        {
        printf("\nimpar: %d", S[cont]);
        }

         printf("\n\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);
}
while (exec=='s');
}
#endif // ex2

#ifdef ex3
/*Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
que recebe os dados via teclado para esses 2 vetores. Usando o operador adicao
"+", some os elementos de mesmo indice dos 2 vetores e guarde o resultado em um
3. vetor. Imprima na tela o indice, os valores e o resultado dos 6 elementos dos vetores.*/
main()
{
    int vetorbi1[2][3], vetorbi2[2][3], vetoresult[2][3], a, b;
    char exec;
do
{


    printf("digite os valores para os vetores abaixo: \n\n");

    for (a = 0; a < 2; a++)
    {
        for (b = 0; b < 3; b++)
            {
            printf("vetor 1 - posicao (%d, %d): ", a + 1, b + 1);
            scanf("%d", &vetorbi1[a][b]);
            }
    }

    printf("\n\n");

    for (a = 0; a < 2; a++)
        {
        for (b = 0; b < 3; b++)
        {
            printf("vetor 2 - posicao (%d, %d): ", a + 1, b + 1);
            scanf("%d", &vetorbi2[a][b]);
        }
    }


    for (a = 0; a < 2; a++) {
        for (b = 0; b < 3; b++) {
            vetoresult[a][b] = vetorbi1[a][b] + vetorbi2[a][b];
        }
    }


    printf("\n\nvetor 1:\n");
    for (a = 0; a < 2; a++)
        {
        for (b = 0; b < 3; b++)
        {
            printf("(%d, %d): %d\n", a + 1, b + 1, vetorbi1[a][b]);
        }
    }

    printf("\n\nvetor 2:\n");
    for (a = 0; a < 2; a++)
        {
        for (b = 0; b < 3; b++) {
            printf("(%d, %d): %d\n", a + 1, b + 1, vetorbi2[a][b]);
        }
    }

    printf("\n\nresultado da soma dos vetores: \n");
    for (a = 0; a < 2; a++) {
        for (b = 0; b < 3; b++) {
            printf("(%d, %d): %d\n", a + 1, b + 1, vetoresult[a][b]);
        }
    }
    printf("\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);
}
while (exec=='s');
}

#endif // ex3

#ifdef ex4
/*Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
que sao digitados. Guarde-os em um vetor. Mostre ao final os valores ordenados.*/
//FAZER DEPOIS!!!!!!!!!!!!!!!!!!!!!!!!
main()
{   char exec;
    int num[10], cont, contaux, cres;
do
{
    for (cont = 0; cont < 10; cont++)
    {
    printf("digite um numero: ");
    scanf("%d", &num[cont]);
    }

    for (contaux = cont; contaux > 0; contaux--)
    {
        if (num[contaux] < num[contaux - 1])
        {
            cres = num[contaux];
            num[contaux] = num[contaux- 1];
            num[contaux- 1] = cres;
        }

    }


    printf("\nValores ordenados em ordem crescente:\n");

    for (cont = 0; cont < 10; cont++) {
        printf("%d ", num[cont]);
    }


    printf("\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);
}
while (exec=='s');
}
#endif // ex4

#ifdef ex5
/*Escreva um programa para receber via teclado em vetores 3 int, 3 long,
3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double*/
main()
{   char exec;
    int cont, in[3];
    long int lo[3];
    unsigned int un[3];
    float fl[3];
    double db[3];

do
{
    for (cont = 0; cont < 3; cont++)
    {
    printf("digite um numero inteiro: ");
    scanf("%d", &in[cont]);
    }
    for (cont = 0; cont < 3; cont++)
    {
     printf("digite um numero inteiro longo: ");
    scanf("%ld", &lo[cont]);
    }
    for (cont = 0; cont < 3; cont++)
    {
     printf("digite um numero inteiro sem sinal: ");
    scanf("%u", &un[cont]);
    }
    for (cont = 0; cont < 3; cont++)
    {
     printf("digite um numero float: ");
    scanf("%f", &fl[cont]);
    }
    for (cont = 0; cont < 3; cont++)
    {
     printf("digite um numero double: ");
    scanf("%lf",&db[cont]);
    }

printf("        10        20        30        40        50\n");
printf("12345678901234567890123456789012345678901234567890\n");



printf("%5.d%21.ld%24.u \n%17.f%21.lf \n%5.d%21.ld%24.u \n%17.f%21.lf \n%5.d%21.ld%24.u \n%17.f%21.lf",
       in[0],lo[0],un[0],fl[0],db[0],in[1],lo[1],un[1],fl[1],db[1],in[2],lo[2],un[2],fl[2],db[2]);

    printf("\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);
}
while (exec=='s');
}
#endif // ex5
