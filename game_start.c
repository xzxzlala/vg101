#include "header.h"
void game_start(Player* p,struct Game_info* game_info,card* card_p){
    if (game_info->auto_or_not==0) {
        printf("----Player %d's Round----\n", p[game_info->who_play_now].playernumber);
        int j = game_info->who_play_now;
        if (game_info->sign_of_game == 1) {
            for (int i = 0; i < game_info->player_number; i++, j++) {
                if (j >= game_info->player_number) { j = j - game_info->player_number; }
                printf("Player %d has %d card(s)\n", p[j].playernumber, p[j].hand_card_left);
            }
        } else {
            for (int i = 0; i < game_info->player_number; i++, j = j - 1) {
                if (j < 0) { j = game_info->player_number - 1; }
                printf("Player %d has %d card(s)\n", p[j].playernumber, p[j].hand_card_left);
            }

        }

        printf("Current Attack : %d\n", game_info->current_attack);
        printf("The previous card is ");
        disp_card(game_info->previous_card);
        printf("\n");
        printf("Player %d's card(s) : ", p[game_info->who_play_now].playernumber);
        disp_player_card(p, game_info->who_play_now);
        whether_play(game_info, p, card_p);
    }
    else
    {
        printf("----Player %d's Round----\n", p[game_info->who_play_now].playernumber);
        int j = game_info->who_play_now;
        if (game_info->sign_of_game == 1) {
            for (int i = 0; i < game_info->player_number; i++, j++) {
                if (j >= game_info->player_number) { j = j - game_info->player_number; }
                printf("Player %d has %d card(s)\n", p[j].playernumber, p[j].hand_card_left);
            }
        } else {
            for (int i = 0; i < game_info->player_number; i++, j = j - 1) {
                if (j < 0) { j = game_info->player_number - 1; }
                printf("Player %d has %d card(s)\n", p[j].playernumber, p[j].hand_card_left);
            }

        }

        printf("Current Attack : %d\n", game_info->current_attack);
        printf("The previous card is ");
        disp_card(game_info->previous_card);
        printf("\n");
        printf("Player %d's card(s) : ", p[game_info->who_play_now].playernumber);
        disp_player_card(p, game_info->who_play_now);
        whether_demo_play(game_info, p, card_p);
    }
}