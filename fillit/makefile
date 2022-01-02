CLEANUP = rm -rf
TARGET_EXTENSION=.out
C_COMPILER=clang

RED=\e[0;31m
GREEN=\e[0;32m
RESET=\e[0m

UNITY_ROOT=..
TEST_DIR=unit_tests
TEST_RUNNER_DIR=test_runners
TARGET_DIR=targets
SRC_DIR=../../fillit
LIBFT_DIR=$(SRC_DIR)/libft
LOG=log

CFLAGS = -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -DUNITY_OUTPUT_COLOR
CFLAGS += -L$(LIBFT_DIR) -lft

TESTS=$(shell find $(TEST_DIR) -name '*.c' -follow -print)
TEST_RUNNERS=$(TESTS:$(TEST_DIR)/%.c=$(TEST_RUNNER_DIR)/%_Runner.c)
TARGETS=$(TESTS:$(TEST_DIR)/%.c=$(TARGET_DIR)/%$(TARGET_EXTENSION))

TEST_LIB=$(UNITY_ROOT)/src/*.c 
INC_DIRS=-I$(UNITY_ROOT)/src -I$(LIBFT_DIR) -I$(SRC_DIR)

all: clean default

default: $(TARGETS)

$(TARGETS): $(TARGET_DIR)/%$(TARGET_EXTENSION): $(TEST_RUNNER_DIR)/%_Runner.c $(TEST_DIR)/%.c $(LIBFT_DIR)/libft.a
	mkdir -p $(TARGET_DIR)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(TEST_LIB) $^ -o $@
	$(shell pwd)/$@ >> $(LOG) && printf "$@: $(GREEN)OK$(RESET)\n" || printf "$@ $(RED)FAIL$(RESET)\n"

$(TEST_RUNNER_DIR)/%_Runner.c: $(TEST_DIR)/%.c 
	mkdir -p $(TEST_RUNNER_DIR)
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb $^ $@

$(LIBFT_DIR)/libft.a: $(LIBFT_DIR)/*.c $(LIBFT_DIR)/*.h
	make -s -C $(LIBFT_DIR) fclean && make -s -C $(LIBFT_DIR)

clean:
	$(CLEANUP) $(TARGET_DIR) $(TEST_RUNNER_DIR) $(LOG)
