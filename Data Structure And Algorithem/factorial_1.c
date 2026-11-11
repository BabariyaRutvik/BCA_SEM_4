/*
1. Write a Program to find the Factorial of a given number using Recursive function.

Explanation:
- Factorial of n (n!) is defined recursively as n * factorial(n - 1) with base case
  0! = 1 and 1! = 1.
- Negative numbers do not have a factorial; the program checks for n < 0 first.
*/

int factorial(int n){
	if(n == 0 || n== 1){
		return 1;
	}
	else{
		return n * factorial(n - 1);
	}
}
#include<stdio.h>
int main(){
	int num, result;
	
	printf("Enter a Number: ");
	scanf("%d", &num);
	
	if( num < 0){
		printf("Factorial is not defined for nagative numbers");
	}
	else{
		result = factorial(num);
		printf("Fsctorial of %d is %d", num, result);
	}
	return 0;
}

/*
Sample Input:
5

Sample Output:
Enter a Number: Fsctorial of 5 is 120
*/
