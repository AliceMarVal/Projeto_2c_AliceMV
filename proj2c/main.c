//Alice Martins Valero

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define arv_tam 100
#define stack_tam 100

char w[16];
char output[2];
int  len = 0;
int c1 = 0;
int c2 = 0;
int c3 = 0;
int c4 = 0;


char stack[stack_tam];
int top = -1;

int pop() {
    if (top >= 0) {
        top--;
    } else {
        printf("Stack underflow!\n");
    }
    return 0;
}

int push(char symbol) {
    if (top < stack_tam - 1) {
        top++;
        stack[top] = symbol;
    } else {
        printf("Stack overflow!\n");
    }
    return 0;
}

void S0(char token){
    if(isdigit(token)){
        output[0] = 'S';
        output[1] = '5';
    }
    else if(token == '('){
        output[0] = 'S';
        output[1] = '4';
    }
    else{
        output[0] = 'B';
        output[1] = 'R';
    }
}

void S1(char token){
    if(token == '+'){
        output[0] = 'S';
        output[1] = '6';
    }
    else if(token == '$'){
        output[0] = 'A';
        output[1] = 'C';
    }
    else{
        output[0] = 'B';
        output[1] = 'R';
    }
}

void S2(char token){
    if(token == '+'){
        output[0] = 'R';
        output[1] = '2';
    }
    else if(token == '*'){
        output[0] = 'S';
        output[1] = '7';
    }
    else if(token == '/'){
        output[0] = 'S';
        output[1] = '7';
    }
    else if(token == ')'){
        output[0] = 'R';
        output[1] = '2';
    }
    else if(token == '$'){
        output[0] = 'R';
        output[1] = '2';
    }
    else{
        output[0] = 'B';
        output[1] = 'R';
    }
}

void S3(char token){
    if(token == '+'){
        output[0] = 'R';
        output[1] = '4';
    }
    else if(token == '*'){
        output[0] = 'R';
        output[1] = '4';
    }
    else if(token == '/'){
        output[0] = 'R';
        output[1] = '4';
    }
    else if(token == ')'){
        output[0] = 'R';
        output[1] = '4';
    }
    else if(token == '$'){
        output[0] = 'R';
        output[1] = '4';
    }
    else{
        output[0] = 'B';
        output[1] = 'R';
    }
}

void S4(char token){
    if(isdigit(token)){
        output[0] = 'S';
        output[1] = '5';
    }
    else if(token == '('){
        output[0] = 'S';
        output[1] = '4';
    }
    else{
        output[0] = 'B';
        output[1] = 'R';
    }
}

void S5(char token){
    if(token == '+'){
        output[0] = 'R';
        output[1] = '6';
    }
    else if(token == '*'){
        output[0] = 'R';
        output[1] = '6';
    }
    else if(token == '/'){
        output[0] = 'R';
        output[1] = '6';
    }
    else if(token == ')'){
        output[0] = 'R';
        output[1] = '6';
    }
    else if(token == '$'){
        output[0] = 'R';
        output[1] = '6';
    }
    else{
        output[0] = 'B';
        output[1] = 'R';
    }
}

void S6(char token){
    if(isdigit(token)){
        output[0] = 'S';
        output[1] = '5';
    }
    else if(token == '('){
        output[0] = 'S';
        output[1] = '4';
    }
    else{
        output[0] = 'B';
        output[1] = 'R';
    }
}

void S7(char token){
    if(isdigit(token)){
        output[0] = 'S';
        output[1] = '5';
    }
    else if(token == '('){
        output[0] = 'S';
        output[1] = '4';
    }
    else{
        output[0] = 'B';
        output[1] = 'R';
    }
}

void S8(char token){
    if(token == '+'){
        output[0] = 'S';
        output[1] = '6';
    }
    else if(token == ')'){
        push('S');
        push('1');
        push('1');
        output[0] = 'S';
        output[1] = '-';
    }
    else{
        output[0] = 'B';
        output[1] = 'R';
    }
}

void S9(char token){
    if(token == '+'){
        output[0] = 'R';
        output[1] = '1';
    }
    else if(token == '*'){
        output[0] = 'S';
        output[1] = '7';
    }
    else if(token == '/'){
        output[0] = 'S';
        output[1] = '7';
    }
    else if(token == ')'){
        output[0] = 'R';
        output[1] = '1';
    }
    else if(token == '$'){
        output[0] = 'R';
        output[1] = '1';
    }
    else{
        output[0] = 'B';
        output[1] = 'R';
    }
}

void S10(char token){
    if(token == '+'){
        output[0] = 'R';
        output[1] = '3';
    }
    else if(token == '*'){
        output[0] = 'R';
        output[1] = '3';
    }
    else if(token == '/'){
        output[0] = 'R';
        output[1] = '3';
    }
    else if(token == ')'){
        output[0] = 'R';
        output[1] = '3';
    }
    else if(token == '$'){
        output[0] = 'R';
        output[1] = '3';
    }
    else{
        output[0] = 'B';
        output[1] = 'R';
    }
}

void S11(char token){
    if(token == '+'){
        output[0] = 'R';
        output[1] = '5';
    }
    else if(token == '*'){
        output[0] = 'R';
        output[1] = '5';
    }
    else if(token == '/'){
        output[0] = 'R';
        output[1] = '5';
    }
    else if(token == ')'){
        output[0] = 'R';
        output[1] = '5';
    }
    else if(token == '$'){
        output[0] = 'R';
        output[1] = '5';
    }
    else{
        output[0] = 'B';
        output[1] = 'R';
    }
}

void action(char s, char token){
    if(s == '0'){
        S0(token);
    }
    else if(s == '1'){
        S1(token);
    }
    else if(s == '2'){
        S2(token);
    }
    else if(s == '3'){
        S3(token);
    }
    else if(s == '4'){
        S4(token);
    }
    else if(s == '5'){
        S5(token);
    }
    else if(s == '6'){
        S6(token);
    }
    else if(s == '7'){
        S7(token);
    }
    else if(s == '8'){
        S8(token);
    }
    else if(s == '9'){
        S9(token);
    }
    else if(s == '_'){
        S10(token);
    }
    else if(s == '-'){
        S11(token);
    }
}

void go_to(char s){
    if(s == '0'){
        if(c1 == 0){
            c1 = 1;
            push('F');
            push('S');
            push('3');
        }
        else if(c1 == 1){
            c1 = 2;
            push('T');
            push('S');
            push('2');
        }
        else if(c1 == 2){
            c1 = 3;
            push('E');
            push('S');
            push('1');
        }
        else{
            pop();
            pop();
            pop();
            if(s == '_' || s == '-'){
                pop();
            }
        }
    }
    else if(s == '4'){
        if(c2 == 0){
            c2 = 1;
            push('F');
            push('S');
            push('3');
        }
        else if(c2 == 1){
            c2 = 2;
            push('T');
            push('S');
            push('2');
        }
        else if(c2 == 2){
            c2 = 3;
            push('E');
            push('S');
            push('8');
        }
        else{
            pop();
            pop();
            pop();
            if(s == '_' || s == '-'){
                pop();
            }
        }
    }
    else if(s == '6'){
        if(c3 == 0){
            c3 = 1;
            push('F');
            push('S');
            push('3');
        }
        else if(c3 == 1){
            c3 = 2;
            push('T');
            push('S');
            push('9');
        }
        else{
            pop();
            pop();
            pop();
            if(s == '_' || s == '-'){
                pop();
            }
        }
    }
    else if(s == '7'){
        if(c4 == 0){
            c4 = 1;
            push('F');
            push('S');
            push('_');
        }
        else{
            pop();
            pop();
            pop();
            if(s == '_' || s == '-'){
                pop();
            }
        }
    }
    else {
        pop();
        pop();
        pop();
        if(s == '_' || s == '-'){
            pop();
        }
    }
}

int main() {
    FILE *file;
    char arv[arv_tam];

    // Open file
    file = fopen("./input.txt", "r");
    if (file == NULL) {
        printf("erro ao abrir o arquivo\n");
        return 1;
    }

    printf("\nEstado   |   Palavra   |   Acao\n"); //d do delta
    printf("\n======== ===============  ======\n");

    

//inicializa a pilha

    push('S');

    push('0');
    while(!feof(file)){
        fscanf(file, "%s", w);
        for(int i = 0; i < strlen(w);i++){

            for(int j = 0; j < top + 1; j++){
                printf("%c ",stack[j]);
            }
            printf(" | ");
            for(int k = i; k < strlen(w);k++){
                printf("%c ",w[k]);
            }
            action(stack[top],w[i]);
        
            if(output[1] == '_'){
                printf("|   10  \n");
            }
            else if(output[1] == '-'){
                printf("|  11  \n");
            }
            else{
                printf("|  %c %c  \n",output[0],output[1]);
            }
            if(output[0] == 'S'){
                push(w[i]);
                push(output[0]);
                push(output[1]);
            }
            else if(output[0] == 'R'){
                pop();
                pop();
                pop();
                go_to(stack[top]);
                i--;
            }
            else if(output[0] == 'B'){
                printf("Palavra nao reconhecida\n\n");
                break;
            }
            else if(output[0] == 'A'){
                printf("Palavra reconhecida\n\n");
                break;
            }
        }
        for(int j = 0; j <= top; j++){
            pop();
        }
        push('S');

        push('0');
    }
}
