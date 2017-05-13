//
// Created by Utilizador on 29/04/2017.
//
#include "Exames.h"
#include "Alunos.h"

int date_cmp (Data d1, Data d2){
    if (d1.ano < d2.ano)
        return -1;
    else if(d1.ano > d2.ano)
        return 1;
    if (d1.mes < d2.mes)
        return -1;
    else if(d1.mes > d2.mes)
        return 1;
    if (d1.dia < d2.dia)
        return -1;
    else if(d1.dia > d2.dia)
        return 1;
    return 0;
}

void imprimeData(Data d){
    printf("%d/%d/%d", d.dia, d.mes, d.ano);
}

void imprimeHora(Hora h){
    printf("%d:%d", h.horas, h.minutos);
}

void imprimeExame(Exame exame){
    printf("Disciplina: %s\n", exame.disciplina->nome);
    printf("Epoca: ");
    switch(exame.epoca){
        case 'n': printf("Normal\n");
            break;
        case 'r': printf("Recurso\n");
            break;
        case 'e': printf("Especial\n");
            break;
        default: printf("Epoca introduzida invalida! Modifique este exame!\n");
            break;
    }
    printf("Data: ");
    imprimeData(exame.data);
    printf("\nHora: ");
    imprimeHora(exame.hora);
    printf("\nDuracao: %d\n", exame.duracao);
    printf("Sala: %s\n", exame.sala);
}

void imprimeExamesAluno(Lista_Alunos lst){
    Lista_Ptr_Exames ptr;
    int num;
    Lista_Alunos no;
    printf("Numero do aluno: ");
    scanf("%d", &num);
    no = pesquisaNum(lst, num);
    if (no == NULL){
        printf("Nao existe aluno na base de dados com esse numero! Abortando...\n");
        return;
    }
    for (ptr = no->aluno.exames; ptr != NULL; ptr = ptr->next)
        imprimeExame(*(ptr->exame));
}