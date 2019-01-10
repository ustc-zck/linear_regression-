#include <stdio.h>

#define M 3764
#define N 2

void main(){

    float data[M][N];
    /*读取文件进入数组*/

    FILE *fp;
    fp = fopen("data.txt", "r");

    if(fp == NULL){
        printf("文件打开失败！\n");
    }
    else{
        printf("读取矩阵！\n");

        for(int i = 0; i < M; i++){

            for(int j = 0; j < N; j++){
                fscanf(fp, "%f", &data[i][j]);
               
            }
        }
       
    }
    /* for(int m = 0; m < M; m++){
        for(int n = 0; n < N; n++){
            printf("%f ", data[m][n]);
        }
        printf("\n");
    }
    */

    /*进行线性回归问题的最小二乘问题的求解，有闭式解*/

    /*
        求x的平均值X_mean, X的平方和X_square_sum, X的和X_sum, 留50个数据作测试集
    */
    float X_sum = 0;
    float X_square_sum = 0;
    float X_mean; 
    
    for(int k = 0; k < M-20; k++){
        X_sum += data[k][0];
        X_square_sum += data[k][0] * data[k][0];
    }
    X_mean = X_sum/(float)(M-20);
    /*printf("%f %f %f", X_sum, X_square_sum, X_mean);*/

    float w, b; /*线性回归 y = w*x + b的系数*/

    float sum_ = 0;
    for(int t = 0; t < M -20; t++){
        sum_ += data[t][1] * (data[t][0] - X_mean);
    }

    w = sum_ / (X_square_sum - X_sum * X_sum / (M-20));
    
    float sum_new = 0;
    for(int p = 0; p < M-20; p++){
        sum_new += data[p][1] - w * data[p][0];
    }
    b = sum_new/(float)(M-20);
    
    /*拟合的直线方程两个参数 w和b*/

    printf("%f %f\n", w ,b);
    
    /*数据集后20组参数作为测试集*/

    for(int i = M-20; i < M; i++){

        printf("%f ", w*data[i][0] + data[i][1]);
        if (i %10 == 0)
            printf("\n");
    }

    printf("\n");

}