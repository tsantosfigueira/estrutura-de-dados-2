#include <stdio.h>

// exemplo de passagem de parâmetro por valor
// as variáveis 'a' e 'b' existem somente no escopo local
void naoTroca(int a, int b){
    int aux = a;
    a = b;
    b = aux;
}

// modificação de variável com ponteiro
// exemplo de passagem de parâmetro por referência
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