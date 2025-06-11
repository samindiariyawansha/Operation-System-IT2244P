/*
Exercise:

Message queue:

read input from the parent process

Enter name: Hi
Enter reg no:2314
Enter age: 24
Message send Successfully!

Message queue:

give the output from the child process

Received name: Hi
Received reg no:2314
Received age: 24
*/

----------------------------------------------------------------
//send
	
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX 100

// Message structure
struct mesg_buffer {
    long mesg_type;
    char mesg_text[MAX];
} message;

int main() {
    key_t key;
    int msgid;

    // Generate unique key
    key = ftok("2021ict40", 40);

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    message.mesg_type = 1;

    char name[50], reg[20], age[10];

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter reg no: ");
    fgets(reg, sizeof(reg), stdin);

    printf("Enter age: ");
    fgets(age, sizeof(age), stdin);

    // Remove newline characters if present
    name[strcspn(name, "\n")] = 0;
    reg[strcspn(reg, "\n")] = 0;
    age[strcspn(age, "\n")] = 0;

    // Combine into single message
    snprintf(message.mesg_text, sizeof(message.mesg_text),
             "Enter name: %s\nEnter reg no:%s\nEnter age: %s", name, reg, age);

    // Send message
    msgsnd(msgid, &message, sizeof(message.mesg_text), 0);

    printf("Message send Successfully!\n");

    return 0;
}


//receive
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX 100

struct mesg_buffer {
    long mesg_type;
    char mesg_text[MAX];
};

int main() {
    key_t key;
    int msgid;
    struct mesg_buffer message;

    // Generate unique key
    key = ftok("2021ict40", 40);

    // Access message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Receive message
    msgrcv(msgid, &message, sizeof(message.mesg_text), 1, 0);

    // Parse received message
    char name[50], reg[20], age[10];
    char *line = strtok(message.mesg_text, "\n");

    if (line != NULL)
        sscanf(line, "Enter name: %s", name);
    line = strtok(NULL, "\n");

    if (line != NULL)
        sscanf(line, "Enter reg no:%s", reg);
    line = strtok(NULL, "\n");

    if (line != NULL)
        sscanf(line, "Enter age: %s", age);

    printf("\nMessage queue:\n");
    printf("Received name: %s\n", name);
    printf("Received reg no: %s\n", reg);
    printf("Received age: %s\n", age);

    // Remove message queue after receiving
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}



[samindi@DESKTOP-FSBHM1J ~]$ vi send.c
[samindi@DESKTOP-FSBHM1J ~]$ touch samindi
[samindi@DESKTOP-FSBHM1J ~]$ chmod 644 samindi
[samindi@DESKTOP-FSBHM1J ~]$ gcc send.c -o send
[samindi@DESKTOP-FSBHM1J ~]$ vi reads.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc reads.c -o reads

[samindi@DESKTOP-FSBHM1J ~]$ ./send
Enter name: sawi
Enter reg no: 3214
Enter age: 25
Message send Successfully!
[samindi@DESKTOP-FSBHM1J ~]$ ./reads

Message queue:
Received name: sawi
Received reg no: 3214
Received age: 25