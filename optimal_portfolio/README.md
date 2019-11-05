# Optimal Portfolio
date coded: November 2016

## Directions:

- Create a program that will solve the problem below.
- The program must written in the C programming language, using only the following libraries stdio.h, stdlib.h, string.h
- The program must compile using standard Linux GCC

To be a good stock investor, he must know how to form an optimal portfolio. A
portfolio is a collection of stocks. An optimal portfolio is a combination of stocks that
maximizes the earnings while minimizing the risks.

There are n stocks in the Stock Market, numbered from 1 – n. For each stock r, there
is an assigned fraction r<sub>i</sub> such that 0<r<sub>i</sub>≤1. This fraction indicates the share of a
particular stock in the portfolio, such that the portfolio is optimal. It follows that
![equation](http://www.sciweavers.org/tex2img.php?eq=%20%5Csum_%7Bi%3D1%7D%5En%20%20r_%7Bi%7D%20%3D%201%20&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0)

Let s<sub>i</sub> indicate the number of stock i stocks already bought by the
investor, and let 

![equation2](http://www.sciweavers.org/tex2img.php?eq=%20m%20%3D%20%5Csum_%7Bi%3D1%7D%5En%20%20s_%7Bi%7D%20&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0)

The portfolio is optimal if the following property is

![equation3](http://www.sciweavers.org/tex2img.php?eq=%5Clfloor%7Bm%20r_%7Bi%7D%7D%20%20%5Crfloor%20%3D%20%7Bs_%7Bi%7D%7D%20%3D%5Clceil%20%7Bm%20r_%7Bi%7D%7D%20%20%5Crceil&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0)

The goal of this code is to determine the number of stocks an investor can still buy to
keep his portfolio optimal. If there is no limit in the number of stocks, then output,
“no limit”. Take note that an investor can buy only one stock per day.

