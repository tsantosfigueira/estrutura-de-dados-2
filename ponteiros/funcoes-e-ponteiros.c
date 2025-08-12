#include <stdio.h>

const int MAX = 3; // declaração de constante 

void dobraVetor(int a[MAX]){
    for (int i = 0; i < MAX; i++)
    {
        a[i] *= 2;
    }
}

void main(){
    int a[] = {2, 4, 6};

    dobraVetor(a);

    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", a[i]); // o vetor foi modificado dentro da função
    }
    printf("\n"); 
}  