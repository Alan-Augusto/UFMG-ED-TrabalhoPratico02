#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Word{    
    public:
        //Lexigr
        string LexOrder;
        string word;     
        string wordInOrder;   
        //Methods
        void setOrder(string order);

        //Operators
        bool operator>(const Word& x);
        bool operator<(const Word& x);
        friend istream &operator>>( istream  &input, Word &D ) { 
            input >> D.word; 
            return input;            
        }
        friend ostream &operator<<( ostream  &stream, Word &D ) { 
            stream << D.word;
            return stream;            
        }

};

class Text{
    public:
        string text;
        string order;
        int size;
        Word* words;

        
        //Methods
        void swapWord(Word* a, Word *b);
        void CleanText();
        void CleanOrder();
        void FillWords();
        void SetOrder();

        void InputText(ifstream &InputFile);
        void InputOrder(ifstream &InputFile);

        //Operators
        friend Word &operator>>( Word  &input, Text &D ) { 
        D.text = D.text + input.word + " ";
        return input;            
        }

        friend string &operator>>( string  &input, Text &D ) { 
        D.text = D.text + input;
        return input;            
        }


};

//Funções Globais
void quicksort (Word *A, int n, int M, int S);