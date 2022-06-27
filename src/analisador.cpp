#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <analisador.h>
#include <regex>

using namespace std;

//ORDENAÇÃO
void particao (int esq, int dir, int *i, int *j, Word *A, int M, int S) {
   Word x, w;
   
   *i = esq; *j = dir;

   int contador = 0;
   for (int z = 0; z < M; z++) {
      if(esq + contador < dir) {
         contador++;
      }
   }
   
   int soma = esq+(esq + contador);
   x = A[soma/2]; // obtém o pivô x
   
   //leMemLog((long int)(&(x)),sizeof(palavra), 0);
   do {
    while (x.wordInOrder > A[*i].wordInOrder) (*i)++;  
    while (x.wordInOrder < A[*j].wordInOrder) (*j)--;  
    if (*i <= *j) {
      w = A[*i]; A[*i] = A[*j]; A[*j] = w;
      (*i)++; (*j)--;
    }
   } while (*i <= *j);
   
}

void insertsort(Word *array, int n) {
   int i, j, trocou;
   for(i = 0; i < n-1; i++) {
      trocou = 0;
      for(j = 1; j < n-i; j++){
         if (array[j].wordInOrder < array[j-1].wordInOrder) {
            swap(array[j-1], array[j]);
            trocou = 1;
         }
         //leMemLog((long int)(&(array[j])),sizeof(palavra), 0);
      }
      if (!trocou) {
         break;
      }
   }
}

void ordena (int esq, int dir, Word *A, int M, int S) {
   int i, j; 
   int n = dir - esq +1;
   int auxS = sqrt(S);

   if (n < auxS){
      insertsort(A, n);
   }
   
   else {
      particao (esq, dir, &i, &j, A, M, S);
      if (esq < j) ordena (esq, j, A, M, S);
      if (i < dir) ordena (i, dir, A, M, S);
   }
}

void quicksort (Word *A, int n, int M, int S) {
   ordena(0, n-1, A, M, S);
}

//WORD
    //Methods
    void Word::setOrder(string order){
        int n = word.length();
        wordInOrder= word;

        for(int i=0; i<n ;i++){
            wordInOrder[i] = order[wordInOrder[i]-97];
        }
    }

    //Operators
    bool Word::operator>(const Word& x){
        if (wordInOrder>x.wordInOrder){
            return true;
        }
        else{
            return false;
        }
    }

    bool Word::operator<(const Word& x){
        if (wordInOrder<x.wordInOrder){
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
        //Colocar em minpuscula
        for_each(order.begin(), order.end(), [](char & c){c = ::tolower(c);});
        
        //Manipulação de strings
        stringstream it(order);
        string orderCLean;
        string aux;

        for(int i = 0; i<26; i++){
            it >> aux;
            orderCLean = orderCLean + aux;
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
        for (int i = 0; i < size; i++)
        {
            it >> words[i];
        }
        
    }

    void Text::SetOrder(){
        
        cout << "GERANDO PALAVRAS DE ORDENAÇÃO:"<<endl;
        for (int i = 0; i < size; i++)
        {
            //Adiciona a ordem lexicográfica em cada palavra
            //words[i].LexOrder = order;
            words[i].setOrder(order);
            cout << words[i] << "|"<< words[i].wordInOrder << endl;
        }
    }