#include "header.h"
void disp_player_card(Player* p,int who_play_card_now){
    sort_card(p[who_play_card_now].HandCard,p[who_play_card_now].hand_card_left);
    //printf("player%d",p[who_play_card_now].playernumber);
    for (int i=0,j=0;i<(*(p+who_play_card_now)).hand_card_left;i++,j++){
        if(j%5==0){printf("\n");}
        //printf("%d\n",i);
        disp_card((*(p+who_play_card_now)).HandCard[i]);
    }
    printf("\n");
}