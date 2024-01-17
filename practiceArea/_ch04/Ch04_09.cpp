#include <iostream>
#define EAST MAZE[x][y + 1]	 // �w�q�F�誺�۹��m
#define WEST MAZE[x][y - 1]	 // �w�q��誺�۹��m
#define SOUTH MAZE[x + 1][y] // �w�q�n�誺�۹��m
#define NORTH MAZE[x - 1][y] // �w�q�_�誺�۹��m
using namespace std;
const int ExitX = 9;  // �w�q�X�f��X�y�Цb�ĤK�C
const int ExitY = 12; // �w�q�X�f��Y�y�Цb�Ģ̦�
struct list
{
	int x, y;
	struct list *next;
};
typedef struct list node;
typedef node *link;

const int ROWS = 10;
const int COLS = 12;
int MAZE[ROWS][COLS] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // �ŧi�g�c�}�C
						0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
						1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1,
						1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
						1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1,
						1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
						1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
						1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1,
						1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
						1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1};

int TAKEN[ROWS][COLS] = {0};
int PATH[ROWS][COLS] = {0};
link push(link stack, int x, int y);
link pop(link stack, int *x, int *y);
int chkExit(int, int, int, int);
void show_taken(int maze[ROWS][COLS]);
void path_taken(int maze[ROWS][COLS]);
void show_map();

int main(void)
{
	int i, j;
	link path = NULL;
	int x = 1; // �J�f��X�y��
	int y = 0; // �J�f��Y�y��
	cout << "[Path of the maze (section 0):]" << endl;
	// cout<<"[�g�c�����|(0������)]"<<endl; //�L�X�g�c�����|��
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++) {
			cout << MAZE[i][j] << " ";
			PATH[i][j] = MAZE[i][j];
		}
		cout << endl;
	}
	cout << endl;
	while (x <= ExitX && y <= ExitY)
	{
		MAZE[x][y] = 2;
		if (NORTH == 0)
		{
			x -= 1;
			path = push(path, x, y);
			show_taken(MAZE);
		}
		else if (SOUTH == 0)
		{
			x += 1;
			path = push(path, x, y);
			show_taken(MAZE);
		}
		else if (WEST == 0)
		{
			y -= 1;
			path = push(path, x, y);
		}
		else if (EAST == 0)
		{
			y += 1;
			path = push(path, x, y);
			show_taken(MAZE);
		}
		else if (chkExit(x, y, ExitX, ExitY) == 1) // �ˬd�O�_����X�f�F
			break;
		else
		{
			MAZE[x][y] = 2;
			path = pop(path, &x, &y);
			show_taken(MAZE);
		}
	}
	cout << "Path taken by the mouse (section 2)" << endl;
	// cout<<"[�ѹ����L�����|(2������)]"<<endl; //�L�X�ѹ������g�c�᪺���|��
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
			//cout << MAZE[i][j] << " ";
			cout << TAKEN[i][j] << " ";
		cout << endl;
	}
	return 0;
}
link push(link stack, int x, int y)
{
	link newnode;
	newnode = new node;
	if (!newnode)
	{
		cout << "Error ! memory fail" << endl;
		// cout<<"Error!�O����t�m����!"<<endl;
		return NULL;
	}
	newnode->x = x;
	newnode->y = y;
	newnode->next = stack;
	stack = newnode;
	return stack;
}
link pop(link stack, int *x, int *y)
{
	link top;
	if (stack != NULL)
	{
		top = stack;
		stack = stack->next;
		*x = top->x;
		*y = top->y;
		delete top;
		return stack;
	}
	else
		*x = -1;
	return stack;
}
int chkExit(int x, int y, int ex, int ey)
{
	if (x == ex && y == ey)
	{
		if (NORTH == 1 || SOUTH == 1 || WEST == 1 || EAST == 2)
			return 1;
		if (NORTH == 1 || SOUTH == 1 || WEST == 2 || EAST == 1)
			return 1;
		if (NORTH == 1 || SOUTH == 2 || WEST == 1 || EAST == 1)
			return 1;
		if (NORTH == 2 || SOUTH == 1 || WEST == 1 || EAST == 1)
			return 1;
	}
	return 0;
}

void path_taken(int maze[ROWS][COLS]) {
	for (size_t i = 0; i < ROWS; i++)
	{
		/* code */
		for (size_t j = 0; j < COLS; j++)
		{
			/* code */
			if (maze[i][j] == 2)
			{
				/* code */
				TAKEN[i][j] = maze[i][j];
			}
			
		}
		
	}
}

int g_i = 0;
void show_taken(int maze[ROWS][COLS]) {

	cout << "Press Enter to continue...";
    cin.get(); // Wait for the user to press Enter

	cout << g_i << "----------------------------"  << endl;
	show_map();
	path_taken(maze);
	for (size_t i = 0; i < ROWS; i++)
	{
		/* code */
		for (size_t j = 0; j < COLS; j++)
		{
			/* code */
			cout << TAKEN[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	cout << "----------------------------"  << endl;
	++g_i;
}

void show_map() {
	for (size_t i = 0; i < ROWS; i++)
	{
		/* code */
		for (size_t j = 0; j < COLS; j++)
		{
			/* code */
			cout << PATH[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}