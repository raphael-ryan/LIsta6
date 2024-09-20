#include <stdio.h>
#include <ctype.h>  // Para fun��es isalpha(), tolower()
#include <string.h> // Para a fun��o strlen

#define MAX_LEN 1000

// Fun��o para verificar se a string � um pal�ndromo
int e_palindromo(const char *str) {
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim) {
        // Pular caracteres n�o alfab�ticos
        while (inicio < fim && !isalpha(str[inicio])) {
            inicio++;
        }
        while (inicio < fim && !isalpha(str[fim])) {
            fim--;
        }

        // Comparar caracteres em min�sculas
        if (tolower(str[inicio]) != tolower(str[fim])) {
            return 0; // N�o � pal�ndromo
        }

        inicio++;
        fim--;
    }

    return 1; // � pal�ndromo
}

int main() {
    char str[MAX_LEN];

    // Leitura da string
    printf("Digite uma string (m�ximo de 999 caracteres): ");
    fgets(str, sizeof(str), stdin);

    // Remove o caractere de nova linha, se presente
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Verificar se a string � um pal�ndromo
    if (e_palindromo(str)) {
        printf("A string � um pal�ndromo.\n");
    } else {
        printf("A string n�o � um pal�ndromo.\n");
    }

    return 0;
}

