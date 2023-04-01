#include <stdio.h> // implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
#include <stdlib.h> // implicit declaration of function ‘system’ [-Wimplicit-function-declaration]
#include <math.h> // implicit declaration of function ‘sin’ [-Wimplicit-function-declaration]

// standard = padrão

/* Caracteres curingas do printf() 

    - %d: imprime um número inteiro (decimal). 10
    - %f: imprime um número em ponto flutuante (decimal). 10.0
    - %c: imprime um caractere. 
    - %s: imprime uma string de caracteres. - char[50]
    - %p: imprime um ponteiro.
    - %o: imprime um número inteiro em octal (base 8).
    - %x ou %X: imprime um número inteiro em hexadecimal (base 16).

    - Além disso, existem alguns caracteres curingas adicionais que podem ser usados para formatar a saída:

    - %e ou %E: imprime um número em notação científica.
    - %g ou %G: imprime um número em notação científica ou em ponto flutuante, dependendo da magnitude do número.
    - %u: imprime um número inteiro sem sinal.
    - %i: imprime um número inteiro (decimal), igual a %d.
    - %%: imprime um sinal de porcentagem literal.

    - Exemplos de implementação:

        int i = 42;
        float f = 3.14;
        char c = 'A';
        char s[] = "Hello, world!";
        printf("i = %d, f = %f, c = %c, s = %s\n", i, f, c, s);

        // saída: i = 42, f = 3.140000, c = A, s = Hello, world!

*/ 

int main (int args, char *argv[]) {
    float y; 
    y = sin(1.5);
    printf("y = %f", y); // y = 0.479426 (y = números)
    char s[] = "Hello, world!";
    printf("\n");
    system("PAUSE");
    return 0;
}