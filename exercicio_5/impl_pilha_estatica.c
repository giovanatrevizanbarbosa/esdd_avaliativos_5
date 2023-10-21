/*
 * File:   impl_pilha_estatica.c
 * Author: Ednilson Rossi
 *
 * Created on 02 de outubro de 2023
 */


#include "pilha.h"


struct stack{
    Tipo_Informacao itens[MAX_STACK_SIZE];
    int topo;
};


void init(Pilha* pilha){

	*pilha = malloc(sizeof(struct stack));

	if(*pilha != NULL){
		(*pilha)->topo = -1;
	}
}


bool is_full(Pilha pilha){
	
	if(pilha->topo == MAX_STACK_SIZE - 1){
		return true;
    }else{
	    return false;
    }
}

bool is_empty(Pilha pilha){
	
    return pilha->topo == -1 ? true : false;

}

bool push(Pilha pilha, Tipo_Informacao elemento){
	bool deuCerto = false;

	if( pilha != NULL ){
		if( ! is_full(pilha) ){
            pilha->topo += 1;
            pilha->itens[pilha->topo] = elemento;
			deuCerto = true;
		}
	}

	return deuCerto;
}

bool pop(Pilha pilha, Tipo_Informacao* elemento){
	bool deuCerto = false;

	if( pilha != NULL ){
		if( ! is_empty(pilha) ){
			*elemento = pilha->itens[pilha->topo];
			pilha->topo -= 1;
			deuCerto = true;
		}
	}

	return deuCerto;
}

bool is_equal(Pilha pilha, Pilha pilha2){
    Pilha pAux1;
    Pilha pAux2;
    int number1;
    int number2;
    bool different = false;

    init(&pAux1);
    init(&pAux2);

    while(!is_empty(pilha)){
        pop(pilha, &number1);
        pop(pilha2, &number2);
        if(number1 != number2){
            different = true;
        }
        push(pAux1, number1);
        push(pAux2, number2);
    }

    while(!is_empty(pAux1)){
        pop(pAux1, &number1);
        push(pilha, number1);
    }

    while(!is_empty(pAux2)){
        pop(pAux2, &number2);
        push(pilha2, number2);
    }

    if(different){
        return false;
    }

    free(pAux1);
    free(pAux2);
    
	return true;
}