#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <analisador.h>
#include <regex>

using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

//ORDENAÇÃO
void insertsort(Word *array, int n) {
   int i, j, trocou;
   for(i = 0; i < n-1; i++) {
      trocou = 0;
      for(j = 1; j < n-i; j++){
         if (array[j] < array[j-1]) {
            swap(array[j-1], array[j]);
            trocou = 1;
         }
         //leMemLog((long int)(&(array[j])),sizeof(Word), 2);
      }
      if (!trocou) {
         break;
      }
   }
}

void particao (int esq, int dir, int *i, int *j, Word *A, int M, int S) {
   Word x, w;
   
   *i = esq; *j = dir;

   // encontra o pivô de acordo com o paramêtro M
   int contador = 0;
   for (int z = 0; z < M; z++) {
      if(esq + contador < dir) {
         contador++;
      }
   }
   Word aux[contador+1];
   for (int z = 0; z < contador + 1; z++) {
      aux[z] = A[esq + z];
   }
   insertsort(aux, contador+1);
   int soma = contador + 1;
   x = aux[soma/2];
     
   //leMemLog((long int)(&(x)),sizeof(Word), 2);
   do {
      while (x > A[*i]) (*i)++;  
      while (x < A[*j]) (*j)--;  
      if (*i <= *j) {
         w = A[*i]; A[*i] = A[*j]; A[*j] = w;
         (*i)++; (*j)--;
      }
   } while (*i <= *j);
   
}

void selectionsort(Word *array, int esq, int dir, int n) {
   int i, j, min;
   n += esq; j = dir;

   for (i = esq; i < n - 1; i++) {
      min = i;
      for (j = i + 1 ; j < n; j++) {
         if (array[j] < array[min])
            min = j;
      }
      swap(array[i], array[min]);
   }
}

void ordena (int esq, int dir, Word *A, int M, int S) {
   int i, j; 

   int n = dir - esq +1;
   
   if (n <= S) 
      selectionsort(A, esq, dir, n);
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
            //97 - 122
            if( 97 <= wordInOrder[i] && wordInOrder[i] <=122 ){
                wordInOrder[i] = alphabet[order.find(wordInOrder[i])];
            }
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

    bool Word::operator==(const Word& x){
        if (word==x.word){
            return true;
        }
        else{
            return false;
        }
    }

    void Word::operator++(int x){
        qtd ++;
    }


//TEXT
    //Methods
    void Text::CleanText(){
        //Zera o contador de Words da classe
        size = 0;

        //Elimina os caracteres desnecessários
        regex pattern("[^A-Za-z0-9 -]");
        text = regex_replace(text, pattern, "");
        
        //Colocar em minpuscula
        for_each(text.begin(), text.end(), [](char & c){c = ::tolower(c);});

        //Coloca apenas as Words puras com um espaço
        stringstream it(text);
        string TextClean;
        string aux;
        while (it>>aux)
        {
            TextClean += (aux + " ");
            //SOma uma unidade a cada Word adicionada
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
            //Registra cada incremento que ocorre na string
            escreveMemLog((long int)(&(text)),sizeof(string), 1);
        }
        CleanText();
        //Aloca o vetor de Words
        words = new Word[size];
        //ALoca o vetor de Words
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
        Word aux;
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            it >> aux;
            //Se não for a primeira palavra inserida
            if(i>0){
                bool achou = false;
                //Procura se a palavra já foi definida
                for (int k = j-1; k >= 0; k--)
                {
                    //Se encontrar a palavra
                    if((aux) == words[k]){
                        //Aumenta a contagem da palavra e não insere no vetor
                        words[k]++;
                        achou = true;
                        break;
                    }
                    //Registra a posição de cada palavra nmo vetor na hora de comparar
                    //escreveMemLog((long int)(&(words[k])),sizeof(Word), 1);
                }
                //Se não encontrar
                if( !achou ){
                    //Atribui a palavra ao vetor
                    aux >> words[j];
                    j++;
                }
            }
            else{
                aux >> words[j];
                j++;
            }

            escreveMemLog((long int)(&(words[j])),sizeof(Word), 1);
        }
        size = j;
        
    }

    void Text::SetOrder(){
        
        for (int i = 0; i < size; i++)
        {
            //Adiciona a ordem lexicográfica em cada palavra
            //words[i].LexOrder = order;
            words[i].setOrder(order);
            //cout << words[i] << "|"<< words[i].wordInOrder << endl;
        }
    }
