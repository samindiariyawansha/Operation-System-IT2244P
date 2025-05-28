![00](https://github.com/user-attachments/assets/569ba7eb-2105-4f74-8178-e7e5870eed7e)
![CAL](https://github.com/user-attachments/assets/2311a1ae-a74f-4b99-a63b-5d9103b96de7)




---

## 🔧 Compiling & Running C Programs

To compile and run a C program:

```bash
$ vi filename.c             # Open file in vi editor
$ gcc filename.c -o outputname
$ ./outputname              # Run compiled program
```

---

## 🖨️ 1. Hello World

```c
#include <stdio.h>
int main() {
    printf("Hello World!");
    return 0;
}
```

**Output:**

```
Hello World!
```

---

## 🧮 2. Variables

```c
#include <stdio.h>
int main() {
    int age = 25;
    printf("%d", age);
    return 0;
}
```

**Output:**

```
25
```

---

## 📊 3. Assign New Value

```c
#include <stdio.h>
int main() {
    int age = 25;
    printf("%d", age);
    printf("c programming");
    age = 31;
    printf("\nNew age: %d", age);
    return 0;
}
```

**Output:**

```
25c programming
New age: 31
```

---

## ➕ 4. Assign One Variable to Another

```c
#include <stdio.h>
int main() {
    int firstNum = 25;
    int secondNum = firstNum;
    printf("First Number: %d\nSecond Number: %d", firstNum, secondNum);
    return 0;
}
```

---

## 📦 5. Multiple Declarations

```c
#include <stdio.h>
int main() {
    int a = 25, b = 10;
    printf("%d\n%d", a, b);
    return 0;
}
```

---

## 📏 6. Size of Variable

```c
#include <stdio.h>
int main() {
    int a = 10;
    printf("%d\nsize: %zu", a, sizeof(a));
    return 0;
}
```

---

## 💧 7. Double Precision

```c
#include <stdio.h>
int main() {
    double a = 10.45;
    printf("%.2lf", a);
    return 0;
}
```

---

## 🌊 8. Float Values

```c
#include <stdio.h>
int main() {
    float a = 10.4f;
    printf("%f\n%.1f", a, a);
    return 0;
}
```

---

## 🔤 9. Character Type

```c
#include <stdio.h>
int main() {
    char a = 'z';
    printf("%c\n%d", a, a);
    return 0;
}
```

---

## ⌨️ 10. User Input

```c
#include <stdio.h>
int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Age=%d", age);
    return 0;
}
```

---

## 🔠 11. Multiple Inputs (Fixed)

```c
#include <stdio.h>
int main() {
    double number;
    char alpha;
    printf("Enter Inputs: ");
    scanf("%lf %c", &number, &alpha);
    printf("Number: %.2lf\nCharacter: %c", number, alpha);
    return 0;
}
```

✅ **Fix:** `%1f` (invalid) changed to `%lf` (correct for double)

---

## 🧾 Format Specifiers Quick Guide

| Format      | Type      |
| ----------- | --------- |
| `%d` / `%i` | Integers  |
| `%f` / `%F` | Float     |
| `%lf`       | Double    |
| `%c`        | Character |
| `%s`        | String    |

---

