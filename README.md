

**README.md**

````markdown
# System V Message Queue Example in C

This project demonstrates inter-process communication (IPC) using System V message queues in C. It includes two C programs:

- `send` program: Sends a message to the message queue.
- `receive` program: Receives the message from the queue.

## Files

- `30.c`: Contains both the sender and receiver code (separated by comments).

## Compilation

Split the `30.c` into two files: `send.c` and `receive.c`.

### Sender

```bash
gcc send.c -o send
````

### Receiver

```bash
gcc receive.c -o receive
```

## Execution

### Step 1: Run the Receiver

Start the receiver in one terminal window or process:

```bash
./receive
```

### Step 2: Run the Sender

In another terminal or process, run the sender:

```bash
./send
```

You'll be prompted to enter a message.

### Output Example

```bash
Write data: hello
Data send is: hello
```

Receiver terminal will display:

```bash
Data Received is: hello




