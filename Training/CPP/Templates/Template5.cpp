#include <iostream>
#include <cstring>

using namespace std;



//Non type template arguments
template <int size>
void Print(){
	//size++; //This cannot be done as size is constant
	char buffer[size];
	cout<<size<<endl;
}

template <typename T, int size>
T Sum(T (&parr)[size]){
	T sum{};
	for(int i=0;i<size;++i)
	{
		sum += parr[i];
	}
	return sum;
}

int main()
{
	int arr[]={1,2,3,4};
	int (&ref)[4] = arr; // reference to an array
	int sum = Sum(arr);
	cout<<sum<<endl;
	int arr2[]={12,78,120,13,56};
	int (&ref2)[5] = arr2; //[5] denotes array size
	cout<<Sum(arr2)<<endl;
	return 0;
}
