# Copyright (c) 2014 Christopher Swenson.

CC ?= gcc
CFLAGS = -O3 -g -Wall -std=c89

default: test

.PHONY: default test

test: demo
	./demo

clean:
	rm -f demo

demo: demo.c vector.h
	$(CC) $(CFLAGS) demo.c -o demo

format:
	astyle --options=astyle.options vector.h demo.c

