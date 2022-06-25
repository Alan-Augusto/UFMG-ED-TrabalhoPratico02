#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <analisador.h>
#include <regex>

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
        for_each(word.begin(), word.end(), [](char & c){
            c = ::tolower(c);
        });
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
    void Text::CleanText(){
        regex pattern("[^A-Za-z0-9 -]");
        text = regex_replace(text, pattern, "");
        
        //Colocar em minpuscula
        for_each(text.begin(), text.end(), [](char & c){c = ::tolower(c);});

        stringstream it(text);
        string TextClean;
        string aux;
        while (it>>aux)
        {
            TextClean += (aux + " ");
            
        }
        text = TextClean;
    }

    void Text::CleanOrder(){
        stringstream it(order);
        string orderCLean;
        string aux;
        for(int i = 0; i<26; i++){
            it >> aux;
            orderCLean = orderCLean + aux + " ";
        }
        order = orderCLean;
    }

    void Text::InputText(ifstream &InputFile){
        string line;
        while (getline(InputFile, line) && line != "#ORDEM")
        {
            //Adiciona a linha no texto
            if(line[line.length()-1] != ' '){
                text += line + " ";
            }
            else{
                text += line;
            }
        }
        //cout << "======TEXO SEM LIMPAR======\n" << text << endl;
        CleanText();
    }

    void Text::InputOrder(ifstream &InputFile){
        string line;
        while (getline(InputFile, line) && line != "#TEXTO")
        {
            //Adiciona a linha no texto
            order += line;
        }
        CleanOrder();
    }