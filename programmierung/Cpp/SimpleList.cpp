#include <iostream>
#include <stdio.h>

using namespace std;

class Data
{
private:
	int wert;
	Data *next;

public:
	Data(int n) {
		wert = n;
		next = nullptr;
	}
	Data* getNext() {
		return next;
	}
	void setNext(Data *d) {
		next = d;
	}// nothing found or list is void
	void Set(int n) {
		wert = n;
	}
	int Get() {
		return wert;
	}
};

class SimpleList
{
private:
	Data *header;

public:
	SimpleList() 
	{
		header = nullptr;
	}
	~SimpleList() 
	{
		Data *tmp = header;
		while (tmp != nullptr)
		{
			Data *tmp2 = tmp;
			tmp = tmp->getNext();
			delete tmp2;
		}
	}

	Data* getLast() 
	{
		if (header == nullptr)
			return nullptr;

		Data *d = header;
		while (d->getNext() != nullptr)
			d = d->getNext();
		return d;
	}

	bool have(int n) 
	{
		Data *tmp = header;
		while (tmp != nullptr) 
		{
			if (tmp->Get() == n)
				return true;
			tmp = tmp->getNext();
		}
		return false;
	}

	void add(int n) 
	{
		Data *d = new Data(n);
		Data *last = getLast();
		if (last == nullptr)
			header = d;
		else
			last->setNext(d);
	}

	bool del(int n) 
	{
		Data *tmp = header;
		if (tmp == nullptr)  // nothing found or list is void
			return false;

		if (tmp->getNext() == nullptr) { // one elemnt
			if (tmp->Get() == n) 
			{ // found
				header = nullptr;
				delete tmp;
				return true;
			}
			return false;
		}

		// first element
		if (tmp->Get() == n) 
		{
			header = tmp->getNext();
			delete tmp;
			return true;
		}

		// more than 1 element
		while (tmp->getNext() != nullptr) 
		{
			Data *tmp2;
			tmp2 = tmp->getNext();
			if (tmp2->Get() == n) // found
			{
				tmp->setNext(tmp2->getNext());
				delete tmp2;
				return true;
			}
			tmp = tmp->getNext();
		}
		
		return false;
	}

	bool replace(int o, int n)
	{
		Data *tmp = header;
		while (tmp != nullptr)
		{
			if (tmp->Get() == o)
			{
				tmp->Set(n);
				return true;
			}
			tmp = tmp->getNext();
		}
		return false;
	}

	int size()
	{
		int s = 0;
		Data *tmp = header;
		while (tmp != nullptr)
		{
			s++;
			tmp = tmp->getNext();
		}
		return s;
	}

	void sort()
	{
		if (size() > 1)
		{
			bool found = false;
			Data *tmp = header;
			while (tmp->getNext() != nullptr)
			{
				int wert = tmp->getNext()->Get();
				if (wert < tmp->Get())
				{
					tmp->getNext()->Set(tmp->Get());
					tmp->Set(wert);
					found = true;
				}
				tmp = tmp->getNext();
			}
			if (found)
				sort();
		}
	}

	void debug(Data *prev)
	{
		Data *tmp = prev->getNext();
		cout << "DEBUG: prev: 0x" << prev << " (" << prev->Get();
		cout << ") -> tmp 0x" << prev->getNext();
		cout << " [ 0x" << tmp << " (" << tmp->Get() << ")]   ";
		prev->setNext(tmp->getNext());
		delete tmp;
	}

	void print() {
		if (header == nullptr) {
			cout << "List is void\n";
		}
		else {
			Data *tmp = header;
			while (tmp != nullptr) {
				cout << tmp->Get() << " :  0x" << tmp << " -> 0x" << tmp->getNext() << endl;
				tmp = tmp->getNext();
			}
		}
		cout << "----------------------------------------------\n";
	}
};


int main()
{
	SimpleList sl;

	sl.print();
	cout << "del(1): " << sl.del(1) << endl;
	cout << "size: " << sl.size() << endl;
	cout << "have(5)  : " << sl.have(5) << endl;
	sl.add(1);
	cout << "del(2): " << sl.del(2) << endl;
	sl.print();

	cout << "del(1): " << sl.del(1) << endl;
	sl.print();

	sl.add(1);
	sl.add(22);
	sl.add(33);
	sl.print();

	cout << "del(1): " << sl.del(1) << endl;
	sl.print();

	sl.add(55); sl.add(40);
	sl.print();
	sl.print();
	cout << "del(33): " << sl.del(33) << endl;
	sl.print();
	cout << "del(1): " << sl.del(1) << endl;
	sl.print();
	cout << "del(55): " << sl.del(55) << endl;
	sl.print();
	cout << "del(40): " << sl.del(40) << endl;
	sl.print();
	cout << "del(22): " << sl.del(22) << endl;
	sl.print();

	for (int i(20); i>-5; i--)
		sl.add(i);
	cout << "size: " << sl.size() << endl;
	sl.del(8);
	sl.add(55);
	sl.print();
	cout << "have(100): " << sl.have(100) << endl;
	cout << "have(5)  : " << sl.have(5) << endl;

	sl.replace(5, 555);
	sl.replace(0, 329);
	sl.print();
	cout << "size: " << sl.size() << endl;

	cout << "\n#####################\n";
	sl.print();
	sl.sort();
	sl.print();
	return 0;
}









