#include <stdio.h>
#include <stdlib.h> 


#define CONSUMO_KM_POR_LITRO 10.0f

int main() {
    float distancia;
    float preco;
    float gasto_total;
    
    printf("Digite a distancia percorrida em km: ");
    scanf("%f", &distancia);

    printf("Digite o preco do combustivel por litro: ");
    scanf("%f", &preco);

    gasto_total = (distancia / CONSUMO_KM_POR_LITRO) * preco;

    printf("\nO valor total gasto com combustivel sera: R$ %.2f\n", gasto_total);

    printf("\nPressione qualquer tecla para sair...");
    system("pause");

    return 0;
}
