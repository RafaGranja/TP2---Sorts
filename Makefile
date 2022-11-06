#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa matop
# Autor		: Rafael Granja (rafaelgranja2003@ufmg.br)
# Histórico	: 2022-11-06 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo   
#			: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
CFLAGS = -pg -Wall 
SRC = src
BIN = bin
OBJ = obj
INC = include
clean:
	rm -f $(BIN)/*
	rm -f $(OBJ)/*

all:

	$(CC) $(CFLAGS) -c $(SRC)/Quicksort.cpp -o $(OBJ)/Quicksort.o
	$(CC) $(CFLAGS) -o $(BIN)/Quicksort.exe $(OBJ)/Quicksort.o
	./$(BIN)/Quicksort.exe quicksort -v 1 -s 10 -i $(SRC)/entrada.txt -o $(SRC)/saida.txt
	./$(BIN)/Quicksort.exe quicksort -v 2 -k 3 -s 10 -i $(SRC)/entrada.txt -o $(SRC)/saida.txt
	./$(BIN)/Quicksort.exe quicksort -v 3 -m 100 -s 10 -i $(SRC)/entrada.txt -o $(SRC)/saida.txt
	./$(BIN)/Quicksort.exe quicksort -v 4 -s 10 -i $(SRC)/entrada.txt -o $(SRC)/saida.txt
	./$(BIN)/Quicksort.exe quicksort -v 5 -s 10 -i $(SRC)/entrada.txt -o $(SRC)/saida.txt