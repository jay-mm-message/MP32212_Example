// Prim �t��k�S�� P ��k 
#define  BIG_NO 99999
#include <iostream>
using namespace std;

int data[60][60];  //�ŧi�G���}�C���۾F�x�}
int total=0;    //�O���̤p�����X�i���`�M, ��ȳ]�w�� 0 
int start;           //�̤p�����X�i�𪺰_�I
int value[60];       //�H�@���}�C�䪺�j�p���v��
char marked[60]={0}; //�ΨӼаO�ӳ��I�O�_�w���, ��ȳ]�w�� 0
int road[60];        //�O���̤p�����X�i�𪺸��|
void MinSpanTree(int,int,int); //�̤p�ͦ��𪺰Ƶ{�� 

int main(void){
	int node=3;    //�ϧγ��I�`��
    int edge=3;   //�ϧ��`���
	int x,y,z;
	//data�}�C��l�ȳ]�w 
	for(int i=0;i<node;i++){
		for(int j=0;j<node;j++){
			data[i][j]=BIG_NO; 
		}
	}
	cout<<"�ϧγ��I�Ӽ�= "<<node<<endl; //��X�ϧγ��I���`�� 
	cout<<"�ϧ��`���= "<<edge<<endl;  //��X�ϧ��`���
	//Ū���ο�X�U�䪺��T, �]�A�_�I, ���I�����
    for(int i=0;i<edge;i++){  
        cout<<"�п�J�� "<<(i+1)<<" ���䪺�_�I, ���I�����, �ƭȤ����H�ťչj�} "<<endl;
 	    cin>>x>>y>>z;
	    data[x][y]=z; 
	    data[y][x]=z;
	    cout<<"�� "<<(i+1)<<" ����O�q���I "<<x<<" �쳻�I "<<y<<", ����ɪ�= "<<z<<endl;
	 }

	cout<<"�п�J�̤p�����X�i��_�l���I: ";
	cin>>start;
	MinSpanTree(start,node,edge);	//�I�s Prim�t��k�Ƶ{�� 
	cout<<"�̤p�����X�i�𪺸��|���G"<<endl;
	for(int i=0;i<node;i++){
		if(i!=start){
		    cout<<"�s�����I "<<road[i]<<"------�쳻�I "<<i<<" ����"<<endl;
		}
	}
	cout<<"�̤p�����X�i���`����= "<<total<<endl;	
	return 0;
} 

void MinSpanTree(int start,int node, int edge){
	int smallest;      //�ΨӰO�������̤p���ܼ� 
	int end_point;     //�����̤p���䪺�������I 
	marked[start]=1;   //�аO�ӳ��I���w��� 
	
	//���j��O�i���l�Ƥu�@ 
	for(int i=0;i<node;i++){   
		value[i]=data[start][i];   //��l�ƶ}�l���I���U�F���䪺����
		road[i]=start; //��l�Ʊq�}�l���I�� i ���I�����|
	} 
	
	for(int i=1;i<node;i++){
		smallest=BIG_NO;	
		//�H�j��v�@�M��X��X�����̤p 
		for(int j=0;j<node;j++){   
			if((marked[j]==0) && (smallest>value[j])){
				smallest=value[j]; //�O�������̤p�䪺�ƭ� 
				end_point=j;     //�O���̤p�䪺�����䪺���I j 
			}
		}
		total =total+value[end_point];   //�֥[�̤p��������
		marked[end_point]=1;  //�аO��X�����I  
		for(int j=0;j<node;j++){  //��s�O���䪺�j�p���v�� value �}�C
			if((marked[j]==0) && (data[end_point][j]<value[j])){
				value[j]=data[end_point][j];
				road[j]=end_point;
			}
		} 
	}
} 

