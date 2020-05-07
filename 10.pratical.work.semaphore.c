#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <semaphore.h>
sem_t sem;
pthread_mutex_t lock;
void *fibo() {
	int a = 1, b = 1;
	//pthread_mutex_lock(&lock);
	sem_wait(&sem);
	for (int i = 0; a < 10000 || b < 10000; i++) 
	{
		printf("%d\n%d\n", a, b);
		a = a + b;
		b = b + a;
	}
	sem_post(&sem);
	//pthread_mutex_unlock(&lock);
}

void *prime() {
	sem_wait(&sem);
	//pthread_mutex_lock(&lock);
	for (int i = 2; i < 10000; i++){
		int isPrime = 1;
		for(int j = 2; j <= sqrt(i); j++) 
		       if (i % j == 0) { isPrime = 0;  break;}
		if (isPrime == 1) printf("%d ",i);	
	}
	sem_post(&sem);
	//pthread_mutex_unlock(&lock);
}
int main() 
{
	//pthread_mutex_init(&lock,NULL);
	sem_init(&sem,0, 1);
	pthread_t t1, t2;
	int thread1 = pthread_create(&t1, NULL, fibo, NULL);
	int thread2 = pthread_create(&t2, NULL, prime, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&sem);
	//pthread_mutex_destroy(&lock);
	return 0;
}
