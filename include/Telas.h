#ifndef TELAS_H_INCLUDED
#define TELAS_H_INCLUDED

#include "Entidades.h"
#include <string.h>
#include <stdlib.h>
#include "curses.h"

class TelaAutenticacao {
public:
    void apresentar(Matricula*, Senha*);
};

class TelaMensagem {
public:
    void apresentar(string);
};

class TelaCadastro {
public:
    void apresentar(Usuario*);
};

class TelaMenuUsuario {
public:
    char apresentar();
};

class TelaDescadastro {
public:
    char apresentar();
};

class TelaControle {
public:
    char apresentar();
};

#endif // TELAS_H_INCLUDED
