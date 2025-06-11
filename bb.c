#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>  // getpid, getppid

#define MAX 100

struct mesg_buffer {
    long mesg_type;
    char mesg_text[MAX];
};

int main() {
    key_t key;
    int msgid;

    key = ftok("2021ict40", 40);
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    printf("Sender PID: %d, Parent PID: %d\n", getpid(), getppid());

    char name[50], reg[20], age[10];
    struct mesg_buffer message;

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter reg no: ");
    fgets(reg, sizeof(reg), stdin);
    printf("Enter age: ");
    fgets(age, sizeof(age), stdin);

    name[strcspn(name, "\n")] = 0;
    reg[strcspn(reg, "\n")] = 0;
    age[strcspn(age, "\n")] = 0;

    message.mesg_type = 1;
    snprintf(message.mesg_text, sizeof(message.mesg_text),
             "Enter name: %s\nEnter reg no:%s\nEnter age: %s", name, reg, age);

    if (msgsnd(msgid, &message, sizeof(message.mesg_text), 0) == -1) {
        perror("msgsnd failed");
        return 1;
    }

    printf("Message sent successfully!\n");

    return 0;
}



//


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>  // getpid, getppid

#define MAX 100

struct mesg_buffer {
    long mesg_type;
    char mesg_text[MAX];
};

int main() {
    key_t key;
    int msgid;
    struct mesg_buffer message;

    key = ftok("2021ict40", 40);
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    printf("Receiver PID: %d, Parent PID: %d\n", getpid(), getppid());

    if (msgrcv(msgid, &message, sizeof(message.mesg_text), 1, 0) == -1) {
        perror("msgrcv failed");
        return 1;
    }

    char name[50], reg[20], age[10];
    char *line = strtok(message.mesg_text, "\n");

    if (line != NULL)
        sscanf(line, "Enter name: %49[^\n]", name);
    line = strtok(NULL, "\n");

    if (line != NULL)
        sscanf(line, "Enter reg no:%19[^\n]", reg);
    line = strtok(NULL, "\n");

    if (line != NULL)
        sscanf(line, "Enter age: %9[^\n]", age);

    printf("\nMessage queue:\n");
    printf("Received name: %s\n", name);
    printf("Received reg no: %s\n", reg);
    printf("Received age: %s\n", age);

    // Optionally remove the message queue if no longer needed
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}



[samindi@DESKTOP-FSBHM1J ~]$ vi sc.c
[samindi@DESKTOP-FSBHM1J ~]$ touch samindi
[samindi@DESKTOP-FSBHM1J ~]$ chmod 644 samindi
[samindi@DESKTOP-FSBHM1J ~]$ gcc sc.c -o sc
[samindi@DESKTOP-FSBHM1J ~]$ vi scc.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc scc.c -o scc
[samindi@DESKTOP-FSBHM1J ~]$ ./sc
Sender PID: 18066, Parent PID: 9668
Enter name: sawi
Enter reg no: 40
Enter age: 25
Message sent successfully!
[samindi@DESKTOP-FSBHM1J ~]$ ./scc
Receiver PID: 18088, Parent PID: 9668

Message queue:
Received name: sawi
Received reg no: 40
Received age: 25

