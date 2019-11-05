#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INFINITE 9999999

float* dijkstra(float **graph,int n,int origin);
int compareFloat(float A, float B);

int main()
{
	FILE *file, *output;
    int i = 0, j =0;
    output = fopen ("output.txt", "w");
    int testCase = 0;

    file = fopen ("input.txt", "r");

    float *kmDistanceArr, *priceArr;
    while(fscanf(file, "%d\n", &testCase) == 1)
    {
    	float destination = 0, tank = 0, kmPerLiter = 0, originCost = 0;
    	int numOfStations = 0;
    	fscanf(file, "%f\n", &destination);
    	fscanf(file, "%f %f %f %d\n", &tank, &kmPerLiter, &originCost, &numOfStations);

    	kmDistanceArr = (float*)malloc((numOfStations+1)*sizeof(float));
        priceArr = (float*)malloc((numOfStations+1)*sizeof(float));

        float tempKmDist = 0, tempPrice =0;
        int x =0, y= 0, z =0;
        for(x=1; x<numOfStations+1; x++)
        {
            float temp1 = 0, temp2 = 0;
        	fscanf(file, "%f ", &temp1);
            fscanf(file, "%f\n", &temp2);
            *(kmDistanceArr + x) = temp1;
            *(priceArr + x) = temp2;
        }

        kmDistanceArr[0] = 0;
        priceArr[0] = 0;

        float **graph = (float**)malloc((numOfStations+1)*sizeof(float*));
        for(y = 0; y < numOfStations+1; y++)
        {
            graph[y] = (float*)malloc((numOfStations+1)*sizeof(float));
        }
        for(x=0; x<numOfStations+1; x++)
        {
            for(y=0; y<numOfStations+1; y++)
            {
                graph[x][y] = 0;
            }
        }

        for(y = 0; y<numOfStations+1; y++)
        {
            for(z = 0; z<numOfStations+1; z++)
            {
                if(z == y || z< y)
                {
                    graph[y][z] = 0;
                }                    
                else
                {
                    float checkIfAddEdge = (kmDistanceArr[z] - kmDistanceArr[y])/kmPerLiter;
                    float halfOfTank = tank/2;
                    if(compareFloat(checkIfAddEdge, halfOfTank) == -1)
                    {
                        if(z!= numOfStations && (compareFloat((kmDistanceArr[z+1] - kmDistanceArr[y])/kmPerLiter,tank) == 1))
                        {
                            graph[y][z] = ((kmDistanceArr[z] - kmDistanceArr[y])/kmPerLiter) * *(priceArr + (z)) + 200;
                            //printf("\n<<<<<<Enter here!!!!!!!LKSDJALSKJD %f ", kmDistanceArr[z]);
                        }
                        else
                        {
                            graph[y][z] = 0;
                        }

                    }
                    else if (compareFloat(checkIfAddEdge, tank) == 1)
                    {
                        break;   
                    }
                    else
                    {
                        graph[y][z] = ((kmDistanceArr[z] - kmDistanceArr[y])/kmPerLiter) * *(priceArr + (z)) + 200;
                    }
                    
                }
            }
        }

        float min = 9999999.99;



        float *cheapest = dijkstra(graph, numOfStations+1, 0);

        for(i=1; i<numOfStations+1; i++)
        {
            float checkIfAabot = (destination - kmDistanceArr[i])/kmPerLiter;
            if(compareFloat(checkIfAabot,tank) == -1 || compareFloat(checkIfAabot,tank) == 0)
            {
                if (compareFloat(*(cheapest+i), min) == -1)
                {
                    min = *(cheapest+i);
                }
            }
            else
            {
                continue;
            }
        }

        float floatAnswer = (min/100) + originCost;//(2* pathCtr[minimumCtr])+originCost;
        int answer = round(floatAnswer);

        //printf("min: %f")
        float compareMin = 9999998.000000;

        //printf("%f == %f\n", min, compareMin);
        if (compareFloat(min, compareMin) == 1)
        {
            if(testCase == 1)
                fprintf(output, "Case %d: Gasoline stations not enough", testCase);
            else
                fprintf(output, "\nCase %d: Gasoline stations not enough", testCase);
        }
        else
        {
            if(testCase == 1)
                fprintf(output, "Case %d: %d", testCase, answer);
            else
                fprintf(output, "\nCase %d: %d", testCase, answer);
        }
    }
    fclose(file);
    fclose(output);

    //float x = 0.91, y = 0.91;
    //if(compareFloat(x,y) == 0)
    //	printf("SAME");
	return 0;
}



/*
* Reference used: 
*http://www.thecrazyprogrammer.com/2014/03/dijkstra-algorithm-for-finding-shortest-path-of-a-graph.html
*
*1. Create cost matrix C[ ][ ] from adjacency matrix adj[ ][ ]. C[i][j] is the cost of going from vertex i to vertex j. If there is no edge between vertices i and j then C[i][j] is infinity.
 
2. Array visited[ ] is initialized to zero.
               for(i=0;i<n;i++)
                              visited[i]=0;
 
3. If the vertex 0 is the source vertex then visited[0] is marked as 1.
 
4. Create the distance matrix, by storing the cost of vertices from vertex no. 0 to n-1 from the source vertex 0.
               for(i=1;i<n;i++)
                              distance[i]=cost[0][i];
Initially, distance of source vertex is taken as 0. i.e. distance[0]=0;
 
5. for(i=1;i<n;i++)
– Choose a vertex w, such that distance[w] is minimum and visited[w] is 0. Mark visited[w] as 1.
– Recalculate the shortest distance of remaining vertices from the source.
– Only, the vertices not marked as 1 in array visited[ ] should be considered for recalculation of distance. i.e. for each vertex v
               if(visited[v]==0)
                              distance[v]=min(distance[v],
                              distance[w]+cost[w][v])
*
*/
float* dijkstra(float **graph,int n,int origin)
{
    int count = 0,nextNode = 0,i = 0,j = 0;
    int ctr2 = 0;
    float cheapest = 0;
    float *distance = (float*)malloc(n*sizeof(float));
    int *pred = (int*)malloc(n*sizeof(int));
    int *visited = (int*)malloc(n*sizeof(int));
    float **sulit = (float**)malloc(n*sizeof(float*));
    for(ctr2 = 0; ctr2 < n; ctr2++)
    {
        sulit[ctr2] = (float*)malloc(n*sizeof(float));
    }
    for(i = 0 ; i < n ; i++)
    {
        for(j=0;j<n;j++)
        {
            if(compareFloat(graph[i][j], 0) == 0)//graph[i][j]==0)
            {
                sulit[i][j]=INFINITE;
            }
            else
            {
                sulit[i][j]=graph[i][j];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        distance[i] = sulit[origin][i];
        pred[i] = origin;
        visited[i] = 0;
    }
    
    distance[origin]=0;
    visited[origin]=1;
    count=1;
    
    while(count < n-1)
    {
        cheapest = INFINITE;
        for(i=0;i<n;i++)
            if((compareFloat(distance[i],cheapest) == -1) &&!visited[i])
            {
                cheapest=distance[i];
                nextNode=i;
            }            
            visited[nextNode]=1;
            for(i=0;i<n;i++)
            {
                if(!visited[i])
                {
                    if(compareFloat(cheapest+sulit[nextNode][i], distance[i]) == -1)
                    {
                        distance[i]=cheapest+sulit[nextNode][i];
                        pred[i]=nextNode;
                    }
                }
            }
        count++;
    }
    return distance;
}

int compareFloat(float A, float B)
{
  float precision = 0.00001;
  if (((A - precision) < B) && 
      ((A + precision) > B))
   {
    return 0;
   }
  else if((A - B < precision) && (fabs(A-B) > precision))
  {
    //printf("A is less than B");
    return -1;
  }

  else if ((A - B > precision) && (fabs(A-B) > precision))
  {
    //printf("A is greater than B");
    return 1;
  }
}
