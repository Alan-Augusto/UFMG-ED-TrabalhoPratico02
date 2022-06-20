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
        firstLetter = word[0];
    }

    void Word::setOrder(){
        int n = word.length();
        for(int i=0; i<n ;i++){
            order[i]=word[i];
        }
    }

    //Methods
    void Word::swapToLowercase(){
        int n = word.length();
        for(int i=0; i< n; i++){
            if(word[i] >= 65 && word[i] <= 90){
                word[i]=word[i]+32;
            }
        }
    }

    void Word::Print(){
        cout << "Palavra: " << word << endl;
        cout << "FirstLetter: "<< firstLetter << endl; 
    }
