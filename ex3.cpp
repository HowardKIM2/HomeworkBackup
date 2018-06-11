#include <iostream>
using namespace std;

class Point
{
	private:
		int x, y;
	public :
		Point(int _x = 0, int _y = 0) : x(_x), y(_y){}
		void ShowPosition(void);
		Point& operator++(void);
		friend Point& operator--(Point& p);
};

void Point::ShowPosition(void)
{
	cout << x << " " << y << endl;
}

Point& Point::operator++(void)
{
	x++;
	y++;
	return *this;
}

Point& operator--(Point& p)
{
	p.x--;
	p.y--;
	return p;
}

int main(void)
{
	Point p(3,7);
	++p;
	p.ShowPosition();

	--p;
	p.ShowPosition();
	
	++(++p);
	p.ShowPosition();
	
	--(--p);
	p.ShowPosition();

	return 0;
}
