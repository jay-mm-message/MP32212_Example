#include <iostream>
using namespace std;
int main(void)
{  
	int arr[6][6];//�ŧi�x�}arr
	int data[14][2]={{1,2},{2,1},{1,5},{5,1}, //�ϧΦU�䪺�_�I�Ȥβ��I��
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3},{3,5},{5,3},
					{4,5},{5,4}};
	for (int i=0;i<6;i++)//��x�}�M��0
		for (int j=0;j<6;j++)
			arr[i][j]=0;
	for (int i=0;i<14;i++)//Ū���ϧθ��
		for (int j=0;j<6;j++)//��Jarr�x�}
			for (int k=0;k<6;k++)
			{  
				int tmpi, tmpj;
				tmpi=data[i][0];//tmpi���_�l���I
				tmpj=data[i][1];//tmpj���פ�I
				arr[tmpi][tmpj]=1;//���䪺�I��J1
			}
	cout<<"�L�V�ϧίx�}�G"<<endl;
	for (int i=1;i<6;i++)
	{  
		for (int j=1;j<6;j++)
	    cout<<"["<<arr[i][j]<<"] ";  //�C�L�x�}���e
		cout<<endl;
	}
}
