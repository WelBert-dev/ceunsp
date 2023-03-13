#include <stdio.h>

int main() {
    char nome[50];

    printf("Digite o seu nome: ");
    scanf("%s", nome);

    printf("Ola, %s!", nome);
    printf("\n");

    return 0;
}