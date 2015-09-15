# Copyright (c) Elijah Jensen 2015. All Rights Reserved.
# See LICENSE file (MIT)
# ReTFeT/Makefile

CC     = gcc
CFlags = -std=c11 -lm # --static NA with clang?

Exe = test
Src = main.o

$(Exe): $(Src)
	$(CC) -o $(Exe) $(Src) $(CFlags)

%.o: %.c %.h
	$(CC) -o $@ -c $< $(CFlags)

clean:
	rm -rf *.o

.PHONY: clean

