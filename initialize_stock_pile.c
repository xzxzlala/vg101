#include "header.h"
card* initialize_stock_pile (int desks,struct Deskcard OneDeskCard){
    card *p=(card *)malloc(52*(unsigned int)desks*sizeof(card));
    for (int j=0;j<desks;j++) {
        for (int i = 0; i <= 51; i++) {
            p[i+j*52].suit = OneDeskCard.cardsar[i].suit;
            p[i+j*52].rank = OneDeskCard.cardsar[i].rank;
            p[i+j*52].deck=j;
            p[i+j*52].position=1;
        }
    }
    return p;
}

