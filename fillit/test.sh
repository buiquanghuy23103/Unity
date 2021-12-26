#!/bin/bash

source ./utils.sh

make -s -C $SRC_DIR
SET_UP_TEST

printf "print error when file does not exist: "
should_print_error 42.txt

printf "print error when file is empty: "
should_print_error empty.txt
