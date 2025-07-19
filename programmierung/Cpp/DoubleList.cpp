///  double list example

#include <iostream>
using namespace std;
class Data
{
private:
	int wert;
	Data *prev;
	Data *next;

public:
	Data(int n) 
	{
		wert = n;
		next = nullptr;
		prev = nullptr;
	}
	Data* getNext() 
	{
		return next;
	}
	Data* getPrev()
	{
		return prev;
	}
	void setNext(Data *d) 
	{
		next = d;
	}
	void setPrev(Data *d)
	{
		prev = d;
	}
	void Set(int n) {
		wert = n;
	}
	int Get() {
		return wert;
	}
};

class DoubleList
{
private:
	Data *header;

public:
	DoubleList()
	{
		header = nullptr;
	}
	~DoubleList()
	{
		Data *d = header;
		while (d != nullptr)
		{
			Data *tmp2 = d;
			d = d->getNext();
			delete tmp2;
		}
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

	Data* find(int n)
	{
		Data *tmp = header;
		while (tmp != nullptr)
		{
			if (tmp->Get() == n)
				return tmp;
			tmp = tmp->getNext();
		}
		return tmp;
	}

	bool swap(Data *d1, Data *d2)
	{
		if ((d1 == nullptr) || (d2 == nullptr))
			return false;
		
		Data *tmp_d1_prev = d1->getPrev();
		Data *tmp_d1_next = d1->getNext();

		Data *tmp_d2_prev = d2->getPrev();
		Data *tmp_d2_next = d2->getNext();
		
		if (tmp_d1_next != d2) // element between
		{
			d2->setPrev(d1->getPrev());
			d2->setNext(d1->getNext());

			if (tmp_d2_prev != nullptr)
				tmp_d2_prev->setNext(d1);
			if (tmp_d2_next != nullptr)
				tmp_d2_next->setPrev(d1);

			d1->setPrev(tmp_d2_prev);
			d1->setNext(tmp_d2_next);

			if (tmp_d1_prev != nullptr)
				tmp_d1_prev->setNext(d2);
			if (tmp_d1_next != nullptr)
				tmp_d1_next->setPrev(d2);
		} 
		else
		{
			d2->setPrev(d1->getPrev());
			d2->setNext(d1);

			if (tmp_d2_next != nullptr)
				tmp_d2_next->setPrev(d1);

			d1->setPrev(d2);
			d1->setNext(tmp_d2_next);

			if (tmp_d1_prev != nullptr)
				tmp_d1_prev->setNext(d2);
		}
		// header anpassen
		if (header == d1)
			header = d2;
		else if (header == d2)
			header = d1;

		return true;
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
					//debug(tmp);
					swap(tmp, tmp->getNext());
					found = true;
				}
				else
					tmp = tmp->getNext();
			}
			if (found)
				sort();
		}
	}

	void add(int n)
	{
		Data *d = new Data(n);
		d->setNext(header);
		d->setPrev(nullptr);

		if (header != nullptr)
		{
			header->setPrev(d);
		}
		header = d;
	}

	bool del(int n)
	{
		cout << "del( " << n << ") : \n";
		Data *d = header;
		while (d != nullptr)
		{
			if (d->Get() == n) // found
			{
				debug(d);
				Data *prev = d->getPrev();
				Data *next = d->getNext();
				if ( prev == nullptr ) // first element
				{
					header = next;
					if ( header != nullptr )
					{
						header->setPrev(nullptr);
					}
				}
				else if (next == nullptr) // last element
				{
					if (prev != nullptr)
					{
						prev->setNext(nullptr);
					}
				}
				else
				{
					prev->setNext(next);
					next->setPrev(prev);
				}
				delete d;
				return true;
			}
			d = d->getNext();
		}
		return false;
	}

	void debug(Data *tmp)
	{
		Data *next = tmp->getNext();
		Data *prev = tmp->getPrev();
		int prevValue = 0, nextValue = 0;
		if (prev != nullptr)
			prevValue = prev->Get();
		if (next != nullptr)
			nextValue = next->Get();
		cout << "DEBUG: prev: 0x" << prev << " (" << prevValue;
		cout << ") -> 0x" << tmp << " (" << tmp->Get() << ") -> ";
		cout << " next: 0x" << next << " (" << nextValue << ")\n";
	}

	void print()
	{
		Data *tmp = header;
		cout << "header: 0x" << header << endl;
		if (tmp == nullptr)
			cout << "void List\n";
		while (tmp != nullptr)
		{
			cout << tmp->Get() << " : pre 0x" << tmp->getPrev();
			cout << " <- 0x" << tmp << " ->  next 0x" << tmp->getNext() << endl;
			tmp = tmp->getNext();
		}
		cout << "--------------------------------\n";
	}
};

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	DoubleList dl;
	dl.print();
	dl.del(-12);

	dl.add(12);
	dl.print();
	dl.del(12);
	dl.print();

	for (int i(-15); i<20; i++)
		dl.add(i);

	dl.print();
	dl.del(-2333);
	dl.del(19);
	dl.del(-15);
	dl.del(3);
	dl.print();

	cout << "have 5 : " << dl.have(5) << endl;
	cout << "have -55 : " << dl.have(-55) << endl;
	cout << "size : " << dl.size() << endl;

	Data *d1 = dl.find(5);
	Data *d2 = dl.find(-14);
	Data *d3 = dl.find(18);
	Data *d4 = dl.find(-239);
	cout << d1->Get() << " " << d2->Get() << " " << d3->Get()  << endl;
	cout << "0x" << d4 << endl;

	cout << "-----------------------------------\n";
	cout << "original\n";
	dl.print();
	dl.swap(d1, d2);
	cout << "-----------------------------------\n";
	cout << "swap ( 5, -14)\n";
	dl.print();
	dl.swap(d3, d2);
	cout << "-----------------------------------\n";
	cout << "swap ( 18, -14)\n";
	dl.print();

	d1 = dl.find(-14);
	d2 = dl.find(17);
	dl.swap(d1, d2);
	cout << "-----------------------------------\n";
	cout << "swap ( -14, 17)\n";
	dl.print();

	dl.sort();
	dl.print();
	return 0;
}
