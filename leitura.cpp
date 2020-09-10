#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    ofstream arquivo;
    string linha;

    arquivo.open("entrada.txt");

    getline(arquivo,linha);

    cout <<linha;


}