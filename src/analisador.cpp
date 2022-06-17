#include <iostream>
#include <string>
#include <analisador.h>

using namespace std;

//WORD
    //Construtor
    Word::Word(){
        firstLetter = -1;
    }

    //Getters
    string Word::getWord(){
        return word;
    }

    //Setters
    void Word::setWord(string input){
        word = input;
        order = new int[word.length()];
        swapToLowercase();
        setOrder();
    }

    void Word::setOrder(){
        cout << word << endl;
        for(int i=0; i<word.length();i++){
            order[i]=word[i];
            cout << order[i]<< endl;
        }
    }

    //Methods
    void Word::swapToLowercase(){
        for(int i=0; i< word.length(); i++){
            if(word[i] >= 65 && word[i] <= 90){
                word[i]=word[i]+32;
            }
        }
    }

