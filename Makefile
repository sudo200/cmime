
CFLAGS:=-g #-s

all:

ifeq ($(wildcard out),)

	mkdir out
endif
	$(CC) -I./include -o"./out/cmime" ./src/*.c ./test/*.c $(CFLAGS)

clean:
	rm -rf ./out

.PHONY: clean

