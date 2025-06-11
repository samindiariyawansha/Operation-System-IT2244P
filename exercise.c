#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define MSGSIZE 16
char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(){
	char inbuf[MSGSIZE];
	int p[2],pid,nbytes;
	
	if(pipe(p)<0)
		exit(1);
	
	if((pid=fork())>0){
		write(p[1],msg1,MSGSIZE); 
		write(p[1],msg2,MSGSIZE);
		write(p[1],msg3,MSGSIZE);
		
		wait(NULL);
	
	}
	else{
		while ((nbytes = read(p[0], inbuf, MSGSIZE))>0)
			printf("%s\n",inbuf);
		if(nbytes != 0)
			exit(2);
		printf("Finished reading\n");
	}
	return 0;
}


[samindi@DESKTOP-FSBHM1J ~]$ vi pipe.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc pipe.c -o pipe
[samindi@DESKTOP-FSBHM1J ~]$ ./pipe
hello world #1
hello world #2
hello world #3
----------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe1[2]; // Parent to Child
    int pipe2[2]; // Child to Parent

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child Process
        close(pipe1[1]); // Close write end of pipe1
        close(pipe2[0]); // Close read end of pipe2

        char S;
        float a, b, r, h, l, n, result;

        // Read input from parent
        read(pipe1[0], &S, sizeof(char));

        // Compute area based on shape type
        switch (S) {
            case 'T':
                printf("Enter the base: ");
                scanf("%f", &a);
                printf("Enter the height: ");
                scanf("%f", &b);
                result = 0.5 * a * b;
                break;
            case 'C':
                printf("Enter the radius: ");
                scanf("%f", &r);
                result = 3.14 * r * r;
                break;
            case 'S':
                printf("Enter the side length: ");
                scanf("%f", &h);
                result = h * h;
                break;
            case 'R':
                printf("Enter the length: ");
                scanf("%f", &l);
                printf("Enter the width: ");
                scanf("%f", &n);
                result = l * n;
                break;
            default: result = 0;
        }

        // Send result to parent
        write(pipe2[1], &result, sizeof(float));

        close(pipe1[0]);
        close(pipe2[1]);
    }
    else {
        // Parent Process
        close(pipe1[0]); // Close read end of pipe1
        close(pipe2[1]); // Close write end of pipe2

        char S;
        float result;

        // Get input from user
        printf("Enter shape type (C-circle, T-triangle, S-square, R-rectangle):");
        scanf(" %c", &S);  // Space before %c to avoid newline issues

        // Send shape type to child
        write(pipe1[1], &S, sizeof(char));

        // Read result from child
        read(pipe2[0], &result, sizeof(float));

        printf("Calculated Area: %0.2f\n", result);

        close(pipe1[1]);
        close(pipe2[0]);
    }

    return 0;
}

[samindi@DESKTOP-FSBHM1J ~]$ vi pipeex.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc pipeex.c -o pipeex
[samindi@DESKTOP-FSBHM1J ~]$ ./pipeex
Enter shape type (C-circle, T-triangle, S-square, R-rectangle):S
Enter the side length: 5
Calculated Area: 25.00
[samindi@DESKTOP-FSBHM1J ~]$ ./pipeex
Enter shape type (C-circle, T-triangle, S-square, R-rectangle):C
Enter the radius: 7
Calculated Area: 153.86
[samindi@DESKTOP-FSBHM1J ~]$