#include <stdio.h>
#include <locale.h>

#define TAM 25

int main() {
    setlocale(LC_ALL, "portuguese");
    int cofre[TAM] = {9, 0, 2, 8, 6, 6, 2, 9, 0, 6, 0, 8, 4, 9, 8, 4, 4, 6, 2, 2, 6, 0, 8, 9, 8};
    int i, pos1, pos2, zero = 0, dois = 1, quatro = 0, seis = 0, oito = 0, nove = 0, cont = 0, cont2 = 3;
    //Caso mude a ordem dos elementos do vetor, mudar a contagem dos n�meros abaixo de acordo com o n�mero que est� na posi��o 10!!!
    while (cont2 > 0) {
        pos1 = 10, pos2 = 10;
        zero = 1, dois = 0, quatro = 0, seis = 0, oito = 0, nove = 0;
        cont = 0;

        while (pos2 >= 0 && cont < 5) {
            pos1 = pos2;

            do {
                printf("\nInsira a posi��o do cofre para qual deseja ir: (0-24): ");
                scanf("%d", &pos2);
            } while (pos2 >= TAM);

            if (pos2 < 0) {
                printf("Posi��o inv�lida.\n");
            } else {

                if (pos2 > pos1) {
                        printf("\n\nPOSI��O");
                    for (i = pos1 + 1; i <= pos2; i++) {
                        printf("\n|%d| %d  ", i, cofre[i]);

                        switch (cofre[i]) {
                            case 0:
                                zero++;
                                break;
                            case 2:
                                dois++;
                                break;
                            case 4:
                                quatro++;
                                break;
                            case 6:
                                seis++;
                                break;
                            case 8:
                                oito++;
                                break;
                            case 9:
                                nove++;
                                break;
                        }
                    }
                } else {

                    printf("\n\nPOSI��O");
                    for (i = pos1 - 1; i >= pos2; i--){
                        printf("\n|%d| %d ", i, cofre[i]);

                        switch (cofre[i]) {
                            case 0:
                                zero++;
                                break;
                            case 2:
                                dois++;
                                break;
                            case 4:
                                quatro++;
                                break;
                            case 6:
                                seis++;
                                break;
                            case 8:
                                oito++;
                                break;
                            case 9:
                                nove++;
                                break;
                        }
                    }
                }
            }
            cont++;

            printf("\n\nCONTAGEM");
            printf("\n|0| %d \n|2| %d \n|4| %d \n|6| %d \n|8| %d \n|9| %d\n\n\n", zero, dois, quatro, seis, oito, nove);
        }


        printf("\n\nSenha final: %d  %d  %d  %d  %d  %d  ", zero, dois, quatro, seis, oito, nove);

        if (zero == 3 && dois == 4 && quatro == 6 && seis == 4 && oito == 5 && nove == 2) {
            printf("\n\nParab�ns! A senha est� correta!!!");
            cont2 = 0;
        } else {
            cont2--;
            printf("\n\nSenha incorreta. Voc� tem mais %d tentativas.", cont2);

            if (cont2 == 0) {
                printf("\nSuas tentativas acabaram. O cofre est� bloqueado.");
            }
        }
    }
    return 0;
}
