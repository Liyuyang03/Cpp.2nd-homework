#pragma once

//#include<stdlib.h>// 用于退出程序
#include <iostream>
#include <complex>
#include <vector>
using namespace std;

class Matrix_33// 设立一个矩阵类
{
private:
	int h, row, col;
	vector< vector < vector<complex<double>> > > res;
public:
	Matrix_33();
	Matrix_33(int r, int c, int h);
//	Matrix_33(const Matrix_33& m);
//	~Matrix_33();
	void disp();//展示矩阵
	friend   Matrix_33 operator + (const Matrix_33& am, const Matrix_33& bm);// 加法运算符的重载
	Matrix_33& operator = (const Matrix_33& a);// “=”运算符的重载
	Matrix_33 operator [] (int i);// []运算符的重载
};

Matrix_33::Matrix_33()//初始化
{
	this->h = 1;
	this->row = 1;
	this->col = 1;
//	this->res = new complex<double>**();
}
//Matrix_33::~Matrix_33()//释放内存
//{
//	delete res;
//}

Matrix_33::Matrix_33(int r, int c, int h)//输入函数
{
	double real, imag;
	this->row = r;
	this->col = c;
	this->h = h;
	/*res = new complex<double>**[h];
	for (int i = 0; i < h; i++)
		for (int j = 0; j < c; j++)
		{
			res[i] = new complex<double>*[c];
			{
				res[i][j] = new complex<double>[r];
			} 
		}
	for (int i = 0; i < h; i++)
		for (int j = 0; j < c; j++)
			for (int k = 0; k < r; k++)
			{
				{
					{
						cout << "请输入第" << (i + 1) * (j + 1) * (k + 1) << "个元素实部：" << endl;
						cin >> real;
						cout << "请输入第" << (i + 1) * (j + 1) * (k + 1) << "个元素虚部：" << endl;
						cin >> imag;
						res[i][j][k] =complex<double>(1,2);
					}
				}
			}*/
	vector< vector < vector<complex<double>> > > res(h, vector< vector<complex<double>> >(c, vector<complex<double>>(r, 0)));
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
		{
			for (int k = 0; k < res[0][0].size(); k++)
			{
				cout << "请输入第" << (i * r * c) +  (j * r) + (k + 1) << "个元素实部：" << endl;
				cin >> real;
				cout << "请输入第" << (i * r * c) +  (j * r) + (k + 1) << "个元素虚部：" << endl;
				cin >> imag;
				res[i][j][k] = complex<double>(real, imag);
			}
			cout << endl;
		}
		cout << endl;
	}
	this->res = res;
	cout << "初始化完成";
}

/*Matrix_33::Matrix_33(const Matrix_33& m_33)// 当加法运算符重载函数被调用时，会调用复制构造函数，由于数据成
{                              // 员有指针，因此为了防止析构函数调用时发生错误，设立一个复制构造函数
	h = m_33.h;
	row = m_33.row;
	col = m_33.col;
	res = m_33.res;
	if (!res)// 当指针未被赋值时，指针被赋予随机数，或当指针被赋值后，通过此语句指针也可以被删除调 
		delete res;// 空间,从而去使用新的空间
	for (int j = 0; j < h; j++)
	{
		res[j].row = row;
		res[j].col = col;
		res[j].p = new complex<double>();
		res[j] = m_33.res[j];
	}
}*/

void Matrix_33::disp()
{
	for (int i = 0; i < h; i++)
	{
		cout << "该三维矩阵的第" << i << "个" << col << '*' << row << "阶二维矩阵:" << endl;

		for (int c = 0; c < col; c++)
		{
			for (int r = 0; r < row; r++)
			{
				cout << '\t';
				cout << res[i][c][r];
			}
			cout << endl;
		}
		cout << endl;
	}
}

Matrix_33 operator + (const Matrix_33& am, const Matrix_33& bm)
{
	if (am.h == bm.h)
	{
		int r=am.row, c=am.col, h=am.h;
		Matrix_33 temp;
		temp.h = am.h;
		temp.row = am.row;
		temp.col = am.col;
		temp.res = am.res;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < c; j++)
			{
				for (int k = 0; k < r; k++)
				{
					temp.res[i][j][k] = am.res[i][j][k] + bm.res[i][j][k];
				}
			}
		}
		return temp;
	}
}

Matrix_33 Matrix_33::operator [] (int i)
{
	Matrix_33 temp;
	row = this->row;
	col = this->col;
	temp.h = 1;
	temp.row = row;
	temp.col = col;
	vector< vector < vector<complex<double>> > > res(1, vector< vector<complex<double>> >(col, vector<complex<double>>(row, 0)));
	for (int c = 0; c < col; c++)
	{ 
		for (int r = 0; r < row; r++)
		{
			res[0][c][r] = this->res[i][c][r];
		}
	}
	temp.res = res;
	return temp;
}

Matrix_33& Matrix_33::operator = (const Matrix_33& bm)
{
	int h = bm.h;
	int row = bm.row;
	int col = bm.col;
	this->h = h;
	this->row = row;
	this->col = col;
	vector< vector < vector<complex<double>> > > res(h, vector< vector<complex<double>> >(col, vector<complex<double>>(row, 0)));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < row; k++)
			{
				res[i][j][k] = bm.res[i][j][k];
			}
		}

	}
	this->res = res;
	return *this;
}
