//Check the sleeping and exit method


#include <stdio.h>
#include <stdlib.h> //for exit()
#include <unistd.h> //for sleep()

int main(){
	printf("Program started\n");
	
	printf("Sleeping for 3 seconds.....\n");
	sleep(3); //pause for 3 seconds
	
	printf("Exiting the proram\n");
	exit(0); //clean exit
	
}
[samindi@DESKTOP-FSBHM1J ~]$ vi sa.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc sa.c -o sa
[samindi@DESKTOP-FSBHM1J ~]$ ./sa
Program started
Sleeping for 3 seconds.....
Exiting the proram
--------------------------------------------------------------------------------



#include <stdio.h>
#include <stdlib.h> //for exit()
#include <unistd.h> //for sleep()
#include <sys/wait.h> //for wait()


int main(){
	pid_t pid;
	
	printf("Parent process started.PID: %d\n",getpid());
	
	pid =fork(); //create a new child process
	
	if(pid<0){
		perror("fork failed");
		exit(1);
	}
	
	if(pid == 0)
	{
		//child process
	printf("child process .PID: %d, Sleeping for 2 seconds...\n",getpid());
	sleep(2); //pause for 2 seconds
	
	printf("Child process exiting\n");
	exit(0); //clean exit
	}
	else
	{
		//parent process
		int status;
		printf("parent waiting for child to finish...\n");
		wait(&status); //wait for child to finish
		
		if(WIFEXITED(status))//WIFEXITED(Status) returns true if child terminated normally
		{
			printf("Child exited with status: %d\n", WEXITSTATUS(status));
			//WEXITSTATUS get the actual exit code (0 here).
		}
		else
		{
			printf("Child did not exit normally.\n");
		}
		printf("Parent process ending\n");
	}
		
	return 0;
}


[samindi@DESKTOP-FSBHM1J ~]$ vi ss.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc ss.c -o ss
[samindi@DESKTOP-FSBHM1J ~]$ ./ss
Parent process started.PID: 55
parent waiting for child to finish...
child process .PID: 56, Sleeping for 2 seconds...
Child process exiting
Child exited with status: 0
Parent process ending

-----------------------------------------------------------------------------------------------

Exercise:

First child: Slept for 1 seconds
Second Child : Slept for three seconds'
Parent : both children have finished

----------------------
#include <stdio.h>
#include <stdlib.h>   // For exit()
#include <unistd.h>   // For sleep(), fork()
#include <sys/wait.h> // For wait()

int main() {
    pid_t pid1, pid2;

    printf("Parent process started. PID: %d\n", getpid());

    pid1 = fork(); // Create first child process
    if (pid1 < 0) {
        perror("First fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        // First child process
        printf("First child process (PID: %d), Sleeping for 1 second...\n", getpid());
        sleep(1);
        printf("First child process exiting.\n");
        exit(0);
    }

    pid2 = fork(); // Create second child process
    if (pid2 < 0) {
        perror("Second fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        // Second child process
        printf("Second child process (PID: %d), Sleeping for 3 seconds...\n", getpid());
        sleep(3);
        printf("Second child process exiting.\n");
        exit(0);
    }

    // Parent process
    printf("Parent waiting for both children to finish...\n");

    int status;
    waitpid(pid1, &status, 0); // Wait for the first child
    if (WIFEXITED(status)) {
        printf("First child exited with status: %d\n", WEXITSTATUS(status));
    }

    waitpid(pid2, &status, 0); // Wait for the second child
    if (WIFEXITED(status)) {
        printf("Second child exited with status: %d\n", WEXITSTATUS(status));
    }

    printf("Both children have finished. Parent process ending.\n");

    return 0;
}

[samindi@DESKTOP-FSBHM1J ~]$ vi sd.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc sd.c -o sd
[samindi@DESKTOP-FSBHM1J ~]$ ./sd
Parent process started. PID: 63
First child process (PID: 64), Sleeping for 1 second...
Parent waiting for both children to finish...
Second child process (PID: 65), Sleeping for 3 seconds...
First child process exiting.
First child exited with status: 0
Second child process exiting.
Second child exited with status: 0
Both children have finished. Parent process ending.

-----------------------------------------------------------------------------------------------

Exercise 02: 
First child: sleeps for 2 seconds, exit with status 2.
Second child: sleeps for 1 second, exit with status 1.
Parent : waits twice , and prints which child (by PID or exit code)
 finished first and second
 
 
 
 
#include <stdio.h>
#include <stdlib.h>   // For exit()
#include <unistd.h>   // For sleep(), fork()
#include <sys/wait.h> // For waitpid()

int main() {
    pid_t pid1, pid2;
    int status;

    printf("Parent process started. PID: %d\n", getpid());

    // Create first child process
    pid1 = fork();
    if (pid1 < 0) {
        perror("First fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        // First child
        printf("First child process (PID: %d), Sleeping for 2 seconds...\n", getpid());
        sleep(2);
        printf("First child process exiting with status 2.\n");
        exit(2);
    }

    // Create second child process
    pid2 = fork();
    if (pid2 < 0) {
        perror("Second fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        // Second child
        printf("Second child process (PID: %d), Sleeping for 1 second...\n", getpid());
        sleep(1);
        printf("Second child process exiting with status 1.\n");
        exit(1);
    }
    // Parent process waits twice
    pid_t first_finished = waitpid(-1, &status, 0);
    printf("Child with PID %d finished first with exit status: %d\n", first_finished, WEXITSTATUS(status));

    pid_t second_finished = waitpid(-1, &status, 0);
    printf("Child with PID %d finished second with exit status: %d\n", second_finished, WEXITSTATUS(status));

    printf("Both children have finished. Parent process ending.\n");

    return 0;
}



[samindi@DESKTOP-FSBHM1J ~]$ vi sg.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc sg.c -o sg
[samindi@DESKTOP-FSBHM1J ~]$ ./sg
Parent process started. PID: 72
First child process (PID: 73), Sleeping for 2 seconds...
Second child process (PID: 74), Sleeping for 1 second...
Second child process exiting with status 1.
Child with PID 74 finished first with exit status: 1
First child process exiting with status 2.
Child with PID 73 finished second with exit status: 2
Both children have finished. Parent process ending.


---------------------------------------------------------------------------------------------------------------

Exercise 03:
The parent creates a child  process.
The child creates a grandchild process.
The grandchild sleeps 2 seconds and exits with status 2.
The child waits for the grandchild, prints its exit status,
then exits with status 55.



#include <stdio.h>
#include <stdlib.h>   // For exit()
#include <unistd.h>   // For sleep(), fork()
#include <sys/wait.h> // For waitpid()

int main() {
    pid_t child_pid, grandchild_pid;
    int status;

    printf("Parent process started. PID: %d\n", getpid());

    // Parent creates a child process
    child_pid = fork();
    if (child_pid < 0) {
        perror("Fork failed for child");
        exit(1);
    }

    if (child_pid == 0) { 
        // Child process
        printf("Child process started. PID: %d\n", getpid());

        // Child creates grandchild process
        grandchild_pid = fork();
        if (grandchild_pid < 0) {
            perror("Fork failed for grandchild");
            exit(1);
        }

        if (grandchild_pid == 0) {
            // Grandchild process
            printf("Grandchild process started. PID: %d, Sleeping for 2 seconds...\n", getpid());
            sleep(2);
            printf("Grandchild exiting with status 2.\n");
            exit(2);
        }

        // Child process waits for grandchild
        waitpid(grandchild_pid, &status, 0);
        printf("Child detected grandchild exited with status: %d\n", WEXITSTATUS(status));
        
        // Child process exits with status 55
        printf("Child exiting with status 55.\n");
        exit(55);
    }

    // Parent process waits for child
    waitpid(child_pid, &status, 0);
    printf("Parent detected child exited with status: %d\n", WEXITSTATUS(status));

    printf("Parent process ending.\n");
    return 0;
}
[samindi@DESKTOP-FSBHM1J ~]$ vi sh.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc sh.c -o sh
[samindi@DESKTOP-FSBHM1J ~]$ ./sh
Parent process started. PID: 81
Child process started. PID: 82
Grandchild process started. PID: 83, Sleeping for 2 seconds...
Grandchild exiting with status 2.
Child detected grandchild exited with status: 2
Child exiting with status 55.
Parent detected child exited with status: 55
Parent process ending.
[samindi@DESKTOP-FSBHM1J ~]$

---------------------------------------------------------------------------------------------------------------


