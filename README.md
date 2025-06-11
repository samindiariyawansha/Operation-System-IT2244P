![Screenshot (138)](https://github.com/user-attachments/assets/c418061c-457b-42bf-b533-ac855ff5827f)

 **Pipe (`last2.c`)**

* Uses **unnamed pipes** for **unidirectional communication** between parent and child.
* The **parent writes** a formatted string to the pipe.
* The **child reads** and displays it.
* The message is temporarily stored in a character buffer (`char inbuf[]`).

---

## 🧠 Key Differences

| Feature           | Message Queue (`msgq.c`)            | Pipe (`last2.c`)                    |
| ----------------- | ----------------------------------- | ----------------------------------- |
| Direction         | Bi-directional (if implemented)     | One-way (Parent → Child)            |
| Structure Support | Structured messages via `struct`    | Only raw byte streams (strings)     |
| Persistence       | Can persist beyond process lifetime | Temporary (gone after program ends) |
| Identification    | Identified by a key (`ftok`)        | Uses file descriptors (`pipe()`)    |
| Suitable For      | Complex/multi-process messaging     | Simple parent-child communication   |

---

## 🧾 Output Recap

### ✅ Message Queue Output:

```
Enter Name: sawi
Enter RegNo: 25
Enter Age: 24
Message sent successfully.
Received Name: sawi
Received RegNo: 25
Received Age: 24
```

### ✅ Pipe Output:

```
Enter name: sawi
Enter registration number: 40
Enter age: 25

--- Child Process Output ---
Name: sawi
Reg No: 40
Age: 25




