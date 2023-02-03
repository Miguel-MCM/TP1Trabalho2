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

    bool valido = false;
    Usuario usuario;

    TelaMensagem telaMensagem;
    usuario.setMatricula(*matricula);
    TelaEdicaoUsuario telaEdicaoUsuario;

    while (!valido) {
        try {
            telaEdicaoUsuario.apresentar(&usuario);
            valido = true;
        }
        catch (invalid_argument *e) {
            clear();
            telaMensagem.apresentar("Dado em formato incorreto.");
        }
    }

    if(cntrServicoUsuario->editar(usuario)){
         telaMensagem.apresentar("Sucesso na execucao da operacao");
    }
    else {
        telaMensagem.apresentar("Falha na execucao da operacao");
    }
}

void ComandoIAUsuarioConsultar::executar(IServicoUsuario* cntrServicoUsuario, Matricula* matricula){

    bool resultado;
    Usuario * usuario = new Usuario();
    usuario->setMatricula(*matricula);

    resultado = cntrServicoUsuario->consultar(usuario);

    if(resultado){
        TelaConsultarUsuario telaConsultarUsuario;
        telaConsultarUsuario.apresentar(*usuario);
    }
    else {
        TelaMensagem telaMensagem;
        telaMensagem.apresentar("Falha na execucao da operacao");
    }
}

//IAProjetos

void ComandoIAProjetoConsultarProjeto::executar(IServicoProjeto* cntrServicoProjeto, Matricula* matricula) {

    Projeto* projeto = new Projeto();
    Codigo* codigo = new Codigo();
    TelaCodigo telaCodigo;
    TelaMensagem telaMensagem;

    projeto->SetUsuario(*matricula);
    while (true) {
        try {
            telaCodigo.apresentar(codigo);
            break;
        }
        catch (const invalid_argument &exp) {
            telaMensagem.apresentar("Cogido Invalido.");
        }
    }
    projeto->setCodigo(*codigo);

    if(cntrServicoProjeto->consultarProjeto(projeto)){
        TelaConsultaProjeto telaConsultaProjeto;
        telaConsultaProjeto.apresentar(projeto);
    }
    else {
        telaMensagem.apresentar("Projeto nao encontrado");
    }

}

void ComandoIAProjetoCadastrarProjeto::executar(IServicoProjeto* cntrServicoProjeto, Matricula* matricula) {

    Projeto projeto;
    projeto.SetUsuario(*matricula);

    TelaCadastroProjeto telaCadastroProjeto;
    TelaMensagem telaMensagem;

    while(true) {
        try {
            telaCadastroProjeto.apresentar(&projeto);
            break;
        }
        catch (const invalid_argument &exp) {
            telaMensagem.apresentar("Dado em formato incorreto.");
        }
    }

    if (cntrServicoProjeto->cadastrarProjeto(projeto)) {
        telaMensagem.apresentar("Projeto cadastrado.");
    }
    else {
        telaMensagem.apresentar("Ocorreu um erro durante o cadastramento");
    }
}

void ComandoIAProjetoEditarProjeto::executar(IServicoProjeto* cntrServicoProjeto, Matricula* matricula) {

    TelaEdicaoProjeto telaEdicaoProjeto;
    TelaMensagem telaMensagem;
    TelaCodigo telaCodigo;

    Codigo* codigo = new Codigo();
    Projeto* projeto = new Projeto();
    projeto->SetUsuario(*matricula);

    while (true) {
        try {
            telaCodigo.apresentar(codigo);
            break;
        }
        catch (const invalid_argument &exp) {
            telaMensagem.apresentar("Cogido Invalido.");
        }
    }
    projeto->setCodigo(*codigo);

    while(true) {
        try {
            telaEdicaoProjeto.apresentar(projeto);
            break;
        }
        catch (const invalid_argument &exp) {
            telaMensagem.apresentar("Dado em formato incorreto.");
        }
    }

    if (cntrServicoProjeto->editarProjeto(*projeto)) {
        telaMensagem.apresentar("Projeto editado com sucesso.");
    }
    else {
        telaMensagem.apresentar("Ocorreu um erro durante a edicao do projeto.");
    }
}

bool ComandoIAProjetoDescadastrarProjeto::executar(IServicoProjeto* cntrServicoProjeto, Matricula * matricula) {
    TelaMensagem telaMensagem;
    TelaCodigo telaCodigo;

    Codigo codigo;
    Projeto* projeto = new Projeto();

    bool resultado;
    char input;

    while (true) {
        try {
            telaCodigo.apresentar(&codigo);
            break;
        }
        catch (const invalid_argument &exp) {
            telaMensagem.apresentar("Cogido Invalido.");
        }
    }
    projeto->setCodigo(codigo);

    while(true) {

        TelaDescadastro telaDescadastro;
        input = telaDescadastro.apresentar();

        if (input == 'S' || input == 's') {
            resultado = cntrServicoProjeto->descadastrarProjeto(projeto->getCodigo());
            break;
        }
        else if (input == 'N' || input == 'n') {
            resultado = false;
            return resultado;
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
    return resultado;
}


void ComandoIAProjetoCadastrarTarefa::executar(IServicoProjeto* cntrServicoProjeto, Matricula* matricula) {

    Tarefa tarefa;
    tarefa.setUsuario(*matricula);

    TelaCadastroTarefa TelaCadastroTarefa;
    TelaMensagem telaMensagem;
    while(true) {
        try {
            TelaCadastroTarefa.apresentar(&tarefa);
            break;
        }
        catch (const invalid_argument &exp) {
            telaMensagem.apresentar("Dado em formato incorreto.");
        }
    }

    if (cntrServicoProjeto->cadastrarTarefa(tarefa)) {
        telaMensagem.apresentar("Tarefa cadastrada.");
    }
    else {
        telaMensagem.apresentar("Nao foi possivel realizar o cadastro");
    }
}

void ComandoIAProjetoConsultarTarefa::executar(IServicoProjeto* cntrServicoProjeto, Matricula* matricula) {

    Tarefa* tarefa = new Tarefa();
    Codigo* codigo = new Codigo();
    TelaCodigo telaCodigo;
    TelaMensagem telaMensagem;

    tarefa->setUsuario(*matricula);
    while (true) {
        try {
            telaCodigo.apresentar(codigo);
            break;
        }
        catch (const invalid_argument &exp) {
            telaMensagem.apresentar("Cogido Invalido.");
        }
    }
    tarefa->setCodigo(*codigo);

    if(cntrServicoProjeto->consultarTarefa(tarefa)){
        TelaConsultaTarefa telaConsultaTarefa;
        telaConsultaTarefa.apresentar(tarefa);
    }
    else {
        telaMensagem.apresentar("Tarefa nao encontrada");
    }

}

void ComandoIAProjetoEditarTarefa::executar(IServicoProjeto* cntrServicoProjeto, Matricula * matricula) {

    TelaEdicaoTarefa telaEdicaoTarefa;
    TelaCodigo telaCodigo;
    TelaMensagem telaMensagem;
    Codigo codigo;
    Tarefa tarefa;
    tarefa.setUsuario(*matricula);

    while (true) {
        try {
            telaCodigo.apresentar(&codigo);
            break;
        }
        catch (const invalid_argument &exp) {
            telaMensagem.apresentar("Cogido Invalido.");
        }
    }
    tarefa.setCodigo(codigo);

    while(true) {
        try {
            telaEdicaoTarefa.apresentar(&tarefa);
            break;
        }
        catch (const invalid_argument &exp) {
            telaMensagem.apresentar("Dado em formato incorreto.");
        }
    }

    if (cntrServicoProjeto->editarTarefa(tarefa)) {
        telaMensagem.apresentar("Tarefa editada com sucesso.");
    }
    else {
        telaMensagem.apresentar("Ocorreu um erro durante a edicao da tarefa.");
    }
}

bool ComandoIAProjetoDescadastrarTarefa::executar(IServicoProjeto* cntrServicoProjeto) {
    TelaMensagem telaMensagem;
    TelaCodigo telaCodigo;
    Codigo* codigo = new Codigo();
    Tarefa tarefa;
    bool resultado;
    char input;

    while (true) {
        try {
            telaCodigo.apresentar(codigo);
            break;
        }
        catch (const invalid_argument &exp) {
            telaMensagem.apresentar("Cogido Invalido.");
        }
    }
    tarefa.setCodigo(*codigo);

    while(true) {

        TelaDescadastro telaDescadastro;
        input = telaDescadastro.apresentar();

        if (input == 'S' || input == 's') {
            resultado = cntrServicoProjeto->descadastrarTarefa(tarefa.getCodigo());
            break;
        }
        else if (input == 'N' || input == 'n') {
            resultado = false;
            return resultado;
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
    return resultado;
}

// ISProjetos

bool ComandoISProjetoConsultarProjeto::executar(Projeto* projeto) {
    ContainerProjeto* container;
    container = ContainerProjeto::getInstancia();

    return container->pesquisar(projeto);
}

bool ComandoISProjetoCadastrarProjeto::executar(Projeto projeto) {
    ContainerProjeto* container;
    container = ContainerProjeto::getInstancia();

    return container->incluir(projeto);
}

bool ComandoISProjetoEditarProjeto::executar(Projeto projeto) {
    ContainerProjeto* container;
    container = ContainerProjeto::getInstancia();

    return container->atualizar(projeto);
}

bool ComandoISProjetoDescadastrarProjeto::executar(Codigo codigo) {
    ContainerTarefa *containerTarefa = ContainerTarefa::getInstancia();
    if (!containerTarefa->removerPorProjeto(codigo))
        return false;
    ContainerProjeto *containerProjeto = ContainerProjeto::getInstancia();
    return containerProjeto->remover(codigo);
}

bool ComandoISProjetoCadastrarTarefa::executar(Tarefa tarefa) {
    // Ver se o projeto existe e pretence ao usuario
    ContainerProjeto *containerProjeto = ContainerProjeto::getInstancia();
    Projeto projeto;
    projeto.SetUsuario(tarefa.getUsuario());
    projeto.setCodigo(tarefa.getProjeto());
    if(!containerProjeto->pesquisar(&projeto))
        return false;

    // cadastrar a tarefa
    ContainerTarefa *containerTarefa = ContainerTarefa::getInstancia();
    return containerTarefa->incluir(tarefa);
}

bool ComandoISProjetoConsultarTarefa::executar(Tarefa* tarefa) {
    ContainerTarefa* container;
    container = ContainerTarefa::getInstancia();

    return container->pesquisar(tarefa);
}

bool ComandoISProjetoEditarTarefa::executar(Tarefa tarefa) {
    ContainerTarefa* container;
    container = ContainerTarefa::getInstancia();

    return container->atualizar(tarefa);
}

bool ComandoISProjetoDescadastarTarefa::executar(Codigo codigo) {
    ContainerTarefa* container;
    container = ContainerTarefa::getInstancia();

    return container->remover(codigo);
}

