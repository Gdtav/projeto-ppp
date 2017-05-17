#ifndef PROJETO_EXAMES_H
#define PROJETO_EXAMES_H

#include "Estruturas.h"
#include "Alunos.h"
#include "Tempo.h"
#include "Disciplinas.h"

void imprimeExame(Exame );

void imprimeExamesAluno(Lista_Alunos );

Lista_Exames criaExame(Lista_Exames , Lista_Disciplinas );

Lista_Ptr_Alunos inscreveAluno(Lista_Ptr_Alunos , Lista_Alunos, Lista_Exames );

Lista_Exames eliminaExamesAntigos(Lista_Exames );

void imprimeExames(Lista_Exames );

void imprimeAlunosInscritos(Lista_Exames );

#endif //PROJETO_EXAMES_H