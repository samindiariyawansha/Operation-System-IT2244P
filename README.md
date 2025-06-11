
![Screenshot (136)](https://github.com/user-attachments/assets/f145cd34-788b-4443-b32f-37aa78bcbcf7)



### 📌 Overview

This project demonstrates three different **Inter-Process Communication (IPC)** techniques in C:

1. **System V Shared Memory**
2. **POSIX Shared Memory (`mmap`)**
3. **Pipes**

   * One-way pipe (unidirectional)
   * Two-way pipe (bidirectional communication using two pipes)

---

### 📁 Files

| File       | Description                                                             |
| ---------- | ----------------------------------------------------------------------- |
| `write.c`  | Writer program using System V shared memory (`shmget`, `shmat`)         |
| `read.c`   | Reader program that reads from shared memory and deletes it             |
| `p.c`      | Parent-child communication using `mmap` shared memory                   |
| `pipe.c`   | Simple unidirectional pipe where the parent writes and child reads      |
| `pipeex.c` | Bidirectional communication using two pipes to calculate area of shapes |

---

### 🛠️ Compilation

Use `gcc` to compile each source file:

```bash
gcc write.c -o write
gcc read.c -o read
gcc p.c -o p
gcc pipe.c -o pipe
gcc pipeex.c -o pipeex
```

---

### ▶️ How to Run

#### 1. **System V Shared Memory**

```bash
touch shmfile       # Required to generate a unique key
./write             # Enter a message when prompted
./read              # Reads and displays the message
```

#### 2. **POSIX `mmap` Shared Memory**

```bash
./p
```

Expected Output:

```
Child wrote: Hello from child
parent read: Hello from child
```

#### 3. **Unidirectional Pipe (`pipe.c`)**

```bash
./pipe
```

Expected Output:

```
hello world #1
hello world #2
hello world #3
Finished reading
```

#### 4. **Bidirectional Pipe Example (`pipeex.c`)**

```bash
./pipeex
```

Example Interaction:

```
Enter shape type (C-circle, T-triangle, S-square, R-rectangle): C
Enter the radius: 5
Calculated Area: 78.50
```






