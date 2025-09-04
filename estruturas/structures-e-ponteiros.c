#include <stdio.h>
#include <string.h>

typedef struct Car{
    char marca[50];
    int ano;
}Carro;

// define-se somente a assinatura do método
void atualizaAno (Carro *c);

void main(){
    Carro car = {"BYD", 2026};
    Carro *pcar = &car;
    
    // o acesso aos membros de uma struct através de um ponteiro acontecem com o símbolo ->
    printf("Carro da marca %s de %d\n", pcar->marca, pcar->ano);

    Carro car2 = {"Toyota", 2024};
    atualizaAno(&car2);

    printf("Carro %s de %d\n", car2.marca, car2.ano);
}

void atualizaAno (Carro *c){
    c->ano=2027;
    strcpy(c->marca, "Abelhinha");
}
