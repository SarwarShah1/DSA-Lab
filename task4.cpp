#include <iostream>
using namespace std;



class rectangle {
	float length, width;
public:
	rectangle() : length(1), width(1) {}
	void setL(float length)
	{
		if (length > 0.0 && length < 20.0)
		this->length = length;
	}
	void setW(float width)
	{
		if (width > 0.0 && width < 20.0)
		this->width = width;
	}
	float getL()
	{
		return length;
	}
	float getW()
	{
		return width;
	}
	float para()
	{
		return 2 * (length + width);
	}
	float area()
	{
		return length * width;
	}
};

int main()
{
	return 0;
}