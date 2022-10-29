#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int populacaoinicial = 0;
    int populacaofinal = 0;
    int populacaoatual = 0;
    int anos = 0;

    // Pergunta ao usuário a pop inicial maior ou igual a 9
    do
    {
        populacaoinicial = get_int("População Inicial: ");
    }
    while (populacaoinicial < 9);

    // Pergunta ao usuário a pop final que seja maior ou igual a pop inicial
    do
    {
        populacaofinal = get_int("População Final: ");
    }
    while (populacaofinal < populacaoinicial);

    // Calculando os anos
    populacaoatual = populacaoinicial;
    while (populacaoatual < populacaofinal)
    {
        // Calculo dos nascimentos e falências, atualizando a população
        int nascem = populacaoatual / 3;
        int morrem = populacaoatual / 4;
        populacaoatual = populacaoatual + nascem - morrem;
        anos++;
    }

    // Imprimindo o resultado final
    printf("Years: %i\n", anos);
}