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

template <typename T> //T is place holder for type
//Keyword Class can also be used
T Max(T x,T y){
	return x >y ? x:y;
}
//The compiler will automatically generate the function for appropriate type
//The compiler examine the arguments of function call and will deduce the type of T
int main()
{
	auto num = Max(3,8);
	//Compiler will create Max<int>
	cout<<num<<endl;
	auto num2 = Max(4.6f , 2.3f);
	//Compiler will create Max<float>
	//Compiler would have created 2 Functions with Max

	//If Function template is not invoked, then function is not generated by compiler
	cout<<num2<<endl;

	return 0;
}

/*
 * Templates
 * Generalizes Software components
 * Reused
 * Operate on any kind of data
 * High Performance classes and algorithms
 * Compile time, No run Time Costs are involved
 * Libraries such as Advanced Template Library(ATL), Windows Template Library(WTL)
 * Boost , POCO, ACE, etc use template for implementation
 */

template <typename T>
T Function(T Arg){
	//Implementation
	return 0;
}
/*
 * Template Instantiation
 * A template function or class only acts as blue print
 * Compiler generates code
 * This is known as template instantiation
 */
