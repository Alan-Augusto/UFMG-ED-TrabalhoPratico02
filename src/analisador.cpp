#include <iostream>
#include <string>
#include <fstream>
#include <analisador.h>

using namespace std;


//WORD
    //Setters
    void Word::inityWord(){
       // order = new int[word.length()];
       // swapToLowercase();
       // setOrder();
       // firstLetter = word[0];
    }

    void Word::setOrder(){
        int n = word.length();
        for(int i=0; i<n ;i++){
            //order[i]=word[i];
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

    void Word::setOrderWord(){
        orderWord = word;
    }

    void Word::Print(){
        cout << "Palavra: " << word << endl;
        //cout << "FirstLetter: "<< firstLetter << endl; 
    }

    void Word::Test(){
        //
    }

    //Operators
    bool Word::operator>(const Word& x){
        if (orderWord>x.orderWord){
            return true;
        }
        else{
            return false;
        }
    }

    bool Word::operator<(const Word& x){
        if (orderWord<x.orderWord){
            return true;
        }
        else{
            return false;
        }
    }

//TEXT
    //Methods
    void Text::InputText(ifstream &InputFile){
        string line;
        while (getline(InputFile, line) && line != "#ORDEM")
        {
            //Adiciona a linha no texto
            text += line + " ";
        }
    }

    void Text::InputOrder(ifstream &InputFile){
        string line;
        while (getline(InputFile, line) && line != "#TEXTO")
        {
            //Adiciona a linha no texto
            order += line;
        }
    }