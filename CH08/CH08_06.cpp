/*
[�ܽd]:�ֳt�ƧǪk
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
void inputarr(int*,int);
void showdata(int*,int);
void quick(int*,int,int,int);
int process = 0;
int main(void)
{
	int size,data[100]={0};
	srand(time(NULL));
	cout<<"�п�J�}�C�j�p(100�H�U)�G";
	cin>>size;
	cout<<"�z��J����l��ƬO�G";
    inputarr (data,size);
	showdata (data,size);
	quick(data,size,0,size-1);
	cout<<"\n�Ƨǵ��G�G";
	showdata(data,size);
	return 0;
}
void inputarr(int data[],int size)
{
	for (int i=0;i<size;i++)
		data[i]=(rand()%99)+1;
}
void showdata(int data[],int size)
{  
	int i;
	for (i=0;i<size;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
}
void quick(int d[],int size,int lf,int rg)
{
	int tmp;
	int lf_idx;
	int rg_idx;
	int t;
 //1:�Ĥ@����Ȭ�d[lf]
	if(lf<rg)
	{
		lf_idx=lf+1;
		rg_idx=rg;
    while(1) {
	    cout<<"[�B�z�L�{"<<process++<<"]=> ";
        for(int t=0;t<size;t++)
			cout<<"["<<setw(2)<<d[t]<<"] ";
		cout<<endl;
		for(int i=lf+1;i<=rg;i++)//2:�ѥ��V�k��X�@����Ȥj��d[lf]��
		{
			if(d[i]>d[lf])
			{
				lf_idx=i;
				break;
			}
			lf_idx++;
		}
		for(int j=rg;j>=lf+1;j--)//3:�ѥk�V����X�@����Ȥp��d[lf]��
		{
			if(d[j]<=d[lf]) 
			{
				rg_idx=j;
				break;
			}
			rg_idx--;
		}
		if(lf_idx<rg_idx)        //4-1:�Ylf_idx<rg_idx
		{					     
			tmp = d[lf_idx];       
			d[lf_idx] = d[rg_idx];//�hd[lf_idx]�Md[rg_idx]����
			d[rg_idx] = tmp;      //�M���~��Ƨ� 
        } else {
			break;    //�_�h���X�ƧǹL�{ 
		} 
    }
		if(lf_idx>=rg_idx)       //5-1:�Ylf_idx�j�󵥩�rg_idx
		{                        //�h�Nd[lf]�Md[rg_idx]����
			tmp = d[lf];
			d[lf] = d[rg_idx];
			d[rg_idx] = tmp;
                                      //5-2:�åHrg_idx������I�������k��b
			quick(d,size,lf,rg_idx-1);//�H���j�覡���O�����k��b�i��Ƨ�
			quick(d,size,rg_idx+1,rg);//���ܧ����Ƨ�
		}
	}
}