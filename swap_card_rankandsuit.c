#include "header.h"
void swap(card* card_p,int a){
    int temps = (*(card_p+a)).suit;
    (*(card_p+a)).suit = (*(card_p+a+1)).suit;
    (*(card_p+a+1)).suit = temps;
    int tempr = (*(card_p+a)).rank;
    (*(card_p+a)).rank = (*(card_p+a+1)).rank;
    (*(card_p+a+1)).rank = tempr;
}