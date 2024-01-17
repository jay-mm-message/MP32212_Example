/*
[示範]:將數學式子由中序表示法轉為後序表示法
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>

const int MAX = 50;
char infix_q[MAX]; // 用來存放中序表示法的佇列
// 運算子優先權的比較，若輸入運算子小於堆疊中運算子
// ，則傳回值為1，否則為0
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
	//cout << "\t本程式會將其轉成後序運算式" << std::endl;
	std::cout << "\tThis program will convert it into postfix and prefix expression" << std::endl;
	//cout << "\t請輸入中序運算式" << std::endl;
	std::cout << "\tPlease enter the infix expression" << std::endl; 
	//std::cout << "\t例如:(9+3)*8+7*6-8/4 " << std::endl;
	std::cout << "\tEx.:(9+3)*8+7*6-8/4 " << std::endl;
	//std::cout << "\t可以使用的運算子包括:^,*,+,-,/,(,)等 " << std::endl;
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
	// 在中序表示法佇列及暫存堆疊中，運算子的優先順序表，
	// 其優先權值為INDEX/2
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
// 中序轉前序的方法
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
	infix_q[rear] = 'q'; // 於佇列加入q為結束符號
	stack_t[top] = 'q'; // 於堆疊加入q為結束符號
	for (flag = 0; flag <= rear; flag++)
	{
		switch (infix_q[flag])
		{
		// 輸入為)，則輸出堆疊內運算子，直到堆疊內為(
		case ')':
			while (stack_t[top] != '(')
				std::cout << std::setw(1) << stack_t[top--];
			top--;
			break;
		// 輸入為q，則將堆疊內還未輸出的運算子輸出
		case 'q':
			while (stack_t[top] != 'q')
				std::cout << std::setw(1) << stack_t[top--];
			break;
		// 輸入為運算子，若小於TOP在堆疊中所指運算子，
		// 則將堆疊所指運算子輸出，若大於等於TOP在堆疊
		// 中所指運算子，則將輸入之運算子放入堆疊
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
		// 輸入為運算元，則直接輸出
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

