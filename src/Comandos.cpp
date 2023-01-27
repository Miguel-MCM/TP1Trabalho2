#include "Comandos.h"

void ComandoIAUsuarioDescadastrar::executar(IServicoUsuario* cntrServicoUsuario, Matricula* matricula){

    TelaMensagem telaMensagem;
    bool resultado;
    char input;

    while(true) {

        TelaDescadastro telaDescadastro;
        input = telaDescadastro.apresentar();

        if (input == 'S' || input == 's') {
            resultado = cntrServicoUsuario->descadastrar(*matricula);
            break;
        }
        else if (input == 'N' || input == 'n') {
            resultado = false;
            return;
        }
        else {
            TelaMensagem telaMensagem;
            telaMensagem.apresentar("Dado em formato incorreto.");
        }
    }

    if(resultado){
        telaMensagem.apresentar("Sucesso na execucao da operacao.");
    }
    else {
        telaMensagem.apresentar("Falha na execucao da operacao");
    }
}

void ComandoIAUsuarioEditar::executar(IServicoUsuario* cntrServicoUsuario, Matricula* matricula){

    bool resultado;
    Usuario usuario;

    // A seguir, incluir c�digo de intera��o com o usu�rio.

    // Solicitar servi�o.

    resultado = cntrServicoUsuario->editar(usuario);

    // Criticar resultado e apresentar mensagem correspondente.

    if(resultado){
         //cout << "Sucesso na execucao da operacao" << endl;

    }
    else {
        TelaMensagem telaMensagem;
        //cout << "Falha na execucao da operacao" << endl;
        telaMensagem.apresentar("Falha na execucao da operacao");
    }
}

void ComandoIAUsuarioConsultar::executar(IServicoUsuario* cntrServicoUsuario, Matricula* matricula){

    bool resultado;
    Usuario * usuario = new Usuario();
    usuario->setMatricula(*matricula);

    // A seguir, incluir c�digo de intera��o com o usu�rio.

    // Solicitar servi�o.

    resultado = cntrServicoUsuario->consultar(usuario);

    // Criticar resultado e apresentar mensagem correspondente.

    if(resultado){
         //cout << "Sucesso na execucao da operacao" << endl;
        TelaConsultarUsuario telaConsultarUsuario;
        telaConsultarUsuario.apresentar(*usuario);
    }
    else {
        //cout << "Falha na execucao da operacao" << endl;
        TelaMensagem telaMensagem;
        telaMensagem.apresentar("Falha na execucao da operacao");
    }
}
