
![Screenshot (101)](https://github.com/user-attachments/assets/1a384125-92c3-42f8-9cd5-a1fbacf246cd)
![Screenshot (98)](https://github.com/user-attachments/assets/c85a6bb9-43de-48c4-87ca-51dc9f7b6ada)


1. multi_fork.c
This program contains multiple calls to fork():

c
Copy code
fork();
fork();
fork();
fork();
fork();
Purpose: Demonstrates exponential process creation. With 5 forks, up to 2⁵ = 32 processes may be created.

Output: Each process prints "Hello World".

2. parent_child_info.c
This program uses a single fork() and identifies whether it's in the parent or child process.

Output:

The parent prints its process ID.

The child prints its process ID and its parent’s process ID.

Example:

less
Copy code
I am a parent process.
My ID: 161

I am a child process.
My ID: 162
My Parent ID: 161
3. sum_child_parent.c
This program demonstrates dividing tasks between parent and child:

Child process prints numbers 1 to 5 and calculates their sum.

Parent process prints numbers 6 to 10 and calculates their sum.

Example Output:

bash
Copy code
6 7 8 9 10
Parent sum: 40
Total sum: 55
1 2 3 4 5
Child sum: 5
Note: Child and parent process outputs may interleave due to concurrent execution.
