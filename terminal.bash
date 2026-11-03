gcc -c main.c -o main.o
ld --oformat binary -Ttext 0x7c00 main.o -o myos.bin
