#====================================================
#ESTRUTURAS DE DADOS - 2022/01
#SISTEMAS DE INFORMAÇÃO
#ALAN AUGUSTO MARTINS CAMPOS
#TRABALHO PRÁTICO 01- POQUER
#====================================================
#IMPLEMENTAÇÃO DAS CLASSES E FUNCIONALIDADES REFERENTES AO JOGO DE PORQUER
#====================================================

CC = g++
CXXFLAGS = -g -Wall -pg

# folders
INCLUDE_FOLDER = ./include/
BIN_FOLFER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/
OUTPUT_FOLDER = ./output/

# all sourcers, obs, and header files
MAIN = main
TARGET = main
SRC = $(wildcard $(SRC_FOLDER)*.cpp)
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))
EXE = $(BIN_FOLFER)main

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all: comp run gprof

comp: $(OBJ) 
	$(CC) $(CXXFLAGS) -o $(BIN_FOLFER)$(TARGET) $(OBJ)
	
run:
	$(EXE) -o ./output/carga10.txt -w 10 -l "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	$(EXE) -o ./output/carga50.txt -w 50 -l "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	$(EXE) -o ./output/carga100.txt -w 100 -l "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	$(EXE) -o ./output/carga500.txt -w 500 -l "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	$(EXE) -o ./output/carga1000.txt -w 1000 -l "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	$(EXE) -o ./output/carga1500.txt -w 1500 -l "ABCDEFGHIJKLMNOPQRSTUVWXYZ"


gprof:
#	gprof ./bin/main gmon.out > gprof.txt

clean: 
	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLFER)* $(TARGET)
	@rm -rf $(OUTPUT_FOLDER)* 
	rm -rf gmon.out
#	rm -rf gprof.txt
	clear