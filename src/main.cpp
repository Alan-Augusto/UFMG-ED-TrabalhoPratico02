#include <iostream>
#include <string>
#include <getopt.h>
#include <fstream>
#include <analisador.h>

using namespace std;

char *logNameArq = NULL;
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

         case 'l':
            logNameArq = optarg;
            break;

         default:
                  exit(1);

       }
}


int main(int argc, char ** argv){
   // Avaliar linha de comando
   parse_args(argc,argv);

   //Abertura dos arquivos
   ifstream InputFile(inputNameArq);
   Assert(InputFile.is_open(), "Opening error in input file");

   ofstream OutputFile(outputNameArq);
   Assert(OutputFile.is_open(), "Opening error in output file");

   //VARIÁVEIS
   //Texto a ser lido:
   Text T;
   //Informação que será recolhida
   string information;
   //Vai receber cada linha.
   string line;
   getline(InputFile, information);

   //Se a primeira informação for o texto
   if(information == "#TEXTO"){
      //Recolhe primeiro o texto depois a ordem
      T.InputText(InputFile);
      T.InputOrder(InputFile);
      //Faz a tradução das palavras de acordo com a ordem lexicográfica
      T.SetOrder();
   }
   else if(information == "#ORDEM"){
      //Recolhe primeiro a ordem depois o texto
      T.InputOrder(InputFile);
      T.InputText(InputFile);
      //Faz a tradução das palavras de acordo com a ordem lexicográfica
      T.SetOrder();
   }
    
   //Realiza a ordenação do vetor de palavras de acordo com a ordem lexicográfica
   quicksort(T.words, T.size, M, S);
   
   //Imprime a saída de acordo com a especificação
   OutputFile << T;

   //Fecha os arquivos
   InputFile.close();
   OutputFile.close();
}