#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    
    int numeroSecreto = time(0);
    srand(numeroSecreto);
    numeroSecreto = numeroSecreto % 100;

    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;

    int nivel;

    int numeroDeTentativas = 5;
    
    // Imprime cabeçalho do jogo
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                             \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao    \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!\n");
    printf("    |     |  |_|  |     |                        \n");
    printf("    |_____| ' _ ' |_____|                        \n");
    printf("          \\__|_|__/                              \n");

    printf("\n\nQual o nivel de dificuldade?\n");
    printf("(1) - Facil\n");
    printf("(2) - Medio\n");
    printf("(3) - Dificil\n\n");

    printf("Escolha: ");
    scanf("%d", &nivel);

    switch (nivel){
    case 1:
        numeroDeTentativas = 20;
        break;
    case 2:
        numeroDeTentativas = 15;
        break;
    default:
        numeroDeTentativas = 6;
        break;
    }
    
    //printf("\nO numero %d e o numero secreto. Nao conta pra ninguem!", numeroSecreto);
    
    for(int i = 1; i <= numeroDeTentativas; i++){
        
        printf("\nTentativa %d\n", tentativas);
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);

        if (chute < 0){
            printf("Voce nao pode chutar numeros negativos\n");

            continue;
        }

        acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;

        if(acertou){        
            break;
        }

        else if(maior){
            printf("Seu chute foi maior que o numero secreto\n");
        } 
        else{
            printf("Seu chute foi menor que o numero secreto\n");
        }
        tentativas++;
    
        double pontosPerdidos = abs((numeroSecreto - chute) / (double)2);
        pontos = pontos - pontosPerdidos;

        printf("Voce perdeu: %.2f\n", pontosPerdidos);
        printf("Pontos atuais: %.2f\n", pontos);
    }
    
    printf("Fim de jogo\n");

    if(acertou) {

        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");

        printf("Parabens! Você ganhou!\n");
        printf("Voce acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);

    } else {
            printf("Voce perdeu! Tente de novo!\n");

            printf("       \\|/ ____ \\|/    \n");
            printf("        @~/ ,. \\~@      \n");
            printf("       /_( \\__/ )_\\    \n");
            printf("          \\__U_/        \n");
    }
}