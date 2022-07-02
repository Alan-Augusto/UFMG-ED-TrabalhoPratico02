#include <iostream>
#include <string>
#include <cstring>
#include <getopt.h>
#include <fstream>
#include <analisador.h>
#include "memlog.h"
#include "msgassert.h"

using namespace std;

char *inputNameArq = NULL;
char *outputNameArq  = NULL;
int M;
int S;

void Assert(bool x, string text){
    if(!x){
        cout << text << endl;
        exit(0);
    }
}

void parse_args(int argc,char ** argv){
     // variaveis externas do getopt
     extern char * optarg;
 
     // variavel auxiliar
     int c;

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "i:I:o:O:m:M:s:S:l:")) != EOF)
       switch(c) {
         case 'i':
            inputNameArq = optarg;
            break;

         case 'I':
            inputNameArq = optarg;
            break;

         case 'o':
            outputNameArq = optarg;
            break;

         case 'O':
            outputNameArq = optarg;
            break;

         case 'm':
            M = atoi(optarg);
            break;

         case 'M':
            M = atoi(optarg);
            break;

         case 's':
            S = atoi(optarg);
            break;

         case 'S':
            S = atoi(optarg);
            break;

         default:
                  exit(1);

       }
}


int main(int argc, char ** argv){
   // Avaliar linha de comando
   parse_args(argc,argv);

   // inicia registro de acesso
   string lognome = "/tmp/memlog.out";
   int n = lognome.length();
   char char_array[n + 1];
   strcpy(char_array, lognome.c_str());
   iniciaMemLog(&char_array[0]);
   ativaMemLog();

   //Abertura dos arquivos
   ifstream InputFile(inputNameArq);
   Assert(InputFile.is_open(), "Opening error in input file");

      //====MEMLOG --> FASE 0====
      defineFaseMemLog(0);
      //Registra apenas a variável do texto

//VARIÁVEIS
   //Texto a ser lido:
   Text T;
   //escreveMemLog((long int)(&(T)),sizeof(Text), 0);
   //Informação que será recolhida
   string information;
   //Vai receber cada linha.
   string line;
   getline(InputFile, information);
   

   //Se a primeira informação for o texto
   if(information == "#TEXTO"){
      //====MEMLOG --> FASE 1====
      //defineFaseMemLog(0);
      //Registra os inputs do texto

      //Recolhe primeiro o texto depois a ordem
      T.InputText(InputFile);
      T.InputOrder(InputFile);
      
      //====MEMLOG --> FASE 2====
      //defineFaseMemLog(0);
      //Registra a tradução das palavras

      //Faz a tradução das palavras de acordo com a ordem lexicográfica
      T.SetOrder();
   }
   else if(information == "#ORDEM"){
      //====MEMLOG --> FASE 1====
      //defineFaseMemLog(0);
      //Registra os inputs do texto

      //Recolhe primeiro a ordem depois o texto
      T.InputOrder(InputFile);
      T.InputText(InputFile);
      
      //====MEMLOG --> FASE 2====
      //defineFaseMemLog(0);
      //Registra a tradução das palavras

      //Faz a tradução das palavras de acordo com a ordem lexicográfica
      T.SetOrder();
   }
   
   //====MEMLOG --> FASE 3====
   //defineFaseMemLog(3);
   //Registra a ordenação das palavras

   //Realiza a ordenação do vetor de palavras de acordo com a ordem lexicográfica
   quicksort(T.words, T.size, M, S);
   
   //Abre o arquivo de saída
   ofstream OutputFile(outputNameArq);
   Assert(OutputFile.is_open(), "Opening error in output file");

   //Imprime a saída de acordo com a especificação
   OutputFile << T;

   //Fecha os arquivos
   InputFile.close();
   OutputFile.close();
}