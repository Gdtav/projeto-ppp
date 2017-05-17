//
// Created by guilh on 13/05/2017.
//

#ifndef PROJETO_ALUNOS_H
#define PROJETO_ALUNOS_H

#include "Estruturas.h"
#include "Exames.h"

Lista_Alunos pesquisaNumAluno(Lista_Alunos, int);

Lista_Ptr_Alunos pesquisaNumPtrAluno(Lista_Ptr_Alunos, int);

void procuraAluno(Lista_Alunos, Aluno, Lista_Alunos *, Lista_Alunos *);

void procuraPtrAluno(Lista_Ptr_Alunos, Aluno, Lista_Ptr_Alunos *, Lista_Ptr_Alunos *);

Lista_Alunos insereAluno(Lista_Alunos, Aluno;

Lista_Ptr_Alunos inserePtrAluno(Lista_Ptr_Alunos, Lista_Alunos);

Lista_Alunos criaAluno(Lista_Alunos);

void modificaAluno(Lista_Alunos);

Lista_Alunos eliminaAluno(Lista_Alunos);

void imprimeAluno(Aluno);

void imprimeAlunos(Lista_Alunos);

void imprimeExamesAluno(Lista_Alunos);

#endif //PROJETO_ALUNOS_H