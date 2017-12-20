#include"Project.h"


void outputfile(Node * head)
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

void inputfile(Node *& head, int &n)
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

void iniempty(Node *& head)
{
	head = NULL;
}

void inirandom(Node *&head, int n)
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

void insert(Node *&head, int k)
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

void inserthead(Node * &head, int data)
{
	Node *tmp = new Node;
	tmp->data = data;
	tmp->pnext = head;
	head = tmp;
}

void inserttail(Node * &head, int data)
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

void insertbeforeNode(Node * &head, int data, int k)
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

void insertafterNode(Node *head, int data, int k)
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

void removehead(Node * &head)
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

void removetail(Node * &head)
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

void removespecificnode(Node * &head, int k)
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

void findlessthan(Node * head, int a)
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
	ins_succ = 0;
	cout << "Can't find any nodes less than " << a << endl;
}

void findgreaterthan(Node * head, int a)
{
	Node * cur = head;
	while (cur != NULL)
	{
		if (cur->data > a)
		{
			ins_succ = 1;
			return;
		}
		else
			cur = cur->pnext;
	}
	ins_succ = 0;
	cout << "Can't find any nodes greater than " << a << endl;
}

void findaspecificNode(Node * head, int k)
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
	ins_succ = 0;
	cout << "Can't find k" << endl;
}

void findinrange(Node * head, int a, int b)
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
	ins_succ = 0;
	cout << "Can't find any nodes in the range [" << a << "," << b << "]" << endl;
}

void makeempty(Node *&head)
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