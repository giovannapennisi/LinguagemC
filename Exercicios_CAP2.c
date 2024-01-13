/*
NOMES: Giovanna Santana Pennisi
                  &
       Sofia Clementino dos Santos

CURSO: ADS Noturno - 2° CICLO
*/

#include <stdio.h>
#define ex5

/*OBS.: Todos os programa devem ser finalizados pelo usuario.*/

#ifdef ex1
/*As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os instantes em que a ligacao
foi iniciada e concluida. Escreva um programa que recebe via teclado dois instantes dados em horas, minutos
e segundo e determina o intervalo de tempo(em horas, minutos e segundos) decorrido entre eles.*/

main()
{   int hr1, min1, seg1, hr2, min2, seg2, hr_dif, min_dif, seg_dif;
    char exec;

    do
        {
    printf("digite um instante inicial em horas, minutos e segundos: \n");
    scanf ("%d%d%d", &hr1, &min1, &seg1);
    printf("digite um instante final em horas, minutos e segundos: \n");
    scanf ("%d%d%d", &hr2, &min2, &seg2);

    hr_dif = hr2-hr1;
    min_dif = min2-min1;
    seg_dif = seg2-seg1;

    if (seg_dif <0) //fazer empréstimo de 1min (60s)
    {
        min_dif = min_dif - 1;
        seg_dif = seg_dif + 60;
    }

    if (min_dif <0) //fazer empréstimo de 1h (60min)
    {
        hr_dif = hr_dif - 1;
        min_dif = min_dif + 60;
    }

    printf("a diferença entre os horarios e de: %d %d %d", hr_dif, min_dif, seg_dif);


             printf("\nvoce quer continuar a execucao(s/n)?");
    scanf (" %c", &exec);
    }
        while (exec=='s');
            printf ("!!!!!!!fim!!!!!!!!");
}


#endif // ex1

#ifdef ex2
/*Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario pensou. Digite via
teclado os simbolos =, > ou < a cada pergunta. Utilize o comando if-else.*/

main()
{   int numinicial = 1, numfinal = 99, numadivinha;
    char sinal, exec;

    do
        {
    do
    {
        numadivinha = (numinicial + numfinal)/ 2;
    printf("o programa ira adivinhar o numero que voce esta pensando. o primeiro numero eh %d", numadivinha);
    printf("\n o numero e maior (>), menor (<) ou igual (=) ?\n");
    scanf(" %c", &sinal);

    if (sinal == '>')
    {numinicial = numadivinha+1;}

    else

    if (sinal == '<')
    {numfinal = numadivinha-1;}

    if(sinal != '<' && '>' && '=')
        printf("\ndigite somente < > ou =\n\n");
    }
    while (sinal != '=');

    printf("acertei");

    printf("\nvoce quer continuar a execucao(s/n)?");
    scanf (" %c", &exec);
        }
        while (exec=='s');
            printf ("!!!!!!!fim!!!!!!!!");
}

#endif // ex2

#ifdef ex3
/*Reescreva o programa do exercicio anterior agora utilizando o comando switch. Conte o n. de tentativas
e imprima o resultado no video.*/

main()
{   int numinicial = 1, numfinal = 99, numadivinha;
    char sinal, exec;

   do
   {
    do
    {
    numadivinha = (numinicial + numfinal)/ 2;
    printf("o programa ira adivinhar o numero que voce esta pensando. o primeiro numero eh %d", numadivinha);
    printf("\n o numero e maior (>), menor (<) ou igual (=) ?\n");
    scanf(" %c", &sinal);

    switch (sinal)
    {
    case '>':
    numinicial = numadivinha+1;
    break;

    case '<':
    numfinal = numadivinha-1;
    break;

     case '=':
    printf("acertei");
    break;

    default:
        printf("digite somente < > ou =");
    }
    }
    while(sinal != '=');


    printf("\nvoce quer continuar a execucao(s/n)?");
    scanf (" %c", &exec);

    } while (exec=='s');



            printf ("!!!!!!!fim!!!!!!!!");
}

#endif // ex3

#ifdef ex4
/*Receba via teclado a distancia em km e a quantidade de litros de gasolina consumidos por um carro em
um percurso. Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela abaixo:
    CONSUMO (km/l) MENSAGEM
    menor que 8    Venda o carro!
    entre 8 e 14   Economico!
    maior que 14   Super economico!*/

main()
{   char exec;
    float dist, qtd, cons;
    do
    {
    printf("digite a distancia em km: ");
    scanf("%f", &dist);
    printf("digite a quantidade de litros de gasolina consumidos: ")/
    scanf("%f", &qtd);

    cons = dist/qtd;

    if (cons < 8)
    {
        printf("Venda o carro!");
    }
    else
        if (cons >= 8 && cons <= 14)
    {
        printf("Economico!");
    }
        else
    {
            printf("Super economico!");
    }

    printf("\nvoce quer continuar a execucao(s/n)?");
    scanf (" %c", &exec);
    }

    while (exec=='s');
}
#endif // ex4

#ifdef ex5
/*Escreva um programa que receba via teclado numeros inteiros positivos. Quando o numero digitado for negativo
o programa deve parar e calcula a media dos valores positivos digitados.*/
main()
{
char exec;
int num, cont=0, soma=0, media;

do
{
    do
    {
    printf("digite um numero: ");
    scanf("%d", &num);

    if (num>=0)
    {
    soma=soma+num;
    cont++;
    }

    }
    while(num>=0);

    media=soma/cont;

    printf("a media dos positivos e: %d", media);

    printf("\nvoce quer continuar a execucao(s/n)?");
    scanf (" %c", &exec);
}
while (exec=='s');
}
#endif // ex5
