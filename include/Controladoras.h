#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "Interfaces.h"
#include "curses.h"

#include <stdexcept>

using namespace std;

class CntrApresentacaoControle{
    private:
        Matricula matricula;
        IApresentacaoAutenticacao* cntrApresentacaoAutenticacao;
        IApresentacaoUsuario* cntrApresentacaoUsuario;
    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
        void setCntrApresentacaoUsuario(IApresentacaoUsuario*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao* cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoUsuario(IApresentacaoUsuario* cntr){
    cntrApresentacaoUsuario = cntr;
}

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao {
private:
    IServicoAutenticacao* cntrServicoAutenticacao;
public:
    bool autenticar(Matricula*);
    void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

void inline CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao* cntrServicoAutenticacao){
    this->cntrServicoAutenticacao = cntrServicoAutenticacao;
}

class CntrApresentacaoUsuario:public IApresentacaoUsuario {
private:
    IServicoUsuario* cntrServicoUsuario;
public:
    void executar(Matricula*);
    void cadastrar();
    void setCntrServicoUsuario(IServicoUsuario*);
};

void inline CntrApresentacaoUsuario::setCntrServicoUsuario(IServicoUsuario* cntrServicoUsuario){
    this->cntrServicoUsuario = cntrServicoUsuario;
}

class CntrServicoAutenticacao:public IServicoAutenticacao{
    public:
        bool autenticar(Matricula, Senha);
};

class CntrServicoUsuario:public IServicoUsuario{
    public:
        bool cadastrar(Usuario);
        bool descadastrar(Matricula);
        bool editar(Usuario);
        bool consultar(Usuario*);
};

#endif // CONTROLADORAS_H_INCLUDED
