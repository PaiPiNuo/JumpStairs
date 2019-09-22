#include <iostream>
#include "ExchangeCoin.h"
#include "main.h"

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
	vector<int> FinalResult;
	vector<vector<int>> recordProgress;
	recordProgress.resize(Total + 1);


	memset(each_method,0,(Total+1)*sizeof(int));
	int minValue=INF;
	int Coin_Choose=0;
	for(int i=1;i<=Total;i++){
		minValue=INF;
		for(int j=0;j<sort_Coin;j++){
			if(i>=Coin[j]&&each_method[i-Coin[j]]<minValue){
				minValue=each_method[i-Coin[j]];
				Coin_Choose = Coin[j];
			}
		}
		recordProgress[i] = recordProgress[i - Coin_Choose];
		recordProgress[i].push_back(Coin_Choose);
		each_method[i]=minValue+1;
		cout << "Detail of money "<< i <<" : "<<endl;
		showVector(recordProgress[i]);
	}

	cout<<"The Least Number is:  "<<each_method[Total]<<endl;
	delete[] each_method;
	delete[] Coin;
	return 0;
}

static void showVector(const vector<int> vect) {
	for (int i = 0; i < vect.size();i++) {
		cout << vect [i]<< "  ";
	}
	cout << endl;
}