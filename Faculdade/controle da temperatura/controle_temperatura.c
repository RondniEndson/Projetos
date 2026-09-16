#include <stdio.h>
#include <locale.h>

typedef enum {
    ACAO_AQUECER,
    ACAO_RESFRIAR,
    ACAO_ESTAVEL
} AcaoSistema;

float lerTemperatura(void) {
    float temperatura;
    int leituraValida;

    do {
        printf("Digite a temperatura atual do ambiente (°C): ");
        leituraValida = scanf("%f", &temperatura);

        if (leituraValida != 1) {
            printf("Entrada invalida! Digite um valor numerico.\n");
            while (getchar() != '\n');
        }
    } while (leituraValida != 1);

    return temperatura;
}

AcaoSistema analisarTemperatura(float temperatura, float limiteMin, float limiteMax) {
    if (temperatura > limiteMax) {
        return ACAO_RESFRIAR;
    } else if (temperatura < limiteMin) {
        return ACAO_AQUECER;
    } else {
        return ACAO_ESTAVEL;
    }
}

void exibirResultado(AcaoSistema acao, float temperatura, float limiteMin, float limiteMax) {
    printf("\n--- Status do Sistema de Climatizacao ---\n");
    printf("Temperatura lida : %.1f C\n", temperatura);
    printf("Faixa ideal      : %.1f C a %.1f C\n", limiteMin, limiteMax);
    printf("Acao do sistema  : ");

    switch (acao) {
        case ACAO_AQUECER:
            printf("Aquecendo...\n");
            break;
        case ACAO_RESFRIAR:
            printf("Resfriando...\n");
            break;
        case ACAO_ESTAVEL:
            printf("Temperatura estável.\n");
            break;
    }
    printf("------------------------------------------\n");
}

int main(void) {
    const float LIMITE_MIN = 18.0;
    const float LIMITE_MAX = 26.0;
    char continuar;

    setlocale(LC_ALL, "");

    printf("=== Sistema Inteligente de Controle de Temperatura ===\n");
    printf("Faixa ideal configurada: %.1f C a %.1f C\n\n", LIMITE_MIN, LIMITE_MAX);

    do {
        float temperaturaAtual = lerTemperatura();
        AcaoSistema acao = analisarTemperatura(temperaturaAtual, LIMITE_MIN, LIMITE_MAX);
        exibirResultado(acao, temperaturaAtual, LIMITE_MIN, LIMITE_MAX);

        printf("\nDeseja testar outro valor? (s/n): ");
        scanf(" %c", &continuar);
        printf("\n");

    } while (continuar == 's' || continuar == 'S');

    printf("Encerrando o sistema de controle de temperatura.\n");
    return 0;
}
