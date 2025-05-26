![00](https://github.com/user-attachments/assets/569ba7eb-2105-4f74-8178-e7e5870eed7e)
![CAL](https://github.com/user-attachments/assets/2311a1ae-a74f-4b99-a63b-5d9103b96de7)



🔧 Compiling & Running C Programs
To compile a C file using gcc and run the output:

bash
Copy
Edit
$ vi filename.c      # open file in vi editor
$ gcc filename.c -o outputname
$ ./outputname       # run compiled program
🖨️ 1. Hello World
c
Copy
Edit
#include <stdio.h>
int main() {
    printf("Hello World !");
    return 0;
}
Output:

nginx
Copy
Edit
Hello World!
🧮 2. Variables
c
Copy
Edit
#include <stdio.h>
int main() {
    int age = 25;
    printf("%d", age);
    return 0;
}
Output:

Copy
Edit
25
📊 3. Assign New Value
c
Copy
Edit
#include <stdio.h>
int main() {
    int age = 25;
    printf("%d", age);
    printf("c programming");
    age = 31;
    printf("\nNew age: %d", age);
    return 0;
}
Output:

r
Copy
Edit
25c programming
New age:31
➕ 4. Assign One Variable to Another
c
Copy
Edit
#include <stdio.h>
int main() {
    int firstNum = 25;
    int secondNum = firstNum;
    printf("First Number: %d\nSecond Number: %d", firstNum, secondNum);
    return 0;
}
📦 5. Multiple Declarations
c
Copy
Edit
#include <stdio.h>
int main() {
    int a = 25, b = 10;
    printf("%d\n%d", a, b);
    return 0;
}
📏 6. Size of Variable
c
Copy
Edit
#include <stdio.h>
int main() {
    int a = 10;
    printf("%d\nsize: %zu", a, sizeof(a));
    return 0;
}
💧 7. Double Precision
c
Copy
Edit
#include <stdio.h>
int main() {
    double a = 10.45;
    printf("%.2lf", a);  // formatted output
    return 0;
}
🌊 8. Float Values
c
Copy
Edit
#include <stdio.h>
int main() {
    float a = 10.4f;
    printf("%f\n%.1f", a, a);
    return 0;
}
🔤 9. Character Type
c
Copy
Edit
#include <stdio.h>
int main() {
    char a = 'z';
    printf("%c\n%d", a, a);  // shows ASCII value
    return 0;
}
⌨️ 10. User Input
c
Copy
Edit
#include <stdio.h>
int main() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Age=%d", age);
    return 0;
}
🔠 11. Multiple Inputs (❗Contains Bug)
c
Copy
Edit
#include <stdio.h>
int main() {
    double number;
    char alpha;
    printf("Enter Inputs: ");
    scanf("%lf %c", &number, &alpha);  // corrected format specifier from `%1f` to `%lf`
    printf("Number: %.2lf\nCharacter: %c", number, alpha);
    return 0;
}
✅ Fix applied: %1f was incorrect. Use %lf for double.

🧾 Format Specifiers Quick Guide
Format	Type
%d / %i	Integers
%f / %F	Float
%lf	Double
%c	Character
%s	String
