

#include <iostream>

#include <fstream>

#include <string>

#include <algorithm>

#include <vector>

 

using namespace std;

 


string to_agenda_telefonica(string nome) {


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

   

    string agenda = "";

    agenda += partes.back(); 

    agenda += ", ";

    for (int i = 0; i < (int)partes.size() - 1; i++) {

        agenda += partes[i]; 

        agenda += " "; 

    }

    agenda.pop_back(); 

   

    return agenda;

}

 

int main() {


    ifstream arquivo("nomes.txt");

    if (!arquivo.is_open()) {

        cout << "Erro ao abrir o arquivo de nomes!" << endl;

        return 1;

    }

   

    string nome;

    while (getline(arquivo, nome)) {

        string agenda = to_agenda_telefonica(nome);

        cout << agenda << endl;

    }



    arquivo.close();


    return 0;

}

