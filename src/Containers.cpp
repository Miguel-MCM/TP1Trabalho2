#include "Containers.h"

ContainerUsuario* ContainerUsuario::instancia = nullptr;

//------------------------------------------------------------------------------------
// Implementações de métodos de classe container.

ContainerUsuario* ContainerUsuario::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerUsuario();
    return instancia;
}

bool ContainerUsuario::incluir(Usuario usuario){
    return container.insert(make_pair(usuario.getMatricula().getValor(), usuario)).second;
    //O QUE O SECOND ESTÁ FAZENDO?
}

bool ContainerUsuario::remover(Matricula matricula){
    map<string, Usuario>::iterator it = container.find(matricula.getValor());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerUsuario::pesquisar(Usuario* usuario){
    map<string, Usuario>::iterator it = container.find(usuario->getMatricula().getValor());
    if(it != container.end()){
        *usuario = it->second;
        return true;
    }
    return false;
}

bool ContainerUsuario::atualizar(Usuario usuario){
    map<string, Usuario>::iterator it = container.find(usuario.getMatricula().getValor());
    if(it != container.end()){
        it->second = usuario;
        return true;
    }
    return false;
}

