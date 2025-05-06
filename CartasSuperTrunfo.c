#include <stdio.h>


int main() {
      // ======= Declaração das variáveis =======
    
    // Carta 1
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;  // Alterado para unsigned long int
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;  // Novo Array para densidade populacional
    float pibPerCapita1;  // Novo array para PIB Per Capita
    float superPoder1;  // Novo atributo para o Super Poder
    
    // Carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;  // Alterado para unsigned long int
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;  // Novo atributo para o Super Poder
    
    // Variáveis para resultados de comparação
    int compPopulacao;
    int compArea;
    int compPIB;
    int compPontosTuristicos;
    int compDensidadePopulacional;
    int compPIBPerCapita;
    int compSuperPoder;
    
    // ======= Mensagem de boas-vindas =======
    printf("=== SUPER TRUNFO DE PAÍSES - BATALHA DE CARTAS ===\n\n");
    
    // ======= CARTA 1 =======
    printf("CADASTRO DA CARTA 1:\n");
    printf("Digite o Estado (letra de A a H): ");
    scanf(" %c", &estado1);
    
    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    
    printf("Digite a População (número de habitantes): ");
    scanf("%lu", &populacao1);  // %lu para unsigned long int
    
    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);
    
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);
    
    // Cálculos carta 1
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0) / (float)populacao1;
    
    // ======= CARTA 2 =======
    printf("\nCADASTRO DA CARTA 2:\n");
    printf("Digite o Estado (letra de A a H): ");
    scanf(" %c", &estado2);
    
    printf("Digite o Código da Carta (ex: A02): ");
    scanf("%s", codigo2);
    
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    
    printf("Digite a População (número de habitantes): ");
    scanf("%lu", &populacao2);  // %lu para unsigned long int
    
    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);
    
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);
    
    // Cálculos carta 2
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / (float)populacao2;
    
    // Cálculo do Super Poder (somar todos os atributos numéricos)
    // Para densidade populacional, use o inverso (1/densidade) porque menor densidade é melhor
    float inversoDensidade1 = 1.0 / densidadePopulacional1;
    float inversoDensidade2 = 1.0 / densidadePopulacional2;
    
    // Cálculo do Super Poder para cada carta
    superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontosTuristicos1 + pibPerCapita1 + inversoDensidade1;
    superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontosTuristicos2 + pibPerCapita2 + inversoDensidade2;
    
    // Comparações entre as cartas (1 se carta 1 vence, 0 se carta 2 vence)
    compPopulacao = (populacao1 > populacao2) ? 1 : 0;
    compArea = (area1 > area2) ? 1 : 0;
    compPIB = (pib1 > pib2) ? 1 : 0;
    compPontosTuristicos = (pontosTuristicos1 > pontosTuristicos2) ? 1 : 0;
    compDensidadePopulacional = (densidadePopulacional1 < densidadePopulacional2) ? 1 : 0;  // Menor é melhor
    compPIBPerCapita = (pibPerCapita1 > pibPerCapita2) ? 1 : 0;
    compSuperPoder = (superPoder1 > superPoder2) ? 1 : 0;
    
    // ======= EXIBIÇÃO DOS DADOS DAS CARTAS =======
    printf("\n=== DADOS DA CARTA 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);
    
    printf("\n=== DADOS DA CARTA 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);
    
    // ======= EXIBIÇÃO DOS RESULTADOS DAS COMPARAÇÕES =======
    printf("\n=== COMPARAÇÃO DE CARTAS ===\n");
    printf("População: Carta %d venceu (%d)\n", compPopulacao ? 1 : 2, compPopulacao);
    printf("Área: Carta %d venceu (%d)\n", compArea ? 1 : 2, compArea);
    printf("PIB: Carta %d venceu (%d)\n", compPIB ? 1 : 2, compPIB);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", compPontosTuristicos ? 1 : 2, compPontosTuristicos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", compDensidadePopulacional ? 1 : 2, compDensidadePopulacional);
    printf("PIB per Capita: Carta %d venceu (%d)\n", compPIBPerCapita ? 1 : 2, compPIBPerCapita);
    printf("Super Poder: Carta %d venceu (%d)\n", compSuperPoder ? 1 : 2, compSuperPoder);

    return 0;
}
