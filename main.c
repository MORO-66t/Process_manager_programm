#include "Header.h"
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

void listProcessesByUser() {
    system("ps aux | awk '{print $1}' | sort | uniq");
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

    switch (choice) {
        case 1:
            listAllProcesses();
            break;
        case 2:
            listProcessesByUser();
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
            printf("Enter signal (e.g., 9 for SIGKILL): ");
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

