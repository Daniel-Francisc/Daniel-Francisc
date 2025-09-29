#include <stdio.h>
#include <stdlib.h>

void *transform(char vetor_n[], int r)
{
    int *vetor_ascv = (int *)malloc(r * sizeof(int));

    if (vetor_ascv == NULL)
    {
        return NULL;
    };

    for (int i = 0; i < r; i++)
    {
        // int a = ("%d", vetor_n[i]);
        vetor_ascv[i] = ("%d", vetor_n[i]);
        // printf("%c :letra - %d ASCII;\n", vetor_ascv[i], vetor_ascv[i]);
    }
    // return vetor_ascv[];
    return (void *)vetor_ascv;
}

void heap_fica(int v[], int i, int qtde)
{
    int f_esq, f_dir, maior, aux;

    maior = i;
    f_esq = 2 * i + 1;
    f_dir = 2 * i + 2;
    if (f_esq < qtde && v[f_esq] > v[maior])
        maior = f_esq;
    if (f_dir < qtde && v[f_dir] > v[maior])
        maior = f_dir;
    if (maior != i)
    {
        aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        heap_fica(v, maior, qtde);
    }
}

void transforma_heap(int v[], int qtde)
{
    int i;
    for (i = qtde / 2 - 1; i >= 0; i--)
    {
        heap_fica(v, i, qtde);
    }
}

void ordena(int v[], int qtde)
{
    int i, aux;
    for (i = qtde - 1; i >= 1; i--)
    {
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        heap_fica(v, 0, i);
    }
}

int main()
{
    char a[] = "over flow";
    int tamanho = 9; // 'O', 'v', 'e', 'r', ' ', 'F', 'l', 'o', 'w' (9 caracteres)

    // 1. CRIA O VETOR ASCII (Aloca memória na HEAP)
    int *vetor_ascii = (int *)transform(a, tamanho);

    if (vetor_ascii == NULL)
    {
        printf("Erro ao criar vetor ASCII.\n");
        return 1;
    }

    printf("--- Vetor ASCII Original ---\n");
    // Imprime o vetor antes da ordenação
    for (int i = 0; i < tamanho; i++)
    {
        printf("|%d == %c| ", vetor_ascii[i], vetor_ascii[i]);
    }
    printf("\n");

    // 2. CONSTRÓI O HEAP MÁXIMO
    transforma_heap(vetor_ascii, tamanho);

    // 3. ORDENA O VETOR
    ordena(vetor_ascii, tamanho);

    printf("--- Vetor ASCII ORDENADO ---\n");
    // Imprime o vetor após a ordenação (agora em ordem crescente)
    for (int i = 0; i < tamanho; i++)
    {
        printf("| %d == %c |", vetor_ascii[i], vetor_ascii[i]);
    }
    printf("\n");

    // CRUCIAL: Liberar a memória alocada
    free(vetor_ascii);

        return 0;
}