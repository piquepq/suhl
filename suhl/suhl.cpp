// suhl.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "CZLPVector.h"
#include "suhlupdate.h"

int main()
{   
	int ColNum = 5, RowNum = 7;
	suhlupdate suhl(RowNum,ColNum);
	vector<int> perm = { 1,2,3 ,4,5};
	vector<int> permback = { 5,4,3,2,1};
	suhl.copy_perm(perm, permback);
	vector<double> res = { 1,0,0,3,0,6,0 };
	double* aq1=new double[RowNum];
	for (int i = 0; i < res.size(); i++) {
		aq1[i] = res[i];
	}
	CZLPVector aq(7);
	aq.set(aq1, 7);
	suhl.ftranl(aq);
	int position, insertPosition;
	position= suhl.search_last_nonzero_position(aq);
	insertPosition = suhl.search_column(position);
	cout << insertPosition;
	return 0;
}

