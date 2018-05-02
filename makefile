C=gcc
ASM=nasm
CFLAGS=-g -O2 -Wall -m64 
ASMFLAGS=-g -f  win64
all: main

main: main.o integral.o root.o f1.o f2.o f3.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

integral.o: integral.c
	$(CC) $(CFLAGS) -c $< -o $@

root.o: root.c
	$(CC) $(CFLAGS) -c $< -o $@

f1.o: f1.asm
	$(ASM) $(ASMFLAGS) $< -o $@

f2.o: f2.asm
	$(ASM) $(ASMFLAGS) $< -o $@

f3.o: f3.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -rf *.o 

