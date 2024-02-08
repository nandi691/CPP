#include <iostream>

using namespace std;

//Function to find maximum
int Max(int x, int y)
{
	return x >y ? x:y;
}
//Function can be overloaded every time
float Max(float x, float y)
{
	return x >y ? x:y;
}

int main()
{
	auto num = Max(3,8);
	cout<<num<<endl;
	auto num2 = Max(4.6f , 2.3f);
	//If we want to overload then other types can also be overloaded
	//This will be tedious and will lead to lot number of functions
	//Templates Allow us to write function that can operate on any of data type.
	cout<<num2<<endl;
	return 0;
}