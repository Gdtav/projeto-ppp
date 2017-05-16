//
// Created by guilh on 03/05/2017.
//
#include "Disciplinas.h"

void imprimeDisciplinas(Lista_Disciplinas disciplinas){
    Lista_Disciplinas ptr = disciplinas;
    int i = 0;
    for (ptr; ptr != NULL; ptr = ptr->next, i++)
        printf("%d - %s \n", i, ptr->disciplina.nome);
}

Lista_Disciplinas pesquisaDisciplinas(Lista_Disciplinas disciplinas, char* nome){
    Lista_Disciplinas ptr = disciplinas;
    while (ptr && strcmp(ptr->disciplina.nome,nome))
        ptr = ptr->next;
    return ptr;
}

Lista_Disciplinas insereDisciplina(Lista_Disciplinas disciplinas, Disciplina nova){
    Lista_Disciplinas no;
    Lista_Disciplinas act;
    no = (Lista_Disciplinas) malloc(sizeof(No_Disciplina));
    if (no != NULL){
        no->disciplina = nova;
        act = disciplinas;
        while (act->next != NULL)
            act = act->next;
        act->next = no;
        no->prev = act;
        no->next = NULL;
    }
    return disciplinas;
}

Lista_Disciplinas criaDisciplina(Lista_Disciplinas disciplinas){
    Disciplina nova;
    char *nome = malloc(TAM_STR * sizeof(char));
    char *docente = malloc(TAM_STR * sizeof(char));
    fflush(stdin);
    printf("Insira o nome da Disciplina:\n");
    gets(nome);
    nova.nome = nome;
    printf("Insira o nome do Docente:\n");
    fflush(stdin);
    gets(docente);
    nova.docente = docente;
    disciplinas = insereDisciplina(disciplinas,nova);
    return disciplinas;
}

Lista_Disciplinas eliminaDisciplina(Lista_Disciplinas disciplinas){
    Lista_Disciplinas no;
    printf("Insira o nome da disciplina que deseja eliminar:\n");
    imprimeDisciplinas(disciplinas);
    char* nome = (char*) malloc(TAM_STR * sizeof(char));
    fflush(stdin);
    gets(nome);
    no = pesquisaDisciplinas(disciplinas,nome);
    if (no == NULL) {
        printf("Essa disciplina nao existe. Abortando...");
        return disciplinas;
    }
    if (no->next != NULL)
        no->next->prev = no->prev;
    if (no->prev != NULL)
        no->prev->next = no->next;
    else
        disciplinas = no->next;
    free(no);
    return disciplinas;
}

Lista_Disciplinas modificaDisciplina(Lista_Disciplinas disciplinas){
    Lista_Disciplinas no;
    printf("Insira o nome da disciplina que deseja modificar:\n");
    imprimeDisciplinas(disciplinas);
    char* nome = (char*) malloc(TAM_STR * sizeof(char));
    char* docente = (char*) malloc(TAM_STR * sizeof(char));
    fflush(stdin);
    gets(nome);
    no = pesquisaDisciplinas(disciplinas,nome);
    if (no == NULL) {
        printf("Essa disciplina nao existe. Abortando...");
        return disciplinas;
    }
    printf("Insira o novo nome da disciplina:\n");
    fflush(stdin);
    gets(nome);
    no->disciplina.nome = nome;
    printf("Insira o novo nome do docente:\n");
    fflush(stdin);
    gets(docente);
    no->disciplina.docente = docente;
    return disciplinas;
}