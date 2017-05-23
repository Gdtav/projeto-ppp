//
// Created by guilh on 23/05/2017.
//

#include "Ficheiros.h"
#include "Estruturas.h"


Lista_Disciplinas leFicheiroDisciplinas(Lista_Disciplinas disc, FILE *fich_disc){
    char *linha = (char *) malloc(TAM_STR * sizeof(char));
    while (fgets(linha,TAM_STR,fich_disc)){
        while(*linha != ';'){
            disc->disciplina.nome = linha;
            linha++;
        }
        linha++;
        while(*linha != '\n'){
            disc->disciplina.docente = linha;
            linha++;
        }
        disc->next;
    }
    return disc;
}

Lista_Alunos leFicheirosAlunos(Lista_Alunos alns, FILE *fich_alns){

}