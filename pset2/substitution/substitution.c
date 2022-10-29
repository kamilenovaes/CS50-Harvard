#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Verificando se a chave é válida
    if (argc != 2)
    {
        // Se o argumento for diferente de 2, imprime o erro ao usuário
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        // Comprimento da chave tem que ser 26
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        // Loop para percorrer todo o array da chave
        for (int i = 0; i < 26; i++)
        {
            // Função para verificar se é uma letra
            if (!isalpha(argv[1][i]))
            {
                // A key deve ter somente letras
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }

            // Outro loop para ir comparando a letra atual com a próxima
            for (int j = i + 1; j < 26; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    // Não pode haver letras iguais
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }
    }

    // Pedir a string pro usuário
    string text = get_string("plaintext: ");
    printf("ciphertext: ");

    // Tamanho do texto do usuário
    int k = strlen(text);

    string s = text;
    string key = argv[1];

    for (int i = 0; i < k; i++)
    {
        // Substitui a letra pela correspondente a posição da key
        if (isalpha(s[i]))
        {
            if (islower(s[i]))
            {
                s[i] = tolower(key[s[i] - 'a']);
            }
            else if (isupper(s[i]))
            {
                s[i] = toupper(key[s[i] - 'A']);
            }
        }
        else
        {
            // Se não for letra, imprime normal
            s[i] = text[i];
        }
    }

    printf("%s\n", s);

}