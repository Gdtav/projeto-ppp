//
// Created by guilh on 01/05/2017.
//

#include "Menus.h"

void menuAlunos(Lista_Alunos alunos) {
    int opcao = 0;
    while (opcao != 5) {
        printf("Gestao de alunos \n Insira o numero da opcao desejada:\n");
        printf("1 - Adicionar aluno\n");
        printf("2 - Modificar aluno\n");
        printf("3 - Eliminar aluno\n");
        printf("4 - Listar exames do aluno\n");
        printf("5 - Voltar\n");
        scanf("%d", &opcao);
        while (opcao < 1 || opcao > 5) {
            printf("Por favor, insira o numero da operacao desejada (de 1 a 5):");
            scanf("%d", &opcao);
        }
        switch (opcao) {
            case 1:
                alunos = criaAluno(alunos);
                break;
            case 2:
                modificaAluno(alunos);
                break;
            case 3:
                eliminaAluno(alunos);
                break;
            case 4:
                imprimeExamesAluno(alunos);
                break;
            default:
                break;
        }
    }
}

void menuDisciplinas() {
    int opcao;
    printf("Gestao de disciplinas \n Insira o numero da opcao desejada:\n");
    printf("1 - Adicionar disciplina\n");
    printf("2 - Modificar disciplina\n");
    printf("3 - Eliminar disciplina\n");
    printf("4 - Voltar\n");
    scanf("%d", &opcao);
    while (opcao < 1 || opcao > 4) {
        printf("Por favor, insira o numero da operacao desejada (de 1 a 4):");
        scanf("%d", &opcao);
    }
    switch (opcao) {
        case 1:
            criaDisciplina(disciplinas);
            break;
        case 2:
            modificaDisciplina(disciplinas);
            break;
        case 3:
            eliminaDisciplina(disciplinas, &exames);
            break;
        case 4:
            return;
        default:
            break;
    }
}

void menuSalas(Lista_Exames exames) {
    int opcao;
    printf("Gestao de salas \n Por favor insira a opcao desejada:\n");
    printf("1 - Atribuir salas a exame\n");
    printf("2 - Verificar salas suficientes\n");
    printf("3 - Voltar\n");
    scanf("%d", &opcao);
    while (opcao < 1 || opcao > 3) {
        printf("Por favor, insira o numero da operacao desejada (de 1 a 3):");
        scanf("%d", &opcao);
    }
    switch (opcao) {
        case 1:
            atribuiSalas(exames);
            break;
        case 2:
            verificaSalasSuficientes(exames);
            break;
        case 3:
            return;
        default:
            break;
    }
}

void menuInscricoes() {
    int opcao;
    printf("Gestao de inscricoes \n Por favor insira a opcao desejada:\n");
    printf("1 - Adicionar aluno a exame\n");
    printf("2 - Remover aluno de exame\n");
    printf("3 - Voltar\n");
    scanf("%d", &opcao);
    while (opcao < 1 || opcao > 3) {
        printf("Por favor, insira o numero da operacao desejada (de 1 a 3):");
        scanf("%d", &opcao);
    }
    switch (opcao) {
        case 1:
            inscreveAluno(exames, alunos);
            break;
        case 2:
            removeInscricao(exames);
            break;
        case 3:
            return;
        default:
            break;
    }
}

void menuExames() {
    int opcao, num;
    printf("Gestao de exames \n Insira o numero da opcao desejada:\n");
    printf("1 - Criar exame\n");
    printf("2 - Configurar salas\n");
    printf("3 - Eliminar exames realizados\n");
    printf("4 - Listar exames\n");
    printf("5 - Gerir inscricoes de alunos\n");
    printf("6 - Listar alunos inscritos em exame\n");
    printf("7 - Voltar\n");
    scanf("%d", &opcao);
    while (opcao < 1 || opcao > 7) {
        printf("Por favor, insira o numero da operacao desejada (de 1 a 7):");
        scanf("%d", &opcao);
    }
    switch (opcao) {
        case 1:
            criaExame(exames,disciplinas);
            break;
        case 2:
            menuSalas(exames);
            break;
        case 3:
            eliminaExamesAntigos(exames);
            break;
        case 4:
            imprimeExames(exames);
            break;
        case 5:
            menuInscricoes();
            break;
        case 6:
            imprimeExames(exames);
            printf("Insira o numero do exame que pretende ver:\n");
            while (scanf("%d", &num) == 0)
                printf("Insira um NUMERO:\n");
            imprimeAlunosInscritos(pesquisaNumExame(exames, num)->exame);
            break;
        case 7:
            return;
        default:
            break;
    }
}

void menuPrincipal() {
    int opcao;
    do {
        printf("Bem vindo ao gestor de exames do DEI. \n Por favor insira a opcao desejada:\n");
        printf("1 - Gerir alunos\n");
        printf("2 - gerir disciplinas\n");
        printf("3 - Gerir exames\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);
        while (opcao < 1 || opcao > 4) {
            printf("Por favor, insira o numero da operacao desejada (de 1 a 4):");
            scanf("%d", &opcao);
        }
        switch (opcao) {
            case 1:
                menuAlunos(alunos);
                break;
            case 2:
                menuDisciplinas();
                break;
            case 3:
                menuExames();
                break;
            case 4:
                return;
            default:
                break;
        }
    } while (1);
}