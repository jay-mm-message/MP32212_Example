#include <iostream>
#define EAST MAZE[x][y + 1]	 // 定義東方的相對位置
#define WEST MAZE[x][y - 1]	 // 定義西方的相對位置
#define SOUTH MAZE[x + 1][y] // 定義南方的相對位置
#define NORTH MAZE[x - 1][y] // 定義北方的相對位置
using namespace std;
const int ExitX = 9;  // 定義出口的X座標在第八列
const int ExitY = 12; // 定義出口的Y座標在第十行

const int TAKEN_MODE = 1;
const int MAZE_ORG_MODE = 2;
const int MAZE_MODE 	= 3;
void show_state(int mode);

class list
{
	public:
		int x, y;
		struct list *next;
	public:
		list() {
			x = 0;
			y = 0;
			next = NULL;
		}
};
typedef struct list node;
typedef node *link;

const int ROWS = 10;
const int COLS = 12;
int MAZE[ROWS][COLS] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // 宣告迷宮陣列
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
int MAZE_ORG[ROWS][COLS] = {0};
link push(link stack, int x, int y);
link pop(link stack, int *x, int *y);
int chkExit(int, int, int, int);
void footprint_monitor(int maze[ROWS][COLS]);
void take_a_step(int maze[ROWS][COLS]);
void show_state(int mode);

int main(void)
{
	int i, j;
	link path = NULL;
	int x = 1; // 入口的X座標
	int y = 0; // 入口的Y座標
	cout << "[Path of the maze (section 0):]" << endl;
	// cout<<"[迷宮的路徑(0的部分)]"<<endl; //印出迷宮的路徑圖

	show_state(MAZE_MODE);

	while (x <= ExitX && y <= ExitY)
	{
		MAZE[x][y] = 2;
		if (NORTH == 0)
		{
			x -= 1;
			path = push(path, x, y);
		}
		else if (SOUTH == 0)
		{
			x += 1;
			path = push(path, x, y);
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
		}
		else if (chkExit(x, y, ExitX, ExitY) == 1) // 檢查是否走到出口了
			break;
		else
		{
			MAZE[x][y] = 2;
			path = pop(path, &x, &y);
		}
		
		footprint_monitor(MAZE);
	}
	cout << "Path taken by the mouse (section 2)" << endl << endl;
	// cout<<"[老鼠走過的路徑(2的部分)]"<<endl; //印出老鼠走完迷宮後的路徑圖
	show_state(TAKEN_MODE);
	return 0;
}
link push(link stack, int x, int y)
{
	link newnode = new node;

	if (!newnode)
	{
		cout << "Error !! memory fail" << endl;
		// cout<<"Error!記憶體配置失敗!"<<endl;
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

void take_a_step(int maze[ROWS][COLS]) {
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

void show_state(int mode) {
	switch (mode)
	{
	case TAKEN_MODE:
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
		/* code */
		break;
	case MAZE_ORG_MODE:
		for (size_t i = 0; i < ROWS; i++)
		{
			/* code */
			for (size_t j = 0; j < COLS; j++)
			{
				/* code */
				cout << MAZE_ORG[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		break;
	case MAZE_MODE:
		for (size_t i = 0; i < ROWS; i++)
		{
			/* code */
			for (size_t j = 0; j < COLS; j++)
			{
				/* code */
				cout << MAZE[i][j] << ' ';
				MAZE_ORG[i][j] = MAZE[i][j];	// store org maze
			}
			cout << endl;
		}
		cout << endl;
		break;
	default:
		break;
	}
}
int g_i = 0;
void footprint_monitor(int maze[ROWS][COLS]) {

	cout << "Press Enter to continue...";
    cin.get(); // Wait for the user to press Enter

	system("clear");
	cout << g_i << "----------------------------"  << endl;
	show_state(MAZE_ORG_MODE);
	take_a_step(maze);
	show_state(TAKEN_MODE);
	cout << "----------------------------"  << endl;
	++g_i;
}
