#include <string.h>
#include <stdexcept>

#include "Interfaces.h"
#include "Controladoras.h"
#include "Builders.h"

using namespace std;

int main()
{
    BuilderSistema* builder;
    builder = new BuilderSistema();

    CntrApresentacaoControle* cntrApresentacaoControle;
    cntrApresentacaoControle = builder->construir();

    cntrApresentacaoControle->executar();

    delete builder;

    return 0;
}
