#include <pthread.h> 
#include <stdio.h> 
  
// Size of array 
#define max 16 
  
// Max number of thread 
#define thrd_max 4 
  
// Array 
int ar[max] = { 1, 3, 5, 7, 9, 12, 14, 16, 18, 20, 
               25, 30, 35, 45, 65, 130, 210 }; 
  
// Array to store max of threads 
int max_num[thrd_max] = { 0 }; 
int thread_no = 0; 
  
// Function to find maximum 
void maximum(void* arg) 
{ 
    int i, num = thread_no++; 
    int maxEl = 0; 
  
    for (i = num * (max / 4); i < (num + 1) * (max / 4); i++) { 
        if (ar[i] > maxEl) 
            maxEl = ar[i]; 
    } 
  
    max_num[num] = maxEl; 
} 
  
// Driver code 
int main() 
{ 
    int maxEl = 0; 
    int i; 
    pthread_t threads[thrd_max]; 
  
    // creating 4 threads 
    for (i = 0; i < thrd_max; i++) 
        pthread_create(&threads[i], NULL, 
                       maximum, (void*)NULL); 
  
    // joining 4 threads i.e. waiting for 
    // all 4 threads to complete 
    for (i = 0; i < thrd_max; i++) 
        pthread_join(threads[i], NULL); 
  
    // Finding max element in an array 
    // by individual threads 
    for (i = 0; i < thrd_max; i++) { 
        if (max_num[i] > maxEl) 
            maxEl = max_num[i]; 
    } 
  
    printf("Maximum Element is : %d", maxs); 
  
    return 0; 
} 