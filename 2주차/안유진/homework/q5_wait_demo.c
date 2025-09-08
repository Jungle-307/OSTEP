#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("Parent process (pid:%d) starting\n", (int)getpid());
    
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // Child process
        printf("Child process (pid:%d) starting\n", (int)getpid());
        
        // Test what happens when child calls wait()
        printf("Child: calling wait()...\n");
        int child_wait_result = wait(NULL);
        printf("Child: wait() returned %d\n", child_wait_result);
        
        printf("Child: sleeping for 2 seconds\n");
        sleep(2);
        printf("Child: exiting with status 42\n");
        exit(42);
    } else {
        // Parent process
        printf("Parent: created child with pid %d\n", rc);
        printf("Parent: calling wait() to wait for child...\n");
        
        int status;
        int wait_result = wait(&status);
        
        printf("Parent: wait() returned %d\n", wait_result);
        
        if (WIFEXITED(status)) {
            printf("Parent: child exited normally with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Parent: child terminated by signal %d\n", WTERMSIG(status));
        }
        
        printf("Parent: done\n");
    }
    
    return 0;
}