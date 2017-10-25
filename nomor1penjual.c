#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main()
{
		//penjual
        key_t key = 1234;
        int *stock;

        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, NULL, 0);
		for(int i=0;i<6;i++)stock[i]=0;
        
        while(1){
        	printf("Menu:\n");
        	printf("1. Tampilkan Stock\n");
        	printf("2. Tambah Stock\n");
        	printf("3. Keluar\n");
        	int command;
			scanf("%d", &command);
			if(commnad==1){
				char *name;
				scanf("%s", &name);
				if(strcmp(name,"MP4A1")==0){
					if(stock[0]>0)printf("Jumlah MP4A1 di stock= %d\n",stock[0]);
					else printf("Stock tidak ada\n")
				}
				else if(strcmp(name,"PM2-V1")==0){
					if(stock[1]>0)printf("Jumlah PM2-V1 di stock= %d\n",stock[1]);
					else printf("Stock tidak ada\n")
				}
				else if(strcmp(name,"SPR-3")==0){
					if(stock[2]>0)printf("Jumlah SPR-3 di stock= %d\n",stock[2]);
					else printf("Stock tidak ada\n")
				}
				else if(strcmp(name,"SS2-V5")==0){
					if(stock[3]>0)printf("Jumlah SS2-V5 di stock= %d\n",stock[3]);
					else printf("Stock tidak ada\n")
				}
				else if(strcmp(name,"SPG1-V3")==0){
					if(stock[4]>0)printf("Jumlah SPG1-V3 di stock= %d\n",stock[4]);
					else printf("Stock tidak ada\n")
				}
				else if(strcmp(name,"MINE")==0){
					if(stock[5]>0)printf("Jumlah MINE di stock= %d\n",stock[5]);
					else printf("Stock tidak ada\n")
				}
			}
			else if(command==2){
				char *name;
				int amount;
				scanf("%s %d", &name,&amount);
				if(strcmp(name,"MP4A1")==0){
					stock[0]+=amount;
				}
				else if(strcmp(name,"PM2-V1")==0){
					stock[1]+=amount;
				}
				else if(strcmp(name,"SPR-3")==0){
					stock[2]+=amount;
				}
				else if(strcmp(name,"SS2-V5")==0){
					stock[3]+=amount;
				}
				else if(strcmp(name,"SPG1-V3")==0){
					stock[4]+=amount;
				}
				else if(strcmp(name,"MINE")==0){
					stock[5]+=amount;
				}
			}
			else if(command==3)break;
        }
}
