#include <iostream>

//returns r value
int Add(int x, int y){
	return x+y;
}

//Returns LValue
int & Transform(int &x){
	x *= x;
	return x;
}

int main(){
	//LValues - x,y,z
	//RValues - 5,10,8
	int x = 5;
	int y = 10;
	int z = 8;

	//Expression returns R-Value
	int result = (x+y)*z;


	std::cout<<x<<std::endl;
	++x = 24; //Expression returns L-value
	std::cout<<x<<std::endl;

	//R Value reference was introduced in C++ 11
	//Reference created to temporary
	int &&r1 = 10;
	int &&r2 = Add(5,8);
	int &&r3 = 7+2;
	std::cout<<r1<<std::endl;
	r1 = 100;
	std::cout<<r1<<std::endl;
	r1 = x;
	//&&r1 = x; // This is not possible
	std::cout<<r1<<std::endl;
	x = r2;
	std::cout<<x<<std::endl;

	int &x1 = x;
	r1 = x1;
	x1 = r3;

	int &ref = Transform(x);
	const int &ref2 = 3;
	const int &ref2 = r3;
	return 0;

}
