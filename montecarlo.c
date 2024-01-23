#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<pthread.h>

#define NUMTHREADS 20

int circleCount;
int squareCount;
pthread_mutex_t mutex;

void* montecarlo(void* arg)
{
    int threadid = *(int*)arg;
    //printf("This is thread %d\n",threadid);                                                                                                                                                                                                 

    struct drand48_data randbuf;
    srand48_r(threadid, &randbuf);
    double randx, randy;
    for(int i = 0; i < 10000; i++)
      {
        drand48_r(&randbuf, &randx);
        drand48_r(&randbuf, &randy);

        if (((randx * randx) + (randy * randy)) <= 1)
        {
          //printf("(%f,%f)\n", randx, randy);                                                                                                                                                                                                
            pthread_mutex_lock(&mutex);
            circleCount++;
            pthread_mutex_unlock(&mutex);
        }
        pthread_mutex_lock(&mutex);
        squareCount++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(){
    pthread_t threads[NUMTHREADS];
    int threadids[NUMTHREADS];

    for(int i = 0; i < NUMTHREADS; i++)
    {
      threadids[i] = i;
      pthread_create(&threads[i], NULL, montecarlo, &threadids[i]);
    }

    for(int i = 0; i < NUMTHREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    //printf("Total points:%d\n", squareCount);                                                                                                                                                                                               

    double pi = 4.0 * (double)circleCount / squareCount;
    printf("%.7g\n", pi);

    return 0;
}

//OUTPUT: 3.13984