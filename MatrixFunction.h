
#ifndef MATRIX_MATRIXFUNCTION_H
#define MATRIX_MATRIXFUNCTION_H
#include <time.h>
#include <iostream>
#define inf 0x7fffffff
//矩阵数据结构
typedef struct {
    double  **mat;
    int      row;
    int      col;
}Matrix;
//一些辅助函数
double maxdouble(double x1,double x2);

//对矩阵进行操作的函数
void InitialMatrix(Matrix *T,int row,int col);//只分配空间不初始化；
void InitialMatrixZero(Matrix *T,int row,int col);//初始化为0
void PrintfMatrix(Matrix *T);//输出矩阵
void InitialMatrixRand(Matrix *T,int row, int col);//初始化为50以内随机正整数
void InputMatrix(Matrix *T);	//键盘输入矩阵
void DestroyMatrix(Matrix *T);	//释放矩阵空间
Matrix AddMatrix(Matrix *A,Matrix *B);//矩阵加
Matrix MinusMatrix(Matrix *A,Matrix *B); //矩阵减
Matrix MultiMatrix(Matrix *A,Matrix *B); //矩阵乘法

double MeanMatrix(Matrix *T);                 //矩阵元素均值
Matrix SubMatrix(Matrix *T,int BeginRow,int BeginCol,int EndRow,int EndCol);            //求T1的子矩阵
double MaxMatrix(Matrix *T); 		  //矩阵元素最大值
Matrix TransMatrix(Matrix *T); 		//矩阵转置
Matrix NormMatrix(Matrix *T); 		//矩阵归一化,这里实现的是按行归一化
Matrix ReverseMatrix(Matrix *T); //B是A的逆矩阵



#endif //MATRIX_MATRIXFUNCTION_H
