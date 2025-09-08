#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int pipefd[2];
    char buffer;
    
    // Create pipe for synchronization
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        exit(1);
    }
    
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // Child process
        close(pipefd[0]); // Close read end
        printf("hello\n");
        write(pipefd[1], "x", 1); // Signal parent that child is done
        close(pipefd[1]);
    } else {
        // Parent process
        close(pipefd[1]); // Close write end
        read(pipefd[0], &buffer, 1); // Wait for child to signal
        close(pipefd[0]);
        printf("goodbye\n");
        // Note: Not using wait() as requested
    }
    return 0;
}