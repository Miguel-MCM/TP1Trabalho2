#include "Builders.h"

CntrApresentacaoControle* BuilderSistema::construir(){

    // Instanciar controladoras da camada de apresentação.

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoUsuario = new CntrApresentacaoUsuario();
    cntrApresentacaoProjeto = new CntrApresentacaoProjeto();

    // Instanciar controladoras da camada de serviço.

    cntrServicoUsuario = new CntrServicoUsuario();
    cntrServicoAutenticacao = new CntrServicoAutenticacao();

    // Interligar as controladoras.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoUsuario(cntrApresentacaoUsuario);
    cntrApresentacaoControle->setCntrlApresentacaoProjeto(cntrApresentacaoProjeto);
    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(cntrServicoAutenticacao);
    cntrApresentacaoUsuario->setCntrServicoUsuario(cntrServicoUsuario);

    // Retornar referência para instância de CntrApresentacaoControle.

    return cntrApresentacaoControle;
}

BuilderSistema::~BuilderSistema(){
        delete cntrApresentacaoControle;
        delete cntrApresentacaoAutenticacao;
        delete cntrApresentacaoUsuario;
        delete cntrServicoAutenticacao;
        delete cntrServicoUsuario;
}
