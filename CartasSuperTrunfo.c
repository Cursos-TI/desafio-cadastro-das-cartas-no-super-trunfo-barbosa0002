#include <stdio.h>


int main() {
     // Declaração das variáveis para a Carta 1
     char estado1;
     char codigo1[4];  // Array para armazenar o código (ex: A01)
     char nomeCidade1[50];  // Array para armazenar o nome da cidade
     int populacao1;
     float area1;
     float pib1;
     int pontosTuristicos1;
     
     // Declaração das variáveis para a Carta 2
     char estado2;
     char codigo2[4];  // Array para armazenar o código (ex: B02)
     char nomeCidade2[50];  // Array para armazenar o nome da cidade
     int populacao2;
     float area2;
     float pib2;
     int pontosTuristicos2;
     
     // Mensagem de boas-vindas
     printf("=== SUPER TRUNFO DE PAÍSES - CADASTRO DE CARTAS ===\n\n");
     
     // Leitura dos dados da Carta 1
     printf("CADASTRO DA CARTA 1:\n");
     printf("Digite o Estado (letra de A a H): ");
     scanf(" %c", &estado1);
     
     printf("Digite o Código da Carta (ex: A01): ");
     scanf("%s", codigo1);
     
     printf("Digite o Nome da Cidade: ");
     scanf(" %[^\n]", nomeCidade1);  // Permite espaços no nome da cidade
     
     printf("Digite a População (número de habitantes): ");
     scanf("%d", &populacao1);
     
     printf("Digite a Área (em km²): ");
     scanf("%f", &area1);
     
     printf("Digite o PIB (em bilhões de reais): ");
     scanf("%f", &pib1);
     
     printf("Digite o Número de Pontos Turísticos: ");
     scanf("%d", &pontosTuristicos1);
     
     printf("\n");  // Linha em branco para separar os cadastros
     
     // Leitura dos dados da Carta 2
     printf("CADASTRO DA CARTA 2:\n");
     printf("Digite o Estado (letra de A a H): ");
     scanf(" %c", &estado2);
     
     printf("Digite o Código da Carta (ex: B02): ");
     scanf("%s", codigo2);
     
     printf("Digite o Nome da Cidade: ");
     scanf(" %[^\n]", nomeCidade2);  // Permite espaços no nome da cidade
     
     printf("Digite a População (número de habitantes): ");
     scanf("%d", &populacao2);
     
     printf("Digite a Área (em km²): ");
     scanf("%f", &area2);
     
     printf("Digite o PIB (em bilhões de reais): ");
     scanf("%f", &pib2);
     
     printf("Digite o Número de Pontos Turísticos: ");
     scanf("%d", &pontosTuristicos2);
     
     // Exibição dos dados das cartas
     printf("\n=== CARTAS CADASTRADAS ===\n\n");
     
     // Exibição dos dados da Carta 1
     printf("Carta 1:\n");
     printf("Estado: %c\n", estado1);
     printf("Código: %s\n", codigo1);
     printf("Nome da Cidade: %s\n", nomeCidade1);
     printf("População: %d\n", populacao1);
     printf("Área: %.2f km²\n", area1);
     printf("PIB: %.2f bilhões de reais\n", pib1);
     printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
     
     printf("\n");  // Linha em branco para separar as exibições
     
     // Exibição dos dados da Carta 2
     printf("Carta 2:\n");
     printf("Estado: %c\n", estado2);
     printf("Código: %s\n", codigo2);
     printf("Nome da Cidade: %s\n", nomeCidade2);
     printf("População: %d\n", populacao2);
     printf("Área: %.2f km²\n", area2);
     printf("PIB: %.2f bilhões de reais\n", pib2);
     printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);

    return 0;
}
