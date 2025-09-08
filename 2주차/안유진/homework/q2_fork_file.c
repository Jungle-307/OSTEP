#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Open file before fork
    int fd = open("test_file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open failed");
        exit(1);
    }
    
    printf("File opened with fd: %d\n", fd);
    
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // Child process
        char child_msg[] = "Hello from child process\n";
        printf("Child: attempting to write to fd %d\n", fd);
        if (write(fd, child_msg, strlen(child_msg)) < 0) {
            perror("Child write failed");
        } else {
            printf("Child: successfully wrote to file\n");
        }
    } else {
        // Parent process
        char parent_msg[] = "Hello from parent process\n";
        printf("Parent: attempting to write to fd %d\n", fd);
        if (write(fd, parent_msg, strlen(parent_msg)) < 0) {
            perror("Parent write failed");
        } else {
            printf("Parent: successfully wrote to file\n");
        }
        wait(NULL);  // Wait for child to complete
    }
    
    close(fd);
    printf("Process %d: closed file descriptor\n", (int)getpid());
    return 0;
}