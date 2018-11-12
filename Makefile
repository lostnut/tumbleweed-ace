CC = clang
CFLAGS = -O3
BIN = tumbleweed-ace

MKDIR = /bin/mkdir -p
RM = /bin/rm -f

BUILD_DIR = ./build
OBJECTS_DIR = $(BUILD_DIR)/objects
BIN_DIR = $(BUILD_DIR)/bin

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:%.c=$(OBJECTS_DIR)/%.o)
DEPS = $(OBJS:%.o=%.d)

all: $(BIN_DIR)/$(BIN)

$(BIN_DIR)/$(BIN): $(OBJS)
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) $^ -o $@

-include $(DEPS)

$(OBJECTS_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

.PHONY : clean
clean:
	$(RM) -r $(BUILD_DIR)
