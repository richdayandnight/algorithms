# Stack Permutation
date coded: August 2016

## How to run C code

- Install gcc compiler
```
sudo apt-get install build-essential
```
- Compile the program
```
gcc -o stack stack_permutation.c
```
- Run the program  
    Method 1:  
        ```
        ./stack
        ```  
        (uses input.txt as default input file)  
    
    Method 2:
        ```
        ./stack test_input.txt
        ```  
        (uses test_input.txt as input file)

- See output text for results (output.txt)

## Directions:

- Create a program that will solve the problem below.
- The program must written in the C programming language, using only the following libraries stdio.h, stdlib.h, string.h
- The program must compile using standard Linux GCC

Create a program such that given a number n and a sequence of numbers, the program should determine if the sequence of numbers is a stack permutation of the sequence 1…n


## Sample Input:

10:3, 5, 4, 8, 9, 10, 7, 6, 2, 1

8:4, 3, 2, 6, 8, 7, 1, 5

15:1, 5, 10, 11, 9, 8, 14, 15, 13, 12, 7, 6, 4, 3, 2

END


## Sample Output

YES

NO

YES

END

 