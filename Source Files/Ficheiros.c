//
// Created by guilh on 23/05/2017.
//
#include "Ficheiros.h"

void leFicheiroDisciplinas(Lista_Disciplinas *disciplinas, FILE *fich_disc){
    char *ptr = NULL;
    int in;
    char *nome;
    char *docente = (char *) malloc(TAM_STR * sizeof(char));
    nome = malloc(TAM_STR * sizeof(char));
    while (fgets(nome, TAM_STR, fich_disc) && fgets(docente, TAM_STR, fich_disc)) {
        in = 1;
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
    }
}

void leFicheiroAlunos(Lista_Alunos *alunos, FILE *fich_aln){
    char *str1 = malloc(TAM_STR * sizeof(char));
    char *str2 = malloc(TAM_STR * sizeof(char));
    int numero, ano;
    char regime;
    while (fscanf(fich_aln, "%[^\n]\n%[^\n]\n%d\n%d\n%c\n", str1, str2, &numero, &ano, &regime) == 5) {
        Aluno aln;
        aln.nome = malloc(TAM_STR * sizeof(char));
        aln.curso = malloc(TAM_STR * sizeof(char));
        strcpy(aln.nome, str1);
        printf("%s\n", aln.nome);
        strcpy(aln.curso, str2);
        printf("%s\n", aln.curso);
        aln.num = numero;
        printf("%d\n", numero);
        aln.ano = ano;
        printf("%d\n", ano);
        aln.regime = regime;
        printf("%c\n", regime);
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
    int in;
    int num;
    int duracao;
    Lista_Salas salas = malloc(sizeof(Lista_Salas));
    Lista_Ptr_Alunos alns = malloc(sizeof(Lista_Ptr_Alunos));
    char *linha = malloc(TAM_STR * sizeof(char));
    while (fgets(linha, TAM_STR, fich_exm)) {
        in = 1;
        for(ptr = linha; in; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                in = 0;
            }
        }
        num = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        in = 1;
        for(ptr = linha; in; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                in = 0;
            }
        }
        duracao = atoi(linha);
        epoca = (char) fgetc(fich_exm);
        fgets(linha, TAM_STR, fich_exm);
        in = 1;
        for(ptr = linha; in; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                in = 0;
            }
        }
        data.dia = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        in = 1;
        for(ptr = linha; in; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                in = 0;
            }
        }
        data.mes = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        in = 1;
        for(ptr = linha; in; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                in = 0;
            }
        }
        data.ano = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        in = 1;
        for(ptr = linha; in; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                in = 0;
            }
        }
        hora.horas = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        in = 1;
        for(ptr = linha; in; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                in = 0;
            }
        }
        hora.minutos = atoi(linha);
        fgets(linha, TAM_STR, fich_exm);
        in = 1;
        for(ptr = linha; in; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                in = 0;
            }
        }
        disciplina = pesquisaDisciplinas(disciplinas, linha);
        fgets(linha, TAM_STR, fich_exm);
        in = 1;
        for(ptr = linha; in; ptr++){
            if(*ptr == '\n'){
                *ptr = '\0';
                in = 0;
            }
        }
        while (!atoi(linha)) {
            strcpy(linha, salas->nome);
            salas = salas->next;
            fgets(linha, TAM_STR, fich_exm);
            in = 1;
            for(ptr = linha; in; ptr++){
                if(*ptr == '\n'){
                    *ptr = '\0';
                    in = 0;
                }
            }
        }
        while (atoi(linha)) {
            alns->aluno = pesquisaNumAluno(alunos, atoi(linha));
            alns = alns->next;
            fgets(linha, TAM_STR, fich_exm);
            in = 1;
            for(ptr = linha; in; ptr++){
                if(*ptr == '\n'){
                    *ptr = '\0';
                    in = 0;
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
        *exames = insereExame(*exames, exm);
        for (exm.alunos; exm.alunos != NULL ; exm.alunos = exm.alunos->next) {
            exm.alunos->aluno->aluno.exames = inserePtrExame(exm.alunos->aluno->aluno.exames,*exames);
        }
        fgets(linha, TAM_STR, fich_exm);
    }
}

void guardaFicheiroDisciplinas(Lista_Disciplinas disciplinas, FILE *fich_disc){
    for (disciplinas;disciplinas != NULL; disciplinas = disciplinas->next) {
        fprintf(fich_disc,"%s\n",disciplinas->disciplina.nome);
        fprintf(fich_disc,"%s\n",disciplinas->disciplina.docente);
    }
}

void guardaFicheiroAlunos(Lista_Alunos alunos, FILE *fich_aln){
    for (alunos; alunos != NULL ; alunos = alunos->next) {
        fprintf(fich_aln,"%s\n",alunos->aluno.nome);
        fprintf(fich_aln,"%s\n",alunos->aluno.curso);
        fprintf(fich_aln,"%d\n",alunos->aluno.num);
        fprintf(fich_aln,"%d\n",alunos->aluno.ano);
        fprintf(fich_aln,"%c\n",alunos->aluno.regime);
    }
}

void guardaFicheiroExames(Lista_Exames exames, FILE *fich_exms){
    for (exames; exames != NULL ; exames = exames->next) {
        fprintf(fich_exms,"%d\n",exames->exame.num);
        fprintf(fich_exms,"%d\n",exames->exame.duracao);
        fprintf(fich_exms,"%c\n",exames->exame.epoca);
        fprintf(fich_exms,"%d\n",exames->exame.data.dia);
        fprintf(fich_exms,"%d\n",exames->exame.data.mes);
        fprintf(fich_exms,"%d\n",exames->exame.data.ano);
        fprintf(fich_exms,"%d\n",exames->exame.hora.horas);
        fprintf(fich_exms,"%d\n",exames->exame.hora.minutos);
        fprintf(fich_exms,"%s\n",exames->exame.disciplina->disciplina.nome);
        do {
            fprintf(fich_exms,"%s\n",exames->exame.salas->nome);
            exames->exame.salas = exames->exame.salas->next;
        } while (exames->exame.salas != NULL);
        do {
            fprintf(fich_exms,"%d\n",exames->exame.alunos->aluno->aluno.num);
            exames->exame.alunos = exames->exame.alunos->next;
        } while (exames->exame.alunos != NULL);
    }
}