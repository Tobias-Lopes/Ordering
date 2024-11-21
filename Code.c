#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMEROS 100

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    char entrada[1000]; // Buffer para a entrada do usuário
    int numeros[MAX_NUMEROS];
    int n = 0;

    printf("Digite os números inteiros separados por espaços:\n");
    fgets(entrada, sizeof(entrada), stdin);
    
    // Remove o caractere de nova linha, se existir
    entrada[strcspn(entrada, "\n")] = '\0';

    // Processa os números da entrada
    char *token = strtok(entrada, " ");
    while (token != NULL) {
        numeros[n++] = atoi(token); // Converte o token para inteiro e armazena no vetor
        token = strtok(NULL, " ");
    }

    // Ordena os números usando qsort
    qsort(numeros, n, sizeof(int), comparar);

    // Exibe os números ordenados
    printf("Lista ordenada:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
