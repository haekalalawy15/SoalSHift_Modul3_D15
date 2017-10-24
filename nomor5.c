#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid1;
pthread_t tid2;
int status;
 


int main(void)
{

    pthread_create(&(tid1), NULL, &ifah, NULL);
    pthread_create(&(tid2), NULL, &fina, NULL);
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    return 0;
}
