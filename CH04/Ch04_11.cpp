/*
[�ܽd]:�N�ƾǦ��l�Ѥ��Ǫ��ܪk�ର��Ǫ��ܪk 
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define MAX 50
char infix_q[MAX]; //�ΨӦs�񤤧Ǫ��ܪk����C  
//�B��l�u���v������A�Y��J�B��l�p����|���B��l
//�A�h�Ǧ^�Ȭ�1�A�_�h��0                          
int compare(char stack_o, char infix_o)
{
//�b���Ǫ��ܪk��C�μȦs���|���A�B��l���u�����Ǫ��A
//���u���v�Ȭ�INDEX/2                               
    char infix_priority[9] ; 
	char stack_priority[8] ;
	int index_s=0, index_i=0;
	infix_priority[0]='q';infix_priority[1]=')';
	infix_priority[2]='+';infix_priority[3]='-';
	infix_priority[4]='*';infix_priority[5]='/';
	infix_priority[6]='^';infix_priority[7]=' ';
	infix_priority[8]='(';      
	stack_priority[0]='q';stack_priority[1]='(';
	stack_priority[2]='+';stack_priority[3]='-';
	stack_priority[4]='*';stack_priority[5]='/';
	stack_priority[6]='^';stack_priority[7]=' ';
	while (stack_priority[index_s] != stack_o)
		index_s++;
	while (infix_priority[index_i] != infix_o)
		index_i++;
	return ((int)(index_s/2) >= (int)(index_i/2) ? 1 : 0);
}
//������e�Ǫ���k
void infix_to_postfix()
{
	int rear=0, top=0, flag=0,i=0;
	char stack_t[MAX];  
	for (i=0; i<MAX; i++)
			stack_t[i]='\0';
	    gets(infix_q);
	    i=0;
	    while(infix_q[i]!='\0') 
	    {
          i++;
          rear++;
        }
		infix_q[rear] = 'q';  //���C�[�Jq�������Ÿ�
		cout<<"\t"<<"��Ǫ��ܪk : ";
		stack_t[top]  = 'q';  //����|�[�Jq�������Ÿ�
		for (flag = 0; flag <= rear; flag++)\
        {		
			switch (infix_q[flag]) 
            {
				//��J��)�A�h��X���|���B��l�A������|����(
				case ')':
					while(stack_t[top]!='(') 			      
						cout<<setw(1)<<stack_t[top--];				   
					top--;
					break;
				//��J��q�A�h�N���|���٥���X���B��l��X
				case 'q':
					while(stack_t[top]!='q')
						cout<<setw(1)<<stack_t[top--];
					break;
				//��J���B��l�A�Y�p��TOP�b���|���ҫ��B��l�A
                //�h�N���|�ҫ��B��l��X�A�Y�j�󵥩�TOP�b���|
                //���ҫ��B��l�A�h�N��J���B��l��J���|     
				case '(':
				case '^':
				case '*':
				case '/':
				case '+':
				case '-': 
					while (compare(stack_t[top], infix_q[flag])==1)                       
						cout<<setw(1)<<stack_t[top--];			
					stack_t[++top] = infix_q[flag];
					break;
				//��J���B�⤸�A�h������X
				default :
					cout<<setw(1)<<infix_q[flag];
					break;
			}
		}
}
//�D��ƫŧi
int main (void) 		
{ 
    int i=0;
    for (i=0; i<MAX; i++)
	infix_q[i]='\0';	
	cout<<"\t=========================================="<<endl;
	cout<<"\t���{���|�N���ন��ǹB�⦡"<<endl;
    cout<<"\t�п�J���ǹB�⦡"<<endl;
    cout<<"\t�Ҧp:(9+3)*8+7*6-8/4 "<<endl;
    cout<<"\t�i�H�ϥΪ��B��l�]�A:^,*,+,-,/,(,)�� "<<endl;
    cout<<"\t=========================================="<<endl;
    cout<<"\t�ж}�l��J���ǹB�⦡: ";
    infix_to_postfix();
    cout<<endl;
    cout<<"\t=========================================="<<endl;   
    return 0; 
}