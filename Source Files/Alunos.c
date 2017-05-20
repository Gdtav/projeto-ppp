//
// Created by guilh on 13/05/2017.
//

#include "Alunos.h"

Lista_Alunos pesquisaNumAluno(Lista_Alunos lst, int num) {
    Lista_Alunos ptr = lst;
    Lista_Alunos find;
    for (find = 0; ptr != NULL && find == 0; ptr = ptr->next)
        find = (ptr->aluno.num == num) ? ptr : NULL;
    return find;
}

Lista_Ptr_Alunos pesquisaNumPtrAluno(Lista_Ptr_Alunos lst, int num) {
    Lista_Ptr_Alunos ptr = lst;
    Lista_Ptr_Alunos find;
    for (find = 0; ptr != NULL && find == 0; ptr = ptr->next)
        find = (ptr->aluno->aluno.num == num) ? ptr : NULL;
    return find;
}

void procuraAluno(Lista_Alunos lst, Aluno chave, Lista_Alunos *ant, Lista_Alunos *act) {
    *ant = NULL;
    *act = lst;
    while ((*act) != NULL && strcmpi((*act)->aluno.nome, chave.nome) < 0) {
        *ant = *act;
        *act = (*act)->next;
    }
    if ((*act) != NULL && strcmpi((*act)->aluno.nome, chave.nome) != 0)
        *act = NULL; /* Se elemento não encontrado*/
}

void procuraPtrAluno(Lista_Ptr_Alunos lst, Aluno chave, Lista_Ptr_Alunos *ant, Lista_Ptr_Alunos *act) {
    *ant = NULL;
    *act = lst;
    while ((*act) != NULL && strcmpi((*act)->aluno->aluno.nome, chave.nome) < 0) {
        *ant = *act;
        *act = (*act)->next;
    }
    if ((*act) != NULL && strcmpi((*act)->aluno->aluno.nome, chave.nome) != 0)
        *act = NULL; /* Se elemento não encontrado*/
}

Lista_Alunos insereAluno(Lista_Alunos lst, Aluno aluno) {
    if (pesquisaNumAluno(lst, aluno.num)) {
        printf("Já existe um aluno com esse número na base de dados! Abortando...\n");
        return lst;
    }
    Lista_Alunos no;
    Lista_Alunos ant, act;
    no = (Lista_Alunos) malloc(sizeof(No_Aluno));
    if (no != NULL) {
        no->aluno = aluno;
        procuraAluno(lst, aluno, &ant, &act);
        if (ant != NULL) {
            no->next = ant->next;
            no->prev = ant;
            if (ant->next != NULL)
                ant->next->prev = no;
            ant->next = no;
        } else {
            no->next = lst;
            no->prev = NULL;
            lst = no;
        }
    } else
        printf("Erro de memoria. Nao foi possivel adicionar aluno\n.");
    return lst;
}

Lista_Ptr_Alunos inserePtrAluno(Lista_Ptr_Alunos lst, Lista_Alunos aluno) {
    if (pesquisaNumPtrAluno(lst, aluno->aluno.num)) {
        printf("Já existe um aluno com esse número na base de dados! Abortando...\n");
        return lst;
    }
    Lista_Ptr_Alunos no;
    Lista_Ptr_Alunos ant, act;
    no = (Lista_Ptr_Alunos) malloc(sizeof(No_Ptr_Aluno));
    if (no != NULL) {
        no->aluno = aluno;
        procuraPtrAluno(lst, aluno->aluno, &ant, &act);
        if (ant != NULL) {
            no->next = ant->next;
            no->prev = ant;
            if (ant->next != NULL)
                ant->next->prev = no;
            ant->next = no;
        } else {
            no->next = lst;
            no->prev = NULL;
            lst = no;
        }
    } else
        printf("Erro de memoria. Nao foi possivel criar relacao.\n");
    return lst;
}

Lista_Ptr_Alunos destroiListaPtrAlunos(Lista_Ptr_Alunos lst) {
    Lista_Ptr_Alunos temp_ptr;
    while (lst) {
        temp_ptr = lst;
        lst = lst->next;
        free(temp_ptr);
    }
    return NULL;
}

Lista_Alunos destroiListaAlunos(Lista_Alunos lst) {
    Lista_Alunos temp_ptr;
    while (lst) {
        temp_ptr = lst;
        lst = lst->next;
        temp_ptr->aluno.exames = destroiListaPtrExames(temp_ptr->aluno.exames);
        free(temp_ptr->aluno.curso);
        free(temp_ptr->aluno.nome);
        free(temp_ptr);
    }
    return NULL;
}

Lista_Alunos criaAluno(Lista_Alunos lst) {
    Aluno novo;
    char *nome = malloc(TAM_STR * sizeof(char));
    char *curso = malloc(TAM_STR * sizeof(char));
    char *regime = malloc(2 * sizeof(char));
    int num, ano;
    printf("Nome do aluno: ");
    fflush(stdin);
    gets(nome);
    novo.nome = nome;
    fflush(stdin);
    printf("Numero do aluno: ");
    while (scanf("%d", &num) == 0){     //
        printf("Insira um NUMERO: ");   //  ESTA PROTECAO NAO FUNCIONA
    }                                   //
    novo.num = num;
    printf("Numero de matriculas: ");
    while (scanf("%d", &ano) == 0)
        printf("Insira um NUMERO: ");
    novo.ano = ano;
    fflush(stdin);
    printf("Curso do aluno: ");
    gets(curso);
    novo.curso = curso;
    fflush(stdin);
    printf("Regime do aluno\n(n -> normal,\nt -> trabalhador-estudante,\na -> atleta,\nd -> dirigente associativo,\ne -> aluno de Erasmus): ");
    while(gets(regime) == NULL || regime != "n" || regime != "t" || regime != "a" || regime != "d" || regime != "e")
        printf("Insira 'n', 't', 'a', 'd' ou 'e': ");
    novo.regime = *regime;
    novo.exames = NULL;
    lst = insereAluno(lst, novo);
    return lst;
}

void modificaAluno(Lista_Alunos lst) {
    int num, escolha = 0;
    char *reg = (char *) malloc(2 * sizeof(char));
    Lista_Alunos aluno;
    printf("Numero do aluno a modificar: ");
    while (scanf("%d", &num) == 0)
        printf("Insira um NUMERO: ");
    aluno = pesquisaNumAluno(lst, num);
    if (aluno == NULL) {
        printf("Nao existe aluno na base de dados com esse numero! Abortando...\n");
        return;
    }
    while (escolha != 5) {
        printf("\nModificar:\n1 - Nome\n2 - Matriculas\n3 - Curso\n4 - Regime\n\n5 - Voltar\n\nEscolha a opcao: ");
        while (scanf("%d", &escolha) == 0)
            printf("Insira um NUMERO: ");
        fflush(stdin);
        switch (escolha) {
            case 1:
                printf("Introduza o novo nome: ");
                gets(aluno->aluno.nome);
                fflush(stdin);
                break;
            case 2:
                printf("Introduza o numero de matriculas: ");
                while (scanf("%d", &(aluno->aluno.ano)) == 0)
                    printf("Insira um NUMERO: ");
                break;
            case 3:
                printf("Introduza o nome do curso: ");
                while(gets(aluno->aluno.curso) == 0)
                    printf("Introduza um NOME: ");
                fflush(stdin);
                break;
            case 4:
                reg = &(aluno->aluno.regime);
                printf("Introduza o regime do aluno\n(n -> normal,\nt -> trabalhador-estudante,\na -> atleta,\nd -> dirigente associativo,\ne -> aluno de Erasmus): ");
                while(gets(reg) == NULL || *(reg + 1) != 0 || (*reg != 'n' || *reg !='t' || *reg != 'a' || *reg != 'd' || *reg != 'e'))
                    printf("Insira 'n', 't', 'a', 'd' ou 'e': ");
                break;
            case 5:
                break;
            default:
                printf("Opcao invalida! Escolha outra opcao...\n");
                break;
        }
    }
}

Lista_Ptr_Alunos eliminaPtrAluno(Lista_Ptr_Alunos lst, int num) {
    Lista_Ptr_Alunos ant;
    Lista_Ptr_Alunos aluno = pesquisaNumPtrAluno(lst, num);
    if (aluno != NULL) {
        ant = aluno->prev;
        if (aluno->next != NULL)
            aluno->next->prev = ant;
        if (ant != NULL)
            ant->next = aluno->next;
        else
            lst = aluno->next;
        free(aluno);
    }
    return lst;
}

Lista_Alunos eliminaAluno(Lista_Alunos lst) {
    int num;
    Lista_Alunos aluno;
    Lista_Ptr_Exames ptr;
    printf("Numero do aluno a eliminar: ");
    while (scanf("%d", &num) == 0)
        printf("Insira um NUMERO: ");
    aluno = pesquisaNumAluno(lst, num);
    if (aluno == NULL) {
        printf("Nao existe aluno na base de dados com esse numero! Abortando...\n");
        return lst;
    }
    if (aluno->next != NULL)
        aluno->next->prev = aluno->prev;
    if (aluno->prev != NULL)
        aluno->prev->next = aluno->next;
    else
        lst = aluno->next;
    for (ptr = aluno->aluno.exames; ptr; ptr = ptr->next) {
        ptr->exame->exame.alunos = eliminaPtrAluno(ptr->exame->exame.alunos, aluno->aluno.num);
    }
    free(aluno->aluno.curso);
    free(aluno->aluno.nome);
    free(aluno);
    return lst;
}

void imprimeAluno(Aluno aluno) {
    printf("Numero: %d\n", aluno.num);
    printf("Nome: %s\n", aluno.nome);
    printf("Curso: %s\n", aluno.curso);
    printf("Matriculas: %d\n", aluno.ano);
    printf("Regime: ");
    switch (aluno.regime) {
        case 'n':
            printf("Normal\n");
            break;
        case 't':
            printf("Trabalhador-estudante\n");
            break;
        case 'a':
            printf("Atleta\n");
            break;
        case 'd':
            printf("Dirigente associativo\n");
            break;
        case 'e':
            printf("Aluno de Erasmus\n");
            break;
        default:
            printf("Regime introduzido invalido! Modifique este aluno!\n");
            break;
    }
}

void imprimeAlunos(Lista_Alunos alunos) {
    Lista_Alunos ptr = alunos;
    for (ptr; ptr != NULL; ptr = ptr->next) {
        imprimeAluno(ptr->aluno);
    }
}