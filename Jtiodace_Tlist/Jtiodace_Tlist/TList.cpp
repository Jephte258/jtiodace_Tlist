#include <string>
#include <iostream>

using namespace std;

template <class t_type>

class TLIST

{

public:

	TLIST();
	~TLIST();
	TLIST(const TLIST<t_type> &);

	bool IsEmpty();

	bool IsFull();

	int Search(t_type item);

	TLIST<t_type> & operator+(const t_type);

	void TLIST<t_type>::Print();

	void Remove(const t_type org);

	TLIST<t_type> & operator=(const TLIST<t_type> &);
	void Double_Capacity();

	//other functions you may want to implement

	friend ostream & operator<<(ostream & out, TLIST<t_type> & Org)
	{
		cout << "operator<<has been called with chaining" << endl;
		int i = 0;

		for (i = 0; i<Org.count; i++)
		{
			out << "DB[i" << i << "] = " << Org.DB[i] << endl;
		}
		return out;
	}

private:

	t_type *DB;

	int count;

	int capacity;

	//additonal state variables you may wish add

};

////////////////////////////////////////////////////////////////////////
// Function Name:  TLIST
// Precondition: State of class has not been initialize
// Postcondition:  State has been initialize
// Description:  Default constructor that initialized DB, count and capaccity.
////////////////////////////////////////////////////////////////////////
template <class t_type>
TLIST<t_type>::TLIST()
{
	cout << "The Default Invoked\n\n";
	count = 0;
	capacity = 5;
	DB = new t_type[capacity];
}

////////////////////////////////////////////////////////////////////////
// Function Name:  ~TLIST
// Precondition:  Dynamic memory state allocated for the class/object
// Postcondition: Dynamic memory has been de-allocated
// Description:  Destructor of the class which de-allocates dynamic memory
//               allocated by operator new
////////////////////////////////////////////////////////////////////////
template <class t_type>
TLIST<t_type>::~TLIST()
{
	cout << "The Destructor Invoked\n\n";
	delete[] DB;
	count = 0;
	DB = 0;
}


////////////////////////////////////////////////////////////////////////
// Function Name:  Search
// Precondition: item contains the search item
// Postcondition:  if item found it location is returned;
//                 otherwise -1 is returned.
// Description:  Locates item in DB if it is there
////////////////////////////////////////////////////////////////////////

template <class t_type>
int TLIST<t_type>::Search(t_type item)
{
	cout << "Search Invoked" << endl;
	int i;

	for (i = 0; i<count; i++)
	{
		if (item == DB[i])
		{
			cout << "item found" << endl;
			return i;
		}
	}
	cout << "item is not found" << endl;
	return -1;
}

////////////////////////////////////////////////////////////////////////
// Function Name:  Isful
// Precondition: count is equal to capacity-1
// Postcondition:  if Count is equal to capacity-1 memory is full, and it returned true. 
// Description:  Allocate new memory if item is full.
////////////////////////////////////////////////////////////////////////
template <class t_type>
bool TLIST<t_type>::IsFull()
{
	cout << "IsFull invoked" << endl;
	int i;
	for (i = 0; i<count; i++)
	{
		if (count == capacity - 1)
		{
			//cout << "is full" << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Function Name:  IsEmpty
// Precondition: set count equal to zero
// Postcondition:  if Count is equal to capacity-1 memory is full, and it returned true. 
// Description:  the function will stop and there will be no need to search.
////////////////////////////////////////////////////////////////////////
template <class t_type>
bool TLIST<t_type>::IsEmpty()
{
	cout << "IsEmpty invoked" << endl;
	if (count == 0)
	{
		//cout << "is empty" << endl;
		return true;
	}
	else
	{
		return false;
	}
}


////////////////////////////////////////////////////////////////////////
// Function Name:  TLIST Copy constructor
// Precondition: State of class has not been initialize
// Postcondition:  State has been initialize
// Description:  Copy constructor that performs a deep copy
////////////////////////////////////////////////////////////////////////

template <class t_type>
TLIST<t_type>::TLIST(const TLIST<t_type> & Org)
{
	cout << "Copy Constructor Invoked" << endl;
	count = Org.count;

	capacity = Org.capacity;
	DB = new t_type[capacity];
	for (int i = 0; i<count; i++)
	{
		DB[i] = Org.DB[i];
	}
}

////////////////////////////////////////////////////////////////////////
// Function Name:  TLIST operator=
// Precondition: count has been equal to org.count and capacity has benn equal to org.capacity
// Postcondition:  New dynamic memory have been allocated
// Description:  The function will point and return the current object
////////////////////////////////////////////////////////////////////////
template <class t_type>
TLIST<t_type> & TLIST<t_type>::operator=(const TLIST<t_type> & Org)
{
	cout << "operator= Invoked" << endl;
	if (this != &Org)
	{
		count = Org.count;
		capacity = Org.capacity;
		DB = new t_type[capacity];
		for (int i = 0; i<count; i++)
		{
			DB[i] = Org.DB[i];
		}
	}
	return *this;
}


////////////////////////////////////////////////////////////////////////
// Function Name:  Print
// Precondition: None
// Postcondition:  DB has been printed to the screen
// Description:  Prints all the elements stored in DB
////////////////////////////////////////////////////////////////////////
template <class t_type>
void TLIST<t_type>::Print()
{
	int i = 0;

	for (i = 0; i < count; i++)
	{
		cout << "DB[i" << i << "] = " << DB[i] << endl;
	}
}
////////////////////////////////////////////////////////////////////////
// Function Name: The remove function
// Precondition: If IsEmpty is zero, function will stop
// Postcondition:  If the function is not empty, it will continue and remove the object.
// Description:  The list will shift up, and it will return count--
////////////////////////////////////////////////////////////////////////

template <class t_type>
void TLIST<t_type>::Remove(const t_type org)
{
	cout << "Remove Invoked";
	if (IsEmpty() == true)
	{
		cout << "is empty";
	}
	int result = Search(org);
	cout << (*this);
	if (result != -1)
	{
		for (int i = result; i < count - 1; i++)
		{
			DB[i] = DB[i + 1];

		}
		count--;
	}
}



////////////////////////////////////////////////////////////////////////
// Function Name:  operator+
// Precondition: Org has not be added to DB
// Postcondition:  Org has been add to array DB; count incremented;
//                 DB's SIZE was doubled if necessary
// Description:  Add an item to the dynamic array of the class; overloading
//               operator+ as a member function with chaining
////////////////////////////////////////////////////////////////////////
template <class t_type>

TLIST<t_type> & TLIST<t_type>::operator+(const t_type Org)
{
	cout << "operator+ has been called with chaining" << endl;
	if (IsFull() == true)
	{
		Double_Capacity();

		//(*this).DB[count++] = Org;
		//this->DB[count++] = Org;
	}
	//Double_Capacity();
	//(*this) + Org;

	DB[count++] = Org;
	return *this;
}

////////////////////////////////////////////////////////////////////////
// Function Name:  Double_Size
// Precondition: DB, the dynamic array is FULL.
// Postcondition:  DB the size/capacity has been doubled
// Description:  Doubles the dynamic memory of the array DB
////////////////////////////////////////////////////////////////////////
template <class t_type>
void TLIST<t_type>::Double_Capacity()
{
	cout << endl << endl;
	cout << "Double_Size has been called\n";
	cout << "Old Size = " << capacity << endl;
	cout << "New Size = " << capacity * 2 << endl;

	(*this).capacity *= 2;
	t_type *temp = new t_type[capacity];

	for (int i = 0; i<count; i++)
	{
		temp[i] = DB[i];
	}

	delete[] DB;
	DB = temp;

}

