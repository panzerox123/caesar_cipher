Caesar_Cypher_1.0.0: cypher.o main_window.o
	gcc main_window.o cypher.o -o "Caesar_Cypher_1.0.0" `pkg-config --cflags --libs gtk+-3.0`

main_window.o: main_window.c cypher.h
	gcc -c main_window.c `pkg-config --cflags --libs gtk+-3.0`

cypher.o: cypher.c cypher.h
	gcc -c cypher.c