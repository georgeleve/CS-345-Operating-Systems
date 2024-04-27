# Operating Systems
https://www.csd.uoc.gr/~hy345/assignments.html

Assignment 1: Linux Shell	Assignment:  
Implemented a C shell and became familiar with how it works. More  
specifically, I learned how to create and control processes, as well as what pipes are
and how they are implemented. Finally, I learned how input-output redirection is done using commands.

Assignment 2:	Process/Thread Synchronization:  
Exercise using semaphores and threads. For this exercise, I made 1 thread for the chef and N=7 threads for the customers.
I made two functions (chef and customer), that run the threads. This thread of the chef finishes when all the customers are served.  
I use 4 semaphores in order to synchronize the threads. The main function creates 3 customer threads and then waits for 3 seconds.  
So the chef serves 3 customers and chef waits for the next 3 customers etc.  

Assignment 3:	System Call Implementation:  
Created a new system call inside an old version of the Linux Kernel using QEMU  
