#ifndef EXAMPLE_H
#define EXAMPLE_H

#include<iostream>
using namespace std;

/*
动态规划，n种面额的硬币，如何用最少的硬币凑出价值为W的钱
*/
void coinConvert();
/*
最长上升子序列问题
*/
void LIS();
void LIS_optimize_nlogn();
/*
最长公共子序列问题
*/
void LCS_NN();
/*
对于两个全排列的数组，用nlogn的复杂度求解最长公共子序列
3 1 2 4 5
2 5 4 1 3
*/
void LCS_nlogn();

#endif