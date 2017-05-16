#include "Exames.h"

void imprimeExame(Exame exame){
    printf("Disciplina: %s\n", exame.disciplina->nome);
    printf("Epoca: ");
    switch(exame.epoca){
        case 'n': printf("Normal\n");
            break;
        case 'r': printf("Recurso\n");
            break;
        case 'e': printf("Especial\n");
            break;
        default: printf("Epoca introduzida invalida! Modifique este exame!\n");
            break;
    }
    printf("Data: ");
    imprimeData(exame.data);
    printf("\nHora: ");
    imprimeHora(exame.hora);
    printf("\nDuracao: %d\n", exame.duracao);
}

void imprimeExamesAluno(Lista_Alunos lst){
    Lista_Ptr_Exames ptr;
    int num;
    Lista_Alunos no;
    printf("Numero do aluno: ");
    scanf("%d", &num);
    no = pesquisaNum(lst, num);
    if (no == NULL){
        printf("Nao existe aluno na base de dados com esse numero! Abortando...\n");
        return;
    }
    for (ptr = no->aluno.exames; ptr != NULL; ptr = ptr->next)
        imprimeExame(*(ptr->exame));
}

Lista_Exames criaExame(Lista_Exames exames){
    char *disciplina = malloc(TAM_STR * sizeof(char));
    char epoca;
    Data data;
    Hora hora;
    int duracao;
    printf("Disciplina do exame: ");
    fflush(stdin);
    gets(disciplina);
    fflush(stdin);
    printf("Epoca(n -> Normal, \nr-> Recurso, \ne-> Especial): ");
    scanf("%c", &epoca);
    printf("Data do exame: ");
    data = leData();
    printf("Hora do exame: ");
    hora = leHora();
    printf("Duracao do exame(minutos): ");
    scanf("%d", &duracao);
}

Lista_Exames eliminaExamesAntigos(Lista_Exames exames){
    Lista_Exames ptr;
    Data data;
    printf("Por favor insira a data até onde quer eliminar (inclusive):\n");
    data = leData();
    int lista_vazia;
    for (ptr = exames; ptr != NULL; ptr = ptr->next) {
        if (cmpData(data,ptr->exame.data) >= 0){
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            lista_vazia = 0;
            Lista_Ptr_Alunos temp;
            while (lista_vazia == 0){
                if (ptr->exame.alunos == NULL)
                    lista_vazia = 1;
                temp = ptr->exame.alunos;
                ptr->exame.alunos = ptr->exame.alunos->next;
                free(temp);
            }
            lista_vazia = 0;
            Lista_Ptr_Salas temp2;
            while (lista_vazia == 0){
                if (ptr->exame.salas == NULL)
                    lista_vazia = 1;
                temp2 = ptr->exame.salas;
                ptr->exame.salas = ptr->exame.salas->next;
                free(temp2);
            }
        }
    }
    return exames;
}

void imprimeExames(Lista_Exames exame){
    Lista_Exames ptr = exame;
    for (ptr;  ptr != NULL ; ptr = ptr->next) {
        imprimeExame(ptr->exame);
    }
}

void imprimeAlunosInscritos(Lista_Exames exames) {
    Lista_Ptr_Alunos ptr;
    for (ptr = exames->exame.alunos; ptr != NULL; ptr = ptr->next) {
        printf(ptr->aluno->nome);
    }
}

Lista_Ptr_Alunos inscreveAluno(Lista_Ptr_Alunos alunos){

}