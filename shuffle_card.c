#include "header.h"
void shuffle_card(card* stock_pile_p,int desks){
    //generate a random int array
    int num=desks*52;
    int i,j;
    int *ran = (int*)calloc((unsigned int)desks*52,sizeof(int));
    for(i=0;i<num;i++)
    {
        ran[i]=rand()%num;
        int flag=1;
        while(flag==1)
        {
            for(j=0;j<i;j++)
                if(ran[i]==ran[j])
                    break;
            if(j<i)
                ran[i]=rand()%num;
            if(j==i)
                flag=0;
        }
    }
    card *p=(card *)malloc(52*(unsigned int)desks*sizeof(card));
    for(i=0;i<num;i++){
        *(p+ran[i])=*(stock_pile_p+i);
    }
    for(i=0;i<num;i++){
        *(stock_pile_p+i)=*(p+i);
    }
    free(p);
}
