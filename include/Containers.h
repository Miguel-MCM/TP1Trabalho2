#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "Entidades.h"

#include <map>

using namespace std;

//----------------------------------------------------------------------------------------
// Declaração de classe container.
//
// Declaração adota padrão de projeto Singleton.

class ContainerUsuario{
    private:
        map<string, Usuario> container;                 // Mapa de usuários.
        static ContainerUsuario *instancia;             // Ponteiro para instância da classe.
        ContainerUsuario(){};                           // Construtor.
    public:
        static  ContainerUsuario* getInstancia();       // Método para instanciar classe.
        bool incluir(Usuario);                          // Métodos responsáveis por prestar serviços.
        bool remover(Matricula);
        bool pesquisar(Usuario*);
        bool atualizar(Usuario);
};

#endif // CONTROLADORAS_H_INCLUDED

