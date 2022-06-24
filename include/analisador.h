#include <iostream>
#include <string>

using namespace std;

class Word{    
    public:
        //Methods
        void inityWord();
        void setOrder();
        void swapToLowercase();
        void setOrderWord();  
        void Print();
        void Test();

        //Operators
        bool operator>(const Word& x);
        bool operator<(const Word& x);

        friend istream &operator>>( istream  &input, Word &D ) { 
            input >> D.word;
            D.swapToLowercase();
            D.setOrderWord();   
            return input;            
        }

        friend ostream &operator<<( ostream  &stream, Word &D ) { 
            stream << D.word;
            return stream;            
        }

        string orderWord;
    private:
        string word;

};

class analyzer{
    public:
        void insertWord();
        void swapWord(Word* a, Word *b);
        int Size();

    private:
        int size;
        Word words[10];
};