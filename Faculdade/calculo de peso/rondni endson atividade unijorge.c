#include <stdio.h>
#include <stdlib.h> 

int main() {

    float peso, altura, resultado_imc;

    printf("Digite seu peso: ");
    scanf("%f", &peso);

    
    printf("Digite sua altura (ex: 1.75): ");
    scanf("%f", &altura);

    resultado_imc = peso / (altura * altura);

    printf("\nO seu IMC é: %.2f\n", resultado_imc);

    printf("\nPressione qualquer tecla para sair...");
    system("pause");

    return 0;
}
