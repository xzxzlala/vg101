#include "header.h"
void reinitialize_all_players (struct Player* p,card* card_p,struct Game_info* game_info,int initial_cards){
    //set all the player's hand card left =0
    //throw all the card into discard_pile
    for (int i=0 ; i < game_info->player_number ; i++)
    {
        for (int j=0 ; j < p[i].hand_card_left ; j++)
        {
            p[i].HandCard[j].suit=0;
            p[i].HandCard[j].rank=0;
            p[i].HandCard[j].position=3;
        }
        p[i].hand_card_left=0;
    }
    //give card to player
    for (int i=0;i<game_info->player_number;i++) {
        for (int j = 0; j < initial_cards; j++){
            give_card(p, card_p, i, game_info);
            game_info->card_left = draw_card(card_p, game_info);
        }
    }
    //make p[0].order=1 p[1].order=1 ...
    regive_order(p,game_info->player_number);
}

