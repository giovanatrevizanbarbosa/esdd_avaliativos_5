#include "pilha.h"

int main(){
    Pilha p1;
    int number;
    int last_element;

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

    to_empty(p1);

    if(is_empty(p1) ? printf("Esta vazia.") : printf("Nao esta vazia."));

    return 0;
}
