#include "header.h"
void two_swap(card* card_1,card* card_2);
Player* initialize_all_players (int player_number,card* card_p,struct Game_info* game_info,int initial_cards){
    //initialize the parameter
    Player *p=(Player *)malloc(((unsigned int)player_number+1)*sizeof(Player));
    for (int i=0;i<player_number;i++) {
        (*(p+i)).playernumber=i+1;
        (*(p+i)).hand_card_left=0;
        p[i].order=i+1;
        p[i].HandCard=(card*)malloc(2*sizeof(card));
        p[i].point=0;
    }
    //give every player a card to decide their play order
    for (int i=0;i<player_number;i++) {
        give_card(p,card_p,i,game_info);
        game_info->card_left=draw_card(card_p,game_info);
    }
    //the exchange array is used to exchange with the order(since the card of the player can not change)
    card *exchangee=(card *)calloc((unsigned int)player_number+2,sizeof(card));
    for (int i=0;i<player_number;i++){
        (*(exchangee+i)).rank=(*(p+i)).HandCard[0].rank;
        (*(exchangee+i)).suit=(*(p+i)).HandCard[0].suit;
    }
    //exchange their order regarding to the first card their get
    for (int i = 0; i<player_number - 1; i++)
        for (int j = 0; j < player_number - i - 1; j++)
        {
            if ((*(exchangee+j)).suit > (*(exchangee+j+1)).suit) {
                two_swap(exchangee+j,exchangee+j+1);
                int temp=(*(p+j)).order;
                //printf("%d\n",temp);
                (*(p+j)).order=(*(p+j+1)).order;
                (*(p+j+1)).order=temp;

            }
            else if((*(exchangee+j)).suit == (*(exchangee+j+1)).suit) {
                if (exchangee[j].rank > exchangee[j+1].rank) {
                    two_swap(exchangee+j,exchangee+j+1);
                    int temp = (*(p + j)).order;
                    //printf("%d\n",temp);
                    (*(p + j)).order = (*(p + j + 1)).order;
                    (*(p + j + 1)).order = temp;
                }
            }
        }
    free(exchangee);
   //disp the order
   //for (int i=0;i<player_number;i++)
   //{
   //    printf("\nplayer %d order %d\n",(*(p+i)).playernumber,(*(p+i)).order);
   //}
   //throw every player's first card into the discard pile
   for (int i=0;i<player_number;i++)
   {
       (p+i)->HandCard[0].rank=0;
       (p+i)->HandCard[0].suit=0;
       (p+i)->HandCard[0].position=3;
       (p+i)->hand_card_left--;
   }
   //give card to player
    for (int i=0;i<player_number;i++) {
        for (int j = 0; j < initial_cards; j++){
            give_card(p, card_p, i, game_info);
            game_info->card_left = draw_card(card_p, game_info);
        }
    }
    //make p[0].order=1 p[1].order=1 ...
    regive_order(p,player_number);
    return p;
}
void two_swap(card* card_1,card* card_2){
    int temp=(*card_1).suit;
    (*card_1).suit=(*card_2).suit;
    (*card_2).suit=temp;
    temp=(*card_1).rank;
    (*card_1).rank=(*card_2).rank;
    (*card_2).rank=temp;
}
