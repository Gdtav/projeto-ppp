//
// Created by guilh on 01/05/2017.
//

#include <stdio.h>
#include "Menus.h"

void menuPrincipal(){
    int opcao;
    printf("Bem vindo ao gestor de exames do DEI. \n Por favor insira a opcao desejada:\n");
    printf("1 - Gerir alunos\n");
    printf("2 - gerir disciplinas\n");
    printf("3 - Gerir exames\n");
    scanf("%d", &opcao);
    while (opcao < 1 || opcao > 3) {
        printf("Por favor, insira o numero da operacao desejada (de 1 a 3):");
        scanf("%d", &opcao);
    }
    switch (opcao){
        case 1: menuAlunos(); break;
        case 2: menuDisciplinas(); break;
        /*case 3: criaExame(); break;
        case 4: eliminaExames(); break;
        case 5: imprimeExames(); break;
        case 6: inscreveAlunos(); break;                PENSAR ESTA PARTE!
        case 7: imprimeAlunosInscritos(); break;
        case 8: imprimeExamesAluno(); break;
        case 9: gerirSalas(); break;*/
        default: break;
    }
}

void menuAlunos(){
    int opcao;
    printf("Gestao de alunos \n Insira o numero da opcao desejada:\n");
    printf("1 - adicionar aluno\n");
    printf("2 - modificar aluno\n");
    printf("3 - eliminar aluno\n");
    printf("4 - Listar exames do aluno\n");
    scanf("%d", &opcao);
    while (opcao < 1 || opcao > 3) {
        printf("Por favor, insira o numero da operacao desejada (de 1 a 3):");
        scanf("%d", &opcao);
    }
}

void menuDisciplinas(){
    int opcao;
    printf("Gestao de disciplinas \n Insira o numero da opcao desejada:\n");
    printf("1 - adicionar disciplina\n");
    printf("2 - modificar disciplina\n");
    printf("3 - eliminar disciplina\n");
    scanf("%d", &opcao);
    while (opcao < 1 || opcao > 3) {
        printf("Por favor, insira o numero da operacao desejada (de 1 a 3):");
        scanf("%d", &opcao);
    }
}


void menuExames(){
    int opcao;
    printf("Gestao de exames \n Insira o numero da opcao desejada:\n");
    printf("1 - criar/eliminar exame\n");
    printf("2 - configurar salas\n");
    printf("3 - eliminar exames realizados\n");
    printf("4 - listar exames\n");
    printf("5 - gerir inscricoes de alunos\n");
    printf("6 - listar alunos inscritos em exame\n");
    scanf("%d", &opcao);
    while (opcao < 1 || opcao > 3) {
        printf("Por favor, insira o numero da operacao desejada (de 1 a 3):");
        scanf("%d", &opcao);
    }
}