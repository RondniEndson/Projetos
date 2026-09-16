
#include <stdio.h>
#include <string.h>

#define LIMITE_HORAS_NORMAIS 40.0
#define ADICIONAL_HORA_EXTRA 0.5  

float calcularSalario(float horasTrabalhadas, float valorHora,
                       float *horasExtras, float *valorExtra,
                       float *valorNormal);

int main(void) {
    char nome[100];
    float horasTrabalhadas, valorHora;
    float salarioTotal, horasExtras, valorExtra, valorNormal;
    char continuar;

    printf("===================================================\n");
    printf("   SISTEMA DE CALCULO DE FOLHA DE PAGAMENTO\n");
    printf("===================================================\n");

    do {
        printf("\n--- Novo calculo ---\n");

        printf("Nome do funcionario: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        printf("Numero de horas trabalhadas na semana: ");
        scanf("%f", &horasTrabalhadas);

        printf("Valor da hora (R$): ");
        scanf("%f", &valorHora);

        if (horasTrabalhadas < 0 || valorHora < 0) {
            printf("\nErro: valores negativos nao sao permitidos!\n");
        } else {
            salarioTotal = calcularSalario(horasTrabalhadas, valorHora,
                                            &horasExtras, &valorExtra,
                                            &valorNormal);

            printf("\n----------- RESUMO DO PAGAMENTO -----------\n");
            printf("Funcionario......: %s\n", nome);
            printf("Horas trabalhadas: %.2f h\n", horasTrabalhadas);
            printf("Valor da hora....: R$ %.2f\n", valorHora);

            if (horasTrabalhadas > LIMITE_HORAS_NORMAIS) {
                printf("Horas normais....: %.2f h -> R$ %.2f\n",
                       LIMITE_HORAS_NORMAIS, valorNormal);
                printf("Horas extras.....: %.2f h -> R$ %.2f (adicional de 50%%)\n",
                       horasExtras, valorExtra);
            } else {
                printf("Nao houve horas extras nesta semana.\n");
            }

            printf("--------------------------------------------\n");
            printf("SALARIO TOTAL....: R$ %.2f\n", salarioTotal);
            printf("--------------------------------------------\n");
        }

        printf("\nDeseja calcular o salario de outro funcionario? (S/N): ");
        scanf(" %c", &continuar);
        while (getchar() != '\n');

    } while (continuar == 'S' || continuar == 's');

    printf("\nPrograma encerrado. Ate logo!\n");

    return 0;
}


float calcularSalario(float horasTrabalhadas, float valorHora,
                       float *horasExtras, float *valorExtra,
                       float *valorNormal) {

    float salario;


    if (horasTrabalhadas > LIMITE_HORAS_NORMAIS) {
        *horasExtras = horasTrabalhadas - LIMITE_HORAS_NORMAIS;
        *valorNormal = LIMITE_HORAS_NORMAIS * valorHora;
        *valorExtra  = (*horasExtras) * (valorHora * (1 + ADICIONAL_HORA_EXTRA));

        salario = *valorNormal + *valorExtra;
    } else {
        *horasExtras = 0;
        *valorExtra  = 0;
        *valorNormal = horasTrabalhadas * valorHora;

        salario = *valorNormal;
    }

    return salario;
}
