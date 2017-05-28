//
// Created by guilh on 23/05/2017.
//

#include "Ficheiros.h"
#include "Estruturas.h"

void leFicheiroDisciplinas(Lista_Disciplinas *disciplinas, FILE *fich_disc){
    char *nome = malloc(TAM_STR * sizeof(char));
    char *docente = malloc(TAM_STR * sizeof(char));
    while (fgets(nome, TAM_STR, fich_disc), fgets(docente, TAM_STR, fich_disc)) {
        Disciplina disc;
        disc.nome = malloc(TAM_STR * sizeof(char));
        disc.docente = malloc(TAM_STR * sizeof(char));
        strcpy(disc.nome, nome);
        strcpy(disc.docente, docente);
        *disciplinas = insereDisciplina(*disciplinas, disc);
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
    while (fgets(nome, TAM_STR, fich_aln), fgets(curso, TAM_STR, fich_aln)) {
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

void leFicheiroExames(Lista_Exames *exames, FILE *fich_exm, Lista_Disciplinas disciplinas, Lista_Alunos alunos){
    Exame exm;
    Lista_Disciplinas disciplina;
    char epoca;
    Data data;
    Hora hora;
    int num;
    int duracao;
    Lista_Salas salas = malloc(sizeof(Lista_Salas));
    Lista_Ptr_Alunos alns = malloc(sizeof(Lista_Ptr_Alunos));
    char *linha = malloc(TAM_STR * sizeof(char));
    while (fgets(linha, TAM_STR, fich_exm)) {
        num = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        duracao = atoi(linha);
        epoca = (char) fgetc(fich_exm);
        fgets(linha, TAM_STR, fich_exm);
        data.dia = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        data.mes = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        data.ano = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        hora.horas = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        hora.minutos = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        disciplina = pesquisaDisciplinas(disciplinas, linha);
        fgets(linha, TAM_STR, fich_exm);
        while (!atoi(linha)) {
            strcpy(linha, salas->nome);
            salas = salas->next;
            fgets(linha, TAM_STR, fich_exm);
        }
        while (atoi(linha)) {
            alns->aluno = pesquisaNumAluno(alunos, atoi(linha));
            alns = alns->next;
            fgets(linha, TAM_STR, fich_exm);
        }
        exm.num = num;
        exm.disciplina = disciplina;
        exm.alunos = alns;
        exm.salas = salas;
        exm.epoca = epoca;
        exm.data = data;
        exm.duracao = duracao;
        exm.hora = hora;
        insereExame(*exames, exm);
        fgets(linha, TAM_STR, fich_exm);
    }
}