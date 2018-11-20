CC ?= gcc
CFLAGS = -O3 -MMD -std=c99
CFLAGS_TEST = -MMD -std=c99
LIBS = 
LIBS_TEST = -lcriterion

BIN_TEST = test

MKDIR = /bin/mkdir -p
RM = /bin/rm -f

BUILD_DIR = ./build
OBJECTS_DIR = $(BUILD_DIR)/objects
BIN_DIR = $(BUILD_DIR)/bin

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:%.c=$(OBJECTS_DIR)/%.o)
DEPS = $(OBJS:%.o=%.d)

TESTS = $(wildcard test/*.c)

all: FLAGS = $(CFLAGS)
all: $(OBJS)

test: FLAGS = $(CFLAGS_TEST)
test: $(BIN_DIR)/$(BIN_TEST)

$(BIN_DIR)/$(BIN_TEST): $(OBJS) $(TESTS) 
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS_TEST) $^ -o $@ $(LIBS_TEST)

-include $(DEPS)

$(OBJECTS_DIR)/%.o: %.c
	$(MKDIR) $(@D)
	$(CC) $(FLAGS) -c $< -o $@

.PHONY : clean
clean:
	$(RM) -r $(BUILD_DIR)
