// workshop.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>

int sign(int n)
{
	if (n < 0)
		return -1;
	else if (n == 0)
		return 0;
	else
		return +1;
}

int sign2(int n)
{
	
	return (n > 0) ? 1: ((n<0) ? -1 : 0);
}

int sign3(int x)
{
	int p, n;

	p = 1 * (x > 0);
	
	n = -1 * (x < 0);

	return p + n;
}

int main()
{
	printf("%d => %d\n", 23, sign3(23));
	printf("%d => %d\n", 0, sign3(0));
	printf("%d => %d\n", -3, sign3(-3));

    return 0;
}

void input(long *a, int cnt)
{
	cout << "Geben Sie " << cnt << " Werte ein\n";
	for (int i(0); i < cnt; i++)
	{
		cout << "Wert "<<i+1<<": ";
		cin >> a[i];
	}
}

void output(long *a, int cnt)
{
	for (int i(0); i < cnt; i++)
	{
		cout << i + 1 << " Wert: " << a[i] << endl;
	}
}

int maximum(long *a, int cnt)
{
	int max = 0;
	int index = 0;
	for (int i(0); i < cnt; i++)
	{
		if (a[i] > max)
		 {
			 max = a[i];
			 index = i;
		 }
	}
	 return index;
}

void swap(long *a, int i1, int i2)
{
	int tmp = a[i2];
	a[i2] = a[i1];
	a[i1] = tmp;
}

void sort(long *a, int max_n)
{
	if (max_n > 1)
	{
		int max_i = maximum(a, max_n);
		if (max_i != (max_n - 1))
		{
			swap(a, max_n - 1, max_i);
		}
		sort(a, max_n - 1);
	}
}

int main()
{
	long ar[] = { 1, -1, 32, 55, 12, -5, 5, 3 };
	int cnt = (sizeof(ar) / sizeof(*ar));
	cout << "lengt: " << cnt << endl;
	//input(ar, 4);
	output(ar, cnt);
	int mi = maximum(ar, cnt);
	cout << "max index: " << mi << " = "<< ar[mi]<<endl;
	cout << "-------------------------------------\n";
	swap(ar, 1, 2);
	swap(ar, 3, 4);
	output(ar, cnt);
	cout << "-------------------------------------\n";
	sort(ar, cnt);
	output(ar, cnt);
    return 0;
}



int getBit(char *c, int bits)
{
	bits--;
	int n = bits / 8;
	int bit = bits % 8;
	if ((c[n] & (1 << bit)) == 0)
		return 0;
	return 1;
}

void output(char *a, int cnt)
{
	for (int i(0); i < cnt; i++)
	{
		cout << i + 1 << " Wert: " << a[i] << "  : ";
		for (int b(8); b >0; b--) {
			if (getBit(a, b + i * 8) == 1)
				cout << "1";
			else
				cout << "0";
		}
		cout << endl;
	}
}

void setBit(char *c, int bits, int val)
{
	bits--;
	int n = bits / 8;
	int bit = bits % 8;
	if (val == 1)
	{
		c[n] |= (1 << bit);
	}
}

void encode(char *c, char *e, int n)
{
	int cnt2 = 0;

	for (int i(0); i < n*8; i++, cnt2++)
	{
		cnt2++;

	}

}

int main()
{
	char b1[10] = { 254, 248, 44, 255, 123, 45 , 46, 47, 48, 49};
	char b2[16];

	for (int i(0); i < 16; i++)
		b2[i] = 0;
	
	output(b1, 10);
	for (int i(1),  i2(1); i < 10*8+1; i++, i2++)
	{
		//cout << "b1, "<<i<<": " << getBit(b1, i) << endl;
		if (i % 8 == 0)
			i2++;
		//cout << "i/i2: " << i << "/" << i2 << endl;
		setBit(b2, i2, getBit(b1, i));
		//cout << "b2, " << i << ": " << getBit(b2, i) << endl<<endl;
	}
	cout << "-------------------------------\n";
	output(b2, 16);

    return 0;
}

/////////////////////////////////////////////////////////////////////////

#pragma once
class Bruch
{
private:
	int zaehler;
	int nenner;
	double erg;
public:
	Bruch(int z, int n);
	~Bruch();
	int Zaehler();
	int Nenner();
	double Wert();
};

#include "Bruch.h"

Bruch::Bruch(int z, int n)
{
	zaehler = z;
	nenner = n;
	erg = double(z) / double(n);
}

Bruch::~Bruch()
{
}

int Bruch::Zaehler()
{
	return zaehler;
}

int Bruch::Nenner()
{
	return nenner;
}

double Bruch::Wert()
{
	return erg;
}


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "Bruch.h"

using namespace std;

int main()
{
	Bruch b(1, 2);

	cout << "z: " << b.Zaehler() << "   n: " << b.Nenner() << "   Wert: " << b.Wert() << endl;
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
class Nibble
{
private:
	unsigned long zahl;
	unsigned long nibble;
public:
	Nibble(unsigned long n);
	~Nibble();
	unsigned long Get();
	void Set(unsigned long n);
};

#include "Nibble.h"

Nibble::Nibble(unsigned long n)
{
	nibble = n & 0xf;
}

Nibble::~Nibble()
{
}

unsigned long Nibble::Get()
{
	return nibble;
}

void Nibble::Set(unsigned long n)
{
	nibble = n & 0xf;
}

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "Nibble.h"
using namespace std;

int main()
{
	Nibble n(23404);
	Nibble n2(8);

	n.Set(23);
	cout << n.Get() << "  " << n2.Get() << endl;
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
class Stack
{
private:
	int werte[100];
	int zeiger;
public:
	Stack();
	~Stack();
	void Push(int x);
	int Pop();
	void out();
};

#include "Stack.h"
#include <iostream>

Stack::Stack()
{
	zeiger = 0;
}

Stack::~Stack()
{
}

void Stack::Push(int x)
{
	werte[zeiger++] = x;
}

int Stack::Pop()
{
	--zeiger;
	int t = werte[zeiger];
	return t;
}

void Stack::out()
{
	std::cout << "zeiger: " << zeiger << std::endl;
	for (int i(0); i < zeiger; i++)
		std::cout << " " << werte[i];
	std::cout << std::endl;
}


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	Stack st;
	st.Push(10); st.Push(12); st.Push(-23);st.Push(1);st.Push(2);st.Push(3);
	st.out();
	cout << "1: " << st.Pop() << endl;
	cout << "2: " << st.Pop() << endl;
	st.Push(255); st.Push(-239032);

	cout << "3: " << st.Pop() << endl;
	cout << "4: " << st.Pop() << endl;
	st.out();
    return 0;
}
///////////////////////////
#pragma once
#include <iostream>

template<class T>
class Stack
{
private:
	T werte[100];
	int zeiger;
public:
	Stack() {
		zeiger = 0;
	}
	int Push(T const x) {
		if (zeiger >= 100)
			return -1;
		werte[zeiger++] = x;
		return 1;
	}
	T Pop() {
		int t = 0;
		if (zeiger > 0)
		{
			--zeiger;
			t = werte[zeiger];
		}
		return t;
	}
	void out() {
		std::cout << "zeiger: " << zeiger << std::endl;
		for (int i(0); i < zeiger; i++)
			std::cout << " " << werte[i];
		std::cout << std::endl;
	}
	int isEmpty() {
		if (zeiger > 0)
			return 0;
		return 1;
	}
};

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack<int> st;
	st.Push(10); st.Push(12); st.Push(-23);st.Push(1);st.Push(2);st.Push(3);
	st.out();
	cout << "1: " << st.Pop() << endl;
	cout << "2: " << st.Pop() << endl;
	st.Push(255); st.Push(-239032);
	st.out();
	cout << "3: " << st.Pop() << endl;
	cout << "4: " << st.Pop() << endl;
	cout << "isEmpty: " << st.isEmpty() << endl;
	cout << "4: " << st.Pop() << endl;
	cout << "4: " << st.Pop() << endl;
	cout << "4: " << st.Pop() << endl;
	cout << "4: " << st.Pop() << endl;
	cout << "4: " << st.Pop() << endl;
	cout << "4: " << st.Pop() << endl;
	cout << "isEmpty: " << st.isEmpty() << endl;
	st.Push(-239032);

	st.out();
	return 0;
}
////////////////////////////////////////
#pragma once
#include <iostream>

template<class T>
class Stack
{
private:
	T werte[100];
	int zeiger;
public:
	Stack() {
		zeiger = 0;
	}
	int Push(T const x) {
		if (zeiger >= 100)
			return -1;
		werte[zeiger++] = x;
		return 1;
	}
	T Pop() {
		int t = 0;
		if (zeiger > 0)
		{
			--zeiger;
			t = werte[zeiger];
		}
		return t;
	}
	void out() {
		std::cout << "zeiger: " << zeiger << std::endl;
		for (int i(0); i < zeiger; i++)
			std::cout << " " << werte[i];
		std::cout << std::endl;
	}
	int isEmpty() {
		if (zeiger > 0)
			return 0;
		return 1;
	}
};


#include "Stack.h"

using namespace std;

int main()
{
	Stack<char> st;

	string s = "Hallo Welt";
	for (unsigned int i(0); i < s.length(); i++)
		st.Push(s[i]);

	for (unsigned int i(0); i < s.length(); i++)
		cout << st.Pop();
	cout << endl;
	return 0;
}

////////////////////////////////////////////////////////7

#pragma once
#include <iostream>

template<class T>
class Queue
{
private:
	T *werte;
	int e, d;

public:
	Queue(int n) {
		werte = new T[n];
		e = 0; d = 0; 
	}
	int Enqueue(T const x) {
		werte[e++] = x;
		return 1;
	}
	T Dequeue() {
		int t = 0;
		t = werte[d++];
		return t;
	}
	void out() {
		std::cout << "e: " << e << "   d: "<<d<<std::endl;
		for (int i(d); i < e; i++)
			std::cout << " " << werte[i];
		std::cout << std::endl;
	}
	int isEmpty() {
		if ( e==d)
			return 0;
		return 1;
	}
};
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	Queue<int> q(100);
	q.Enqueue(23);q.Enqueue(24);q.Enqueue(25);

	q.out();
	q.Dequeue(); q.Enqueue(23);q.Enqueue(24);q.Enqueue(25);

	q.out();
	return 0;
}
///////////////////////////////////////////////












