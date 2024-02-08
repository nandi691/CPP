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

void Print(int &x){
	std::cout<<"int &x"<<std::endl;
}

void Print(const int &x){
	std::cout<<"const int &x"<<std::endl;
}

void Print(int &&x){
	std::cout<<"int &&x"<<std::endl;
}

int main(){
	int x = 10;
	Print(x); // Print(int &x)
	//This is used to identify Temporary
	Print(3); // Print(int &&x)
	return 0;

}