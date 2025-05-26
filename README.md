Q1) Fibonacci Numbers:
Purpose: Generate the first 10 Fibonacci numbers using a loop.

Q2) Factorial:
Purpose: Calculate the factorial of a number using a loop.

Q3) Multiples of 3:
Purpose: Print multiples of 3 between 1 and 50 using a while loop.# Operation-System-IT2244P



# 📘 Shell Script Exercises: Fibonacci, Factorial, Multiples

## ✅ (Q1) Fibonacci Numbers (First 10 Terms)

### 📜 Script: `m.sh`

```bash
#!/bin/bash

a=0
b=1
echo -n "$a $b "
for (( i=2; i<10; i++))
do
    fib=$((a + b))
    echo -n "$fib "
    a=$b
    b=$fib
done
```

### ▶️ Run:

```bash
$ chmod 777 m.sh
$ ./m.sh
```

### ✅ Output:

```
0 1 1 2 3 5 8 13 21 34
```

---

## ✅ (Q2) Factorial of a Number

### 📜 Script: `n.sh`

```bash
#!/bin/bash

fact=1
num=5
for (( i=1; i<=num; i++))
do
    fact=$((fact * i))
done
echo "Factorial $num = $fact"
```

### ▶️ Run:

```bash
$ vi n.sh
$ chmod 777 n.sh
$ ./n.sh
```

### ✅ Output:

```
Factorial 5 = 120
```

---

## ✅ (Q3) Multiples of 3 Between 1 and 50

### 📜 Script: `o.sh`

```bash
#!/bin/bash

i=3
while [ $i -le 50 ]
do
    echo $i
    i=$((i + 3))
done
```

### ▶️ Run:

```bash
$ vi o.sh
$ chmod 777 o.sh
$ ./o.sh
```

### ✅ Output:

```
3
6
9
12
15
18
21
24
27
30
33
36
39
42
45
48


