#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estruturas para armazenar os dados de cada carta
char estado1[3], estado2[3];
char codigo1[12], codigo2[12];
char nome_cidade1[50], nome_cidade2[50];
long int populacao1, populacao2;
double PIB1, PIB2;
double area1, area2;
int num_pontos_turisticos1, num_pontos_turisticos2;
double densidade_populacional1, densidade_populacional2;
double PIB_per_capita1, PIB_per_capita2;

double calcular_densidade_populacional(long int populacao, double area) {
    return populacao / area;
}

double calcular_PIB_per_capita(double PIB, long int populacao) {
    return PIB / populacao;
}

void cadastrarCarta(char estado[], char codigo[], char nome_cidade[], long int *populacao, double *PIB, double *area, int *num_pontos_turisticos, double *densidade_populacional, double *PIB_per_capita) {
    printf("Digite o estado (2 letras): ");
    scanf("%2s", estado);

    printf("Digite o código da carta: ");
    scanf("%s", codigo);

    // Concatenar o estado ao código
    char codigo_completo[12];
    strcpy(codigo_completo, estado);
    strcat(codigo_completo, codigo);

    strcpy(codigo, codigo_completo);

    printf("Código completo: %s\n", codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]%*c", nome_cidade);

    printf("Digite a população: ");
    scanf("%ld", populacao);

    printf("Digite o PIB: ");
    scanf("%lf", PIB);

    printf("Digite a área (em km²): ");
    scanf("%lf", area);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", num_pontos_turisticos);

    // Calcular densidade populacional e PIB per capita
    *densidade_populacional = calcular_densidade_populacional(*populacao, *area);
    *PIB_per_capita = calcular_PIB_per_capita(*PIB, *populacao);

    printf("Carta cadastrada com sucesso!\n");
}

void exibirCarta(char estado[], char codigo[], char nome_cidade[], long int populacao, double area, double densidade_populacional, double PIB, double PIB_per_capita, int num_pontos_turisticos) {
    printf("\nInformações da Carta:\n");
    printf("Estado: %s\n", estado);
    printf("Código da Carta: %s\n", codigo);
    printf("Nome da Cidade: %s\n", nome_cidade);
    printf("População: %ld\n", populacao);
    printf("Área: %.2lf km²\n", area);
    printf("Densidade Populacional: %.2lf habitantes/km²\n", densidade_populacional);
    printf("PIB: %.2lf bilhões de reais\n", PIB);
    printf("PIB per capita: %.2lf reais\n", PIB_per_capita);
    printf("Número de Pontos Turísticos: %d\n", num_pontos_turisticos);
}

void compararAtributos() {
    int atributo;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. Densidade Populacional\n");
    printf("4. PIB\n");
    printf("5. PIB per capita\n");
    printf("Escolha uma opção: ");
    scanf("%d", &atributo);

    switch (atributo) {
        case 1:
            printf("População da carta 1: %ld, População da carta 2: %ld\n", populacao1, populacao2);
            if (populacao1 > populacao2) {
                printf("A carta 1 venceu!\n");
            } else if (populacao2 > populacao1) {
                printf("A carta 2 venceu!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        case 2:
            printf("Área da carta 1: %.2lf, Área da carta 2: %.2lf\n", area1, area2);
            if (area1 > area2) {
                printf("A carta 1 venceu!\n");
            } else if (area2 > area1) {
                printf("A carta 2 venceu!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        case 3:
            printf("Densidade Populacional da carta 1: %.2lf, Densidade Populacional da carta 2: %.2lf\n", densidade_populacional1, densidade_populacional2);
            if (densidade_populacional1 > densidade_populacional2) {
                printf("A carta 1 venceu!\n");
            } else if (densidade_populacional2 > densidade_populacional1) {
                printf("A carta 2 venceu!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        case 4:
            printf("PIB da carta 1: %.2lf, PIB da carta 2: %.2lf\n", PIB1, PIB2);
            if (PIB1 > PIB2) {
                printf("A carta 1 venceu!\n");
            } else if (PIB2 > PIB1) {
                printf("A carta 2 venceu!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        case 5:
            printf("PIB per capita da carta 1: %.2lf, PIB per capita da carta 2: %.2lf\n", PIB_per_capita1, PIB_per_capita2);
            if (PIB_per_capita1 > PIB_per_capita2) {
                printf("A carta 1 venceu!\n");
            } else if (PIB_per_capita2 > PIB_per_capita1) {
                printf("A carta 2 venceu!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        default:
            printf("Atributo inválido!\n");
    }
}

int main() {
    int opcao;
    do {
        printf("\n\nMenu:\n");
        printf("1. Adicionar Carta 1\n");
        printf("2. Adicionar Carta 2\n");
        printf("3. Listar Carta 1\n");
        printf("4. Listar Carta 2\n");
        printf("5. Comparar Atributos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCarta(estado1, codigo1, nome_cidade1, &populacao1, &PIB1, &area1, &num_pontos_turisticos1, &densidade_populacional1, &PIB_per_capita1);
                break;
            case 2:
                cadastrarCarta(estado2, codigo2, nome_cidade2, &populacao2, &PIB2, &area2, &num_pontos_turisticos2, &densidade_populacional2, &PIB_per_capita2);
                break;
            case 3:
                exibirCarta(estado1, codigo1, nome_cidade1, populacao1, area1, densidade_populacional1, PIB1, PIB_per_capita1, num_pontos_turisticos1);
                break;
            case 4:
                exibirCarta(estado2, codigo2, nome_cidade2, populacao2, area2, densidade_populacional2, PIB2, PIB_per_capita2, num_pontos_turisticos2);
                break;
            case 5:
                compararAtributos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
