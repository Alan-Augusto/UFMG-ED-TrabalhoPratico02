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
        //Zera o contador de palavras da classe
        size = 0;

        //Elimina os caracteres desnecessários
        regex pattern("[^A-Za-z0-9 -]");
        text = regex_replace(text, pattern, "");
        
        //Colocar em minpuscula
        for_each(text.begin(), text.end(), [](char & c){c = ::tolower(c);});

        //Coloca apenas as palavras puras com um espaço
        stringstream it(text);
        string TextClean;
        string aux;
        while (it>>aux)
        {
            TextClean += (aux + " ");
            //SOma uma unidade a cada palavra adicionada
            size ++;
            
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
        CleanText();
        //Aloca o vetor de palavras
        words = new Word[size];
        //ALoca o vetor de palavras
        FillWords();
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

    void Text::FillWords(){
        //string de iteração
        stringstream it(text);
        cout << "\nATRIBUINDO PALAVRAS:" << endl;
        for (int i = 0; i < size; i++)
        {
            it >> words[i];

            cout << words[i] << "|";
        }
        cout << endl;
        
    }