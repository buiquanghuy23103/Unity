CLEANUP = rm -rf
TARGET_EXTENSION=.out
C_COMPILER=clang

UNITY_ROOT=..

TEST_DIR=test
TEST_RUNNER_DIR=test_runners
TARGET_DIR=targets
SRC_DIR ?= /Users/huybui/core_studies/ft_printf

CFLAGS = -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -DUNITY_OUTPUT_COLOR
CFLAGS += -L$(SRC_DIR) -lftprintf

TESTS=$(shell find $(TEST_DIR) -name '*.c')
TEST_RUNNERS=$(TESTS:$(TEST_DIR)/%.c=$(TEST_RUNNER_DIR)/%_Runner.c)
TARGETS=$(TESTS:$(TEST_DIR)/%.c=$(TARGET_DIR)/%$(TARGET_EXTENSION))

TEST_LIB=$(UNITY_ROOT)/src/*.c 
INC_DIRS=-I$(UNITY_ROOT)/src -I$(SRC_DIR)/libft -I$(SRC_DIR)

all: clean default

default: $(SRC_DIR)/libftprintf.a $(TARGETS)

$(TARGET_DIR)/%$(TARGET_EXTENSION): $(TEST_RUNNER_DIR)/%_Runner.c $(TEST_DIR)/%.c 
	mkdir -p $(TARGET_DIR)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(TEST_LIB) $^ -o $@
	$(shell pwd)/$@

$(TEST_RUNNER_DIR)/%_Runner.c: $(TEST_DIR)/%.c 
	mkdir -p $(TEST_RUNNER_DIR)
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb $^ $@

$(SRC_DIR)/libftprintf.a: $(SRC_DIR)/*
	make -sC $(SRC_DIR)

clean:
	$(CLEANUP) $(TARGET_DIR) $(TEST_RUNNER_DIR)
