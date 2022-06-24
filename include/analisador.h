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
        string word;

};

class Text{
    public:
        void swapWord(Word* a, Word *b);
        int Size();

        friend Word &operator>>( Word  &input, Text &D ) { 
        D.text = D.text + input.word + " ";
        return input;            
        }

        string text;
    private:
        int size;
};