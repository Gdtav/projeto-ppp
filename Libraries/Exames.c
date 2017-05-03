//
// Created by Utilizador on 29/04/2017.
//
#include "Exames.h"


int verificaNum(Lista_Alunos lst, int num){
    Lista_Alunos ptr = lst;
    int find;
    for(find = 0; ptr != NULL && find == 0; ptr = ptr->next)
        find = (ptr->aluno.num == num)? 1 : 0;
    return find;
}

void procuraAluno (Lista_Alunos lst, Aluno chave, Lista_Alunos *ant, Lista_Alunos *act)
{
    *ant = NULL; *act = lst;
    while ((*act) != NULL && strcmp((*act)->aluno.nome, chave.nome) < 0)
    {
        *ant = *act;
        *act = (*act)->next;
    }
    if ((*act) != NULL && strcmp((*act)->aluno.nome, chave.nome) != 0)
        *act = NULL; /* Se elemento não encontrado*/
}

Lista_Alunos insereAluno(Lista_Alunos lst, Aluno aluno){
    if(verificaNum(lst, aluno.num)){
        printf("Já existe um aluno com esse número na base de dados! Abortando...");
        return lst;
    }
    Lista_Alunos no;
    Lista_Alunos ant, act;
    no = (Lista_Alunos) malloc (sizeof (No_Aluno));
    if (no != NULL) {
        no->aluno = aluno;
        procuraAluno(lst, aluno, &ant, &act);
        if (ant != NULL) {
            no->next = ant->next;
            no->prev = ant;
            if (ant->next != NULL)
                ant->next->prev = no;
            ant->next = no;
        }
        else {
            no->next = lst;
            no->prev = NULL;
            lst = no;
        }
    }
    else
        printf("Erro de memoria. Nao foi possivel adicionar aluno.")
    return lst;
}

Lista_Alunos criaAluno(Lista_Alunos lst){
    Aluno novo;
    char *nome = malloc(TAM_STR * sizeof(char));
    int num, ano;
    char *curso = malloc(TAM_STR * sizeof(char));
    char regime;
    printf("Nome do aluno: ");
    fflush(stdin);
    gets(nome);
    novo.nome = nome;
    fflush(stdin);
    printf("Numero do aluno: ");
    scanf("%d", &num);
    novo.num = num;
    printf("Numero de matriculas: ");
    scanf("%d", &ano);
    novo.ano = ano;
    printf("Curso do aluno: ");
    gets(curso);
    novo.curso = curso;
    fflush(stdin);
    printf("Regime do aluno\n(n -> normal,\nt -> trabalhador-estudante,\na -> atleta,\nd -> dirigente associativo,\ne -> aluno de Erasmus): ");
    scanf("%c", &regime);
    novo.regime = regime;
    novo.exames = NULL;
    lst = insereAluno(lst, novo);
    return lst;
}