#include <stdio.h>
#include <ctype.h>  // Para funções isdigit(), isupper(), islower()
#include <string.h> // Para função strlen()

#define MAX_LEN 100

int verificar_senha(const char *senha) {
    int len = strlen(senha);
    int tem_numero = 0;
    int tem_maiuscula = 0;
    int tem_minuscula = 0;

    // Verificar comprimento da senha
    if (len < 8 || len > 100) {
        return 0; // Senha inválida
    }

    // Verificar caracteres
    for (int i = 0; i < len; i++) {
        if (isdigit(senha[i])) {
            tem_numero = 1;
        } else if (isupper(senha[i])) {
            tem_maiuscula = 1;
        } else if (islower(senha[i])) {
            tem_minuscula = 1;
        }
    }

    // Verificar se todos os requisitos são atendidos
    return tem_numero && tem_maiuscula && tem_minuscula;
}

int main() {
    char senha[MAX_LEN + 1]; // +1 para o caractere nulo

    printf("Digite a senha (maximo de 100 caracteres): ");
    fgets(senha, sizeof(senha), stdin);

    // Remover o caractere de nova linha, se presente
    size_t len = strlen(senha);
    if (len > 0 && senha[len - 1] == '\n') {
        senha[len - 1] = '\0';
    }

    // Verificar a senha
    if (verificar_senha(senha)) {
        printf("Senha válida.\n");
    } else {
        printf("Senha inválida. Certifique-se de que a senha:\n");
        printf("- Tenha no mínimo 8 caracteres.\n");
        printf("- Contenha pelo menos um número.\n");
        printf("- Contenha pelo menos uma letra maiúscula.\n");
        printf("- Contenha pelo menos uma letra minúscula.\n");
        printf("- Tenha no máximo 100 caracteres.\n");
    }

    return 0;
}

