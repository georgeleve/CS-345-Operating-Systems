		/*   Georgios Gerasimos Leventopoulos  */
		/*     Assignment 2  Operating Systems */

- For this exercise, I made 1 thread for the chef and N=7 threads for the customers.

- I made two functions (chef and customer), that run the threads.
  This thread of the chef finishes when all the customers are served.

- I use 4 semaphores to synchronize the threads. 

- The main function creates 3 customer threads and waits for 3 seconds.
  So the chef serves 3 customers and chef waits for the next 3 customers etc
