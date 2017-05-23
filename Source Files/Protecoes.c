#include "Protecoes.h"

void p_scan_int(int *num){
    int s_check = 1, test = 0;
    s_check = scanf("%d", num);
    test = getchar();
    fflush(stdin);
    while (s_check == 0 || test != '\n'){
        printf("Insira um NUMERO: ");
        s_check = scanf("%d", num);
        test = getchar();
        fflush(stdin);
    }
}

void p_scan_numAluno(Lista_Alunos alunos, int *num){
    int s_check = 1, test = 0;
    Lista_Alunos e_check;
    s_check = scanf("%d", num);
    test = getchar();
    e_check = pesquisaNumAluno(alunos, *num);
    fflush(stdin);
    while (s_check == 0 || e_check || test != '\n'){
        if(s_check || test != '\n')
            printf("Insira um NUMERO: ");   //  ESTA PROTECAO JÁ FUNCIONA :O
        else if(e_check)
            printf("Ja existe um aluno com esse numero! Insira outro");
        s_check = scanf("%d", num);
        test = getchar();
        e_check = pesquisaNumAluno(alunos, *num);
        fflush(stdin);
    }
}
