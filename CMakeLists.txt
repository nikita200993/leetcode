cmake_minimum_required(VERSION 3.21)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)

add_executable(leetcode main.cpp
        merge_sorted_arrays.cpp merge_sorted_arrays.h
        remove_element.cpp remove_element.h
        remove_duplicates.cpp remove_duplicates.h
        remove_duplicates_2.cpp remove_duplicates_2.h
        majority_element.cpp majority_element.h
        rotate_array.cpp rotate_array.h
        best_time_to_buy_sell_stock.cpp best_time_to_buy_sell_stock.h
        best_time_to_buy_sell_stock_2.cpp best_time_to_buy_sell_stock_2.h
        jump_game.cpp jump_game.h
        jump_game_2.cpp jump_game_2.h
        h_index.cpp h_index.h RandomizedSet.cpp RandomizedSet.h product_of_array.cpp product_of_array.h)
