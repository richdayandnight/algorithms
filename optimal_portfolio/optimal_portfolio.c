#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	FILE *file, *output;
    output = fopen ("output.txt", "w");
    int firstWrite = 0;


    file = fopen ("input.txt", "r");
    int n = 0, k = 0, ctr1 = 0, origK = 0;
    while(fscanf(file, "%d ", &n) == 1)
    {
        firstWrite++;
        int stock = 0, maxStock =0;
    	fscanf(file, "%d\n", &k);
        origK = k;

    	int *nArr = (int*)malloc(n*sizeof(int));
        int *kArr = (int*)malloc(n*sizeof(int));
        int *kArrOrig = (int*)malloc(n*sizeof(int));

        int denom = 0;
    	for(ctr1 = 0; ctr1 < n-1; ctr1++)
    	{
    		fscanf(file, "%d ", &nArr[ctr1]);
            denom += nArr[ctr1];
    	}
    	fscanf(file, "%d\n", &nArr[ctr1]);


        denom += nArr[ctr1];
        int temp = 0;
        for(ctr1 = 0; ctr1 < n; ctr1++)
        {
            kArr[ctr1] = 0;
        }
    	for(ctr1 = 0; ctr1 < k-1; ctr1++)
    	{
    		fscanf(file, "%d ", &temp);
            kArr[temp-1] += 1; 
    	}
    	fscanf(file, "%d\n", &temp);
        kArr[temp-1] += 1;

        for(ctr1 = 0; ctr1 < n; ctr1++)
        {
            kArrOrig[ctr1] = kArr[ctr1];
        }


        int extraCtr = 0, j=0;

        
        int limit = n;
        if (limit > 10000)
            limit = 200;
        for(extraCtr = 0; extraCtr<limit; extraCtr++)
        {
            for(j=0;j<n;j++)
            {
                kArr[j] = kArrOrig[j];
            }
            int m = origK, ctr2 = 0; 
            stock = 0;

            for(ctr1 = extraCtr; ctr1<n ; ctr1++)
            {

                m += 1;
                float r = (float) nArr[ctr1] / (float) denom;
                float fBoundary = (float)m * r;
                int upperBound = ceil(fBoundary);
                int lowerBound = floor(fBoundary);
                if((kArr[ctr1] + 1) >= lowerBound && (kArr[ctr1] + 1) <= upperBound)
                {    
                    int optimal = 1;
                    for(ctr2=0; ctr2<n;ctr2++)
                    {
                        if(ctr1 == ctr2)
                            continue;
                        r = (float) nArr[ctr2] / (float) denom;
                        fBoundary = (float)m * (float)r;
                        upperBound = ceil(fBoundary);
                        lowerBound = floor(fBoundary);
                        if(((kArr[ctr2] < lowerBound) || (kArr[ctr2] > upperBound)))
                        {
                            optimal = 0;
                            m -=1;
                            break;
                        }
                    }
                    if (optimal == 1)
                    {
                        kArr[ctr1] += 1;
                        stock += 1;
                        ctr1 = ctr1-1;
                        if(stock > 3)
                            break;
                    } 
                }
                else
                {
                    m-=1;
                }
            }
            if(maxStock<stock)
            {
                maxStock = stock;
            }
            if (maxStock > 1)
                break;
        }
        if(firstWrite == 1)
        {
            if(maxStock >= 2)
                fprintf(output, "NO LIMIT");
            else
                fprintf(output, "%d" ,maxStock);
        }
        else
        {
            if(maxStock >= 2)
                fprintf(output, "\nNO LIMIT");
            else
                fprintf(output, "\n%d" ,maxStock);
        }
    }

    fclose(file);
    fclose(output);
	return 0;
}