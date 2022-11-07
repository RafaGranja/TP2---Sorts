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

first:

	rm -f $(SRC)/saida.txt
	$(CC) $(CFLAGS) -c $(SRC)/Quicksort.cpp -o $(OBJ)/Quicksort.o
	$(CC) $(CFLAGS) -o $(BIN)/Quicksort.exe $(OBJ)/Quicksort.o
	./$(BIN)/Quicksort.exe quicksort -v 1 -s 10 -i $(SRC)/entrada.txt -o $(SRC)/saida.txt
	./$(BIN)/Quicksort.exe quicksort -v 2 -k 3 -s 10 -i $(SRC)/entrada.txt -o $(SRC)/saida.txt
	./$(BIN)/Quicksort.exe quicksort -v 3 -m 100 -s 10 -i $(SRC)/entrada.txt -o $(SRC)/saida.txt
	./$(BIN)/Quicksort.exe quicksort -v 4 -s 10 -i $(SRC)/entrada.txt -o $(SRC)/saida.txt
	./$(BIN)/Quicksort.exe quicksort -v 5 -s 10 -i $(SRC)/entrada.txt -o $(SRC)/saida.txt

second:

	rm -f $(SRC)/saida2.txt
	$(CC) $(CFLAGS) -c $(SRC)/Quicksort.cpp -o $(OBJ)/Quicksort.o
	$(CC) $(CFLAGS) -o $(BIN)/Quicksort.exe $(OBJ)/Quicksort.o
	./$(BIN)/Quicksort.exe quicksort -v 4 -s 10 -i $(SRC)/entrada.txt -o $(SRC)/saida2.txt
	./$(BIN)/Quicksort.exe quicksort -v 6 -s 10 -i $(SRC)/entrada.txt -o $(SRC)/saida2.txt
	./$(BIN)/Quicksort.exe quicksort -v 7 -s 10 -i $(SRC)/entrada.txt -o $(SRC)/saida2.txt
	./$(BIN)/Quicksort.exe quicksort -v 4 -s 100 -i $(SRC)/entrada.txt -o $(SRC)/saida2.txt
	./$(BIN)/Quicksort.exe quicksort -v 6 -s 100 -i $(SRC)/entrada.txt -o $(SRC)/saida2.txt
	./$(BIN)/Quicksort.exe quicksort -v 7 -s 100 -i $(SRC)/entrada.txt -o $(SRC)/saida2.txt
	./$(BIN)/Quicksort.exe quicksort -v 4 -s 120 -i $(SRC)/entrada.txt -o $(SRC)/saida2.txt
	./$(BIN)/Quicksort.exe quicksort -v 6 -s 120 -i $(SRC)/entrada.txt -o $(SRC)/saida2.txt
	./$(BIN)/Quicksort.exe quicksort -v 7 -s 120 -i $(SRC)/entrada.txt -o $(SRC)/saida2.txt

