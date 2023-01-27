#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "Interfaces.h"
#include "Telas.h"
#include <stdexcept>
#include <cstdlib>

class ComandoIAUsuario {
public:
    virtual void executar(IServicoUsuario*, Matricula*) = 0;
    virtual ~ComandoIAUsuario(){}
};

class ComandoIAUsuarioDescadastrar:public ComandoIAUsuario {
    void executar(IServicoUsuario*, Matricula*);
};

class ComandoIAUsuarioEditar:public ComandoIAUsuario {
    void executar(IServicoUsuario*, Matricula*);
};

class ComandoIAUsuarioConsultar: public ComandoIAUsuario {
    void executar(IServicoUsuario*, Matricula*);
};

class ComandoIAProjeto {
public:
    virtual void executar(IServicoProjeto*, Matricula*) = 0;
    virtual ~ComandoIAProjeto(){}
};

class ComandoIAProjetoConsultarProjeto:public ComandoIAProjeto {
public:
    void executar(IServicoProjeto*, Matricula*);
};

class ComandoISProjetoConsultarProjeto {
public:
    bool executar(Projeto* projeto);
};



#endif // COMANDOS_H_INCLUDED


