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

Lista_Exames criaExame(Lista_Exames exames, Lista_Disciplinas disciplinas){
    Exame novo;
    Lista_Disciplinas disc = NULL;
    char epoca, dummy;
    Data data;
    Hora hora;
    int duracao;
    Lista_Salas salas = NULL, ptr = NULL;
    ptr = salas;
    char *str = malloc(TAM_STR * sizeof(char));
    while (disc == NULL) {
        printf("Disciplina do exame: ");
        fflush(stdin);
        gets(str);
        disc = pesquisaDisciplinas(disciplinas, str);
        if (disc)
            novo.disciplina = disc;
        else
            printf("Disciplina nao existe na base de dados!\n");
    }
    fflush(stdin);
    printf("Epoca(n -> Normal, \nr-> Recurso, \ne-> Especial): ");
    scanf("%c", &epoca);
    while (epoca != 'n' && epoca != 'r' && epoca != 'e'){
        printf("Epoca invalida!\n");
        fflush(stdin);
        printf("Epoca(n -> Normal, \nr-> Recurso, \ne-> Especial): ");
        scanf("%c", &epoca);
    }
    printf("Data do exame: ");
    data = leData();
    printf("Hora do exame: ");
    hora = leHora();
    printf("Duracao do exame(minutos): ");
    scanf("%d", &duracao);
    printf("Salas ('/' para terminar): \n");
    gets(str);
    scanf("%c", &dummy);
    while (*str != '/'){
        Lista_Salas no = (Lista_Salas) malloc(sizeof(No_Sala));
        no->nome = malloc(TAM_STR * sizeof(char));
        strcpy(no->nome, str);
        no->next = NULL;
        no->prev = ptr;
        ptr = no;
        if (salas == NULL)
            salas = ptr;
        gets(str);
    }
}