#include <iostream>
#include <string>
#include <analisador.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    Word *words = new Word[n];

    for(int i =0; i<n; i++){
        Word w;
        string palavraInput;
        cin >> w;
        w.inityWord();

        words[i]= w;
    }
    
    for(int j =0; j<n; j++){
        if(j>0){
            if(words[j] > words[j-1]){
                cout << words[j] << " é maior que " << words[j-1] << endl;
            }
        }
    }

    
}