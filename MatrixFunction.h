
#ifndef MATRIX_MATRIXFUNCTION_H
#define MATRIX_MATRIXFUNCTION_H
#include <time.h>
#include <iostream>
#define inf 0x7fffffff
//�������ݽṹ
typedef struct {
    double  **mat;
    int      row;
    int      col;
}Matrix;
//һЩ��������
double maxdouble(double x1,double x2);

//�Ծ�����в����ĺ���
void InitialMatrix(Matrix *T,int row,int col);//ֻ����ռ䲻��ʼ����
void InitialMatrixZero(Matrix *T,int row,int col);//��ʼ��Ϊ0
void PrintfMatrix(Matrix *T);//�������
void InitialMatrixRand(Matrix *T,int row, int col);//��ʼ��Ϊ50�������������
void InputMatrix(Matrix *T);	//�����������
void DestroyMatrix(Matrix *T);	//�ͷž���ռ�
Matrix AddMatrix(Matrix *A,Matrix *B);//�����
Matrix MinusMatrix(Matrix *A,Matrix *B); //�����
Matrix MultiMatrix(Matrix *A,Matrix *B); //����˷�

double MeanMatrix(Matrix *T);                 //����Ԫ�ؾ�ֵ
Matrix SubMatrix(Matrix *T,int BeginRow,int BeginCol,int EndRow,int EndCol);            //��T1���Ӿ���
double MaxMatrix(Matrix *T); 		  //����Ԫ�����ֵ
Matrix TransMatrix(Matrix *T); 		//����ת��
Matrix NormMatrix(Matrix *T); 		//�����һ��,����ʵ�ֵ��ǰ��й�һ��
Matrix ReverseMatrix(Matrix *T); //B��A�������



#endif //MATRIX_MATRIXFUNCTION_H
