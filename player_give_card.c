#include "header.h"
void player_give_card(struct Player* p, struct Game_info* game_info,int user_input_card_number){
    //you do not put this card into the discard pile
    //printf("\n");
    //printf("user_input_card_number%d",user_input_card_number);
    //printf("\n");
    //p[game_info->who_play_now].HandCard[user_input_card_number].suit=0;
    //p[game_info->who_play_now].HandCard[user_input_card_number].rank=0;
    //p[game_info->who_play_now].HandCard[user_input_card_number].position=3;
    for (int i=user_input_card_number ; i <= p[game_info->who_play_now].hand_card_left ; i++)
    {
        if (i==p[game_info->who_play_now].hand_card_left){break;}
        p[game_info->who_play_now].HandCard[i]=p[game_info->who_play_now].HandCard[i+1];
    }
    p[game_info->who_play_now].hand_card_left--;
    sort_card(p[game_info->who_play_now].HandCard,p[game_info->who_play_now].hand_card_left);
}