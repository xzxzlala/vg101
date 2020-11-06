#include "header.h"
Deskcard initialize_index_to_card(struct Deskcard OneDeskCard) {
    for (int i=0;i<=51;i++){
        switch (i/13) {
            case 0:
                OneDeskCard.cardsar[i].suit=1;
                break;
            case 1:
                OneDeskCard.cardsar[i].suit=2;
                break;
            case 2:
                OneDeskCard.cardsar[i].suit=3;
                break;
            case 3:
                OneDeskCard.cardsar[i].suit=4;
                break;
        }
        switch (i%13) {
            case 0:
                OneDeskCard.cardsar[i].rank=2;
                break;
            case 1:
                 OneDeskCard.cardsar[i].rank=3;
                break;
            case 2:
                 OneDeskCard.cardsar[i].rank=4;
                break;
            case 3:
                 OneDeskCard.cardsar[i].rank=5;
                break;
            case 4:
                 OneDeskCard.cardsar[i].rank=6;
                break;
            case 5:
                 OneDeskCard.cardsar[i].rank=7;
                break;
            case 6:
                 OneDeskCard.cardsar[i].rank=8;
                break;
            case 7:
                 OneDeskCard.cardsar[i].rank=9;
                break;
            case 8:
                 OneDeskCard.cardsar[i].rank=10;
                break;
            case 9:
                 OneDeskCard.cardsar[i].rank=11;
                break;
            case 10:
                 OneDeskCard.cardsar[i].rank=12;
                break;
            case 11:
                 OneDeskCard.cardsar[i].rank=13;
                break;
            case 12:
                 OneDeskCard.cardsar[i].rank=14;
                break;
        }
    }
    return OneDeskCard;
}