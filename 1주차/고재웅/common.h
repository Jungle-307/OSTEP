#ifndef __common_h__
#define __common_h__

#include <assert.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

#define Malloc(s) ({ void *p = malloc(s); assert(p != NULL); p; })
#define Time_GetSeconds() ({ struct timeval t; int rc = gettimeofday(&t, NULL); assert(rc == 0); (double) t.tv_sec + (double) t.tv_usec/1e6; })

void Spin(int howlong) {
    double t = Time_GetSeconds();
    while ((Time_GetSeconds() - t) < (double) howlong)
        ; // 지정된 시간(초) 동안 대기
}

void Pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine)(void*), void *arg) {
    int rc = pthread_create(thread, attr, start_routine, arg);
    assert(rc == 0);
}

void Pthread_join(pthread_t thread, void **value_ptr) {
    int rc = pthread_join(thread, value_ptr);
    assert(rc == 0);
}

#endif // __common_h__