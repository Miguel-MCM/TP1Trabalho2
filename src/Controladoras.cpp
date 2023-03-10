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
                        cntrApresentacaoProjeto->executar(&matricula);
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

void CntrApresentacaoControle::menuAutenticado(Matricula *matricula) {

    TelaMenu telaMenu;
    char opcao;

    while(true) {
        opcao = telaMenu.apresentar();

        switch(opcao) {
        case '1':
            cntrApresentacaoUsuario->executar(matricula);
            break;
        case '2':
            cntrApresentacaoProjeto->executar(matricula);
            break;
        case '3':
            return;
        default:
            TelaMensagem telaMensagem;
            telaMensagem.apresentar("Opcao Invalida");
        }
    }
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
    TelaMenuUsuario telaMenuUsuario;
    TelaMensagem telaMensagem;
    char opcao;
    bool notDone = true;
    while (notDone) {
        opcao = telaMenuUsuario.apresentar();

        switch(opcao){
            case '1': {
                comando = new ComandoIAUsuarioConsultar();
                comando->executar(cntrServicoUsuario,matricula);
                delete comando;
                return;
            }
            case '2': {
                comando = new ComandoIAUsuarioDescadastrar();
                comando->executar(cntrServicoUsuario,matricula);
                cadastro = false;
                delete comando;
                return;
            }
            case '3': {
                comando = new ComandoIAUsuarioEditar();
                comando->executar(cntrServicoUsuario,matricula);
                delete comando;
                return;
            }
            case '4':
                return;
            default:
                telaMensagem.apresentar("Escolha uma opcao valida");
        }
    }
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

void CntrApresentacaoProjeto::executar(Matricula* matricula) {

    TelaMenuProjeto telaMenuProjeto;
    char opcao;
    ComandoIAProjeto* comando;
    ComandoIAProjetoEditarProjeto comandoIAPEP;
    ComandoIAProjetoDescadastrarProjeto comandoIAPDP;
    ComandoIAProjetoEditarTarefa comandoIAProjetoEditarTarefa;
    ComandoIAProjetoDescadastrarTarefa comandoIAProjetoDescadastrarTarefa;



    while(true) {
        opcao = telaMenuProjeto.apresentar();

        switch(opcao) {
            case '1':
                comando = new ComandoIAProjetoConsultarProjeto();
                comando->executar(cntrServicoProjeto, matricula);

                break;
            case '2':
                comando = new ComandoIAProjetoCadastrarProjeto();
                comando->executar(cntrServicoProjeto, matricula);

                break;
            case '3':
                comandoIAPEP.executar(cntrServicoProjeto, matricula);

                break;
            case '4':
                comandoIAPDP.executar(cntrServicoProjeto, matricula);

                break;
            case '5':
                comando = new ComandoIAProjetoConsultarTarefa();
                comando->executar(cntrServicoProjeto, matricula);

                break;
            case '6':
                comando = new ComandoIAProjetoCadastrarTarefa();
                comando->executar(cntrServicoProjeto, matricula);
                break;
            case '7':
                comandoIAProjetoEditarTarefa.executar(cntrServicoProjeto, matricula);
                break;
            case '8':
                comandoIAProjetoDescadastrarTarefa.executar(cntrServicoProjeto);
                break;
            case '9':
                return;
            default:
                TelaMensagem telaMensagem;
                telaMensagem.apresentar("Opcao invalida.");
        }
    }
}

bool CntrServicoAutenticacao::autenticar(Matricula matricula, Senha senha) {

    Usuario usuario;
    usuario.setMatricula(matricula);
    usuario.setSenha(senha);

    ContainerUsuario* container = ContainerUsuario::getInstancia();

    return container->autenticar(usuario);
}

bool CntrServicoUsuario::cadastrar(Usuario usuario) {

    ContainerUsuario* container;
    container = ContainerUsuario::getInstancia();

    return container->incluir(usuario);
}

bool CntrServicoUsuario::descadastrar(Matricula matricula) {

    ContainerTarefa *containerTarefa = ContainerTarefa::getInstancia();
    if (!containerTarefa->removerPorUsuario(matricula))
        return false;

    ContainerProjeto *containerProjeto = ContainerProjeto::getInstancia();
    if (!containerProjeto->removerPorUsuario(matricula))
        return false;

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

bool CntrServicoProjeto::consultarProjeto(Projeto* projeto) {
    ComandoISProjetoConsultarProjeto comando;
    return comando.executar(projeto);
}

bool CntrServicoProjeto::cadastrarProjeto(Projeto projeto){
    ComandoISProjetoCadastrarProjeto comando;
    return comando.executar(projeto);
}

bool CntrServicoProjeto::descadastrarProjeto(Codigo codigo){
    ComandoISProjetoDescadastrarProjeto comando;
    return comando.executar(codigo);
}

bool CntrServicoProjeto::editarProjeto(Projeto projeto){
    ComandoISProjetoEditarProjeto comando;
    return comando.executar(projeto);
}

bool CntrServicoProjeto::cadastrarTarefa(Tarefa tarefa){
    ComandoISProjetoCadastrarTarefa comando;
    return comando.executar(tarefa);
}

bool CntrServicoProjeto::descadastrarTarefa(Codigo codigo){
    ComandoISProjetoDescadastarTarefa comando;
    return comando.executar(codigo);
}

bool CntrServicoProjeto::editarTarefa(Tarefa tarefa){
    ComandoISProjetoEditarTarefa comando;
    return comando.executar(tarefa);
}

bool CntrServicoProjeto::consultarTarefa(Tarefa* tarefa){
    ComandoISProjetoConsultarTarefa comando;
    return comando.executar(tarefa);
}


