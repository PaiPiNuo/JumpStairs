#include "memorySearch.h"
#include <iostream>
#include <algorithm>

using namespace std;

/*
01背包问题，DFS暴搜的方法解决
*/
int* weight;
int* value;
int total=0;
int capacity, sorts;

void DFS_base(int capacity,int Sorts,int j,int money){
	if (capacity < 0)
		return;
	//j从0开始计数
	if (j == Sorts){
		total = max(total, money);
		return;
	}
	
	DFS_base(capacity, Sorts, j + 1, money);
	DFS_base(capacity - weight[j], Sorts, j + 1, money + value[j]);
}

int DFS_return(int capacity, int j){
	if (capacity < 0)
		return 0;
	if (j == sorts)
		return 0;
	int choose = DFS_return(capacity, j + 1);
	int noChoose = DFS_return(capacity - weight[j], j + 1) + value[j];
	return max(choose, noChoose);
}

int DFS_memory(int capacity, int j){

}

void forceSearch(){	
	cout << "Please input the Total Capacity:" << endl;
	cin >> capacity;
	cout << "Please input the sorts of Goods:" << endl;
	cin >> sorts;
	cout << "Please input the time and value of each Herb: (eg. 20(time)  5(value))" << endl;
	weight = new int[sorts];
	value = new int[sorts];
	for (unsigned int i = 0; i < sorts; i++){
		cin >> weight[i] >> value[i];
	}

	//DFS_base(capacity, sorts, 0, 0);//第一个0表示0号商品，第二个0表示当前包内总价值为0
	//total=DFS_return(capacity, 0);


	cout << "The Max Total Value is:" << total << endl;
}