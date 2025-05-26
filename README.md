Q1) Multiplication Table:
Purpose: Print the multiplication table for the number 2.

Q2) Diamond Shape Pattern:
Purpose: Print a diamond-shaped pattern of stars based on user input for the number of stars.

Q3) Rectangle with Hollow:
Purpose: Print a rectangle with hollow spaces in the middle.

Q4) Fibonacci Series and Sum:
Purpose: Print the Fibonacci series up to the 10th number and calculate their sum.

Q5) Sum of Prime Numbers:
Purpose: Calculate the sum of all prime numbers between 1 and 100.# Operation-System-IT2244P

# 🐚 Shell Script Exercises

Each example includes the script, how to run it, and expected output.

---

## ✅ Q1: Multiplication Table of 2

**Script (p.sh):**

```bash
for ((i=1;i<=10;i++))
do
    echo "$i * 2 = $((i * 2))"
done
```

**Run:**

```bash
$ vi p.sh
$ chmod 777 p.sh
$ ./p.sh
```

**Output:**

```
1 * 2 = 2
2 * 2 = 4
...
10 * 2 = 20
```

---

## ✅ Q2: Diamond Pattern

**Script (q.sh):**

```bash
echo "Enter the number of stars: "
read stars

# Top Half
for ((i=1; i<=stars; i++))
do
    for ((j=i; j<stars; j++))
    do
        echo -n " "
    done
    for ((k=1; k<=((2*i-1)); k++))
    do
        echo -n "*"
    done
    echo ""
done

# Bottom Half
for ((i=stars-1; i>=1; i--))
do
    for ((j=stars; j>i; j--))
    do
        echo -n " "
    done
    for ((k=1; k<=((2*i-1)); k++))
    do
        echo -n "*"
    done
    echo ""
done
```

**Run:**

```bash
$ vi q.sh
$ chmod 777 q.sh
$ ./q.sh
```

**Example Input:**

```
Enter the number of stars:
10
```

**Example Output:**

```
         *
        ***
       *****
      *******
     *********
    ***********
   *************
  ***************
 *****************
*******************
 *****************
  ***************
   *************
    ***********
     *********
      *******
       *****
        ***
         *
```

---

## ✅ Q3: Hollow Rectangle

**Script (r.sh):**

```bash
rows=6
cols=6

for ((i=1; i<=rows; i++))
do
    for ((j=1; j<=cols; j++))
    do
        if [ $i -eq 1 ] || [ $i -eq $rows ] || [ $j -eq 1 ] || [ $j -eq $cols ]; then
            echo -n "*"
        else
            echo -n " "
        fi
    done
    echo ""
done
```

**Output:**

```
******
*    *
*    *
*    *
*    *
******
```

---

## ✅ Q4: Fibonacci Series + Sum

**Script (s.sh):**

```bash
a=0
b=1
sum=0
count=10

echo -n "Fibonacci Series: "

for ((i=0; i<count; i++))
do
    echo -n "$a "
    sum=$((sum + a))
    fn=$((a + b))
    a=$b
    b=$fn
done

echo ""
echo "Sum of the first 10 fibonacci numbers is: $sum"
```

**Output:**

```
Fibonacci Series: 0 1 1 2 3 5 8 13 21 34
Sum of the first 10 fibonacci numbers is: 88
```

---

## ✅ Q5: Sum of Prime Numbers (1–100)

**Script (t.sh):**

```bash
sum=0

is_prime() {
    num=$1
    if [ $num -le 1 ]; then
        return 1
    fi
    for ((i=2; i*i<=num; i++)); do
        if (( num % i == 0 )); then
            return 1
        fi
    done
    return 0
}

for ((n=1; n<=100; n++))
do
    if is_prime $n; then
        sum=$((sum + n))
    fi
done

echo "Sum of prime numbers between 1 and 100 is: $sum"
```

**Output:**

```
Sum of prime numbers between 1 and 100 is: 1060

