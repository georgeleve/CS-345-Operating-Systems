
/*   Georgios Gerasimos Leventopoulos csd4152  */
/*     Assignment 2  Operating Systems         */

#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SLEEP_TIME 3
#define TRUE 1
#define N 7  /* Customer threads */ 

/* Use semaphore gia na mhn trexoun ola ta threads parallhla */
sem_t sem_1, sem_2, sem_3, sem_4;
int count = 0;

/* The chef thread runs in this method */
void *chef(void *arg) {
    while(TRUE) { 
        if(count%3==0 && count!=0) printf("Chef is on FB and waits for the next customers..\n\n");
        sem_post(&sem_1); /* Ched waits for custoem==mer */
        sem_wait(&sem_2); /* Chef saw an available customer */
        printf("Chef: Serves food.\n"); 
        sem_post(&sem_3); /* The food is ready */
        sem_wait(&sem_4); /* Chef waits for customer to leave */ 
        count++;
        if(count == N) break; /* Finish the program when there are no customers left. */
    }
    pthread_exit(NULL);
}

/* All the customer threads run in this method */
void *customer(void *arg) {
    sem_wait(&sem_1); /* Customer waits for chef to be ready to take customer order */
    printf("Customer: Orders food.\n");
    sem_post(&sem_2); /* Customer ordered the food */
    
    sem_wait(&sem_3); /* Customer takes the food */
    printf("Customer: Left.\n\n");
    sem_post(&sem_4); /* Customer left */
    pthread_exit(NULL);
}

/* Only main() method creates threads */
int main() {
    pthread_t chef_thread, customer_thread[N];
    int rc1, rc2, i;
    i = 0;
   
    sem_init(&sem_1, 0, 0); /* Initialize semaphores */
    sem_init(&sem_2, 0, 0);
    sem_init(&sem_3, 0, 0);
    sem_init(&sem_4, 0, 0);

    printf("Start\n\n");
    rc1 = pthread_create(&chef_thread, NULL, chef, NULL); /* Create 1 thread for chef */ 
    if(rc1 != 0) { 
        printf("Error: return code from pthread_create() is %d\n:", rc1);
        exit(-1);
    }

    /* Create N customer threads */
    while(i < N) {
        if(i%3==0 && i!=0) {
            sleep(SLEEP_TIME); /* Sleep every 3 customers */
        }
        rc2 = pthread_create(&customer_thread[i], NULL, customer, NULL); 
        if(rc2 != 0) {
            printf("Error: return code from pthread_create() is %d\n:", rc2);
            exit(-1);
        }
        i++;
    }
    pthread_join(chef_thread, NULL);  /* main() waits the threads to finish */
    printf("End\n");
    
    sem_destroy(&sem_1);   /* Free semaphores */
    sem_destroy(&sem_2);
    sem_destroy(&sem_3);
    sem_destroy(&sem_4);
    
    return 0;
}
