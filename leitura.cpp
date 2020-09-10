#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>

using namespace std;

void entradaArquivo(string nomeTXT);

int main(){
    
    setlocale(LC_ALL,NULL);

    string nomeTXT="entrada.txt";

    //Fazer o cin e cout bunitin.

        entradaArquivo(nomeTXT);
        
    return 0;

}

void entradaArquivo(string nomeTXT){

    ifstream arquivo;
    string linha;
    int count=0;

    //Abri o arquivo.
    arquivo.open(nomeTXT, ios::out );
        
        //Verifica se o arquivo foi aberto corretamente
        if(arquivo.is_open()){
            
            //Rodar enquanto todo o arquivo não for lido(eof).
            while(!arquivo.eof()) {
                
                //Quebra cada linha do arq e armazena numa string.
                getline(arquivo,linha);
                
                cout <<"line: " <<linha<<endl;
                cout <<"cont: " <<count<<endl<<endl;
                
                count++;

            }
        }
        else
        {
            cout <<"\nO arquivo não foi aberto corretamente.\n";
        }


}