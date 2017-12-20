#include"Project.h"

void resize(int w, int h)
{
	// float ratio = 1;
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;
	glViewport(0, 0, (h - (w / ratio))>0 ? w : (int)(h*ratio), (w - (h*ratio))>0 ? h : (int)(w / ratio));
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

void animation()//show animation
{
	delay();
	//glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 0.4f, 0.0f);
	glColor3f(6.0, 16.0, 5.6);
	int k = 0, i = 0;
	GLfloat x1 = 50, x2 = 95, x3 = 110, y1 = 200, y2 = 225, y3 = 250,
		x4 = 95, y4 = 225, x5 = 160, y5 = 210, y6 = 240, x6 = 180;
	GLfloat posx = x4, posy = y4, xspeed = 10;

	//draw the last node with pnext ==NULL
	if (head->pnext == NULL)
	{
		delay();
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
	}
	//draw Nodes and the arrow
	else
	{
		delay();
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
	}
	// draw the data in the node with 2 last digits

	int tmp = head->data;
	//int pos = 85;
	int dig = countdigit(tmp);
	if (dig >= 5)
		dig = 5;
	int pos = 63 + (dig - 1)*(85 - 63) / 4;
	delay();
	while (tmp > 0 && pos > 45)
	{
		ar[i].p = tmp % 10;
		ar[i].p = ar[i].p + 48;
		//ar[i].q = b[j] % 10;
		//ar[i].p = ar[i].p + 48;
		//ar[i].q = ar[i].q + 48;
		glColor3f(9.0, 2.0, 0.0);//choose the color
		glRasterPos2f(pos + k * 130, 225.0);//the position of the number displayed in the node with coordinate (x,y)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ar[i].p);
		//glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ar[i].q);
		tmp = tmp / 10;
		pos -= 8;
		//dig--;
	}
	drawstring1(50.0 + k * 130, 185, "INFO", 1);
	drawstring1(85.0 + k * 130, 185, "LINK", 1);
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
	drawstring(200.0, 450.0, "COMPUTER GRAPHICS PROJECT 2", 1);
	drawstring(50.0, 350.0, "GROUP ID: 6 ", 3);
	drawstring(50.0, 300.0, "Ho Chi Minh University of Science", 3);
	drawstring(100.0, 250.0, "", 2);
	drawstring(50.0, 250.0, "Dinh Dat Thanh", 3);
	drawstring(50.0, 200.0, "Nguy Thien Ban", 3);
	drawstring(50.0, 150.0, "Ta Huy Hoang", 3);
	drawstring(50.0, 100.0, "", 3);
	drawstring(150.0, 100.0, "(Click Right Mouse Button For Options)", 2);
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
	drawstring(250, 250, "Empty list", 0);
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

void display()//show maximum 5 digits
{
	int i = 0, j = 0, k = 0, b[20];
	Node * temp = NULL;

	glClear(GL_COLOR_BUFFER_BIT);//clear the current screen
	glClearColor(1.0f, 1.0f, 0.4f, 0.0f);
	glColor3f(6.0, 16.0, 5.6);
	if (head == NULL)
	{
		cout << "list is empty" << endl;
		disp();
		return;
	}
	cout << "contents of singly linked list" << endl;
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
			}
			// draw the data in the node with 2 last digits
			//b[j] = temp->data;
			cout << temp->data;
			int tmp = temp->data;
			temp = temp->pnext;
			cout << endl;

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
	glutSwapBuffers();
}

void submenu(int choose)
{
	switch (choose)
	{
	case 1:exit(0);
	case 2:exit(0);
	}
}

void ao_menu(int choice)
{
	int k;
	switch (choice)
	{
	case 1:
		iniempty(head);
		display();
		glutDisplayFunc(display);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		glFlush();//put an end for the programm to know it is the end of animation and show out
		break;
	case 2:
		do
		{
			cout << "How many node do you want? ";
			cin >> item;
		} while (item<0);
		inirandom(head, item);
		dem += item;
		display();
		glutDisplayFunc(display);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		drawstring(200.0, 150.0, "NEW NODE INSERTED", 2);
		glFlush();//put an end for the programm to know it is the end of animation and show out
		break;
	case 3:
		inputfile(head, num);
		dem += num;
		display();
		glutDisplayFunc(display);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		drawstring(200.0, 150.0, "INPUT FROM FILE", 2);
		glFlush();//put an end for the programm to know it is the end of animation and show out
		break;
	case 4:

		cout << "Do you want to put in or random? (p: put in, otherwise random)";
		cin >> ch;
		if (ch == 'p')
		{
			cout << "enter the item to be inserted: ";
			cin >> item;
		}
		else
			item = rand() % 100;
		cin.get();
		inserthead(head, item);
		dem++;
		display();
		glutDisplayFunc(display);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		drawstring(200.0, 150.0, "NEW NODE INSERTED", 2);
		glFlush();//put an end for the programm to know it is the end of animation and show out
		break;
	case 5:
		cout << "Do you want to put in or random? (p: put in, otherwise random)";
		cin >> ch;
		if (ch == 'p')
		{
			cout << "enter the item to be inserted: ";
			cin >> item;
		}
		else
			item = rand() % 100;
		cin.get();
		inserttail(head, item);
		dem++;
		display();
		glutDisplayFunc(display);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		drawstring(200.0, 150.0, "NEW NODE INSERTED", 2);
		glFlush();
		break;
	case 6:
		cout << "enter the item to be inserted : ";
		cin >> item;
		cout << "enter the value of the node you want to insert after: ";
		cin >> k;
		ins_succ = 1;
		insertafterNode(head, item, k);
		dem++;
		display();
		glutDisplayFunc(display);
		if (!ins_succ)
			drawstring(200.0, 150.0, "KEY NODE DOESN'T EXIST", 2);
		else
			drawstring(200.0, 150.0, "NEW NODE INSERTED", 2);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		glFlush();
		break;
	case 7:
		cout << "enter the item to be inserted : ";
		cin >> item;
		cout << "enter the value of the node you want to insert before: ";
		cin >> k;
		ins_succ = 1;
		insertbeforeNode(head, item, k);
		dem++;
		display();
		glutDisplayFunc(display);
		if (!ins_succ)
			drawstring(200.0, 150.0, "KEY NODE DOESN'T EXIST", 2);
		else
			drawstring(200.0, 150.0, "NEW NODE INSERTED", 2);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		glFlush();
		break;
	case 8:
		succ = 1;
		removehead(head);
		dem--;
		display();
		glutDisplayFunc(display);
		if (succ)
			drawstring(200.0, 150.0, "NODE DELETED", 2);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		glFlush();
		break;
	case 9:
		succ = 1;
		removetail(head);
		dem--;
		display();
		glutDisplayFunc(display);
		if (succ)
			drawstring(200.0, 150.0, "NODE DELETED", 2);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		glFlush();
		break;
	case 10:
		succ = succ1 = 1;
		cout << "Which node do you want to delete? ";
		cin >> item;
		removespecificnode(head, item);
		dem--;
		display();
		glutDisplayFunc(display);
		if (succ)
			drawstring(200.0, 150.0, "NODE DELETED", 2);
		if (!succ1)
			drawstring(200.0, 150.0, "KEY NODE DOESN'T EXIST", 2);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		glFlush();
		break;
	case 11:

		display();
		glutDisplayFunc(display);
		drawstring(200.0, 150.0, "LINKED LIST OUTPUT", 2);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		outputfile(head);
		glFlush();
		break;
	case 12:
		int temp;
		cout << "Input the number to find smaller: ";
		cin >> temp;
		findlessthan(head, temp);
		display();
		glutDisplayFunc(display);
		if (!ins_succ)
			drawstring(200.0, 150.0, "CAN'T FIND ANY NODE ", 2);
		else
			drawstring(200.0, 150.0, "NODE FOUND!", 2);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		glFlush();
		break;
	case 13:

		//int temp;
		cout << "Input the number to find greater: ";
		cin >> temp;
		findgreaterthan(head, temp);
		display();
		glutDisplayFunc(display);
		if (!ins_succ)
			drawstring(200.0, 150.0, "CAN'T FIND ANY NODE ", 2);
		else
			drawstring(200.0, 150.0, "NODE FOUND!", 2);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		glFlush();
		break;
	case 14:

		// temp;
		cout << "Input the number to find : ";
		cin >> temp;
		findaspecificNode(head, temp);
		display();
		glutDisplayFunc(display);
		if (!ins_succ)
			drawstring(200.0, 150.0, "CAN'T FIND THE NODE ", 2);
		else
			drawstring(200.0, 150.0, "NODE FOUND!", 2);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		glFlush();
		break;
	case 15:

		int left, right;
		do
		{
			cout << "Input the the range: ";
			cin >> left >> right;
		} while (right<left);
		findinrange(head, left, right);
		display();
		glutDisplayFunc(display);
		if (!ins_succ)
			drawstring(200.0, 150.0, "CAN'T FIND ANY NODE ", 2);
		else
			drawstring(200.0, 150.0, "NODE FOUND!", 2);
		drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
		glFlush();
		break;
	case 16:
		exit(0);
	}
}

void ani_menu(int choice)
{
	int k;
	switch (choice)
	{
	case 1:
		cout << "enter the item to be inserted: ";
		cin >> item;
		glClear(GL_COLOR_BUFFER_BIT);
		if (head != NULL)
		{
			glTranslatef(80.0f, 0.0f, 0.0f);
			display();

			inserthead(head, item);
			dem++;
			animation();
		}
		else
		{

			drawstring(200.0, 450.0, "SINGLY LINKED LIST", 1);
			inserthead(head, item);
			dem++;
			animation();
		}
		display();

		glutDisplayFunc(display);
		drawstring(200.0, 150.0, "NEW NODE INSERTED", 2);
		glFlush();//put an end for the programm to know it is the end of animation and show out
		break;
	case 2:
		cout << "enter the item to be inserted: ";
		cin >> item;
		inserttail(head, item);
		dem++;
		display();
		glutDisplayFunc(display);
		drawstring(200.0, 150.0, "NEW NODE INSERTED", 2);
		glFlush();
		break;
	case 3:
		cout << "enter the item to be inserted : ";
		cin >> item;
		cout << "enter the value of the node you want to insert after: ";
		cin >> k;
		ins_succ = 1;
		insertafterNode(head, item, k);
		dem++;
		display();
		glutDisplayFunc(display);
		if (!ins_succ)
			drawstring(200.0, 150.0, "KEY NODE DOESN'T EXIST", 2);
		else
			drawstring(200.0, 150.0, "NEW NODE INSERTED", 2);
		glFlush();
		break;
	case 4:
		cout << "enter the item to be inserted : ";
		cin >> item;
		cout << "enter the value of the node you want to insert before: ";
		cin >> k;
		ins_succ = 1;
		insertbeforeNode(head, item, k);
		dem++;
		display();
		glutDisplayFunc(display);
		if (!ins_succ)
			drawstring(200.0, 150.0, "KEY NODE DOESN'T EXIST", 2);
		else
			drawstring(200.0, 150.0, "NEW NODE INSERTED", 2);
		glFlush();
		break;
	case 5:
		succ = 1;
		removehead(head);
		dem--;
		display();
		glutDisplayFunc(display);
		if (succ)
			drawstring(200.0, 150.0, "NODE DELETED", 2);
		glFlush();
		break;
	case 6:
		succ = 1;
		removetail(head);
		dem--;
		display();
		glutDisplayFunc(display);
		if (succ)
			drawstring(200.0, 150.0, "NODE DELETED", 2);
		glFlush();
		break;
	case 7:
		succ = succ1 = 1;
		cout << "Which node do you want to delete? ";
		cin >> item;
		removespecificnode(head, item);
		dem--;
		display();
		glutDisplayFunc(display);
		if (succ)
			drawstring(200.0, 150.0, "NODE DELETED", 2);
		if (!succ1)
			drawstring(200.0, 150.0, "KEY NODE DOESN'T EXIST", 2);
		glFlush();
		break;
	case 8:
		display();
		glutDisplayFunc(display);
		drawstring(200.0, 150.0, "LINKED LIST OUTPUT", 2);
		outputfile(head);
		glFlush();
		break;
	case 9:
		int temp;
		cout << "Input the number to find smaller: ";
		cin >> temp;
		findlessthan(head, temp);
		display();
		glutDisplayFunc(display);
		if (!ins_succ)
			drawstring(200.0, 150.0, "CAN'T FIND ANY NODE ", 2);
		else
			drawstring(200.0, 150.0, "NODE FOUND!", 2);
		glFlush();
		break;
	case 10:
		//int temp;
		cout << "Input the number to find greater: ";
		cin >> temp;
		findgreaterthan(head, temp);
		display();
		glutDisplayFunc(display);
		if (!ins_succ)
			drawstring(200.0, 150.0, "CAN'T FIND ANY NODE ", 2);
		else
			drawstring(200.0, 150.0, "NODE FOUND!", 2);
		glFlush();
		break;
	case 11:
		// temp;
		cout << "Input the number to find : ";
		cin >> temp;
		findaspecificNode(head, temp);
		display();
		glutDisplayFunc(display);
		if (!ins_succ)
			drawstring(200.0, 150.0, "CAN'T FIND THE NODE ", 2);
		else
			drawstring(200.0, 150.0, "NODE FOUND!", 2);
		glFlush();
		break;
	case 12:
		int left, right;
		do
		{
			cout << "Input the the range: ";
			cin >> left >> right;
		} while (right<left);
		findinrange(head, left, right);
		display();
		glutDisplayFunc(display);
		if (!ins_succ)
			drawstring(200.0, 150.0, "CAN'T FIND ANY NODE ", 2);
		else
			drawstring(200.0, 150.0, "NODE FOUND!", 2);
		glFlush();
		break;
	case 13:
		exit(0);
	}
}