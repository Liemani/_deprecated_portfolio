#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void* print1(void* arg);
void* print2(void* arg);
void* print3(void* arg);

static sem_t sem_one;
static sem_t sem_two;
static sem_t sem_three;

int main(int argc, char** argv) {
	pthread_t id_t1, id_t2, id_t3;
	sem_init(&sem_one, 0, 1);
	sem_init(&sem_two, 0, 0);
	sem_init(&sem_three, 0, 0);

	pthread_create(&id_t1, NULL, print1, NULL);
	pthread_create(&id_t2, NULL, print2, NULL);
	pthread_create(&id_t3, NULL, print3, NULL);

	pthread_join(id_t1, NULL);
	pthread_join(id_t2, NULL);
	pthread_join(id_t3, NULL);

	sem_destroy(&sem_one);
	sem_destroy(&sem_two);
	sem_destroy(&sem_three);
	return 0;
}

void* print1(void* arg) {
	for (int i = 0; i < 5; ++i) {
		sem_wait(&sem_three);
		printf("print1\n");
		sem_post(&sem_one);
	}

	return NULL;
}

void* print2(void* arg) {
	for (int i = 0; i < 5; ++i) {
		sem_wait(&sem_two);
		printf("print2\n");
		sem_post(&sem_three);
	}

	return NULL;
}

void* print3(void* arg) {
	for (int i = 0; i < 5; ++i) {
		sem_wait(&sem_one);
		printf("print3\n");
		sem_post(&sem_two);
	}

	return NULL;
}
