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
LOGDATE = $(shell date +"%b/%d at %kh:%Mm")

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all: comp run gprof

comp: $(OBJ) 
	$(CC) $(CXXFLAGS) -o $(BIN_FOLFER)$(TARGET) $(OBJ)
	
run:
	./bin/main

gprof:
#	gprof ./bin/main gmon.out > gprof.txt

clean: 
	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLFER)* $(TARGET)
	rm -rf $(OUTPUT_FOLDER) 
	rm -rf gmon.out
#	rm -rf gprof.txt
	clear

git:
	git add .
	@echo "your commit text: "; \
    read AGE ;\
	git commit -m "Update $(LOGDATE) - $$AGE"
	git push