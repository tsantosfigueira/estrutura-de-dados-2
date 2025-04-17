#include <stdio.h>

int isToeplitz(int linhas, int colunas, int matriz[][colunas]){
    for(int i = 1; i < linhas; i++){
        for(int j = 1; j < colunas; j++){
            if(matriz[i][j] != matriz[i-1][j-1]){
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int matriz[4][4] = {
        {6,7,8,9},
        {4,6,7,8},
        {1,4,6,7},
        {0,1,4,6}
    };
    
    if(isToeplitz(4, 4, matriz)) {
        printf("A matriz é Toeplitz\n");
    } else {
        printf("A matriz não é Toeplitz\n");
    }
    
    return 0;
}