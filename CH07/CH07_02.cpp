/*
[�ܽd]:�ϥά۾F�x�}�Ӫ�ܦ��V��
*/
#include <iostream>
using namespace std;
int  main(void)
{  
	int arr[5][5],i,j; //�ŧi�x�}arr
	int data[5][2]={{1,2},{2,1},{2,3},{2,4},{4,3}};//�ϧΦU�䪺�_�I�Ȥβ��I��
	for (i=0;i<5;i++)//��x�}�M��0
		for (j=0;j<5;j++)
			arr[i][j]=0;
	for (i=0;i<5;i++) //Ū���ϧθ��
		for (j=0;j<5;j++) //��Jarr�x�}
		{  
			int tmpi,tmpj;
			tmpi=data[i][0];//tmpi���_�l���I
			tmpj=data[i][1];//tmpj���פ�I
			arr[tmpi][tmpj]=1;//���䪺�I��J1
		}
	cout<<"���V�ϧίx�}�G"<<endl;
	for (i=1;i<5;i++)
	{  
		for (j=1;j<5;j++)
	    cout<<"["<<arr[i][j]<<"] ";//�C�L�x�}���e
		cout<<endl;
	}
}
