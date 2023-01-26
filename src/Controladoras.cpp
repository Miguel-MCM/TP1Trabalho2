#include "Controladoras.h"
#include "Comandos.h"

void CntrApresentacaoControle::executar(){

    TelaControle telaControle;
    TelaMensagem telaMensagem;
    char opcaoControle;
    char opcaoMenu;

    while(true){

        opcaoControle = telaControle.apresentar();

        if(opcaoControle == '1') {
            if (cntrApresentacaoAutenticacao->autenticar(&matricula)) {
                TelaMenu telaMenu;
                cntrApresentacaoUsuario->setStatusCadastro(true);
                while(cntrApresentacaoUsuario->getStatusCadastro()) {
                    opcaoMenu = telaMenu.apresentar();
                    if (opcaoMenu == '1') {
                        cntrApresentacaoUsuario->executar(&matricula);
                    }
                    else if (opcaoMenu == '2') {
                        //cntrApresentacaoProjeto/Tarefa
                    }
                    else if (opcaoMenu == '3') {
                        break;
                    }
                    else {
                        telaMensagem.apresentar("Dado em formato incorreto");
                    }
                }
            }
            else {
                telaMensagem.apresentar("Falha na autenticacao");
            }
        }
        else if (opcaoControle == '2') {
            cntrApresentacaoUsuario->cadastrar();
        }
        else if (opcaoControle == '3') {
            return;
        }
        else {
            telaMensagem.apresentar("Opcao invalida.");
        }
    }
    return;
}

bool CntrApresentacaoAutenticacao::autenticar(Matricula* matricula){

    bool resultado;
    Senha senha;

    while(true) {

        try {
            TelaAutenticacao telaAutenticacao;
            telaAutenticacao.apresentar(matricula, &senha);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem telaMensagem;
            telaMensagem.apresentar("Dado em formato incorreto.");
        }
    }

    resultado = cntrServicoAutenticacao->autenticar(*matricula,senha);

    return resultado;
};

void CntrApresentacaoUsuario::executar(Matricula* matricula){

    ComandoIAUsuario* comando;
    TelaMenuUsuario telaMenuUsuario;
    char opcao = telaMenuUsuario.apresentar();

    switch(opcao){
        case '1': comando = new ComandoIAUsuarioConsultar();
                  comando->executar(cntrServicoUsuario,matricula);
                  delete comando;
                  return;
        case '2': comando = new ComandoIAUsuarioDescadastrar();
                  comando->executar(cntrServicoUsuario,matricula);
                  cadastro = false;
                  delete comando;
                  return;
        case '3': comando = new ComandoIAUsuarioEditar();
                  comando->executar(cntrServicoUsuario,matricula);
                  delete comando;
                  return;
        case '4': return;
    }
    TelaMensagem telaMensagem;
    telaMensagem.apresentar("Opcao invalida.");
};

void CntrApresentacaoUsuario::cadastrar() {

    bool resultado;
    Usuario usuario;

    while(true) {

        try {
            TelaCadastro telaCadastro;
            telaCadastro.apresentar(&usuario);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem telaMensagem;
            telaMensagem.apresentar("Dado em formato incorreto.");
        }
    }

    resultado = cntrServicoUsuario->cadastrar(usuario);
    TelaMensagem telaMensagem;

    if (resultado) {
        telaMensagem.apresentar("Cadastro realizado com sucesso.");
    }
    else {
        telaMensagem.apresentar("Falha no cadastro.");
    }
}

bool CntrServicoAutenticacao::autenticar(Matricula matricula, Senha senha) {

    Usuario usuario;
    usuario.setMatricula(matricula);
    usuario.setSenha(senha);

    ContainerUsuario* container;
    container = ContainerUsuario::getInstancia();

    return container->pesquisar(&usuario);
    //este usuario é o objeto no conteiner
}

bool CntrServicoUsuario::cadastrar(Usuario usuario) {

    ContainerUsuario* container;
    container = ContainerUsuario::getInstancia();

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
