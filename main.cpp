#include <string.h>
#include <stdexcept>

#include "Interfaces.h"
#include "Controladoras.h"
#include "Builders.h"

using namespace std;

int main()
{

    // Inicio do BD
    ContainerUsuario *contUsuario = ContainerUsuario::getInstancia();
    Usuario usuario;
    Matricula matricula;
    matricula.setValor("ABCD1234");
    usuario.setMatricula(matricula);
    Senha senha;
    senha.setValor("ABC123");
    usuario.setSenha(senha);

    contUsuario->incluir(usuario);

    Projeto projeto;
    Codigo codigo;
    codigo.setValor("12345678900");
    projeto.setCodigo(codigo);
    projeto.SetUsuario(matricula);
    ContainerProjeto* contProjeto = ContainerProjeto::getInstancia();
    contProjeto->incluir(projeto);

    Tarefa tarefa;
    tarefa.setCodigo(codigo);
    tarefa.setProjeto(codigo);
    tarefa.setUsuario(matricula);
    ContainerTarefa *contTarefa = ContainerTarefa::getInstancia();
    contTarefa->incluir(tarefa);
    // Instanciar Builder.

    BuilderSistema* builder;
    builder = new BuilderSistema();

    // Construir (build) sistema.

    CntrApresentacaoControle* cntrApresentacaoControle;
    cntrApresentacaoControle = builder->construir();

    // Solicitar servi�o de apresentacao.

    cntrApresentacaoControle->executar();

    // Destruir builder.

    delete builder;

    return 0;
}
