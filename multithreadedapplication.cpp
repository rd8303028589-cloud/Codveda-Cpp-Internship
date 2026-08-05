#include <iostream>
#include<pthread.h>
#include <unistd.h>

using namespace std;

const int BUFFER_SIZE = 5;
const int TOTAL_ITEMS = 10;

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

pthread_mutex_t mutexLock;
pthread_cond_t notFull;
pthread_cond_t notEmpty;

// Producer thread
void* producer(void* arg)
{
    for (int item = 1; item <= TOTAL_ITEMS; item++)
    {
        pthread_mutex_lock(&mutexLock);

        // Wait if buffer is full
        while (((in + 1) % BUFFER_SIZE) == out)
        {
            pthread_cond_wait(&notFull, &mutexLock);
        }

        buffer[in] = item;
        cout << "Producer produced: " << item << endl;

        in = (in + 1) % BUFFER_SIZE;

        pthread_cond_signal(&notEmpty);
        pthread_mutex_unlock(&mutexLock);

        sleep(1);
    }

    return nullptr;
}

// Consumer thread
void* consumer(void* arg)
{
    for (int i = 1; i <= TOTAL_ITEMS; i++)
    {
        pthread_mutex_lock(&mutexLock);

        // Wait if buffer is empty
        while (in == out)
        {
            pthread_cond_wait(&notEmpty, &mutexLock);
        }

        int item = buffer[out];

        cout << "Consumer consumed: " << item << endl;

        out = (out + 1) % BUFFER_SIZE;

        pthread_cond_signal(&notFull);
        pthread_mutex_unlock(&mutexLock);

        sleep(2);
    }

    return nullptr;
}

int main()
{
    pthread_t producerThread;
    pthread_t consumerThread;

    // Initialize mutex and condition variables
    pthread_mutex_init(&mutexLock, nullptr);
    pthread_cond_init(&notFull, nullptr);
    pthread_cond_init(&notEmpty, nullptr);

    cout << "===== Producer Consumer Simulation =====" << endl;
    cout << "Buffer Size: " << BUFFER_SIZE << endl;
    cout << "Total Items: " << TOTAL_ITEMS << endl << endl;

    // Create threads
    pthread_create(&producerThread, nullptr, producer, nullptr);
    pthread_create(&consumerThread, nullptr, consumer, nullptr);

    // Wait for threads to finish
    pthread_join(producerThread, nullptr);
    pthread_join(consumerThread, nullptr);

    // Destroy synchronization objects
    pthread_mutex_destroy(&mutexLock);
    pthread_cond_destroy(&notFull);
    pthread_cond_destroy(&notEmpty);

    cout << endl;
    cout << "All items produced and consumed successfully." << endl;

    return 0;
}