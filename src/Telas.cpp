#include "Telas.h"
#include <iostream>
void TelaAutenticacao::apresentar(Matricula *matricula, Senha *senha) {

    char campo1[]="Digite a matricula : ";
    char campo2[]="Digite a senha     : ";
    char dado1[80];
    char dado2[80];
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
    getstr(dado1);
    mvprintw(linha/2 + 2,(coluna-strlen(campo2))/2,"%s",campo2);
    getstr(dado2);
    clear();
    endwin();

    matricula->setValor(dado1);
    senha->setValor(dado2);
}

void TelaMensagem::apresentar(string mensagem) {

    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(mensagem.c_str()))/2,"%s", mensagem.c_str());
    noecho();
    getch();
    echo();
    clear();
    endwin();
}

void TelaCadastro::apresentar(Usuario *usuario) {

    char campo1[]="Digite a matricula : ";
    char campo2[]="Digite a senha     : ";
    char campo3[]="Digite o nome     : ";
    char dado1[80];
    char dado2[80];
    char dado3[80];
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/3,(coluna-strlen(campo1))/2,"%s",campo1);
    getstr(dado1);
    mvprintw(linha/3 + 2,(coluna-strlen(campo2))/2,"%s",campo2);
    getstr(dado2);
    mvprintw(linha/3 + 4,(coluna-strlen(campo3))/2,"%s",campo3);
    getstr(dado3);
    clear();
    endwin();

    Matricula matricula;
    matricula.setValor(dado1);
    usuario->setMatricula(matricula);

    Senha senha;
    senha.setValor(dado2);
    usuario->setSenha(senha);

    Nome nome;
    nome.setValor(dado3);
    usuario->setNome(nome);
}

char TelaMenuUsuario::apresentar() {

    char campo1[]="Gerenciamento de Usuario";
    char campo2[]="1 - Consultar";
    char campo3[]="2 - Descadastrar";
    char campo4[]="3 - Editar";
    char campo5[]="4 - Retornar a Tela Inicial";
    char campo6[]="Selecione uma opcao: ";
    char dado1[10];
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/2 - 4,(coluna-strlen(campo1))/2,"%s",campo1);
    mvprintw(linha/2 - 2,(coluna-strlen(campo2))/2,"%s",campo2);
    mvprintw(linha/2,(coluna-strlen(campo3))/2,"%s",campo3);
    mvprintw(linha/2 + 2,(coluna-strlen(campo4))/2,"%s",campo4);
    mvprintw(linha/2 + 4,(coluna-strlen(campo5))/2,"%s",campo5);
    mvprintw(linha/2 + 6,(coluna-strlen(campo6))/2,"%s",campo6);
    getstr(dado1);
    clear();
    endwin();

    return dado1[0];
}

char TelaDescadastro::apresentar() {

    char campo1[]="Deseja confimar o descadastramento? (S/N) ";
    char dado1[80];
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
    getstr(dado1);
    clear();
    endwin();

    return dado1[0];
}

char TelaControle::apresentar() {

    char campo1[]="Seja bem-vindo";
    char campo2[]="1 - Acessar sistema.";
    char campo3[]="2 - Cadastrar usuario.";
    char campo4[]="3 - Encerrar execucao.";
    char campo5[]="Selecione uma opcao: ";
    char dado1[10];
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/2 - 4,(coluna-strlen(campo1))/2,"%s",campo1);
    mvprintw(linha/2 - 2,(coluna-strlen(campo2))/2,"%s",campo2);
    mvprintw(linha/2,(coluna-strlen(campo3))/2,"%s",campo3);
    mvprintw(linha/2 + 2,(coluna-strlen(campo4))/2,"%s",campo4);
    mvprintw(linha/2 + 4,(coluna-strlen(campo5))/2,"%s",campo5);
    getstr(dado1);
    clear();
    endwin();

    return dado1[0];
}

char TelaMenuProjeto::apresentar() {
    char campo1[]="Gerenciamento de Projetos";
    char campo2[]="1. Consultar";
    char campo3[]="2. Cadastrar";
    char campo4[]="3. Editar";
    char campo5[]="4. Descadastrar";

    char campo6[]="Gerenciamento de Tarefas";
    char campo7[]="5. Consultar";
    char campo8[]="6. Cadastrar";
    char campo9[]="7. Editar";
    char campo10[]="8. Descadastrar";

    char campo11[]="9. Voltar";

    char campo12[]="Selecione uma opcao: ";
    char dado1[1];
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/4,(coluna-strlen(campo1))/4,"%s",campo1);
    mvprintw(linha/4 + 2,(coluna-strlen(campo2))/4,"%s",campo2);
    mvprintw(linha/4 + 4,(coluna-strlen(campo3))/4,"%s",campo3);
    mvprintw(linha/4 + 6,(coluna-strlen(campo4))/4,"%s",campo4);
    mvprintw(linha/4 + 8,(coluna-strlen(campo5))/4,"%s",campo5);

    mvprintw(linha/4,3*(coluna-strlen(campo6))/4,"%s",campo6);
    mvprintw(linha/4 + 2,3*(coluna-strlen(campo7))/4,"%s",campo7);
    mvprintw(linha/4 + 4,3*(coluna-strlen(campo8))/4,"%s",campo8);
    mvprintw(linha/4 + 6,3*(coluna-strlen(campo9))/4,"%s",campo9);
    mvprintw(linha/4 + 8,3*(coluna-strlen(campo10))/4,"%s",campo10);

    mvprintw(linha/4 + 12,(coluna-strlen(campo11))/2,"%s",campo11);
    mvprintw(linha/4 + 14,(coluna-strlen(campo12))/2,"%s",campo12);

    getstr(dado1);
    clear();
    endwin();

    return dado1[0];
}

char TelaMenu::apresentar(){

    char campo1[]="Tela inicial: ";
    char campo2[]="1 - Servicos de Usuario";
    char campo3[]="2 - Servicos de Projeto e Tarefa";
    char campo4[]="3 - Sair da conta.";
    char campo5[]="Selecione uma opcao: ";
    char dado1[10];
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/2 - 4,(coluna-strlen(campo1))/2,"%s",campo1);
    mvprintw(linha/2 - 2,(coluna-strlen(campo2))/2,"%s",campo2);
    mvprintw(linha/2,(coluna-strlen(campo3))/2,"%s",campo3);
    mvprintw(linha/2 + 2,(coluna-strlen(campo4))/2,"%s",campo4);
    mvprintw(linha/2 + 4,(coluna-strlen(campo5))/2,"%s",campo5);
    getstr(dado1);
    clear();
    endwin();

    return dado1[0];
}

void TelaCodigo::apresentar(Codigo* codigo) {
    char campo1[]="Codigo: ";
    char dado1[15];
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);
    getstr(dado1);

    clear();
    endwin();

    codigo->setValor(dado1);
}

void TelaConsultaProjeto::apresentar(Projeto* projeto) {
    char campo1[]="Consulta de Projeto";

    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/2 - 10,(coluna-strlen(campo1))/2,"%s",campo1);
    mvprintw(linha/2 - 6,coluna/5,"Nome: %s",projeto->getNome().getValor().c_str());
    mvprintw(linha/2 - 4,coluna/5,"Codigo: %s",projeto->getCodigo().getValor().c_str());
    mvprintw(linha/2 - 2,coluna/5,"Descricao: %s",projeto->getDescricao().getValor().c_str());
    getch();
    clear();
    endwin();
}

void TelaConsultarUsuario::apresentar(Usuario usuario) {
    char campo1[] ="Consultar usuario";
    char campo2[]="Matricula: ";
    char campo3[]="Nome: ";
    char campo4[]="Aperte qualquer tecla para retornar";
    string matricula = usuario.getMatricula().getValor(), nome = usuario.getNome().getValor();

    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/2 - 4,(coluna-strlen(campo1))/2, campo1);
    mvprintw(linha/2 - 2,(coluna-strlen(campo2)-matricula.length())/2, "Matricula: %s", matricula.c_str());
    mvprintw(linha/2,(coluna-strlen(campo3)-nome.length())/2, "Nome: %s", nome.c_str());
    mvprintw(linha/2 + 4,(coluna-strlen(campo4))/2, campo4);
    getch();
    clear();
    endwin();
}


void TelaCadastroProjeto::apresentar(Projeto* projeto) {
    char campo1[]="Digite o codigo : ";
    char campo2[]="Digite o nome : ";
    char campo3[]="Digite a descricao : ";
    char dado1[80];
    char dado2[80];
    char dado3[80];
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/3,(coluna-strlen(campo1))/2,"%s",campo1);
    getstr(dado1);
    mvprintw(linha/3 + 2,(coluna-strlen(campo2))/2,"%s",campo2);
    getstr(dado2);
    mvprintw(linha/3 + 4,(coluna-strlen(campo3))/2,"%s",campo3);
    getstr(dado3);
    clear();
    endwin();

    Codigo codigo;
    codigo.setValor(dado1);
    projeto->setCodigo(codigo);

    Texto nome;
    nome.setValor(dado2);
    projeto->setNome(nome);

    Texto descricao;
    descricao.setValor(dado3);
    projeto->setDescricao(descricao);
}

void TelaEdicaoProjeto::apresentar(Projeto* projeto) {
    char campo1[]="Deixe o campo em branco para manter-lo igual.";
    char campo2[]="Digite o nome : ";
    char campo3[]="Digite a descricao : ";
    char dado1[80];
    char dado2[80];
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/3 - 2,(coluna-strlen(campo1))/2,"%s",campo1);
    mvprintw(linha/3,(coluna-strlen(campo2))/2,"%s",campo2);
    getstr(dado1);
    mvprintw(linha/3 + 2,(coluna-strlen(campo3))/2,"%s",campo3);
    getstr(dado2);
    clear();
    endwin();

    if (dado1[0] != '\0'){
        Texto nome;
        nome.setValor(dado1);
        projeto->setNome(nome);
    }

    if (dado2[0] != '\0') {
        Texto descricao;
        descricao.setValor(dado2);
        projeto->setDescricao(descricao);
    }
}

void TelaEdicaoUsuario::apresentar(Usuario * usuario) {
    char campo1[]="Edicao do usuario";
    char campo2[]="Digite o nome: ";
    char campo3[]="Digite a senha: ";
    char dado1[80], dado2[80];
    int linha,coluna;
    Senha senha;
    Nome nome;

    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/2 - 4,(coluna-strlen(campo1))/2,"%s",campo1);
    mvprintw(linha/2 - 2,(coluna-strlen(campo2))/2,"%s",campo2);
    getstr(dado1);
    nome.setValor(dado1);

    mvprintw(linha/2,(coluna-strlen(campo3))/2,"%s",campo3);
    getstr(dado2);
    senha.setValor(dado2);

    clear();
    endwin();

    usuario->setNome(nome);
    usuario->setSenha(senha);
}

void TelaCadastroTarefa::apresentar(Tarefa* tarefa) {
    char campo1[]="Digite o codigo : ";
    char campo2[]="Digite o nome : ";
    char campo3[]="Digite o codigo do projeto : ";
    char campo4[]="Digite a data de inicio : ";
    char campo5[]="Digite a data de termino : ";
    char campo6[]="Digite a disciplina : ";
    char dado1[80];
    char dado2[80];
    char dado3[80];
    char dado4[80];
    char dado5[80];
    char dado6[80];
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/3,(coluna-strlen(campo1))/2,"%s",campo1);
    getstr(dado1);
    mvprintw(linha/3 + 2,(coluna-strlen(campo2))/2,"%s",campo2);
    getstr(dado2);
    mvprintw(linha/3 + 4,(coluna-strlen(campo3))/2,"%s",campo3);
    getstr(dado3);
    mvprintw(linha/3 + 6,(coluna-strlen(campo4))/2,"%s",campo4);
    getstr(dado4);
    mvprintw(linha/3 + 8,(coluna-strlen(campo5))/2,"%s",campo5);
    getstr(dado5);
    mvprintw(linha/3 + 10,(coluna-strlen(campo6))/2,"%s",campo6);
    getstr(dado6);
    clear();
    endwin();

    Codigo codigo;
    codigo.setValor(dado1);
    tarefa->setCodigo(codigo);

    Texto nome;
    nome.setValor(dado2);
    tarefa->setNome(nome);

    Codigo projeto;
    projeto.setValor(dado3);
    tarefa->setProjeto(projeto);

    Data inicio;
    inicio.setValor(dado4);
    tarefa->setInicio(inicio);

    Data termino;
    termino.setValor(dado5);
    tarefa->setTermino(termino);

    Disciplina disciplina;
    disciplina.setValor(dado6);
    tarefa->setDisciplina(disciplina);
}

void TelaConsultaTarefa::apresentar(Tarefa* tarefa) {
    char campo1[]="Consulta de Tarefa";

    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/2 - 12,(coluna-strlen(campo1))/2,"%s",campo1);
    mvprintw(linha/2 - 8,coluna/5,"Nome: %s",tarefa->getNome().getValor().c_str());
    mvprintw(linha/2 - 6,coluna/5,"Codigo: %s",tarefa->getCodigo().getValor().c_str());
    mvprintw(linha/2 - 4,coluna/5,"Codigo do Projeto: %s",tarefa->getProjeto().getValor().c_str());
    mvprintw(linha/2 - 2,coluna/5,"Inicio: %s",tarefa->getInicio().getValor().c_str());
    mvprintw(linha/2,coluna/5,"Termino: %s",tarefa->getTermino().getValor().c_str());
    mvprintw(linha/2 + 2,coluna/5,"Disciplina: %s",tarefa->getDisciplina().getValor().c_str());
    getch();
    clear();
    endwin();

}

void TelaEdicaoTarefa::apresentar(Tarefa* tarefa) {
    char campo1[]="Deixe o campo em branco para manter-lo igual.";
    char campo2[]="Digite o nome : ";
    char campo3[]="Digite a data de inicio : ";
    char campo4[]="Digite a data de termino : ";
    char campo5[]="Digite a disciplina : ";

    char dado1[80];
    char dado2[80];
    char dado3[80];
    char dado4[80];

    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/3 - 2,(coluna-strlen(campo1))/2,"%s",campo1);
    mvprintw(linha/3,(coluna-strlen(campo2))/2,"%s",campo2);
    getstr(dado1);
    mvprintw(linha/3 + 2,(coluna-strlen(campo3))/2,"%s",campo3);
    getstr(dado2);
    mvprintw(linha/3 + 4,(coluna-strlen(campo4))/2,"%s",campo4);
    getstr(dado3);
    mvprintw(linha/3 + 6,(coluna-strlen(campo5))/2,"%s",campo5);
    getstr(dado4);
    clear();
    endwin();

    if (dado1[0] != '\0'){
        Texto nome;
        nome.setValor(dado1);
        tarefa->setNome(nome);
    }

    if (dado2[0] != '\0'){
        Data inicio;
        inicio.setValor(dado2);
        tarefa->setInicio(inicio);
    }

    if (dado3[0] != '\0'){
        Data termino;
        termino.setValor(dado3);
        tarefa->setTermino(termino);
    }

    if (dado4[0] != '\0'){
        Disciplina disciplina;
        disciplina.setValor(dado4);
        tarefa->setDisciplina(disciplina);
    }

}
