#include <stdio.h>
#include <pthread.h>

pthread_once_t once_control = PTHREAD_ONCE_INIT;

void initialize() {
    printf("Initialization function executed.\n");
}

void* thread_func(void* arg) {
    pthread_once(&once_control, initialize);
    printf("Thread %ld running\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_func, (void*)1);
    pthread_create(&t2, NULL, thread_func, (void*)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}


/*
int pthread_once(pthread_once_t *once_control, void (*init_routine)(void));
args:
    once_control：指向 ⁠pthread_once_t 类型的控制变量，必须静态初始化为 ⁠PTHREAD_ONCE_INIT
    ⁠init_routine：指向无参无返回值的初始化函数指针，该函数只会被调用一次。
description:
    保证 ⁠init_routine 只执行一次，即使多个线程同时调用 ⁠pthread_once，只有第一个线程会执行初始化函数，其他线程会等待初始化完成
*/