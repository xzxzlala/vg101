#include "header.h"
void player_swap(struct Player*p1,struct Player*p2){
    struct Player temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}