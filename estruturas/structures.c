#include <stdio.h>
#include <string.h>

struct Carro{
    int ano;
    char modelo[30];
    int automatico;
};

typedef struct Jogo{
    int qtdeNiveis;
    char nome[30];
    int anoLancamento;
    char desenvolvedora[30];
}Jogo; // define-se um novo tipo com o comando typedef 

void main(){
    struct Carro car; // criação de variável do tipo struct Carro

    car.ano = 2011; // atribuição de valores aos membros da estrutura
    strcpy(car.modelo, "BYD");
    car.automatico = 1;

    if (car.automatico == 1){
        printf("Carro %s de %d é automático\n", car.modelo, car.ano);
    }
    else{
        printf("Carro %s de %d não é automático\n", car.modelo, car.ano);
    }

    Jogo gearsOfWar = {14, "Gears of War", 2006, "Microsoft"};
    Jogo lastOfUs = {10, "The Last of Us", 2013, "Naughty Dog/Sony"};
    int i = 1;
    troca(&i);
}