CLEANUP = rm -rf
TARGET_EXTENSION=.out
C_COMPILER=gcc

UNITY_ROOT=../

CFLAGS = -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -Wconversion
CFLAGS += -L. -lft

TEST_DIR=test
TEST_RUNNER_DIR=test_runners
TARGET_DIR=targets

TESTS=$(shell find $(TEST_DIR) -name '*.c')
TEST_RUNNERS=$(TESTS:$(TEST_DIR)/%.c=$(TEST_RUNNER_DIR)/%_Runner.c)
TARGETS=$(TESTS:$(TEST_DIR)/%.c=$(TARGET_DIR)/%$(TARGET_EXTENSION))

TEST_LIB=$(UNITY_ROOT)/src/*.c 
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I.

all: clean default

default: $(TARGETS)

$(TARGET_DIR)/%$(TARGET_EXTENSION): $(TEST_RUNNER_DIR)/%_Runner.c $(TEST_DIR)/%.c
	mkdir -p $(TARGET_DIR)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(TEST_LIB) $^ -o $@

$(TEST_RUNNER_DIR)/%_Runner.c: $(TEST_DIR)/%.c 
	mkdir -p $(TEST_RUNNER_DIR)
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb $^ $@

clean:
	$(CLEANUP) $(TARGET_DIR) $(TEST_RUNNER_DIR)
