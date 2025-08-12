#include <stdio.h>

void main(){

    int myNumbers[4] = {25, 50, 75, 100};
    int i;

    // loop (iteração) sobre o vetor
    for (i = 0; i < 4; i++) {
        printf("%d\n", myNumbers[i]);
    }

    // endereço de memória de cada posição do array
    for (i = 0; i < 4; i++) {
        printf("%p\n", &myNumbers[i]);
    }

    // o tipo "int" geralmente tem tamanho de 4 bytes
    printf("%zu\n", sizeof(i));

    // o nome do array (vetor) é um ponteiro para seu primeiro elemento
    printf("%p\n", myNumbers);
    printf("%p\n", &myNumbers[0]);

    // isso quer dizer que podemos manipular arrays como ponteiros
    printf("%d\n", *myNumbers);

    // para acessar os demais elementos do array basta incrementar 
    // o valor do segundo elemento em myNumbers
    printf("%d\n", *(myNumbers + 1));

    // O valor do terceiro elemento em myNumbers
    printf("%d\n", *(myNumbers + 2));

}