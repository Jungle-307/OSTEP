#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid());
    int x = 100;
    printf("Initial value of x: %d\n", x);
    
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // Child process
        printf("Child: initial x value: %d\n", x);
        x = 150;
        printf("Child: after modification, x = %d\n", x);
    } else {
        // Parent process
        printf("Parent: initial x value: %d\n", x);
        x = 200;
        printf("Parent: after modification, x = %d\n", x);
        wait(NULL);  // Wait for child to complete
    }
    printf("Process %d: final x value = %d\n", (int)getpid(), x);
    return 0;
}