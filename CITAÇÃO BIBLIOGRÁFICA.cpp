
#include <iostream>

#include <fstream>

#include <string>

#include <algorithm>

#include <vector>


using namespace std;

 


string to_citacao_bibliografica(string nome) {


    vector<string> partes;

    string parte_atual = "";

    for (char c : nome) {

        if (c == ' ') {

            if (!parte_atual.empty()) {

                partes.push_back(parte_atual);

                parte_atual = "";

            }

        } else {

            parte_atual += c;

        }

    }

    if (!parte_atual.empty()) {

        partes.push_back(parte_atual);

    }

   

    string citacao = "";

    citacao += toupper(partes.back()[0]); 

    citacao += partes.back().substr(1); 

    citacao += ", "; 

    for (int i = 0; i < (int)partes.size() - 1; i++) {

        citacao += toupper(partes[i][0]); 

        citacao += ". "; 

    }

    citacao.pop_back(); 

    citacao += "."; 

   

    return citacao;

}

 

int main() {


    ifstream arquivo("nomes.txt");

    if (!arquivo.is_open()) {

        cout << "Erro ao abrir o arquivo de nomes!" << endl;

        return 1;

    }

   

    string nome;

    while (getline(arquivo, nome)) {

        string citacao = to_citacao_bibliografica(nome);

        cout << citacao << endl;

    }

   


    arquivo.close();

   

    return 0;

}