

#include <stdio.h>

int main() {
    double num1, num2, result;
    char op;
    
    printf("Enter an expression (e.g., 5 + 3): ");
    scanf("%lf %c %lf", &num1, &op, &num2);

    result = (op == '+') ? num1 + num2 :
             (op == '-') ? num1 - num2 :
             (op == '*') ? num1 * num2 :
             (op == '/') ? (num2 != 0 ? num1 / num2 : 0) : 0;

    if (op == '/' && num2 == 0)
        printf("Error: Division by zero!\n");
    else
        printf("Result: %.2lf\n", result);

    return 0;
}

ANSWERS: 

[samindi@DESKTOP-FSBHM1J ~]$ vi aaaaa.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc aaaaa.c -o aaaaa
[samindi@DESKTOP-FSBHM1J ~]$ ./aaaaa
Enter an expression (e.g., 5 + 3): 6+7
Result: 13.00
