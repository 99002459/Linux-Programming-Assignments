#include<stdio.h>
#include<pthread.h>
void* sum_func(void* subArray)
{
    int* arraypart = (int*)subArray;
    int sum_fun=0;
    for(int i=0;i<100;i++)
    {
        sum_fun+=subArray[i];;
    }
    pthread_exit((void*)sum_fun);

}
int main()
{
    static int array[1000];
    static int sum=0;
    void* sub_sum=NULL;
    for(int i=0;i<1000;i++)
    {
        array[i]=i;
    }
    pthread_t threads[10];
    for(int i=0;i<10;i++)
    {
        int* subArray=array + (i*100);
        pthread_create(&threads[i],NULL,sub_sum,(void*) subArray);
    }
    for(int i=0;i<10;i++)
    {
        pthread_join(threads[i],&sub_sum);
        sum+=(int)sub_sum;
    }
    printf("total = %d\n",sum);
    return 0;
}