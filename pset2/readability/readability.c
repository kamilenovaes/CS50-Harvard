#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{

    // Pedindo o copy/paste do texto do usuário
    string texto = get_string("Text: ");

    int tamanho = strlen(texto);
    int letras = 0;
    int palavras = 1;
    int frases = 0;

    // Loop para percorrer todo o array
    for (int i = 0; i < tamanho; i++)
    {
        // Contar as letras (função do ctype)
        if (isalpha(texto[i]))
        {
            letras++;
        }
        // Contar os espaços (função do ctype), espaços + 1 = palavras
        else if (isspace(texto[i]))
        {
            palavras++;
        }
        // Contar os pontos finais para contar as frases
        else if (texto[i] == '.' || texto[i] == '?' || texto[i] == '!')
        {
            frases++;
        }
    }

    // Utilizando a formula de Coleman (índice = 0,0588 * L - 0,296 * S - 15,8)
    // L é o número médio de letras por 100 palavras no texto
    // S é o número médio de sentenças por 100 palavras no texto
    float L = ((float) letras / palavras) * 100;
    float S = ((float) frases / palavras) * 100;
    float indice = 0.0588 * L - 0.296 * S - 15.8;

    // Função lround() da biblioteca math.h para arredondar o número para o inteiro mais próximo
    int grade = lround(indice);

    if (grade < 1)
    {
        printf("Before Grade 1");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i", grade);
    }

    printf("\n");

}