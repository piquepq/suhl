#include "suhlupdate.h"
#include<vector>
using std::vector;

suhlupdate::suhlupdate(int RowNum,int ColNum):
	RowNum(RowNum), ColNum(ColNum) {
	Steps = 0;
}

void suhlupdate::copy_perm(vector<int> perm, vector<int> permback) {
	this->perm = perm;
	this->permback = permback;
}
void  suhlupdate::copy_L(vector<double> Lvalues, vector<int> Lindex, vector<int> Lstart, vector<double> LRvalues, vector<int> LRindex, vector<int> LRstart) {
	this->Lvalues = Lvalues;
	this->Lindex = Lindex;
	this->Lstart = Lstart;
	this->LRvalues = LRvalues;
	this->LRindex = LRindex;
	this->LRstart = LRstart;
}
void suhlupdate::copy_U(vector<double> Upivotvalues, vector<double> Uvalues, vector<int> Uindex, vector<int> Ustart, vector<int> Uend,vector<double> URvalues, vector<int> URindex, vector<int> URstart, vector<int> URend, vector<int> URspace) {
	this->Upivotvalues = Upivotvalues;
	this->Uvalues = Uvalues;
	this->Uindex = Uindex;
	this->Ustart = Ustart;
	this->Uend = Uend;
	this->URvalues = URvalues;
	this->URindex = URindex;
	this->URstart = URstart;
}
void suhlupdate::btran(CZLPVector &aq) {
	btranu(aq);
	btranl(aq);
}
void suhlupdate::ftran(CZLPVector &aq) {
	ftranl(aq);
	ftranu(aq);
}
void suhlupdate::btranl(CZLPVector&aq) {

}
void suhlupdate::btranu(CZLPVector&aq) {

}
void suhlupdate::ftranl(CZLPVector&aq) {
	printf("hello\n");
}
void suhlupdate::ftranu(CZLPVector&aq) {

}
void suhlupdate::ftranr(CZLPVector &aq) {

}
void suhlupdate::btranr(CZLPVector &aq){

}

int suhlupdate::search_last_nonzero_position(CZLPVector& aq) {
	int i = aq.Array.size()-1;
	while (aq.Array[i] == 0) {
		i--;
	}
	return i;

}
//还要加排除出基出基列
int suhlupdate::search_column(int position) {
	this->Uindex = { 1,0,0,3,0,6,0 };
	this->Uend = { 1,0,0,3,0,6,0 };
	int i = 0;
	for (i = 0; i < RowNum; i++) {
		if (Uindex[Uend[i]] == position)
			break;
	}
	return i;
}


void update(CZLPVector& aq, CZLPVector &ep, int ColOut) {

}