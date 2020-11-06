#include "header.h"
void sort_card(card* card_p,int n){
    for (int i = 0; i<n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((*(card_p+j)).suit > (*(card_p+j+1)).suit) {
                swap(card_p,j);
            }
            else if((*(card_p+j)).suit == (*(card_p+j+1)).suit){
                if ((*(card_p+j)).rank > (*(card_p+j+1)).rank)
                swap(card_p,j);
                }
        }
}
