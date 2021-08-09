// thread로 행렬 계산하는 프로그램 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#define MAX_LEN 1000

void print_matrix(int**,char* name,int len);
double wtime();

int main(){

        int **a;
        int **b;
        int **c;
        int **c1;
        int i,j,k;
        int len = 10;
        double start,stop;
        int select=0;

        printf("행렬의 크기를 입력하세요 : ");
        scanf("%d",&len);
        /*
        if(len == 2){
                run_thread = 1; //core count
        }
        else if(len ==3){
                run_thread = 2;
        } else{
                pritnf("Usage:matrix [row][run_thread]\n");
        }*/
        a=(int**)malloc(len * sizeof(int*));
        b=(int**)malloc(len * sizeof(int*));
        c=(int**)malloc(len * sizeof(int*));
        c1=(int**)malloc(len * sizeof(int*));


        for(i=0;i<len;i++){

                        a[i]=(int*)malloc(len * sizeof(int*));
                        b[i]=(int*)malloc(len * sizeof(int*));
                        c[i]=(int*)malloc(len * sizeof(int*));
                        c1[i]=(int*)malloc(len * sizeof(int*));

        }

        srandom((unsigned int)time(NULL));
        for(i=0;i<len;i++){
                        for(j=0;j<len;j++){
                                        a[i][j]=(random()%10);
                                        b[i][j]=(random()%10);
                        }
        }
        print_matrix(a,"A",len);
        print_matrix(b,"B",len);
    while(select!=5){
        printf("========== MATRIX CALCULATE ===========\n");
        printf("=== 1. ADD 2.SUB 3.MUX 4.INV 5.EXIT ===\n");
        printf("입력값 : ");
        scanf("%d",&select);
        switch(select){
        case 1:

                start = wtime();
                mat_add(a,b,c,len);
                stop = wtime();

                print_matrix(c,"ADD",len);
                printf("processing time : %f\n",stop-start);
                break;

        case 2:

                start = wtime();
                mat_sub(a,b,c,len);
                stop = wtime();
                print_matrix(c,"SUB",len);
                printf("processing time : %f\n",stop-start);
                break;

        case 3:

                start=wtime();
                if(mat_mul_th(a,b,c,len) != 0){
                        fprintf(stderr,"Failed to matrix multiplication\n");
                        exit(1);
                }
                print_matrix(c,"MUL",len); //쓰레드로 실행한 곱셈
                stop = wtime();
                printf("processing time : %f\n",stop-start);
                start=wtime();
                if(mat_mul(a,b,c,len) != 0){ //쓰레드를 사용하지 않고 하나의 프로세스에서 실행하는 곱샘
                        fprintf(stderr,"Failed to matrix multiplication\n");
                        exit(1);
                }
                stop = wtime();
                print_matrix(c,"MUL",len);
                printf("processing time : %f\n",stop-start); //쓰레드사용했을 때와 사용안했을때시간비교

                break;

        case 4:

                start=wtime();
                mat_mul(a,b,c1,len);
                mat_inv(c1,c,len);
                stop = wtime();
                print_matrix(c,"INVERSE",len);
                printf("processing time : %f\n",stop-start);
                break;

        case 5:
                exit(0);

        default:
                printf("숫자를 입력하지 않았습니다");
        }
        }
        return 0;
}
double wtime(){
        static int sec = -1;
        struct timeval tv;
        gettimeofday(&tv,NULL);
        if(sec < 0)sec = tv.tv_sec;

        return(tv.tv_sec - sec) + 1.0e-6*tv.tv_usec;
}
void print_matrix(int** matrix, char* name,int len)
{
        int i,j;
        printf("======== %s matrix ========\n",name);
        for(i=0;i<len;i++){
                        for(j=0;j<len;j++){
                                printf("%d ",matrix[i][j]);
                        }
                        printf("\n");
        }

}
