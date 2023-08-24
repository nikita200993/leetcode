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
        h_index.cpp h_index.h
        RandomizedSet.cpp RandomizedSet.h
        product_of_array.cpp product_of_array.h
        gas_station.cpp gas_station.h
        candy.cpp candy.h
        trapping_rain_water.cpp trapping_rain_water.h
        roman_to_int.cpp roman_to_int.h
        int_to_roman.cpp int_to_roman.h
        length_of_last_word.cpp length_of_last_word.h
        common_prefix.cpp common_prefix.h
        reverse_words_string.cpp reverse_words_string.h
        zig_zag.cpp zig_zag.h
        find_substring.cpp find_substring.h text_justification.cpp text_justification.h palindrom.cpp palindrom.h subsequence.cpp subsequence.h two_sum_2_sorted.cpp two_sum_2_sorted.h container_with_most_water.cpp container_with_most_water.h three_sum.cpp three_sum.h min_subarray_sub.cpp min_subarray_sub.h longest_substring_without_repeat.cpp longest_substring_without_repeat.h substring_with_concat.cpp substring_with_concat.h min_window_substring.cpp min_window_substring.h sudoku.cpp sudoku.h spiral.cpp spiral.h)
