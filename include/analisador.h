#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Word{    
    public:
        string orderWord;
        string word;        
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

};

class Text{
    public:
        string text;
        string order;
        
        //Methods
        void swapWord(Word* a, Word *b);
        void CleanText();
        void CleanOrder();

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