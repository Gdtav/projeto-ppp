//
// Created by guilh on 23/05/2017.
//

#include "Ficheiros.h"
#include "Estruturas.h"

void leFicheiroDisciplinas(Lista_Disciplinas *disciplinas, FILE *fich_disc){
    char *nome = malloc(TAM_STR * sizeof(char));
    char *docente = malloc(TAM_STR * sizeof(char));
    while (fgets(nome,TAM_STR,fich_disc),fgets(docente,TAM_STR,fich_disc)) {
        Disciplina disc;
        disc.nome = malloc(TAM_STR * sizeof(char));
        disc.docente = malloc(TAM_STR * sizeof(char));
        strcpy(disc.nome, nome);
        strcpy(disc.docente, docente);
        *disciplinas = insereDisciplina(*disciplinas,disc);
        printf("%s\n", disc.nome);
        printf("%s\n", disc.docente);
    }
}