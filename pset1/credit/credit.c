#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long cartaocredito;
    int cont = 0;
    int soma = 0;
    long divisor = 10;

    // Pedindo ao usuário um número positivo
    do
    {
        cartaocredito = get_long("Número do cartão: ");
    }
    while (cartaocredito < 0);

    /* Necessário usar sempre essa variável auxiliar igual ao número do cartão pois ela vai sendo reutilizada
    e alterada ao longo do código. */
    long cc = cartaocredito;

    // Contador de dígitos
    while (cc != 0)
    {
        cc = cc / 10;
        cont++;
    }

    // Primeiro caso: somar os dígitos que não precisam ser multiplicados por 2
    cc = cartaocredito;
    while (cc > 0)
    {
        int ultimodigito = cc % 10;
        soma = soma + ultimodigito;
        cc = cc / 100;
    }

    // Segundo caso: multiplicar os dígitos necessários por 2, e somar
    cc = cartaocredito / 10;
    while (cc > 0)
    {
        int ultimodigito = cc % 10;
        int digitox2 = ultimodigito * 2;
        // Soma de dígitos e não de valores, caso seja > 9
        soma = soma + (digitox2 % 10) + (digitox2 / 10);
        cc = cc / 100;
    }

    // Divisor para pegar os dígitos iniciais do cartao e fazer a comparação das bandeiras
    for (int i = 0; i < cont - 2; i++)
    {
        divisor = divisor * 10;
    }

    int primeirodigito = cartaocredito / divisor;
    int primeirosdoisdigitos = cartaocredito / (divisor / 10);

    // Checando tudo e imprimindo o resultado
    if (soma % 10 == 0)
    {
        if (primeirodigito == 4 && (cont == 13 || cont == 16))
        {
            printf("VISA\n");
        }
        else if ((primeirosdoisdigitos == 34 || primeirosdoisdigitos == 37) && cont == 15)
        {
            printf("AMEX\n");
        }
        else if ((primeirosdoisdigitos > 50 && primeirosdoisdigitos < 56) && cont == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}