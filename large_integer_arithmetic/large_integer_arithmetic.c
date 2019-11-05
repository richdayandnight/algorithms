#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int QueueElemType;  //Quiwa queue implementation
typedef struct queuenode QueueNode;

typedef int doublyListElemType;      // if int list
typedef struct doublynode DoublyNode;

struct doublynode
{
    doublyListElemType INFO;
    DoublyNode *rLINK;
    DoublyNode *lLINK;
};

struct doublyList
{
    DoublyNode *head;
};
typedef struct doublyList dList;

struct queuenode
{
    QueueElemType INFO;
    QueueNode *LINK;
};

struct queue
{
    QueueNode *front;
    QueueNode *rear;
};
typedef struct queue Queue;

void InitQueue(Queue *);
int IsEmptyQueue(Queue *);
void ENQUEUE(Queue *, QueueElemType);
void DEQUEUE(Queue *, QueueElemType *);
void QueueOverflow(void);
void QueueUnderflow(void);

void listOverflow(void);
void listUnderflow(void);
void initDList(dList *D);   //dList struct of doublyList
int isEmptyList(dList *D);
void insertFirst(dList *D, doublyListElemType x);
void insertTail(dList *D, doublyListElemType x);
void deleteFirst(dList *D, doublyListElemType *x);
void printList(dList *D);
void printHead(dList *D);
void addTwoLargeNumbers(dList *A, dList *B, dList *Sum);
void multiplyTwoLargeNumbers(dList *A, dList *B, dList *Prod);
void initProduct(dList *prod, int k);
int peek(dList *D);
void deleteAll(dList *D);
void deleteTail(dList *D, doublyListElemType *x);
void convertToBase10(dList *D);
void makeCopyOfList(dList *D, dList *copy);

void convertToBase27(dList *A, dList *remainder);
char *division(char dividend[],long int divisor, int *remainder1, int *j);
int compareTwoNumbers(dList *A, dList *B);
int power(int base, unsigned int exp);
int gcf(dList *A, dList *B);
void subtraction1(dList *A);
void computePhi(dList *p, dList *q, dList *phi);
void modInverse(dList *e, dList *phi, dList *modIn);
void subtraction(dList *A, dList *B, dList *difference);
void subtraction1(dList *A);

void exponentiation(dList *M, dList *e, dList *n, dList *result);
void printListMessage(dList *D);
void printToFile(FILE *fp, dList *D);

int main()
{
    FILE *fp = fopen("input.txt","r");
    FILE *output = fopen ("output.txt", "w");
    int ch=0;
    if (fp == NULL)
        return 0;
    Queue firstLetter;
    QueueElemType x; 
    InitQueue(&firstLetter); 
    ENQUEUE(&firstLetter, 'C');
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            if((ch = fgetc(fp)) != EOF)
                ENQUEUE(&firstLetter, ch);
        }
    }
    fclose(fp);

    
    fp = fopen("input.txt","r");

    int caseNum = 0;
    dList p, q, e;// M;
    initDList(&p);
    initDList(&q);
    initDList(&e);
    //initDList(&M);
    while(fscanf(fp, "CASE %d\n", &caseNum) == 1)
    //while ((ch = fgetc(fp)) != EOF)
    {
        //------------------------
        if(caseNum == 1)
            fprintf(output, "CASE %d", caseNum);
        else
            fprintf(output, "\nCASE %d", caseNum);
        deleteAll(&p);
        deleteAll(&q);
        deleteAll(&e);
        dList M;
        initDList(&M);

        //printf("CASENUM: %d", caseNum);
        int ctr =0;
        for(ctr =0; ctr< 2; ctr++)
          DEQUEUE(&firstLetter,&x); 
        //--------------------------
        //printf("\nX value: %d\n", x);
        
        while((ch = fgetc(fp)) != EOF)
        {
            if(ch == ',')
                break;
            insertTail(&p, ch-48);
        }
        //printf("\nP: ");
        //printList(&p);
        //printf("CH HERE: |%c|", ch);

        ch = fgetc(fp); // for space after comma
        //printf("CH HERE: |%c|", ch);
        while ((ch = fgetc(fp)) != EOF) //savin to q
        {
            if(ch == '\n' || ch == ' ')
            {

                break;
            }
            insertTail(&q, ch-48); 

        }
        while(ch != '\n')
        {
            ch = fgetc(fp);
        }
        while ((ch = fgetc(fp)) != EOF) //savin to e
        {

            if(ch == '\n')// || ch == ' ');
                break;
            insertTail(&e, ch-48);   
        }

        dList phi, n, d;
        initDList(&d);

        computePhi(&p, &q, &phi);

        dList tempPhi, tempE1;
        initDList(&tempPhi);
        initDList(&tempE1);
        makeCopyOfList(&phi, &tempPhi);
        makeCopyOfList(&e, &tempE1);

        int gcd = gcf(&tempPhi, &tempE1);
        if (gcd != 1)
        {
            fprintf(output, "\nInvalid encryption key");
            //printf("Case %d <><<><><>INVALID ENCRYPTION<><><>", caseNum);
        }
        else
        {
            multiplyTwoLargeNumbers(&p, &q, &n);
            modInverse(&e, &phi, &d);
        }

        while(x != 67 && x != 69)
        {
            deleteAll(&M);
            DEQUEUE(&firstLetter, &x);

            int temp = 0;
            if(x == 65) // 65 or A
            {
                //printf("\nAlice message: ");
                fscanf(fp, "Alice will send the message:%c", &temp);

                while (1)
                {
                    ch = fgetc(fp);
                    if(ch == 't')
                    {
                        break;
                    }
                    if(ch>= 97)
                        ch = ch -32;
                    else if(ch == 32)
                        ch = 26;
                    else
                        ch = ch - 65;
                    insertTail(&M, ch);

                }
                fscanf(fp, "%c Bob\n", &temp);
                deleteTail(&M, &temp);
                convertToBase10(&M);

                if(gcd == 1)
                {
                
                dList X, encrypt, tempM, tempE, tempD;
                initDList(&X);
                initDList(&encrypt);
                initDList(&tempM);
                initDList(&tempE);
                initDList(&tempD);
                makeCopyOfList(&M, &tempM);
                makeCopyOfList(&e, &tempE);
                makeCopyOfList(&d, &tempD);
                
                    exponentiation(&tempM, &tempE, &n, &encrypt);
                dList remainder27;
                initDList(&remainder27);
                convertToBase27(&encrypt, &remainder27);
                fprintf(output,"\nAlice sent: ");
                printToFile(output, &remainder27);
                }
            }
            else if(x == 66) //66 or B
            {
                fscanf(fp, "Bob received the message:%c", &temp);
                while (1)
                {
                    ch = fgetc(fp);
                    

                    if(ch == 'f')
                    {
                        break;
                    }
                    if(ch>= 97)
                        ch = ch -32;
                    else if(ch == 32)
                        ch = 26;
                    else
                        ch = ch - 65;
                    insertTail(&M, ch);
                }
                fscanf(fp, "%com Alice\n", &temp);
                deleteTail(&M, &temp);
                convertToBase10(&M);
                if(gcd ==1)
                {
                dList X, decrypt, tempM, tempE, tempD;
                initDList(&X);
                initDList(&decrypt);
                initDList(&tempM);
                initDList(&tempE);
                initDList(&tempD);
                makeCopyOfList(&M, &tempM);
                makeCopyOfList(&e, &tempE);
                makeCopyOfList(&d, &tempD);
                exponentiation(&tempM, &tempD, &n, &decrypt);
                dList remainder27;
                initDList(&remainder27);
                convertToBase27(&decrypt, &remainder27);
                fprintf(output,"\nBob received: ");
                printToFile(output, &remainder27);
                }

            }
        }

        if (x == 69) //if x == E
        {
            break;
        }
    }
    fclose(fp);
    fclose(output);


    return 0;
}

void exponentiation(dList *M, dList *e, dList *n, dList *result)
{
    insertTail(&(*result), 1);

    //m = m % number
    if(compareTwoNumbers(&(*M), &(*n)) >= 0)
    {
        do
        {
            dList tempDiff;
            initDList(&tempDiff);
            subtraction(&(*M), &(*n), &tempDiff);
            makeCopyOfList(&tempDiff, &(*M));
            //printList(&(*M));
        } while(compareTwoNumbers(&(*M), &(*n)) >= 0);
    }
    dList zero;
    initDList(&zero);
    insertTail(&zero, 0);
    int i = 0;
    while(compareTwoNumbers(&(*e), &zero) > 0) //while e > 0
    {
        //DoublyNode curr;
        //curr = e -> head;
        if(e->head->lLINK->INFO % 2 != 0)
        {
            dList tempProd;
            initDList(&tempProd);
            multiplyTwoLargeNumbers(&(*result), &(*M), &tempProd);

            while(compareTwoNumbers(&tempProd, &(*n)) >= 0)
        {
            int z = tempProd.head -> INFO - (n -> head -> INFO);
            dList mult, tempHere;
            initDList(&mult);
            insertTail(&mult,1);
            int x1 = 0;
            for(x1 =0 ;x1<z; x1++)
            {
                insertTail(&mult, 0);
            }

            if(mult.head->INFO != 0)
            {
                multiplyTwoLargeNumbers(&(*n), &mult, &tempHere);
            }
            else
            {
                initDList(&tempHere);
                makeCopyOfList(&(*n), &tempHere);

            }

            while(compareTwoNumbers(&tempProd, &tempHere) < 0)
            {

                deleteAll(&tempHere);
                char* quotient;
                char dividend[10000];
                long int divisor = 2;
                int remainderX = 0, l = 0, ctrDiv = 0;
                DoublyNode *curr;
                curr =mult.head;
                while(curr -> rLINK != mult.head)
                {
                    curr = curr -> rLINK;
                    dividend[ctrDiv++] = curr -> INFO + 48;
                }
                dividend[ctrDiv] = '\0';
                quotient = division(dividend,divisor, &remainderX, &l);
            while(*quotient)
                 if(*quotient ==48)
                     quotient++;
                 else
                     break;

                 deleteAll(&mult);
                 ctrDiv = 0;
                 while(quotient[ctrDiv++] != '\0')
                {
                    insertTail(&mult, quotient[ctrDiv-1] - 48);
                }

                 
                multiplyTwoLargeNumbers(&(*n), &mult, &tempHere);
            }
            dList tempDiff1;
            initDList(&tempDiff1);
            subtraction(&tempProd, &tempHere, &tempDiff1);
            makeCopyOfList(&tempDiff1, &tempProd);

        }
        makeCopyOfList(&tempProd, &(*result));
        }

        char *q;
        char dividend[10000];
        long int divisor = 2, ctr1 = 0;
        int remainder1 = 0, k = 0;
        DoublyNode *curr;
        curr = e -> head;
        while(curr -> rLINK != e -> head)
        {
            curr = curr -> rLINK;
            dividend[ctr1++] = curr -> INFO + 48;
        }
        dividend[ctr1] = '\0';
        q = division(dividend,divisor, &remainder1, &k);
        while(*q)
                 if(*q ==48)
                     q++;
                 else
                     break;
        ctr1 = 0;
        deleteAll(&(*e));
        while(q[ctr1++] != '\0')
        {
            insertTail(&(*e), q[ctr1-1] - 48);
        }

        dList tempProd2;
        //initDList(&tempProd2);
        multiplyTwoLargeNumbers(&(*M),&(*M), &tempProd2);

        while(compareTwoNumbers(&tempProd2, &(*n)) >= 0)
        {
            int z = tempProd2.head -> INFO - (n -> head -> INFO);
            
            dList mult, tempHere;
            initDList(&mult);
            insertTail(&mult,1);
            int x1 = 0;
            for(x1 =0 ;x1<z; x1++)
            {
                insertTail(&mult, 0);
            }

            if(mult.head->INFO != 0)
            {
                multiplyTwoLargeNumbers(&(*n), &mult, &tempHere);
            }
            else
            {
                initDList(&tempHere);
                makeCopyOfList(&(*n), &tempHere);

            }

            while(compareTwoNumbers(&tempProd2, &tempHere) < 0)
            {
                deleteAll(&tempHere);
            
                char* quotient;
                char dividend[10000];
                long int divisor = 2;
                int remainderX = 0, l = 0, ctrDiv = 0;
                DoublyNode *curr;
                curr =mult.head;
                while(curr -> rLINK != mult.head)
                {
                    curr = curr -> rLINK;
                    dividend[ctrDiv++] = curr -> INFO + 48;
                }
                dividend[ctrDiv] = '\0';
                quotient = division(dividend,divisor, &remainderX, &l);
            while(*quotient)
                 if(*quotient ==48)
                     quotient++;
                 else
                     break;

                 deleteAll(&mult);
                 ctrDiv = 0;
                 while(quotient[ctrDiv++] != '\0')
                {
                    insertTail(&mult, quotient[ctrDiv-1] - 48);
                }


                multiplyTwoLargeNumbers(&(*n), &mult, &tempHere);
            }
           
            dList tempDiff3;
            initDList(&tempDiff3);
            subtraction(&tempProd2, &tempHere, &tempDiff3);
            makeCopyOfList(&tempDiff3, &tempProd2);

           
        }
          
        makeCopyOfList(&tempProd2, &(*M));
    }

}



void modInverse(dList *e, dList *phi, dList *modIn)
{
    //phi is large
    //e is not that large
    long int j = 1;
    dList u1, u3, v1, v3, t1, t3, zero;
    initDList(&u1);
    initDList(&u3);
    initDList(&v1);
    initDList(&v3);
    initDList(&t1);
    initDList(&t3);
    initDList(&zero);

    insertTail(&zero, 0);
    insertTail(&u1, 1);
    makeCopyOfList(&(*e), &u3);
    insertTail(&v1, 0);
    makeCopyOfList(&(*phi), &v3);

    while(compareTwoNumbers(&v3, &zero) != 0)
    {
        char *quotient;
        if(compareTwoNumbers(&u3, &v3) < 0)//if e is > phi
        {

            makeCopyOfList(&u3, &t3);
            makeCopyOfList(&u1, &t1);
        }
        else
        {
            
            char dividend[10000];
            long int divisor = 0;
            
            DoublyNode *curr;
            curr = u3.head;
            int ctr2 = 0;
            while(curr -> rLINK != u3.head)
            {
                curr = curr -> rLINK;
                dividend[ctr2++] = (curr -> INFO) + 48;
            }
            dividend[ctr2] = '\0';
            curr = v3.head;
            int i = 0;
            while(curr -> lLINK != v3.head)
            {
                curr = curr -> lLINK;
                divisor += (curr -> INFO) * power(10, i++);
            }
            int x = 0, remainder1 =0;


            quotient = division(dividend,divisor, &remainder1, &x);
            while(*quotient)
                 if(*quotient ==48)
                     quotient++;
                 else
                     break;

            deleteAll(&t3);
            if(remainder1 == 0)
                insertFirst(&t3, 0);
            while(remainder1 != 0)
            {
                insertFirst(&t3, remainder1 % 10);
                remainder1 = remainder1/10;
                

            }
            
            dList tempProd, tempQuot;

            initDList(&tempQuot);
 
            int ctr = 0;
            while(quotient[ctr++] != '\0')
            {

                insertTail(&tempQuot, quotient[ctr-1] - 48);
            }

            multiplyTwoLargeNumbers(&tempQuot, &v1,&tempProd);
            deleteAll(&t1);
            addTwoLargeNumbers(&tempProd, &u1, &t1);

        }

        makeCopyOfList(&v1, &u1);
        makeCopyOfList(&t1, &v1);
        makeCopyOfList(&v3, &u3);
        makeCopyOfList(&t3, &v3);
        j = -j;

    }
    if(j < 0)
    {
        subtraction(&(*phi), &u1, &(*modIn));
    }
    else
        makeCopyOfList(&u1, &(*modIn));

}



void convertToBase10(dList *D)
{
    dList copy, exponent, sum, twentyseven;
    DoublyNode *curr;
    initDList(&copy);
    initDList(&exponent);
    initDList(&sum);
    initDList(&twentyseven);

    insertTail(&twentyseven,2);
    insertTail(&twentyseven,7);

    makeCopyOfList(&(*D), &copy);
    deleteAll(&(*D));
    insertTail(&(*D), 0);
    curr = copy.head;
    int limit = curr -> INFO;
    
    int j = 0, k = 0;
    for(j=0; j< limit; j++)
    {
        curr = curr ->lLINK;
        deleteAll(&exponent);
        insertTail(&exponent, 1);
        dList product;

        for(k=0; k<j; k++)
        {

            multiplyTwoLargeNumbers(&exponent, &twentyseven, &product); // expo * 27 = prod
            makeCopyOfList(&product, &exponent);                        // expo = prod
            deleteAll(&product);                                        //
        }


        
        dList temp;
        initDList(&temp);
        if(curr -> INFO == 0)
        {
            continue;
        }
        else if (curr -> INFO < 10)
        {
            insertTail(&temp, curr->INFO);
        }
        else
        {
            insertTail(&temp, (curr->INFO)/10);
            insertTail(&temp, (curr->INFO)%10);
        }
        multiplyTwoLargeNumbers(&exponent, &temp, &product); 

        addTwoLargeNumbers(&(*D), &product, &sum);
        makeCopyOfList(&sum, &(*D));
        deleteAll(&sum);
    }
   
}

void makeCopyOfList(dList *D, dList *copy)
{
    deleteAll(&(*copy));
    DoublyNode *curr;
    curr = D -> head;
    while(curr -> rLINK !=  D->head)
    {
        curr = curr -> rLINK;
        insertTail(&(*copy), curr->INFO);
    }
}

void InitQueue(Queue *Q)
{
    Q -> front = NULL;
}
int IsEmptyQueue(Queue *Q)
{
    return(Q->front == NULL);
}

void QueueOverflow(void)
{
    printf("Unable to get node from the memory pool.\n");
    exit(1);
}

void QueueUnderflow(void)
{
    printf("Queue underflow detected.\n");
    exit(1);
}

void ENQUEUE(Queue *Q, QueueElemType x)
{
    QueueNode *alpha;
    alpha = (QueueNode *) malloc(sizeof(QueueNode));
    if (alpha == NULL)
        QueueOverflow();
    else
    {
        alpha -> INFO = x;
        alpha -> LINK = NULL;
        if(Q -> front == NULL)
        {
            Q-> front = alpha;
            Q -> rear = alpha;
        }
        else
        {
            Q -> rear -> LINK = alpha;
            Q -> rear = alpha;
        }
    }
}

void DEQUEUE(Queue *Q, QueueElemType *x)
{
    QueueNode *alpha;
    if (Q-> front == NULL)
        QueueUnderflow();
    else
    {
        *x = Q -> front -> INFO;
        alpha = Q -> front;
        Q -> front = Q -> front -> LINK;
        free(alpha);
    }
}


//-------------------------------
void listOverflow(void)
{
    printf("Stack overflow detected. \n");
    exit(1);
}

void listUnderflow(void)
{
    printf("Stack underflow detected. \n");
    exit(1);
}

void initDList(dList *D)   //dList struct of doublyList
{
    //printf("a");
    D -> head = (DoublyNode *) malloc(sizeof(DoublyNode));
    D -> head -> INFO = 0;
    D -> head -> rLINK = D -> head;
    D -> head -> lLINK = D -> head;
}

int isEmptyList(dList *D)
{
    return (D->head == NULL);
}

void insertFirst(dList *D, doublyListElemType x)
{
    DoublyNode *alpha;
    alpha = (DoublyNode *) malloc(sizeof(DoublyNode));
    if(alpha == NULL)
        listUnderflow();
    else
    {
        D -> head -> INFO = D -> head -> INFO + 1; 
        alpha -> INFO = x;
        alpha -> rLINK = D -> head -> rLINK;
        alpha -> rLINK -> lLINK = alpha;
        alpha -> lLINK = D -> head;
        D -> head -> rLINK = alpha;
        //D -> head -> lLINK

    }
}

void insertTail(dList *D, doublyListElemType x)
{
    DoublyNode *alpha;
    alpha = (DoublyNode *) malloc(sizeof(DoublyNode));
    if(alpha == NULL)
        listUnderflow();
    else
    {
        D -> head -> INFO = D -> head -> INFO + 1; 
        alpha -> INFO = x;
        alpha -> lLINK = D -> head -> lLINK;
        alpha -> lLINK -> rLINK = alpha;
        alpha -> rLINK = D -> head;
        D -> head -> lLINK = alpha;

    }
}

void deleteFirst(dList *D, doublyListElemType *x)
{
    DoublyNode *alpha;
    if(D -> head -> INFO == 0)//NULL)
        listUnderflow();
    else
    {
        D -> head -> INFO = (D -> head -> INFO) - 1;
        alpha = D -> head -> rLINK; //temp del sa right
        *x = D -> head -> rLINK -> INFO;
        D -> head -> rLINK -> rLINK -> lLINK = D -> head;
        D -> head -> rLINK = D -> head -> rLINK -> rLINK;
        free(alpha);
    }
}

void printListMessage(dList *D)
{
    DoublyNode *curr, *headPTR;
    headPTR = D -> head; 
    curr = D -> head;
    printf("\nHEAD NG LIST:|%d| \n", D->head->INFO);
    while(curr -> rLINK != headPTR)
    {
        curr = curr -> rLINK;
        int x = curr -> INFO;
        if (x == 26)
        {
            x = 32;
        }
        else
        {    
            x = x + 65;
        }
        printf("%c" , x);

    }
}

void printToFile(FILE *fp, dList *D)
{
    DoublyNode *curr, *headPTR;
    headPTR = D -> head; 
    curr = D -> head;

    while(curr -> rLINK != headPTR)
    {
        curr = curr -> rLINK;
        int x = curr -> INFO;
        if (x == 26)
        {
            x = 32;
        }
        else
        {    
            x = x + 65;
        }
        fprintf(fp, "%c" , x);

    }
}

void printList(dList *D)
{
    DoublyNode *curr, *headPTR;
    headPTR = D -> head; 
    curr = D -> head;
    printf("\nHEAD NG LIST:|%d| \n", D->head->INFO);

    while(curr -> rLINK != headPTR)
    {
        curr = curr -> rLINK;
        printf("%d" , curr -> INFO);

    }
}

void printHead(dList *D)
{
    printf("Head: %d", D-> head -> INFO);


}

void addTwoLargeNumbers(dList *A, dList *B, dList *Sum)
{
    if ((A-> head -> INFO) >= (B -> head -> INFO))
    {
        DoublyNode *curr1, *curr2, *headPTR;
        headPTR = B -> head; 
        curr1 = B -> head;
        curr2 = A -> head;
        int c= 0, carry = 0;
        while(curr1 -> lLINK != headPTR)
        {
            curr1 = curr1 -> lLINK;
            curr2 = curr2 -> lLINK;
            c = curr1-> INFO + curr2 -> INFO + carry;
            carry = 0;
            if (c >= 10)
            {
                c = c % 10;
                carry = 1;
            } 
            insertFirst(&(*Sum), c);

        }
        headPTR = A -> head;
        while(curr2 -> lLINK != headPTR)
        {
            curr2 = curr2 -> lLINK;
            c = curr2 -> INFO + carry;
            carry = 0;
            if (c >= 10)
            {
                c = c % 10;
                carry = 1;
            } 
            insertFirst(&(*Sum), c);
        }
        if (carry > 0)
        {
            insertFirst(&(*Sum), carry);
        }
        //if (carry)*/
    }
    else
    {
        DoublyNode *curr1, *curr2, *headPTR;
        headPTR = A -> head; 
        curr1 = A -> head;
        curr2 = B -> head;
        int c= 0, carry = 0;
        while(curr1 -> lLINK != headPTR)
        {
            curr1 = curr1 -> lLINK;
            curr2 = curr2 -> lLINK;
            c = curr1-> INFO + curr2 -> INFO + carry;
            carry = 0;
            if (c >= 10)
            {
                c = c % 10;
                carry = 1;
            } 
            insertFirst(&(*Sum), c);

        }
        headPTR = B -> head;

        while(curr2 -> lLINK != headPTR)
        {
            curr2 = curr2 -> lLINK;
            c = curr2 -> INFO + carry;
            carry = 0;
            if (c >= 10)
            {
                c = c % 10;
                carry = 1;
            } 
            insertFirst(&(*Sum), c);
        }
        if (carry > 0)
        {
            insertFirst(&(*Sum), carry);
        }
        //if (carry)*/        
    }
}

void multiplyTwoLargeNumbers(dList *A, dList *B, dList *Prod)
{
    int k = peek(&(*A)) + peek(&(*B));//*(num1) -> head -> INFO + *(num2) -> head -> INFO;
    initProduct(&(*Prod), k);


    DoublyNode *theta, *alpha, *beta, *zeta;//, *headPTR;
    theta = Prod -> head;
    alpha = A -> head -> lLINK;
    while (alpha != A->head)
    {
        int a =0, c =0;
        a = alpha -> INFO;
        beta = B -> head -> lLINK;
        zeta = theta -> lLINK;
        theta = zeta;
        c = 0;
        while(beta != B->head)
        {
            int t =0;
            t = a * (beta->INFO) + (zeta -> INFO) + c;
            zeta -> INFO = t % 10;
            c = t/10;
            beta = beta -> lLINK;
            zeta = zeta -> lLINK;
        }
        zeta -> INFO= c;
        alpha = alpha -> lLINK;
    }
    DoublyNode *curr = Prod -> head;
    int temp = 0;
    while(curr -> rLINK->INFO == 0)
    {
        deleteFirst(&(*Prod), &temp);
    }
}

void initProduct(dList *prod, int k)
{
    initDList(&(*prod));
    int zero = 0, i = 0;
    for (i=0; i<k; i++)
    {
        insertFirst(&(*prod), zero);
    }        
}

int peek(dList *D)
{
    return D->head->INFO;
}

void deleteAll(dList *D)
{
    int i=0, x = 0;
    int limit = D-> head -> INFO;
    
    for (i=0; i< limit; i++)
    {
        deleteFirst(&(*D), &x); 
    }


}

void deleteTail(dList *D, doublyListElemType *x)
{
    DoublyNode *alpha;
    if(D -> head -> INFO == 0)
        listUnderflow();
    else
    {
        D -> head -> INFO = (D -> head -> INFO) - 1;
        alpha = D -> head -> lLINK; //temp del sa right
        *x = D -> head -> lLINK -> INFO;
        D -> head -> lLINK -> lLINK -> rLINK = D -> head;
        D -> head -> lLINK = D -> head -> lLINK -> lLINK;
        free(alpha);
    }
}


void convertToBase27(dList *A, dList *remainder27)
{
    dList twentyseven;
    initDList(&twentyseven);

    insertTail(&twentyseven,2);
    insertTail(&twentyseven,7);
    char *quotient;
    int j = 0;
    while(compareTwoNumbers(&(*A), &twentyseven) >= 0)
    {
        int remainder1= 0; //long int dati
        j=0;
        char dividend[10000];
        long int divisor = 27;
        DoublyNode *curr;
        curr = A -> head;
        long int i = 0;
        while(curr -> rLINK != A->head)
        {
            curr = curr -> rLINK;
            if(curr -> INFO >= 10)
            {
                dividend[i++] = ((curr->INFO)/10) + 48;
                dividend[i++] = ((curr->INFO)%10) + 48;
            }
            else
                dividend[i++] = (curr -> INFO) + 48;
        }

        quotient = division(dividend,divisor, &remainder1, &j);

        while(*quotient)
             if(*quotient ==48)
                 quotient++;
             else
                 break;

        insertFirst(&(*remainder27), remainder1);
        deleteAll(&(*A));
        for(i=0; i<j; i++)
        {
            insertTail(&(*A), (quotient[i]-48));
        }
        
    }

    if(quotient[0] == '\0')
    {

    }
    else if (quotient[1] == '\0')
    {
        int x = (quotient[0]-48);
        insertFirst(&(*remainder27), x);
    }
    else if (quotient[2] == '\0')
    {
        int x = (10*(quotient[0]-48)) + (quotient[1]-48);
        insertFirst(&(*remainder27), x);
    }

}

int compareTwoNumbers(dList *A, dList *B)
{
    // we know that A > B always
    if ((peek(&(*A)) > peek(&(*B))))
    {
        return 1;
    }
    else if (peek(&(*A)) < peek(&(*B)))
    {
        return -1;
    }
    else 
    {
        DoublyNode *currTemp1, *currTemp2;
        currTemp1 = A -> head;
        currTemp2 = B -> head;
        while(currTemp1->rLINK != A ->head)
        {
            currTemp1 = currTemp1 -> rLINK;
            currTemp2 = currTemp2 -> rLINK;
            if((currTemp1->INFO) > (currTemp2->INFO))
            {

                return 1; //return
            }
            else if((currTemp1->INFO) < (currTemp2->INFO))
            {
                return -1; // return
            }
        }

        return 0;
    }

}

/*
Reference:
http://www.cquestions.com/2010/08/division-of-large-numbers-in-c.html

*/
char *division(char dividend[],long int divisor, int *remainder1, int *j)
{
   
    static char quotient[10000];
    long int temp=0;
    int i=0;
    //char *quotient;

    while(dividend[i])
    { 
        temp = temp*10 + (dividend[i] -48);
        if(temp<divisor)
        {   
            quotient[(*j)++] = 48;
        }
        else
        {
            quotient[(*j)++] = (temp / divisor) + 48;
            temp = temp % divisor;
        }
        i++;
    }
    quotient[(*j)] = '\0';
    *remainder1 = temp;
    return quotient;
}

int gcf(dList *A, dList *B)
{

    dList r;
    initDList(&r);

    char dividend[10000],*quotient;
    long int divisor = 0;
    int remainder1 = 0, j = 0;

    DoublyNode *curr;
    curr = B -> head;
    int i = 0;
    while(curr -> lLINK != B -> head)
    {
        curr = curr -> lLINK;
        divisor += (curr -> INFO) * power(10, i++);
        //printf("")
    }
    curr = A -> head;
    //int j = 0;
    while(curr -> rLINK != A -> head)
    {
        curr = curr -> rLINK;
        dividend[j++] = (curr -> INFO) +48;
    }
    
    
    quotient = division(dividend,divisor, &remainder1, &j);
    int b = divisor;
    while(remainder1 > 0)
    {
        char dividend2[10000];
        deleteAll(&(*A));
        makeCopyOfList(&(*B), &(*A));
        b = remainder1;
        curr = A -> head;
        j = 0;
        dividend2[curr->INFO] = '\0';
        while(curr -> rLINK != A -> head)
        {
            curr = curr -> rLINK;
            dividend2[j++] = (curr -> INFO) + 48;
        }

        deleteAll(&(*B));
        curr = B -> head;
        int tempB = b;
        while(tempB != 0)
        {
            insertFirst(&(*B), tempB%10);
            tempB = tempB / 10;
        }
        divisor = b;
        quotient = division(dividend2,divisor, &remainder1, &j);
    }
    return b;
}

int power(int base, unsigned int exp) 
{
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}

void computePhi(dList *p, dList *q, dList *phi)
{
    dList one, pTEMP, qTEMP;
    initDList(&pTEMP);
    initDList(&qTEMP);
    initDList(&one);
    insertFirst(&one, 1);

    makeCopyOfList(&(*p), &pTEMP);
    makeCopyOfList(&(*q), &qTEMP);

    subtraction1((&pTEMP));
    subtraction1((&qTEMP));
    multiplyTwoLargeNumbers(&pTEMP, &qTEMP, &(*phi));
}

void subtraction1(dList *A)
{
    dList twentyseven, difference;
    initDList(&twentyseven);
    initDList(&difference);

    insertTail(&twentyseven,1);
    //insertTail(&twentyseven,7);

    DoublyNode *curr1, *curr2;
    curr1 = A -> head;
    curr2 = twentyseven.head;
    int c = 0, borrow = 0;//, d = 0;
    while(curr2 -> lLINK != twentyseven.head)
    {
        curr1 = curr1 -> lLINK;
        curr2 = curr2 -> lLINK;

        //borrow = 0;
        if ((curr1 -> INFO-borrow) < curr2 -> INFO)
        {
            c = (10 + (curr1 -> INFO - borrow)) - (curr2->INFO); 
            borrow = 1;
            insertFirst(&difference, c);
        }
        else
        {
            c = (curr1 -> INFO - (borrow)) - (curr2 -> INFO);
            borrow = 0;
            insertFirst(&difference,c);
        }
    }

    while(curr1 -> lLINK != A -> head)
    {


        curr1 = curr1 -> lLINK;
        if (((curr1 -> INFO)-borrow) < 0)
        {
            c = 9; 
            borrow = 1;
            insertFirst(&difference, c);
        }
        else
        {
            c = (curr1 -> INFO) - borrow;
            //printf("\nc = curr1 INFO - borrow %d = %d - %d\n", c, curr1->INFO, borrow);

            borrow = 0;
            insertFirst(&difference,c);
        }
    }
    deleteAll(&(*A));
    makeCopyOfList(&difference, &(*A));

}

void subtraction(dList *A, dList *B, dList *difference)
{

    DoublyNode *curr1, *curr2;
    curr1 = A -> head;
    curr2 = B ->head;
    int c = 0, borrow = 0;//, d = 0;
    while(curr2 -> lLINK != B->head)
    {
        curr1 = curr1 -> lLINK;
        curr2 = curr2 -> lLINK;

        //borrow = 0;
        if ((curr1 -> INFO-borrow) < curr2 -> INFO)
        {
            c = (10 + (curr1 -> INFO - borrow)) - (curr2->INFO); 
            borrow = 1;
           // printf("\n%d-borrow(%d) - %d", curr1 -> INFO, borrow, curr2 -> INFO);
            //printf("\nC: %d", c);
            insertFirst(&(*difference), c);
        }
        else
        {
            c = (curr1 -> INFO - (borrow)) - (curr2 -> INFO);
            borrow = 0;
            insertFirst(&(*difference),c);
        }
    }

    while(curr1 -> lLINK != A -> head)
    {

        curr1 = curr1 -> lLINK;
        if (((curr1 -> INFO)-borrow) < 0)
        {
            c = 9; 
            borrow = 1;
            insertFirst(&(*difference), c);
        }
        else
        {
            c = (curr1 -> INFO) - borrow;
            //printf("\nc = curr1 INFO - borrow %d = %d - %d\n", c, curr1->INFO, borrow);

            borrow = 0;
            insertFirst(&(*difference),c);
        }
    }
    curr1 = difference -> head;
    int tempInt = 0;
    while(curr1 -> rLINK -> INFO == 0)
    {
        deleteFirst(&(*difference), &tempInt);
    }

}