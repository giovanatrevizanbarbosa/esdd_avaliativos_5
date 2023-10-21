#include "pilha.h"

bool isEvenOdd(int number);

void binary(int decimal, Pilha pilha);

int main(){
    Pilha pilha;
    int decimal, bit;
    
    init(&pilha);

    printf("Insira um número decimal: ");
    scanf("%d", &decimal);

    binary(decimal, pilha);

    while (!is_empty(pilha)) {
        pop(pilha, &bit);
        printf("%d", bit);
    }
    
    return 0;
}

// Retorna verdadeiro (par), retorna falso (ímpar)
bool isEvenOdd(int number){
    return number % 2 == 0; 
}

void binary(int decimal, Pilha pilha){
    int bit;

    while(decimal > 0){
        bit = isEvenOdd(decimal) ? 0 : 1;
        push(pilha, bit);
        decimal /= 2;
    }
}