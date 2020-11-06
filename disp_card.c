#include "header.h"
int disp_card (card acard){
        char acard_output[20] = {' '};
        switch (acard.suit) {
            case 1:
                strcat(acard_output, "  Spades");
                break;
            case 2:
                strcat(acard_output, "  Hearts");
                break;
            case 3:
                strcat(acard_output, "Diamonds");
                break;
            case 4:
                strcat(acard_output, "   Clubs");
                break;
        }
        switch (acard.rank) {
            case 2:
                strcat(acard_output, " 2    ");
                break;
            case 3:
                strcat(acard_output, " 3    ");
                break;
            case 4:
                strcat(acard_output, " 4    ");
                break;
            case 5:
                strcat(acard_output, " 5    ");
                break;
            case 6:
                strcat(acard_output, " 6    ");
                break;
            case 7:
                strcat(acard_output, " 7    ");
                break;
            case 8:
                strcat(acard_output, " 8    ");
                break;
            case 9:
                strcat(acard_output, " 9    ");
                break;
            case 10:
                strcat(acard_output, " 10   ");
                break;
            case 11:
                strcat(acard_output, " Jack ");
                break;
            case 12:
                strcat(acard_output, " Queen");
                break;
            case 13:
                strcat(acard_output, " King ");
                break;
            case 14:
                strcat(acard_output, " Ace  ");
                break;
        }
        printf("  %s  ", acard_output);
    return 2;
}