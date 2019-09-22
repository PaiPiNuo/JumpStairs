#include <iostream>
#include "ExchangeCoin.h"
using namespace std;

int ExchangeCoin_Dyna(){
	int Total;
	cout<<"Please input Total Money:"<<endl;
	cin>>Total;
	int sort_Coin;
	cout<<"The Number of Coin Sort:"<<endl;
	cin>>sort_Coin;
	int *Coin=new int[sort_Coin];
	for(int i=0;i<sort_Coin;i++){
		cin>>Coin[i];
	}
	int *each_method=new int[Total+1];
	memset(each_method,100000,(Total+1)*sizeof(int));
	int minValue=100000;
	each_method[0]=0;
	for(int i=1;i<=Total;i++){
		minValue=100000;
		for(int j=0;j<sort_Coin;j++){
			if(i>=Coin[j]&&each_method[i-Coin[j]]<minValue){
				minValue=each_method[i-Coin[j]];
			}
		}
		each_method[i]=minValue+1;
		//cout<<each_method[i]<<endl;
	}

	cout<<"The Least Number is:  "<<each_method[Total]<<endl;
	delete each_method;
	delete Coin;
	return 0;
}