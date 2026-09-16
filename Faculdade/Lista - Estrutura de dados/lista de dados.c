#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    int codigo;
    char nome[50];
    float nota;
    struct Aluno *prox;
};

typedef struct Aluno Aluno;

void limparBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

Aluno *criarAluno(int codigo, const char *nome, float nota) {
    Aluno *novo = (Aluno *)malloc(sizeof(Aluno));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    novo->codigo = codigo;
    strcpy(novo->nome, nome);
    novo->nota = nota;
    novo->prox = NULL;

    return novo;
}

void inserirInicio(Aluno **inicio, int codigo, const char *nome, float nota) {
    Aluno *novo = criarAluno(codigo, nome, nota);
    novo->prox = *inicio;
    *inicio = novo;
    printf("Aluno inserido no inicio da lista.\n");
}

void inserirFim(Aluno **inicio, int codigo, const char *nome, float nota) {
    Aluno *novo = criarAluno(codigo, nome, nota);

    if (*inicio == NULL) {
        *inicio = novo;
        printf("Aluno inserido na lista vazia.\n");
        return;
    }

    Aluno *atual = *inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novo;
    printf("Aluno inserido no final da lista.\n");
}

void listarTodos(Aluno *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("\n--- Lista de alunos ---\n");
    Aluno *atual = inicio;
    int contador = 1;

    while (atual != NULL) {
        printf("[%d] Codigo: %d | Nome: %s | Nota: %.2f\n",
               contador,
               atual->codigo,
               atual->nome,
               atual->nota);
        atual = atual->prox;
        contador++;
    }
    printf("-----------------------\n\n");
}

int consultarPorCodigo(Aluno *inicio, int codigo) {
    Aluno *atual = inicio;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            printf("Aluno encontrado:\n");
            printf("Codigo: %d\nNome: %s\nNota: %.2f\n",
                   atual->codigo,
                   atual->nome,
                   atual->nota);
            return 1;
        }
        atual = atual->prox;
    }

    printf("Aluno com codigo %d nao encontrado.\n", codigo);
    return 0;
}

int alterarPorCodigo(Aluno *inicio, int codigo, const char *novoNome, float novaNota) {
    Aluno *atual = inicio;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            strcpy(atual->nome, novoNome);
            atual->nota = novaNota;
            printf("Dados do aluno alterados com sucesso.\n");
            return 1;
        }
        atual = atual->prox;
    }

    printf("Nao foi possivel alterar: codigo %d nao encontrado.\n", codigo);
    return 0;
}

int removerPorCodigo(Aluno **inicio, int codigo) {
    Aluno *anterior = NULL;
    Aluno *atual = *inicio;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            if (anterior == NULL) {
                *inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            printf("Aluno com codigo %d removido com sucesso.\n", codigo);
            return 1;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("Nao foi possivel remover: codigo %d nao encontrado.\n", codigo);
    return 0;
}

void liberarLista(Aluno **inicio) {
    Aluno *atual = *inicio;
    while (atual != NULL) {
        Aluno *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}

int main(void) {
    Aluno *inicio = NULL;
    int opcao;
    int codigo;
    char nome[50];
    float nota;

    do {
        printf("\n========================================\n");
        printf("Lista simplesmente encadeada - Menu\n");
        printf("========================================\n");
        printf("1 - Incluir aluno\n");
        printf("2 - Consultar aluno por codigo\n");
        printf("3 - Alterar dados do aluno\n");
        printf("4 - Remover aluno\n");
        printf("5 - Listar todos os alunos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                printf("Digite o codigo: ");
                scanf("%d", &codigo);
                limparBuffer();
                printf("Digite o nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("Digite a nota: ");
                scanf("%f", &nota);
                limparBuffer();

                inserirFim(&inicio, codigo, nome, nota);
                break;

            case 2:
                printf("Digite o codigo para consultar: ");
                scanf("%d", &codigo);
                limparBuffer();
                consultarPorCodigo(inicio, codigo);
                break;

            case 3:
                printf("Digite o codigo para alterar: ");
                scanf("%d", &codigo);
                limparBuffer();
                printf("Digite o novo nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("Digite a nova nota: ");
                scanf("%f", &nota);
                limparBuffer();
                alterarPorCodigo(inicio, codigo, nome, nota);
                break;

            case 4:
                printf("Digite o codigo para remover: ");
                scanf("%d", &codigo);
                limparBuffer();
                removerPorCodigo(&inicio, codigo);
                break;

            case 5:
                listarTodos(inicio);
                break;

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    liberarLista(&inicio);
    return 0;
}
