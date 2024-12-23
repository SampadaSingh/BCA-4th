#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <sched.h>

int flag[2];
int turn;
const int MAX = 1e9;
int ans = 0;

void Pthread_mutex_lock(pthread_mutex_t *m) {
    int rc = pthread_mutex_lock(m);
    assert(rc == 0);
}

void Pthread_mutex_unlock(pthread_mutex_t *m) {
    int rc = pthread_mutex_unlock(m);
    assert(rc == 0);
}

void Pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg) {
    int rc = pthread_create(thread, attr, start_routine, arg);
    assert(rc == 0);
}

void Pthread_join(pthread_t thread, void **value_ptr) {
    int rc = pthread_join(thread, value_ptr);
    assert(rc == 0);
}

void lock_init() {
    flag[0] = flag[1] = 0;
    turn = 0;
}

void lock(int self) {
    flag[self] = 1;
    turn = 1 - self;
    while (flag[1 - self] == 1 && turn == 1 - self);
}

void unlock(int self) {
    flag[self] = 0;
}

void* func(void *s) {
    int i = 0;
    int self = (int) s;
    printf("Thread Entered: %d\n", self);

    lock(self);
    for (i = 0; i < MAX; i++) ans++;
    unlock(self);
}

int main() {
    pthread_t p1, p2;
    lock_init();
    pthread_create(&p1, NULL, func, (void*)0);
    pthread_create(&p2, NULL, func, (void*)1);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("Actual Count: %d | Expected Count: %d\n", ans, MAX * 2);
    return 0;
}
