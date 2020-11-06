cmake_minimum_required(VERSION 3.17)
project(p2 C)

set(CMAKE_C_STANDARD 99)

add_executable(p2 main.c header.h draw_card.c disp_card.c initialize_index_to_card.c initialize_all_players.c give_card.c initialize_stock_pile.c shuffle_card.c sort_card.c disp_player_card.c swap_card_rankandsuit.c have_winner.c game_start.c player_give_card.c whether_play.c reinitialize_all_players.c regive_order.c player_swap.c whether_demo_play.c)