#include <iostream>
using namespace std;

class Point
{
	private:
		int x, y;
	public : 
		Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
		void ShowPosition(void);
		Point operator+(int val);
		friend Point operator+(int val, Point& p);

};

void Point::ShowPosition(void)
{
	cout << x << " " << y << endl;
}

Point Point::operator+(int val)
{
	Point temp(x + val, y + val);
	return temp;
}

Point operator+(int val, Point& p)
{
	return p + val;
}

int main(void)
{
	Point p1(3,7);
	Point p2 = p1 + 3;
	p2.ShowPosition();
	
	Point p3 = 7 + p2;
	p3.ShowPosition();

	return 0;
}
