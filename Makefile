CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -I/ncurses/include/ncurses
LIBFLAG = -lncurses

SRC_DIRS = system item profile save step step/mage step/golem step/chevalier

SRC_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
SRC_FILES += readint.c

OBJ_FILES := $(SRC_FILES:.c=.o)

TARGET = adventure

all: $(TARGET)

$(TARGET): main.o $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFLAG)

%.o: %.c system/sys.h system/type.h readint.h
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBFLAG)
clean:
	rm -f $(OBJ_FILES) $(TARGET)

