//
// Created by guilh on 01/05/2017.
//

#include <stdio.h>
#include "Menus.h"
#include "Exames.h"

void menuPrincipal(){
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
        switch (opcao){
            case 1: menuAlunos(); break;
            case 2: menuDisciplinas(); break;
            case 3: menuExames(); break;
            case 4: return;
            default: break;
        }
    } while (TRUE);
}

void menuAlunos(){
    int opcao;
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
    switch (opcao){
        case 1: criaAluno(); break;
        case 2: modificaAluno(); break;
        case 3: eliminaAluno(); break;
        case 4: imprimeExamesAluno(); break;
        case 5: return;
        default: break;
    }
}

void menuDisciplinas(){
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
    switch (opcao){
        case 1: criaDisciplina(); break;
        case 2: modificaDisciplina(); break;
        case 3: eliminaDisciplina(); break;
        case 4: return;
        default: break;
    }
}

void menuExames(){
    int opcao;
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
    switch (opcao){
        case 1: criaExame(); break;
        case 2: menuSalas(); break;
        case 3: eliminaExamesAntigos(); break;
        case 4: imprimeExames(); break;
        case 5: menuInscricoes(); break;
        case 6: imprimeAlunosInscritos(); break;
        case 7: return;
        default: break;
    }
}

void menuSalas(){
    int opcao;
    printf("Gestao de salas \n Por favor insira a opcao desejada:\n");
    printf("1 - Atribuir salas a exame\n");
    printf("2 - Listar Salas vazias\n");
    printf("3 - Voltar\n");
    scanf("%d", &opcao);
    while (opcao < 1 || opcao > 7) {
        printf("Por favor, insira o numero da operacao desejada (de 1 a 3):");
        scanf("%d", &opcao);
    }
    switch (opcao){
        case 1: atribuiSalas(); break;
        case 2: imprimeSalasVazias(); break;
        case 3: return;
        default: break;
    }
}

void menuInscricoes(){
    int opcao;
    printf("Gestao de inscricoes \n Por favor insira a opcao desejada:\n");
    printf("1 - Adicionar aluno a exame\n");
    printf("2 - Remover aluno de exame\n");
    printf("3 - Voltar\n");
    scanf("%d", &opcao);
    while (opcao < 1 || opcao > 7) {
        printf("Por favor, insira o numero da operacao desejada (de 1 a 3):");
        scanf("%d", &opcao);
    }
    switch (opcao){
        case 1: inscreveAluno(); break;
        case 2: removeAluno(); break;
        case 3: return;
        default: break;
    }
}