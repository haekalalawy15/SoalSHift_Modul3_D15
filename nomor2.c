#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid1;
pthread_t tid2;
int poin1=0;
int poin2=0;
int ranjau[2][17];
int terisi;
char* player1;
char* player2;
int status;


void show_point(){
	printf("%s : %d\n", &player1,poin1);
	printf("%s : %d\n", &player2,poin2);
}

void* turn_player1(void *arg)
{

    
    while(poin1<10&&poin2<10){
    	while(status == 1)
    	{

    	}
		if(status==2)return NULL;
		terisi=0;
    	for(int i=0;i<2;i++){
    		for(int j=1;j<=16;j++){
    			if(ranjau[i][j]==1)terisi++;
    		}
    	}
    	if(terisi==32)break;
	char c;
  	while(1){
		printf("Show Point?(y/n)\n");
 		scanf(" %c", &c);
    		if(c=='y'){show_point();break;}
		else break;
	}
    	printf("%s, Isi Lubang?(Jika kurang dari 4, isi dengan 0)\n", &player1);
    	for(int i=0;i<4;i++){
    		int n;
			scanf("%d", &n);
			ranjau[0][n]=1;
    	}
    	
    	system("clear");
    	
    	printf("%s, Tebak 4 Lubang\n", &player2);
    	for(int i=0;i<4;i++){
    		int n;
			scanf("%d", &n);
			if(ranjau[0][n]==1)poin1++;
			else poin2++;
    	}
    	
    	status=1;
	}
    printf("Permainan Berakhir\n");
	show_point();
	if(poin1>poin2)printf("%s menang\n", &player1);
	else if(poin1<poin2)printf("%s menang\n", &player2);
	else printf("Permainan Seri\n");
	status=2;
	return NULL;
 
}


void* turn_player2(void *arg)
{
    
    while(poin1<10&&poin2<10){
    	while(status == 0)
    	{

    	}
		if(status==2)return NULL;
		terisi=0;
    	for(int i=0;i<2;i++){
    		for(int j=1;j<=16;j++){
    			if(ranjau[i][j]==1)terisi++;
    		}
    	}
    	if(terisi==32)break;
	char c;
	while(1){
	    	printf("Show Point?(y/n)\n");
    		scanf(" %c", &c);
    		if(c=='y'){show_point();break;}
		else break;
    	}
    	printf("%s, Isi Lubang?(Jika kurang dari 4, isi dengan 0)\n", &player2);
    	for(int i=0;i<4;i++){
    		int n;
			scanf("%d", &n);
			ranjau[1][n]=1;
    	}
    	
   	system("clear");
    	
    	printf("%s, Tebak 4 Lubang\n", &player1);
    	for(int i=0;i<4;i++){
    		int n;
			scanf("%d", &n);
			if(ranjau[1][n]==1)poin2++;
			else poin1++;
    	}
    	
    	status=0;
	}
    printf("Permainan Berakhir\n");
	show_point();
	if(poin1>poin2)printf("%s menang\n", &player1);
	else if(poin1<poin2)printf("%s menang\n", &player2);
	else printf("Permainan Seri\n");
	status=2;
	return NULL;
    
    
}

int main()
{
	status = 0;
	printf("Nama Player 1: ");
	scanf("%s", &player1);
	printf("Nama Player 2: ");
	scanf("%s", &player2);
    pthread_create(&(tid1), NULL, &turn_player1, NULL);
    pthread_create(&(tid2), NULL, &turn_player2, NULL);
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    return 0;
}
