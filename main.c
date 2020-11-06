#ifdef __WIN32
#define CLEAR() do { system("cls"); } while ((void)0, 0)
#else
#define CLEAR() do { system("clear"); } while ((void)0, 0)
#endif
#include "header.h"
int main(int argc, char *argv[]) {
    srand((unsigned int) time(NULL));
    setbuf(stdout, NULL); /* I use this to debug in clion , you can ignore it*/

    //command line part
    //this part will get the
    int opt, option_index = 0;
    char *string = "hl:n:c:d:r:asm";
    char filename[30] = {0};
    struct Game_info game_info;
    game_info.player_number = 4;
    game_info.rounds_now=1;
    int initial_cards = 5, desks = 2, rounds = 1, help_or_not = 0, auto_or_not = 0, ascii_or_not = 0, multi_or_not = 0;
    static struct option long_options[] =
            {
                    {"help",          no_argument,       NULL, 'h'},
                    {"log",           required_argument, NULL, 'l'},
                    {"player_number", required_argument, NULL, 'n'},
                    {"initial_cards", required_argument, NULL, 'c'},
                    {"desks",         required_argument, NULL, 'd'},
                    {"rounds",        required_argument, NULL, 'r'},
                    {"auto",          no_argument,       NULL, 'a'},
                    {"no_ascii",      no_argument,       NULL, 's'},
                    {"multi",         no_argument,       NULL, 'm'},
            };
    while ((opt = getopt_long(argc, argv, string, long_options, &option_index)) != -1) {
        switch (opt) {
            case 'h' :
                help_or_not = 1;
                break;
            case 'a' :
                auto_or_not = 1; game_info.auto_or_not = 1;
                break;
            case 's' :
                ascii_or_not = 1;
                break;
            case 'm' :
                multi_or_not = 1;
                break;
            case 'n' :
                game_info.player_number = atoi(optarg);
                break;
            case 'c' :
                initial_cards = atoi(optarg);
                break;
            case 'd' :
                desks = atoi(optarg);
                break;
            case 'r' :
                rounds = atoi(optarg);
                game_info.rounds_now = rounds;
                break;
            case 'l' :
                strcat(filename, optarg);
                break;
            default :
                break;
        }
    }
    //printf("desks,initial_cards,player_number,rounds\n");
    //scanf("%d %d %d %d",&desks,&initial_cards,&game_info.player_number,&game_info.rounds_now);
    printf("auto\n");
    scanf("%d",&game_info.auto_or_not);
    rounds = game_info.rounds_now;
    auto_or_not=game_info.rounds_now;
    if (help_or_not == 1) {
        printf("-h  |  --help            print this help message\n");
        printf("-log filename           write the logs in filename (default: onecard.log)\n");
        printf("-n n|--player_number=n  n players, n must be larger than 2 (default: 4)\n");
        printf("-c c|--initial_cards=c  deal c cards per player, c must be at least 2 (default: 5)\n");
        printf("-d d|--decks=d          use d decks 52 cards each, d must be at least 2 (default: 2)\n");
        printf("-r r|--rounds=r         play r rounds, r must be at least 1 (default: 1)\n");
        printf("-a  |--auto             run in demo mode\n");
        printf("--no_ascii              run without ASCII art cards\n");
        printf("--multi                 allow players play more than one card per round\n");
        return 0;
    }
    //printf("\n\n you can ignore %d%d%d\n\n", multi_or_not, ascii_or_not, auto_or_not);
    //initialize part
    game_info.card_left = desks * 52;
    struct Deskcard OneDeskCard = initialize_index_to_card(OneDeskCard);
    card *stock_pile_p;
    stock_pile_p = initialize_stock_pile(desks, OneDeskCard);
    shuffle_card(stock_pile_p, desks);
    //for (int i=0;i<game_info.card_left;i++){
    //    disp_card(*(stock_pile_p+i));
    //}
    Player *all_player_p = initialize_all_players(game_info.player_number, stock_pile_p, &game_info, initial_cards);
    //for (int i=0;i < game_info.player_number;i++){
    //    disp_player_card(all_player_p,i);
    //}
    game_info.current_attack = 0;
    //initialize finish
    //all player have their initial cards and their order
    //in the game, we need
    //1, a function to reverse the order
    //2, a function to decide which card can be played according to the previous card
    //3, a function to tell the user to input and judge whether it is Invalid
    //4, a function to count rounds and whether a player has no card
    //5, a function to calculate the whole outcome
    //this for loop , one loop one round

    game_info.who_play_now = 0;
    game_info.next_player = 1;
    game_info.sign_of_game = 1;
    game_info.previous_card.rank = stock_pile_p[game_info.card_left - 1].rank;
    game_info.previous_card.suit = stock_pile_p[game_info.card_left - 1].suit;
    game_info.previous_card.position = 3;
    game_info.card_left = draw_card(stock_pile_p, &game_info);
    //disp_card(game_info.previous_card);printf("\n");
    //disp_card(game_info.previous_card);printf("\n");
    //disp_card(game_info.previous_card);printf("\n");
    printf("########################\n"
           "#                      #\n"
           "# Welcome to One Card! #\n"
           "#                      #\n"
           "########################\n"
           "==============================================================\n");
    if (auto_or_not==0){
        for (int i = 0; i < rounds; i++) {
            printf("==========================round %d=============================\n", i);
            for (int points_i = 0; points_i < game_info.player_number; points_i++) {
                printf("Player %d's points is %d\n", all_player_p[points_i].playernumber, all_player_p[points_i].point);
            }
            while (all_player_p[game_info.who_play_now].hand_card_left != 0) {
                game_start(all_player_p, &game_info, stock_pile_p);
                int flag_win = have_winner(all_player_p, &game_info);
                if (flag_win == 1) {
                    printf("press enter to start a new round\n");
                    system("pause");
                    stock_pile_p = initialize_stock_pile(desks, OneDeskCard);
                    shuffle_card(stock_pile_p, desks);
                    reinitialize_all_players(all_player_p, stock_pile_p, &game_info, initial_cards);
                    game_info.current_attack = 0;

                }
                if (flag_win == 2) { break; }
                if (game_info.next_player > game_info.player_number - 1) {
                    game_info.next_player = game_info.next_player - game_info.player_number;
                }
                if (game_info.next_player < 0) {
                    game_info.next_player = game_info.next_player + game_info.player_number;
                }
                game_info.who_play_now = game_info.next_player;
                game_info.next_player = game_info.next_player + game_info.sign_of_game * 1;
                if (game_info.next_player > game_info.player_number - 1) {
                    game_info.next_player = game_info.next_player - game_info.player_number;
                }
                if (game_info.next_player < 0) {
                    game_info.next_player = game_info.next_player + game_info.player_number;
                }
                CLEAR();
                system("pause");
            }
        }

    } else{
        for (int i = 0; i < rounds; i++) {
            printf("==========================round %d=============================\n", i);
            for (int points_i = 0; points_i < game_info.player_number; points_i++) {
                printf("Player %d's points is %d\n", all_player_p[points_i].playernumber, all_player_p[points_i].point);
            }
            while (all_player_p[game_info.who_play_now].hand_card_left != 0) {
                game_start(all_player_p, &game_info, stock_pile_p);
                int flag_win = have_winner(all_player_p, &game_info);
                if (flag_win == 1) {
                    printf("a new round\n");
                    stock_pile_p = initialize_stock_pile(desks, OneDeskCard);
                    shuffle_card(stock_pile_p, desks);
                    reinitialize_all_players(all_player_p, stock_pile_p, &game_info, initial_cards);
                    game_info.current_attack = 0;

                }
                if (flag_win == 2) { break; }
                if (game_info.next_player > game_info.player_number - 1) {
                    game_info.next_player = game_info.next_player - game_info.player_number;
                }
                if (game_info.next_player < 0) {
                    game_info.next_player = game_info.next_player + game_info.player_number;
                }
                game_info.who_play_now = game_info.next_player;
                game_info.next_player = game_info.next_player + game_info.sign_of_game * 1;
                if (game_info.next_player > game_info.player_number - 1) {
                    game_info.next_player = game_info.next_player - game_info.player_number;
                }
                if (game_info.next_player < 0) {
                    game_info.next_player = game_info.next_player + game_info.player_number;
                }
            }
        }
    }


    for (int i=0; i < game_info.card_left ; i++) {
        free(stock_pile_p+i);
    }
    free(stock_pile_p);
    for (int i=0; i < game_info.player_number ; i++) {
        free(all_player_p+i);
    }
    free(all_player_p);
    return 0;
}