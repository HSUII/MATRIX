
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int mat_add(int** a,int** b,int** c,int len){

        int i,j;
                for(i=0;i<len;i++){
                        for(j=0;j<len;j++){
                                        c[i][j]=a[i][j]+b[i][j];
                        }
        }
        return(0);
}
int mat_sub(int** a,int** b,int** c,int len){

        int i,j;
                for(i=0;i<len;i++){
                        for(j=0;j<len;j++){
                                        c[i][j]=a[i][j]-b[i][j];
                        }
        }
        return(0);

}
int mat_mul(int** a,int** b,int** c,int len){
        int i,j,k;
                for(i=0;i<len;i++){
                        for(j=0;j<len;j++){
                                c[i][j]=0;
                                for(k=0;k<len;k++){
                                        c[i][j]+=a[i][k]*b[k][j];
                                }
                        }
        }
        return(0);
}
typedef struct{
        int i;
        int** a;
        int** b;
        int** c;
        int len;
}matmul_arg_t;


//int mat_mul_th_kernel(int i,int** a,int** b,int** c,int len)
void *mat_mul_th_kernel(void *arg)
{
                int j,k;
                matmul_arg_t *parg =(matmul_arg_t*)arg;
                int i = parg->i;
                int **a = parg->a;
                int **b = parg->b;
                int **c = parg->c;
                int len = parg->len;

                for(j=0;j<len;j++){
                        c[i][j]=0;
                        for(k=0;k<len;k++){
                        c[i][j]+=a[i][k]*b[k][j];
                        }
                }
}
int mat_mul_th(int** a,int** b,int** c,int len){

        int                              i,j,k,res;
        matmul_arg_t     *arg;
        pthread_t                *a_thread;
        void                     *thread_result;

        a_thread = (pthread_t*)malloc(sizeof(pthread_t) * len);

        for(i=0;i<len;i++){
                        arg = (matmul_arg_t*)malloc(sizeof(matmul_arg_t));
                        arg->i = i;
                        arg->a = a;
                        arg->b = b;
                        arg->c = c;
                        arg->len = len;
                        res = pthread_create(a_thread+i, NULL, mat_mul_th_kernel,(void*)arg);
                        if(res !=0){
                                perror("thread creation failed");
                                exit(EXIT_FAILURE);
                        }
        }
        for(i=0;i<len;i++){
                res = pthread_join(a_thread[i], &thread_result);
                if(res !=0){
                                perror("thread join failed");
                                exit(EXIT_FAILURE);
                }

        }
        return(0);
}


//0:success
//1:inverse matrix isnt existed

int mat_inv(int** src,int** dst,int len){

                int i,j;
                for(i=0;i<len;i++){
                        for(j=0;j<len;j++){
                                        dst[j][i]=src[i][j];
                        }
        }
                return(0);
}
