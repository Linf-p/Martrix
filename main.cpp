#include <iostream>
#include <time.h>
#include "MatrixFunction.h"


int main() {
    if (0)
    {
//    //���Ծ�ֵ
//    printf("����MeanMatrix-----------------\n");
//    Matrix A ;
//    InitialMatrixRand(&A,2,2);
//    PrintfMatrix(&A);
//    double mean=MeanMatrix(&A);
//    printf("Mean = %.3lf\n",mean);
//    DestroyMatrix(&A);
//
//    //�����Ӿ���
//    printf("����SubMatrix-----------------\n");
//    Matrix Sub;
//    InitialMatrixRand(&A,5,5);
//    PrintfMatrix(&A);
//    Sub =SubMatrix(&A,3,3,4,4);
//    PrintfMatrix(&Sub);
//    DestroyMatrix(&Sub);
//
//    //�������ֵ
//    printf("����MaxMatrix-----------------\n");
//    InitialMatrixRand(&A,3,3);
//    double maxnum = MaxMatrix(&A);
//    PrintfMatrix(&A);
//    printf("Maxnum = %.3lf\n",maxnum);
//
//    //���Ծ���ת��
//    printf("����TransMatrix-----------------\n");
//    InitialMatrixRand(&A,3,2);
//    Matrix  TA =  TransMatrix(&A);
//    PrintfMatrix(&A);
//    PrintfMatrix(&TA);
//    DestroyMatrix(&TA);
//
//    //���Ծ����һ��������ʵ�ֵ��ǰ��й�һ��
//    printf("����NormMatrix-----------------\n");
//    InitialMatrixRand(&A,3,3);
//    PrintfMatrix(&A);
//    A = NormMatrix(&A);
//    PrintfMatrix(&A);
//
//    //���Ծ�������
//    printf("����ReverseMatrix-----------------\n");
//    InitialMatrix(&A,3,3);
//    A.mat[0][0]=16;A.mat[0][1]=25;A.mat[0][2]=19;
//    A.mat[1][0]=3;A.mat[1][1]=40;A.mat[1][2]=40;
//    A.mat[2][0]=41;A.mat[2][1]=44;A.mat[2][2]=7;
//    Matrix rA=ReverseMatrix(&A);
//    PrintfMatrix(&A);
//    PrintfMatrix(&rA);
//    Matrix I = MultiMatrix(&A,&rA);
//    PrintfMatrix(&I);
    }
    printf(
            "���������ԣ���ѡ���ܣ������Ӧ�����֣�\n"
            "***************************************************\n"
            "1.����һ������������ֵ��\n"
            "2.����һ�����������������ֵ��\n"
            "3.�������������������ͣ�\n"
            "4.�������������������\n"
            "5.����������������������\n"
            "6.������������������������ͣ�\n"
            "7.������������������������\n"
            "8.���������������������������\n"
            "9.����������������2-4�У�1-3�е�����\n"
            "10.����һ�����������Ԫ�ص����ֵ��\n"
            "11.����һ����������������Ԫ�ص����ֵ��\n"
            "12.����һ�����������ת�ã�\n"
            "13.����һ����������������ת�ã�\n"
            "14.����һ������������һ����\n"
            "15.����һ�����������������һ����\n"
            "16.����һ�������������棻\n"
            "17.����һ������������������棻\n"
            "0������!");

    bool exitflag= false;
    while (!exitflag)    //����0ʱ��exitflag��Ϊtrue
    {
        int caseValue;
        int n,m;
        Matrix A,B,C;
        scanf("%d", &caseValue);   //���������caseValue�жϽ����������
        switch (caseValue) {
            case 1:
                printf("��ֱ�������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("Mean=%lf\n", MeanMatrix(&A));
                break;
            case 2:
                printf("��ֱ�������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&A);
                printf("Mean=%lf\n", MeanMatrix(&A));
                break;
            case 3:
                printf("�������һ�����������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("������ڶ������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&B,n,m);
                InputMatrix(&B);
                C = AddMatrix(&A,&B);
                PrintfMatrix(&C);
                break;
            case 4:
                printf("�������һ�����������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("������ڶ������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&B,n,m);
                InputMatrix(&B);
                C = MinusMatrix(&A,&B);
                PrintfMatrix(&C);
                break;
            case 5:
                printf("�������һ�����������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("������ڶ������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&B,n,m);
                InputMatrix(&B);
                C = MultiMatrix(&A,&B);
                PrintfMatrix(&C);
                break;
            case 6:
                printf("�������һ�����������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&A);
                printf("������ڶ������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&B,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&B);
                C = AddMatrix(&A,&B);
                printf("A+B:\n");
                PrintfMatrix(&C);
                break;
            case 7:
                printf("�������һ�����������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&A);
                printf("������ڶ������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&B,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&B);
                C = MinusMatrix(&A,&B);
                printf("A-B:\n");
                PrintfMatrix(&C);
                break;
            case 8:
                printf("�������һ�����������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&A);
                printf("������ڶ������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&B,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&B);
                C = MultiMatrix(&A,&B);
                printf("A*B:\n");
                PrintfMatrix(&C);
                break;
            case 9:
                printf("����SubMatrix-----------------\n");
                Matrix Sub;
                InitialMatrixRand(&A,5,5);
                PrintfMatrix(&A);
                Sub =SubMatrix(&A,2,1,4,3);
                printf("SubMatrix:\n");
                PrintfMatrix(&Sub);
                DestroyMatrix(&Sub);
                break;
            case 10:
                printf("��ֱ�������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("Max=%lf\n", MaxMatrix(&A));
                break;
            case 11:
                printf("��ֱ�����Ҫ������������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&A);
                printf("Max=%lf\n", MaxMatrix(&A));
                break;
            case 12:
                printf("��ֱ�������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("Transposed matrix=\n");
                C =TransMatrix(&A);
                PrintfMatrix(&C);
                break;
            case 13:
                printf("��ֱ�����Ҫ������������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Original Matrix=\n");
                PrintfMatrix(&A);
                C =TransMatrix(&A);
                PrintfMatrix(&C);
                break;
            case 14:
                printf("��ֱ�������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("Normalized matrix=\n");
                C =NormMatrix(&A);
                PrintfMatrix(&C);
                break;
            case 15:
                printf("��ֱ�������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Original Matrix=\n");
                PrintfMatrix(&A);
                printf("Normalized matrix=\n");
                C =NormMatrix(&A);
                PrintfMatrix(&C);
                break;
            case 16:
                printf("��ֱ�������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("Reversed Matrix=\n");
                C =  ReverseMatrix(&A);
                PrintfMatrix(&C);
                break;
            case 17:
                printf("��ֱ�����Ҫ������������������n������m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Original Matrix=\n");
                PrintfMatrix(&A);
                printf("Reversed Matrix=\n");
                C =  ReverseMatrix(&A);
                PrintfMatrix(&C);
            case 0:
                exitflag = true;
        }
    }
    return 0;
}
