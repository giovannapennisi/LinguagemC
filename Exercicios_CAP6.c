/*
NOMES: Giovanna Santana Pennisi
                  &
       Sofia Clementino dos Santos

CURSO: ADS Noturno - 2° CICLO
*/

#include <stdio.h>
#define ex5

#ifdef ex1
/*Escreva um programa que receba via teclado 2 numeros inteiros e
imprima-os no video com o resultado das 4 operacoes aritmeticas.*/
main(){

    char exec;
    int num1, num2;

do{

    printf("digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("digite o segundo numero: ");
    scanf("%d", &num2);

    printf("\nSoma: %d \nSubtracao: %d \nMutiplicacao: %d",
           num1+num2, num1 - num2, num1 * num2);

    if(num2==0)
    {
    printf("\nNao e possivel dividir um numero por zero");
    }
    else
    {
    printf("\nDivisao: %d", num1/num2);
    }


printf("\n\nvoce deseja continuar a execucao(s/n)");
scanf(" %c", &exec);

}
while (exec=='s' || exec=='S');
}
#endif // ex1

#ifdef ex2
/*Reescreva o exercicio anterior utilizando operadores de atribuicao composta.*/
main(){

    char exec;
    int num1, num2;

do{

    printf("digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("digite o segundo numero: ");
    scanf("%d", &num2);

    num1+=num2;
    printf("\nSoma: %d", num1);;

    num1-=num2;
    printf("\nSubtracao: %d", num1);

    num1*=num2;
    printf("\nMultiplicacao: %d", num1);

    if(num2==0)
    {
    printf("\nNao e possivel dividir um numero por zero");
    }
    else
    {
    num1/=num2;
    printf("\nDivisao: %d", num1);
    }


printf("\n\nvoce deseja continuar a execucao(s/n)");
scanf(" %c", &exec);

}
while (exec=='s' || exec=='S');
}
#endif // ex2

#ifdef ex3
/* Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
data (dia, mes e ano) atual.*/
main(){

    char exec;
    int dianasc, mesnasc, anonasc, diaagr, mesagr, anoagr, diaresult, mesresult, anoresult, ultimodia;

do{

    printf("insira a data de nascimento: ");
    scanf("%d %d %d", &dianasc, &mesnasc, &anonasc);

    printf("insira a data atual: ");
    scanf("%d %d %d", &diaagr, &mesagr, &anoagr);


    anoresult = anoagr - anonasc;

    if (mesagr < mesnasc || (mesagr == mesnasc && diaagr < dianasc))
    {
        anoresult--;
        mesresult = 12 - mesnasc + mesagr - 1;
    }
        else
        {
        mesresult = mesagr - mesnasc;
        }


    if (diaagr < dianasc)
    {
        mesresult--;

        if (mesagr == 0)
        {
            mesresult = 11;
            anoresult--;
        }

            if (mesagr == 1 || mesagr == 3 || mesagr == 5 || mesagr ==7 || mesagr == 8 || mesagr == 10 || mesagr ==12)
            {
                ultimodia=31;
            }
            else if (mesagr == 4 || mesagr == 6 || mesagr == 9 | mesagr == 11)
            {
                ultimodia=30;
            }
            else if (mesagr==2)
            {
                if ((anoagr % 4 == 0 && anoagr % 100 != 0) || (anoagr % 400 == 0))
                {
                    ultimodia=29;
                }
                else
                {
                    ultimodia=28;
                }
            }
            else
                printf("mes inexistente.");

        diaresult = diaagr + ultimodia - dianasc;
    }
        else
        {
        diaresult = diaagr - dianasc;
        }

    printf("\nessa pessoa tem %d anos, %d meses e %d dias\n", anoresult, mesresult, diaresult);

printf("\n\nvoce deseja continuar a execucao(s/n)");
scanf(" %c", &exec);
}
while (exec=='s' || exec=='S');
}
#endif // ex3

#ifdef ex4
/*Escreva um programa que receba via teclado uma data (dia, mes, e ano).
Determine o dia da semana desta data.*/

main(){

    char exec;
    int dia, mes, ano, aux1, aux2, result;

do{
    printf("insira a data que sera calculada: ");
    scanf("%d %d %d", &dia, &mes, &ano);

    if (mes == 1 || mes == 2)
    {
        mes += 12;
        ano--;
    }

    aux1 = ano % 100;
    aux2 = ano / 100;

    result = (dia + 13 * (mes + 1) / 5 + aux1 + aux1 / 4 + aux2 / 4 - 2 * aux2) % 7;


    if (result < 0)
    {
        result += 7;
    }

    switch (result)
    {
        case 0:
            printf("este dia corresponde a um sabado\n");
            break;
        case 1:
            printf("este dia corresponde a um domingo\n");
            break;
        case 2:
            printf("este dia corresponde a uma segunda-feira\n");
            break;
        case 3:
            printf("este dia corresponde a uma terça-feira\n");
            break;
        case 4:
            printf("este dia corresponde a uma quarta-feira\n");
            break;
        case 5:
            printf("este dia corresponde a uma quinta-feira\n");
            break;
        case 6:
            printf("este dia corresponde a uma sexta-feira\n");
            break;
        default:
            printf("data digitada invalida\n");
    }

printf("\n\nvoce deseja continuar a execucao(s/n)");
scanf(" %c", &exec);
}
while (exec=='s' || exec=='S');
}
#endif // ex4

#ifdef ex5
/*Escreva um programa que receba via teclado 2 numeros inteiros e execute
as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
video no formato decimal e hexadecimal.*/
main(){

    char exec;
    int num1, num2, resultAND, resultOU, resultOUEX;

do{

    printf("digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("digite o segundo numero: ");
    scanf("%d", &num2);

    resultAND = num1 & num2;
    resultOU = num1 | num2;
    resultOUEX = num1 ^ num2;

    /*VERIFICAR SE EH MELHOR O %i OU O %x OU USAR A TABELA ASCII*/

    printf("\nresultado and - decimal: %d e hexadecimal: %X", resultAND, resultAND);
    printf("\nresultado ou - decimal: %d e hexadecimal: %X", resultOU, resultOU);
    printf("\nresultado ou exclusivo - decimal: %d e hexadecimal: %X", resultOUEX, resultOUEX);

printf("\n\nvoce deseja continuar a execucao(s/n)");
scanf(" %c", &exec);

}
while (exec=='s' || exec=='S');
}
#endif // ex5
