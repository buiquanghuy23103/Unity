#!/bin/bash

source ./utils.sh

make -s -C $SRC_DIR

printf "NORM: "
norminette $SRC_DIR > /dev/null && print_ok || print_fail

printf "print error when file does not exist: "
should_print_error 42.txt

printf "print error when file is empty: "
should_print_error empty.txt

printf "print error when line length > 4: "
should_print_error too_wide.txt

printf "print error when line length < 4: "
should_print_error too_narrow.txt

printf "print error when more than 4 lines: "
should_print_error too_high.txt

printf "print error when less than 4 lines: "
should_print_error too_short.txt

printf "print error when there is no newline separating 4x4 square: "
should_print_error no_nl_separator.txt

printf "print error when there are too many newlines separating 4x4 square: "
should_print_error too_many_nl.txt

printf "print error when there are more than 4 blocks: "
should_print_error more_than_4_blocks.txt

printf "print error when there are less than 4 blocks: "
should_print_error less_than_4_blocks.txt

printf "print error when there is an invalid char: "
should_print_error invalid_char.txt

printf "print error when blocks are not stick together (1): "
should_print_error blocks_not_stick_together_1.txt

printf "print error when blocks are not stick together (2): "
should_print_error blocks_not_stick_together_2.txt

printf "1 Tetrimino: "
should_be_the_same one_tetrimino.txt one_tetrimino.txt.correct

printf "4 Tetriminos: "
should_be_the_same four_tetriminos.txt four_tetriminos.txt.correct

printf "8 Tetriminos: "
should_be_the_same eight_tetriminos.txt eight_tetriminos.txt.correct