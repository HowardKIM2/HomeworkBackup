#include <iostream>

using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int_x = 0, int_y = 0) : x(_x), y(_y) {}
	void ShowPosition(void);
	void operator+(int val);
};
void Point::ShowPosition(void)
{
	cout << x << " " << y << endl;
}
void Point::operator+(int val)
{
	x += val;
	y += val;
}
int main(void)
{
	Point p(3,4);
	p.ShowPosition();
	
	p.operator+(10);
	p.ShowPosition();
	return 0;
}
