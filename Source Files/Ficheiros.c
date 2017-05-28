//
// Created by guilh on 23/05/2017.
//
#include "Ficheiros.h"

void leFicheiroDisciplinas(Lista_Disciplinas *disciplinas, FILE *fich_disc){
    char *ptr = NULL;
    int in = 1;
    char *nome;
    char *docente = (char *) malloc(TAM_STR * sizeof(char));
    nome = malloc(TAM_STR * sizeof(char));
    while (fgets(nome, TAM_STR, fich_disc) && fgets(docente, TAM_STR, fich_disc)) {
        for(ptr = nome; in; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                in = 0;
            }
        }
        in = 1;
        for(ptr = docente; in; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                in = 0;
            }
        }
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
    char *ptr;
    char *nome = malloc(TAM_STR * sizeof(char));
    char *curso = malloc(TAM_STR * sizeof(char));
    char *linha = malloc(TAM_STR * sizeof(char));
    int numero, ano;
    char regime;
    while (fgets(nome, TAM_STR, fich_aln), fgets(curso, TAM_STR, fich_aln)) {
        for(ptr = nome; ptr; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                ptr = NULL;
            }
        }
        for(ptr = curso; ptr; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                ptr = NULL;
            }
        }
        Aluno aln;
        aln.nome = malloc(TAM_STR * sizeof(char));
        aln.curso = malloc(TAM_STR * sizeof(char));
        strcpy(aln.nome, nome);
        strcpy(aln.curso, curso);
        fgets(linha, TAM_STR, fich_aln);
        for(ptr = linha; ptr; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                ptr = NULL;
            }
        }
        numero = atoi(linha);
        aln.num = numero;
        fgets(linha, TAM_STR, fich_aln);
        for(ptr = linha; ptr; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                ptr = NULL;
            }
        }
        ano = atoi(linha);
        aln.ano = ano;
        regime = (char) fgetc(fich_aln);
        aln.regime = regime;
        aln.exames = NULL;
        *alunos = insereAluno(*alunos, aln);
    }
}

void leFicheiroExames(Lista_Exames *exames, FILE *fich_exm, Lista_Disciplinas disciplinas, Lista_Alunos alunos){
    char *ptr;
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
        for(ptr = linha; ptr; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                ptr = NULL;
            }
        }
        num = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        for(ptr = linha; ptr; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                ptr = NULL;
            }
        }
        duracao = atoi(linha);
        epoca = (char) fgetc(fich_exm);
        fgets(linha, TAM_STR, fich_exm);
        for(ptr = linha; ptr; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                ptr = NULL;
            }
        }
        data.dia = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        for(ptr = linha; ptr; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                ptr = NULL;
            }
        }
        data.mes = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        for(ptr = linha; ptr; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                ptr = NULL;
            }
        }
        data.ano = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        for(ptr = linha; ptr; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                ptr = NULL;
            }
        }
        hora.horas = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        for(ptr = linha; ptr; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                ptr = NULL;
            }
        }
        hora.minutos = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        for(ptr = linha; ptr; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                ptr = NULL;
            }
        }
        disciplina = pesquisaDisciplinas(disciplinas, linha);
        fgets(linha, TAM_STR, fich_exm);
        for(ptr = linha; ptr; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                ptr = NULL;
            }
        }
        while (!atoi(linha)) {
            strcpy(linha, salas->nome);
            salas = salas->next;
            fgets(linha, TAM_STR, fich_exm);
            for(ptr = linha; ptr; ptr++){
                if(*ptr == '\n'){
                    *ptr = '\0';
                    ptr = NULL;
                }
            }
        }
        while (atoi(linha)) {
            alns->aluno = pesquisaNumAluno(alunos, atoi(linha));
            alns = alns->next;
            fgets(linha, TAM_STR, fich_exm);
            for(ptr = linha; ptr; ptr++){
                if(*ptr == '\n'){
                    *ptr = '\0';
                    ptr = NULL;
                }
            }
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

void guardaFicheiroDisciplinas(Lista_Disciplinas disciplinas, FILE *fich_disc){
    
}