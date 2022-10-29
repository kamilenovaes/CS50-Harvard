#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;

    // Pergunta ao usuario o tamanho da piramide que seja apenas entre 1 e 8
    do
    {
        n = get_int("Tamanho: ");
    }
    while (n < 1 || n > 8);

    // Loop para formar as n linhas
    for (int i = 0; i < n; i++)
    {
        // Imprime o vazio. É como se precisássemos decrementar o j a cada linha
        for (int j = 0; j < (n - i - 1); j++)
        {
            printf(" ");
        }
        // Imprime o #, como se precisássemos incrementar o k a cada linha
        for (int k = 0; k < (i + 1); k++)
        {
            printf("#");
        }

        printf("\n");
    }
}