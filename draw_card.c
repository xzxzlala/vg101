#include "header.h"
int draw_card(card* shuffle_card_pile,struct Game_info* game_info){
    int i=game_info->card_left-1;
    //del the last card from the stock pile
    (*(shuffle_card_pile+i)).suit=0;
    (*(shuffle_card_pile+i)).rank=0;
    (*(shuffle_card_pile+i)).position=0;
    return i;
}