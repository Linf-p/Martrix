#include <cmath>
#include "MatrixFunction.h"
//一些辅助函数
double maxdouble(double x1, double x2) {
    return x1>x2 ? x1:x2;
}

//操作矩阵的函数
void InitialMatrix(Matrix *T, int row, int col) {
    if (row>0&&col>0) {
        T->row = row;
        T->col = col;
        T->mat = (double**)malloc(sizeof(double*)*row);
        for (int i=0;i<row;i++)
            T->mat[i] = (double*) malloc(col*sizeof(double ));
    }else{printf("Parameter row or col is wrong! \n");}
}

void InitialMatrixZero(Matrix *T, int row, int col) {
    if (row>0&&col>0) {
        T->row = row;
        T->col = col;
        T->mat = (double**)malloc(sizeof(double*)*row);
        for (int i=0;i<row;i++)
            T->mat[i] = (double*) malloc(col*sizeof(double ));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col ; ++j) {
                T->mat[i][j]=0;
            }
        }
    }else{printf("Parameter row or col is wrong! \n");}
}

void PrintfMatrix(Matrix *T) {
    for (int i = 0; i <T->row ; ++i) {
        for (int j = 0; j <T->col; ++j) {
            printf("%.3lf  ",T->mat[i][j]);
        }
        printf("\n");
    }
}

void InitialMatrixRand(Matrix *T, int row, int col) {
    srand((unsigned)time(NULL));   //获得随机数种子
    if (row>0&&col>0) {
        T->row = row;
        T->col = col;
        T->mat = (double**)malloc(sizeof(double*)*row);
        for (int i=0;i<row;i++)
            T->mat[i] = (double*) malloc(col*sizeof(double ));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col ; ++j) {
                T->mat[i][j]=rand()%51;
            }
        }
    } else{printf("Parameter row or col is wrong! \n");}

}

void InputMatrix(Matrix *T) {
    printf("Please enter a Matrix. \n");
    for (int i = 0; i < T->row; ++i) {
        for (int j = 0; j < T->col ; ++j) {
            scanf("%lf",&T->mat[i][j]);
        }
    }
}

void DestroyMatrix(Matrix *T) {
    for (int i = 0; i < T->row; ++i) {
        free(T->mat[i]);
    }
    free(T->mat);
}

Matrix AddMatrix(Matrix *A, Matrix *B) {
    if (A->row==B->row&&A->col==B->col)
    {
        Matrix C;
        InitialMatrix(&C,A->row,A->col);
        for (int i = 0; i < A->row; ++i) {
            for (int j = 0; j < A->col ; ++j) {
                C.mat[i][j] = A->mat[i][j]+B->mat[i][j];
            }
        }
        return C;
    } else{printf("These two matrices cannot be added together!");}
}

Matrix MinusMatrix(Matrix *A, Matrix *B) {
    if (A->row==B->row&&A->col==B->col)
    {
        Matrix C;
        InitialMatrix(&C,A->row,A->col);
        for (int i = 0; i < A->row; ++i) {
            for (int j = 0; j < A->col ; ++j) {
                C.mat[i][j] = A->mat[i][j]-B->mat[i][j];
            }
        }
        return C;
    } else{printf("These two matrices cannot be subtracted!");}
}

Matrix MultiMatrix(Matrix *A, Matrix *B) {
    if (A->col==B->row)
    {
        Matrix C;
        InitialMatrixZero(&C,A->row,B->col);
        for (int i = 0; i <A->row ; ++i) {
            for (int j = 0; j < B->col ; ++j) {
                for (int k = 0; k <A->col ; ++k) {
                    C.mat[i][j] += A->mat[i][k]*B->mat[k][j];
                }
            }
        }
        return C;
    } else{printf("These two matrices cannot be multiplied");}
}

double MeanMatrix(Matrix *T) {
    double mean=0;
    for (int i = 0; i < T->row; ++i) {
        for (int j = 0; j < T->col ; ++j) {
            mean+= T->mat[i][j];
        }
    }
    mean /=T->row*T->col;
    return mean;
}

Matrix SubMatrix(Matrix *T,  int BeginRow, int BeginCol, int EndRow, int EndCol) {
    if (BeginRow<=EndRow&&BeginCol<=EndCol)
    {
        BeginCol-=1;BeginRow-=1;EndCol-=1;EndRow-=1;  //人对矩阵的认识从1开始，计算机中从0开始，因此需要减1
        Matrix C;
        InitialMatrix(&C,(EndRow-BeginRow)+1,(EndCol-BeginCol)+1);
        for (int i = 0; i <C.row ; ++i) {
            for (int j = 0; j <C.col  ; ++j) {
                C.mat[i][j] = T->mat[i+BeginRow][j+BeginCol];
            }
        }
        return C;
    } else{printf("Make sure Begin < End !\n");}

}


double MaxMatrix(Matrix *T) {
    double ans = -inf;
    for (int i = 0; i < T->row; ++i) {
        for (int j = 0; j < T->col ; ++j) {
            ans  =  maxdouble(ans,T->mat[i][j]);
        }
    }
    return ans;
}

Matrix TransMatrix(Matrix *T) {
    Matrix C;
    InitialMatrix(&C,T->col,T->row);
    for (int i = 0; i < C.row; ++i) {
        for (int j = 0; j < C.col ; ++j) {
            C.mat[i][j]=T->mat[j][i];
        }
    }
    return C;
}

//矩阵归一化,这里实现的是按行归一化
Matrix NormMatrix(Matrix *T) {
    Matrix C;
    InitialMatrix(&C,T->row,T->col);
    for (int i = 0; i < C.row; ++i) {
        double temp =0;
        for (int j = 0; j < C.col ; ++j) {
            temp+=T->mat[i][j]*T->mat[i][j];
        }
        temp =sqrt(temp);
        for (int j = 0; j < C.col ; ++j) {
            C.mat[i][j]=T->mat[i][j]/temp;
        }
    }
    return C;
}

//利用高斯消元法实现矩阵求逆
Matrix ReverseMatrix(Matrix *T) {
    //flag标记该矩阵是否可逆
    bool flag = true;
    //先产生一个双倍长的矩阵，后半部分是单位阵
    Matrix C;
    InitialMatrix(&C,T->row,2*T->col);
    for (int i = 0; i < C.row ; ++i) {
        for (int j = 0; j <C.col ; ++j) {
            if (j<T->col)
            {
                C.mat[i][j]=T->mat[i][j];
            } else{//后半部分是单位阵
                if (i == j-T->col) C.mat[i][j] = 1;
                else C.mat[i][j] = 0;
            }
        }
    }
    for (int i=0;i<C.row;i++)
    {
        //找出第i列中最大的元素作为主元
        double tmax = C.mat[i][i];
        int k =i;
        for (int j = i+1; j <T->row ; ++j) {
            if (fabs(C.mat[j][i])>fabs(tmax))
            {
                tmax =C.mat[j][i];
                k = j;
            }
        }
        //如果主元为0，则说明A不是满秩矩阵，不存在逆矩阵
        if (tmax!=0){
            if (k!=i){  //若主元不在第i行，将主元交换到i行
                double temp ;
                for (int j = 0; j < C.col; ++j) {
                    temp = C.mat[k][j];
                    C.mat[k][j] = C.mat[i][j];
                    C.mat[i][j] = temp;
                }
            }
            //消去A的第i列除去i行以外的各行元素
            for (int j = 0; j <C.col ; ++j) {
                C.mat[i][j]/=tmax;
            }
            for (int j = 0; j <C.row ; ++j) {
                if (j!=i)
                {
                    double temp =C.mat[j][i];  //C的第j行的每一项都要减去C.mat[j][i]/1  （1即为C.mat[i][i]）
                    for (int u = 0; u <C.col ; ++u) {
                        C.mat[j][u]-=C.mat[i][u]*temp;
                    }
                }
            }
        } else{flag = false;
            break;}


    }

    if (flag){
        //取C的后一半返回
        return SubMatrix(&C,1,T->row+1,C.row,C.col);
    } else{
        printf("Can't be Reversed!");
    }


}


