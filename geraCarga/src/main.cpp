#include <iostream>
#include <string>
#include <getopt.h>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STR_SIZE	50
#define MIN_STR_SIZE	5

using namespace std;

char *validchars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-";

char *inputNameArq = NULL;
char *outputNameArq  = NULL;
int words = 10;
char *LexOrder = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


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
     while ((c = getopt(argc, argv, "o:O:w:W:l:L:")) != EOF)
       switch(c) {
         case 'o':
            outputNameArq = optarg;
            break;

         case 'O':
            outputNameArq = optarg;
            break;

         case 'w':
            words = atoi(optarg);
            break;

         case 'W':
            words = atoi(optarg);
            break;

         case 'l':
            LexOrder = optarg;
            break;

         case 'L':
            LexOrder = optarg;
            break;

         default:
                  exit(1);

       }
}

int main(int argc, char ** argv)
{
    srand(time(NULL));
    
    string* lista;
    lista = new string[words];

	char *novastr;
    int str_len;

    // Avaliar linha de comando
    parse_args(argc,argv);


    //Abertura dos arquivos
    ofstream OutputFile(outputNameArq);
    Assert(OutputFile.is_open(), "Opening error in output file");

    if(rand()%2 == 0){
        //FAZ O TEXTO PRIMEIRO
        OutputFile << "#TEXTO" << endl;
        for (int j = 0; j < words; j++)
        {
            str_len = (rand() % MAX_STR_SIZE );
            str_len += ( str_len < MIN_STR_SIZE ) ? MIN_STR_SIZE : 0;

            novastr = new char[str_len+1];
            for (int i = 0; i < str_len; i++ ) {
                novastr[i] = validchars[ rand() % strlen(validchars) ];
                novastr[i + 1] = '\0';

            }
            OutputFile << novastr;
            if(rand()%2 == 0){
                OutputFile << endl;
            }
            else{
                OutputFile << " ";
            }
        }

        //DEPOIS A ORDEM LEXICOGRÁFICA
        OutputFile << "\n#ORDEM" << endl;
        OutputFile << LexOrder << endl;
    }
    else{
        //FAZ A ORDEM LEXICOGRÁFICA
        OutputFile << "#ORDEM" << endl;
        OutputFile << LexOrder << endl;   
        
        //DEPOIS O TEXTO PRIMEIRO
        OutputFile << "#TEXTO" << endl;
        for (int j = 0; j < words; j++)
        {
            str_len = (rand() % MAX_STR_SIZE );
            str_len += ( str_len < MIN_STR_SIZE ) ? MIN_STR_SIZE : 0;

            novastr = new char[str_len+1];
            for (int i = 0; i < str_len; i++ ) {
                novastr[i] = validchars[ rand() % strlen(validchars) ];
                novastr[i + 1] = '\0';

            }
            OutputFile << novastr;
            if(rand()%2 == 0){
                OutputFile << endl;
            }
            else{
                OutputFile << " ";
            }
        }

    }

    


    OutputFile.close();
}
