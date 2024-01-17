/*
[�ܽd]:�N�ƾǦ��l�Ѥ��Ǫ�ܪk�ର��Ǫ�ܪk
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>

const int MAX = 50;
char infix_q[MAX]; // �ΨӦs�񤤧Ǫ�ܪk����C
// �B��l�u���v������A�Y��J�B��l�p����|���B��l
// �A�h�Ǧ^�Ȭ�1�A�_�h��0
int compare(char stack_o, char infix_o);
void infix_to_postfix();
void init_infix_expression(std::string myString);
void show_infix_pression();

#include <stack>
#include <algorithm>

bool isOperator(char c);
int getPrecedence(char op);
std::string infixToPrefix(const std::string& infix);

const int INFIX = 1;
const int PREFIX = 2;
const int POSTFIX = 3;
void expression_mode(int mode, std::string expression);

int main(void)
{
	int i = 0;
	for (i = 0; i < MAX; i++)
		infix_q[i] = '\0';
	std::cout << "\t==========================================" << std::endl;
	//cout << "\t���{���|�N���ন��ǹB�⦡" << std::endl;
	std::cout << "\tThis program will convert it into postfix and prefix expression" << std::endl;
	//cout << "\t�п�J���ǹB�⦡" << std::endl;
	std::cout << "\tPlease enter the infix expression" << std::endl; 
	//std::cout << "\t�Ҧp:(9+3)*8+7*6-8/4 " << std::endl;
	std::cout << "\tEx.:(9+3)*8+7*6-8/4 " << std::endl;
	//std::cout << "\t�i�H�ϥΪ��B��l�]�A:^,*,+,-,/,(,)�� " << std::endl;
	std::cout << "\tThe operators that can be use include: ^,*,+,-,/,(,) etc " << std::endl;
	std::cout << "\t==========================================" << std::endl;
	//std::cout << "\tPlease start entering infix expression: ";
	//init_infix_expression("(9+3)*8+7*6-8/4");
	//std::std::string infixExpression = "A + B * (C - D) / E";
	std::string expression = "8+7";
	expression_mode(INFIX, expression);
	expression_mode(PREFIX, expression);
	expression_mode(POSTFIX, expression);

	std::cout << "\t==========================================" << std::endl;
	return 0;
}

int compare(char stack_o, char infix_o)
{
	// �b���Ǫ�ܪk��C�μȦs���|���A�B��l���u�����Ǫ�A
	// ���u���v�Ȭ�INDEX/2
	char infix_priority[9];
	char stack_priority[8];
	int index_s = 0, index_i = 0;
	infix_priority[0] = 'q';
	infix_priority[1] = ')';
	infix_priority[2] = '+';
	infix_priority[3] = '-';
	infix_priority[4] = '*';
	infix_priority[5] = '/';
	infix_priority[6] = '^';
	infix_priority[7] = ' ';
	infix_priority[8] = '(';
	stack_priority[0] = 'q';
	stack_priority[1] = '(';
	stack_priority[2] = '+';
	stack_priority[3] = '-';
	stack_priority[4] = '*';
	stack_priority[5] = '/';
	stack_priority[6] = '^';
	stack_priority[7] = ' ';
	while (stack_priority[index_s] != stack_o)
		index_s++;
	while (infix_priority[index_i] != infix_o)
		index_i++;
	return ((int)(index_s / 2) >= (int)(index_i / 2) ? 1 : 0);
}
// ������e�Ǫ���k
void infix_to_postfix()
{
	int rear = 0, top = 0, flag = 0, i = 0;
	char stack_t[MAX];
	for (i = 0; i < MAX; i++)
		stack_t[i] = '\0';

	// cin.getline(infix_q, sizeof(infix_q));
	
	i = 0;
	while (infix_q[i] != '\0')
	{
		i++;
		rear++;
	}
	infix_q[rear] = 'q'; // ���C�[�Jq�������Ÿ�
	stack_t[top] = 'q'; // ����|�[�Jq�������Ÿ�
	for (flag = 0; flag <= rear; flag++)
	{
		switch (infix_q[flag])
		{
		// ��J��)�A�h��X���|���B��l�A������|����(
		case ')':
			while (stack_t[top] != '(')
				std::cout << std::setw(1) << stack_t[top--];
			top--;
			break;
		// ��J��q�A�h�N���|���٥���X���B��l��X
		case 'q':
			while (stack_t[top] != 'q')
				std::cout << std::setw(1) << stack_t[top--];
			break;
		// ��J���B��l�A�Y�p��TOP�b���|���ҫ��B��l�A
		// �h�N���|�ҫ��B��l��X�A�Y�j�󵥩�TOP�b���|
		// ���ҫ��B��l�A�h�N��J���B��l��J���|
		case '(':
		case '^':
		case '*':
		case '/':
		case '+':
		case '-':
			while (compare(stack_t[top], infix_q[flag]) == 1)
				std::cout << std::setw(1) << stack_t[top--];
			stack_t[++top] = infix_q[flag];
			break;
		// ��J���B�⤸�A�h������X
		default:
			std::cout << std::setw(1) << infix_q[flag];
			break;
		}
	}
}

void init_infix_expression(std::string myString) {
    myString.copy(infix_q, myString.length());
    infix_q[myString.length()] = '\0'; // Add null terminator
	show_infix_pression();
}

void show_infix_pression() {
	int i = 0;
	while(infix_q[i] != '\0') {
		std::cout << infix_q[i];
		++i;
	}
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::string infixToPrefix(const std::string& infix) {
    std::string reversedInfix = infix;
    //std::cout << "reverse before: " << reversedInfix << std::endl;
    std::reverse(reversedInfix.begin(), reversedInfix.end());
    //std::cout << "reverse after: " << reversedInfix << std::endl;

    for (int i = 0 ; i < reversedInfix.size() ; ++i) {
    // for (char& c : reversedInfix) {
        char c = reversedInfix[i];
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    std::stack<char> operatorStack;
    std::string prefixExpression;

    //for (char c : reversedInfix) {
    for (int i = 0 ; i < reversedInfix.size() ; ++i) {
        char c = reversedInfix[i];
        if (isalnum(c)) {
			if (c == 'q')
			{
				/* code */
				continue;
			}
			
            prefixExpression += c;
        } else if (isOperator(c)) {
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) > getPrecedence(c)) {
                prefixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        } else if (c == '(') {
            while (!operatorStack.empty() && operatorStack.top() != ')') {
                prefixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Discard ')'
        } else if (c == ')') {
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        prefixExpression += operatorStack.top();
        operatorStack.pop();
    }

    std::reverse(prefixExpression.begin(), prefixExpression.end());
    return prefixExpression;
}

void expression_mode(int mode, std::string expression) {
	switch (mode)
	{
	case INFIX:
		std::cout << "\tInfix Expression: ";
		init_infix_expression(expression);
		std::cout << std::endl;
		break;
	case POSTFIX:
		std::cout << "\tPostfix Expression: ";
		infix_to_postfix();
		std::cout << std::endl;
		break;
	case PREFIX:
		std::string infixExpression = std::string(expression);
		std::string prefixExpression = infixToPrefix(infixExpression);
		// //std::cout << "\tInfix Expression: " << infixExpression << std::endl;
		std::cout << "\tPrefix Expression: " << prefixExpression << std::endl;
		break;
	// default:
	// 	break;
	}
}

