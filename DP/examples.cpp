#include "example.h"
#include "main.h"
#include<algorithm>
#include<vector>
//using namespace std;
/*
��̬�滮��n������Ӳ�ң���������ٵ�Ӳ�Ҵճ���ֵΪW��Ǯ
*/
void coinConvert(){
	cout << "Dynamic Programming:Coin problem"<< endl;
	cout << "Please input the number of Coin sort:"<< endl;
	int sort,Total,cost,choosePre;
	cin >> sort;
	int *coin = new int[sort];
	cout << "Please input the sort of Coins in turn:" << endl;
	for (int i = 0; i < sort;i++)
		cin >> coin[i];
	cout <<"Please input the Total:" << endl;
	cin >> Total;
	int *resolution = new int[Total + 1];
	vector<vector<int>> detailAnswer;//��¼ÿһ���ľ���ƴ�շ���
	detailAnswer.resize(Total + 1);
	memset(resolution, INF - 5, sizeof(int)*(Total + 1));//��resolution�����ͳһ���㣬����ԭ����void *memset(void *s,int ch,size_t n);
	resolution[0] = 0;
	for (int i = 1; i <= Total;i++){//Ϊ�����F(Total),������Ҫ���μ����F(0),F(1),F(2),...F(n-1),�Ӷ��Ƶ���F(n)
		cost = INF;
		if (i<coin[0]){
			resolution[i] = 0;
			cout << "i: " << i << " ---> " << resolution[i] << endl;
			continue;
		}
		else
			//������forѭ�����Ǵ�ǰ��sort��pre������ѡ����С���
			for (int j = 0; j < sort; j++){
				if (i >= coin[j])
					//cost =min(cost, resolution[i - coin[j]] + 1);
					//��min()��������࣬����Ϊ�˼�¼ѡ�����Ǹ�pre���ݣ�������Ҫ��if����choosePre��¼��
					if (cost>(resolution[i - coin[j]] + 1)){
						cost = resolution[i - coin[j]] + 1;
						choosePre = coin[j];
					}
			}		

		resolution[i] = cost;
		detailAnswer[i] = detailAnswer[i - choosePre];
		detailAnswer[i].push_back(choosePre);
		cout << "i: " << i << " ---> " << resolution[i]<<"  Details:  ";
		for (int k = 0; k < detailAnswer[i].size();k++){
			cout << detailAnswer[i] [k]<< "  ";
		}
		cout << endl;
	}

	delete[] resolution;
	delete[] coin;
}

/*
���������������
*/
void LIS(){
	cout << "LIS problem" << endl;
	cout << "Please input the length of list:" << endl;
	int len;
	cin >> len;
	int *dataList = new int[len];
	int *maxLength = new int[len];//�洢ÿһ��  �Ը�λ��Ԫ�ؽ�β�����������  �ĳ���
	int MaxIndex;
	vector<vector<int>> itemOfLIS;//�洢ÿһ��  �Ը�λ��Ԫ�ؽ�β�����������  �ľ������Ԫ��
	itemOfLIS.resize(len);
	cout << "Please input the items of dataList in turn:" << endl;
	for (int i = 0; i < len; i++){
		cin >> dataList[i];
		maxLength[i] = 0;//��ʼ����ÿһ��  �Ը�λ��Ԫ�ؽ�β�����������  �ĳ���Ϊ0
	}
	
	int tempmax;
	int tempmaxInd;
	for (int i = 0; i < len;i++){
		tempmax = 0;
		//Ĭ�ϣ����iԪ��С��ǰ���ÿһ��Ԫ�أ���ôֻ���Լ�׷�ӽ��Լ����е����������м��ɣ�����Ϊ1��
		//���iԪ�ش���ǰ���ĳһ��Ԫ�أ���ô���������ѭ���ж�tempmaxInd��tempmax���и���
		tempmaxInd = i;
		//׷��iԪ��ʱ��Ҫ��i֮ǰ��ÿһ��Ԫ�ضԱ�
		for (int j = 0; j < i;j++){
			if (dataList[i]>dataList[j]){
				if (tempmax<maxLength[j]){
					tempmax = maxLength[j];
					tempmaxInd = j;
				}
			}
		}
		maxLength[i] = maxLength[tempmaxInd] + 1;
		itemOfLIS[i] = itemOfLIS[tempmaxInd];
		itemOfLIS[i].push_back(dataList[i]);		
	}

	//----------check the result------------
	for (int i = 0; i < len;i++){
		cout << i+1<<" : "<<maxLength[i]<<"  --  ";
		for (int j = 0; j < itemOfLIS[i].size();j++){
			cout << itemOfLIS[i][j]<<"  ";
		}
		cout << endl;
	}

	delete[] dataList;
	delete[] maxLength;
}
void LIS_optimize_nlogn(){
	cout << "LIS problem" << endl;
	cout << "Please input the length of list:" << endl;
	int len;
	cin >> len;
	int *dataList = new int[len];	
	vector<int> currentLIS;//
	vector<int> finalLIS;
	cout << "Please input the items of dataList in turn:" << endl;
	for (int i = 0; i < len; i++){
		cin >> dataList[i];
	}
	currentLIS.push_back(dataList[0]);
	int top=0,start=0,end;
	for (int i =1; i < len; i++){
		if (dataList[i]>currentLIS[top]){
			currentLIS.push_back(dataList[i]);
			finalLIS = currentLIS;
			top++;
		}
		else{
			start = 0, end = top;
			while (start<=end){

				if (currentLIS[(start + end) / 2]<dataList[i]){
					start = (start + end) / 2+1;
				}
				else{
					end = (start + end) / 2-1;
				}
			}
			currentLIS[start] = dataList[i];
		}
	}
	cout << "The Max Length is: " << top+1 << "  Specific composition: ";
	//----------check the result------------
	for (int i = 0; i <=top; i++){
		cout << "  "<< finalLIS[i];
	}
	cout << endl;
	delete[] dataList;
}
/*
���������������
*/
void LCS_NN(){
	cout <<"Longest Common Subsequence Problem: " << endl;
	cout << "The Length of the first Sequence:"<<endl;
	int len1,len2;
	cin >> len1;
	int* Seq1 = new int[len1];
	cout << "Please input the first Sequence:" << endl;
	for (unsigned int i = 0; i < len1;i++)
		cin>>Seq1[i];
	cout << "The Length of the Second Sequence:" << endl;
	cin >> len2;
	int* Seq2 = new int[len2];
	cout << "Please input the Second Sequence:" << endl;
	for (unsigned int i = 0; i < len2; i++)
		cin >> Seq2[i];

	vector<vector<vector<int>>> DP_Details;
	vector<vector<int>> DP_Number;
	DP_Number.resize(len1);
	DP_Details.resize(len1);
	for (unsigned int i = 0; i < len1; i++){
		DP_Number[i].resize(len2,0);
		DP_Details[i].resize(len2);
	}

	for ( int i = 0; i < len1;i++){
		for ( int j = 0; j < len2; j++){
			if (Seq1[i]==Seq2[j]){
				DP_Number[i][j]=DP_Number[max(0, i - 1)][max(0, j - 1)]+1;
				DP_Details[i][j] = DP_Details[max(0, i - 1)][max(0, j - 1)];
				DP_Details[i][j].push_back(Seq1[i]);
			}
			else{				
				if (DP_Number[max(0, i - 1)][j]>=DP_Number[i][max(0, j - 1)])
					DP_Details[i][j] = DP_Details[max(0, i - 1)][j];
				else
					DP_Details[i][j] = DP_Details[i][max(0, j - 1)];
				DP_Number[i][j] = max(DP_Number[max(0, i - 1)][j], DP_Number[i][max(0, j - 1)]);
			}
		}
	}

	for (unsigned int i = 0; i < len1; i++){
		for (unsigned int j = 0; j < len2; j++){
			cout << DP_Number [i][j]<<"  ";
		}
		cout << endl;
	}
	cout << "The specific commom items is��" << endl;
	for (unsigned int i = 0; i < DP_Details[len1 - 1][len2 - 1].size();i++){
		cout << DP_Details[len1 - 1][len2 - 1][i]<<"  ";
	}
	cout << endl;

	delete[] Seq1;
	delete[] Seq2;
}
/*
��������ȫ���е����飬��nlogn�ĸ��Ӷ���������������
3 1 2 4 5
2 5 4 1 3
*/
void LCS_nlogn(){
	cout << "LCS-nlogn:��������ȫ��������"<< endl;
	cout << "Please input the length of Array:"<< endl;
	int number;
	cin >> number;
	int* A_arr = new int[number+1];
	int* B_arr = new int[number+1];
	int* map = new int[number+1];
	vector<int> LCS_array;
	//vector<int> commonSubseq;
	cout << "Please input A array:"<< endl;
	for (int i = 1; i <= number;i++){
		cin >> A_arr[i];
		map[A_arr[i]] =i ;
	}
	cout << "Please input B array:" << endl;
	for (int i = 1; i <= number; i++){
		cin >> B_arr[i];
	}
	int len = 0,start,end,mid;
	for (int i = 1; i <= number; i++){
		if (LCS_array.size()==0){
			LCS_array.push_back(map[B_arr[i]]);
			//commonSubseq = LCS_array;
			len++;
		}
		else{
			if (map[B_arr[i]]>LCS_array[len-1]){
				LCS_array.push_back(map[B_arr[i]]);
				//commonSubseq = LCS_array;
				len++;
			}
			else{
				start = 0;
				end = len-1;
				mid = (start + end) / 2;
				while (start <= end){
					if (LCS_array[mid] < map[B_arr[i]]){
						start = mid + 1;
						mid = (start + end) / 2;
					}
					else{
						end = mid - 1;
						mid = (start + end) / 2;
					}
				}
				LCS_array[mid] = map[B_arr[i]];
			}
		}
	}

	cout << "The Common Subsequence Length is: "<<len<< endl;
	delete[] A_arr;
	delete[] B_arr;
	delete[] map;
}
