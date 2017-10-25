#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

//int pthread_create(pthread_t * thread,const pthread_attr_t * attr,void * (*start_routine)(void *),void *arg);

pthread_t tid1;
pthread_t tid2;
int status_lohan=100;
int status_kepiting=100;
void* lohan(void *arg)
{
	int newstatus_lohan;
	do
	{
		sleep(5);
		status_lohan -=50;
		//status_lohan=newstatus_lohan;
	}while((status_lohan>0)&&(status_lohan<=100));
	
	printf("lohan mati\n");
	return (0);
}

void* kepiting(void *arg)
{
	int newstatus_kepiting;
    do
	{
		sleep(20);
		status_kepiting-=10;
		//status_kepiting=newstatus_kepiting;
	} while((status_kepiting>0)&&(status_kepiting<=100));
	
	printf("kepiting mati\n");
	return (0);
}

int main()
{
	char* feed;
	
	pthread_create(tid1,NULL,&lohan,NULL);
	pthread_create(tid2,NULL,&kepiting,NULL);
	
	while((status_lohan>0)&&(status_lohan<=100)&&(status_kepiting>0)&&(status_kepiting<=100))
	{
		scanf("%s", feed);
		if(strcmp(feed,"feed_lohan")==0) status_lohan+=10;
		else if(strcmp(feed,"feed_kepiting")==0) status_kepiting+=10;
	}
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
}
