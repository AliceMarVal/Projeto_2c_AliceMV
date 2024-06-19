#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Definindo os tokens
#define PLUS '+'
#define MINUS '-'
#define TIMES '*'
#define DIVIDE '/'
#define LPAREN '('
#define RPAREN ')'
#define NUMBER 'n'
#define END_OF_INPUT '\0'

// Funções para o analisador sintático
int expression();
int term();
int factor();
void error(char *msg);
void match(int token);

// Variáveis globais
char *input;
int index = 0;
int parse_tree[100];
int tree_index = 0;
int tree_type = 2; // Define o tipo de árvore (2 = binária, 3 = ternária, 4 = quaternária, 5 = penta-ária)

// Função para calcular o índice do filho na árvore n-ária
int left_child_index(int i, int n) {
    return n * i + 1;
}

int right_child_index(int i, int n) {
    return n * i + n;
}

int nth_child_index(int i, int n, int nth) {
    return n * i + nth;
}

int main() {
    char buffer[100];

    printf("Digite a expressão aritmética (use espaço para separar): ");
    fgets(buffer, sizeof(buffer), stdin);

    // Remover o caractere de nova linha do final de buffer
    buffer[strcspn(buffer, "\n")] = '\0';

    // Definir o input para o analisador
    input = buffer;

    // Iniciar análise sintática
    if (expression() && input[index] == END_OF_INPUT) {
        printf("A expressão foi aceita sintaticamente.\n");

        // Imprimir a árvore de análise sintática (representada como um vetor de inteiros)
        printf("Árvore de análise sintática (código numérico):\n");
        for (int i = 0; i < tree_index; i++) {
            printf("%d ", parse_tree[i]);
        }
        printf("\n");

    } else {
        error("Erro sintático.");
    }

    return 0;
}

// Função para analisar uma expressão
int expression() {
    int result = term();

    while (input[index] == PLUS || input[index] == MINUS) {
        char op = input[index++];
        int term_value = term();
        
        // Construir a árvore de análise
        parse_tree[tree_index] = op;
        parse_tree[left_child_index(tree_index, tree_type)] = result;
        parse_tree[right_child_index(tree_index, tree_type)] = term_value;
        tree_index++;
        
        if (op == PLUS) {
            result += term_value;
        } else {
            result -= term_value;
        }
    }

    return result;
}

// Função para analisar um termo
int term() {
    int result = factor();

    while (input[index] == TIMES || input[index] == DIVIDE) {
        char op = input[index++];
        int factor_value = factor();
        
        // Construir a árvore de análise
        parse_tree[tree_index] = op;
        parse_tree[left_child_index(tree_index, tree_type)] = result;
        parse_tree[right_child_index(tree_index, tree_type)] = factor_value;
        tree_index++;

        if (op == TIMES) {
            result *= factor_value;
        } else {
            if (factor_value == 0) {
                error("Divisão por zero.");
            }
            result /= factor_value;
        }
    }

    return result;
}

// Função para analisar um fator
int factor() {
    int result;

    if (isdigit(input[index])) {
        // Se for um número, converter para inteiro
        result = input[index++] - '0';
        while (isdigit(input[index])) {
            result = result * 10 + (input[index++] - '0');
        }

        // Construir a árvore de análise
        parse_tree[tree_index] = NUMBER;
        parse_tree[left_child_index(tree_index, tree_type)] = result;
        parse_tree[right_child_index(tree_index, tree_type)] = -1; // Indicador de folha
        tree_index++;

    } else if (input[index] == LPAREN) {
        // Se for um parêntese esquerdo, analisar a expressão dentro dos parênteses
        index++;
        result = expression();
        match(RPAREN);

    } else {
        error("Erro: esperado número ou '('.");
    }

    return result;
}

// Função para emitir mensagens de erro
void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

// Função para verificar e consumir um token esperado
void match(int token) {
    if (input[index] == token) {
        index++;
    } else {
        error("Erro de correspondência de token.");
    }
}
