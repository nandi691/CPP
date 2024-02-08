#include <iostream>

using Comparator = bool(*)(int,int); //Functions that return bool are called predicate
//a function that returns true or false depending on whether its input(s) satisfy some condition


template <typename T, int size>
//void Sort(T(&arr)[size])
void Sort(T(&arr)[size], Comparator comp){ //Note use of Function pointer here
	for(int i =0; i<size-1;++i){
		for(int j =0; j<size-1;++j)
		{
			//if(arr[j] > arr[j+1]){
			if(comp(arr[j],arr[j+1])){ //Function pointer to call predicate
				//Function pointer disadvantage, they cannot be optimized by compiler
				//this cannot be made inline
				//Function will be called by address
				//Function pointer point to global function
				//State cannot be stored for Global variables
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

int main()
{
	int arr[] {12,5,0,1,2};
	for (auto x:arr){
		std::cout<<x<<" " ;
	}
	std::cout<<std::endl ;

	//Sort(arr);
	Sort(arr,compAscending);
	for (auto x:arr){
			std::cout<<x<<" " ;
		}
		std::cout<<std::endl ;
	Sort(arr,compDescending);
	for (auto x:arr){
			std::cout<<x<<" " ;
		}
	std::cout<<std::endl ;

}
