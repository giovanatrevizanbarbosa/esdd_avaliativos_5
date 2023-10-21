#include "pilha.h"

int main(){
    Pilha p1;
    Pilha p2;
    int number;

    init(&p1);
    init(&p2);

    do{
        printf("\nInsira o numero: ");
        scanf("%d", &number);
        if(push(p1, number)){
            printf("\nSucesso.\n");
        }else{
            printf("\nErro.\n");
        }
    }while(!is_full(p1));

    do{
        printf("\nInsira o numero: ");
        scanf("%d", &number);
        if(push(p2, number)){
            printf("\nSucesso.\n");
        }else{
            printf("\nErro.\n");
        }
    }while(!is_full(p2));

    if(is_equal(p1, p2)){
        printf("Sao iguais.");
    }else{
        printf("Sao diferentes.");
    }

    while(!is_empty(p1)){
        pop(p1, &number);
        printf("%d\n", number);
    }

    while(!is_empty(p1)){
        pop(p2, &number);
        printf("%d\n", number);
    }
    
    return 0;
}