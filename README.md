
1. **Pattern 1**:
   - **Description**: Right-angle triangle with increasing stars.
   - **Purpose**: Demonstrates printing an increasing star pattern.

2. **Pattern 2**:
   - **Description**: Inverted right-angle triangle with decreasing stars.
   - **Purpose**: Shows how to print a decreasing star pattern.

3. **Pattern 3**:
   - **Description**: Numbers repeating in each row.
   - **Purpose**: Prints a pattern with repeated numbers.

4. **Pattern 4**:
   - **Description**: Incrementing numbers in each row.
   - **Purpose**: Prints a pattern with incrementing numbers.

5. **Pattern 5**:
   - **Description**: Centered triangle of stars.
   - **Purpose**: Prints a centered star pattern with spaces.

---

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
```

---
