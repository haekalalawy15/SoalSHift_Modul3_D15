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
