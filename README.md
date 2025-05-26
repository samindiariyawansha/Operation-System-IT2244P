Q1) Life Path Number and Astrology Insight
Description: Calculates the life path number based on the user's birth date and provides an astrology insight.

Purpose: To provide a life path number and an associated astrological insight.

Q2) Summation and Multiplication of Numbers
Description: Takes a list of numbers, calculates the summation and multiplication using a for loop.

Purpose: To calculate the sum and product of a list of numbers.

Q3) Print Integers from 1 to 10
Description: Prints integers from 1 to 10 using a while loop.

Purpose: To display integers from 1 to 10 sequentially.# Operation-System-IT2244P


## 🧙‍♂️ **Q1: Astrology Based on Life Path Number (Using `case`)**

### 💡 Description:

This script calculates a "life path number" based on the day of birth (DD format). Then it uses a `case` statement to provide a short astrology insight based on that number.

### ▶️ Example Output:

```bash
Enter your date of birth (DD):
29
Your Life Path Number is: 2
Astrology Insight: Carefully do your work
```

---

## ➕ **Q2: Summation and Multiplication of List of Numbers**

### 💡 Description:

Takes a list of numbers from the user and calculates both the total sum and the product using a `for` loop.

### ✅ **Code:**

```bash
#!/bin/bash

echo "Enter a list of numbers separated by spaces:"
read -a numbers

sum=0
mul=1

for num in "${numbers[@]}"
do
    sum=$((sum + num))
    mul=$((mul * num))
done

echo "Summation = $sum"
echo "Multiplication = $mul"
```

### ▶️ Example Output:

```bash
Enter a list of numbers separated by spaces:
1 2 3 4 5
Summation = 15
Multiplication = 120
```

---

## 🔁 **Q3: Print Integers from 1 to 10 Using While Loop**

### 💡 Description:

A simple loop to print numbers from 1 through 10.

### ✅ **Code:**

```bash
#!/bin/bash

i=1
while [ $i -le 10 ]
do
    echo $i
    i=$((i + 1))
done
```

### ▶️ Output:

```
1
2
3
4
5
6
7
8
9
10


