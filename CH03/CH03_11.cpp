/*
[�ܽd]:�N��Ӿǥͦ��Z��C�s���_�ӡA
       �M��C�L�X�s���᪺��C���e
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
class list
{
	public:
 	int num,score;
	char name[10];
	class list *next;
};
typedef class list node;
typedef node *link;
link creat_link(int data[10][2],int num);
void print_link(link head);
link concat(link ptr1,link ptr2);
int main()
{  
	link ptr1,ptr2,ptr;
	int i,data1[6][2],data2[6][2];
	srand(time(NULL));
	for (i=1;i<=6;i++)
	{  
		data1[i-1][0]=i*2-1;
		data1[i-1][1]=rand()%49+52;
		data2[i-1][0]=i*2;
		data2[i-1][1]=rand()%49+52;
	}
	ptr1=creat_link(data1,6);//�إߦ�C1
	ptr2=creat_link(data2,6);//�إߦ�C2
	i=0;
	cout<<"\t\t    �� �l �� �C �� �ơG"<<endl;
	cout<<"\t    �y�� ���Z   �y�� ���Z   �y�� ���Z"<<endl;
	cout<<"\t    =================================="<<endl;
	cout<<"   ��C 1 �G";
	print_link(ptr1);
	cout<<"   ��C 2 �G";
	print_link(ptr2);
	cout<<"\t    =================================="<<endl;
	cout<<"�s�����C�G";
	ptr=concat(ptr1,ptr2);//�s����C
	print_link(ptr);
}
link creat_link(int data[10][2],int num)//�إߦ�C�Ƶ{��
{  
	link head,ptr,newnode;
	for(int i=0;i<num;i++)
	{  
		newnode=new node;
		if(!newnode)
		{  
			cout<<"Error!! �O����t�m����!!"<<endl;
			exit(i);
		}
		if(i==0)//�إߦ�C��
		{  
			newnode->num=data[i][0];
			newnode->score=data[i][1];
			newnode->next=NULL;
			head=newnode;
			ptr=head;
		}
		else //�إߦ�C��L�`�I
		{  
			newnode->num=data[i][0];
			newnode->score=data[i][1];
			newnode->next=NULL;
			ptr->next=newnode;
			ptr=newnode;
		}
		newnode->next=head;
	}
	return ptr;//�^�Ǧ�C
}
void print_link(link head)//�C�L��C�Ƶ{��
{  
	link ptr;
	int i=0;
	ptr=head->next;
	do 
	{  
		cout<<"["<<setw(2)<<ptr->num<<"-"<<setw(3)
            <<ptr->score<<"] -> ";
		i++;
		if(i>=3)//�C��C�L�T�Ӥ���
		{  
			cout<<"\n\t    ";
			i=0;
		}
		ptr=ptr->next;
	}while(ptr!=head->next);
	cout<<endl;
}
link concat(link ptr1,link ptr2)//�s����C�Ƶ{��
{  
	link head;
	head=ptr1->next;//�bptr1��ptr2���A�U����N�@�Ӹ`�I
	ptr1->next=ptr2->next;//���Ӹ`�I��next��էY�i
	ptr2->next=head;
	return ptr2;
}
