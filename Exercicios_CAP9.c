/*
NOMES: Giovanna Santana Pennisi
                  &
       Sofia Clementino dos Santos

CURSO: ADS Noturno - 2° CICLO
*/

#include <stdio.h>
#define ex6

#ifdef ex1
/*Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na função main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main().*/

int Compara(char *ps1, char *ps2)
{
    int i = 0;

    for (i=0; *(ps1+i) != '\0';i++)
        {
        if (*(ps1+i) != *(ps2+i))
        {
        return 0;
        }
        }
        if (*(ps1+i) == '\0' && *(ps2+i) == '\0')
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
    char exec, string1[10], string2[10];

do{
    fflush(stdin);
    printf("digite a string 1: ");
    scanf("%s", &string1);

    fflush(stdin);
    printf("digite a string 2: ");
    scanf("%s", &string2);

    int comparar= Compara(&string1, &string2);

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
/*Escreva um programa que receba n valores via teclado e receba tambem a
    operação a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operações aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.
    As variaveis sao LOCAIS na funcao main().*/
RecebeOperador(char *opp)
{
    printf("\ndigite a operacao desejada (+, -, *, /) ou '=' para exibir o resultado acumulado:  ");
    scanf(" %c", opp);
}

RecebeNum(int *pn)
{
    printf("\ndigite um valor: ");
    scanf("%d", pn);
}

int Soma(int *pr, int *pn)
{
    *pr += *pn;
    return *pr;
}

int Subtracao(int *pr, int *pn)
{
    *pr -= *pn;
    return *pr;
}

int Multip(int *pr, int *pn)
{
   *pr *= *pn;
   return *pr;
}

int Divisao(int *pr, int *pn)
{
    *pr = (*pr)/(*pn);
    return *pr;
}

main()
{
    int num, resultado;
    char exec, op;

do
{
    printf("\ndigite o primeiro valor: ");
    scanf("%d", &num);
    resultado=num;

    do
    {

    RecebeOperador(&op);

    if(op != '=')
    {
    RecebeNum(&num);
    }

    switch(op)
	{
        case '+' :
		{
        resultado = Soma(&resultado, &num);
		break;
		}
        case '-' :
		{
		 resultado = Subtracao(&resultado, &num);
		break;
		}
		case '*' :
		{
        resultado = Multip(&resultado, &num);
		break;
		}
		case '/' :
		{
		resultado = Divisao(&resultado,&num);
		break;
		}
		case '=':
        {
        printf ("\nTOTAL: %d", resultado);
        break;
        }
	}
    }while (op != '=');

    printf("\nvoce deseja executar novamente? (s/n) ");
    scanf(" %c", &exec);
}
while (exec=='s');
}
#endif // ex2

#ifdef ex3
/*Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa
    usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/

int i;

int PesquisaC(char *p, char *p2)
{
       for(i=0; i<13; i++)
       {
        if (*p == *(p2+i))
            {
            return 1;
            }
       }
}

main()
{
    char vetletras[13] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};
    char exec, letra, *pletra, *pvetor;
    do
    {
    fflush(stdin);
    pletra = &letra;
    pvetor = &vetletras;

    printf("\ndigite uma letra: ");
    scanf ("%c", pletra);

    printf("\na letra pertence ao conjunto = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'}? \n");
    int Pesquisar = PesquisaC(pletra, pvetor);

    if(Pesquisar == 1)
    {
        printf("\na letra '%c' pertence ao conjunto, e se encontra na posicao %d dentro do conjunto!!!", *pletra, i+1);
    }
    else
    {
        printf("\na letra '%c' nao pertence ao conjunto", *pletra);
    }


    printf("\n\nvoce deseja continuar a execucao(s/n) ");
    scanf(" %c", &exec);
    }
        while (exec=='s');
}
#endif // ex3

#ifdef ex4
/*Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato(também numa função).

    estrutura: char, int, long, float, double, unsigned char, unsigned int,
    unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long*/

RecebeChar(char *ch)
{
    fflush(stdin);
    printf("\ndigite um caracter: ");
    scanf(" %c", ch);
}

RecebeInt(int *in)
{
    printf("\ndigite um num inteiro: ");
    scanf("%i", in);
}

RecebeNLong(long *lo)
{
    printf("\ndigite um num longo: ");
    scanf("%ld", lo);
}

RecebeFloat(float *fl)
{
    printf("\ndigite um num float: ");
    scanf("%e", fl);
}

RecebeDouble(double *db)
{
    printf("\ndigite um num double: ");
    scanf("%le", db);
}

RecebeUChar(unsigned char *uc)
{
    printf("\ndigite um caractere sem sinal: ");
    scanf("%u", uc);
}

RecebeUInt(unsigned *ui)
{
    printf("\ndigite um num inteiro sem sinal: ");
    scanf("%u", &ui);
}

RecebeULong(unsigned long *ul)
{
    printf("\ndigite um num longo inteiro: ");
    scanf("%lu", ul);
}

ImprimeDados(char *ch, int *in, long *lo,  float *fl, double *db, unsigned char *uc, unsigned *ui, unsigned long *ul)
{
    printf("    %c", *ch);
    printf("         %-11i", *in);
    printf("%-11ld", *lo);
    printf("        %-8.1e", *fl);
    printf("            %-8.1le", *db);
    printf("\n          %-3u", *uc);
    printf("                 %-10u", *ui);
    printf("          %-10lu", *ul);
}

main()
{
    char exec;

    struct var
    {
    char ch;
    int in;
    long lo;
    float fl;
    double db;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
    };

    struct var num;

    do
    {
    RecebeChar(&num.ch);
    RecebeInt(&num.in);
    RecebeNLong(&num.lo);
    RecebeFloat(&num.fl);
    RecebeDouble(&num.db);
    RecebeUChar(&num.uc);
    RecebeUInt(&num.ui);
    RecebeULong(&num.ul);

    printf("\n        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    ImprimeDados(&num.ch, &num.in, &num.lo, &num.fl, &num.db, &num.uc, &num.ui, &num.ul);

    printf("\n\nvoce deseja continuar a execucao(s/n)");
    scanf(" %c", &exec);
    }
    while (exec=='s');

}
#endif // ex4

#ifdef ex5
/* Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa função e imprima todos os registros no
    video em outra funcao. Faça um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opção de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
     estutura: nome, end, cidade, estado, cep*/

struct var
    {
    char nome[20];
    char end[30];
    char cidade[20];
    char estado[20];
    char cep[11];
    };

RecebeDados(struct var *p)
{
    for (int i=0; i<4; i++)
    {
    fflush(stdin);
    printf("\nInsira dados de 4 pessoas diferentes abaixo: \n\n");
    printf("nome: ");
    scanf("%s", &(p+i)->nome[0]);
    fflush(stdin);
    printf("endereco: ");
    scanf("%s", &(p+i)->end[0]);
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

ImprimeDados(struct var *p)
{
    for (int i=0; i<4; i++)
    {
    printf("\nDados %i: \n", i+1);
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

    struct var dados[4];
    struct var *p;

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
/*Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro sempre usando ponteiros.*/ //usar um asterisco para excluir o registro
 struct var
    {
    char nome[20];
    char end[30];
    char cidade[20];
    char estado[20];
    char cep[11];
    };

    char procura[20];

RecebeDados(struct var *p)
{
    for (int i=0; i<4; i++)
    {
    fflush(stdin);
    printf("\nInsira dados de 4 pessoas diferentes abaixo: \n\n");
    printf("nome: ");
    scanf("%s", &(p+i)->nome[0]);
    fflush(stdin);
    printf("endereco: ");
    scanf("%s", &(p+i)->end[0]);
    fflush(stdin);
    printf("cidade: ");
    scanf("%s", &(p+i)->cidade[0]);
    fflush(stdin);
    printf("estado: ");
    scanf("%s", &(p+i)->estado[0]);
    fflush(stdin);
    printf("cep (com o traco): ");
    scanf("%s", &(p+i)->cep[0]);
    }
}

ImprimeDados(struct var *p)
{
    for (int i=0; i<4; i++)
    {
    printf("\nDados %i: \n", i+1);
    printf("nome: %s", (p+i) -> nome);
    printf("\nendereco: %s", (p+i) -> end);
    printf("\ncidade: %s", (p+i) -> cidade);
    printf("\nestado: %s", (p+i) -> estado);
    printf("\ncep: %s\n\n", (p+i) -> cep);
    }
}

int ComparaDados(char *c1, char *c2)
{
    int i = 0;
    do
    {
        if (c1[i] != c2[i])
        {
            return 0;
        }
        i++;
    } while (c1[i] != '\0' || c2[i] != '\0');
    return 1;
}

ProcuraDados(struct var *p)
{

    printf("\npesquise o nome para buscar dados: \n");
    fflush(stdin);
    gets(procura);

    if(ComparaDados((p+0)->nome, procura))
    {
        printf ("\nDADOS BUSCADOS: \n\nnnome: %s \nendereco: %s \ncidade: %s \nestado: %s \ncep: %s", (p+0)->nome, (p+0)->end, (p+0)->cidade, (p+0)->estado, (p+0)->cep);
    }
    else
     if(ComparaDados((p+1)->nome, procura))
    {
        printf ("\nDADOS BUSCADOS: \n\nnnome: %s \nendereco: %s \ncidade: %s \nestado: %s \ncep: %s", (p+1)->nome, (p+1)->end, (p+1)->cidade, (p+1)->estado, (p+1)->cep);
    }
    else
    if(ComparaDados((p+2)->nome, procura))
    {
        printf ("\nDADOS BUSCADOS: \n\nnnome: %s \nendereco: %s \ncidade: %s \nestado: %s \ncep: %s", (p+2)->nome, (p+2)->end, (p+2)->cidade, (p+2)->estado, (p+2)->cep);
    }
    else
    if(ComparaDados((p+3)->nome, procura))
    {
        printf ("\nDADOS BUSCADOS: \n\nnnome: %s \nendereco: %s \ncidade: %s \nestado: %s \ncep: %s", (p+3)->nome, (p+3)->end, (p+3)->cidade, (p+3)->estado, (p+3)->cep);
    }
    else
    {
        printf ("\nDADOS NAO ENCONTRADOS, tente novamente.\n");
    }
}

AlteraDados(struct var *p)
{
    printf("\npesquise o nome para alterar dados: \n");
    fflush(stdin);
    gets(procura);

    if(ComparaDados((p+0)->nome, procura))
    {
    printf("\ndigite novos dados: \n");
    printf("nome: ");
    scanf("%s", &(p+0)->nome[0]);
    fflush(stdin);
    printf("endereco: ");
    scanf("%s", &(p+0)->end[0]);
    fflush(stdin);
    printf("cidade: ");
    scanf("%s", &(p+0)->cidade[0]);
    fflush(stdin);
    printf("estado: ");
    scanf("%s", &(p+0)->estado[0]);
    fflush(stdin);
    printf("cep (com o traco): ");
    scanf("%s", &(p+0)->cep[0]);
    }
    else
     if(ComparaDados((p+1)->nome, procura))
    {
    printf("\ndigite novos dados: \n");
    printf("nome: ");
    scanf("%s", &(p+1)->nome[0]);
    fflush(stdin);
    printf("endereco: ");
    scanf("%s", &(p+1)->end[0]);
    fflush(stdin);
    printf("cidade: ");
    scanf("%s", &(p+1)->cidade[0]);
    fflush(stdin);
    printf("estado: ");
    scanf("%s", &(p+1)->estado[0]);
    fflush(stdin);
    printf("cep (com o traco): ");
    scanf("%s", &(p+1)->cep[0]);
    }
    else
    if(ComparaDados((p+2)->nome, procura))
    {
    printf("\ndigite novos dados: \n");
    printf("nome: ");
    scanf("%s", &(p+2)->nome[0]);
    fflush(stdin);
    printf("endereco: ");
    scanf("%s", &(p+2)->end[0]);
    fflush(stdin);
    printf("cidade: ");
    scanf("%s", &(p+2)->cidade[0]);
    fflush(stdin);
    printf("estado: ");
    scanf("%s", &(p+2)->estado[0]);
    fflush(stdin);
    printf("cep (com o traco): ");
    scanf("%s", &(p+2)->cep[0]);
    }
    else
    if(ComparaDados((p+3)->nome, procura))
    {
    printf("\ndigite novos dados: \n");
    printf("nome: ");
    scanf("%s", &(p+3)->nome[0]);
    fflush(stdin);
    printf("endereco: ");
    scanf("%s", &(p+3)->end[0]);
    fflush(stdin);
    printf("cidade: ");
    scanf("%s", &(p+3)->cidade[0]);
    fflush(stdin);
    printf("estado: ");
    scanf("%s", &(p+3)->estado[0]);
    fflush(stdin);
    printf("cep (com o traco): ");
    scanf("%s", &(p+3)->cep[0]);
    }
    else
    {
        printf ("\nDADOS NAO ENCONTRADOS, tente novamente.\n");
    }
}

ExcluiDados(struct var *p)
{
    printf("\npesquise o nome para excluir dados: \n");
    fflush(stdin);
    gets(procura);

if(ComparaDados((p+0)->nome, procura))
    {
        (p+0)->nome[0] = '*';
        (p+0)->nome[1] = '\0';
        (p+0)->end[0] = '*';
        (p+0)->end[1] = '\0';
        (p+0)->cidade[0] = '*';
        (p+0)->cidade[1] = '\0';
        (p+0)->estado[0] = '*';
        (p+0)->estado[1] = '\0';
        (p+0)->cep[0] = '*';
        (p+0)->cep[1] = '\0';

        printf("\ndados excluidos.\n");
    }
    else
     if(ComparaDados((p+1)->nome, procura))
    {
        (p+1)->nome[0] = '*';
        (p+1)->nome[1] = '\0';
        (p+1)->end[0] = '*';
        (p+1)->end[1] = '\0';
        (p+1)->cidade[0] = '*';
        (p+1)->cidade[1] = '\0';
        (p+1)->estado[0] = '*';
        (p+1)->estado[1] = '\0';
        (p+1)->cep[0] = '*';
        (p+1)->cep[1] = '\0';

        printf("\ndados excluidos.\n");
    }
    else
    if(ComparaDados((p+2)->nome, procura))
    {
        (p+2)->nome[0] = '*';
        (p+2)->nome[1] = '\0';
        (p+2)->end[0] = '*';
        (p+2)->end[1] = '\0';
        (p+2)->cidade[0] = '*';
        (p+2)->cidade[1] = '\0';
        (p+2)->estado[0] = '*';
        (p+2)->estado[1] = '\0';
        (p+2)->cep[0] = '*';
        (p+2)->cep[1] = '\0';

        printf("\ndados excluidos.\n");
    }
    else
    if(ComparaDados((p+3)->nome, procura))
    {
        (p+3)->nome[0] = '*';
        (p+3)->nome[1] = '\0';
        (p+3)->end[0] = '*';
        (p+3)->end[1] = '\0';
        (p+3)->cidade[0] = '*';
        (p+3)->cidade[1] = '\0';
        (p+3)->estado[0] = '*';
        (p+3)->estado[1] = '\0';
        (p+3)->cep[0] = '*';
        (p+3)->cep[1] = '\0';

        printf("\ndados excluidos.\n");
    }
    else
    {
        printf ("\nDADOS NAO ENCONTRADOS, tente novamente.\n");
    }
}

main()
{
    char opcao;


    struct var dados[4];
    struct var *p;

    p = &dados[0];

   do
    {
    printf("\n\n[1] Entrada de dados\n");
    printf("[2] Exibir dados\n");
    printf("[3] Procura dados\n");
    printf("[4] Altera dados\n");
    printf("[5] Exclui dados\n");
    printf("[6] Sair\n\n");
    printf("Digite a opcao desejada: ");
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
            ProcuraDados(p);
        }
        else
        if(opcao == '4')
        {
            AlteraDados(p);
        }
        else
        if(opcao == '5')
        {
            ExcluiDados(p);
        }
        else
        if(opcao == '6')
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
#endif // ex6
