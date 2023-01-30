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

class ComandoIAProjetoCadastrarProjeto:public ComandoIAProjeto {
public:
    void executar(IServicoProjeto*, Matricula*);
};

class ComandoIAProjetoEditarProjeto {
public:
    void executar(IServicoProjeto*, Projeto);
};

class ComandoIAProjetoDescadastrarProjeto {
public:
    bool executar(IServicoProjeto*, Projeto);
};

class ComandoIAProjetoConsultarTarefa:public ComandoIAProjeto {
public:
    void executar(IServicoProjeto*, Matricula*);
};

class ComandoIAProjetoCadastrarTarefa:public ComandoIAProjeto {
public:
    void executar(IServicoProjeto*, Matricula*);
};

class ComandoIAProjetoEditarTarefa {
public:
    void executar(IServicoProjeto*, Tarefa);
};

class ComandoIAProjetoDescadastrarTarefa {
public:
    bool executar(IServicoProjeto*, Tarefa);
};

class ComandoISProjetoConsultarProjeto {
public:
    bool executar(Projeto* projeto);
};

class ComandoISProjetoCadastrarProjeto {
public:
    bool executar(Projeto);
};

class ComandoISProjetoEditarProjeto {
public:
    bool executar(Projeto);
};

class ComandoISProjetoDescadastrarProjeto {
public:
    bool executar(Codigo);
};

class ComandoISProjetoCadastrarTarefa {
public:
    bool executar(Tarefa);
};

class ComandoISProjetoConsultarTarefa {
public:
    bool executar(Tarefa* tarefa);
};

class ComandoISProjetoEditarTarefa {
public:
    bool executar(Tarefa);
};

class ComandoISProjetoDescadastarTarefa {
public:
    bool executar(Codigo);
};


#endif // COMANDOS_H_INCLUDED


