//
// Created by guilh on 23/05/2017.
//

#include "Ficheiros.h"
#include "Estruturas.h"

void leFicheiroDisciplinas(Lista_Disciplinas *disciplinas, FILE *fich_disc){
    Disciplina *disc = malloc(sizeof(Disciplina));
    while (fgets(disc->nome,TAM_STR,fich_disc),fgets(disc->docente,TAM_STR,fich_disc)) {
        *disciplinas = insereDisciplina(*disciplinas,*disc);
        printf(disc->nome);
        printf(disc->docente);
    }
}