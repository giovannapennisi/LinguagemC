/*
NOMES: Giovanna Santana Pennisi
                  &
       Sofia Clementino dos Santos

CURSO: ADS Noturno - 2° CICLO
*/

#include <stdio.h>

    char medico1[20], medico2[20], medico3[20], aux[20];
    char data1[11], data2[11], data3[11];

Entrada()
{
    fflush(stdin);
    printf("digite o nome do medico 1: ");
    gets(medico1);
    printf("digite a data da consulta do medico 1: ");
    gets(data1);

    do
    {
    printf("digite o nome do medico 2: ");
    gets(medico2);
    printf("digite a data da consulta do medico 2: ");
    gets(data2);
    }
    while(medico1[0] == medico2[0] && medico1[1] == medico2[1] && medico1[2] == medico2[2] && medico1[3] == medico2[3] && medico1[4] == medico2[4] && medico1[5] == medico2[5] && medico1[6] == medico2[6] && medico1[7] == medico2[7] &&medico1[8] == medico2[8] && medico1[9] == medico2[9] && medico1[10] == medico2[10] && medico1[11] == medico2[11] &&medico1[12] == medico2[12] && medico1[13] == medico2[13] && medico1[14] == medico2[14] && medico1[15] == medico2[15] && medico1[16] == medico2[16] && medico1[17] == medico2[17] && medico1[18] == medico2[18] && medico1[19] == medico2[19]);

    do
    {
    printf("digite o nome do medico 3: ");
    gets(medico3);
    printf("digite a data da consulta do medico 3: ");
    gets(data3);
    }
    while (medico2[0] == medico3[0] && medico2[1] == medico3[1] && medico2[2] == medico3[2] && medico2[3] == medico3[3] &&
       medico2[4] == medico3[4] && medico2[5] == medico3[5] && medico2[6] == medico3[6] && medico2[7] == medico3[7] &&
       medico2[8] == medico3[8] && medico2[9] == medico3[9] && medico2[10] == medico3[10] && medico2[11] == medico3[11] &&
       medico2[12] == medico3[12] && medico2[13] == medico3[13] && medico2[14] == medico3[14] && medico2[15] == medico3[15] &&
       medico2[16] == medico3[16] && medico2[17] == medico3[17] && medico2[18] == medico3[18] && medico2[19] == medico3[19] ||
       medico1[0] == medico3[0] && medico1[1] == medico3[1] && medico1[2] == medico3[2] && medico1[3] == medico3[3] &&
       medico1[4] == medico3[4] && medico1[5] == medico3[5] && medico1[6] == medico3[6] && medico1[7] == medico3[7] &&
       medico1[8] == medico3[8] && medico1[9] == medico3[9] && medico1[10] == medico3[10] && medico1[11] == medico3[11] &&
       medico1[12] == medico3[12] && medico1[13] == medico3[13] && medico1[14] == medico3[14] && medico1[15] == medico3[15] &&
       medico1[16] == medico3[16] && medico1[17] == medico3[17] && medico1[18] == medico3[18] && medico1[19] == medico3[19]);
}

Lista()
{
    printf("\nLISTA DE TODOS OS MEDICOS E DATAS\n");
    printf("\nnome: %s - data consulta: %s", medico1, data1);
    printf("\nnome: %s - data consulta: %s", medico2, data2);
    printf("\nnome: %s - data consulta: %s\n", medico3, data3);
}

PesquisaMed()
{
    int i, comparador;

    fflush(stdin);
    printf("\npesquise o nome do medico que voce deseja encontrar: ");
    gets(aux);


    for(i=0; medico1[i] != '\0' || aux[i] != '\0'; i++)
    {
        if(medico1[i] != aux[i])
            {
                break;
            }
            if (medico1[i] == aux[i])
            {
                comparador = 1;
            }
    }

            for (i=0; medico1[1] != '\0' || aux[i] != '\0'; i++)
            {   if (medico2[i] != aux[i])
                {
                break;
                }
                if (medico2[i] == aux[i])
                {
                    comparador = 2;
                }
            }

            for (i=0; medico1[1] != '\0' || aux[i] != '\0'; i++)
            {   if (medico3[i] != aux[i])
                {
                break;
                }
                if (medico3[i] == aux[i])
                {
                    comparador = 3;
                }
            }


    if (comparador == 1) {
        printf("\nnome do medico: %s - data da consulta: %s\n", medico1, data1);
    }
    else
    if (comparador == 2) {
        printf("\nnome do medico: %s - data da consulta: %s\n", medico2, data2);
    }
    else
    if (comparador == 3)
    {
        printf("\nnome do medico: %s - data da consulta: %s\n", medico3, data3);
    }
    else

    {
        printf("\nnao encontrado.\n");
    }

}

PesquisaData()
{
    int i, comparador=0;

    fflush(stdin);
    printf("\npesquise a data que voce deseja encontrar: ");
    gets(aux);


            for(i=0; data1[i] != '\0' || aux[i] != '\0'; i++)
            {
            if(data1[i] != aux[i])
            {
                break;
            }
            if (data1[i] == aux[i])
            {
                comparador += 1;
                printf("\nmedico: %s - %s", medico1, data1);
            }
            }

            for (i=0; data1[1] != '\0' || aux[i] != '\0'; i++)
            {   if (data2[i] != aux[i])
                {
                break;
                }
                if (data2[i] == aux[i])
                {
                    comparador+=1;
                    printf("\nmedico: %s - %s", medico2, data2);
                }
            }

            for (i=0; data1[1] != '\0' || aux[i] != '\0'; i++)
            {   if (data3[i] != aux[i])
                {
                break;
                }
                if (data3[i] == aux[i])
                {
                    comparador+=1;
                    printf("\nmedico: %s - %s", medico3, data3);
                }
            }


    if (comparador == 1)
    { printf("\numa data foi encontrada!\n"); }
    else if (comparador == 2)
    { printf("\nduas datas foram encontradas!\n"); }
    else if (comparador == 3)
    { printf("\ntres datas foram encontradas!\n");}
    else if (comparador == 0)
    { printf("\nnao encontrado!\n"); }


}

Altera()
{

}
Exclui()
{

}

main()
{
    int opcao;

    do{
printf("Escolha uma das opcoes abaixo: \n");


printf("1 - Entrada de dados.\n");
printf("2 - Lista todos os dados na tela.\n");
printf("3 - Pesquisa um medico pelo nome completo e mostra todo os dados na tela\n");
printf("4 - Pesquisa pela data de consulta e mostra todos na tela.\n");
printf("5 - Altera dados. Pesquisa pelo nome completo do medico.\n");
printf("6 - Exclui dados. Pesquisa pelo nome completo do medico.\n");
printf("7 - Saida\n");

printf("Opcao escolhida: ");
scanf("%d", &opcao);

    if(opcao == 1)
    {
        Entrada();
    }
    else
        if(opcao == 2)
    {
        Lista();
    }
    else
        if(opcao == 3)
    {
        PesquisaMed();
    }
    else
        if(opcao == 4)
    {
        PesquisaData();
    }
    else
        if(opcao == 5)
    {
        Altera();
    }
    else
        if(opcao == 6)
    {
        Exclui();
    }
    else
        if (opcao == 7)
    {
        exit(0);
    }



    }while(opcao> 0 && opcao<8);
}
