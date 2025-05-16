#include <stdio.h>
#include <stdlib.h>

// Função para imprimir um separador bonitinho
int imprimirSeparador() {
    printf("\n-----------------------------------------\n");
    return 0;
}

// Função para obter o nome do atributo com base na opção escolhida
char* getNomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        case 7: return "Super Poder";
        default: return "Atributo desconhecido";
    }
}

// Função para obter o valor do atributo com base na opção escolhida
float getValorAtributo(int opcao, 
                      unsigned long int populacao, float area, float pib, 
                      int pontosTuristicos, float densidadePopulacional, 
                      float pibPerCapita, float superPoder) {
    switch (opcao) {
        case 1: return populacao;
        case 2: return area;
        case 3: return pib;
        case 4: return pontosTuristicos;
        case 5: return densidadePopulacional;
        case 6: return pibPerCapita;
        case 7: return superPoder;
        default: return 0.0;
    }
}

// Função para verificar se um atributo tem regra invertida (menor vence)
int ehAtributoInvertido(int opcao) {
    // Apenas densidade populacional tem regra invertida (menor vence)
    return (opcao == 5) ? 1 : 0;
}

// Função para exibir o menu de escolha de atributos excluindo o atributo já escolhido
int exibirMenuAtributosDinamico(int atributoExcluido) {
    int opcao;
    
    printf("\n=== MENU DE ATRIBUTOS PARA COMPARAÇÃO ===\n");
    
    if (atributoExcluido != 1)
        printf("1 - População (vence o MAIOR valor)\n");
    
    if (atributoExcluido != 2)
        printf("2 - Área (vence o MAIOR valor)\n");
    
    if (atributoExcluido != 3)
        printf("3 - PIB (vence o MAIOR valor)\n");
    
    if (atributoExcluido != 4)
        printf("4 - Pontos Turísticos (vence o MAIOR valor)\n");
    
    if (atributoExcluido != 5)
        printf("5 - Densidade Populacional (vence o MENOR valor)\n");
    
    if (atributoExcluido != 6)
        printf("6 - PIB per Capita (vence o MAIOR valor)\n");
    
    if (atributoExcluido != 7)
        printf("7 - Super Poder (vence o MAIOR valor)\n");
    
    printf("0 - Sair do jogo\n");
    printf("\nEscolha o atributo para comparar as cartas: ");
    scanf("%d", &opcao);
    
    return opcao;
}

// Função para comparar os países com base em dois atributos
int compararComDoisAtributos(
    char nomeCidade1[], char nomeCidade2[],
    unsigned long int populacao1, unsigned long int populacao2,
    float area1, float area2,
    float pib1, float pib2,
    int pontosTuristicos1, int pontosTuristicos2,
    float densidadePopulacional1, float densidadePopulacional2,
    float pibPerCapita1, float pibPerCapita2,
    float superPoder1, float superPoder2) {
    
    int atributo1, atributo2;
    int pontosCarta1 = 0, pontosCarta2 = 0;
    float valorCarta1Atrib1, valorCarta2Atrib1;
    float valorCarta1Atrib2, valorCarta2Atrib2;
    float somaCarta1, somaCarta2;
    
    printf("\n*** COMPARAÇÃO COM DOIS ATRIBUTOS ***\n");
    
    // Solicitar o primeiro atributo
    atributo1 = exibirMenuAtributosDinamico(0);
    
    // Verificar se o usuário escolheu sair
    if (atributo1 == 0) {
        printf("\nComparação cancelada. Voltando ao menu principal.\n");
        return 0;
    }
    
    // Validar a escolha do primeiro atributo
    if (atributo1 < 1 || atributo1 > 7) {
        printf("\nOpção inválida para o primeiro atributo! Por favor, escolha um número entre 1 e 7.\n");
        return 0;
    }
    
    // Solicitar o segundo atributo, excluindo o primeiro da lista
    printf("\nAgora escolha o segundo atributo (diferente do primeiro):\n");
    atributo2 = exibirMenuAtributosDinamico(atributo1);
    
    // Verificar se o usuário escolheu sair
    if (atributo2 == 0) {
        printf("\nComparação cancelada. Voltando ao menu principal.\n");
        return 0;
    }
    
    // Validar a escolha do segundo atributo
    if (atributo2 < 1 || atributo2 > 7 || atributo2 == atributo1) {
        printf("\nOpção inválida para o segundo atributo! Por favor, escolha um número entre 1 e 7 (diferente do primeiro).\n");
        return 0;
    }
    
    // Obter os valores dos atributos escolhidos
    valorCarta1Atrib1 = getValorAtributo(atributo1, populacao1, area1, pib1, pontosTuristicos1, densidadePopulacional1, pibPerCapita1, superPoder1);
    valorCarta2Atrib1 = getValorAtributo(atributo1, populacao2, area2, pib2, pontosTuristicos2, densidadePopulacional2, pibPerCapita2, superPoder2);
    
    valorCarta1Atrib2 = getValorAtributo(atributo2, populacao1, area1, pib1, pontosTuristicos1, densidadePopulacional1, pibPerCapita1, superPoder1);
    valorCarta2Atrib2 = getValorAtributo(atributo2, populacao2, area2, pib2, pontosTuristicos2, densidadePopulacional2, pibPerCapita2, superPoder2);
    
    // Comparar o primeiro atributo
    printf("\n--- Comparação do primeiro atributo: %s ---\n", getNomeAtributo(atributo1));
    printf("Carta 1 - %s: %.2f\n", nomeCidade1, valorCarta1Atrib1);
    printf("Carta 2 - %s: %.2f\n", nomeCidade2, valorCarta2Atrib1);
    
    // Verificar o vencedor do primeiro atributo
    if (ehAtributoInvertido(atributo1)) {
        // Para atributos onde o menor vence (como densidade populacional)
        if (valorCarta1Atrib1 < valorCarta2Atrib1) {
            printf("No primeiro atributo, Carta 1 (%s) venceu!\n", nomeCidade1);
            pontosCarta1++;
        } else if (valorCarta2Atrib1 < valorCarta1Atrib1) {
            printf("No primeiro atributo, Carta 2 (%s) venceu!\n", nomeCidade2);
            pontosCarta2++;
        } else {
            printf("No primeiro atributo, houve empate!\n");
        }
    } else {
        // Para atributos onde o maior vence
        if (valorCarta1Atrib1 > valorCarta2Atrib1) {
            printf("No primeiro atributo, Carta 1 (%s) venceu!\n", nomeCidade1);
            pontosCarta1++;
        } else if (valorCarta2Atrib1 > valorCarta1Atrib1) {
            printf("No primeiro atributo, Carta 2 (%s) venceu!\n", nomeCidade2);
            pontosCarta2++;
        } else {
            printf("No primeiro atributo, houve empate!\n");
        }
    }
    
    // Comparar o segundo atributo
    printf("\n--- Comparação do segundo atributo: %s ---\n", getNomeAtributo(atributo2));
    printf("Carta 1 - %s: %.2f\n", nomeCidade1, valorCarta1Atrib2);
    printf("Carta 2 - %s: %.2f\n", nomeCidade2, valorCarta2Atrib2);
    
    // Verificar o vencedor do segundo atributo
    if (ehAtributoInvertido(atributo2)) {
        // Para atributos onde o menor vence (como densidade populacional)
        if (valorCarta1Atrib2 < valorCarta2Atrib2) {
            printf("No segundo atributo, Carta 1 (%s) venceu!\n", nomeCidade1);
            pontosCarta1++;
        } else if (valorCarta2Atrib2 < valorCarta1Atrib2) {
            printf("No segundo atributo, Carta 2 (%s) venceu!\n", nomeCidade2);
            pontosCarta2++;
        } else {
            printf("No segundo atributo, houve empate!\n");
        }
    } else {
        // Para atributos onde o maior vence
        if (valorCarta1Atrib2 > valorCarta2Atrib2) {
            printf("No segundo atributo, Carta 1 (%s) venceu!\n", nomeCidade1);
            pontosCarta1++;
        } else if (valorCarta2Atrib2 > valorCarta1Atrib2) {
            printf("No segundo atributo, Carta 2 (%s) venceu!\n", nomeCidade2);
            pontosCarta2++;
        } else {
            printf("No segundo atributo, houve empate!\n");
        }
    }
    
    // Calcular a soma dos atributos para cada carta
    somaCarta1 = valorCarta1Atrib1 + valorCarta1Atrib2;
    somaCarta2 = valorCarta2Atrib1 + valorCarta2Atrib2;
    
    // Apresentar o resultado final baseado na soma dos valores
    printf("\n--- RESULTADO FINAL BASEADO NA SOMA DOS VALORES ---\n");
    printf("Soma dos valores para Carta 1 (%s): %.2f\n", nomeCidade1, somaCarta1);
    printf("Soma dos valores para Carta 2 (%s): %.2f\n", nomeCidade2, somaCarta2);
    
    if (somaCarta1 > somaCarta2) {
        printf("\nVENCEDOR GERAL: Carta 1 (%s) com soma de %.2f pontos!\n", nomeCidade1, somaCarta1);
    } else if (somaCarta2 > somaCarta1) {
        printf("\nVENCEDOR GERAL: Carta 2 (%s) com soma de %.2f pontos!\n", nomeCidade2, somaCarta2);
    } else {
        printf("\nRESULTADO FINAL: EMPATE! Ambas as cartas têm a mesma soma (%.2f).\n", somaCarta1);
    }
    
    return 0;
}

// Função para exibir o menu principal
int exibirMenuPrincipal() {
    int opcao;
    
    printf("\n=== MENU PRINCIPAL - SUPER TRUNFO DE PAÍSES ===\n");
    printf("1 - Comparar com um atributo\n");
    printf("2 - Comparar com dois atributos (NOVO!)\n");
    printf("0 - Sair do jogo\n");
    printf("\nEscolha uma opção: ");
    scanf("%d", &opcao);
    
    return opcao;
}

// Função para comparar um atributo específico
int compararAtributoEspecifico(int atributo, 
                               char nomeCidade1[], char nomeCidade2[],
                               unsigned long int populacao1, unsigned long int populacao2,
                               float area1, float area2,
                               float pib1, float pib2,
                               int pontosTuristicos1, int pontosTuristicos2,
                               float densidadePopulacional1, float densidadePopulacional2,
                               float pibPerCapita1, float pibPerCapita2,
                               float superPoder1, float superPoder2) {
    
    printf("\n*** COMPARAÇÃO DETALHADA ***\n");
    
    // Mostrar qual atributo estamos comparando
    if (atributo == 1) {
        printf("Comparação baseada em: População\n");
        printf("Carta 1 - %s: %lu habitantes\n", nomeCidade1, populacao1);
        printf("Carta 2 - %s: %lu habitantes\n", nomeCidade2, populacao2);
        
        // Verificar quem ganhou
        if (populacao1 > populacao2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (populacao2 > populacao1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate! As duas cidades têm a mesma população.\n");
        }
    }
    
    else if (atributo == 2) {
        printf("Comparação baseada em: Área\n");
        printf("Carta 1 - %s: %.2f km²\n", nomeCidade1, area1);
        printf("Carta 2 - %s: %.2f km²\n", nomeCidade2, area2);
        
        if (area1 > area2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (area2 > area1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate! As duas cidades têm a mesma área.\n");
        }
    }
    
    else if (atributo == 3) {
        printf("Comparação baseada em: PIB\n");
        printf("Carta 1 - %s: %.2f bilhões de reais\n", nomeCidade1, pib1);
        printf("Carta 2 - %s: %.2f bilhões de reais\n", nomeCidade2, pib2);
        
        if (pib1 > pib2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (pib2 > pib1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate! As duas cidades têm o mesmo PIB.\n");
        }
    }
    
    else if (atributo == 4) {
        printf("Comparação baseada em: Pontos Turísticos\n");
        printf("Carta 1 - %s: %d pontos\n", nomeCidade1, pontosTuristicos1);
        printf("Carta 2 - %s: %d pontos\n", nomeCidade2, pontosTuristicos2);
        
        if (pontosTuristicos1 > pontosTuristicos2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (pontosTuristicos2 > pontosTuristicos1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate! As duas cidades têm o mesmo número de pontos turísticos.\n");
        }
    }
    
    else if (atributo == 5) {
        printf("Comparação baseada em: Densidade Populacional\n");
        printf("Carta 1 - %s: %.2f hab/km²\n", nomeCidade1, densidadePopulacional1);
        printf("Carta 2 - %s: %.2f hab/km²\n", nomeCidade2, densidadePopulacional2);
        
        // Lembrete: para densidade, o MENOR valor vence!
        if (densidadePopulacional1 < densidadePopulacional2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (densidadePopulacional2 < densidadePopulacional1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate! As duas cidades têm a mesma densidade populacional.\n");
        }
    }
    
    else if (atributo == 6) {
        printf("Comparação baseada em: PIB per Capita\n");
        printf("Carta 1 - %s: %.2f reais\n", nomeCidade1, pibPerCapita1);
        printf("Carta 2 - %s: %.2f reais\n", nomeCidade2, pibPerCapita2);
        
        if (pibPerCapita1 > pibPerCapita2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (pibPerCapita2 > pibPerCapita1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate! As duas cidades têm o mesmo PIB per capita.\n");
        }
    }
    
    else if (atributo == 7) {
        printf("Comparação baseada em: Super Poder\n");
        printf("Carta 1 - %s: %.2f pontos\n", nomeCidade1, superPoder1);
        printf("Carta 2 - %s: %.2f pontos\n", nomeCidade2, superPoder2);
        
        if (superPoder1 > superPoder2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (superPoder2 > superPoder1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate! As duas cidades têm o mesmo Super Poder.\n");
        }
    }
    
    else {
        printf("Ops! Atributo inválido. Escolha entre 1 e 7.\n");
    }
    
    return 0;
}

// Função para exibir o menu de escolha de atributos
int exibirMenuAtributos() {
    int opcao;
    
    printf("\n=== MENU DE ATRIBUTOS PARA COMPARAÇÃO ===\n");
    printf("1 - População (vence o MAIOR valor)\n");
    printf("2 - Área (vence o MAIOR valor)\n");
    printf("3 - PIB (vence o MAIOR valor)\n");
    printf("4 - Pontos Turísticos (vence o MAIOR valor)\n");
    printf("5 - Densidade Populacional (vence o MENOR valor)\n");
    printf("6 - PIB per Capita (vence o MAIOR valor)\n");
    printf("7 - Super Poder (vence o MAIOR valor)\n");
    printf("0 - Sair do jogo\n");
    printf("\nEscolha o atributo para comparar as cartas: ");
    scanf("%d", &opcao);
    
    return opcao;
}

int main() {
    // Declaração das variáveis
    
    // Carta 1
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    float superPoder1;
    
    // Carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;
    
    // Variáveis para o menu e controle do jogo
    int opcaoMenu;
    int opcaoMenuPrincipal;
    int jogarNovamente = 1;
    
    // Mensagem de boas-vinda
    printf("=== SUPER TRUNFO DE PAÍSES - BATALHA DE CARTAS ===\n\n");
    
    // CARTA 1 
    printf("CADASTRO DA CARTA 1:\n");
    printf("Digite o Estado (letra de A a H): ");
    scanf(" %c", &estado1);
    
    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    
    printf("Digite o Nome do País: ");
    scanf(" %[^\n]", nomeCidade1);
    
    printf("Digite a População (número de habitantes): ");
    scanf("%lu", &populacao1);
    
    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);
    
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);
    
    // Cálculos carta 1
    densidadePopulacional1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;
    
    // CARTA 2 
    printf("\nCADASTRO DA CARTA 2:\n");
    printf("Digite o Estado (letra de A a H): ");
    scanf(" %c", &estado2);
    
    printf("Digite o Código da Carta (ex: A02): ");
    scanf("%s", codigo2);
    
    printf("Digite o Nome do País: ");
    scanf(" %[^\n]", nomeCidade2);
    
    printf("Digite a População (número de habitantes): ");
    scanf("%lu", &populacao2);
    
    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);
    
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);
    
    // Cálculos carta 2
    densidadePopulacional2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;
    
    // Cálculo do Super Poder (somar todos os atributos numéricos)
    float inversoDensidade1 = 1.0 / densidadePopulacional1;
    float inversoDensidade2 = 1.0 / densidadePopulacional2;
    
    // Cálculo do Super Poder para cada carta
    superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + inversoDensidade1;
    superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + inversoDensidade2;
    
    // EXIBIÇÃO DOS DADOS DAS CARTAS 
    printf("\n=== DADOS DA CARTA 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome do País: %s\n", nomeCidade1);
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
    printf("Nome do País: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);
    
    // Loop principal do jogo
    do {
        // Exibir menu principal e obter a escolha do usuário
        opcaoMenuPrincipal = exibirMenuPrincipal();
        
        // Usar switch para processar a escolha do usuário no menu principal
        switch (opcaoMenuPrincipal) {
            case 0:
                printf("\nObrigado por jogar Super Trunfo de Países! Até a próxima!\n");
                jogarNovamente = 0;  // Sair do loop
                break;
                
            case 1:  // Comparação com um atributo
                // Exibir menu de atributos e obter a escolha do usuário
                opcaoMenu = exibirMenuAtributos();
                
                // Usar switch para processar a escolha do usuário
                switch (opcaoMenu) {
                    case 0:
                        printf("\nVoltando ao menu principal.\n");
                        break;
                        
                    case 1:  // População
                    case 2:  // Área
                    case 3:  // PIB
                    case 4:  // Pontos Turísticos
                    case 5:  // Densidade Populacional
                    case 6:  // PIB per Capita
                    case 7:  // Super Poder
                        imprimirSeparador();
                        compararAtributoEspecifico(opcaoMenu, 
                                                  nomeCidade1, nomeCidade2,
                                                  populacao1, populacao2,
                                                  area1, area2,
                                                  pib1, pib2,
                                                  pontosTuristicos1, pontosTuristicos2,
                                                  densidadePopulacional1, densidadePopulacional2,
                                                  pibPerCapita1, pibPerCapita2,
                                                  superPoder1, superPoder2);
                        imprimirSeparador();
                        break;
                        
                    default:
                        printf("\nOpção inválida! Por favor, escolha um número entre 0 e 7.\n");
                        break;
                }
                break;
                
            case 2:  // Comparação com dois atributos (NOVO!)
                imprimirSeparador();
                compararComDoisAtributos(nomeCidade1, nomeCidade2,
                                        populacao1, populacao2,
                                        area1, area2,
                                        pib1, pib2,
                                        pontosTuristicos1, pontosTuristicos2,
                                        densidadePopulacional1, densidadePopulacional2,
                                        pibPerCapita1, pibPerCapita2,
                                        superPoder1, superPoder2);
                imprimirSeparador();
                break;
                
            default:
                printf("\nOpção inválida! Por favor, escolha um número entre 0 e 2.\n");
                break;
        }
        
        // Se não escolheu sair, perguntar se deseja jogar novamente
        if (opcaoMenuPrincipal != 0) {
            printf("\nDeseja continuar jogando?\n");
            printf("1 - Sim\n");
            printf("0 - Não\n");
            printf("Sua escolha: ");
            scanf("%d", &jogarNovamente);
        }
        
    } while (jogarNovamente != 0);

    return 0;
}