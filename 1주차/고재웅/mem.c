#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[]) {
    int *p = malloc(sizeof(int)); // 정수형 포인터 p에 메모리 할당
    assert(p != NULL); // p가 NULL이 아닌지 확인
    printf("(%d) p의 메모리 주소: %08x\n", getpid(), (unsigned) p); // 프로세스 ID와 p의 메모리 주소 출력
    *p = 0; // p가 가리키는 값을 0으로 초기화
    while (1) {
        Spin(1); // 1초 대기
        *p = *p + 1; // p가 가리키는 값을 1 증가
        printf("(%d) p: %d\n", getpid(), *p); // 프로세스 ID와 p가 가리키는 값 출력
    }
    return 0;
}