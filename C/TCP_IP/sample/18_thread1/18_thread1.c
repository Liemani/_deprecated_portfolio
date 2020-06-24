#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void* thread_main(void* arg);
void* thread_main2(void* arg);

int main(int argc, char** argv) {
	pthread_t thread1;
	pthread_t thread2;

	int thread_param = 5;

	if (pthread_create(&thread1, NULL, thread_main, (void*)&thread_param) != 0) {
		puts("pthread_craete() error");
		return -1;
	}

	if (pthread_create(&thread2, NULL, thread_main2, (void*)&thread_param) != 0) {
		puts("pthread_craete() error");
		return -1;
	}

	pthread_detach(thread1);
	pthread_detach(thread2);

	puts("end of main");
	return 0;
}

void* thread_main(void* arg) {
	int i;
	int cnt = *((int*)arg);

	for (i = 0; i < cnt; ++i) {
		sleep(1);
		puts("running thread2");
	}

	return NULL;
}

void* thread_main2(void* arg) {
	int i;
	int cnt = *((int*)arg);

	for (i = 0; i < cnt; ++i) {
		sleep(1);
		puts("running thread");
	}

	return NULL;
}
