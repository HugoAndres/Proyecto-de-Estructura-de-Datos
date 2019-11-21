Huffman.o: Huffman.c
	gcc Huffman.c -c
main.o: main.c
	gcc main.c -c
a.out: main.o Huffman.o
	gcc main.o Huffman.o
run:a.out
	./a.out
clean:
	rm -f a.out main.o Huffman.o
