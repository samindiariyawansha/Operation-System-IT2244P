//writer process1
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHM_SIZE 1024 //size of shared memory segment

int main(){
	key_t key = ftok("shmfile",31); //Generate unique key
	int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); //Create shared memory segment
	if(shmid ==-1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr = (char*) shmat(shmid,NULL, 0); //Attach to shared memory
	if(shmaddr == (char*) -1){
		perror("shmat");
		exit(1);
	}
	printf("Write Data: ");
	fgets(shmaddr, SHM_SIZE, stdin); //write data to shared memory
	
	printf("Data written in memory: %s\n",shmaddr);
	
	shmdt(shmaddr); //Detach from shared memory
	
	return 0;
}  

//Reader

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHM_SIZE 1024 //size of shared memory segment

int main(){
	key_t key = ftok("shmfile",31); //Generate unique key
	int shmid = shmget(key, SHM_SIZE, 0666); //access shared memory segment
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr = (char*) shmat(shmid,NULL, 0); //Attach to shared memory
	if(shmaddr == (char*) -1){
		perror("shmat");
		exit(1);
	}
	
	printf("Data read from memory: %s\n",shmaddr); //read data from shared memory
	
	shmdt(shmaddr); //Detach from shared memory
	
	shmctl(shmid,IPC_RMID, NULL); //Remove shared memory segment
	return 0;
}   


[samindi@DESKTOP-FSBHM1J ~]$ vi write.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc write.c -o write
[samindi@DESKTOP-FSBHM1J ~]$ vi read.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc read.c -o read
[samindi@DESKTOP-FSBHM1J ~]$ ./write
Write Data: hi How are you?
Data written in memory: hi How are you?

[samindi@DESKTOP-FSBHM1J ~]$ ./read
Data read from memory: hi How are you?
Data written in memory: apple

-----------------------------------------------------------------------------------------------------


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/wait.h>


int main(){
	size_t size = 4096;
	char *shared_mem = mmap(NULL,size,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if(shared_mem == MAP_FAILED){
		perror("mmap failed");
		exit(1);
	}
	pid_t pid = fork();
	if(pid == 0){
		//child process1
		sprintf(shared_mem,"Hello from child");
		printf("Child wrote: %s\n",shared_mem);
		exit(0);
		
	}else if(pid>0){
		//parent process1
		wait(NULL); //wait fo child to finish
		printf("parent read: %s\n",shared_mem);
		munmap(shared_mem,size);
	}else{
		perror("fork failed");
		exit(1);
	}
	return 0;
}
[samindi@DESKTOP-FSBHM1J ~]$ vi p.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc p.c -o p
[samindi@DESKTOP-FSBHM1J ~]$ ./p
Child wrote: Hello from child
parent read: Hello from child



------------------------------------------------------------------------------------------------------------------