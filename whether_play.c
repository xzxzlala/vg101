#include "header.h"
void get_the_attack_card(struct Game_info* game_info,struct Player* p,card* card_p);
void whether_play(struct Game_info* game_info,struct Player* p,card* card_p){
    /*for (int test1=0 ; test1 < game_info->player_number ; test1++){
        printf("\n\nplayer%d\n\n",p[test1].playernumber);
        for (int test2=0 ; test2 < p[test1].hand_card_left ; test2++)
        {
            printf("%d",test2);
            disp_card(p[test1].HandCard[test2]);
            printf("\n");
        }
    }*/
    int flag=0;
    int can_he_play=0;
    //can he play a card?
    if (game_info->current_attack==0) {
        for (int i = 0; i < p[game_info->who_play_now].hand_card_left; i++) {
            if (game_info->previous_card.rank == p[game_info->who_play_now].HandCard[i].rank) { can_he_play = 1; }
            if (game_info->previous_card.suit == p[game_info->who_play_now].HandCard[i].suit) { can_he_play = 1; }
        }
    }
    else
    {
        printf("Current Attack is %d\n",game_info->current_attack);
        for (int i = 0; i < p[game_info->who_play_now].hand_card_left; i++) {
            if (game_info->previous_card.rank == p[game_info->who_play_now].HandCard[i].rank )
            { can_he_play = 1; }
            if (game_info->previous_card.suit == p[game_info->who_play_now].HandCard[i].suit && (p[game_info->who_play_now].HandCard[i].rank==2 ||p[game_info->who_play_now].HandCard[i].rank==3 || p[game_info->who_play_now].HandCard[i].rank==12|| p[game_info->who_play_now].HandCard[i].rank==11|| p[game_info->who_play_now].HandCard[i].rank==7))
            { can_he_play = 1; }
        }
    }
    if (can_he_play==1) {
        printf("Input 1 ~ %d to play a card or 0 to pass the turn and draw a card.\n",p[game_info->who_play_now].hand_card_left);
    }
    else {
        printf("No valid move! Input 0 to pass the turn.\n");
        int is_zero;
        flag=1;
        int flag2=0;
        while (flag2==0) {
            if (scanf("%d",&is_zero)) {
                if (is_zero == 0) {
                    flag2=1;
                    if (game_info->current_attack == 0) {
                        give_card(p, card_p, game_info->who_play_now, game_info);
                        game_info->card_left = draw_card(card_p, game_info);
                    } else {
                        for (int j = game_info->current_attack; j > 0; j--) {
                            give_card(p, card_p, game_info->who_play_now, game_info);
                            game_info->card_left = draw_card(card_p, game_info);
                        }
                        game_info->current_attack=0;
                    }
                }
                else {
                    printf("Invalid Input ! Try again ! \n");
                    flag=0;
                }
            }

        }
    }
    int user_input_card_number;
    card user_input_card;
    while (flag==0) {
        if (scanf("%d", &user_input_card_number)) {
            if (user_input_card_number == 0) {
                if (game_info->current_attack==0)
                {
                    give_card(p, card_p, game_info->who_play_now, game_info);
                    game_info->card_left = draw_card(card_p, game_info);
                    break;
                }
                else{
                for (int j = game_info->current_attack; j > 0; j--) {
                    give_card(p, card_p, game_info->who_play_now, game_info);
                    game_info->card_left = draw_card(card_p, game_info);
                }
                    break;
                }

            }
            user_input_card_number = user_input_card_number - 1;
            user_input_card = p[game_info->who_play_now].HandCard[user_input_card_number];
            /*
            printf("test\n");
            disp_card(user_input_card);printf("\n");
            disp_card(user_input_card);printf("\n");
            disp_card(user_input_card);printf("\n");
            printf("test\n");
            */
            if (game_info->current_attack == 0){
                if (game_info->previous_card.rank == user_input_card.rank ||
                    game_info->previous_card.suit == user_input_card.suit) {
                    switch (user_input_card.rank) {
                        case 2:
                            player_give_card(p, game_info, user_input_card_number);
                            game_info->current_attack = game_info->current_attack + 2;
                            break;
                        case 3:
                            player_give_card(p, game_info, user_input_card_number);
                            game_info->current_attack = game_info->current_attack + 3;
                            break;
                        case 4:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                        case 5:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                        case 6:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                        case 7:
                            player_give_card(p, game_info, user_input_card_number);
                            game_info->current_attack = 0;
                            break;
                        case 8:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                        case 9:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                        case 10:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                        case 11:
                            player_give_card(p, game_info, user_input_card_number);
                            game_info->next_player = game_info->next_player + game_info->sign_of_game * 1;
                            break;
                        case 12:
                            player_give_card(p, game_info, user_input_card_number);
                            game_info->sign_of_game = -game_info->sign_of_game;
                            game_info->next_player=game_info->next_player+ 2 * game_info->sign_of_game;
                            break;
                        case 13:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                        case 14:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                    }
                    flag = 1;
                    game_info->previous_card = user_input_card;
                } else {
                    printf("Invalid Input ! Try again ! \n");
                    flag = 0;
                }
        }
            else {
                if (((user_input_card.rank == 2 || user_input_card.rank == 3 ||
                        user_input_card.rank == 11 || user_input_card.rank == 12 || user_input_card.rank == 7
                        ) && game_info->previous_card.suit == user_input_card.suit ) ||
                    game_info->previous_card.rank == user_input_card.rank
                    ) {
                    switch (user_input_card.rank) {
                        case 2:
                            player_give_card(p, game_info, user_input_card_number);
                            game_info->current_attack = game_info->current_attack + 2;
                            break;
                        case 3:
                            player_give_card(p, game_info, user_input_card_number);
                            game_info->current_attack = game_info->current_attack + 3;
                            break;
                        case 4:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                        case 5:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                        case 6:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                        case 7:
                            player_give_card(p, game_info, user_input_card_number);
                            game_info->current_attack = 0;
                            break;
                        case 8:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                        case 9:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                        case 10:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                        case 11:
                            player_give_card(p, game_info, user_input_card_number);
                            game_info->next_player = game_info->next_player + game_info->sign_of_game * 1;
                            break;
                        case 12:
                            player_give_card(p, game_info, user_input_card_number);
                            game_info->sign_of_game = -game_info->sign_of_game;
                            game_info->next_player=game_info->next_player+ 2 * game_info->sign_of_game;
                            break;
                        case 13:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                        case 14:
                            player_give_card(p, game_info, user_input_card_number);
                            break;
                    }
                    flag = 1;
                    game_info->previous_card = user_input_card;
                } else {
                    printf("Invalid Input ! Try again ! \n");
                    flag = 0;
                }
            }
        }
    }
}
void get_the_attack_card(struct Game_info* game_info,struct Player* p,card* card_p){
for (int j = game_info->current_attack; j > 0; j--) {
give_card(p, card_p, game_info->who_play_now, game_info);
game_info->card_left = draw_card(card_p, game_info);
}
}
