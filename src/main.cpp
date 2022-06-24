#include <iostream>
#include <string>
#include <analisador.h>

using namespace std;


int main()
{
    int n;
    cout << "tamanho: ";
    cin >> n;
    cout << endl;

    Word *words = new Word[n];

    string lixo;
    getline(cin, lixo);

    cout << "LexOrder: "<< endl;
    string lexorder;
    getline(cin, lexorder);


    cout << "palavras: "<< endl;
    for(int i =0; i<n; i++){
        Word w;
        string palavraInput;
        cin >> w;
        //w.inityWord();

        words[i]= w;
    }
    
    cout << "LexOrder: " << lexorder << endl;

    for(int j =0; j<n; j++){
         cout << words[j] << "||" << words[j].orderWord << endl;
        if(j>0){
            if(words[j] > words[j-1]){
                cout << words[j] << " é maior que " << words[j-1] << endl;
            }
        }
    }

    
}