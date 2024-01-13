/*
NOMES: Giovanna Santana Pennisi
                  &
       Sofia Clementino dos Santos

CURSO: ADS Noturno - 2° CICLO
*/

#include <stdio.h>
#define ex1

#ifdef ex1
/* Escreva um programa que receba via teclado um tempo em segundos e converta
para horas, minutos e segundos.     Ex.: recebe 3850 segundos que converte para 1h 4min 10s.*/

main(){

    int segundos, minutos, minutos2, horas;

    printf("Digite o tempo em segundos:");
    scanf("%d", &segundos);

    horas = segundos / 3600;
    minutos = segundos - horas * 3600;
    minutos2 = minutos / 60;
    segundos = minutos - minutos2 * 60;

    printf("Tempo convertido: %dh %dmin %ds\n", horas, minutos2, segundos);
}

#endif // ex1

#ifdef ex2
/*Escreva um programa que receba dados via teclado para variaveis do tipo short,
    long, int, float, double e um char e imprima-os no video no seguinte
    formato:

             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char*/

main(){

short int si;
long int li;
int a;
float b;
double d;
char c;

    printf("digite 6 variaveis");
    scanf("%hi%li%d%f%lf", &si,&li,&a,&b,&d);
    c = getchar ();

printf("        10        20        30        40        50        60\n");
printf("12345678901234567890123456789012345678901234567890123456789012345\n");

printf("%9.hi %18.li %18.d \n %18.2f %20.2lf %17c", si,li,a,b,d,c);

}

#endif // ex2

#ifdef ex3
/*Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma variável auxiliar.*/
/*2 resoluçoes logica e aritmetica*/

//fazer depois

main()
{
    int a, b;
    printf ("digite duas variaveis: ");
    scanf ("%d%d", &a, &b);

    a = a+b;
    b = a-b;
    a = a-b;

    printf("a = %d e b = %d", a,b);

}
#endif // ex3

#ifdef ex4
/* Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
outro número formado pelos dígitos invertidos do número lido.
Ex:   NúmeroLido = 123
      NúmeroGerado = 321*/

main ()
{   int n, u, d, c;

    do
    {
    printf("digite um numero com unidade, dezena e centena: ");
    scanf("%d", &n);
    if (n>999 | n<0)
    {
    printf("somente tres digitos e numeros positivos, digite novamente\n");
    }
    }
    while (n>999 | n<0);

    u = n % 10;
    d = n % 100/10;
    c = n % 10000/100;

    printf ("\nvoce digitou: %d%d%d\n", c, d, u);
    printf ("numero invertido: %d%d%d\n", u, d, c);

}
#endif // ex4

#ifdef ex5
/*Escreva um programa que determine o menor multiplo de um numero inteiro. Este
multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via teclado.
Ex: menor multiplo de 13 maior que 100. Resultado: 104.*/

main()
{
    int n, limit, multp, cont=1;

    printf("digite um numero: ");
    scanf("%d", &n);
    printf("digite um limite: ");
    scanf ("%d", &limit);

    do
    {
    multp = n * cont;
    cont++;
    }
    while (multp<=limit);

    printf("%d", multp);
}
#endif // ex5
