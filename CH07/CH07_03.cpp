/*
[�ܽd]:�ϥά۾F��C�Ӫ�ܹϧ�(a)��(b)
*/
#include <iostream>
using namespace std;
class list
{
	public:
	int val;
	class list *next;
};
class list head[6];//�ŧi�@�Ӹ`�I���A�}�C
int main(void)
{  
	list *ptr,*newnode;
 	int data[14][2]={{1,2},{2,1},{1,5},{5,1},//�ϧΰ}�C�ŧi
					{2,3},{3,2},{2,4},{4,2},
					{3,4},{4,3},{3,5},{5,3},
					{4,5},{5,4}};
	cout<<"�ϧ�(a)���F����C���e�G"<<endl;
	for (int i=1;i<6;i++)
	{  
		head[i].val=i; //��C��head
		head[i].next=NULL;
		cout<<"���I "<<i<<" =>";	//�⳻�I�ȦC�L�X��
		ptr=&(head[i]);          	//�Ȧs�`�Iptr
		for (int j=0;j<14;j++)      //���X�ϧΰ}�C
		{  
			if (data[j][0]==i)    	//�p�G�`�I��=i�A�[�J�`�I���C��
			{  
				newnode = new list;
    			newnode->val=data[j][1];//�ŧi�s�`�I�A�Ȭ����I��
				newnode->next=NULL;
				while(ptr!=NULL)        //�P�_�O�_����C������
					ptr=ptr->next;
				ptr=newnode;            //�[�J�s�`�I
				cout<<"["<<newnode->val<<"] ";//�C�L�۾F���I
			}
		}   
		cout<<endl;
	}
}
