

### 📌 Overview

This project demonstrates **Inter-Process Communication (IPC)** techniques in C through the following mechanisms:

1. **System V Shared Memory**
2. **POSIX Shared Memory (`mmap`)**
3. **Pipes** (Unidirectional and Bidirectional)
4. **System V Message Queues**

---

### 📁 Files

| File       | Description                                                                 |
| ---------- | --------------------------------------------------------------------------- |
| `write.c`  | Writer using System V Shared Memory                                         |
| `read.c`   | Reader using System V Shared Memory                                         |
| `p.c`      | Parent-child using POSIX `mmap` shared memory                               |
| `pipe.c`   | One-way pipe: parent writes messages, child reads                           |
| `pipeex.c` | Two-way pipe: parent sends shape type, child computes area and responds     |
| `send.c`   | Parent process: sends name, reg no, and age using a message queue           |
| `reads.c`  | Child process: receives and prints name, reg no, and age from message queue |

---

### 🛠️ Compilation

Use `gcc` to compile each file:

```bash
gcc write.c -o write
gcc read.c -o read
gcc p.c -o p
gcc pipe.c -o pipe
gcc pipeex.c -o pipeex
gcc send.c -o send
gcc reads.c -o reads
```

---

### ▶️ How to Run

#### 1. **System V Shared Memory**

```bash
touch shmfile           # Needed for ftok
./write
./read
```

#### 2. **POSIX mmap Shared Memory**

```bash
./p
```

Expected Output:

```
Child wrote: Hello from child
parent read: Hello from child
```

#### 3. **Unidirectional Pipe**

```bash
./pipe
```

Output:

```
hello world #1
hello world #2
hello world #3
Finished reading
```

#### 4. **Two-Way Pipe (Shape Area Calculation)**

```bash
./pipeex
```

Sample Input/Output:

```
Enter shape type (C-circle, T-triangle, S-square, R-rectangle): C
Enter the radius: 5
Calculated Area: 78.50
```

#### 5. **System V Message Queue**

**Sender:**

```bash
./send
```

```
Enter name: sawi
Enter reg no: 3214
Enter age: 25
Message send Successfully!
```

**Receiver:**

```bash
./reads
```

```
Message queue:
Received name: sawi
Received reg no: 3214
Received age: 25
```


### 📌 Overview

This program demonstrates **Inter-Process Communication (IPC)** using **System V Message Queues**, including process ID tracking to help identify the sending and receiving processes.

---

### 📂 Files

| File    | Description                                      |
| ------- | ------------------------------------------------ |
| `sc.c`  | Sender process: collects user data and sends it  |
| `scc.c` | Receiver process: receives and displays the data |

---

### 🔧 Compilation

```bash
gcc sc.c -o sc
gcc scc.c -o scc
```

Make sure the file used in `ftok()` exists:

```bash
touch 2021ict40
chmod 644 2021ict40
```

---

### ▶️ Execution

1. **Run the Sender first**:

   ```bash
   ./sc
   ```

   Example Output:

   ```
   Sender PID: 18066, Parent PID: 9668
   Enter name: sawi
   Enter reg no: 40
   Enter age: 25
   Message sent successfully!
   ```

2. **Then run the Receiver**:

   ```bash
   ./scc
   ```

   Example Output:

   ```
   Receiver PID: 18088, Parent PID: 9668

   Message queue:
   Received name: sawi
   Received reg no: 40
   Received age: 25
   ```

---

### 💡 Key Features

* Uses `ftok()` to generate a unique key from an existing file.
* Demonstrates `msgsnd()` and `msgrcv()` for message transfer.
* Includes `getpid()` and `getppid()` to show which process is running.
* Uses `msgctl(..., IPC_RMID, ...)` in the receiver to clean up the message queue.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 📌 Overview

This program demonstrates **Inter-Process Communication (IPC)** using **System V Message Queues**. It passes structured data (name, registration number, and age) between a parent and child process using a `struct`.

---

### 📂 File

| File     | Description                                                             |
| -------- | ----------------------------------------------------------------------- |
| `msgq.c` | Contains both sender and receiver code in a single process via `fork()` |

---

### 🧑‍💻 How it Works

* The **parent process** collects user data (name, reg no, age) and sends it using a message queue.
* The **child process** receives this data using the same queue and prints it.
* The message queue is removed after the message is received.

---

### 🔧 Compilation & Execution

```bash
gcc msgq.c -o msgq
./msgq
```

### 🧪 Sample Run

```bash
Enter Name: sawi
Enter RegNo: 25
Enter Age: 24
Message sent successfully.
Received Name: sawi
Received RegNo: 25
Received Age: 24
```

--
