#include <stdio.h>
#include <ctype.h>  // Para funções isalpha(), tolower()
#include <string.h> // Para a função strlen

#define MAX_LEN 1000

// Função para verificar se a string é um palíndromo
int e_palindromo(const char *str) {
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim) {
        // Pular caracteres não alfabéticos
        while (inicio < fim && !isalpha(str[inicio])) {
            inicio++;
        }
        while (inicio < fim && !isalpha(str[fim])) {
            fim--;
        }

        // Comparar caracteres em minúsculas
        if (tolower(str[inicio]) != tolower(str[fim])) {
            return 0; // Não é palíndromo
        }

        inicio++;
        fim--;
    }

    return 1; // É palíndromo
}

int main() {
    char str[MAX_LEN];

    // Leitura da string
    printf("Digite uma string (máximo de 999 caracteres): ");
    fgets(str, sizeof(str), stdin);

    // Remove o caractere de nova linha, se presente
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Verificar se a string é um palíndromo
    if (e_palindromo(str)) {
        printf("A string é um palíndromo.\n");
    } else {
        printf("A string não é um palíndromo.\n");
    }

    return 0;
}

