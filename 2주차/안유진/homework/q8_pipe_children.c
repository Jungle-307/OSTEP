#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int pipefd[2];
    int rc1, rc2;
    
    printf("Parent process (pid:%d) starting\n", (int)getpid());
    
    // Create pipe before forking
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        exit(1);
    }
    
    printf("Parent: created pipe with fds %d (read) and %d (write)\n", 
           pipefd[0], pipefd[1]);
    
    // Create first child (producer - writes to pipe)
    rc1 = fork();
    if (rc1 == 0) {
        // Child 1: Producer
        printf("Child 1 (pid:%d): Producer starting\n", (int)getpid());
        
        // Close read end of pipe (not needed)
        close(pipefd[0]);
        
        // Redirect stdout to write end of pipe
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        
        // Execute command that produces output
        execlp("ls", "ls", "-l", NULL);
        printf("Child 1: exec failed\n");
        exit(1);
    }
    
    // Create second child (consumer - reads from pipe)
    rc2 = fork();
    if (rc2 == 0) {
        // Child 2: Consumer
        printf("Child 2 (pid:%d): Consumer starting\n", (int)getpid());
        
        // Close write end of pipe (not needed)
        close(pipefd[1]);
        
        // Redirect stdin to read end of pipe
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        
        // Execute command that processes input
        execlp("wc", "wc", "-l", NULL);
        printf("Child 2: exec failed\n");
        exit(1);
    }
    
    // Parent process
    printf("Parent: created producer child (pid %d) and consumer child (pid %d)\n", 
           rc1, rc2);
    
    // Close both ends of pipe in parent (children have their own copies)
    close(pipefd[0]);
    close(pipefd[1]);
    
    // Wait for both children to complete
    printf("Parent: waiting for producer child...\n");
    wait(NULL);
    printf("Parent: waiting for consumer child...\n");
    wait(NULL);
    
    printf("Parent: both children completed - pipeline finished\n");
    return 0;
}