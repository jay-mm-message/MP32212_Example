#include <iostream>
#include <cstdlib>
using namespace std;

struct tree
{  int data;
   struct tree *left,*right;
};

typedef struct tree node;
typedef node *btree;

btree creat_tree(btree root,int val)
{  
	btree newnode,current,backup;
	newnode=(btree) malloc(sizeof(node));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{  
		root=newnode;
		return root;
	}
	else
	{  
		for(current=root;current!=NULL;)
		{  
			backup=current;
			if(current->data > val)
				current=current->left;
			else
				current=current->right;
		}
		if(backup->data >val)
			backup->left=newnode;
		else
			backup->right=newnode;
	}
	return root;
}
btree search(btree ptr,int val)     //�j�M�G����Ƶ{��
{  
	int i=1;                     //�P�_���榸�ƪ��ܼ�
	while(1)
	{  
		if(ptr==NULL)            //�S���N�Ǧ^NULL
			return NULL;
		if(ptr->data==val)       //�`�I�ȵ���j�M��
		{  
			cout<<"�@�j�M "<<i<<"��"<<endl;
			return ptr;
		}
		else if(ptr->data > val)  //�`�I�Ȥj��j�M��
			ptr=ptr->left;
		else
			ptr=ptr->right;
		i++;
	}   
}

int main()
{  
	int i,data,arr[]={7,1,4,2,8,13,12,11,15,9,5};
	btree ptr=NULL;
	cout<<"[��l�}�C���e]"<<endl;
	for (i=0;i<11;i++)              
	{  
		ptr=creat_tree(ptr,arr[i]);  //�إߤG����
		cout<<"["<<arr[i]<<"] ";
	}
	cout<<endl;
	cout<<"�п�J�j�M�ȡG"<<endl;
	cin>>data;
	if((search(ptr,data)) !=NULL)        //�j�M�G����
		cout<<"�A�n�䪺�� ["<<data<<" ] �����!!"<<endl;
	else
		cout<<"�z�n�䪺�ȨS���!!"<<endl;
	return 0;
}
