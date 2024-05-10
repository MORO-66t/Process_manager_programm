#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void listAllProcesses() {
    system("ps aux");
}

void listProcessesByUser(char* input) {
  char command[1000]; // Adjust the size as needed
    snprintf(command, sizeof(command), "ps aux | awk '$1 == \"%s\"'", input);
    system(command);
}

void displayProcessID() {
    system("ps aux | awk '{print $2}'");
}

void  runOrStopProcess(int pid, int action) {
    if (action == 1)
        kill(pid, SIGCONT);
    else if (action == 0)
        kill(pid, SIGSTOP);
}

void sendSignal(int pid, int signal) {
    kill(pid, signal);
}
void menu() {
    int choice,pid,signal;

    while (1) {
        printf("\nProcess Manager Menu:\n");
        printf("1. List all processes in the system\n");
        printf("2. List all processes grouped by user\n");
        printf("3. Display process ID of all processes\n");
        printf("4. Run/stop a specific process\n");
        printf("5. Send specific signals to specific process\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        choose(choice);
    }
}

void choose(int choice) {

    int signal,pid;
    char input[50]; 
    switch (choice) {
        case 1:
            listAllProcesses();
            break;
        case 2:
            printf("Enter User to search for: ");
            scanf("%s", input);
            listProcessesByUser(input);
            break;
        case 3:
            displayProcessID();
            break;
        case 4:
            printf("Enter PID of the process: ");
            scanf("%d", &pid);
            printf("Enter signal (0 for SIGSTOP, 1 for SIGCONT): ");
            scanf("%d", &signal);
            runOrStopProcess( pid, signal);
            break;
        case 5:
            printf("Enter PID of the process: ");
            scanf("%d", &pid);
            printf("Enter signal (e.g. 2 for interrupt, 9 for kill, 15 for terminate, 18 for continue, 19 for stop) : ");
            scanf("%d", &signal);
            sendSignal(pid, signal);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
    }
}


int main()
{
    int choice;
   while (1){
   menu();
   }
    return 0;
}
