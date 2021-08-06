# MATRIX   
행렬 계산하는 프로그램 
***
## 기능 
1. 2X2행렬부터 1000X1000 행렬까지 원하는 다양한 크기의 행렬 생성 가능 
2. 랜덤으로 행렬 생성
3. 행렬 덧셈
4. 행렬 뺼셈
5. 행렬 곱셈
6. 곱셈의 전치 행렬 생성

## 시나리오 
1. **make**
![image](https://user-images.githubusercontent.com/87008955/128462143-35efdf2d-0ba2-44ea-95bd-dcf4dca5504c.png)


2. **프로그램 실행**
![image](https://user-images.githubusercontent.com/87008955/128462172-48a50137-7586-4c7f-aa81-2df6501b3e81.png)


3. **행렬 크기 입력** 
ex) 4x4 행렬
![image](https://user-images.githubusercontent.com/87008955/128462206-9c046a3b-7ba4-4b19-851c-0801893d1e64.png)


4. **원하는 계산 입력** 
  - 덧셈 
 ![image](https://user-images.githubusercontent.com/87008955/128462250-3647e921-ee53-4ee6-9d74-c6ff2e558c05.png)
  
  - 뺼셈
  ![image](https://user-images.githubusercontent.com/87008955/128462284-dbe86426-69cd-42b7-8210-c472e59909aa.png)
  
  - 곱셈
  ![image](https://user-images.githubusercontent.com/87008955/128462329-8e3ff08c-40ff-4cc5-9755-6f1ed29b4a0c.png)
  
  - 전치
 ![image](https://user-images.githubusercontent.com/87008955/128462354-b2e68df6-aa71-4a85-81ba-c74598c77035.png)
 
  - 종료
  ![image](https://user-images.githubusercontent.com/87008955/128462377-7b15334d-2518-4e79-8db4-83c1019958a2.png)

## 프로그램 구성 

1. Makefile 
: 파일 변경을 쉽게 할 수 있도록 make 파일 생성 

2. main.c
: 메인 프로그램 
**주요함수**
- 행렬생성 
```c
        //'입력한 행의 크기 x 4byte x 4byte(int크기)' 크기의 행렬주소공간 생성  
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
        //랜덤행렬을 생성할 수 있도록 시간에 따라 랜덤하게 생성하도록 프로그래밍 
        srandom((unsigned int)time(NULL));
        for(i=0;i<len;i++){
                        for(j=0;j<len;j++){
                                        a[i][j]=(random()%10);
                                        b[i][j]=(random()%10);
                        }
        }
        print_matrix(a,"A",len);
        print_matrix(b,"B",len);
```
- 계산 선택 
while 문을 사용해 여러계산 할수 있도록 설정     
switch~case문을 이용해 원하는 계산을 선택할 수 있도록 설정 

- 행렬 출력
```c
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
```
3.matrix.c
:행렬 계산식만 담아놓은 c파일 
- add
  ```c[i][j]=a[i][j]+b[i][j];```
- sub
  ``` c[i][j]=a[i][j]-b[i][j];```
- mul
  ```c[i][j]+=a[i][k]*b[k][j];```
- inv
  ```dst[j][i]=src[i][j];```
  
4.matrix.h
:함수원형 선언해놓은 헤더파일 





