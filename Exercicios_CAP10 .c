/*
NOMES: Giovanna Santana Pennisi
                  &
       Sofia Clementino dos Santos

CURSO: ADS Noturno - 2° CICLO
*/

#include <stdio.h>
#define ex4

#ifdef ex1
/* Escreva um programa para criar e abrir um arquivo texto de nome "arq.txt".
    Receba via teclado diversos caracteres (um por vezes) e escreva-os
    nesse arquivo. O caracter '0' finaliza a entrada de dados. Abra o arquivo
    "arq.txt", leia e imprima na tela todos os caracteres armazenados no
    arquivo (um por vezes).*/

main(){
    FILE *p;
    char caracter, exec;
    do
        {
    if((p = fopen("arquivo.txt", "w")) == NULL)
	{
	printf("\nErro.\n");
	exit(0);
	}

	printf("Digite '0' para finalizar a entrada de dados.\n");
    while(1)
    {
        printf("Digite um caracter: ");
        scanf(" %c", &caracter);
        if(caracter == '0')
        {
        break;
        }
        putc(caracter, p);
    }
    fclose(p);

    if((p = fopen("arquivo.txt", "r")) == NULL)
	{
	printf("\nErro.\n");
	exit(0);
	}

    while((caracter = getc(p)) != EOF)
    {
    printf("\n%c", caracter);
    }
    fclose(p);

    printf("\n\nVoce deseja continuar a execucao(s/n)? ");
    scanf(" %c", &exec);

        }
    while (exec=='s');
        }
#endif // ex1

#ifdef ex2
/*Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
    dados. Utilize um vetor de estrutura de 4 elementos como variavel LOCAL na
    funcao main(). Utilize ponteiros para passar o vetor de estrutura para
    as funcoes. Sempre que o programa for encerrado, os contatos devem ser
    escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
    do arquivo.
    O programa deve ter as seguintes opcoes:(cada opcao do menu e' um funcao)
    1 - inserir contato
    2 - listar todos os contatos
    3 - pesquisar um contato pelo nome
    4 - listar os contatos cujo nome inicia com uma letra digitada
    5 - imprimir os aniversariantes do mês.
    6 - altera contato
    7 - exclui contato
    8 - saida*/

struct var
    {
    char nome[20];
    char tel[13];
    char aniver[6];
    };

    char procura[20];

RecebeDados(struct var *p)
{
    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo2.txt", "w");

    for (int i=0; i<4; i++)
    {
    fflush(stdin);
    printf("\nInsira dados de 4 pessoas diferentes abaixo: \n\n");
    printf("Nome: ");
    scanf("%s", &(p+i)->nome[0]);
    fflush(stdin);
    printf("Telefone: ");
    scanf("%s", &(p+i)->tel[0]);
    fflush(stdin);
    printf("Aniversario no formato dd/mm: " );
    scanf("%s", &(p+i)->aniver[0]);

    fwrite(p+i, sizeof(*p), 1, dadosarquivo);
    }

    fclose(dadosarquivo);
}

ImprimeDados(struct var *p)
{
    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo2.txt", "r");

    if(dadosarquivo == NULL)
    {
        printf("O arquivo ainda nao contem nenhum dado. Insira na entrada de dados\n");
        return 0;
    }

    for (int i=0; i<4; i++)
    {
    fread(p+i, sizeof(*p), 1, dadosarquivo);

    printf("\nDados %i: ", i+1);
    printf("\nNome: %s", (p+i) -> nome);
    printf("\nTelefone: %s", (p+i) -> tel);
    printf("\nAniversario: %s\n", (p+i) -> aniver);
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

int ComparaInicial(char *c1, char *c2)
{
        if (c1[0] != c2[0])
        {
            return 0;
        }

    return 1;
}

int ComparaAniver(char *c1, char *c2)
{
        if (c1[3] == c2[0] && c1[4] == c2[1])
        {
            return 1;
        }
        return 0;
}

ProcuraDados(struct var *p)
{
    printf("\nPesquise o nome para buscar os dados: \n");
    fflush(stdin);
    gets(procura);

    if(ComparaDados((p+0)->nome, procura))
    {
        printf ("\nDADOS BUSCADOS: \n\nNome: %s \nTelefone: %s \nAniversario: %s", (p+0)->nome, (p+0)->tel, (p+0)->aniver);
    }
    else
     if(ComparaDados((p+1)->nome, procura))
    {
        printf ("\\nDADOS BUSCADOS: \n\Nome: %s \nTelefone: %s \nAniversario: %s", (p+1)->nome, (p+1)->tel, (p+1)->aniver);
    }
    else
    if(ComparaDados((p+2)->nome, procura))
    {
        printf ("\nDADOS BUSCADOS: \n\Nome: %s \nTelefone: %s \nAniversario: %s", (p+2)->nome, (p+2)->tel, (p+2)->aniver);
    }
    else
    if(ComparaDados((p+3)->nome, procura))
    {
        printf ("\nDADOS BUSCADOS: \n\Nome: %s \nTelefone: %s \nAniversario: %s", (p+3)->nome, (p+3)->tel, (p+3)->aniver);
    }
    else
    {
        printf ("\nDADOS NAO ENCONTRADOS, tente novamente.\n");
    }
}

ListaLetra(struct var *p)
{
    printf("\nPesquise a letra inicial para buscar dados: \n");
    fflush(stdin);
    gets(procura);

    if(ComparaInicial((p+0)->nome, procura))
    {
        printf ("\nDADOS BUSCADOS: \n\Nome: %s \nTelefone: %s \nAniversario: %s", (p+0)->nome, (p+0)->tel, (p+0)->aniver);
    }
    if(ComparaInicial((p+1)->nome, procura))
    {
        printf ("\nDADOS BUSCADOS: \n\Nome: %s \nTelefone: %s \nAniversario: %s", (p+1)->nome, (p+1)->tel, (p+1)->aniver);
    }
    if(ComparaInicial((p+2)->nome, procura))
    {
        printf ("\nDADOS BUSCADOS: \n\Nome: %s \nTelefone: %s \nAniversario: %s", (p+2)->nome, (p+2)->tel, (p+2)->aniver);
    }
    if(ComparaInicial((p+3)->nome, procura))
    {
        printf ("\nDADOS BUSCADOS: \n\Nome: %s \nTelefone: %s \nAniversario: %s", (p+3)->nome, (p+3)->tel, (p+3)->aniver);
    }
    else
    if(ComparaInicial((p+0)->nome, procura) == 0 && ComparaInicial((p+1)->nome, procura) == 0 && ComparaInicial((p+2)->nome, procura) == 0 && ComparaInicial((p+3)->nome, procura) == 0)
    {
        printf ("\nDADOS NAO ENCONTRADOS, tente novamente.\n");
    }
}

Aniversariante(struct var *p)
{
    printf("\nPesquise o mes para buscar os aniversariantes: \n");
    fflush(stdin);
    gets(procura);

    if(ComparaAniver((p+0)->aniver, procura))
    {
        printf ("\nANIVERSARIANTE: \n\Nome: %s \nTelefone: %s \nAniversario: %s", (p+0)->nome, (p+0)->tel, (p+0)->aniver);
    }
    if(ComparaAniver((p+1)->aniver, procura))
    {
        printf ("\nANIVERSARIANTE: \n\Nome: %s \nTelefone: %s \nAniversario: %s", (p+1)->nome, (p+1)->tel, (p+1)->aniver);
    }
    if(ComparaAniver((p+2)->aniver, procura))
    {
        printf ("\nANIVERSARIANTE: \n\Nome: %s \nTelefone: %s \nAniversario: %s", (p+2)->nome, (p+2)->tel, (p+2)->aniver);
    }
    if(ComparaAniver((p+3)->aniver, procura))
    {
        printf ("\nANIVERSARIANTE: \n\Nome: %s \nTelefone: %s \nAniversario: %s", (p+3)->nome, (p+3)->tel, (p+3)->aniver);
    }
    else
    if(ComparaAniver((p+0)->aniver, procura) == 0 && ComparaAniver((p+1)->aniver, procura) == 0 && ComparaAniver((p+2)->aniver, procura) == 0 && ComparaAniver((p+3)->aniver, procura) == 0)
    {
        printf ("\nDADOS NAO ENCONTRADOS, tente novamente.\n");
    }
}

AlteraDados(struct var *p)
{
    printf("\nPesquise o nome para alterar dados: \n");
    fflush(stdin);
    gets(procura);


    if(ComparaDados((p+0)->nome, procura))
    {
    printf("\nDigite novos dados: \n");
    printf("Nome: ");
    scanf("%s", &(p+0)->nome[0]);
    fflush(stdin);
    printf("Telefone: ");
    scanf("%s", &(p+0)->tel[0]);
    fflush(stdin);
    printf("Aniversario: ");
    scanf("%s", &(p+0)->aniver[0]);
    }
    else
     if(ComparaDados((p+1)->nome, procura))
    {
    printf("\nDigite novos dados: \n");
    printf("nNome: ");
    scanf("%s", &(p+1)->nome[0]);
    fflush(stdin);
    printf("Telefone: ");
    scanf("%s", &(p+1)->tel[0]);
    fflush(stdin);
    printf("Aniversario: ");
    scanf("%s", &(p+1)->aniver[0]);
    }
    else
    if(ComparaDados((p+2)->nome, procura))
    {
    printf("\nDigite novos dados: \n");
    printf("Nome: ");
    scanf("%s", &(p+2)->nome[0]);
    fflush(stdin);
    printf("Telefone: ");
    scanf("%s", &(p+2)->tel[0]);
    fflush(stdin);
    printf("Aniversario: ");
    scanf("%s", &(p+2)->aniver[0]);
    }
    else
    if(ComparaDados((p+3)->nome, procura))
    {
    printf("\nDigite novos dados: \n");
    printf("Nome: ");
    scanf("%s", &(p+3)->nome[0]);
    fflush(stdin);
    printf("Telefone: ");
    scanf("%s", &(p+3)->tel[0]);
    fflush(stdin);
    printf("Aniversario: ");
    scanf("%s", &(p+3)->aniver[0]);
    }
    else
    {
        printf ("\nDADOS NAO ENCONTRADOS, tente novamente.\n");
    }

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo2.txt", "w");

    if(dadosarquivo == NULL)
    {
        printf("O arquivo nao existe.\n");
        return 0;
    }
    fwrite(p+0, sizeof(*p), 1, dadosarquivo);
    fwrite(p+1, sizeof(*p), 1, dadosarquivo);
    fwrite(p+2, sizeof(*p), 1, dadosarquivo);
    fwrite(p+3, sizeof(*p), 1, dadosarquivo);
    fclose(dadosarquivo);

}

ExcluiDados(struct var *p)
{
    printf("\nPesquise o nome para excluir dados: \n");
    fflush(stdin);
    gets(procura);

if(ComparaDados((p+0)->nome, procura))
    {
        (p+0)->nome[0] = '*';
        (p+0)->nome[1] = '\0';
        (p+0)->tel[0] = '*';
        (p+0)->tel[1] = '\0';
        (p+0)->aniver[0] = '*';
        (p+0)->aniver[1] = '\0';

        printf("\nDados excluidos.\n");
    }
    else
     if(ComparaDados((p+1)->nome, procura))
    {
        (p+1)->nome[0] = '*';
        (p+1)->nome[1] = '\0';
        (p+1)->tel[0] = '*';
        (p+1)->tel[1] = '\0';
        (p+1)->aniver[0] = '*';
        (p+1)->aniver[1] = '\0';

        printf("\nDados excluidos.\n");
    }
    else
    if(ComparaDados((p+2)->nome, procura))
    {
        (p+2)->nome[0] = '*';
        (p+2)->nome[1] = '\0';
        (p+2)->tel[0] = '*';
        (p+2)->tel[1] = '\0';
        (p+2)->aniver[0] = '*';
        (p+2)->aniver[1] = '\0';

        printf("\nDados excluidos.\n");
    }
    else
    if(ComparaDados((p+3)->nome, procura))
    {
        (p+3)->nome[0] = '*';
        (p+3)->nome[1] = '\0';
        (p+3)->tel[0] = '*';
        (p+3)->tel[1] = '\0';
        (p+3)->aniver[0] = '*';
        (p+3)->aniver[1] = '\0';

        printf("\nDados excluidos.\n");
    }
    else
    {
        printf ("\nDADOS NAO ENCONTRADOS, tente novamente.\n");
    }

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo2.txt", "w");

    if(dadosarquivo == NULL)
    {
        printf("O arquivo nao existe.\n");
        return 0;
    }
    fwrite(p+0, sizeof(*p), 1, dadosarquivo);
    fwrite(p+1, sizeof(*p), 1, dadosarquivo);
    fwrite(p+2, sizeof(*p), 1, dadosarquivo);
    fwrite(p+3, sizeof(*p), 1, dadosarquivo);
    fclose(dadosarquivo);
}

main()
{
    char opcao;


    struct var dados[4];
    struct var *p;

    p = &dados[0];

   do
    {
    printf("\n\n[1] Entrada de contatos\n");
    printf("[2] Exibir contatos\n");
    printf("[3] Procurar contatos\n");
    printf("[4] Listar contatos com a letra: \n");
    printf("[5] Buscar aniversariantes do mes: \n");
    printf("[6] Alterar contatos\n");
    printf("[7] Excluir contatos\n");
    printf("[8] Sair\n\n");
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
            ListaLetra(p);
        }
        else
        if(opcao == '5')
        {
            Aniversariante(p);
        }
        else
        if(opcao == '6')
        {
            AlteraDados(p);
        }
        else
        if(opcao == '7')
        {
            ExcluiDados(p);
        }
        else
        if(opcao == '8')
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
/*Escreva um programa para o controle de mercadorias em uma dispensa
    domestica. Para cada produto sera' armazenado um codigo numerico, nome
    do produto e quantidade atual numa estrutura de dados. A unica estrutura
    de dados deve ser declarada como variavel LOCAL na funcao main(). Escreva
    os itens das mercadorias direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui produtos
    2 - listar todos os produtos
    3 - pesquisar uma mercadoria pela descrição
    4 - listar os produtos não disponíveis.
    5 - alterar a quantidade atual
    6 - altera produtos
    7 - exclui produtos
    8 - saida*/

struct var
    {
    char nome[20];
    int id;
    int qtd;
    };

    char procura[20];

RecebeDados(struct var *p)
{   int op;

    do
    {
    printf("\nCadastre os dados do produto desejado: \n\n");
    printf("Codigo id: ");
    scanf("%d", &p->id);
    fflush(stdin);
    printf("Nome: ");
    scanf("%s", &p->nome[0]);
    printf("Quantidade: ");
    scanf("%d", &p->qtd);

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo3.txt", "a");
    fwrite(p, sizeof(*p), 1, dadosarquivo);
    fclose(dadosarquivo);

    printf("\nVoce deseja continuar cadastrando produtos?\nDigite '1' para sim ou qualquer numero para parar: \n");
    scanf("%d", &op);
    }
    while (op == 1);
}

ImprimeDados(struct var *p)
{   int i, cont = 0;
    for (i = 0; (ImprimeProd(p, i)) != 0; i++)
    {
        if (p->nome[0] != '*')
    {
        printf("\nProduto: " );
        printf("\nCodigo id: %d", (p) -> id);
        printf("\nNome: %s", (p) -> nome);
        printf("\nQuantidade: %d\n", (p) -> qtd);
        cont++;
    }

    }
    if(cont == 0)
    {
    printf("\nNao ha produtos cadastrados.");
    }
}

int ImprimeProd(struct var *p, int i)
{
    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo3.txt", "r");

    if(dadosarquivo == NULL)
        {
        printf("\nO arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }
    else
        {
        fseek(dadosarquivo, i*sizeof(*p), 0);
        int bytes = fread(p, sizeof(*p), 1, dadosarquivo);
        fclose(dadosarquivo);

        return bytes;
        }
}

int ComparaDados(char *c1, char *c2)
{
    for (int i = 0; c1[i] != '\0' || c2[i] != '\0'; i++)
    {
        if (c1[i] != c2[i])
        {
            return 0;
        }
    }
    return 1;
}

int PesquisaDados(struct var *p)
{
    char procura[20];
    int bytes, i, cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo3.txt", "r");

    if(dadosarquivo == NULL)
        {
        printf("\nO arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome do produto para buscar os dados: \n");
    fflush(stdin);
    gets(procura);

        for (i = 0; (ImprimeProd(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->nome))
            {
            printf("\nProduto buscado: " );
            printf("\nCodigo id: %d", (p) -> id);
            printf("\nNome: %s", (p) -> nome);
            printf("\nQuantidade: %d\n", (p) -> qtd);
             cont++;
            }
        }

        if(cont == 0)
            {
            printf("\nNao foi possivel encontrar nenhum registro correspondente." );
            }

        fclose(dadosarquivo);
}

ListaIndisp(struct var *p)
{   int cont = 0;
    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo3.txt", "r");

    if(dadosarquivo == NULL)
        {
        printf("\nO arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }

        printf("\nProdutos indisponiveis: \n");

         for (int i = 0; (ImprimeProd(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(p->qtd == 0 && p->nome[0] != '*')
            {
            printf("\nCodigo id: %d", (p) -> id);
            printf("\nNome: %s", (p) -> nome);
            printf("\nQuantidade: %d\n", (p) -> qtd);
            cont++;
            }
        }

        if(cont == 0)
            {
            printf("\nNao foram encontrados produtos indisponiveis." );
            }
        fclose(dadosarquivo);
}

AlteraQtd(struct var *p)
{   char procura[20];
    int cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo3.txt", "r+");

    if(dadosarquivo == NULL)
        {
        printf("\nO arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome do produto para buscar os dados: \n");
    fflush(stdin);
    gets(procura);

        for (int i = 0; (ImprimeProd(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->nome))
            {
            printf("Nova quantidade: ");
            scanf("%d", &p->qtd);
            cont++;
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fwrite(p, sizeof(*p), 1, dadosarquivo);
            }
        }

            fclose(dadosarquivo);

        if(cont == 0)
            {
            printf("\nNao foi possivel encontrar nenhum registro correspondente." );
            }

}

AlteraDados(struct var *p)
{
    char procura[20];
    int cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo3.txt", "r+");

    if(dadosarquivo == NULL)
        {
        printf("\nO arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome para buscar dados: \n");
    fflush(stdin);
    gets(procura);

        for (int i = 0; (ImprimeProd(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->nome))
            {
            printf("\nAltere o produto selecionado: \n\n");
            printf("Novo codigo id: ");
            scanf("%d", &p->id);
            fflush(stdin);
            printf("Novo nome: ");
            scanf("%s", &p->nome[0]);
            printf("Nova quantidade: ");
            scanf("%d", &p->qtd);
            cont++;
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fwrite(p, sizeof(*p), 1, dadosarquivo);
            }
        }


            fclose(dadosarquivo);

        if(cont == 0)
            {
            printf("\nNao foi possivel encontrar nenhum registro correspondente." );
            }

}

ExcluiDados(struct var *p)
{
    char procura[20];
    int cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo3.txt", "r+");

    if(dadosarquivo == NULL)
        {
        printf("\nO arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome do produto para excluir os dados: \n");
    fflush(stdin);
    gets(procura);

        for (int i = 0; (ImprimeProd(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->nome))
            {
            p->id = 0;
            p->nome[0] = '*';
            p->qtd = 0;

            printf("\nO produto foi excluido com sucesso.");
            cont++;
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fwrite(p, sizeof(*p), 1, dadosarquivo);
            }
        }


            fclose(dadosarquivo);

        if(cont == 0)
            {
            printf("\nNao foi possivel encontrar nenhum registro correspondente." );
            }

}

main()
{
    char opcao;

    struct var dados;
    struct var *p;

    p = &dados;

   do
    {
    printf("\n\n[1] Incluir produtos\n");
    printf("[2] Listar todos os produtos\n");
    printf("[3] Pesquisar mercadoria\n");
    printf("[4] Listar indisponiveis\n");
    printf("[5] Alterar quantidade de um produto\n");
    printf("[6] Alterar produto\n");
    printf("[7] Excluir produto\n");
    printf("[8] Sair\n\n");
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
            PesquisaDados(p);
        }
        else
        if(opcao == '4')
        {
            ListaIndisp(p);
        }
        else
        if(opcao == '5')
        {
            AlteraQtd(p);
        }
        else
        if(opcao == '6')
        {
            AlteraDados(p);
        }
        else
        if(opcao == '7')
        {
            ExcluiDados(p);
        }
        else
        if(opcao == '8')
        {
        printf("\nPrograma encerrado.\n");
        exit(0);
        }
        else
        {
            printf("\nOpcao invalida.\n");
        }
    }
        while (opcao!= '1' || opcao!= '2' || opcao!= '3');
}
#endif // ex3

#ifdef ex4
/*Escreva um programa para controle de um cadastro de clientes. Para cada
    registro sera' armazenado nome, email e celular numa estrutura de dados.
    A unica estrutura de dados e' uma variavel LOCAL na funcao main().
    Escreva os registros direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros para
    passar parametros para as funcoes.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui registros
    2 - listar todos os registros
    3 - pesquisar registro pelo nome
    4 - altera registro
    5 - exclui registro
    6 - saida*/

struct var
    {
    char nome[20];
    char email[20];
    char cel[15];
    };

    char procura[20];

RecebeDados(struct var *p)
{   int op;

    do
    {
    printf("\nCadastre os dados da pessoa desejada: \n");
    printf("Nome: ");
    scanf("%s", &p->nome[0]);
    fflush(stdin);
    printf("Email: ");
    scanf("%s", &p->email[0]);
    printf("Celular: ");
    scanf("%s", &p->cel[0]);

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo4.txt", "a");
    fwrite(p, sizeof(*p), 1, dadosarquivo);
    fclose(dadosarquivo);

    printf("\nVoce deseja continuar cadastrando novos dados?\nDigite '1' para sim ou qualquer numero para parar: \n");
    scanf("%d", &op);
    }
    while (op == 1);
}

ImprimeDados(struct var *p)
{   int i, cont = 0;
    for (i = 0; (ImprimeInfo(p, i)) != 0; i++)
    {
        if (p->nome[0] != '*')
    {
        printf("\nDados: " );
        printf("\nNome: %s", (p) -> nome);
        printf("\nEmail: %s", (p) -> email);
        printf("\nCelular: %s\n", (p) -> cel);
        cont++;
    }

    }
    if(cont == 0)
    {
    printf("\nNao ha dados cadastrados.");
    }
}

int ImprimeInfo(struct var *p, int i)
{
    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo4.txt", "r");

    if(dadosarquivo == NULL)
        {
        printf("\nO arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }
    else
        {
        fseek(dadosarquivo, i*sizeof(*p), 0);
        int bytes = fread(p, sizeof(*p), 1, dadosarquivo);
        fclose(dadosarquivo);

        return bytes;
        }
}

int ComparaDados(char *c1, char *c2)
{
    for (int i = 0; c1[i] != '\0' || c2[i] != '\0'; i++)
    {
        if (c1[i] != c2[i])
        {
            return 0;
        }
    }
    return 1;
}

int PesquisaDados(struct var *p)
{
    char procura[20];
    int bytes, i, cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo4.txt", "r");

    if(dadosarquivo == NULL)
        {
        printf("O arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome que deseja buscar os dados: \n");
    fflush(stdin);
    gets(procura);

        for (i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->nome))
            {
            printf("\nInformacoes buscadas: " );
            printf("\nNome: %s", (p) -> nome);
            printf("\nEmail: %s", (p) -> email);
            printf("\nCelular: %s\n", (p) -> cel);
             cont++;
            }
        }

        if(cont == 0)
            {
            printf("\nNao foi possivel encontrar nenhum registro correspondente." );
            }

        fclose(dadosarquivo);
}


AlteraDados(struct var *p)
{
    char procura[20];
    int cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo4.txt", "r+");

    if(dadosarquivo == NULL)
        {
        printf("O arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome desejado para buscar os dados: \n");
    fflush(stdin);
    gets(procura);

        for (int i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->nome))
            {
            printf("\nAltere as seguintes informacoes: \n\n");
            printf("Novo nome: ");
            scanf("%s", &p->nome[0]);
            fflush(stdin);
            printf("Novo email: ");
            scanf("%s", &p->email[0]);
            printf("Novo celular: ");
            scanf("%s", &p->cel[0]);
            cont++;
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fwrite(p, sizeof(*p), 1, dadosarquivo);
            }
        }
            fclose(dadosarquivo);

        if(cont == 0)
        {
        printf("\nNao foi possivel encontrar nenhum registro correspondente." );
        }
}

ExcluiDados(struct var *p)
{
    char procura[20];
    int cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivo4.txt", "r+");

    if(dadosarquivo == NULL)
        {
        printf("\nO arquivo ainda nao contem nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome desejado para excluir os dados: \n");
    fflush(stdin);
    gets(procura);

        for (int i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->nome))
            {
            p->nome[0] = '*';
            p->email[0] = '*';
            p->cel[0] = '*';

            printf("\nOs dados foram excluidos com sucesso.");
            cont++;
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fwrite(p, sizeof(*p), 1, dadosarquivo);
            }
        }
            fclose(dadosarquivo);

        if(cont == 0)
        {
        printf("\nNao foi possivel encontrar nenhum registro correspondente." );
        }
}

main()
{
    char opcao;

    struct var dados;
    struct var *p;

    p = &dados;

   do
    {
    printf("\n\n[1] Incluir dados\n");
    printf("[2] Listar todos os dados\n");
    printf("[3] Pesquisar dados pelo nome\n");
    printf("[4] Alterar dados\n");
    printf("[5] Excluir dados\n");
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
            PesquisaDados(p);
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
#endif // ex4
