#include <iostream>
#include <string.h>
using namespace std;
class Person
{
	char* name;
	char* phone;
	
	public:
	Person(char *_name, char *_phone);
	~Person();
	Person(const Person& p);
	void ShowData();
};

Person::Person(char* _name, char* _phone)
{
	name = new char(strlen(_name) + 1);
	strcpy(name, _name);

	phone = new char(strlen(_phone) + 1);
	strcpy(phone, _phone);
		
}
Person::~Person(void)
{
	delete []name;
	delete []phone;
}

Person::Person(const Person& p)
{
	name = new char(strlen(p.name) + 1);
	strcpy(name, p.name);
	phone = new char(strlen(p.phone) + 1);
	strcpy(phone, p.phone);
	
}
void Person::ShowData(void)
{
	cout << "name : "<<name <<endl;
	cout << "phone : " << phone << endl;
}

int main(void)
{
	char _name[3] = "jo";
	char _phone[15] = "011-1123-2323";
	_name[2] = '\0';
	_phone[13] = '\0';
	Person p1(_name, _phone);
	Person p2 = p1;
	p1.ShowData();
	p1.~Person();
	p1.ShowData();
	p2.ShowData();

	return 0;

}
