#ifndef TELAS_H_INCLUDED
#define TELAS_H_INCLUDED

#ifdef WIN32
    #include "curses.h"
#else
    #include <ncurses.h>

#endif // WIN32

#include "Entidades.h"
#include <string.h>

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

class TelaMenu {
public:
    char apresentar();
};

#endif // TELAS_H_INCLUDED
