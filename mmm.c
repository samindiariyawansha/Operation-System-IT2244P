#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGSIZE 16
char*msg1 = "hello , world #1";
char*msg2 = "hello , world #2";
char*msg3 = "hello , world #3";


int main()
{
	char inbuf[MSGSIZE]; 
	int p[2], i;
	
	if(pipe(p) < 0)
		exit(1);
	
	//continued
	// write pipe
	
	write(p[1], msg1 ,MSGSIZE); //write (fields, message, messagesize)
	write(p[1], msg2 ,MSGSIZE);
	write(p[1], msg3 ,MSGSIZE);
	
	
	for(i=0; i<3; i++){
		//read pipe
		read(p[0], inbuf,MSGSIZE); //read(filedes
		printf("%s\n",inbuf);
	}
	return 0;
}
----------------------------


[samindi@DESKTOP-FSBHM1J ~]$ vi last.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc last.c -o last
[samindi@DESKTOP-FSBHM1J ~]$ ./last
hello , world #1
hello , world #2
hello , world #3

*********************************************************************
/*
Exercise

1. read two input from user( parent process)

name
reg no: 
age:

2. print the output from the child (child process)

name: abc
reg no: 2021/ICT/01
age:25
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MSGSIZE 99

int main() {
    char inbuf[MSGSIZE];
    int p[2], i;
    pid_t pid;

    if (pipe(p) < 0) {
        perror("Pipe creation failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) { // Parent process
        close(p[0]); // Close read end

        char name[30], reg_no[20], age[5];

        printf("Enter name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0; // Remove newline

        printf("Enter registration number: ");
        fgets(reg_no, sizeof(reg_no), stdin);
        reg_no[strcspn(reg_no, "\n")] = 0; // Remove newline

        printf("Enter age: ");
        fgets(age, sizeof(age), stdin);
        age[strcspn(age, "\n")] = 0; // Remove newline

        // Format message
        snprintf(inbuf, sizeof(inbuf), "Name: %s\nReg No: %s\nAge: %s", name, reg_no, age);

        write(p[1], inbuf, MSGSIZE);
        close(p[1]); // Close write end
    } else { // Child process
        close(p[1]); // Close write end
        read(p[0], inbuf, MSGSIZE);
        printf("\n--- Child Process Output ---\n%s\n", inbuf);
        close(p[0]); // Close read end
    }

    return 0;
}


[samindi@DESKTOP-FSBHM1J ~]$ vi last2.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc last2.c -o last2
[samindi@DESKTOP-FSBHM1J ~]$ ./last2
Enter name: sawi
Enter registration number: 40
Enter age: 25

--- Child Process Output ---
Name: sawi
Reg No: 40
Age: 25
[samindi@DESKTOP-FSBHM1J ~]$




