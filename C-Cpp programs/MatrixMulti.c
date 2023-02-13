#include<stdio.h>


/*void AcceptMatrixValues(int matrix[10][10] , int row , int column)
{
	int i,j;
	printf("\nEnter values :\n");
	
	for( i = 0 ; i < row ; i++)
	{
		for( j = 0 ; j < column ; j++)
		{
			printf("Enter a[%d][%d]:" , i+1 , j+1);
			scanf("%d",&matrix[i][j]);
		}
	}
}*/


int* MatrixMultiplication(int a[][10], int b[][10],int result[][10] , int row1, int column1, int row2 , int column2)
{
	int i,j,k,arr[100];
	
	for (int i = 0; i < row1; ++i) 
	{
	    for (int j = 0; j < column2; ++j) 
		{
	        result[i][j] = 0;
	    }
	}
	for( i = 0 ; i < row1 ; i++)    
	{    
		for( j = 0 ; j < column2 ; j++)    
		{    
			for( k = 0 ; k < column1 ; k++)    
			{    
				result[i][j] += a[i][k]*b[k][j];    
				
			}    
		} 
	}
	k=0;
    for(i=0;i<row1;i++)
    {
	   	for( j=0;j<column2;j++)
	   	{
	   		arr[k++]=result[i][j];
		}
    }
    return arr;
}

void TestMultiplyMatrices(int a[][10],
                      int b[][10],
                      int result[][10],
                      int row1, int column1, int row2, int column2,int expectedOutcome[])
{
    int i,j,count=0;
    int *arr=MatrixMultiplication(a,b,result,row1,column1,row2,column2);
	for(i=0;i<row1*column2;i++)
	{
			if(arr[i]==expectedOutcome[i])
			{
				count++;
			}
			else
			{
				break;
			}
		
	}
	if(count==row1*column2)
	{
		printf("successful\n");
	}
	else
	{
		printf("unsuccessful\n");
		
							}						
}                	
void Display(int result[10][10],int row , int column)
{
	int i,j;
	printf("\nMultiplication is :\n");
	for( i = 0 ; i < row ; i++)    
	{    
		for( j = 0 ; j < column ; j++)    
		{    
			printf("%d\t",result[i][j]);    
		}    
		printf("\n");    
	} 
}

int main()
{
	/*int a[10][10], b[10][10],result[10][10],row1,column1,row2,column2;
	printf("Enter rows and column for first matrix:");
	scanf("%d %d",&row1,&column1);
	printf("Enter rows and column for second matrix:");
	scanf("%d %d",&row2,&column2);
	
	while(column1!=column2)
	{
		printf("Not accepeted! Enter Again\n");
		printf("Enter rows and column for first matrix:");
		scanf("%d %d",&row1,&column1);
		printf("Enter rows and column for second matrix:");
		scanf("%d %d",&row2,&column2);
	}
	AcceptMatrixValues(a ,row1 ,column1);
	
	AcceptMatrixValues(b ,row2 ,column2);
	
	MatrixMultiplication(a,b,result,row1,column1,row2,column2);
	
	Display(result , row1 , column2);*/
	
	FILE* ptr;
    int row1,column1,row2,column2;
    ptr = fopen("matrixMultiFile.txt", "r"); 
    if (ptr == NULL) {
        printf("file can't be opened \n");
    }
    
    fscanf(ptr,"%d",&row1);
     fscanf(ptr,"%d",&column1);
      fscanf(ptr,"%d",&row2);
    fscanf(ptr,"%d",&column2);
    //num=getw(ptr);
	int a[row1][column1],b[row2][column2],result[row1][column2],expected[row1*column2];
	int i,j;
	for(i=0;i<row1;i++)
	{
		for(j=0;j<column1;j++)
		{
			fscanf(ptr,"%d",&a[i][j]);
			printf("%d   ",a[i][j]);
		}
			printf("\n");
	}
	for(i=0;i<row2;i++)
	{
		for(j=0;j<column2;j++)
		{
			fscanf(ptr,"%d",&b[i][j]);
			printf("%d   ",b[i][j]);
		}
			printf("\n");
	}
	for(i=0;i<row1*column2;i++)
	{
			fscanf(ptr,"%d",&expected[i]);
			printf("%d   ",expected[i]);
	}
	TestMultiplyMatrices(a, b, result, row1, column1, row2, column2,expected);
	
    fclose(ptr);
  

   return 0;
	
}

