#pragma once
#include<vector>
#include <iostream>
#include "CZLPVector.h"
using std::cout;
using std::endl;
using std::cin;
using std::vector;
class suhlupdate
{public:
	suhlupdate(int RowNum,int ColNum);

	void copy_perm(vector<int> perm, vector<int> permback);
	void copy_L(vector<double> Lvalues, vector<int> Lindex, vector<int> Lstart, vector<double> LRvalues, vector<int> LRindex, vector<int> LRstart);
	void copy_U(vector<double> Upivotvalues,vector<double> Uvalues, vector<int> Uindex, vector<int> Ustart, vector<int> Uend,vector<double> URvalues, vector<int> URindex, vector<int> URstart,vector<int> URend,vector<int> URspace);
	void btran(CZLPVector &aq);
	void ftran(CZLPVector &aq);
	void btranl(CZLPVector&aq);
	void btranu(CZLPVector&aq);
	void ftranl(CZLPVector&aq);
	void ftranu(CZLPVector&aq);
	void ftranr(CZLPVector &aq);
	void btranr(CZLPVector &aq);
	
	int search_last_nonzero_position(CZLPVector& aq);
	//Ѱ����Ҫ���뵽��һ��
	int search_column(int position);

	void update(CZLPVector& aq, CZLPVector &ep,int ColOut);
private:
	//����Ĵ�С
	const int RowNum;
	const int ColNum;
	//Ŀǰ�����˶��ٲ�
	int Steps;
	//�Ƿ���Ҫ���¸���
	bool flag;
	//���о���P
	vector<int> perm;
	vector<int> permback;
	//L����

	vector<double> Lvalues;
	vector<int> Lindex;
	vector<int> Lstart;

	vector<double> LRvalues;
	vector<int> LRindex;
	vector<int> LRstart;

	//U����
	vector<double> Upivotvalues;
	vector<int> Upivotindex;
	vector<int> Upivotlookup;
	vector<double> Uvalues;
	vector<int> Uindex;
	vector<int> Ustart;
	vector<int> Uend;

	vector<double> URvalues;
	vector<int> URindex;
	vector<int> URstart;
	vector<int> URend;
	vector<int> URspace;

	//R����,ÿһ��Ϊһ��eta����
	vector<int> Rvalues;
	vector<int> Rindex;

};

