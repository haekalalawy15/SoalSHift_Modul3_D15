#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[100];
int inp[100];

int main(int argc, char* argv[])
{	
   for(int i=0;i<argc;i++){
    	inp[i]=(int)(*argv[i]-48);
    }
   for (int i = 1; i < argc; i++){
	int tmp;
       for (int j = 1; j < argc-i; j++){ 
           if (inp[j] < inp[j+1])
              tmp=inp[j];
              inp[j]=inp[j+1];
              inp[j+1]=tmp;
	}
   }	
	for(int i=1;i<argc;i++){
		int *arg=malloc(sizeof(*arg));
		*arg=i;
		pthread_create(&(tid[i]), NULL, &faktorial,(void *)arg);
	}
	
	for(int i=0;i<argc;i++){
		pthread_join(tid[i],NULL);
	}
}

