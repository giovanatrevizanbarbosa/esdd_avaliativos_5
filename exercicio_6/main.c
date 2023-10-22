#include "pilha.h"

bool checkExpression(char *expression);

int main() {
    char *expression = "{[()]}";

    if (checkExpression(expression)) {
        printf("Contém parênteses, colchetes e chaves bem formados.\n");
    } else {
        printf("NÃO contém parênteses, colchetes e chaves bem formados.\n");
    }

    return 0;
}

bool checkExpression(char *expression) {
    Pilha pilha;
    init(&pilha);

    Tipo_Informacao top;
    int i;

    for (i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(pilha, expression[i]);
        } else {
            if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
                if (is_empty(pilha)) {
                    return false;
                }
                pop(pilha, &top);
                if ((expression[i] == ')' && top != '(') ||
                    (expression[i] == ']' && top != '[') ||
                    (expression[i] == '}' && top != '{')) {
                    return false;
                }
            }
        } 
    }

    return is_empty(pilha);
}
