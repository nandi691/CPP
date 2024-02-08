//Function object , object of class having function call operator overloading
#include <iostream>

using Comparator = bool(*)(int,int);

template <typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator comp){
	for(int i =0; i<size-1;++i){
		for(int j =0; j<size-1;++j)
		{
			if(comp(arr[j],arr[j+1])){
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j+1]);
				arr[j+1] = std::move(temp);
			}
		}
	}
}

bool compAscending(int x,int y){
	return x > y;

}

bool compDescending(int x,int y){
	return x < y;

}
struct Comp2{
	bool operator()(int x, int y){
		return x > y;
	}
};
int main()
{
	compAscending(3,5);
	Comp2 comp;
	comp(3,5);
	int arr[] {12,5,0,1,2};
	for (auto x:arr){
		std::cout<<x<<" " ;
	}
	std::cout<<std::endl ;

	Sort(arr,compAscending);
	for (auto x:arr){
			std::cout<<x<<" " ;
		}
		std::cout<<std::endl ;
	Sort(arr,comp); // We have passed as object
	//We do not get any function call, it will be inline
	//As comp is a object it can have some state
	//Function objects have a state, while global functions do not
	for (auto x:arr){
			std::cout<<x<<" " ;
		}
	std::cout<<std::endl ;

}

/*
 * FUNCTION OBJECT
 * ---------------
 *
 * Object with overloaded function call operator
 * Resembles global function call
 * can be used as callback instead of function pointers
 * More effecient than function pointers
 * Implemented as structs
 */

/*
 * Function Pointer Vs Function Object
 * pointer - object
 * Dynamic - static
 * runtime - compile time
 * difficult to optimize - easy to optimize
 * slow - fast
 * cannot store state - can store state
 */
