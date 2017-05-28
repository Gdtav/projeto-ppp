//
// Created by guilh on 23/05/2017.
//

#ifndef PROJETO_FICHEIROS_H
#define PROJETO_FICHEIROS_H

#include "Estruturas.h"
#include "Disciplinas.h"

void leFicheiroDisciplinas(Lista_Disciplinas *,FILE * );

void leFicheiroAlunos(Lista_Alunos *,FILE * );

void leFicheiroExames(Lista_Exames *,FILE * ,Lista_Disciplinas ,Lista_Alunos );

#endif //PROJETO_FICHEIROS_H
