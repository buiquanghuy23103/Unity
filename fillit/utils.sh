#!/bin/bash

DARKGRAY='\033[1;30m'
RED='\033[0;31m'    
LIGHTRED='\033[1;31m'
GREEN='\033[0;32m'    
YELLOW='\033[1;33m'
BLUE='\033[0;34m'    
PURPLE='\033[0;35m'    
LIGHTPURPLE='\033[1;35m'
CYAN='\033[0;36m'    
WHITE='\033[1;37m'
RESET='\033[0m'

SRC_DIR=/Users/huybui/core_studies/fillit
EXE=$SRC_DIR/fillit
ACTUAL=actual.log

print_ok() {
	printf "${GREEN}OK${RESET}\n"
}

should_print_error() {
	$EXE $1 > $ACTUAL
	printf "${RED}"
	diff error $ACTUAL && print_ok
	printf "${RESET}"
	rm $ACTUAL
}
