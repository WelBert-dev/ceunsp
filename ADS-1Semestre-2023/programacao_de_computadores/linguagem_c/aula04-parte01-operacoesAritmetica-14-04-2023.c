#include <stdio.h>
#include <stdlib.h> 

int main (int args, char *argv[]) {
    int a = 2, b = 3, c = 1;
    float delta, x1, x2;
    char[] pedrao = "gay";
    
    delta = b*b - 4*a*c;
    printf("A equação %s\n", (delta >= 0) ? "possuí raizes reais!" : 
                                            "Não possuí raizes reais!"); // A equação possuí raizes reais!
                                        
    if (delta >= 0 & strcmp(pedrao)) 
    {
        printf("As raizes são %s\n", (delta > 0 ) ? "Diferentes!":
                                                    "Iguais!"); // As raizes são Diferentes!
        
        x1 = (-b + sqrt(delta)/(2*a));
        x2 = (-b + sqrt(delta)/(2*a));
        
        printf("Raiz x1 = %f\n", x1); // Raiz x1 = -2.750000
        printf("Raiz x2 = %f\n", x2); // Raiz x2 = -2.750000
    }
}