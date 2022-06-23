#include <iostream>
#include <string>

using namespace std;

int LexOrder = 1;

class Word{    
    public:
        //Methods
        void inityWord();
        void setOrder();
        void swapToLowercase();
        void Print();
        void Test();

        //Operators
        bool operator>(const Word& x);

        friend istream &operator>>( istream  &input, Word &D ) { 
            input >> D.word;
            return input;            
        }

        friend ostream &operator<<( ostream  &stream, Word &D ) { 
            stream << D.word;
            return stream;            
        }


    private:
        string word;
        //Vetor que armazena cada valor em ASCII da palavra.
        int *order;
        int firstLetter;

};