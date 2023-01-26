#include "Controladoras.h"
#include "Comandos.h"

void CntrApresentacaoControle::executar(){
    TelaMensagem telaMensagem;
    TelaControle telaControle;
    bool notDone = true;
    while(notDone){
        char opcao;
        opcao = telaControle.apresentar();

        switch (opcao) {
            case '1': {
                if (cntrApresentacaoAutenticacao->autenticar(&matricula)) {
                    cntrApresentacaoUsuario->executar(&matricula);
                    notDone = false;
                }
                else{
                    telaMensagem.apresentar("Falha na autenticacao.");
                }
                break;
            }
            case '2': {
                    cntrApresentacaoUsuario->cadastrar();
                    break;
            }
            default: {
                telaMensagem.apresentar("Dado em formato incorreto");
            }
        }
    }
    return;
}

bool CntrApresentacaoAutenticacao::autenticar(Matricula* matricula){

    bool resultado;
    Senha* senha = new Senha();

    while(true) {

        try {
            TelaAutenticacao telaAutenticacao;
            telaAutenticacao.apresentar(matricula, senha);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem telaMensagem;
            telaMensagem.apresentar("Dado em formato incorreto.");
        }
    }

    resultado = cntrServicoAutenticacao->autenticar(*matricula,*senha);

    return resultado;
};

void CntrApresentacaoUsuario::executar(Matricula* matricula){
    ComandoIAUsuario* comando;
    int opcao;
    TelaMenuUsuario telaMenuUsuario;
    opcao = telaMenuUsuario.apresentar();
    noecho();
    switch(opcao){
        case 1: comando = new ComandoIAUsuarioConsultar();
                comando->executar(cntrServicoUsuario,matricula);
                delete comando;
                return;
        case 2: comando = new ComandoIAUsuarioDescadastrar();
                comando->executar(cntrServicoUsuario,matricula);
                delete comando;
                return;
        case 3: comando = new ComandoIAUsuarioEditar();
                comando->executar(cntrServicoUsuario,matricula);
                delete comando;
                return;
    }
    TelaMensagem telaMensagem;
    telaMensagem.apresentar("Opcao invalida.");
};

void CntrApresentacaoUsuario::cadastrar() {

    bool resultado;
    Usuario* usuario = new Usuario();
    TelaMensagem telaMensagem;
    TelaCadastro telaCadastro;
    while(true) {

        try {
            telaCadastro.apresentar(usuario);
            break;
        }
        catch (const invalid_argument &exp) {
            telaMensagem.apresentar("Dado em formato incorreto.");
        }
    }

    resultado = cntrServicoUsuario->cadastrar(*usuario);

    if (resultado) {
        telaMensagem.apresentar("Cadastro realizado com sucesso.");
    }
    else {
        telaMensagem.apresentar("Falha no cadastro.");
    }
}

bool CntrServicoAutenticacao::autenticar(Matricula matricula, Senha senha) {
    Usuario* usuario = new Usuario();
    usuario->setMatricula(matricula);

    ContainerUsuario* container = ContainerUsuario::getInstancia();

    return container->pesquisar(usuario);
}

bool CntrServicoUsuario::cadastrar(Usuario usuario) {

    // Instancia container de usuários.
    ContainerUsuario* container;
    container = ContainerUsuario::getInstancia();

    // Solicitar cadastramento de usuário e retornar resultado da solicitação de serviço.
    return container->incluir(usuario);
}

bool CntrServicoUsuario::descadastrar(Matricula matricula) {

    ContainerUsuario* container;
    container = ContainerUsuario::getInstancia();
    return container->remover(matricula);
}

bool CntrServicoUsuario::editar(Usuario usuario) {

    ContainerUsuario* container;
    container = ContainerUsuario::getInstancia();
    return container->atualizar(usuario);
}

bool CntrServicoUsuario::consultar(Usuario* usuario) {

    ContainerUsuario* container;
    container = ContainerUsuario::getInstancia();
    return container->pesquisar(usuario);
}
