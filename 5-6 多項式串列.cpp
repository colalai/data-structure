#include <iostream>
using namespace std;

class ListNode
{
public:
	ListNode(int a, int b) { coef = a; exp = b; link = 0; }
private:
	int coef;
	int exp;
	ListNode* link;
	friend class PolyList;
};

class PolyList
{
public:
	void InsertLast(int, int);
	void Add(PolyList&);
	void PrintList();
private:
	ListNode* first = 0;
	ListNode* last = 0;
};

void PolyList::InsertLast(int coef, int exp) {
	ListNode* newNode = new ListNode(coef, exp);
	if (last == 0)
		first = newNode;
	else
		last->link = newNode;
	last = newNode;
}

void PolyList::Add(PolyList& b)
{
	PolyList c;
	ListNode* c1 = first;
	ListNode* c2 = b.first;
	

	while (c1!= 0 && c2 != 0)
	{
		
		ListNode* n = new ListNode(0, 0);
		if (c1->exp == c2->exp)
		{
			n->exp = c1->exp;
			n->coef = c1->coef + c2->coef;
			c1 = c1->link;
			c2 = c2->link;
		}
		else if(c1->exp > c2->exp)
		{
			n->coef = c1->coef;
			n->exp = c1->exp;
			c1 = c1->link;
		}
		else if (c1->exp < c2->exp)
		{
			
			n->coef = c2->coef;
			n->exp = c2->exp;
			c2 = c2->link;
		}
		
		if (c.last == 0)
			c.first = n;
		else
		{
			c.last->link = n;
			n->link = 0;
		}
		c.last = n;

	}
	
	
	first = c.first;
	


}

void PolyList::PrintList()
{
	ListNode* current = first;
	while (current != 0)
	{
		cout << current->coef << "x^" << current->exp << " ";
		current = current->link;
	}
}

int main(int argc, char* argv[])
{
	PolyList A, B;
	int times, input, input2;
	for (cin >> times, times /= 2; times > 0; times--) { cin >> input >> input2; A.InsertLast(input, input2); }
	for (cin >> times, times /= 2; times > 0; times--) { cin >> input >> input2; B.InsertLast(input, input2); }
	A.Add(B);
	A.PrintList();
}
