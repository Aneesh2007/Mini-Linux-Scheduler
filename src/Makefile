CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -g
TARGET  = scheduler
SRCS    = main.c input.c output.c fcfs.c sjf.c srtf.c rr.c
OBJS    = $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c scheduler.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
