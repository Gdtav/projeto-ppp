//
// Created by guilh on 13/05/2017.
//

#include "Alunos.h"

Lista_Alunos pesquisaNum(Lista_Alunos lst, int num){
    Lista_Alunos ptr = lst;
    Lista_Alunos find;
    for(find = 0; ptr != NULL && find == 0; ptr = ptr->next)
        find = (ptr->aluno.num == num)? ptr : NULL;
    return find;
}

void procuraAluno (Lista_Alunos lst, Aluno chave, Lista_Alunos *ant, Lista_Alunos *act)
{
    *ant = NULL; *act = lst;
    while ((*act) != NULL && strcmpi((*act)->aluno.nome, chave.nome) < 0)
    {
        *ant = *act;
        *act = (*act)->next;
    }
    if ((*act) != NULL && strcmpi((*act)->aluno.nome, chave.nome) != 0)
        *act = NULL; /* Se elemento não encontrado*/
}

Lista_Alunos insereAluno(Lista_Alunos lst, Aluno aluno){
    if(pesquisaNum(lst, aluno.num)){
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
        printf("Erro de memoria. Nao foi possivel adicionar aluno.");
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

void modificaAluno(Lista_Alunos lst){
    int num, escolha = 0;
    Lista_Alunos no;
    printf("Numero do aluno a modificar: ");
    scanf("%d", &num);
    no = pesquisaNum(lst, num);
    if (no == NULL){
        printf("Nao existe aluno na base de dados com esse numero! Abortando...\n");
        return;
    }
    while(escolha != 5){
        printf("\nModificar:\n1 - Nome\n2 - Matriculas\n3 - Curso\n4 - Regime\n\n5 - Voltar\n\nEscolha a opcao: ");
        scanf("%d", &escolha);
        fflush(stdin);
        switch (escolha){
            case 1: printf("Introduza o novo nome: ");
                gets(no->aluno.nome);
                fflush(stdin);
                break;
            case 2: printf("Introduza o numero de matriculas: ");
                scanf("%d", &(no->aluno.ano));
                break;
            case 3: printf("Introduza o nome do curso: ");
                gets(no->aluno.curso);
                fflush(stdin);
                break;
            case 4: printf("Introduza o regime do aluno\n(n -> normal,\nt -> trabalhador-estudante,\na -> atleta,\nd -> dirigente associativo,\ne -> aluno de Erasmus): ");
                scanf("%c", &(no->aluno.regime));
                break;
            case 5:
                break;
            default: printf("Opcao invalida! Escolha outra opcao...\n");
                break;
        }
    }
}

Lista_Alunos eliminaAluno(Lista_Alunos lst){
    int num;
    Lista_Alunos no;
    printf("Numero do aluno a eliminar: ");
    scanf("%d", &num);
    no = pesquisaNum(lst, num);
    if (no == NULL){
        printf("Nao existe aluno na base de dados com esse numero! Abortando...\n");
        return lst;
    }
    if (no->next != NULL)
        no->next->prev = no->prev;
    if (no->prev != NULL)
        no->prev->next = no->next;
    else
        lst = no->next;
    free(no);
    return lst;
}