
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#define MAX_LEN 1000

void print_matrix(int**,char* name,int len);


int main(){

        int **a;
        int **b;
        int **c;
        int **c1;
        int i,j,k;
        int len = 10;
        clock_t start,stop;
        int select=0;

        printf("행렬의 크기를 입력하세요 : ");
        scanf("%d",&len);

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

                start=clock();
                mat_add(a,b,c,len);
                stop = clock();

                print_matrix(c,"ADD",len);
                printf("processing time : %f\n",((double)stop-start)/CLOCKS_PER_SEC);
                break;

        case 2:

                start=clock();
                mat_sub(a,b,c,len);
                stop = clock();
                print_matrix(c,"SUB",len);
                printf("processing time : %f\n",((double)stop-start)/CLOCKS_PER_SEC);
                break;

        case 3:

                start=clock();
                if(mat_mul(a,b,c,len) != 0){
                        fprintf(stderr,"Failed to matrix multiplication\n");
                        exit(1);
                }
                stop = clock();
                print_matrix(c,"MUL",len);
                printf("processing time : %f\n",((double)stop-start)/CLOCKS_PER_SEC);

                break;

        case 4:

                start=clock();
                mat_mul(a,b,c1,len);
                mat_inv(c1,c,len);
                stop = clock();
                print_matrix(c,"INVERSE",len);
                printf("processing time : %f\n",((double)stop-start)/CLOCKS_PER_SEC);
                break;

        case 5:
                exit(0);

        default:
                printf("숫자를 입력하지 않았습니다");
        }
        }
        return 0;
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
