/*
[�ܽd]:�����쵲��C���`�I�R�� 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
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

link findnode(link head,int num)
{
     link ptr;
     ptr=head;
     while(ptr!=NULL)
     {
        if(ptr->num==num)
           return ptr;
        ptr=ptr->next;
     }
     return ptr;
}

link deletenode(link head,link del)   
{
     link CurNode=NULL;  
     link PreNode=NULL;
     link TailNode=NULL;
     if(head==NULL)
     {
        cout<<"[������C�w�g�ŤF]";
        return NULL;
     }
     else
     {
         if(del==head) //�R�����`�I�O��C��
         {
            CurNode=head;
            while(CurNode->next!=head)
               CurNode=CurNode->next;
               //���̫�@�Ӹ`�I�ðO���U��
               TailNode=CurNode;
               //(1)�N��C������U�@�Ӹ`�I
               head=head->next;
               //(2)�N��C�̫�@�Ӹ`�I�����Ы��V�s����C��
               TailNode->next=head;
               return head;
         } 
         else //�n�R�����`�I���O��C��
         {
              CurNode=head;
              while(CurNode->next!=del)
                 CurNode=CurNode->next;
              //(1)���n�R���`�I���e�@�Ӹ`�I�ðO���U��
              PreNode=CurNode;
              //�n�R�����`�I
              CurNode=CurNode->next;
              //(2)�N�n�R���`�I���e�@�ӫ��Ы��V�n�R���`�I���U�@�Ӹ`�I
              PreNode->next=CurNode->next;
              delete CurNode;
              return head;
         }
     }
}


int main()
{  
	link head,ptr,newnode;
	int new_num, new_score;
	char new_name[10];
	int i,j,position=0,find,data[12][2];
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"}
    ,{"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"}
    ,{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	srand((unsigned)time(NULL));
	cout<<"�y��  ���Z  �y��  ���Z  �y��  ���Z  �y��  ���Z"<<endl;
	cout<<"=============================================="<<endl;
	for(i=0;i<12;i++)
	{  
		data[i][0]=i+1;
		data[i][1]=rand()%50+51;
	}
	for(i=0;i<3;i++)
	{  
		for (j=0;j<4;j++)
			cout<<"["<<data[j*3+i][0]<<"]"<<setw(4)<<"["<<data[j*3+i][1]<<"]  ";
		cout<<endl;
	}
	head=new node;   //�إߦ�C��
	if(!head)
	{  
		cout<<"Error!! �O����t�m����!!"<<endl;
		exit(1);
	}
	head->num=data[0][0];
	for (j=0;j<10;j++)
		head->name[j]=namedata[0][j];
	head->score=data[0][1];
	head->next=NULL;
	ptr=head;
	for(i=1;i<12;i++) //�إߦ�C
	{  
		newnode=new node;
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;//�N�e�@�Ӹ`�I���V�s�إߪ��`�I
		ptr=newnode; //�s�`�I�����e�@�Ӹ`�I
	}
	newnode->next=head;//�N�̫�@�Ӹ`�I���V�Y�`�I�N���F�����쵲
	while(1)
	{  
		cout<<"�п�J�n�R�����ǥͽs���A������J-1�G";
		cin>>position;
		if(position==-1) //�j�餤�_����
			break;
		else
		{  
			ptr=findnode(head,position);
			head=deletenode(head,ptr);
		}
	}
	ptr=head;//���V��C���}�Y
	cout<<"\n\t�y��\t    �m�W\t���Z\n";         
	cout<<"\t==============================\n";
	do
	{
	    cout<<"\t["<<ptr->num<<"]\t[ "<<setw(10)<<ptr->name<<"]\t["<<ptr->score<<"]"<<endl;
		ptr=ptr->next;//���V�U�@�Ӹ`�I
    } while(head!=ptr && head!=head->next);
    delete head;
	return 0;
}
