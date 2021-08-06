
int mat_add(int** a,int** b,int** c,int len){

        int i,j;
        c[i][j]=0;
                for(i=0;i<len;i++){
                        for(j=0;j<len;j++){
                                        c[i][j]=a[i][j]+b[i][j];
                        }
        }
        return(0);
}
int mat_sub(int** a,int** b,int** c,int len){


        int i,j;
        c[i][j]=0;
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
                                //c[i][k]=a[i][j]+b[i][j] = add matrix
                                c[i][j]=0;
                                for(k=0;k<len;k++){
                                        c[i][j]+=a[i][k]*b[k][j];
                                }
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
