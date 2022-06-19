SRC_DIR = discord\src

CC = gcc
CFLAGS = -Wall

SRC_FILES = \
	$(wildcard $(SRC_DIR)/*.c)
HEADER_FILES = \
	$(wildcard $(SRC_DIR)/*.h)
OUT_FILES = \
	$(SRC_FILES:%.c=%.o)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(OUT_FILES) $(HEADER_FILES)
	$(CC) -shared -o discord.dll $(OUT_FILES)

EXAMPLE_FOLDER = example
EXAMPLE_FILES = \
	$(wildcard $(EXAMPLE_FOLDER)/*.c)

example: all
	$(CC) -o example.exe $(EXAMPLE_FILES) -L. -ldiscord
	cls
	example.exe