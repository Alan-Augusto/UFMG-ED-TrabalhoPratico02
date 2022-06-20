#include <iostream>
#include <string>
#include <analisador.h>

using namespace std;

int main()
{
    Word w1;
    string palavraInput;
    cin >> palavraInput;

    w1.setWord(palavraInput);
    w1.Print();
}