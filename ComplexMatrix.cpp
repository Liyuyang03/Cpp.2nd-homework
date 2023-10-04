#include "ComplexMatrix2.h"

int main()
{
	int h, row, col;
	cout << "请输入三维矩阵的行数和列数和高:" << endl;
	cin >> row >> col >> h;
	cout << "请输入三维矩阵A:" << endl;
	Matrix_33 am(row, col, h);
	cout << "A" << endl;
	am.disp();
	cout << "请输入三维矩阵B:" << endl;
	Matrix_33 bm(row, col, h);
	cout << "B:" << endl;
	bm.disp();
	int i;
	Matrix_33 cm;
	cout << "C=A+B:" << endl;
	cm = am + bm;
	cm.disp();
	cout << "请输入i显示C[i]，即第i个二维矩阵:" << endl;
	cin >> i;
	cm[i].disp();
	return 0;
}

