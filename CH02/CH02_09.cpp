#include <iostream>
using namespace std;
#define ARRAY_SIZE 5  // �x�}�����Ƥj�p 
int getValue(int ,int);
int A[ARRAY_SIZE][ARRAY_SIZE]={  //�U�T���x�}�����e 
                			{76, 0, 0, 0, 0}, 
               			 	{54, 51, 0, 0, 0}, 
              				{23, 8, 26, 0, 0}, 
                			{43, 35, 28, 18, 0}, 
                			{12, 9, 14, 35, 46}};  
//�@���}�C���}�C�ŧi 
int B[ARRAY_SIZE*(1+ARRAY_SIZE)/2];  
int main()
{
    int i=0,j=0;
    int index;    
		cout<<"=========================================="<<endl;
		cout<<"�U�T���ίx�}�G"<<endl;
		for ( i = 0 ; i < ARRAY_SIZE ; i++ ) 
		{
			for ( j = 0 ; j < ARRAY_SIZE ; j++ ) 
			    cout<<"\t"<<A[i][j];
		    cout<<endl;  
		}
		/* �N���U�T���x�}���Y���@���}�C */
		index=0;
		for ( i = 0 ; i < ARRAY_SIZE ; i++ ) 
		{
			for ( j = 0 ; j < ARRAY_SIZE ; j++ ) 
			{
                if(A[i][j]!=0) B[index++]=A[i][j];
            }
        }
		cout<<"==========================================\n";
		cout<<"�H�@�����覡��ܡG"<<endl;
		cout<<"\t[";
		for ( i = 0 ; i < ARRAY_SIZE ; i++ ) 
		{
			for ( j = i ; j < ARRAY_SIZE ; j++ ) 
		        cout<<" "<<getValue(i,j);
		}
		cout<<" ]";
		cout<<endl;   
}
int getValue(int i, int j) {
        int index = ARRAY_SIZE*i-i*(i+1)/2+j;
        return B[index];
}
