#!/bin/bash

source ./utils.sh

make -s -C $SRC_DIR

printf "NORM: "
norminette $SRC_DIR > /dev/null && print_ok || print_fail

printf "print error when file does not exist: "
should_print_error sandbox/42.txt

printf "print error when file is empty: "
should_print_error sandbox/empty.txt

printf "print error when line length > 4: "
should_print_error sandbox/too_wide.txt

printf "print error when line length < 4: "
should_print_error sandbox/too_narrow.txt

printf "print error when more than 4 lines: "
should_print_error sandbox/too_high.txt

printf "print error when less than 4 lines: "
should_print_error sandbox/too_short.txt

printf "print error when there is no newline separating 4x4 square: "
should_print_error sandbox/no_nl_separator.txt

printf "print error when there are too many newlines separating 4x4 square: "
should_print_error sandbox/too_many_nl.txt

printf "print error when there are more than 4 blocks: "
should_print_error sandbox/more_than_4_blocks.txt

printf "print error when there are less than 4 blocks: "
should_print_error sandbox/less_than_4_blocks.txt

printf "print error when there is an invalid char: "
should_print_error sandbox/invalid_char.txt

printf "print error when blocks are not stick together (1): "
should_print_error sandbox/blocks_not_stick_together_1.txt

printf "print error when blocks are not stick together (2): "
should_print_error sandbox/blocks_not_stick_together_2.txt

printf "1 Tetrimino: "
should_be_the_same sandbox/one_tetrimino.txt sandbox/one_tetrimino.txt.correct

printf "4 Tetriminos: "
should_be_the_same sandbox/four_tetriminos.txt sandbox/four_tetriminos.txt.correct

printf "8 Tetriminos: "
should_be_the_same sandbox/eight_tetriminos.txt sandbox/eight_tetriminos.txt.correct
