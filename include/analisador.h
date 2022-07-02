#include <iostream>
#include <string>
#include <fstream>
#include "memlog.h"
#include "msgassert.h"

using namespace std;

class Word{    
    public:
        string word;     
        string wordInOrder;  
        int qtd = 1; 
        //Methods
        void setOrder(string order);

        //Operators
        bool operator>(const Word& x);
        bool operator<(const Word& x);
        bool operator==(const Word& x);
        void operator++(int x);
        
        friend istream &operator>>( istream  &input, Word &D ) { 
            input >> D.word;
            return input;            
        }
        friend ostream &operator<<( ostream  &stream, Word &D ) { 
            stream << D.word << " " << D.qtd;
            return stream;            
        }
        friend Word &operator>>( Word  &input, Word &D ) { 
            D.word = input.word; 
            return input;            
        }

};

class Text{
    public:
        string text;
        string order;
        int size;
        Word* words;

        
    //Methods
        void CleanText();
        void CleanOrder();
        void FillWords();
        void SetOrder();

        void InputText(ifstream &InputFile);
        void InputOrder(ifstream &InputFile);

    //Operators
        //Atribuição de palavra
        friend Word &operator>>( Word  &input, Text &D ) { 
            D.text = D.text + input.word + " ";
            return input;            
        }
        //Atribuição de string 
        friend string &operator>>( string  &input, Text &D ) { 
        D.text = D.text + input;
        return input;            
        }
        //Impressão
        friend ostream &operator<<( ostream  &stream, Text &D ) { 
            for(int i = 0; i<D.size; i++){
                stream << D.words[i] << endl;
                leMemLog((long int)(&(D.words[i])),sizeof(string), 0);
            }
            stream << "#FIM";
            
            return stream;            
        }

};

//Funções Globais
void quicksort (Word *A, int n, int M, int S);