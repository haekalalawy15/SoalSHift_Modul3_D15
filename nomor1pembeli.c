void main()
{
		//pembeli
        key_t key = 1234;
        int *stock;

        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, NULL, 0);
     
        while(1){
        	printf("Menu:\n");
        	printf("1. Tampilkan Stock\n");
        	printf("2. Beli Senjata\n");
        	printf("3. Keluar\n");
        	if(command==1){
        		printf("MP4A1 %d\n",stock[0]);
        		printf("PM2-V1 %d\n",stock[1]);
        		printf("SPR-3 %d\n",stock[2]);
        		printf("SS2-V5 %d\n",stock[3]);
        		printf("SPG1-V3 %d\n",stock[4]);
        		printf("MINE %d\n",stock[5]);
        	}
        	else if(command==2){
        			char *name;
				int amount;
				scanf("%s %d", &name,&amount);
				if(strcmp(name,"MP4A1")==0){
					if(stock[0]>0)stock[0]-=amount;
					else("Barang di Stock tidak cukup\n");
				}
				else if(strcmp(name,"PM2-V1")==0){
					if(stock[1]>0)stock[1]-=amount;
					else("Barang di Stock tidak cukup\n");
				}
				else if(strcmp(name,"SPR-3")==0){
					if(stock[2]>0)stock[2]-=amount;
					else("Barang di Stock tidak cukup\n");
				}
				else if(strcmp(name,"SS2-V5")==0){
					if(stock[3]>0)stock[3]-=amount;
					else("Barang di Stock tidak cukup\n");
				}
				else if(strcmp(name,"SPG1-V3")==0){
					if(stock[4]>0)stock[4]-=amount;
					else("Barang di Stock tidak cukup\n");
				}
				else if(strcmp(name,"MINE")==0){
					if(stock[5]>0)stock[5]-=amount;
					else("Barang di Stock tidak cukup\n");
				}
        	}
        	else if(command==3)break;
        }
}
