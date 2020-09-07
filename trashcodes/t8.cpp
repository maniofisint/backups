#include <iostream>
#include <string>

using namespace std;

class box
{
	public:
		/*box(int a,int b,int c)
		{
			x=a;
			y=b;
			z=c;
		}*/
		void print()
		{
			cout << x << ' '  << y << ' ' << z <<endl;
		}
		int vol()
		{
			return x*y*z;
		}
		box operator+(const box &b)
		{
			box B;
			B.x=this->x+b.x;
			B.y=this->y+b.y;
			B.z=this->z+b.z;
			return B;
		}
	private:
		int x;
		int y;
		int z;
};

int main()
{
	box ali;
	ali.print();
	cout << ali.vol() << endl ;
}
