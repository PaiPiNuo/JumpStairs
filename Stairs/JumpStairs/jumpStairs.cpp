#include "jumpStairs.h"
#include <iostream>
using namespace std;

/*
Method:Recursion
*/
int simpleStairs_Recur(const int n){
	if(0==n){
		cout<<"Warning:No stairs!"<<endl;
		return 0;
	}
	else if(1==n){
		return 1;
	}
	else if(2==n){
		return 2;
	}
	else if(n>2){
		return simpleStairs_1(n-1)+simpleStairs_1(n-2);
	}
}

/*
Method:Dynamic Programming
*/
int simpleStairs_Dyna(const int n){
	int fn_1=0,fn_2=0,fn;//f(n-1),f(n-2),f(n)
	if(0==n){
		cout<<"Warning:No stairs!"<<endl;
		return 0;
	}
	else if(1==n){
		return 1;
	}
	else if(2==n){
		return 2;
	}
	else if(n>2){
		fn_2=1;//f(n-2)
		fn_1=2;//f(n-1)
		for(int i=3;i<=n;i++){
			fn=fn_1+fn_2;
			fn_2=fn_1;
			fn_1=fn;
		}
		return fn;
	}
}

/*
Method:Dynamic Programming
*/
int CrazyStairs_Dyna(const int n){

	//int fn_1=0,fn_2=0,fn;//f(n-1),f(n-2),f(n)
	//if(0==n){
	//	cout<<"Warning:No stairs!"<<endl;
	//	return 0;
	//}
	//else if(1==n){
	//	return 1;
	//}
	//else if(2==n){
	//	return 2;
	//}
	//else if(n>2){
	//	fn_2=1;//f(n-2)
	//	fn_1=2;//f(n-1)
	//	for(int i=3;i<=n;i++){
	//		fn=fn_1+fn_2;
	//		fn_2=fn_1;
	//		fn_1=fn;
	//	}
	//	return fn;
	//}
}