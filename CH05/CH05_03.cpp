/*
[�ܽd]:��@������C��ƪ��s�J�M���X
*/
#include <iostream>
using namespace std;
int main(void)
{  
	int front,rear,val=0,queue[5]={0};
	front=rear=-1;
	while(rear<5&&val!=-1)
	{  
	    cout<<"�п�J�@�ӭȥH�s�J��C�A�����X�Ƚп�J-2�C(������J-1)�G";
		cin>>val;
		if(val==-2)
		{  
			if(front==rear)
			{  
				cout<<"[��C�w�g�ŤF]"<<endl;
				break;
			}
			front++;
			if (front==5)
				front=0;
			cout<<"���X��C�� ["<<queue[front]<<"]"<<endl;
			queue[front]=0;
		}
		else if(val!=-1 && rear<5)
		{  
			if(rear+1==front || rear==4 && front<=0)
			{  
				cout<<"[��C�w�g���F]"<<endl;
				break;
			}
			rear++;
			if(rear==5)
				rear=0;
			queue[rear]=val;
		}
	}
	cout<<"\n��C�Ѿl��ơG"<<endl;
	if (front==rear)
		cout<<"��C�w��!!"<<endl;
	else 
	{ 
		while(front!=rear)
		{  
			front++;
			if (front==5)
				front=0;
			cout<<"["<<queue[front]<<"]";
			queue[front]=0;
		}
	}
	cout<<endl;
	return 0;
}
