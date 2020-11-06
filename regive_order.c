#include "header.h"
void regive_order(struct Player* p,const int player_number){
    for (int i = 0; i < player_number - 1; i++)
        for (int j = 0; j < player_number - i - 1; j++)
        {
            //printf("original%d %d\n",p[j].order,p[j+1].order);
            if (p[j].order > p[j+1].order) {
                player_swap(&p[j],&p[j+1]);
                //printf("after%d %d\n",p[j].order,p[j+1].order);
            }
        }
}