#include<iostream>
#include "main.h"
using namespace std;

static int A2(){
	cout<<"main_A"<<endl;
	return 0;
}
int main(){
	/*int Num_Stairs;
	cout<<"Please input the Number of Total Stairs:"<<endl;
	cin>>Num_Stairs;
	cout<<"Number of ways to Go Up Stairs:"<<endl;
	cout<<"Method-Recursion:"<<simpleStairs_Recur(Num_Stairs)<<endl;
	cout<<"Method-Dynamic Programming:"<<simpleStairs_Dyna(Num_Stairs)<<endl;
	cout << "Simple Jumping:1-2-1-1-2"<< endl;
	cout<<"Method-Recursion:  "<<simpleStairs_Recur(Num_Stairs)<<endl;
	cout<<"Method-Dynamic Programming:  "<<simpleStairs_Dyna(Num_Stairs)<<endl;
	cout << "----------------"<<endl<<"Crazy Jumping:1-2-n-4" << endl;
	cout << "Method-Recursion:  " << CrazyStairs_Recur(Num_Stairs) << endl;
	cout << "Method-Dynamic Programming:  " << CrazyStairs_Dyna(Num_Stairs) << endl;*/

	ExchangeCoin_Dyna();
	cout<<"HelloWorld!"<<endl;
	system("pause");
	return 0;
}