#include <stdio.h>

// método principal
void main(){
    int a = 43;
    
    printf("Valor de a: %d\n", a);
    printf("Endereço de a: %p\n", &a); 
        
    int *pa; // ponteiro para um inteiro
    pa = &a;

    printf("Valor de p: %p\n", pa);
    printf("Endereço de p: %p\n", &pa);
    printf("Valor no endereço de memória apontado por p: %d\n", *pa);
}