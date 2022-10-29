#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Pegar a key como argumento e verificar se realmente é um numero
    int k = 0;

    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    else
    {
        k = atoi(argv[1]);
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (k <= 0 || (!isdigit(argv[1][i])))
            {
                printf("Usage: ./caesar key \n");
                return 1;
            }
        }
    }

    // Pedir a string pro usuário
    string s = get_string("plaintext: ");
    printf("ciphertext: ");

    // Loop para percorrer o array
    // Usar a função isalpha() pra verificar se é uma letra
    // Fórmula para loop da criptografia (Ci = (Pi + K) % 26)
    // Ci = caractere criptografado, Pi = caractere a criptografar, K = key, %26 = resto para retornar
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            // Letras minúsculas
            int ci = ((((s[i]) - 97) + k) % 26) + 97;
            // Letras maiúsculas
            int ce = ((((s[i]) - 65) + k) % 26) + 65;

            if (islower(s[i]))
            {
                printf("%c", ci);
            }
            if (isupper(s[i]))
            {
                printf("%c", ce);
            }
        }
        else
        {
            printf("%c", s[i]);
        }
    }

    printf("\n");

}