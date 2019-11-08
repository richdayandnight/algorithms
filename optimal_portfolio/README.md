# Optimal Portfolio
date coded: November 2016

## How to run C code

- Install gcc compiler
```
sudo apt-get install build-essential
```
- Compile the program
```
gcc -o optimal optimal_portfolio.c -lm
```
- Run the program
```
./optimal
```
- See output text for results (output.txt)

## Directions:

- Create a program that will solve the problem below.
- The program must written in the C programming language, using only the following libraries stdio.h, stdlib.h, string.h
- The program must compile using standard Linux GCC

To be a good stock investor, he must know how to form an optimal portfolio. A
portfolio is a collection of stocks. An optimal portfolio is a combination of stocks that
maximizes the earnings while minimizing the risks.

There are n stocks in the Stock Market, numbered from 1 – n. For each stock r, there
is an assigned fraction r<sub>i</sub> such that 0<r<sub>i</sub>≤1. This fraction indicates the share of a
particular stock in the portfolio, such that the portfolio is optimal. It follows that ![formula1](https://raw.github.com/richdayandnight/algorithms/master/optimal_portfolio/equation1.png)

Let s<sub>i</sub> indicate the number of stock i stocks already bought by the
investor, and let ![equation2](https://raw.github.com/richdayandnight/algorithms/master/optimal_portfolio/equation2.png)

The portfolio is optimal if the following property is ![equation3](https://raw.github.com/richdayandnight/algorithms/master/optimal_portfolio/equation3.png)

The goal of this code is to determine the number of stocks an investor can still buy to
keep his portfolio optimal. If there is no limit in the number of stocks, then output,
“no limit”. Take note that an investor can buy only one stock per day.

## Input format:
Each input test case has three lines. The first line is consists of the number of
available stocks n and the total stocks already bought (k). The second line is a series
of n integers that will eventually correspond to the fraction contribution to the optimal
portfolio (i.e: Each ai in the second line corresponds to the following fraction ri : ![equation4](https://raw.github.com/richdayandnight/algorithms/master/optimal_portfolio/equation4.png).  

The third line is consists of k numbers indicating the stock bought in
each of the previous k days.

## Output Format:
For each test case, the output is either a number (indicating the number of stocks
that can still be bought while keeping the portfolio balanced) or “NO LIMIT” if there is
no limit in the number of stocks that can be bought. 

### INPUT:
10 6  
10 10 10 1 1 1 1 1 1 1  
1 2 3 4 5 6  
10 5  
10 10 10 1 1 1 1 1 1 1  
1 2 3 6 7  
10 7  
10 10 10 1 1 1 1 1 1 1  
3 2 1 6 5 4 10  

### OUTPUT:
1  
NO LIMIT  
0  