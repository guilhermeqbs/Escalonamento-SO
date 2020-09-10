#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    ifstream arquivo;
    string linha;
    int count=0;


    arquivo.open("entrada.txt", ios::out );

        //Rodar enquanto todo o arquivo não for lido(eof).
        while(!arquivo.eof()) {
            
            //Quebra cada linha do arq e armazena numa string.
            getline(arquivo,linha);
            
            cout <<"line: " <<linha<<endl;
            cout <<"cont: "<<count<<endl<<endl;
            
            count++;

            //Quebarar a linha nessas variaveis: (p,i,s).
        }
    
        
    return 0;

}