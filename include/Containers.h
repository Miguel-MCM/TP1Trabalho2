#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "Entidades.h"

#include <map>

using namespace std;

class ContainerUsuario{
    private:
        map<string, Usuario> container;
        static ContainerUsuario *instancia;
        ContainerUsuario(){};
    public:
        static  ContainerUsuario* getInstancia();
        bool incluir(Usuario);
        bool remover(Matricula);
        bool pesquisar(Usuario*);
        bool atualizar(Usuario);
        bool autenticar(Usuario);
};

class ContainerProjeto{
    private:
        map<string, Projeto> container;
        static ContainerProjeto *instancia;
        ContainerProjeto(){};
    public:
        static  ContainerProjeto* getInstancia();
        bool incluir(Projeto);
        bool remover(Codigo);
        bool pesquisar(Projeto*);
        bool atualizar(Projeto);
        bool removerPorUsuario(Matricula);
};

class ContainerTarefa{
    private:
        map<string, Tarefa> container;
        static ContainerTarefa *instancia;
        ContainerTarefa(){};
    public:
        static  ContainerTarefa* getInstancia();
        bool incluir(Tarefa);
        bool remover(Codigo);
        bool pesquisar(Tarefa*);
        bool atualizar(Tarefa);
        bool removerPorProjeto(Codigo);
        bool removerPorUsuario(Matricula);
};

#endif // CONTROLADORAS_H_INCLUDED

