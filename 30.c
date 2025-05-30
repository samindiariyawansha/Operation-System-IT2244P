//send

#include<stdio.h>
#include <sys/ipc.h>  
#include <sys/msg.h>  
#define MAX 10

//STRUCTURE FOR MESSAGE QUEUE
struct mesg_buffer{
	long mesg_type;
	char mesg_text[100];
}
message;
int main()
{
	key_t key;
	int msgid;
	//ftok to generate unique key

	key=ftok("progfile", 65);

//msgget creates a message queue
//and returns identifier

msgid =msgget(key, 0666 |IPC_CREAT);
message.mesg_type=1;
printf("Write data: ");
fgets(message.mesg_text,MAX,stdin);
//msgsnd to send message
msgsnd(msgid, &message,sizeof(message),0);
//display the message
printf("Data send is: %s \n", message.mesg_text);
return 0;
}



[samindi@DESKTOP-FSBHM1J ~]$ vi kk.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc kk.c -o kk
[samindi@DESKTOP-FSBHM1J ~]$ ./kk
Write data: hi sawi
Data send is: hi sawi

----------------------------------------------------------------

//receive

#include<stdio.h>
#include <sys/ipc.h>  
#include <sys/msg.h>  
//STRUCTURE FOR MESSAGE QUEUE
struct mesg_buffer{
	long mesg_type;
	char mesg_text[100];
}
message;
int main()
{
	key_t key;
	int msgid;
	//ftok to generate unique key

	key=ftok("progfile", 65);

//msgget creates a message queue
//and returns identifier

msgid =msgget(key, 0666 |IPC_CREAT);
//msgeov to receive message
msgrcv(msgid, &message,sizeof(message), 1,0);
//display the message
printf("Data Received is: %s \n", message.mesg_text);
//to destroy the message queue
msgctl(msgid, IPC_RMID,NULL);
return 0;
}


[samindi@DESKTOP-FSBHM1J ~]$ vi kl.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc kl.c -o kl
[samindi@DESKTOP-FSBHM1J ~]$ ./kl
Data Received is: hi sawi

	
	