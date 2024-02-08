#include <iostream>

using namespace std;

//Function to find maximum
/*int Max(int x, int y)
{
	return x >y ? x:y;
}
//Function can be overloaded every time
float Max(float x, float y)
{
	return x >y ? x:y;
}*/

template <typename T>
T Max(T x,T y){
	cout<<typeid(T).name()<<endl;
	return x >y ? x:y;
}

int main()
{
	auto num = Max(3,8);
	cout<<num<<endl;
	auto num2 = Max(4.6f , 2.3f);//NOTE : this type is deduced as float
	cout<<num2<<endl;
	auto num3 = Max(4.6 , 2.3); //NOTE : this type is deduced as double
		cout<<num3<<endl;

	return 0;
}
