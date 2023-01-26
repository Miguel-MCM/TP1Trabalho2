#ifdef WIN32
    #include "curses.h"
#else
    #include <ncurses.h>

#endif // WIN32

#include <string.h>
#include <stdexcept>

#include "Interfaces.h"
#include "Controladoras.h"
#include "Builders.h"

using namespace std;

int main()
{
    // Instanciar Builder.

    BuilderSistema* builder;
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
