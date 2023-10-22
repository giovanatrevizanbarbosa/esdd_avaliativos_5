#include "pilha.h"

int main(){
    Pilha p1;
    int number;

    init(&p1);

    do{
        printf("\nInsira o numero: ");
        scanf("%d", &number);
        if(push(p1, number)){
            printf("\nSucesso.\n");
        }else{
            printf("\nErro.\n");
        }
    }while(!is_full(p1));

    invert(p1);

    while (!is_empty(p1)) {
        pop(p1, &number);
        printf("%d\n", number);
    }

    return 0;
}
