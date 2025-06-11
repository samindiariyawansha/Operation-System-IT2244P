

![Screenshot (134)](https://github.com/user-attachments/assets/f4548031-e8d0-446e-86c5-c2edb0257b53)




### 📌 Overview

This project demonstrates **Inter-Process Communication (IPC)** in C using **Shared Memory**. Two different methods are shown:

1. **System V Shared Memory** (`shmget`, `shmat`, etc.)
2. **POSIX Shared Memory using `mmap` with `fork()`**

Each example consists of simple writer/reader or parent/child communication using shared memory.

---

### 📁 Files

| File      | Description                                         |
| --------- | --------------------------------------------------- |
| `write.c` | Writer process using System V shared memory         |
| `read.c`  | Reader process using System V shared memory         |
| `p.c`     | Parent-child IPC using `mmap` (POSIX shared memory) |

---

### 🛠️ Compilation

Use `gcc` to compile each file:

```bash
gcc write.c -o write
gcc read.c -o read
gcc p.c -o p
```

---

### ▶️ How to Run

#### 1. **System V Shared Memory Example**

In **two separate terminals** or sequentially:

```bash
./write
# (Enter input when prompted, e.g., "Hello from writer")

./read
# (Output: Data read from memory: Hello from writer)
```

> The shared memory segment is removed after reading.

#### 2. **POSIX `mmap` Example with `fork()`**

```bash
./p
```

Output:

```
Child wrote: Hello from child
parent read: Hello from child
```

---

### 🧠 Concepts Demonstrated

* `ftok()`, `shmget()`, `shmat()`, `shmdt()`, `shmctl()`
* `mmap()` with `MAP_SHARED | MAP_ANONYMOUS`
* Process creation using `fork()`
* Memory sharing between processes
* Proper memory cleanup

---

### 📌 Notes

* The file `"shmfile"` (used in `ftok()`) must exist. You can create it using:

  ```bash
  touch shmfile
  ```
* The size of shared memory is set to 1024 bytes for demonstration.

