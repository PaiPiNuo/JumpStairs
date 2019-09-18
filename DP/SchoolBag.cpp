#include "schoolbag.h"
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

/*
   01�������⣬ÿ����Ʒֻ��һ����ֻ��ѡһ�Σ���ά����ⷨ
   (��ȫ���������У�ÿ����Ʒ�����ظ���)
*/
void DP_schoolbag01(){
	int TotalTime, sorts;
	cout << "Please input the Total Time:"<< endl;
	cin >> TotalTime;
	cout << "Please input the sorts of Herb:" << endl;
	cin >> sorts;
	cout << "Please input the time and value of each Herb: (eg. 20(time)  5(value))"<< endl;
	int* time = new int[sorts];
	int* value = new int[sorts];
	for (unsigned int i = 0; i < sorts;i++){
		cin >> time[i] >> value[i];
	}

	vector<vector<int>> valueTable;
	valueTable.resize(sorts+1);
	for (int i = 0; i <= sorts;i++){
		valueTable[i].resize(TotalTime+1,0);
	}
	//------------�ص���ƹ�ʽ-----------------------
	for (int i = 0; i <= TotalTime; i++){
		for (int j = 1; j <= sorts;j++){
			if (i < time[j-1]){
				//�����³��ֵ���Ʒ���࣬�����������i<����Ʒ��������time[j-1]����ô������Ʒ�������ֶ�һ����ֱ�Ӽ̳и���Ʒ����֮ǰ�Ľ������
				valueTable[j][i] = valueTable[j-1][i];
			}
			else{ 
				//�����³��ֵ���Ʒ���࣬�����������i>=����Ʒ��������time[j-1]����ô
				//max(ѡ�����Ʒ����ѡ�����Ʒ)
				valueTable[j][i] = max(valueTable[j - 1][i], valueTable[j - 1][i - time[j - 1]] + value[j - 1]);
				if (i == TotalTime&&valueTable[j][i] != valueTable[j - 1][i]){
					cout <<"Choose: "<<time[j-1] << endl;
				}
			}
			//cout << valueTable[j][i] << "  ";
		}
		//cout << endl;
	}
	//-----------------------------------------------
	cout << "The Max Value is: " << valueTable[sorts][TotalTime] << endl;

	delete[] time;
	delete[] value;
}

/*
01�������⣬ÿ����Ʒֻ��һ����ֻ��ѡһ�Σ�һά����ⷨ
(��ȫ���������У�ÿ����Ʒ�����ظ���)
*/
void DP_schoolbag01_Single(){
	int TotalTime, sorts;
	cout << "Please input the Total Time:" << endl;
	cin >> TotalTime;
	cout << "Please input the sorts of Herb:" << endl;
	cin >> sorts;
	cout << "Please input the time and value of each Herb: (eg. 20(time)  5(value))" << endl;
	int* time = new int[sorts];
	int* value = new int[sorts];
	for (unsigned int i = 0; i < sorts; i++){
		cin >> time[i] >> value[i];
	}

	vector<int> valueTable;
	valueTable.resize(TotalTime + 1,0);
	//------------�ص���ƹ�ʽ-----------------------
	for (int j = 0; j < sorts; j++){
		for (int i = TotalTime; i >= 0; i--){
			if (i>=time[j]){
				valueTable[i] = max(valueTable[i], valueTable[i-time[j]] + value[j]);
			}			
		}
	}
	//-----------------------------------------------
	for (int i = 0; i <= TotalTime;i++){
		cout << valueTable [i]<<"  " ;
	}
	cout << endl;
	delete[] time;
	delete[] value;
}

