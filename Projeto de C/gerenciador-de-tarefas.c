#include <stdio.h>
#include <string.h>

//Definindo já no começo os vetores e o número que cada um deve conter
#define Max_Tasks 200 //Quantidade Máxima de Tarefas
#define Tit_Size 70 //Tamanho do Título
#define Desc_Size 500 //Tamanho da Descrição

//Enumeração das constantes para representar o status da tarefa
typedef enum {
    PENDENTE,
    CONCLUIDA
} TaskStatus;

//Estrutura para representar uma tarefa
typedef struct {
    char title[Tit_Size]; //Título da tarefa
    char description[Desc_Size]; //Descrição da tarefa
    char dateCreation[50]; //Data de criação da tarefa
    char completionDeadline[50]; //Prazo para conclusão da tarefa
    TaskStatus status; //Status atual da tarefa
} Task;

Task tasks[Max_Tasks]; //Vetor para armazenar as tarefas
int numTasks = 0; //Variável para controlar o número atual de tarefas

//Adicionar uma nova tarefa
void addTask() {
    if (numTasks < Max_Tasks) {

        Task novaTarefa; //Declara uma nova variável do tipo 'Task' para armazenar os dados da nova tarefa.

        printf("Titulo da tarefa: ");
        scanf(" %[^\n]s", novaTarefa.title);

        printf("Descricao da tarefa: ");
        scanf(" %[^\n]s", novaTarefa.description);

        printf("Data de criacao (DD/MM/AAAA): ");
        scanf(" %s", novaTarefa.dateCreation);

        printf("Prazo de conclusao (DD/MM/AAAA): ");
        scanf(" %s", novaTarefa.completionDeadline);

        novaTarefa.status = PENDENTE; //Define o status da nova tarefa como "PENDENTE".
        tasks[numTasks++] = novaTarefa; //Adiciona a nova tarefa ao vetor 'tasks' na posição indicada por 'numTasks'.

        printf("Tarefa adicionada com sucesso!\n");

    } else {
        printf("Limite de tarefas atingido!\n");
    }
}

//Editar uma tarefa existente
void editTask() {

    int numTask;

    printf("Digite o numero da tarefa que deseja editar: ");
    scanf("%d", &numTask);

    numTask--;

    if (numTask >= 0 && numTask < numTasks) {
        printf("Novo titulo: ");
        scanf(" %[^\n]s", tasks[numTask].title);

        printf("Nova descricao: ");
        scanf(" %[^\n]s", tasks[numTask].description);

        printf("Novo prazo (DD/MM/AAAA): ");
        scanf(" %s", tasks[numTask].completionDeadline);

        printf("Tarefa editada com sucesso!\n");

    } else {
        printf("Numero de tarefa invalido!\n");
    }
}

//Função para Concluir uma tarefa
void markCompleted() {

    int numTask;

    printf("Digite o numero da tarefa concluida: ");
    scanf("%d", &numTask);

    numTask--;

    if (numTask >= 0 && numTask < numTasks) {
        tasks[numTask].status = CONCLUIDA;

        printf("Tarefa marcada como concluida!\n");

    } else {
        printf("Numero de tarefa invalido!\n");
    }
}

//Mostrar todas as tarefas
void allTasks() {

    printf("Todas as tarefas:\n");

    for (int i = 0; i < numTasks; ++i) {
        printf("Tarefa %d\n", i + 1);
        printf("Titulo: %s\n", tasks[i].title);
        printf("Descricao: %s\n", tasks[i].description);
        printf("Data de criacao: %s\n", tasks[i].dateCreation);
        printf("Prazo de conclusao: %s\n", tasks[i].completionDeadline);
        printf("Status: %s\n", tasks[i].status == PENDENTE ? "Pendente" : "Concluida");
        printf("\n");
    }
}

//Mostrar tarefas pendentes
void pendingTasks() {

    printf("Tarefas pendentes:\n");

    for (int i = 0; i < numTasks; ++i) {

        if (tasks[i].status == PENDENTE) {
            printf("Tarefa %d\n", i + 1);
            printf("Titulo: %s\n", tasks[i].title);
            printf("Descricao: %s\n", tasks[i].description);
            printf("Data de criacao: %s\n", tasks[i].dateCreation);
            printf("Prazo de conclusao: %s\n", tasks[i].completionDeadline);
            printf("\n");
        }
    }
}

//Mostrar tarefas concluídas
void completedTasks() {

    printf("Tarefas concluidas:\n");

    for (int i = 0; i < numTasks; ++i) {

        if (tasks[i].status == CONCLUIDA) {
            printf("Tarefa %d\n", i + 1);
            printf("Titulo: %s\n", tasks[i].title);
            printf("Descricao: %s\n", tasks[i].description);
            printf("Data de criacao: %s\n", tasks[i].dateCreation);
            printf("Prazo de conclusao: %s\n", tasks[i].completionDeadline);
            printf("\n");
        }
    }
}

//Menu Interativo
int main() {

    int opcao;

    //Loop do menu interativo do programa
    do {
        printf("\n---> GERENCIADOR DE TAREFAS <---\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Editar Tarefa\n");
        printf("3. Concluir Tarefa\n");
        printf("4. Todas as Tarefas\n");
        printf("5. Tarefas Pendentes\n");
        printf("6. Tarefas Concluidas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                addTask();
                break;
            case 2:
                editTask();
                break;
            case 3:
                markCompleted();
                break;
            case 4:
                allTasks();
                break;
            case 5:
                pendingTasks();
                break;
            case 6:
                completedTasks();
                break;
            case 0:
                printf("Saindo... Bye Bye Xuxuzinho ;)\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}