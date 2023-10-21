#include "pilha.h"

bool insert(Pilha pilha, Tipo_Informacao elemento);

int main(){
    Pilha p1;
    int number;
    int last_element;

    init(&p1);

    do{
        printf("\nInsira o numero: ");
        scanf("%d", &number);
        if(insert(p1, number)){
            printf("\nSucesso.\n");
        }else{
            printf("\nErro.\n");
        }
    }while(!is_full(p1));

    
    while (!is_empty(p1)) {
        pop(p1, &number);
        printf("%d ", number);
    }

    return 0;
}

bool insert(Pilha pilha, Tipo_Informacao element){
    Pilha pAux;

    init(&pAux);

    Tipo_Informacao value, top;
    bool valueFound = false;

    // Se for o primeiro elemento, insere e retorna verdadeiro.
    if (is_empty(pilha)){
        push(pilha, element);
        return true;
    }

    // Pega o elemento que está no topo da pilha.
    pop(pilha, &value);
    top = value;
    push(pilha, value);

    // Se o elemento que precisa ser inserido for menor ou igual ao topo, retorna falso.
    if (element <= top){
        return false;
    }

    // Percorre a pilha para descobrir se algum elemento é repetido.
    while (!is_empty(pilha)){
        pop(pilha, &value);
        push(pAux, value);
        if (element == value){
            valueFound = true;
        }
    }

    // Coloca a pilha em ordem.
    while (!is_empty(pAux)) {
        pop(pAux, &value);
        push(pilha, value);
    }

    // Se o valor não for encontrado na pilha, empilha e retorna verdadeiro.
    if (!valueFound){
        push(pilha, element);
        return true;
    }

    return false;
}