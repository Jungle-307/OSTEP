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
        printf("Child: Before closing stdout\n");
        
        // Close standard output
        close(STDOUT_FILENO);
        printf("Child: This should not appear on screen after closing stdout\n");
        
        // Try to write to stderr instead (which should still work)
        fprintf(stderr, "Child: This message goes to stderr and should appear\n");
        
        // Try to write using direct file descriptor (should fail)
        char msg[] = "Child: Trying to write to fd 1 directly\n";
        int bytes_written = write(STDOUT_FILENO, msg, sizeof(msg) - 1);
        
        // Report the result via stderr
        fprintf(stderr, "Child: write() to stdout returned %d bytes\n", bytes_written);
        
        exit(0);
    } else {
        // Parent process
        printf("Parent: created child with pid %d\n", rc);
        wait(NULL);
        printf("Parent: child process completed\n");
    }
    
    return 0;
}