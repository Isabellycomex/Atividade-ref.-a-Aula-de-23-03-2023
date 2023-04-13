

#include <iostream>

#include <string>

#include <unistd.h>



using namespace std;

 

int main() {

    string mensagem;

    cout << "Digite uma mensagem: ";

    getline(cin, mensagem);

   

    int largura_tela = 80; 

    int tamanho_mensagem = mensagem.size();

    int espacos_lado_esquerdo = (largura_tela - tamanho_mensagem) / 2;

    for (int i = 0; i < espacos_lado_esquerdo; i++) {

        cout << " ";

    }

    cout << mensagem << endl;

   

    for (int i = 0; i < tamanho_mensagem; i++) {

        for (int j = 0; j < espacos_lado_esquerdo; j++) {

            cout << " ";

        }

        for (int j = 0; j <= i; j++) {

            cout << mensagem[j];

        }

        cout << endl;

        usleep(100000); 

    }

   

    return 0;

}


