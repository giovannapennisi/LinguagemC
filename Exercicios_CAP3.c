/*
NOMES: Giovanna Santana Pennisi
                  &
       Sofia Clementino dos Santos

CURSO: ADS Noturno - 2° CICLO
*/

#include <stdio.h>
#define ex5

#ifdef ex1
/*Escreva um programa que receba um numero N via teclado. Escreva uma funcao que retorne a soma
dos algarismos do resultado de N!. O resultado deve ser mostrado na funcao main().
Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e´ 2 + 4 = 6.*/
char exec;
int num, soma=0, fatorial, digito;

Soma(int fatorial)
{
    while (fatorial>0)
    {
        digito = fatorial % 10;
        soma = soma + digito;
        fatorial = fatorial/10;
    }
    return soma;

}
main()
{

do
{
    do
    {
    printf("digite um numero: ");
    scanf("%d", &num);
    if(num<0)
    {
        printf("\ndigite apenas numeros positivos\n\n");
    }
    }
    while(num<0);

    for(fatorial = 1; num > 1; num = num - 1)
    {
      fatorial = fatorial * num;
    }

    soma=Soma(fatorial);

    printf("\na soma e: %d", soma);

    printf("\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);

    soma=0;
}
while (exec=='s');

}
#endif // ex1

#ifdef ex2
/*Escreva um programa que receba dois numeros inteiros e execute as seguintes funçoes:
    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
      retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
      eles.
    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
      entre eles.
    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.
*/
char exec;
int num1, num2, sinal1, sinal2, somacont, multcont=1, div;

VerificarSinal(int num)
{
    if(num>0)
    {return 1;}
    else
        if(num==0)
    {return -1;}
    else
    {return 0;}
}

RetornarSoma(int num1, int num2)
{   int cont;
    if(num1<num2)
    {
    for(cont = num1 + 1; cont < num2; cont++)
    {somacont += cont;}
        return somacont;
    }
    else
        if(num2<num1)
    {
    for(cont = num2 + 1; cont < num1; cont++)
    {somacont += cont;}
        return somacont;
    }
    else
    {return 0;}
}

RetornarMult(int num1, int num2)
{   int cont;
    if(num1<num2)
    {
    for(cont = num1 + 1; cont < num2; cont++)
    {multcont *= cont;}
        return multcont;
    }
    else
        if(num2<num1)
    {
    for(cont = num2 + 1; cont < num1; cont++)
    {multcont *= cont;}
        return multcont;
    }
    else
    {return 0;}
}

RetornarDiv(int num1, int num2)
{
    div = num1/num2;
    return div;
}

main()
{

do
{
    printf("digite um numero: ");
    scanf("%d", &num1);
    printf("digite outro numero: ");
    scanf("%d", &num2);


    sinal1= VerificarSinal(num1);
    sinal2= VerificarSinal(num2);
    printf("%d\n%d", sinal1, sinal2);


    if(sinal1 && sinal2 == 1)
    {
        somacont= RetornarSoma(num1, num2);
        printf("\nresultado da soma: %d\n", somacont);
    }

    else
        if(sinal1 == 0 && sinal2 == 0)
    {
        multcont= RetornarMult(num1, num2);
        printf("\nresultado da multiplicacao: %d\n", multcont);
    }
    else
    {
        div= RetornarDiv(num1, num2);
        printf("\nresultado da divisao: %d\n", div);
    }
    printf("\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);
}
while (exec=='s');
}
#endif // ex2

#ifdef ex3
/*Escreva um programa que receba na funcao main() 2 valores inteiros. Escreva uma funcao para
cada operacoes aritmeticas e passe como parametro os 2 valores recebidos na funcao main().
Retorne os resultados usando o comando return e imprima os 4 resultados no video na funcao main().*/
char exec;
int num1, num2, soma, subtracao, multip, divisao;

Soma(int num1, int num2)
{
    soma = num1+num2;

    return soma;
}

Subtracao(int num1, int num2)
{
    subtracao = num1-num2;

    return subtracao;
}

Multip(int num1, int num2)
{
    multip = num1*num2;

    return multip;
}

Divisao(int num1, int num2)
{
    divisao = num1/num2; //colocar bagulho de (tipo)

    return divisao;
}

main()
{
do
{
    printf("digite um numero: ");
    scanf("%d", &num1);
    printf("digite outro numero: ");
    scanf("%d", &num2);

    soma=Soma(num1,num2);
    printf("a soma e: %d", soma);
    subtracao=Subtracao(num1,num2);
    printf("\na subtracao e: %d", subtracao);
    multip=Multip(num1, num2);
    printf("\na multiplicacao e: %d", multip);
    divisao=Divisao(num1, num2);
    printf("\na divisao e: %d", divisao);

    printf("\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);

}
while (exec=='s');
}
#endif // ex3

#ifdef ex4
/*Reescreva o programa do exercicio anterior para receber via teclado n valores. Os n
valores nao sao definidos previamente.*/
char exec;
int soma, subtracao, multip=1, qtd, contqtd, cont=0;
float divisao;

Soma(int num)
{
    soma += num;
}

Subtracao(int num)
{
    subtracao -= num;
}

Multip(int num)
{
    multip *= num;
}

Divisao(int num)
{
    divisao = (float)divisao/(float)num;
}

main()
{   int num;
do
{   printf("para parar digite zero");

    printf("\ndigite os numeros desejados: ");
    scanf("%d", &num);

    soma=num;
    subtracao=num;
    multip=num;
    divisao=num;

    do{
    printf("\ndigite os numeros desejados: ");
    scanf("%d", &num);

    if(num!=0)
    {
    Soma(num);
    Subtracao(num);
    Multip(num);
    Divisao(num);
    }


    }while (num!=0);

    printf("\n soma: %d", soma);
    printf("\n subtracao: %d", subtracao);
    printf("\n multiplicacao: %d", multip);
    printf("\n divisao: %f", divisao);

    printf("\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);

}
while (exec=='s');
}
#endif // ex4

#ifdef ex5
/*Escreva um programa que receba n valores inteiros via teclado na funcao main().Faca uma calculadora
com as 4 operacoes aritmeticas.(utilize o comando switch). As operacoes aritmeticas devem ser funcoes.
O resultado acumulado deve ser mostrado na funcao main().*/
char exec, op;


Soma(int resultado, int num)
{
    resultado += num;
    return resultado;
}

Subtracao(int resultado, int num)
{
    resultado -= num;
    return resultado;
}

Multip(int resultado, int num)
{
   resultado *= num;
   return resultado;
}

Divisao(int resultado, int num)
{
    resultado = resultado/num;
    return resultado;
}

main()
{   int num, resultado;

do
{   printf("para parar digite zero");

    printf("\ndigite o primeiro valor: ");
    scanf("%d", &num);


    resultado=num;


    do{
    printf("\ndigite a operacao desejada: (+, -, *, /) ");
    scanf(" %c", &op);


    printf("\ndigite um valor: ");
    scanf("%d", &num);


    switch(op)
	{
        case '+' :
		{
        resultado = Soma(resultado, num);
        printf ("\n resultado soma: %d", resultado);
		break;
		}
        case '-' :
		{
		 resultado = Subtracao(resultado, num);
		  printf ("\n resultado: %d", resultado);
		break;
		}
		case '*' :
		{
        resultado = Multip(resultado, num);
        printf ("\n resultado: %d", resultado);
		break;
		}
		case '/' :
		{
		resultado = Divisao(resultado,num);
        printf ("\n resultado: %d", resultado);
		break;
		}
        default:
		{
		printf ("\n invalido");
		}

        printf ("\n resultado: %d", resultado);


	}

    } while (num!=0);

    printf("\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);
}
while (exec=='s');
}

#endif // ex5
