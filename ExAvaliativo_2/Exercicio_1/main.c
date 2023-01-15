#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int idaluno, idcurso;
    int idade;
    int nota;
} aluno; // info alunos

typedef struct
{
    aluno alunos[3];
} curso; // quantidade de cadastros em cada curso

curso cursos[4];
int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0;
int auxAluno = 0;

void cursos_Disponiveis()
{
    printf("\nID dos cursos:\n1 - Agronomia.\n2 - Medicina.\n3 - Odontologia.\n4 "
           "- Sistemas de informacao.\nDigite o ID do Curso em que o Aluno sera "
           "cadastrado: ");
}

void Cadastrar_Aluno()
{
    aluno novoAluno, auxA;
    int idCurso;
    int aux;
    int indexA;

    cursos_Disponiveis();
    scanf("%d", &idCurso);

    while (idCurso < 1 || idCurso > 4)
    {
        printf("\nInsira uma opcao valida!!\n");

        cursos_Disponiveis();
        scanf("%d", &idCurso);
    }

    novoAluno.idcurso = idCurso;
    printf("\nDigite o ID do aluno: ");
    scanf("%d", &novoAluno.idaluno);
    printf("\nDigite a idade do aluno: ");
    scanf("%d", &novoAluno.idade);
    printf("\nDigite a nota do aluno: ");
    scanf("%d", &novoAluno.nota);

    if (idCurso == 1)   // Agronomia.
    {
        bool verifica = false;
        for (int i = 0; i < cont1; i++)
        {
            if (cursos[0].alunos[i].idaluno == novoAluno.idaluno)
            {
                verifica = true;
            }
        }

        if (verifica)
        {
            printf("\nID já em uso, tente novamente!!\n");
        }
        else
        {
            auxA = novoAluno;
            verifica = false;
            if (cont1 >= 3)
            {
                for (int i = 0; i < cont1; i++)
                {
                    if (cursos[0].alunos[i].nota <= auxA.nota)
                    {
                        auxA = cursos[0].alunos[i];
                        indexA = i;
                    }
                }
                if (auxA.idaluno != novoAluno.idaluno)
                {
                    if (auxA.nota == novoAluno.nota)
                    {
                        if (novoAluno.idade > auxA.nota)
                        {
                            cursos[0].alunos[indexA] = novoAluno;
                            printf("\nAluno Cadastrado com sucesso!!\n");
                            verifica = true;
                        }
                    }
                    else
                    {
                        cursos[0].alunos[indexA] = novoAluno;
                        printf("\nAluno Cadastrado com sucesso!!\n");
                        verifica = true;
                    }
                }
                if (!verifica)
                {
                    printf("\nO aluno nao tirou nota suficiente pra entrar no curso!");
                }
            }
            else
            {
                cursos[0].alunos[cont1] = novoAluno;
                printf("\nAluno Cadastrado com sucesso!!\n");
                cont1++;
            }
        }

    }

    else if (idCurso == 2)   // Medicina.
    {
        bool verifica = false;
        for (int i = 0; i < cont2; i++)
        {
            if (cursos[1].alunos[i].idaluno == novoAluno.idaluno)
            {
                verifica = true;
            }
        }
        if (verifica)
        {
            printf("\nID já em uso, tente novamente!!\n");
        }
        else
        {
            auxA = novoAluno;
            verifica = false;
            if (cont3 >= 3)
            {
                for (int i = 0; i < cont2; i++)
                {
                    if (cursos[1].alunos[i].nota <= auxA.nota)
                    {
                        auxA = cursos[1].alunos[i];
                        indexA = i;
                    }
                }
                if (auxA.idaluno != novoAluno.idaluno)
                {
                    if (auxA.nota == novoAluno.nota)
                    {
                        if (novoAluno.idade > auxA.nota)
                        {
                            cursos[1].alunos[indexA] = novoAluno;
                            printf("\nAluno Cadastrado com sucesso!!\n");
                            verifica = true;
                        }
                    }
                    else
                    {
                        cursos[1].alunos[indexA] = novoAluno;
                        printf("\nAluno Cadastrado com sucesso!!\n");
                        verifica = true;
                    }
                }
                if (!verifica)
                {
                    printf("\nO aluno nao tirou nota suficiente pra entrar no curso!");
                }
            }
            else
            {
                cursos[1].alunos[cont2] = novoAluno;
                printf("\nAluno Cadastrado com sucesso!!\n");
                cont2++;
            }
        }

    }
    else if (idCurso == 3)     // Odontologia.
    {
        bool verifica = false;
        for (int i = 0; i < cont3; i++)
        {
            if (cursos[2].alunos[i].idaluno == novoAluno.idaluno)
            {
                verifica = true;
            }
        }
        if (verifica)
        {
            printf("\nID já em uso, tente novamente!!\n");
        }
        else
        {
            auxA = novoAluno;
            verifica = false;
            if (cont3 >= 3)
            {
                for (int i = 0; i < cont3; i++)
                {
                    if (cursos[2].alunos[i].nota <= auxA.nota)
                    {
                        auxA = cursos[2].alunos[i];
                        indexA = i;
                    }
                }
                if (auxA.idaluno != novoAluno.idaluno)
                {
                    if (auxA.nota == novoAluno.nota)
                    {
                        if (novoAluno.idade > auxA.nota)
                        {
                            cursos[2].alunos[indexA] = novoAluno;
                            printf("\nAluno Cadastrado com sucesso!!\n");
                            verifica = true;
                        }
                    }
                    else
                    {
                        cursos[2].alunos[indexA] = novoAluno;
                        printf("\nAluno Cadastrado com sucesso!!\n");
                        verifica = true;
                    }
                }
                if (!verifica)
                {
                    printf("\nO aluno nao tirou nota suficiente pra entrar no curso!");
                }
            }
            else
            {
                cursos[2].alunos[cont3] = novoAluno;
                printf("\nAluno Cadastrado com sucesso!!\n");
                cont3++;
            }
        }

    }
    else if (idCurso == 4)     // Sistemas de informacao.
    {
        bool verifica = false;
        for (int i = 0; i < cont4; i++)
        {
            if (cursos[3].alunos[i].idaluno == novoAluno.idaluno)
            {
                verifica = true;
            }
        }
        if (verifica)
        {
            printf("\nID já em uso, tente novamente!!\n");
        }
        else
        {
            auxA = novoAluno;
            verifica = false;
            if (cont4 >= 3)
            {
                for (int i = 0; i < cont1; i++)
                {
                    if (cursos[3].alunos[i].nota <= auxA.nota)
                    {
                        auxA = cursos[3].alunos[i];
                        indexA = i;
                    }
                }
                if (auxA.idaluno != novoAluno.idaluno)
                {
                    if (auxA.nota == novoAluno.nota)
                    {
                        if (novoAluno.idade > auxA.nota)
                        {
                            cursos[3].alunos[indexA] = novoAluno;
                            printf("\nAluno Cadastrado com sucesso!!\n");
                            verifica = true;
                        }
                    }
                    else
                    {
                        cursos[3].alunos[indexA] = novoAluno;
                        printf("\nAluno Cadastrado com sucesso!!\n");
                        verifica = true;
                    }
                }
                if (!verifica)
                {
                    printf("\nO aluno nao tirou nota suficiente pra entrar no curso!");
                }
            }
            else
            {
                cursos[3].alunos[cont4] = novoAluno;
                printf("\nAluno Cadastrado com sucesso!!\n");
                cont4++;
            }
        }
    }
}

void Print_Matriculas()
{
    printf("\n1 - Agronomia:\n");
    for (int i = 0; i < cont1; i++)
    {
        printf("\nID Aluno: %d\n", cursos[0].alunos[i].idaluno);
        printf("\nIdade do Aluno: %d\n", cursos[0].alunos[i].idade);
        printf("\nNota do Aluno: %d\n", cursos[0].alunos[i].nota);
    }
    printf("\n2 - Medicina:\n");
    for (int i = 0; i < cont2; i++)
    {
        printf("\nID Aluno: %d\n", cursos[1].alunos[i].idaluno);
        printf("\nIdade do Aluno: %d\n", cursos[1].alunos[i].idade);
        printf("\nNota do Aluno: %d\n", cursos[1].alunos[i].nota);
    }
    printf("\n3 - Odontologia:\n");
    for (int i = 0; i < cont3; i++)
    {
        printf("\nID Aluno: %d\n", cursos[2].alunos[i].idaluno);
        printf("\nIdade do Aluno: %d\n", cursos[2].alunos[i].idade);
        printf("\nNota do Aluno: %d\n", cursos[2].alunos[i].nota);
    }
    printf("\n4 - Sistemas de informacao:\n");
    for (int i = 0; i < cont4; i++)
    {
        printf("\nID Aluno: %d\n", cursos[3].alunos[i].idaluno);
        printf("\nIdade do Aluno: %d\n", cursos[3].alunos[i].idade);
        printf("\nNota do Aluno: %d\n", cursos[3].alunos[i].nota);
    }
}

int main()
{

    int option;
    do
    {
        printf(
            "\n1 - Cadastrar e Matricular aluno.\n2 - Alunos Cadastrados e "
            "Matriculados/Aprovados.\n0 - Encerrar programa.\nInsira uma opcao: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            Cadastrar_Aluno();
            break;
        case 2:
            Print_Matriculas();
            break;
        default:
            if (option != 0 && option != 1 && option != 2 && option != 3)
            {
                printf("\nInsira uma opcao valida!\n");
            }
            break;
        }
    }
    while (option != 0);

    return 0;
}
