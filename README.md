
![Screenshot (109)](https://github.com/user-attachments/assets/bbeed361-a7f3-4367-82ff-171ce1401480)



---

### ✅ **Key Concepts Practiced:**

| Concept                         | Description                                                            |
| ------------------------------- | ---------------------------------------------------------------------- |
| `fork()`                        | Used to create a new process (child).                                  |
| `sleep()`                       | Suspends execution for a specified time.                               |
| `exit(status)`                  | Terminates a process with a return status.                             |
| `wait()` / `waitpid()`          | Waits for child process(es) to finish and retrieves their exit status. |
| `WIFEXITED()` / `WEXITSTATUS()` | Macros to interpret the child process's exit status.                   |

---

### 🔁 **Exercise Highlights:**

1. **Basic Sleep and Exit**
   ✅ Demonstrated how `sleep()` and `exit(0)` behave in a simple program.

2. **Parent & Single Child**
   ✅ Forks a child, parent waits, and confirms child's exit status.

3. **Parent & Two Children**
   ✅ Two child processes sleep different durations. Parent waits for both and shows correct order of completion.

4. **Child Exit Order Detection**
   ✅ Captured which child exited **first and second** using `waitpid(-1,...)`.

5. **Grandchild Process**
   ✅ Child forks its own child (grandchild). Demonstrated **multi-level process hierarchy**, with status communication up to parent.

---

### 💡 Suggestions for Further Learning:

* **Orphan and Zombie Processes**
  Try creating a child that doesn’t `wait()` for its own child (grandchild), and observe how it becomes a **zombie** briefly.

* **Using `ps` or `top`**
  Monitor processes live in terminal while running programs.

* **Handling Signals**
  Learn about `signal()`, `kill()`, and how to handle interruptions like `Ctrl+C`.

* **Process Pipes and `exec()`**
  Replace a child process’s image with a new program (`exec*()` family), and learn inter-process communication (pipes).





