/*
 *
 * Thin wrapper over C- Stlye static array
 * Knows about its size
 * provides random access
 * Can be used with C Functions
 * Cannot grow as it is created in compile time
 *
 */

#include <iostream>
#include <array>


void Array()
{
	std::array<int,5> arr;
	for(int i = 0;i< arr.size();++i){
		arr[i] = i;
	}

	std::array<int,5> arr2{1,2,3,4,5}; //Uniform initializer list

	auto itr = arr.begin();
	for (auto x: arr2){
		std::cout<<x<<" ";
	}
	std::cout<<std::endl;
}
int main()
{
	Array();
	return 0;
}


