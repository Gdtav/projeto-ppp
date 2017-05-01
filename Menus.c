//
// Created by guilh on 01/05/2017.
//

#include <stdio.h>
#include "Menus.h"

void menuPrincipal(){
    int opcao;
    printf("Bem vindo ao gestor de exames do DEI. \nPor favor insira a opção desejada:");
    printf("1 - Gerir alunos\n");
    printf("2 - gerir disciplinas\n");
    printf("3 - Criar novo exame\n");
    printf("4 - Eliminar exames realizados\n");
    printf("5 - Listar exames\n");
    printf("6 - Gerir inscrições de alunos\n");
    printf("7 - Listar alunos inscritos num exame\n");
    printf("8 - Listar exames de um aluno\n");
    printf("9 - Gerir salas de exames\n");
    scanf("%d", &opcao);
    while (opcao < 1 || opcao > 9) {
        printf("Por favor, insira o numero da operação desejada (de 1 a 9):");
        scanf("%d", &opcao);
    }

}