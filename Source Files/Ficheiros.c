//
// Created by guilh on 23/05/2017.
//

#include "Ficheiros.h"
#include "Estruturas.h"


Lista_Disciplinas leFicheiroDisciplinas(Lista_Disciplinas disc, FILE *fich_disc){
    fseek(fich_disc,0L,SEEK_SET);
    Disciplina *discip = malloc(sizeof(Disciplina));
    while (fgets(discip->nome,TAM_STR,fich_disc)) {
        fgets(discip->docente, TAM_STR, fich_disc);
        insereDisciplina(disc,*discip);
    }
    return disc;
}

Lista_Alunos leFicheirosAlunos(Lista_Alunos alns, FILE *fich_alns){

}