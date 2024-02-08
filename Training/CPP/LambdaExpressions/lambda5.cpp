#include <iostream>
#include <fstream>

//Generalised lambda captures
//[var = expression ] (args)
//[&var = expression ] (args)
int main(){
	//int arr[] {12,5,0,3,1};

	int x{5};
	auto f = [y=x](int arg){ //This is generalised Lambda capture
		return y + arg;
	};
	std::cout<<f(10)<<std::endl;

	std::ofstream out{"file.txt"};
	auto write = [out = std::move(out)](int x)mutable {
		out<< x;
	};
	write(200);
}
