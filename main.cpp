#include <iostream>
#include "Entidades.h"

using namespace std;
int main(void) {
    Usuario pessoa;
    Nome nome;
    nome.setValor("Hello World");
    pessoa.setNome(nome);

    cout << pessoa.getNome().getValor() << endl;
    return 0;
}
