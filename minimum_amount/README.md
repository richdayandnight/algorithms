# Minimum amount
date coded: November 2016

## Directions:
- Create a program that will solve the problem below.
- The program must written in the C programming language, using only the
following libraries stdio.h, stdlib.h, string.h, math.h
- The program must compile using standard Linux GCC
- Time Limit: 5 seconds
- Assume that all input data will be less than 106
- Assume that there are at most 1000 gasoline stations

Your family owns a bus corporation. Since you are the only Computer Scientist in the
family, your father has tasked you to create a program that will compute the
minimum amount of money a driver will spend for gasoline and food to make the trip.
You will have the following assumptions:
1. You have a copy of the list of all the gasoline stations in the routes. The list
contains the location of the station and the current price per liter of gasoline.
2. A driver never stops at a gasoline station when the gasoline tank contains
more than half of its capacity, unless the car cannot get to the next gasoline
station or to the destination with the amount of gasoline left in the tank.
3. A driver always fills the gasoline tank completely at every gasoline station
stop.
4. When stopped in a gasoline station, the driver will spend 2 pesos on candies
and chewing gum
5. A driver does not need to store gasoline more than what the bus needs.
6. A driver always begins with a full tank of gasoline.
7. The final amount must be rounded off to the nearest peso.

## Input:
The program input will consist of several test cases, with each test case having
several lines of information. The first line indicates the case number. The next 2 lines
give information about the origin and destination. The remaining lines of the data set
represent the gasoline stations along the route, with one line per gasoline station.  
Line 1: Case number
Line 2: One real number (less than 106 ) – distance from the origin to the destination.
Line 3: Three real numbers followed by an integer (First 3 numbers are less than 106,
the last integer is less than 1000).
- First number: Capacity of the fuel tank (in liters)
- Second number: number of kilometers per liter that the bus can travel
- Third number: Cost of filling the bus in the origination city.
- Fourth number: Number of gasolines along the route
Each remaining line: Two real numbers (both less than 106 )
- First number is the distance (in kms) from the origination city to the gasoline
station.
- Second number is the price (in centavos) per liter of gasoline sold at that
station.
All data are positive. Gasoline stations along the route are arranged in non
descending order of distance from the origin. No gasoline station along the route is
further from the origin that the distance from the origin to the destination. It is
possible that there are no enough gasoline stations in the route that can provide
enough gasoline to the vehicle for it to reach its destination. In this case the program
should output: Gasoline stations not enough.

## Output
For each data set, the program should print the case number and the minimum total
cost (or “Gasoline stations not enough.”).

## Sample Input 
1  
475.6  
11.9 27.4 14.98 6  
102 99.9  
220 132.9  
256.3 147.9  
275 102.9  
277.6 112.9  
381.3 100.9  
2  
516.3  
15.7 22.1 20.87 3  
125.4 125.9  
297.9 112.9  
345.2 99.9  
3  
1000  
11.2 10.1 15 1  
990 99.2  

## Sample Output
Case 1: 27  
Case 2: 38  
Case 3: Gasoline stations not enough  