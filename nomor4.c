#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[100];
int inp[100];

void* faktorial(void* n){
	int* m=(int*)n;
	int l= *m;
	int ans=inp[l];
	for(int i=inp[l]-1;i>0;i--){
		ans*=i;	
	}
	printf("%d!= %d\n",inp[l],ans);
}

int main(int argc, char* argv[])
{	
   for(int i=0;i<argc;i++){
    	inp[i]=(int)(*argv[i]-48);
    }
/*   for (int i = 1; i < argc-1; i++){
	int tmp;
       for (int j = 1; j < argc-i-1; j++){ 
           if (inp[j] < inp[j+1])
              tmp=inp[j];
              inp[j]=inp[j+1];
              inp[j+1]=tmp;
	}
   }*/	

//	for(int i=0;i<argc;i++)printf("isi inp %d\n",inp[i]); 
	for(int i=1;i<argc;i++){
		int *arg=malloc(sizeof(*arg));
		*arg=i;
		pthread_create(&(tid[i]), NULL, &faktorial,(void *)arg);
	}
	
	for(int i=0;i<argc;i++){
		pthread_join(tid[i],NULL);
	}
}

