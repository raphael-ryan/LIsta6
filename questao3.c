#include <stdio.h>
#include <string.h>  // Para a fun��o strlen

int main() {
    char str[100];  // Buffer para armazenar a string (tamanho m�ximo 99 caracteres + 1 para '\0')

    // Leitura da string
    printf("Digite uma string (m�ximo de 99 caracteres): ");
    fgets(str, sizeof(str), stdin);

    // Remove o caractere de nova linha, se presente
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;  // Ajusta o comprimento da string ap�s remover o '\n'
    }

    // Imprimir a string de tr�s para frente
    printf("String de tr�s para frente: ");
    for (int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");

    return 0;
}

