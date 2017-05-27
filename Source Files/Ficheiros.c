//
// Created by guilh on 23/05/2017.
//

#include "Ficheiros.h"

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

void leFicheiroAlunos(Lista_Alunos *alunos, FILE *fich_aln){
    char *nome = malloc(TAM_STR * sizeof(char));
    char *curso = malloc(TAM_STR * sizeof(char));
    char *linha = malloc(TAM_STR * sizeof(char));
    int numero, ano;
    char regime;
    while (fgets(nome,TAM_STR,fich_aln),fgets(curso,TAM_STR,fich_aln)) {
        Aluno aln;
        aln.nome = malloc(TAM_STR * sizeof(char));
        aln.curso = malloc(TAM_STR * sizeof(char));
        strcpy(aln.nome, nome);
        strcpy(aln.curso, curso);
        fgets(linha, TAM_STR, fich_aln);
        numero = atoi(linha);
        aln.num = numero;
        fgets(linha, TAM_STR, fich_aln);
        ano = atoi(linha);
        aln.ano = ano;
        regime = (char) fgetc(fich_aln);
        aln.regime = regime;
        aln.exames = NULL;
        *alunos = insereAluno(*alunos, aln);
    }
}

void leFicheiroExames(Lista_Exames *exames, FILE *fich_exm){
    Lista_Disciplinas disciplina;
    char epoca;
    Data data;
    Hora hora;
    int num;
    int duracao;
    Lista_Salas salas;
    Lista_Ptr_Alunos alunos;
    char *linha = malloc(TAM_STR * sizeof(char));
    while (fgets(linha,TAM_STR,fich_exm)) {
        num = atoi(linha);
        fgets(linha,TAM_STR,fich_exm);
        duracao = atoi(linha);
        epoca = (char) fgetc(fich_exm);

    }
}