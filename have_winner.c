#include "header.h"
int have_winner(Player* p,struct Game_info* game_info){
    int return_value=0;
   if (p[game_info->who_play_now].hand_card_left == 0){
        for (int i=0 ; i < game_info->player_number ; i++)
        {
            p[i].point=p[i].point-p[i].hand_card_left;
        }
        return_value=1;
        game_info->rounds_now=game_info->rounds_now-1;
        printf("Player %d Win This Round\n",p[game_info->who_play_now].playernumber);
        system("pause");
        game_info->next_player=game_info->who_play_now;
   }
   if (game_info->rounds_now==0){
       int flag=0;
       for (int i=0;i<game_info->player_number;i++)
       {
           if (p[flag].point<p[i].point)
           {
               flag=i;
           }
       }
       printf("Player %d is the WINNER !!! \n",p[flag].playernumber);
       return_value=2;
   }
    return return_value;
}