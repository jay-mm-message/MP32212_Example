/*
[�ܽd]:�����X�ֱƧǪk
       ����ɦW�Gdata1.txt,data2.txt�A�X�֫��ɮסGdata.txt
*/
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
void merge(ofstream& fp, ifstream& fp1, ifstream& fp2)
{  
    char n1,n2;
    char txt1[40];
    char txt2[40];
	fp1>>n1;
	fp2>>n2;
	while(fp1.eof()==0 && fp2.eof()==0)
	{  
		if (n1 <= n2)
		{  
            fp.put(n1);   
			fp1>>n1;/*����Ū�U�@�� n1 �����*/
		}
		else
		{  
            fp.put(n2);/*�p�Gn2����p�A�h��n2�s��fp��*/
			fp2>>n2;/*����Ū�U�@�� n2�����*/
		}
	}
	if(fp1.eof())/*�p�G�䤤�@�Ӹ���ɤwŪ�������A�g�P�_��*/
	{ 
       /*��t�@�Ӹ���ɤ�����ƥ������fp��*/
		while (!fp2.eof())
		{  
            fp2>>n2;
			fp.put(n2);
		}
	}
	else if (fp2.eof())
	{ 
		while(!fp1.eof())
		{             
            fp1>>n1;
			fp.put(n1);
		}
	}	 
}
int main(void)
{  
	char txt[40];;
	ofstream fp;
	ifstream fp1,fp2;
	ifstream f,f1,f2;
	fp.open("data.txt",ios::out);
	fp1.open("data1.txt",ios::in);
	fp2.open("data2.txt",ios::in);
	if(!fp.is_open())
		cout<<"�}�ҥD�ɥ���"<<endl;
	else if(!fp1.is_open())
		cout<<"�}�Ҹ���� 1 ����"<<endl;
	else if(!fp2.is_open())
		cout<<"�}�Ҹ���� 2 ����"<<endl;
	else
	{  
		cout<<"��ƱƧǤ�......"<<endl;
        merge(fp,fp1,fp2);
		cout<<"��ƳB�z����!!"<<endl;
	}
	fp.close();
	fp1.close();
	fp2.close();
	cout<<"data1.txt��Ƥ��e���G"<<endl;
	f1.open("data1.txt",ios::in);
	while(!f1.eof()) 
	{  
		f1>>txt;
		cout<<txt<<endl;
	}
	cout<<"data2.txt��Ƥ��e���G"<<endl;
	f2.open("data2.txt",ios::in);
	while(!f2.eof())
	{  
		f2>>txt;
		cout<<txt<<endl;
	}
	cout<<"�Ƨǫ�data.txt��Ƥ��e���G"<<endl;
	f.open("data.txt",ios::in);
	while(!f.eof())
	{  
		f>>txt;
		cout<<txt<<endl;
	}
	cout<<endl;
	f.close();
	f1.close();
	f2.close();
	return 0;
}
