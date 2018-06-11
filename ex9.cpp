#include <iostream>

using namespace std;
class A
{
	private:	
		int data;
	friend class B;
	public : 
		A()
		{
			data = 0;
		}
		void PrintData(void)
		{
			cout << data << endl;
		}
};
class B
{
	public :
		void SetData(A& a, int data)
		{
			a.data = data;
		}
};
int main(void)
{
	A a;
	B b;
	a.PrintData();
	b.SetData(a, 10);
	a.PrintData();
	return 0;

}
