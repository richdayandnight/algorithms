/*
 *A program which determines if the given series of numbers is a stack permutation
 *of 1...n
 *
 *Note: The used linked stack implementation based on the reference book.
 * Data Structures: Quiwa (c) 2007
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int StackElemType;
typedef struct stacknode StackNode;

struct stacknode
{
    StackElemType INFO;
    StackNode *LINK;
};

struct stack
{
    StackNode *top;
};

typedef struct stack Stack;

void StackOverflow(void)
{
    printf("Stack overflow detected. \n");
    exit(1);
}

void StackUnderflow(void)
{
    printf("Stack underflow detected. \n");
    exit(1);
} 

void InitStack(Stack *S)
{
    S->top = NULL;
}

int isEmptyStack(Stack *S)
{
    return (S->top == NULL);
}

StackElemType PEEK(Stack *S)
{
    return S->top->INFO;
}

void PUSH(Stack *S, StackElemType x)
{
    StackNode *alpha;
    alpha = (StackNode *) malloc(sizeof(StackNode));
    if (alpha == NULL)
        StackOverflow();
    else
    {
        alpha->INFO = x;
        alpha->LINK = S->top;
        S->top = alpha;
    }
}

void POP(Stack *S, StackElemType *x)
{
    StackNode *alpha;
    if(S->top == NULL)
        StackUnderflow();
    else
    {
        alpha = S->top;
        *x = S->top->INFO;
        S->top =  S->top->LINK;
        free(alpha);
    }
}


int main()
{   
    StackElemType pop1;
    FILE *file, *output;
    file = fopen ("input.txt", "r");
    output = fopen ("output.txt", "w");
    int num, firstWrite = 0;
    while(fscanf(file, "%d:", &num) == 1)
    {
        firstWrite++;
        Stack Test;
        InitStack(&Test);
        int x=0, switchScan = 0;
        int i = 1, j = 1;
        for(i = 1;i < num; i++)
        {
            fscanf(file, "%d, ", &x);
            StackElemType popped;
            for(;j<=x; j++)
            {
                PUSH(&Test, j);
            }
            if (isEmptyStack(&Test) || PEEK(&Test) < x)
            {
                for(;j<=x; j++)
                {
                    PUSH(&Test, j);
                }
            }
            if (PEEK(&Test) == x)
            {
                POP(&Test, &popped);
                continue;
            }
            else
            {
                if (firstWrite == 1)
                    fprintf(output, "NO");
                else
                    fprintf(output, "\nNO");
                switchScan = 1;
                InitStack(&Test);
                break;
            }
        }
        if(i == num && switchScan != 1)
        {
            fscanf(file, "%d\n", &x);
            if(isEmptyStack(&Test))
            {
                PUSH(&Test, j);
            }
             if(PEEK(&Test) == x)
            {
                POP(&Test, &pop1);
                if (firstWrite == 1)
                    fprintf(output, "YES");
                else
                    fprintf(output, "\nYES");
            }
            else
            {
                if(firstWrite == 1)
                    fprintf(output, "NO");
                else
                    fprintf(output, "\nNO");
            }
        }
        else if (i == (num-1) && switchScan == 1)
        { 
            fscanf(file, "%d\n", &x);
        }
        else
        {
            for(;i<num-1;i++)
                fscanf(file, "%d, ", &x);
            fscanf(file, "%d\n", &x);
        }
    }
    fclose(file);
    fclose(output);
    return 0;
}

