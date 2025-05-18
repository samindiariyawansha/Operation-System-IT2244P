//print hello world using .c extension and c language

#include<stdio.h>
int main(){
	printf("Hello World !");
return 0;
}

[samindi@DESKTOP-FSBHM1J ~]$ vi first.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc first.c -o first
[samindi@DESKTOP-FSBHM1J ~]$ ./first
Hello World!
-----------------------------------------------------------*

//variables
/*int age; //store inteager values
age=25;
int age =25;*/

#include<stdio.h>
int main(){
	int age=25;
printf("%d",age);
return 0;
}



[samindi@DESKTOP-FSBHM1J ~]$ vi second.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc second.c -o second
[samindi@DESKTOP-FSBHM1J ~]$ ./second
25

-----------------------------------------------------------*
%d /%i - inteagers
%f /%F - float
%lf    - double
%e     - char
%s     - string

-----------------------------------------------------------*
//assign a new value for same variables
#include<stdio.h>
int main(){
	int age =25;
	printf("%d",age);
	
	printf("c programming");
	
	age=31;
	printf("\nNew age:%d",age);
	return 0;
}
	
	
	
[samindi@DESKTOP-FSBHM1J ~]$ vi third.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc third.c -o third
[samindi@DESKTOP-FSBHM1J ~]$ ./third
25c programming
New age:31

-----------------------------------------------------------*
//equals numbers

#include<stdio.h>
int main(){
	int firstNum =25;
	printf("First Number:%d",firstNum);
	
	int secondNum=firstNum;
	
	printf("\nSecond Number:%d",secondNum);
	return 0;
}


[samindi@DESKTOP-FSBHM1J ~]$ vi fourth.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc fourth.c -o fourth
[samindi@DESKTOP-FSBHM1J ~]$ ./fourth
First Number:25
Second Number:25

-----------------------------------------------------------*
//declare multiple variables in single line


#include<stdio.h>
int main(){
	int a=25,b=10;
	
	printf("%d",a);
	printf("\n%d",b);
	return 0;
}

[samindi@DESKTOP-FSBHM1J ~]$ vi fifth.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc fifth.c -o fifth
[samindi@DESKTOP-FSBHM1J ~]$ ./fifth
25
10
-----------------------------------------------------------*
//Size Of variable


#include<stdio.h>
int main(){
	int a=10;
	
	printf("%d",a);
	printf("\nsize: %zu",sizeof(a));
	return 0;
}


[samindi@DESKTOP-FSBHM1J ~]$ vi sixth.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc sixth.c -o sixth
[samindi@DESKTOP-FSBHM1J ~]$ ./sixth
10
size: 4

-----------------------------------------------------------*
//double numbers


#include<stdio.h>
int main(){
	double a=10.45;
	
	printf("%lf",a);
	return 0;
}


[samindi@DESKTOP-FSBHM1J ~]$ vi seventh.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc seventh.c -o seventh
[samindi@DESKTOP-FSBHM1J ~]$ ./seventh
10.450000

-----------------------------------------------------------*


#include<stdio.h>
int main(){
	double a=10.45;
	
	printf("%.2lf",a);
	return 0;
}

[samindi@DESKTOP-FSBHM1J ~]$ vi eighth.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc eighth.c -o eighth
[samindi@DESKTOP-FSBHM1J ~]$ ./eighth
10.45


-----------------------------------------------------------*
//float

#include<stdio.h>
int main(){
	float a=10.4f;
	
	printf("%f",a);
	printf("\n%.1f",a);
	return 0;
}

samindi@DESKTOP-FSBHM1J ~]$ vi nineth.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc nineth.c -o nineth
[samindi@DESKTOP-FSBHM1J ~]$ ./nineth
10.400000
10.4

-----------------------------------------------------------*
//character

#include<stdio.h>
int main(){
	char a='z';
	
	printf("%c",a);
	printf("\n%d",a);//character  are in integer
	return 0;
}

[samindi@DESKTOP-FSBHM1J ~]$ vi tenth.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc tenth.c -o tenth
[samindi@DESKTOP-FSBHM1J ~]$ ./tenth
z
122

-----------------------------------------------------------*
//user input 

#include<stdio.h>
int main(){
	
	int age;
	printf("Enter your age:");
	printf("\n%d",age);
	scanf("%d",&age);
	
	
	printf("Age=%d",age);
	return 0;
}

[samindi@DESKTOP-FSBHM1J ~]$ vi eleventh.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc eleventh.c -o eleventh
[samindi@DESKTOP-FSBHM1J ~]$ ./eleventh
Enter your age:
8
Age=8[

-----------------------------------------------------------*

//Take multiple input together

#include<stdio.h>
int main(){
	double number;
	char alpha;
	
	printf("Enter Inputs: ");
	scanf("\n%1f %c",&number, &alpha);
	return 0;
}


[samindi@DESKTOP-FSBHM1J ~]$ vi twevelth.c
[samindi@DESKTOP-FSBHM1J ~]$ gcc twevelth.c -o twevelth
[samindi@DESKTOP-FSBHM1J ~]$ ./twevelth
Enter Inputs: 10.45


-----------------------------------------------------------*









































