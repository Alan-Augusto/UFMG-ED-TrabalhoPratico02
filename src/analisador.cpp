#include <iostream>
#include <string>
#include <analisador.h>

using namespace std;

extern int LexOrder;

//WORD
    //Setters
    void Word::inityWord(){
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

    void Word::Test(){
        
        cout << LexOrder;
    }

    //Operators
    bool Word::operator>(const Word& x){
        if (word>x.word){
            return true;
        }
        else{
            return false;
        }
    }

