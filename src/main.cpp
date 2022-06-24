#include <iostream>
#include <string>
#include <getopt.h>
#include <fstream>
#include <analisador.h>

using namespace std;

char *logNameArq = NULL;
char *inputNameArq = NULL;
char *outputNameArq  = NULL;

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

            break;

         case 'M':

            break;

         case 's':

            break;

         case 'S':

            break;

         case 'l':
            logNameArq = optarg;
            break;

         default:
                  exit(1);

       }
}


int main(int argc, char ** argv)
{
    // avaliar linha de comando
    parse_args(argc,argv);

    //Abertura dos arquivos
    ifstream InputFile(inputNameArq);
	Assert(InputFile.is_open(), "Opening error in input file");

    ofstream OutputFile(outputNameArq);
    Assert(OutputFile.is_open(), "Opening error in output file");

    cout << "AAAAAAAA"<< endl;
    cout << inputNameArq << "and " << outputNameArq << endl;;


    Text T;

    int n;
    cout << "tamanho: ";
    cin >> n;

    string lixo;
    getline(cin, lixo);

    /*
    cout << "LexOrder: "<< endl;
    string lexorder;
    getline(cin, lexorder);
*/

    cout << "palavras: "<< endl;
    for(int i =0; i<n; i++){
        Word w;
        string palavraInput;
        cin >> w;
        //w.inityWord();
        w >> T;
    }

    cout << T.text << endl;

/*
    cout << "LexOrder: " << lexorder << endl;
    for(int j =0; j<n; j++){
         cout << words[j] << "||" << words[j].orderWord << endl;
        if(j>0){
            if(words[j] > words[j-1]){
                cout << words[j] << " é maior que " << words[j-1] << endl;
            }
        }
    }  
*/
    InputFile.close();
    OutputFile.close();
}