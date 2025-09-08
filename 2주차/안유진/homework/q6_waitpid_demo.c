#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("Parent process (pid:%d) starting\n", (int)getpid());
    
    // Create first child
    int rc1 = fork();
    if (rc1 == 0) {
        printf("Child 1 (pid:%d): sleeping for 3 seconds\n", (int)getpid());
        sleep(3);
        printf("Child 1: exiting with status 1\n");
        exit(1);
    }
    
    // Create second child
    int rc2 = fork();
    if (rc2 == 0) {
        printf("Child 2 (pid:%d): sleeping for 1 second\n", (int)getpid());
        sleep(1);
        printf("Child 2: exiting with status 2\n");
        exit(2);
    }
    
    // Parent process - demonstrate waitpid() advantages
    printf("Parent: created children with pids %d and %d\n", rc1, rc2);
    
    // 1. Wait for specific child (child 2)
    printf("Parent: waiting specifically for child 2 (pid %d)\n", rc2);
    int status;
    int wait_result = waitpid(rc2, &status, 0);
    printf("Parent: waitpid() returned %d for child 2\n", wait_result);
    if (WIFEXITED(status)) {
        printf("Parent: child 2 exited with status %d\n", WEXITSTATUS(status));
    }
    
    // 2. Non-blocking wait for child 1
    printf("Parent: checking if child 1 is done (non-blocking)...\n");
    wait_result = waitpid(rc1, &status, WNOHANG);
    if (wait_result == 0) {
        printf("Parent: child 1 is still running\n");
    } else if (wait_result > 0) {
        printf("Parent: child 1 finished with pid %d\n", wait_result);
    }
    
    // 3. Wait for child 1 (blocking)
    printf("Parent: now waiting for child 1 to complete...\n");
    wait_result = waitpid(rc1, &status, 0);
    printf("Parent: waitpid() returned %d for child 1\n", wait_result);
    if (WIFEXITED(status)) {
        printf("Parent: child 1 exited with status %d\n", WEXITSTATUS(status));
    }
    
    printf("Parent: all children completed\n");
    return 0;
}