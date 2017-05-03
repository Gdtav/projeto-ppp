//
// Created by Utilizador on 29/04/2017.
//

#ifndef PROJETO_EXAMES_H
#define PROJETO_EXAMES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int horas;
    int minutos;
} Hora;

typedef struct {
    char *nome;
    char *docente;
} Disciplina;

typedef struct l_d *Lista_Disciplinas;

typedef struct l_d{
    Disciplina disciplina;
    Lista_Disciplinas prev;
    Lista_Disciplinas next;
} Item_disciplinas;

typedef struct no_aluno *Lista_Alunos; // definir o no de uma suposta lista de alunos

typedef struct aluno *Ptr_Aluno; // definir ponteiro para um tipo de dados a definir com "aluno"

typedef struct no_ptr_exame *Lista_Ptr_Alunos;

typedef struct no_exame *Lista_Exames; // definir o no de uma suposta lista de alunos

typedef struct exame *Ptr_Exame; // definir ponteiro para um tipo de dados a definir com "exame"

typedef struct no_ptr_exame *Lista_Ptr_Exames;

typedef struct no_ptr_aluno{
    Ptr_Aluno aluno;
    Lista_Ptr_Alunos prev;
    Lista_Ptr_Alunos next;
} Item_Ptr_Aluno;

typedef struct no_ptr_exame{
    Ptr_Exame exame;
    Lista_Ptr_Exames prev;
    Lista_Ptr_Exames next;
} Item_Ptr_Exame;

typedef struct aluno{
    int num, ano;
    char *curso;
    char regime;// n -> normal, t -> trabalhador-estudante, a -> atleta, d -> dirigente associativo, e -> aluno de Erasmus)
    Lista_Ptr_Exames exames;
} Aluno;

typedef struct exame{
    Disciplina *disciplina;
    char epoca;// n -> Normal, r-> Recurso, e-> Especial
    Data data;
    Hora hora;
    int duracao;// em minutos
    char *sala;
    Lista_Ptr_Alunos alunos; //adicionar funcao para contar nos da lista
} Exame;

typedef struct no_aluno{
    Aluno aluno;
    Lista_Alunos prev;
    Lista_Alunos next;
} Item_Aluno;

typedef struct no_exame{
    Exame exame;
    Lista_Exames prev;
    Lista_Exames next;
} Item_Exame;


#endif //PROJETO_EXAMES_H