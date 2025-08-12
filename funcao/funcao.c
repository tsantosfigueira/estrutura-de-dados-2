#include <stdio.h>

void naoTroca(int a, int b){
    int aux = a;
    a = b;
    b = aux;
}

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void main(){
    int a = 7, b = 5, c;
    naoTroca(a, b);
    printf("%d %d\n", a, b);

    troca(&a, &b);
    printf("%d %d\n", a, b);
}