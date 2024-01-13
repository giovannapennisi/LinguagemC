/*
NOMES: Giovanna Santana Pennisi
                  &
       Sofia Clementino dos Santos

CURSO: ADS Noturno - 2° CICLO
*/

#include <stdio.h>
#define ex5

#ifdef ex1
/*Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
(Declare os vetores como variavel global) (nao pode usar funcao de biblioteca)*/

char exec, string1[10], string2[10];

int Compara(char *aux1, char *aux2)
{
    int i = 0;
    do {
        if (aux1[i] != aux2[i])
        {
            return 0;
        }
        i++;
    } while (aux1[i] != '\0' || aux2[i] != '\0');
    return 1;

}

main(){

do{

    fflush(stdin);

    printf("digite a string 1: ");
    gets(string1);

    printf("digite a string 2: ");
    gets(string2);

       int comparar = Compara(string1,string2);
            if(comparar == 0)
            {
        printf("\na string e diferente\n");
            }
        else
        {
            printf("\n a string e igual");
        }


printf("\n\nvoce deseja continuar a execucao(s/n)");
scanf(" %c", &exec);

}
while (exec=='s');
}
#endif // ex1

#ifdef ex2
/*Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
e imprima-os no video no seguinte formato:(Declare os 5 vetores como variaveis
globais)

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3*/

char exec, nome1[7], nome2[7], nome3[7], nome4[7], nome5[7];

main(){

do{

    fflush(stdin);

    printf("digite o nome 1: ");
    gets(nome1);

    printf("digite o nome 2: ");
    gets(nome2);

    printf("digite o nome 3: ");
    gets(nome3);

    printf("digite o nome 4: ");
    gets(nome4);

    printf("digite o nome 5: ");
    gets(nome5);

    printf("        10        20        30        40        50\n");
printf("12345678901234567890123456789012345678901234567890\n");


printf("%7s %39s \n %16s %19s \n %26s", nome1, nome5, nome2, nome4, nome3);


printf("\n\nvoce deseja continuar a execucao(s/n)");
scanf(" %c", &exec);

}
while (exec=='s');
}

#endif // ex2

#ifdef ex3
/*Escreva um programa que receba uma string na funcao main(). Faca uma funcao que
calcula o comprimento de uma string recebida via teclado. Mostre o valor do
comprimento na funcao main().
(Declare o vetor como variavel global) (nao pode usar funcao de biblioteca)*/

char exec, vetstring[50];

int CalculaComp(char *vetstring)
{
    int tamanho = 0;

    while (*vetstring != '\0') {
        tamanho++;
        vetstring++;
    }
    return tamanho;
}

main(){

    int tamanho;

do{

    fflush(stdin);

    printf("digite uma string: ");
    gets(vetstring);

    tamanho=CalculaComp(vetstring);

    printf("o comprimento dessa string e de %d caractere(s).", tamanho);


printf("\n\nvoce deseja continuar a execucao(s/n)");
scanf(" %c", &exec);

}
while (exec=='s');
}
#endif // ex3

#ifdef ex4
/*Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
para letras maiusculas. (nao pode usar funcao de biblioteca)*/
char exec, vetstring[11];

ConverteString(char *vetstring)
{
   while (*vetstring != '\0')
   {
        if (*vetstring >= 'a' && *vetstring <= 'z')
        {
            *vetstring = *vetstring - ('a' - 'A');
        }
        vetstring++;
    }
}

main(){


do{

    fflush(stdin);

    printf("digite uma string de ate 10 caracteres: ");
    gets(vetstring);

    ConverteString(vetstring);

    printf("\na string convertida em letras maiusculas fica: %s", vetstring);


printf("\n\nvoce deseja continuar a execucao(s/n)");
scanf(" %c", &exec);

}
while (exec=='s');
}
#endif // ex4

#ifdef ex5
/*Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
para letras minusculas. (nao pode usar funcao de biblioteca)*/
char exec, vetstring[11];

ConverteString(char *vetstring)
{
   while (*vetstring != '\0')
   {
        if (*vetstring >= 'A' && *vetstring <= 'Z')
        {
            *vetstring = *vetstring - ('A' - 'a');
        }
        vetstring++;
    }
}

main(){


do{

    fflush(stdin);

    printf("digite uma string de ate 10 caracteres: ");
    gets(vetstring);

    ConverteString(vetstring);

    printf("\na string convertida em letras minusculas fica: %s", vetstring);


printf("\n\nvoce deseja continuar a execucao(s/n)");
scanf(" %c", &exec);

}
while (exec=='s' || exec=='S');
}
#endif // ex5
