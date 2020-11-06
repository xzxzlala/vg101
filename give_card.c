#include "header.h"
void give_card(Player* p,card* cp,int who_draw,struct Game_info* game_info){
    p[who_draw].HandCard=(card*)realloc((*(p+who_draw)).HandCard,((unsigned int)p[who_draw].hand_card_left+1)*sizeof(card));
    int x=(*(p+who_draw)).hand_card_left;
    int ii=game_info->card_left-1;
    (*((*(p+who_draw)).HandCard+x)).rank=(*(cp+ii)).rank;
    (*((*(p+who_draw)).HandCard+x)).suit=(*(cp+ii)).suit;
    (*((*(p+who_draw)).HandCard+x)).position=2;
    (*(p+who_draw)).hand_card_left=x+1;
}
