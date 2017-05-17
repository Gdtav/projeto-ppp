#ifndef PROJETO_EXAMES_H
#define PROJETO_EXAMES_H

#include "Estruturas.h"
#include "Alunos.h"
#include "Tempo.h"
#include "Disciplinas.h"

Lista_Exames pesquisaNumExame(Lista_Exames, int);

Lista_Ptr_Exames pesquisaNumPtrExame(Lista_Ptr_Exames, int);

void procuraExame(Lista_Exames, Exame, Lista_Exames *, Lista_Exames *);

void procuraPtrExame(Lista_Ptr_Exames, Exame, Lista_Ptr_Exames *, Lista_Ptr_Exames *);

void procuraSala(Lista_Salas, char *, Lista_Salas *, Lista_Salas *);

Lista_Exames insereExame(Lista_Exames, Exame);

Lista_Ptr_Exames inserePtrExame(Lista_Ptr_Exames, Lista_Exames);

Lista_Salas insereSala(Lista_Salas, char *);

void atribuiSalas(Lista_Exames);

Lista_Exames criaExame(Lista_Exames, Lista_Disciplinas);

Lista_Exames eliminaExamesAntigos(Lista_Exames);

void imprimeExame(Exame);

void imprimeExames(Lista_Exames);

void imprimeAlunosInscritos(Lista_Ptr_Alunos);

void imprimeExamesAluno(Lista_Alunos);

void inscreveAluno(Lista_Exames, Lista_Alunos);

#endif //PROJETO_EXAMES_H