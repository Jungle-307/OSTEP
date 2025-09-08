#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("Parent process (pid:%d) demonstrating exec() variants\n", (int)getpid());
    
    // 1. execl() - list arguments individually
    int rc1 = fork();
    if (rc1 == 0) {
        printf("Child 1: Using execl()\n");
        execl("/bin/ls", "ls", "-l", NULL);
        printf("This won't print if exec succeeds\n");
    }
    wait(NULL);
    
    // 2. execlp() - uses PATH to find executable
    int rc2 = fork();
    if (rc2 == 0) {
        printf("Child 2: Using execlp() (searches PATH)\n");
        execlp("ls", "ls", "-la", NULL);
        printf("This won't print if exec succeeds\n");
    }
    wait(NULL);
    
    // 3. execv() - arguments as array
    int rc3 = fork();
    if (rc3 == 0) {
        printf("Child 3: Using execv()\n");
        char *args[] = {"ls", "-l", "-h", NULL};
        execv("/bin/ls", args);
        printf("This won't print if exec succeeds\n");
    }
    wait(NULL);
    
    // 4. execvp() - arguments as array, searches PATH
    int rc4 = fork();
    if (rc4 == 0) {
        printf("Child 4: Using execvp()\n");
        char *args[] = {"ls", "-a", NULL};
        execvp("ls", args);
        printf("This won't print if exec succeeds\n");
    }
    wait(NULL);
    
    // 5. execve() - with custom environment
    int rc5 = fork();
    if (rc5 == 0) {
        printf("Child 5: Using execve() with custom environment\n");
        char *args[] = {"ls", "-l", NULL};
        char *env[] = {"PATH=/bin:/usr/bin", "HOME=/tmp", NULL};
        execve("/bin/ls", args, env);
        printf("This won't print if exec succeeds\n");
    }
    wait(NULL);
    
    printf("Parent process completed all exec() demonstrations\n");
    return 0;
}