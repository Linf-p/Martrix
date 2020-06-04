#include <iostream>
#include <time.h>
#include "MatrixFunction.h"


int main() {
    if (0)
    {
//    //测试均值
//    printf("测试MeanMatrix-----------------\n");
//    Matrix A ;
//    InitialMatrixRand(&A,2,2);
//    PrintfMatrix(&A);
//    double mean=MeanMatrix(&A);
//    printf("Mean = %.3lf\n",mean);
//    DestroyMatrix(&A);
//
//    //测试子矩阵
//    printf("测试SubMatrix-----------------\n");
//    Matrix Sub;
//    InitialMatrixRand(&A,5,5);
//    PrintfMatrix(&A);
//    Sub =SubMatrix(&A,3,3,4,4);
//    PrintfMatrix(&Sub);
//    DestroyMatrix(&Sub);
//
//    //测试最大值
//    printf("测试MaxMatrix-----------------\n");
//    InitialMatrixRand(&A,3,3);
//    double maxnum = MaxMatrix(&A);
//    PrintfMatrix(&A);
//    printf("Maxnum = %.3lf\n",maxnum);
//
//    //测试矩阵转置
//    printf("测试TransMatrix-----------------\n");
//    InitialMatrixRand(&A,3,2);
//    Matrix  TA =  TransMatrix(&A);
//    PrintfMatrix(&A);
//    PrintfMatrix(&TA);
//    DestroyMatrix(&TA);
//
//    //测试矩阵归一化，这里实现的是按行归一化
//    printf("测试NormMatrix-----------------\n");
//    InitialMatrixRand(&A,3,3);
//    PrintfMatrix(&A);
//    A = NormMatrix(&A);
//    PrintfMatrix(&A);
//
//    //测试矩阵求逆
//    printf("测试ReverseMatrix-----------------\n");
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
            "矩阵函数测试，请选择功能，输入对应的数字：\n"
            "***************************************************\n"
            "1.输入一个矩阵，求矩阵均值；\n"
            "2.产生一个随机数矩阵，求矩阵均值；\n"
            "3.输入两个个矩阵，求矩阵和；\n"
            "4.输入两个个矩阵，求矩阵差；\n"
            "5.输入两个个矩阵，求矩阵积；\n"
            "6.产生两个个随机数矩阵，求矩阵和；\n"
            "7.产生两个个随机数矩阵，求矩阵差；\n"
            "8.产生两个个随机数矩阵，求矩阵积；\n"
            "9.求矩阵的子阵，如矩阵的2-4行，1-3列的子阵；\n"
            "10.输入一个矩阵，求矩阵元素的最大值；\n"
            "11.产生一个随机数矩阵，求矩阵元素的最大值；\n"
            "12.输入一个矩阵，求矩阵转置；\n"
            "13.产生一个随机数矩阵，求矩阵转置；\n"
            "14.输入一个矩阵，求矩阵归一化；\n"
            "15.产生一个随机数矩阵，求矩阵归一化；\n"
            "16.输入一个矩阵，求矩阵的逆；\n"
            "17.产生一个随机数矩阵，求矩阵的逆；\n"
            "0：结束!");

    bool exitflag= false;
    while (!exitflag)    //输入0时将exitflag置为true
    {
        int caseValue;
        int n,m;
        Matrix A,B,C;
        scanf("%d", &caseValue);   //根据输入的caseValue判断进行哪项测试
        switch (caseValue) {
            case 1:
                printf("请分别输入矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("Mean=%lf\n", MeanMatrix(&A));
                break;
            case 2:
                printf("请分别输入矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&A);
                printf("Mean=%lf\n", MeanMatrix(&A));
                break;
            case 3:
                printf("请输入第一个矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("请输入第二个矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&B,n,m);
                InputMatrix(&B);
                C = AddMatrix(&A,&B);
                PrintfMatrix(&C);
                break;
            case 4:
                printf("请输入第一个矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("请输入第二个矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&B,n,m);
                InputMatrix(&B);
                C = MinusMatrix(&A,&B);
                PrintfMatrix(&C);
                break;
            case 5:
                printf("请输入第一个矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("请输入第二个矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&B,n,m);
                InputMatrix(&B);
                C = MultiMatrix(&A,&B);
                PrintfMatrix(&C);
                break;
            case 6:
                printf("请输入第一个矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&A);
                printf("请输入第二个矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&B,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&B);
                C = AddMatrix(&A,&B);
                printf("A+B:\n");
                PrintfMatrix(&C);
                break;
            case 7:
                printf("请输入第一个矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&A);
                printf("请输入第二个矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&B,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&B);
                C = MinusMatrix(&A,&B);
                printf("A-B:\n");
                PrintfMatrix(&C);
                break;
            case 8:
                printf("请输入第一个矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&A);
                printf("请输入第二个矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&B,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&B);
                C = MultiMatrix(&A,&B);
                printf("A*B:\n");
                PrintfMatrix(&C);
                break;
            case 9:
                printf("测试SubMatrix-----------------\n");
                Matrix Sub;
                InitialMatrixRand(&A,5,5);
                PrintfMatrix(&A);
                Sub =SubMatrix(&A,2,1,4,3);
                printf("SubMatrix:\n");
                PrintfMatrix(&Sub);
                DestroyMatrix(&Sub);
                break;
            case 10:
                printf("请分别输入矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("Max=%lf\n", MaxMatrix(&A));
                break;
            case 11:
                printf("请分别输入要产生的随机矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Matrix=\n");
                PrintfMatrix(&A);
                printf("Max=%lf\n", MaxMatrix(&A));
                break;
            case 12:
                printf("请分别输入矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("Transposed matrix=\n");
                C =TransMatrix(&A);
                PrintfMatrix(&C);
                break;
            case 13:
                printf("请分别输入要产生的随机矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Original Matrix=\n");
                PrintfMatrix(&A);
                C =TransMatrix(&A);
                PrintfMatrix(&C);
                break;
            case 14:
                printf("请分别输入矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("Normalized matrix=\n");
                C =NormMatrix(&A);
                PrintfMatrix(&C);
                break;
            case 15:
                printf("请分别输入矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrixRand(&A,n,m);
                printf("Original Matrix=\n");
                PrintfMatrix(&A);
                printf("Normalized matrix=\n");
                C =NormMatrix(&A);
                PrintfMatrix(&C);
                break;
            case 16:
                printf("请分别输入矩阵的行数n，列数m\n");
                scanf("%d%d",&n,&m);
                InitialMatrix(&A,n,m);
                InputMatrix(&A);
                printf("Reversed Matrix=\n");
                C =  ReverseMatrix(&A);
                PrintfMatrix(&C);
                break;
            case 17:
                printf("请分别输入要产生的随机矩阵的行数n，列数m\n");
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
