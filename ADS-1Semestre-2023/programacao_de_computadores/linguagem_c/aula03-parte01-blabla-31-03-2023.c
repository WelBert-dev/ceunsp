#include <stdio.h> // implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
#include <stdlib.h> // implicit declaration of function ‘system’ [-Wimplicit-function-declaration]
#include <math.h> // implicit declaration of function ‘sin’ [-Wimplicit-function-declaration]

// standard = padrão

/* Modificadores de Tipo em c (Mais info: https://www.cprogressivo.net/2013/01/Modificadores-do-tipo-inteiro-int-em-C--short-long-signed-unsigned.html)
    - Maior valor possível de armazenar em um int: 
    01111111111111111111111111111111 = 231 – 1 = 2147483647
    - O primeiro bit representa o sinal

    - A linguagem C define alguns modificadores de tipo. Alguns deles são:
    short, long, unsigned.
    
        short: Instrui o compilador a representar valores inteiros usando 16 bits.
            obs: Logo, uma variável short int pode armazenar valores inteiros no 
            intervalo: –215 a 215 – 1.

        long: 64bits (8bytes)

        unsigned: Sempre deve ser positivo; 

    - Ao tipo float não se aplica nenhum dos modificadores, ao tipo double
    aplica-se apenas o modificador long e ao tipo char aplica-se somente
    o tipo unsigned.

*/ 

/* Limites de Armazenamento:

    short int: 16bits (2bytes)
    int: 32bits (4bytes)
    long int: 64bits (8bytes)

    float: 16bits (2btes)
    double: 32bits (4bytes)
    long double: 64bits (8bytes)

    char: 8bits (–2^7 a 2^7 – 1) 
        com unsigned como deleta a capacidade de armazenar negativos logo dobramos
        a capacidade: `unsigned char`: 2^8 – 1

*/

/* Ordem de precedência dos operadores aritméticos:

    1o - Parênteses;
    2o - Expoentes;
    3o - Multiplicações e divisões; (da esquerda para a direita);
    4o - Somas e subtrações. (da esquerda para a direita);

*/

// A conversão cast é a mesma do Java `(int)`

int main (int args, char *argv[]) {
    int x;
    short int y;
    char a;
    unsigned char b;

    x = pow(2, 31)-1;
    y = pow(2, 15)-1;
    printf("x = %d y = %d\n",x,y);
    x ++;
    y ++;
    printf("x = %d y = %d\n",x,y);

    a = pow(2, 7)-1;
    b = pow(2, 8)-1;
    printf("a = %d b = %d\n",a,b);

    // Representando valores float no printf:

    printf("Pamonha float %8.3", 10.1);
    // Assim, o tag %8.3f significa: “exibir um valor de ponto
    // flutuante com oito caracteres no total e com três casas decimais”.

    // %p é ponteiro ou seja o endereço de memória
    int valEmMemoria = 10;
    printf("Valor: %d | Endereço em memória: %p", valEmMemoria, &valEmMemoria);

    // Tipo de variável que armazena ponteiro:
    int ponteiro = &valEmMemoria;

    // Definindo uma variável do tipo pointer:
    int *ponteiroDefinition;

    system("PAUSE");

    return 0;
}