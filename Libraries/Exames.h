//
// Created by Utilizador on 29/04/2017.
//

#ifndef PROJETO_EXAMES_H
#define PROJETO_EXAMES_H

#endif //PROJETO_EXAMES_H

#define TAM_STR 100

#include "Estruturas.h"

int date_cmp (Data, Data);

void imprimeData(Data);

Lista_Alunos pesquisaNum(Lista_Alunos, int);

void procuraAluno (Lista_Alunos, Aluno, Lista_Alunos *, Lista_Alunos *);

Lista_Alunos insereAluno(Lista_Alunos, Aluno);

Lista_Alunos criaAluno(Lista_Alunos);

void modificaAluno(Lista_Alunos);

Lista_Alunos eliminaAluno(Lista_Alunos);

void imprimeExame(Exame);

void imprimeExamesAluno(Lista_Alunos);

