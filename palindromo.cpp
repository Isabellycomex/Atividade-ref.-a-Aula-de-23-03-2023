
#include <iostream>

#include <string>

#include <algorithm>

 

using namespace std;

 

string remove_espacos(string str) {

    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    return str;

}

 

bool is_palindromo(string str) {

    str = remove_espacos(str);

    string str_reversa = str;

    reverse(str_reversa.begin(), str_reversa.end());

    return str == str_reversa;

}

 

int main() {


    string mensagem;

    cout << "Digite uma mensagem: ";

    getline(cin, mensagem);

   

    if (is_palindromo(mensagem)) {

        cout << "A mensagem e um palindromo!" << endl;

    } else {

        cout << "A mensagem nao e um palindromo." << endl;

    }

   

    return 0;

}
