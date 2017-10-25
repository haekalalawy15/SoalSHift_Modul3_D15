#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid1;
pthread_t tid2;
int status;

void* ifah(void *arg)
{
    status = 0;
 
    FILE * in;
    char * line=NULL;
    int count_ifah=0;
    size_t len=0;
    ssize_t read;
    in = fopen("Novel.txt","r");
    while((read=getline(&line,&len,in))!=-1)
    {
	if(strstr(line,"ifah")!=NULL||strstr(line,"Ifah")!=NULL)
	count_ifah++;
    }
    fclose(in);
    printf("ifah= %d \n",count_ifah);
    

 
    return NULL;
} 


void* fina(void *arg)
{
  
 
    FILE * in;
    char * line=NULL;
    int count_fina=0;
    size_t len=0;
    ssize_t read;
    in = fopen("Novel.txt","r");
    while((read=getline(&line,&len,in))!=-1)
    {
	if(strstr(line,"fina")!=NULL||strstr(line,"Fina")!=NULL)
	count_fina++;
    }
    fclose(in);
    printf("fina= %d \n", count_fina);
 
 
    return NULL;
}


int main(void)
{

    pthread_create(&(tid1), NULL, &ifah, NULL);
    pthread_create(&(tid2), NULL, &fina, NULL);
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    return 0;
}
