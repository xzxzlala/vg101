#ifndef P2_HEADER_H
#define P2_HEADER_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <time.h>
typedef struct card{
    //card suit
    int suit;
    //card rank
    int rank;
    //how many decks
    int deck;
    //position, 1(the stock pile) 2(the player's hand) 3(the discard pile)
    int position;
}card;
typedef struct Deskcard {
    struct card cardsar[52];
}Deskcard;
typedef struct Player{
    int point;
    int hand_card_left;
    //the order of the players
    int order;
    //somehow the "name" of the player
    int playernumber;
    //HandCard[0] for the first card the player have, HandCard[1] for the ...
    struct card *HandCard;
}Player;
typedef struct Game_info{
    card previous_card;
    int who_play_now;
    int next_player;
    int player_number;
    int current_attack;
    int card_left;
    int rounds_now;
    int sign_of_game;
    int auto_or_not;
}Game_info;
//typedef struct AllPlayer{
//    //I suppose a game won't have 20 players
//    //APlayer[0] for the first player
//    struct Player APlayer[20];
//}AllPlayer;
//functions
//relate an index to a card (suit and rank) eg: OneDeskCard[1]={'S',3}
Deskcard initialize_index_to_card(struct Deskcard OneDeskCard);
//give all the card  a card suit and rank
//StockPile initialize_pile(int desks,struct Deskcard OneDeskCard,struct StockPile AllCard);
//initialize all the players
//AllPlayer initialize_all_players(struct AllPlayer AllThePlayer,int playernum);
//display a card's suit and rank on the screen
int disp_card (card acard);
//give a card to player
//AllPlayer give_card(struct AllPlayer AllThePlayer,struct StockPile AllCard,int whoDrawtheCard);
//draw a card from the StockPile (delete the last card)
card* initialize_stock_pile (int desks,struct Deskcard OneDeskCard);
Player* initialize_all_players (int player_number,card* card_p,struct Game_info* game_info,int initial_cards);
int draw_card(card* shuffle_card_pile,struct Game_info* game_info);
void shuffle_card(card* stock_pile_p,int desks);
void give_card(Player* player_p,card* card_p,int who_draw,struct Game_info* game_info);
void sort_card(card* card_p,int n);
void disp_player_card(Player* the_player_now,int who_play_card_now);
void swap(card* card_p,int a);
//void player_play(Player* player_now);
int have_winner(Player* p,struct Game_info* game_info);
//void game_finish(Player* p,int player_number);
void game_start(Player* p,struct Game_info* game_info,card* card_p);
void player_give_card(struct Player* p,struct Game_info* game_info,int user_input_card_number);
//void player_can_or_not(card previous_card,struct Player* p,struct Game_info* game_info,int user_input_card_number);
void whether_play(struct Game_info* game_info,struct Player* p,card* card_p);
void reinitialize_all_players (struct Player* p,card* card_p,struct Game_info* game_info,int initial_cards);
void player_swap(struct Player*p1,struct Player*p2);
void regive_order(struct Player* p,const int player_number);
void whether_demo_play(struct Game_info* game_info,struct Player* p,card* card_p);
#endif //P2_HEADER_H
