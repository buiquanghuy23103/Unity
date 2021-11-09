# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=../

CFLAGS = -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
CFLAGS += -Wconversion
CFLAGS += -L. -lft

TEST_DIR=test
TEST_RUNNER_DIR=test_runners
TARGET_DIR=targets

TESTS=$(shell find $(TEST_DIR) -name '*.c')
TEST_RUNNERS=$(TESTS:$(TEST_DIR)/%.c=$(TEST_RUNNER_DIR)/%_Runner.c)
TARGETS=$(TESTS:$(TEST_DIR)/%.c=$(TARGET_DIR)/%$(TARGET_EXTENSION))

TARGET_BASE=test
TARGET = $(TARGET_BASE)$(TARGET_EXTENSION)
SRC_FILES=$(UNITY_ROOT)/src/unity.c $(TESTS) $(TEST_RUNNERS)
TEST_LIB=$(UNITY_ROOT)/src/unity.c 
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I.
SYMBOLS=

all: clean default

default: $(TARGETS)

$(TARGET_DIR)/%$(TARGET_EXTENSION): $(TEST_RUNNER_DIR)/%_Runner.c $(TEST_DIR)/%.c
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(TEST_LIB) $^ -o $@

$(TEST_RUNNER_DIR)/%_Runner.c: $(TEST_DIR)/%.c 
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb $^ $@

clean:
	$(CLEANUP) $(TARGET_DIR)/* 
