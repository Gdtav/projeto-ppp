#include <stdio.h>
#include "Source Files/Menus.h"
#include "Source Files/Estruturas.h"

int main() {
    FILE *f_exames;
    FILE *f_alunos;
    FILE *f_disciplinas;
    f_exames = fopen("Ficheiros/Exames.txt","a");
    f_alunos = fopen("Ficheiros/Alunos.txt","a");
    f_disciplinas = fopen("Ficheiros/Disciplinas.txt","a");
    menuPrincipal();
    return 0;
}