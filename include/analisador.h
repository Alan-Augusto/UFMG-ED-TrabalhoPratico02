#include <iostream>
#include <string>

using namespace std;

class Word{
    public:
        //Construtor
        Word();
        //getters
        string getWord();

        //Setters
        void setWord(string input);
        void setOrder();

        //Methods
        void swapToLowercase();
        void Print();

    private:
        string word;
        //Vetor que armazena cada valor em ASCII da palavra.
        int *order;
        int firstLetter;

};