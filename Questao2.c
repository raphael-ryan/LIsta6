#include <stdio.h>
#include <string.h>  // Para a fun��o strlen

// Fun��o para calcular o comprimento da string sem usar strlen
int calcular_tamanho_sem_strlen(const char *str) {
    int tamanho = 0;
    while (str[tamanho] != '\0') {
        tamanho++;
    }
    return tamanho;
}

int main() {
    char str[100];  // Buffer para armazenar a string (tamanho m�ximo 99 caracteres + 1 para '\0')

    // Leitura da string
    printf("Digite uma string (m�ximo de 99 caracteres): ");
    fgets(str, sizeof(str), stdin);

    // Remove o caractere de nova linha, se presente
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // C�lculo do comprimento usando strlen
    size_t tamanho_com_strlen = strlen(str);
    
    // C�lculo do comprimento sem usar strlen
    int tamanho_sem_strlen = calcular_tamanho_sem_strlen(str);

    // Compara��o dos resultados
    printf("Comprimento calculado usando strlen: %zu\n", tamanho_com_strlen);
    printf("Comprimento calculado sem usar strlen: %d\n", tamanho_sem_strlen);

    if (tamanho_com_strlen == tamanho_sem_strlen) {
        printf("Os resultados coincidem.\n");
    } else {
        printf("Os resultados n�o coincidem.\n");
    }

    return 0;
}

