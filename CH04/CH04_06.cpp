/*
[�ܽd]:�λ��j��ƨD 0-4 ���h����
*/
#include <iostream>
using namespace std;
int recursive(int);  //��ƭ쫬
int main(void)
{  
	for (int i=0;i<5;i++)
		cout<<i<<" ���h�Ȭ� "<<recursive(i)<<endl;   
    return 0;
}
int recursive(int i)
{  
	int sum;
	if(i == 0) //���j�פ����
		return(1);
	else
		sum = i * recursive(i-1); //sum=n*(n-1)!�ҥH�����I�s����
	return sum;
}
