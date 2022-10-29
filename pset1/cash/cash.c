#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float reais;
    int moedas = 0;

    // Pergunta um valor positivo do troco
    do
    {
        reais = get_float("Troco: ");
    }
    while (reais < 0);

    // Transforma os reais em um numero inteiro
    int cents = round(reais * 100);

    // Loop para subtrair os valores enquanto conta as moedas
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents = cents - 25;
            moedas++;
        }
        if (cents >= 10 && cents < 25)
        {
            cents = cents - 10;
            moedas++;
        }
        if (cents >= 5 && cents < 10)
        {
            cents = cents - 5;
            moedas++;
        }
        if (cents < 5 && cents != 0)
        {
            cents = cents - 1;
            moedas++;
        }
    }

    printf("%i\n", moedas);

}
