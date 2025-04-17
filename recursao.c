#include <stdio.h>

int recursao(int a, int b){
    if (b==0) return 1;
    
    return a * recursao(a, b-1);
}

int main(){
    printf("saida: %d\n", recursao(5, 2));
}