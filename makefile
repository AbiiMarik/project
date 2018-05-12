CC=gcc
ASM=nasm
CFLAGS=-g -O2 -m32
ASMFLAGS=-g -f  elf32
all: main

main: main.o integral.o root.o f.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

integral.o: integral.c
	$(CC) $(CFLAGS) -c $< -o $@

root.o: root.c
	$(CC) $(CFLAGS) -c $< -o $@

f.o: f.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -rf *.o main

