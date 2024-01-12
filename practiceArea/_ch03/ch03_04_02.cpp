#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip> //���a�l�����Y��
using namespace std;
class list
{
public:
	int num, score;
	char name[10];
	class list *next;
};

typedef class list node;
typedef node *link;

link findnode(link head, int position) {
    link ptr = head;

    while(ptr != NULL) {
        if (ptr->num == position)
        {
            /* code */
            return ptr;
        }
        
        ptr = ptr->next;
    }
    return ptr;
}

link insertnode(link head, link ptr, int new_num, int new_score, char name_name[10]) {
    link newNode = new node;
    newNode->num = new_num;
    newNode->score = new_score;
    strcpy(newNode->name, name_name);
    newNode->next = NULL;

    if (head == NULL)
    {
        /* code */
        newNode->next = head;
        return newNode;
    }
    else
    {
        if (ptr == NULL)
        {
            /* code */
            ptr->next = newNode;
        }
        else
        {
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }

    return head;
}

int main()
{
	link head, ptr, newnode;
	int new_num, new_score;
	char new_name[10];
	int i, j, position = 0, find, data[12][2];
	char namedata[12][10] = {{"Allen"}, {"Scott"}, {"Marry"}, {"John"}, {"Mark"},
	 						{"Ricky"}, {"Lisa"}, {"Jasica"}, {"Hanson"}, {"Amy"},
	  						{"Bob"}, {"Jack"}};
	srand((unsigned)time(NULL));

	//cout << "�y��  ���Z  �y��  ���Z  �y��  ���Z  �y��  ���Z" << endl;
	cout << "Seat Number Score" << endl;
	cout << "==============================================" << endl;
	for (i = 0; i < 12; i++)
	{
		data[i][0] = i + 1;
		data[i][1] = rand() % 50 + 51;
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
			cout << "[" << data[j * 3 + i][0] << "]  [" << data[j * 3 + i][1] << "]   ";
		cout << endl;
	}
	head = new node; // �إߦ�C��
	if (!head)
	{
		//cout << "Error!! �O����t�m����!!" << endl;
		cout << "Error!! Memory allocation failed!!" << endl;
		exit(1);
	}
	head->num = data[0][0];
	for (j = 0; j < 10; j++)
		head->name[j] = namedata[0][j];
	head->score = data[0][1];
	head->next = NULL;
	ptr = head;
	for (i = 1; i < 12; i++) // �إߦ�C
	{
		newnode = new node;
		newnode->num = data[i][0];
		for (j = 0; j < 10; j++)
			newnode->name[j] = namedata[i][j];
		newnode->score = data[i][1];
		newnode->next = NULL;
		ptr->next = newnode;
		ptr = ptr->next;
	}
	while (1)
	{
		//cout << "�п�J�n���J��᪺�ǥͽs���A������J-1�G";
		cout << "Please enter the student ID to insert after, and end input with -1.";
		cin >> position;
		if (position == -1) // �j�餤�_����
			break;
		else
		{
			ptr = findnode(head, position);
			cout << "Please enter the student ID for the new insertion:";
			//cout << "�п�J�s���J���ǥͽs���G";
			cin >> new_num;
			cout << "Please enter the new student's grade to be inserted:";
			//cout << "�п�J�s���J���ǥͦ��Z�G";
			cin >> new_score;
			cout << "Please enter the name of the new student to be inserted:";
			//cout << "�п�J�s���J���ǥͩm�W�G";
			cin >> new_name;
			head = insertnode(head, ptr, new_num, new_score, new_name);
		}
	}
	ptr = head;
	cout << "\n\tSeat number\t		Name\tGrade\n";
	//cout << "\n\t�y��\t    �m�W\t���Z\n";
	cout << "\t==============================\n";
	while (ptr != NULL)
	{
		cout << "\t[" << ptr->num << "]\t[ " << ptr->name << "]" << setw(6) << "\t[" << ptr->score << "]\n";
		ptr = ptr->next;
	}
	delete head;
	return 0;
}
