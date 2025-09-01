#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    assert(fd > -1); // 파일 열기를 확인
    int rc = write(fd, "hello world\n", 13); // "hello world\n" 문자열 쓰기
    assert(rc == 13); // 쓰기 작업을 확인
    close(fd); // 파일 닫기
    return 0;
}