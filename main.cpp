#include <string.h>
#include <stdexcept>

#include "Interfaces.h"
#include "Controladoras.h"
#include "Builders.h"

using namespace std;

int main()
{
    // Instanciar Builder.

    BuilderSistema *builder;
    builder = new BuilderSistema();

    // Construir (build) sistema.

    CntrApresentacaoControle* cntrApresentacaoControle;
    cntrApresentacaoControle = builder->construir();

    // Solicitar serviço de apresentacao.

    cntrApresentacaoControle->executar();

    // Destruir builder.

    delete builder;

    return 0;
}

/*
    Matricula matricula;
    Matricula* ptrMatricula = &matricula;
    bool autenticou;

    // Iniciar curses.
    // Solicitar serviço apresentacao.
    // Finalizar curses.

    initscr();
    cntrApresentacaoUsuario->cadastrar();
    endwin();
    initscr();
    autenticou = cntrApresentacaoAutenticacao->autenticar(ptrMatricula);
    endwin();
    initscr();
    cntrApresentacaoUsuario->executar(ptrMatricula);
    endwin();
    if (autenticou) {
        initscr();
        cntrApresentacaoUsuario->executar(ptrMatricula);
        endwin();
    }
    else {
        initscr();
        cntrApresentacaoUsuario->cadastrar();
        endwin();
    }


    return 0;
}
*/
