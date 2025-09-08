#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x = 150;
        printf("hello, I am child (x:%d)\n", x);
    } else {
        // x = 200;
        printf("hello, I am parent (x:%d)\n", x);
    }
    return 0;
}