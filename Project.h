#include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<GL\glut.h>
#include<GL\glui.h>
using namespace std;

//*************************************************************************************************************

struct Node
{
	int data;
	Node * pnext;
	bool _state;
	int _order;
};
struct linkedlist
{
	Node * list;
};
struct arr
{
	int p;
	int q;
}ar[20];
static Node * head = NULL, *cur = NULL;
int dem = 0, flag = 1, num = 0, _dem = 0, _time = 0, _choose;
char ch;
int succ = 1, succ1 = 1, ins_succ = 1, temporder = 0;
int item, key, k;
bool _trait = false, _cut = false;
GLfloat _xspeed = 0.0f;
//color for string
float color[4][3] = { { 0.0f, 0.4f, 2.0f },{ 0.0f, 0.4f, 2.0f },{ 0.0f, 0.4f, 2.0f },{ 0.0f, 0.4f, 2.0f } };
//GLUI 
int choice;
int _data1;
int _data2;
int _data3;
int _left;
int _right;
int main_window;
int sbs = 0;
int ao = 0;
int succAni = 1;

//*************************************************************************************************************

void inistate();//initialize the state of the node
void mark();//make the order of the nodes in the list
void resize(int w, int h);//change window size without changing size of the content
void MyKeyboard(unsigned char key, int mouseX, int mouseY);
int countdigit(int n);//count number of digit
void drawstring(float x, float y, char *string, int col);//draw strings
void title();//show titles
void renderscene();
void init();
void disp();
void reshape(GLsizei w, GLsizei h);
void drawstring1(float x, float y, char *string, int col);
void display();//draw nodes and arrows,show maximum 5 digits
void delay();

void RollBack();//press button o to roll back
void MoveBack(int value);//move the trait back

						 //*************************************************************************************************************

void InitEmpty(Node * &head);//initialize empty
void InitRandom(Node * &head, int n);//initialize random
void InputFile(Node * &head, int &n);//inputfrom file

void InsertHead(Node * &head, int data);//insert a new node to the head of the linked list
void InsertTail(Node * &head, int data);//insert a new node to the last of the linked list
void InsertBeforeNode(Node * &head, int data, int k);//insert a new node before the first node having data k
void InsertAfterNode(Node * head, int data, int k);//insert a new node after the first node having data k

void RemoveHead(Node * &head);//remove the first node
void RemoveTail(Node * &head);//remove the tail node
void RemoveSpecificNode(Node * &head, int k);//delete the first Node k
void OutputFile(Node * head);//output linkes list to file


void FindSpecificNode(Node * head, int k);//find a node having data k
void FindInRange(Node * head, int a, int b);//find the first node having data in the range [a,b]
void FindLesser(Node * head, int a);//find the first node having data less than a
void FindGreater(Node * head, int a);//find the first node having data greater than a

void Insert(Node *&head, int k);//insert a new node k to the linked list
void MakeEmpty(Node *&head);//make the linked list empty

//*************************************************************************************************************

void Traverse_One(int value);//to traverse the list step-by-step
void Traverse_All(int value);//to traverse the list automatic
void FindSmaller_One(int value);//to traverse and find smaller node step-by-step
void FindSmaller_All(int value);//to traverse and find smaller automaticcaly
void FindBigger_One(int value);//to traverse and find greater node step-by-step
void FindBigger_All(int value);//to traverse and find greater node automaticcaly
void FindSpecific_One(int value);//to traverse and find a specific node step-by-step
								 //void FindSpecific_All(int value);//to traverse and find a specific node run-one
void FindRange_One(int value);//to traverse and find in range step-by-step
void FindRange_All(int value);//to traverse and find in range run-one
void RemoveTail_One(int value);//traverse the list and remove the tail step-by-step
void RemoveTail_All(int value);//traverse the list and remove the tail run-one
							   //void RemoveSpecific_All(int value);//traverse the list and remove the node run-one
void RemoveSpecific_One(int value);//traverse the list and remove the node step-by-step

 //*************************************************************************************************************

void inistate()
{
	if (head == NULL)
		return;
	Node * cur = head;
	while (cur != NULL)
	{
		cur->_state = true;
		cur = cur->pnext;
	}
}
void mark()
{
	if (head == NULL)
		return;
	Node * cur = head;
	while (cur != NULL)
	{
		cur->_order = temporder;
		temporder++;
		cur->pnext;
	}
	temporder = 0;
}
void resize(int w, int h)
{
	// float ratio = 1;
	//if (h == 0)
	//	h = 1;
	//float ratio = w * 1.0 / h;
	GLUI_Master.auto_set_viewport();
	//glViewport(0, 0, (h - (w / ratio))>0 ? w : (int)(h*ratio), (w - (h*ratio))>0 ? h : (int)(w / ratio));
	//update camera
	//glViewport( 0, 0, ,  );//change the size of the window without changing the size of the contents


}
void MyKeyboard(unsigned char key, int mouseX, int mouseY)
{
	if (key == 'd')
	{
		glTranslatef(15.0f, 0.0f, 0.0f);
		glutPostRedisplay();
		//glTranslated (1.5f ,1.0f ,1.0f);
		//glScaled(0.5f ,1.0f ,1.0f);
		//glutPostRedisplay();
		glutSwapBuffers();
		return;
	}
	else if (key == 'a')
	{
		glTranslatef(-15.0f, 0.0f, 0.0f);
		glutPostRedisplay();
		//glTranslated (-3.5f ,1.0f ,1.0f);
		//glScaled (1.0f ,0.5f ,1.0f);
		//glutPostRedisplay();
		return;
	}
	else if (key == 'w')
	{
		glTranslatef(0.0f, 15.0f, 0.0f);
		//glutPostRedisplay();
		//glTranslated (-3.5f ,1.0f ,1.0f);
		//glScaled (1.0f ,0.5f ,1.0f);
		glutPostRedisplay();
		return;
	}
	else if (key == 's')
	{
		glTranslatef(0.0f, -15.0f, 0.0f);
		glutPostRedisplay();
		//glTranslated (-3.5f ,1.0f ,1.0f);
		//glScaled (1.0f ,0.5f ,1.0f);
		//glutPostRedisplay();
		return;
	}
	else if (key == 'q')
	{
		//glTranslated (1.0f ,1.0f ,1.0f);
		glScaled(1.2f, 1.2f, 1.2f);
		glutPostRedisplay();
		return;
	}
	else if (key == 'e')
	{
		//glTranslated (1.0f ,1.0f ,1.0f);
		glScaled(0.8f, 0.8f, 0.8f);
		glutPostRedisplay();
		return;
	}

	glutSwapBuffers();
}
int countdigit(int n)
{
	int sum = 0;
	while (n != 0)
	{
		sum++;
		n = n / 10;
	}
	return sum;
}
void drawstring(float x, float y, char *string, int col)
{
	char *c;
	glColor3fv(color[col]);
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}
void title()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	drawstring(150.0, 450.0, "COMPUTER GRAPHICS PROJECT 2", 1);
	drawstring(30.0, 350.0, "GROUP ID: 6 ", 3);
	drawstring(30.0, 300.0, "Ho Chi Minh University of Science", 3);
	drawstring(100.0, 250.0, "", 2);
	drawstring(30.0, 250.0, "Dinh Dat Thanh", 3);
	drawstring(30.0, 200.0, "Nguy Thien Ban", 3);
	drawstring(30.0, 150.0, "Ta Huy Hoang", 3);
	drawstring(30.0, 100.0, "", 3);
	glFlush();
}
void renderscene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	title();
	glLoadIdentity();

	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
void init()
{
	glClearColor(1.0f, 1.0f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(8.0, 1.6, 1.2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 60.0, 480.0);
}
void delay()
{
	int i, j;
	for (i = 0; i<10000; i++)
		for (j = 0; j<10000; j++)
			;
}
void disp()
{
	glColor3f(0.5, 0.4, 0.7);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2i(50, 200);
	glVertex2i(50, 250);
	glVertex2i(130, 250);
	glVertex2i(130, 200);
	glEnd();
	glFlush();
}
void reshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, 1920, 1080);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	glutPostRedisplay();
}
void drawstring1(float x, float y, char *string, int col)
{
	char *c;
	glColor3fv(color[col]);
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
	}
}

void RollBack()
{
	if (cur == head || cur == NULL)
		return;
	Node * temp = head;
	while (temp->pnext != cur)
		temp = temp->pnext;
	cur = temp;
	temp = NULL;
	glutTimerFunc(0, MoveBack, 0);
	glFlush();
}
void MoveBack(int value)
{
	if (_dem < 26)
	{
		_xspeed -= 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else
	{
		_dem = 0;
		return;
	}
	glutTimerFunc(30, MoveBack, 0);
}

//*************************************************************************************************************

void display()//show maximum 5 digits
{
	int i = 0, j = 0, k = 0, b[20];
	Node * temp = NULL;

	glClear(GL_COLOR_BUFFER_BIT);//clear the current screen
	glClearColor(1.0f, 1.0f, 0.4f, 0.0f);
	glColor3f(6.0, 16.0, 5.6);
	drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
	if (head == NULL)
	{
		drawstring(200.0, 150.0, "EMPTY LIST", 2);
		disp();
		//return;
	}
	temp = head;
	while (temp != NULL)
	{
		for (k = 0; k<dem; k++)
		{
			GLfloat x1 = 50, x2 = 95, x3 = 110, y1 = 200, y2 = 225, y3 = 250,
				x4 = 95, y4 = 225, x5 = 160, y5 = 210, y6 = 240, x6 = 180;
			GLfloat posx = x4, posy = y4, xspeed = 10;
			if (head->pnext == NULL)
			{
				glColor3f(0.0, 0.0, 0.0);
				glBegin(GL_LINES);
				glVertex2i(x2 + k * 130, y3);
				glVertex2i(x3 + k * 130, y1);
				glEnd();
			}
			//draw the last node with pnext ==NULL
			if (temp->pnext == NULL)
			{
				glColor3f(0.0f, 0.2f, 1.70f);
				glBegin(GL_POLYGON);
				glVertex2i(x1 + k * 130, y1);
				glVertex2i(x1 + k * 130, y3);
				glVertex2i(x2 + k * 130, y3);
				glVertex2i(x2 + k * 130, y1);
				glEnd();
				glColor3f(0.0, 0.60, 0.80);
				glBegin(GL_POLYGON);
				glVertex2i(x2 + k * 130, y1);
				glVertex2i(x2 + k * 130, y3);
				glVertex2i(x3 + k * 130, y3);
				glVertex2i(x3 + k * 130, y1);
				glEnd();
				//draw the ending /
				glColor3f(0.0, 0.0, 0.0);
				glBegin(GL_LINES);
				glVertex2i(x2 + k * 130, y3);
				glVertex2i(x3 + k * 130, y1);
				glEnd();
				// Print out meesage for Insert/Delete/Find/Input File/Output File/ Randon
				if (choice == 0)
				{
					drawstring(200.0, 150.0, "RANDOM", 2);
				}
				if (choice == 1)
				{
					drawstring(200.0, 150.0, "INPUT FILE", 2);
				}
				if (choice == 2)
				{
					if (!ins_succ)
						drawstring(200.0, 150.0, "KEY NODE DOESN'T EXIST", 2);
					else
					{
						if (succAni)
							drawstring(200.0, 150.0, "PROCESSING", 2);
						else
							drawstring(200.0, 150.0, "NEW NODE INSERTED", 2);
					}
				}
				if (choice == 3)
				{
					if (!succ)
						drawstring(200.0, 150.0, "KEY NODE DOESN'T EXIST", 2);
					else
					{
						if (succAni)
							drawstring(200.0, 150.0, "PROCESSING", 2);
						else
							drawstring(200.0, 150.0, "NODE DELETED", 2);
					}
				}
				if (choice == 4)
				{
					drawstring(200.0, 150.0, "OUTPUT FILE", 2);
				}
				if (choice == 5)
				{
					if (!ins_succ)
						drawstring(200.0, 150.0, "CAN'T FIND ANY NODE ", 2);
					else
					{
						if (succAni)
							drawstring(200.0, 150.0, "PROCESSING", 2);
						else
							drawstring(200.0, 150.0, "NODE FOUND!", 2);
					}
				}
			}
			//draw Nodes and the arrow
			else
			{
				glColor3f(0.6f, 1.5f, 1.5f);
				/*glBegin(GL_LINES);
				glVertex2i(x4 + k * 130, y4);
				glVertex2i(x6 + k * 130, y4);
				glEnd();
				glColor3f(0.0f, 0.0f, 0.0f);
				glBegin(GL_LINES);
				glVertex2i(x5 + k * 130, y6);
				glVertex2i(x6 + k * 130, y4);
				glVertex2i(x6 + k * 130, y4);
				glVertex2i(x5 + k * 130, y5);
				glEnd();*/
				glBegin(GL_POLYGON);
				glVertex2i(x3 + k * 130, y4 - 5);
				glVertex2i(x5 + k * 130, y4 - 5);
				glVertex2i(x5 + k * 130, y4 + 5);
				glVertex2i(x3 + k * 130, y4 + 5);
				glEnd();
				glColor3f(0.6f, 1.5f, 1.5f);
				glBegin(GL_TRIANGLES);
				glVertex2i(x5 + k * 130, y4 - 10);
				glVertex2i(x6 + k * 130, y4);
				glVertex2i(x5 + k * 130, y4 + 10);
				glEnd();
				glColor3f(0.0f, 0.2f, 1.70f);
				glBegin(GL_POLYGON);
				glVertex2i(x1 + k * 130, y1);
				glVertex2i(x1 + k * 130, y3);
				glVertex2i(x2 + k * 130, y3);
				glVertex2i(x2 + k * 130, y1);
				glEnd();
				glColor3f(0.0, 0.60, 0.80);
				glBegin(GL_POLYGON);
				glVertex2i(x2 + k * 130, y1);
				glVertex2i(x2 + k * 130, y3);
				glVertex2i(x3 + k * 130, y3);
				glVertex2i(x3 + k * 130, y1);
				glEnd();
				//drawstring(200.0, 150.0, "NEW NODE INSERTED", 2);
			}
			// draw the data in the node with 2 last digits
			//b[j] = temp->data;
			//cout << temp->data;
			int tmp = temp->data;
			temp = temp->pnext;
			//cout << endl;

			//int pos = 85;
			int dig = countdigit(tmp);
			if (dig >= 5)
				dig = 5;
			int pos = 63 + (dig - 1)*(85 - 63) / 4;

			while (tmp > 0 && pos > 45)
			{
				int number = tmp % 10 + 48;
				//ar[i].p = ar[i].p + 48;
				//ar[i].q = b[j] % 10;
				//ar[i].p = ar[i].p + 48;
				//ar[i].q = ar[i].q + 48;
				glColor3f(9.0, 2.0, 0.0);//choose the color
				glRasterPos2f(pos + k * 130, 225.0);//the position of the number displayed in the node with coordinate (x,y)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, number);
				//glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ar[i].q);
				tmp = tmp / 10;
				pos -= 8;
				//dig--;
			}
			drawstring1(50.0 + k * 130, 185, "INFO", 1);
			drawstring1(85.0 + k * 130, 185, "LINK", 1);
			i++;
			j++;
			glFlush();
		}
	}
	if (_trait)
	{
		glPushMatrix();
		glColor3f(1.0f, 0.2f, 1.70f);
		glTranslatef(_xspeed, 0.0f, 0.0f);
		glBegin(GL_LINE_LOOP);
		//glBegin(GL_POLYGON);
		glVertex2i(50, 200);
		glVertex2i(50, 250);
		glVertex2i(110, 250);
		//glVertex2i(110 + _dem * 130, 200);
		glVertex2i(110, 200);
		glEnd();
		glPopMatrix();
		glFlush();
	}
	if (_cut)
	{
		glPushMatrix();
		glColor3f(19.0f, 0.2f, 1.70f);
		glTranslatef(_xspeed, 0.0f, 0.0f);
		glBegin(GL_LINES);
		glVertex2i(50, 200);
		glVertex2i(110, 250);
		glEnd();
		glPopMatrix();
		glFlush();
		glPushMatrix();
		glColor3f(19.0f, 0.2f, 1.70f);
		glTranslatef(_xspeed, 0.0f, 0.0f);
		glBegin(GL_LINES);
		glVertex2i(50, 250);
		glVertex2i(110, 200);
		glEnd();
		glPopMatrix();
		glFlush();
	}
	glutSwapBuffers();
}

void OutputFile(Node * head)
{
	ofstream out;
	out.open("output.txt");
	Node * tmp = head;
	while (tmp != NULL)
	{
		out << tmp->data << " ";
		tmp = tmp->pnext;
	}
	out << endl;
	out.close();
}
void Output(Node * head)
{
	if (head == NULL)
	{
		cout << "List is emtpy" << endl;
		return;
	}
	Node * cur = head;
	cout << "The content of the linked list: ";
	while (cur != NULL)
	{
		cout << cur->data << " ";
		cur = cur->pnext;
	}
	cout << endl;
}
void InputFile(Node *& head, int &n)
{
	ifstream in;
	n = 0;
	Node * cur = head;
	while (cur != NULL && cur->pnext != NULL)
		cur = cur->pnext;
	in.open("input.txt");
	while (!in.eof())
	{

		if (head == NULL)
		{
			head = new Node;
			if (head != NULL)
			{
				cur = head;
				in >> cur->data;
				cur->pnext = NULL;
			}
		}
		else
		{
			Node * tmp = new Node;
			if (tmp != NULL)
			{
				in >> tmp->data;
				cur->pnext = tmp;
				tmp->pnext = NULL;
				cur = cur->pnext;
			}
		}
		n++;
	}
	in.close();
}
void InitEmpty(Node *& head)
{
	head = NULL;
}
void InitRandom(Node *&head, int n)
{
	Node * cur = head;
	while (cur != NULL&&cur->pnext != NULL)
		cur = cur->pnext;
	for (int i = 0; i<n; i++)
	{
		if (head == NULL)
		{
			head = new Node;
			if (head != NULL)
			{
				cur = head;
				cur->data = rand() % 100;
				cur->pnext = NULL;
			}
		}
		else
		{
			Node * tmp = new Node;
			if (tmp != NULL)
			{
				tmp->data = rand() % 100;
				cur->pnext = tmp;
				tmp->pnext = NULL;
				cur = cur->pnext;
			}
		}
	}
}

void InsertHead(Node * &head, int data)
{
	Node *tmp = new Node;
	tmp->data = data;
	tmp->pnext = head;
	head = tmp;
}
void InsertTail(Node * &head, int data)
{
	if (head == NULL)
	{
		Node *tmp = new Node;
		tmp->data = data;
		tmp->pnext = head;
		head = tmp;
		return;
	}
	Node * cur = head;
	while (cur->pnext != NULL)
		cur = cur->pnext;
	Node * tmp = new Node;
	tmp->data = data;
	tmp->pnext = cur->pnext;
	cur->pnext = tmp;
}
void InsertBeforeNode(Node * &head, int data, int k)
{
	if (head == NULL)
	{
		ins_succ = 0;
		return;
	}
	if (head->data == k)
	{
		Node * tmp = new Node;
		tmp->data = data;
		tmp->pnext = head;
		head = tmp;
		return;
	}
	Node *cur = head;
	while (cur->pnext != NULL && cur->pnext->data != k)
		cur = cur->pnext;
	if (cur->pnext == NULL)//check if the is a node k
	{
		cout << "there is no node k in the list" << endl;
		dem--;
		ins_succ = 0;
		return;
	}
	Node * tmp = new Node;
	tmp->data = data;
	tmp->pnext = cur->pnext;
	cur->pnext = tmp;
}
void InsertAfterNode(Node *head, int data, int k)
{
	if (head == NULL)
	{
		ins_succ = 0;
		return;
	}
	Node *cur = head;
	while (cur != NULL && cur->data != k)
	{
		cur = cur->pnext;
	}
	if (cur == NULL)//check if there is a Node k
	{
		cout << "There is no Node k in the list" << endl;
		dem--;
		ins_succ = 0;
		return;
	}
	Node *tmp = new Node;
	tmp->data = data;
	tmp->pnext = cur->pnext;
	cur->pnext = tmp;
}

void RemoveHead(Node * &head)
{
	if (head == NULL)
	{
		cout << "list is empty cannot delete" << endl;
		disp();
		dem++;
		succ = 0;
		return;
	}
	Node * temp = head;
	head = head->pnext;
	delete temp;
}
void RemoveTail(Node * &head)
{
	if (head == NULL)
	{
		cout << "list is empty cannot delete" << endl;
		disp();
		dem++;
		succ = 0;
		return;
	}
	if (head->pnext == NULL)
	{
		delete head;
		head = NULL;
		return;
	}
	Node * tmp = head;
	while (tmp->pnext->pnext != NULL)
		tmp = tmp->pnext;
	Node * cur = tmp->pnext;
	delete cur;
	tmp->pnext = NULL;
}
void RemoveSpecificNode(Node * &head, int k)
{
	if (head == NULL)
	{
		cout << "list is empty cannot delete" << endl;
		disp();
		dem++;
		succ = 0;
		return;
	}
	if (head->data == k)
	{
		Node * tmp = head;
		head = head->pnext;
		delete tmp;
		return;
	}
	Node * cur = head;
	while (cur->pnext != NULL && cur->pnext->data != k)
		cur = cur->pnext;
	if (cur->pnext == NULL)
	{
		cout << "Search is unsuccessful" << endl;
		dem++;
		succ1 = 0;
		succ = 0;
		return;
	}
	Node * tmp = cur->pnext;
	cur->pnext = tmp->pnext;
	delete tmp;
}

void FindSpecificNode(Node * head, int k)
{
	Node * cur = head;
	while (cur != NULL)
	{
		if (cur->data == k)
		{
			ins_succ = 1;
			return;
		}
		else
			cur = cur->pnext;
	}
	//ins_succ = 0;
	//cout << "Can't find k" << endl;
}
void FindInRange(Node * head, int a, int b)
{
	Node * cur = head;
	while (cur != NULL)
	{
		if (cur->data >= a && cur->data <= b)
		{
			ins_succ = 1;
			return;
		}
		else
			cur = cur->pnext;
	}
	//ins_succ = 0;
	//cout << "Can't find any nodes in the range [" << a << "," << b << "]" << endl;
}
void FindLesser(Node * head, int a)
{
	Node * cur = head;
	while (cur != NULL)
	{
		if (cur->data < a)
		{
			ins_succ = 1;
			return;
		}
		else
			cur = cur->pnext;
	}
	//ins_succ = 0;
	//cout << "Can't find any nodes less than " << a << endl;
}
void FindGreater(Node * head, int a)
{
	Node * cur = head;
	while (cur != NULL)
	{
		if (cur->data > a)
		{
			ins_succ = 1;
			return;
		}
		cur = cur->pnext;
	}
	//ins_succ = 0;
	//cout << "Can't find any nodes greater than " << a << endl;
}

void Insert(Node *&head, int k)
{
	if (head == NULL)
	{
		head = new Node;
		if (!head)
		{
			head->data = k;
			head->pnext = NULL;
			return;
		}
	}
	Node * cur = head;
	while (cur->pnext != NULL)
	{
		cur = cur->pnext;
	}
	Node * tmp = new Node;
	if (!tmp)
	{
		tmp->data = k;
		tmp->pnext = NULL;
		cur->pnext = tmp;
	}
}
void MakeEmpty(Node *&head)
{
	Node * cur = head;
	while (cur != NULL)
	{
		head = head->pnext;
		delete cur;
		cur = head;
	}
	head = NULL;
}

//*************************************************************************************************************

void Traverse_One(int value)
{
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		_dem = 0;
		cur = cur->pnext;
		glutPostRedisplay();
		return;
	}
	else  if (cur->pnext == NULL)
	{
		_dem = 0;
		_trait = false;
		glutPostRedisplay();
		return;
	}
	glutTimerFunc(30, Traverse_One, 0);

}
void Traverse_All(int value)
{
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (_time == 30)
		{
			_dem = 0;
			_time = 0;
			cur = cur->pnext;
			glutPostRedisplay();
		}
		else
		{
			_time++;
		}
	}
	else  if (cur->pnext == NULL)
	{
		_dem = 0;
		_trait = false;
		glutPostRedisplay();
		return;
	}
	glutTimerFunc(30, Traverse_All, 0);
}

void FindSmaller_One(int value)
{
	ins_succ = 1;
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL && cur->data >= _data2)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (cur->data >= _data2)
		{
			_dem = 0;
			cur = cur->pnext;
			glutPostRedisplay();
			return;
		}
		else
		{
			succAni = 0;
			_trait = false;
			glutPostRedisplay();
			return;
		}
	}
	else  if (cur->pnext == NULL)
	{
		succAni = 0;
		if (cur->data >= _data2)
			ins_succ = 0;
		_dem = 0;
		_trait = false;
		glutPostRedisplay();
		return;
	}
	glutTimerFunc(30, FindSmaller_One, 0);
}
void FindSmaller_All(int value)
{
	succAni = 1;
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL && cur->data >= _data2)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (_time == 30 && cur->data >= _data2)
		{
			_dem = 0;
			_time = 0;
			cur = cur->pnext;
			glutPostRedisplay();
		}
		else if (cur->data < _data2)
		{
			succAni = 0;
			_time = 0;
			_dem = 0;
			_trait = false;
			glutPostRedisplay();
			return;
		}
		else if (_time < 30)
		{
			_time++;
		}
	}
	else  if (cur->pnext == NULL)
	{
		succAni = 0;
		if (cur->data >= _data2)
			ins_succ = 0;
		_dem = 0;
		_trait = false;
		glutPostRedisplay();
		return;
	}
	glutTimerFunc(30, FindSmaller_All, 0);
}

void FindBigger_One(int value)
{
	ins_succ = 1;
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL && cur->data <= _data2)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (cur->data <= _data2)
		{
			_dem = 0;
			cur = cur->pnext;
			glutPostRedisplay();
			return;
		}
		else
		{
			succAni = 0;
			_dem = 0;
			_trait = false;
			glutPostRedisplay();
			return;
		}
	}
	else  if (cur->pnext == NULL)
	{
		succAni = 0;
		if (cur->data <= _data2)
			ins_succ = 0;
		_dem = 0;
		_trait = false;
		glutPostRedisplay();
		return;
	}
	glutTimerFunc(30, FindBigger_One, 0);
}
void FindBigger_All(int value)
{
	succAni = 1;
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL && cur->data <= _data2)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (_time == 30 && cur->data <= _data2)
		{
			_dem = 0;
			_time = 0;
			cur = cur->pnext;
			glutPostRedisplay();
		}
		else if (cur->data > _data2)
		{
			succAni = 0;
			_time = 0;
			_dem = 0;
			_trait = false;
			glutPostRedisplay();
			return;
		}
		else if (_time < 30)
		{
			_time++;
		}
	}
	else  if (cur->pnext == NULL)
	{
		succAni = 0;
		if (cur->data <= _data2)
			ins_succ = 0;
		_dem = 0;
		_trait = false;
		glutPostRedisplay();
		return;
	}
	glutTimerFunc(30, FindBigger_All, 0);
}

void FindSpecific_One(int value)
{
	ins_succ = 1;
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL && cur->data != _data2)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (cur->data != _data2)
		{
			_dem = 0;
			cur = cur->pnext;
			glutPostRedisplay();
			return;
		}
		else
		{
			succAni = 0;
			_dem = 0;
			_trait = false;
			glutPostRedisplay();
			return;
		}
	}
	else  if (cur->pnext == NULL)
	{
		succAni = 0;
		if (cur->data != _data2)
			ins_succ = 0;
		_dem = 0;
		_trait = false;
		glutPostRedisplay();
		return;
	}
	glutTimerFunc(30, FindSpecific_One, 0);
}
void FindSpecificAll(int value)
{
	ins_succ = 1;
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL && cur->data != _data2)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (_time == 30 && cur->data != _data2)
		{
			_dem = 0;
			_time = 0;
			cur = cur->pnext;
			glutPostRedisplay();
		}
		else if (cur->data == _data2)
		{
			succAni = 0;
			_time = 0;
			_dem = 0;
			_trait = false;
			glutPostRedisplay();
			return;
		}
		else if (_time < 30)
		{
			_time++;
		}
	}
	else  if (cur->pnext == NULL)
	{
		succAni = 0;
		if (cur->data != _data2)
			ins_succ = 0;
		_dem = 0;
		_trait = false;
		glutPostRedisplay();
		return;
	}
	glutTimerFunc(30, FindSpecificAll, 0);
}

void FindRange_One(int value)
{
	int count = 0;
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL && (cur->data <_left || cur->data > _right))
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (cur->data <_left || cur->data > _right)
		{
			_dem = 0;
			cur = cur->pnext;
			glutPostRedisplay();
			return;
		}
		else
		{
			succAni = 0;
			++count;
			_dem = 0;
			_trait = false;
			glutPostRedisplay();
			return;
		}
	}
	else  if (cur->pnext == NULL)
	{
		succAni = 0;
		if (cur->data < _left || cur->data > _right)
		{
			if (count == 0)
				ins_succ = 0;
		}
		_dem = 0;
		_trait = false;
		glutPostRedisplay();
		return;
	}
	glutTimerFunc(30, FindRange_One, 0);
}
void FindRange_All(int value)
{
	int count = 0;
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem < 26 && cur->pnext != NULL && (cur->data < _left || cur->data > _right))
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (_time == 30 && (cur->data < _left || cur->data > _right))
		{
			_dem = 0;
			_time = 0;
			cur = cur->pnext;
			glutPostRedisplay();
		}
		else if (cur->data >= _left && cur->data <= _right)
		{
			succAni = 0;
			++count;
			_time = 0;
			_dem = 0;
			_trait = false;
			glutPostRedisplay();
			return;
		}
		else if (_time < 30)
		{
			_time++;
		}
	}
	else  if (cur->pnext == NULL)
	{
		succAni = 0;
		if (cur->data < _left || cur->data > _right)
		{
			if (count == 0)
				ins_succ = 0;
		}
		_dem = 0;
		_trait = false;
		glutPostRedisplay();
		return;
	}
	glutTimerFunc(30, FindRange_All, 0);
}

void RemoveTail_One(int value)
{
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		_dem = 0;
		cur = cur->pnext;
		glutPostRedisplay();
		return;
	}
	else  if (cur->pnext == NULL)
	{
		if (_dem == 0)
		{
			_dem++;
			_cut = true;
			glutPostRedisplay();
			return;
		}
		else if (_dem == 1)
		{
			succAni = 0;
			_dem = 0;
			_trait = false;
			_cut = false;
			RemoveTail(head);
			dem--;
			Output(head);
			cur = NULL;
			glutPostRedisplay();
			return;
		}
		return;
	}
	glutTimerFunc(30, RemoveTail_One, 0);

}
void RemoveTail_All(int value)
{
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (_time == 30)
		{
			_dem = 0;
			_time = 0;
			cur = cur->pnext;
			if (cur->pnext == NULL)
			{
				_cut = true;
			}
			glutPostRedisplay();
		}
		else
		{
			_time++;
		}
	}
	else  if (cur->pnext == NULL)
	{
		succAni = 0;
		_dem = 0;
		_trait = false;
		_cut = false;
		RemoveTail(head);
		dem--;
		Output(head);
		cur = NULL;
		glutPostRedisplay();
		return;
	}
	glutTimerFunc(30, RemoveTail_All, 0);
}

void RemoveSpecific_One(int value)
{
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL && cur->data != _data2)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (cur->data != _data2)
		{
			_dem = 0;
			cur = cur->pnext;
			glutPostRedisplay();
			return;
		}
		else
		{
			if (_dem == 0)
			{
				_cut = true;
				_dem++;
				glutPostRedisplay();
				return;
			}
			if (_dem == 1)
			{
				succAni = 0;
				_dem = 0;
				_trait = false;
				_cut = false;
				RemoveSpecificNode(head, _data2);
				dem--;
				cur = NULL;
				Output(head);
				glutPostRedisplay();
				return;
			}
		}
	}
	else  if (cur->pnext == NULL)
	{
		if (cur->data == _data2)
		{
			if (_dem == 0)
			{
				_dem++;
				_cut = true;
				glutPostRedisplay();
				return;
			}
			else if (_dem == 1)
			{
				succAni = 0;
				RemoveSpecificNode(head, _data2);
				dem--;
				cur = NULL;
				Output(head);
				_dem = 0;
				_trait = false;
				_cut = false;
				glutPostRedisplay();
				return;
			}
		}
		else
		{
			_dem = 0;
			_trait = false;
			_cut = false;
			glutPostRedisplay();
			return;
		}
	}
	glutTimerFunc(30, RemoveSpecific_One, 0);
}
void RemoveSpecific_All(int value)
{
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL && cur->data != _data2)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (_time == 30 && cur->data != _data2)
		{
			_dem = 0;
			_time = 0;
			cur = cur->pnext;
			if (cur->data == _data2)
				_cut = true;
			glutPostRedisplay();
		}
		else if (cur->data == _data2)
		{
			if (_time == 30)
			{
				succAni = 0;
				_time = 0;
				_dem = 0;
				_cut = false;
				_trait = false;
				RemoveSpecificNode(head, _data2);
				dem--;
				Output(head);
				cur = NULL;
				glutPostRedisplay();
				return;
			}
			else
				_time++;
		}
		else if (_time < 30)
		{
			_time++;
		}
	}
	else  if (cur->pnext == NULL)
	{
		if (cur->data == _data2)
		{
			if (_time == 30)
			{
				succAni = 0;
				_time = 0;
				_dem = 0;
				_cut = false;
				_trait = false;
				RemoveSpecificNode(head, _data2);
				dem--;
				Output(head);
				cur = NULL;
				glutPostRedisplay();
				return;
			}
			else
				_time++;
		}
		else
		{
			succ = 0;
			_dem = 0;
			_trait = false;
			_cut = false;
			glutPostRedisplay();
			return;
		}
	}
	glutTimerFunc(30, RemoveSpecific_All, 0);
}

void RemoveHead_One(int value)
{
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem == 0)
	{
		_cut = true;
		_dem++;
		display();
		glutPostRedisplay();
		return;
	}
	if (_dem == 1)
	{
		succAni = 0;
		_dem = 0;
		RemoveHead(head);
		Output(head);
		dem--;
		_cut = false;
		_trait = false;
		cur = NULL;
		glutPostRedisplay();
		return;
	}
}
void RemoveHead_All(int value)
{
	if (cur = NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_time == 100 && _dem == 0)
	{
		_time = 0;
		_dem = 1;
		_cut = true;
		glutPostRedisplay();
	}
	else if (_time == 100 && _dem == 1)
	{
		succAni = 0;
		_time = 0;
		_dem = 0;
		_cut = false;
		_trait = false;
		RemoveHead(head);
		dem--;
		cur = NULL;
		Output(head);
		glutPostRedisplay();
		return;
	}
	else if (_time != 100)
		_time++;
	glutTimerFunc(30, RemoveHead_All, 0);
}

void InsertTail_One(int value)
{
	if (cur == NULL)
	{
		_trait = false;
		dem++;
		InsertTail(head, _data2);
		Output(head);
		cur = NULL;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		_dem = 0;
		cur = cur->pnext;
		glutPostRedisplay();
		return;
	}
	else  if (cur->pnext == NULL)
	{
		succAni = 0;
		_dem = 0;
		_trait = false;
		InsertTail(head, _data2);
		dem++;
		Output(head);
		cur = NULL;
		glutPostRedisplay();
		return;
	}
	glutTimerFunc(30, InsertTail_One, 0);
}
void InsertTail_All(int value)
{
	if (cur == NULL)
	{
		succAni = 0;
		_trait = false;
		dem++;
		InsertTail(head, _data2);
		Output(head);
		cur = NULL;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (_time == 30)
		{
			_dem = 0;
			_time = 0;
			cur = cur->pnext;
			glutPostRedisplay();
		}
		else
		{
			_time++;
		}
	}
	else  if (cur->pnext == NULL)
	{
		if (_time == 30)
		{
			succAni = 0;
			_dem = 0;
			_trait = false;
			InsertTail(head, _data2);
			dem++;
			Output(head);
			cur = NULL;
			glutPostRedisplay();
			return;
		}
		else {
			_time++;
		}
	}
	glutTimerFunc(30, InsertTail_All, 0);
}

void InsertHead_All(int value)
{
	if (_time == 100)
	{
		_time = 0;
		_dem = 0;
		_trait = false;
		succAni = 0;
		InsertHead(head, _data2);
		dem++;
		cur = NULL;
		Output(head);
		glutPostRedisplay();
		return;
	}
	else if (_time != 100)
		_time++;
	glutTimerFunc(30, InsertHead_All, 0);
}
void InserHead_One(int value)
{
	succAni = 0;
	_trait = false;
	_time = 0;
	_dem = 0;
	InsertHead(head, _data2);
	Output(head);
	dem++;
	glutPostRedisplay();
	return;
}

void InsertBefore_One(int value)
{
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL && cur->data != _data3)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (cur->data != _data3)
		{
			_dem = 0;
			cur = cur->pnext;
			glutPostRedisplay();
			return;
		}
		else
		{
			succAni = 0;
			_dem = 0;
			_trait = false;
			InsertBeforeNode(head, _data2, _data3);
			dem++;
			cur = NULL;
			Output(head);
			glutPostRedisplay();
			return;
		}
	}
	else  if (cur->pnext == NULL)
	{
		if (cur->data == _data3)
		{
			succAni = 0;
			_dem = 0;
			_trait = false;
			cur = NULL;
			InsertBeforeNode(head, _data2, _data3);
			dem++;
			Output(head);
			glutPostRedisplay();
			return;
		}
		else
		{
			ins_succ = 0;
			_dem = 0;
			_trait = false;
			glutPostRedisplay();
			return;
		}
	}
	glutTimerFunc(30, InsertBefore_One, 0);
}
void InsertBefore_All(int value)
{
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL && cur->data != _data3)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (_time == 30 && cur->data != _data3)
		{
			_dem = 0;
			_time = 0;
			cur = cur->pnext;
			glutPostRedisplay();
		}
		else if (cur->data == _data3)
		{
			succAni = 0;
			_time = 0;
			_dem = 0;
			_trait = false;
			InsertBeforeNode(head, _data2, _data3);
			dem++;
			Output(head);
			glutPostRedisplay();
			return;
		}
		else if (_time < 30)
		{
			_time++;
		}
	}
	else  if (cur->pnext == NULL)
	{
		if (cur->data == _data3)
		{
			succAni = 0;
			_time = 0;
			_dem = 0;
			_trait = false;
			InsertBeforeNode(head, _data2, _data3);
			dem++;
			Output(head);
			glutPostRedisplay();
			return;
		}
		else
		{
			ins_succ = 0;
			_dem = 0;
			_trait = false;
			glutPostRedisplay();
			return;
		}
	}
	glutTimerFunc(30, InsertBefore_All, 0);
}

void InsertAfter_All(int value)
{
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL && cur->data != _data3)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (_time == 30 && cur->data != _data3)
		{
			_dem = 0;
			_time = 0;
			cur = cur->pnext;
			glutPostRedisplay();
		}
		else if (cur->data == _data3)
		{
			succAni = 0;
			_time = 0;
			_dem = 0;
			_trait = false;
			InsertAfterNode(head, _data2, _data3);
			dem++;
			Output(head);
			glutPostRedisplay();
			return;
		}
		else if (_time < 30)
		{
			_time++;
		}
	}
	else  if (cur->pnext == NULL)
	{
		if (cur->data == _data3)
		{
			succAni = 0;
			_time = 0;
			_dem = 0;
			_trait = false;
			InsertAfterNode(head, _data2, _data3);
			dem++;
			Output(head);
			glutPostRedisplay();
			return;
		}
		else
		{
			ins_succ = 0;
			_dem = 0;
			_trait = false;
			glutPostRedisplay();
			return;
		}
	}
	glutTimerFunc(30, InsertAfter_All, 0);
}
void InsertAfter_One(int value)
{
	if (cur == NULL)
	{
		_trait = false;
		glutPostRedisplay();
		return;
	}
	if (_dem<26 && cur->pnext != NULL && cur->data != _data3)
	{
		_xspeed += 5.0f;
		_dem++;
		glutPostRedisplay();
	}
	else if (cur->pnext != NULL)
	{
		if (cur->data != _data3)
		{
			_dem = 0;
			cur = cur->pnext;
			glutPostRedisplay();
			return;
		}
		else
		{
			succAni = 0;
			_dem = 0;
			_trait = false;
			InsertAfterNode(head, _data2, _data3);
			dem++;
			cur = NULL;
			Output(head);
			glutPostRedisplay();
			return;
		}
	}
	else  if (cur->pnext == NULL)
	{
		if (cur->data == _data3)
		{
			succAni = 0;
			_dem = 0;
			_trait = false;
			cur = NULL;
			InsertAfterNode(head, _data2, _data3);
			dem++;
			Output(head);
			glutPostRedisplay();
			return;
		}
		else
		{
			ins_succ = 0;
			_dem = 0;
			_trait = false;
			glutPostRedisplay();
			return;
		}
	}
	glutTimerFunc(30, InsertAfter_One, 0);
}

//*************************************************************************************************************
enum
{
	INIT_EMPTY = 0,
	RANDOM,
	INPUT_FILE,
	INSERT_HEAD,
	INSERT_TAIL,
	INSERT_BEFORE,
	INSERT_AFTER,
	DELETE_HEAD,
	DELETE_TAIL,
	DELETE_SPECIFIC,
	OUTPUT_FILE,
	FIND_LESSER,
	FIND_GREATER,
	FIND_SPECIFIC,
	FIND_IN_RANGE,
	QUIT,

	NEXT,
	PREVIOUS,
};

void myGlutIdle()
{
	if (glutGetWindow() != main_window)
		glutSetWindow(main_window);

	glutPostRedisplay();
}

void glui_callback(int id)
{
	if (ao)
	{
		switch (id)
		{
		case INIT_EMPTY:
			InitEmpty(head);
			inistate();
			display();
			glutDisplayFunc(display);
			glFlush();
			break;
		case RANDOM:
			choice = 0;
			InitRandom(head, _data1);
			dem += _data1;
			display();
			glutDisplayFunc(display);
			glFlush();//put an end for the programm to know it is the end of animation and show out
			break;
		case INPUT_FILE:
			choice = 1;
			InputFile(head, num);
			dem += num;
			display();
			glutDisplayFunc(display);
			glFlush();//put an end for the programm to know it is the end of animation and show out
			break;
		case INSERT_HEAD:
			succAni = 1; // print out line "being inserted" then "inserted"
			choice = 2;
			_xspeed = 0;
			_trait = true;
			_dem = 0;
			cur = head;
			inistate();
			display();
			glutDisplayFunc(display);
			glutTimerFunc(100, InsertHead_All, 0);
			glFlush();
			break;
		case INSERT_TAIL:
			succAni = 1;
			choice = 2;
			_xspeed = 0;
			_trait = true;
			_dem = 0;
			cur = head;
			display();
			glutDisplayFunc(display);
			glutTimerFunc(100, InsertTail_All, 0);
			glFlush();
			break;
		case INSERT_BEFORE:
			ins_succ = 1;
			succAni = 1;
			choice = 2;
			_xspeed = 0;
			_trait = true;
			_dem = 0;
			cur = head;
			inistate();
			glutTimerFunc(100, InsertBefore_All, 0);
			display();
			glutDisplayFunc(display);
			glFlush();
			break;
		case INSERT_AFTER:
			ins_succ = 1;
			succAni = 1;
			choice = 2;
			_xspeed = 0;
			_trait = true;
			_dem = 0;
			cur = head;
			inistate();
			glutTimerFunc(100, InsertAfter_All, 0);
			display();
			glutDisplayFunc(display);
			glFlush();
			break;
		case DELETE_HEAD:
			succAni = 1;
			choice = 3;
			if (head == NULL)
				succ = 0;
			else succ = 1;
			_xspeed = 0;
			_trait = true;
			_cut = false;
			cur = head;
			_time = 0;
			_dem = 0;
			inistate();
			display();
			glutDisplayFunc(display);
			glutTimerFunc(0, RemoveHead_All, 0);
			glFlush();
			break;
		case DELETE_TAIL:
			succAni = 1;
			choice = 3;
			if (head != NULL)
				succ = 1;
			else succ = 0;
			cur = head;
			_xspeed = 0;
			_trait = true;
			inistate();
			display();
			glutDisplayFunc(display);
			glutTimerFunc(0, RemoveTail_All, 0);
			glFlush();
			break;
		case DELETE_SPECIFIC:
			succAni = 1;
			choice = 3;
			_xspeed = 0;
			_trait = true;
			cur = head;
			succ = 1; // succ = succ1 = 1 ???? succ1
			inistate();
			display();
			glutDisplayFunc(display);
			glutTimerFunc(300, RemoveSpecific_All, 0);
			glFlush();
			break;
		case OUTPUT_FILE:
			succAni = 1;
			choice = 4;
			_trait = true;
			_xspeed = 0;
			inistate();
			OutputFile(head);
			cur = head;
			glutTimerFunc(100, Traverse_All, 0);
			glFlush();
			break;
		case FIND_LESSER:
			succAni = 1;
			ins_succ = 1;
			choice = 5;
			_trait = true;
			cur = head;
			_xspeed = 0;
			FindLesser(head, _data2);
			inistate();
			display();
			glutDisplayFunc(display);
			glutTimerFunc(100, FindSmaller_All, 0);
			glFlush();
			break;
		case FIND_GREATER:
			succAni = 1;
			ins_succ = 1;
			choice = 5;
			_trait = true;
			cur = head;
			_xspeed = 0;
			FindGreater(head, _data2);
			inistate();
			display();
			glutDisplayFunc(display);
			glutTimerFunc(100, FindBigger_All, 0);
			glFlush();
			break;
		case FIND_SPECIFIC:
			succAni = 1;
			ins_succ = 1;
			choice = 5;
			_trait = true;
			cur = head;
			_xspeed = 0;
			FindSpecificNode(head, _data2);
			inistate();
			display();
			glutDisplayFunc(display);
			glutTimerFunc(100, FindSpecificAll, 0);
			glFlush();
			break;
		case FIND_IN_RANGE:
			succAni = 1;
			ins_succ = 1;
			choice = 5;
			_trait = true;
			cur = head;
			_xspeed = 0;
			FindInRange(head, _left, _right);
			inistate();
			display();
			glutDisplayFunc(display);
			glutTimerFunc(100, FindRange_All, 0);
			glFlush();
			break;
		default:
			return;
		}
	}
	if (sbs)
	{
		switch (id)
		{
		case INIT_EMPTY:
			InitEmpty(head);
			inistate();
			display();
			glutDisplayFunc(display);
			glFlush();
			break;
		case RANDOM:
			choice = 0;
			InitRandom(head, _data1);
			dem += _data1;
			display();
			glutDisplayFunc(display);
			glFlush();//put an end for the programm to know it is the end of animation and show out
			break;
		case INPUT_FILE:
			choice = 1;
			InputFile(head, num);
			dem += num;
			display();
			glutDisplayFunc(display);
			glFlush();//put an end for the programm to know it is the end of animation and show out
			break;
		case INSERT_HEAD:
			succAni = 1;
			ins_succ = 1;
			choice = 2;
			_choose = 1;
			_xspeed = 0;
			_trait = true;
			_dem = 0;
			cur = head;
			inistate();
			display();
			glutDisplayFunc(display);
			glFlush();//put an end for the programm to know it is the end of animation and show out
			break;
		case INSERT_TAIL:
			ins_succ = 1;
			succAni = 1;
			choice = 2;
			_choose = 2;
			_xspeed = 0;
			_trait = true;
			_dem = 0;
			cur = head;
			inistate();
			display();
			glutDisplayFunc(display);
			glFlush();//put an end for the programm to know it is the end of animation and show out
			break;
		case INSERT_BEFORE:
			ins_succ = 1;
			succAni = 1;
			choice = 2;
			_choose = 3;
			_xspeed = 0;
			_trait = true;
			_dem = 0;
			cur = head;
			inistate();
			display();
			glutDisplayFunc(display);
			glFlush();
			break;
		case INSERT_AFTER:
			ins_succ = 1;
			succAni = 1;
			choice = 2;
			_choose = 4;
			_xspeed = 0;
			_trait = true;
			_dem = 0;
			cur = head;
			inistate();
			display();
			glutDisplayFunc(display);
			glFlush();
			break;
		case DELETE_HEAD:
			succAni = 1;
			choice = 3;
			_choose = 5;
			_xspeed = 0;
			_trait = true;
			_cut = false;
			cur = head;
			_time = 0;
			_dem = 0;
			inistate();
			display();
			glutDisplayFunc(display);
			glFlush();
			break;
		case DELETE_TAIL:
			succAni = 1;
			choice = 3;
			_choose = 6;
			_xspeed = 0;
			_trait = true;
			_cut = false;
			cur = head;
			_time = 0;
			_dem = 0;
			inistate();
			display();
			glutDisplayFunc(display);
			glFlush();
			break;
		case DELETE_SPECIFIC:
			succAni = 1;
			choice = 3;
			_choose = 7;
			_xspeed = 0;
			_trait = true;
			_cut = false;
			cur = head;
			_time = 0;
			_dem = 0;
			inistate();
			display();
			glutDisplayFunc(display);
			glFlush();
			break;
		case OUTPUT_FILE:
			choice = 4;
			_choose = 8;
			_trait = true;
			_xspeed = 0;
			inistate();
			OutputFile(head);
			cur = head;
			glFlush();
			break;
		case FIND_LESSER:
			ins_succ = 1;
			succAni = 1;
			choice = 5;
			_choose = 9;
			_trait = true;
			cur = head;
			_xspeed = 0;
			FindLesser(head, _data2);
			inistate();
			display();
			glutDisplayFunc(display);
			glFlush();
			break;
		case FIND_GREATER:
			ins_succ = 1;
			succAni = 1;
			choice = 5;
			_choose = 10;
			_trait = true;
			cur = head;
			_xspeed = 0;
			FindGreater(head, _data2);
			inistate();
			display();
			glutDisplayFunc(display);
			glFlush();
			break;
		case FIND_SPECIFIC:
			ins_succ = 1;
			succAni = 1;
			choice = 5;
			_choose = 11;
			_trait = true;
			cur = head;
			_xspeed = 0;
			FindSpecificNode(head, _data2);
			inistate();
			display();
			glutDisplayFunc(display);
			glFlush();
			break;
		case FIND_IN_RANGE:
			ins_succ = 1;
			succAni = 1;
			choice = 5;
			_choose = 12;
			_trait = true;
			cur = head;
			_xspeed = 0;
			FindInRange(head, _left, _right);
			inistate();
			display();
			glutDisplayFunc(display);
			glFlush();
			break;

		case NEXT:
			if (_choose == 1)
			{
				glutTimerFunc(0, InserHead_One, 0);
				glFlush();
				return;
			}
			if (_choose == 2)
			{
				glutTimerFunc(0, InsertTail_One, 0);
				glFlush();
				return;
			}
			if (_choose == 3)
			{
				glutTimerFunc(0, InsertBefore_One, 0);
				glFlush();
				return;
			}
			if (_choose == 4)
			{
				glutTimerFunc(0, InsertAfter_One, 0);
				glFlush();
				return;
			}
			if (_choose == 5)
			{
				glutTimerFunc(0, RemoveHead_One, 0);
				glFlush();
				return;
			}
			if (_choose == 6)
			{
				glutTimerFunc(0, RemoveTail_One, 0);
				glFlush();
				return;
			}
			else if (_choose == 7)
			{
				glutTimerFunc(0, RemoveSpecific_One, 0);
				glFlush();
				return;
			}
			else if (_choose == 8)
			{
				glutTimerFunc(0, Traverse_One, 0);
				glFlush();
				return;
			}
			else if (_choose == 9)
			{
				glutTimerFunc(0, FindSmaller_One, 0);
				glFlush();
				return;
			}
			else if (_choose == 10)
			{
				glutTimerFunc(0, FindBigger_One, 0);
				glFlush();
				return;
			}
			else if (_choose == 11)
			{
				glutTimerFunc(0, FindSpecific_One, 0);
				glFlush();
				return;
			}
			else if (_choose == 12)
			{
				glutTimerFunc(0, FindRange_One, 0);
				glFlush();
				return;
			}
			break;
		case PREVIOUS:
			RollBack();
			break;
		default:
			return;
		}
	}
}

void setupGLUI()
{
	GLUI *glui = GLUI_Master.create_glui_subwindow(main_window, GLUI_SUBWINDOW_RIGHT);

	GLUI_Panel *panel1 = glui->add_panel("Data Panel");
	glui->add_statictext_to_panel(panel1, "Amount of numbers to random");
	glui->add_edittext_to_panel(panel1, "Data 1: ", GLUI_EDITTEXT_INT, &_data1);
	glui->add_statictext_to_panel(panel1, "Insert/Delete(Head/Tail) and Find(Lesser/Larger/Specific) data");
	glui->add_edittext_to_panel(panel1, "Data 2: ", GLUI_EDITTEXT_INT, &_data2);
	glui->add_separator_to_panel(panel1);
	glui->add_statictext_to_panel(panel1, "data to be Inserted(After/Before)");
	glui->add_edittext_to_panel(panel1, "Data 3: ", GLUI_EDITTEXT_INT, &_data3);
	glui->add_statictext_to_panel(panel1, "Find In Range data");
	glui->add_edittext_to_panel(panel1, "Left: ", GLUI_EDITTEXT_INT, &_left);
	glui->add_edittext_to_panel(panel1, "Right: ", GLUI_EDITTEXT_INT, &_right);

	GLUI_Panel *panel2 = glui->add_panel("Control Panel");
	GLUI_Button *empty = glui->add_button_to_panel(panel2, "Empty List", INIT_EMPTY, glui_callback);
	GLUI_Button *insert_head = glui->add_button_to_panel(panel2, "Insert Head", INSERT_HEAD, glui_callback);
	GLUI_Button *insert_tail = glui->add_button_to_panel(panel2, "Insert Tail", INSERT_TAIL, glui_callback);
	GLUI_Button *insert_before = glui->add_button_to_panel(panel2, "Insert Before", INSERT_BEFORE, glui_callback);
	GLUI_Button *insert_after = glui->add_button_to_panel(panel2, "Insert After", INSERT_AFTER, glui_callback);
	glui->add_column_to_panel(panel2, true);
	GLUI_Button *random = glui->add_button_to_panel(panel2, "Random", RANDOM, glui_callback);
	GLUI_Button *input_file = glui->add_button_to_panel(panel2, "Input File", INPUT_FILE, glui_callback);
	GLUI_Button *delete_head = glui->add_button_to_panel(panel2, "Delete Head", DELETE_HEAD, glui_callback);
	GLUI_Button *delete_tail = glui->add_button_to_panel(panel2, "Delete Tail", DELETE_TAIL, glui_callback);
	GLUI_Button *delete_specific = glui->add_button_to_panel(panel2, "Delete Specific", DELETE_SPECIFIC, glui_callback);
	glui->add_column_to_panel(panel2, true);
	GLUI_Button *find_lesser = glui->add_button_to_panel(panel2, "Find Lesser", FIND_LESSER, glui_callback);
	GLUI_Button *find_greater = glui->add_button_to_panel(panel2, "Find Greater", FIND_GREATER, glui_callback);
	GLUI_Button *find_specific = glui->add_button_to_panel(panel2, "Find Specific", FIND_SPECIFIC, glui_callback);
	GLUI_Button *find_in_range = glui->add_button_to_panel(panel2, "Find In Range", FIND_IN_RANGE, glui_callback);
	GLUI_Button *output_file = glui->add_button_to_panel(panel2, "Output File", OUTPUT_FILE, glui_callback);

	GLUI_Panel *option_panel = glui->add_panel("Animation Properties");
	glui->add_checkbox_to_panel(option_panel, "At once", &ao);
	glui->add_checkbox_to_panel(option_panel, "Step by Step", &sbs);
	GLUI_Button *previous = glui->add_button_to_panel(option_panel, "Previous", PREVIOUS, glui_callback);
	GLUI_Button *next = glui->add_button_to_panel(option_panel, "Next", NEXT, glui_callback);

	glui->add_separator();
	glui->add_button("Quit", QUIT, (GLUI_Update_CB)exit);

	glui->set_main_gfx_window(main_window);
}

//*************************************************************************************************************