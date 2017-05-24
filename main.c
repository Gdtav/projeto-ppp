#include <stdio.h>
#include "Source Files/Menus.h"
#include "Source Files/Estruturas.h"
#include "Source Files/Ficheiros.h"

int main() {
    FILE *f_exames;
    FILE *f_alunos;
    FILE *f_disciplinas;
    Lista_Exames exames = NULL;
    Lista_Alunos alunos = NULL;
    Lista_Disciplinas disciplinas = NULL;
    f_exames = fopen("Ficheiros/Exames.txt","r");
    f_alunos = fopen("Ficheiros/Alunos.txt","r");
    f_disciplinas = fopen("Ficheiros/Disciplinas.txt","r");
    if (f_exames == NULL || f_alunos == NULL || f_disciplinas == NULL) {
        printf("Erro. Nao foi possível aceder aos dados. Pressione enter para sair");
        if (getc(stdin))
            return -1;
    }
    exames = NULL;
    alunos = NULL;
    disciplinas = leFicheiroDisciplinas(disciplinas,f_disciplinas);
    disciplinas = NULL;
    menuPrincipal(&alunos, &exames, &disciplinas);
    return 0;
}