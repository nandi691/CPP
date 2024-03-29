#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
T Max(T x,T y){
	//cout<<typeid(T).name()<<endl;
	return x >y ? x:y;
}

template char Max(char x, char y); //Explicit instantiation

//Explicit specialization
template<> const char * Max<const char *>(const char * x, const char * y){
	cout<<"Explicit Specialization"<<endl;
	return strcmp(x,y) > 0?x:y;
}
//Above should not be defined in header file as it is already instantiated


//Non type template arguments
template <int size>
void Print(){
	//size++; //This cannot be done as size is constant
	char buffer[size];
	cout<<size<<endl;
}

template <typename T>
T Sum(T* parr,int size){
	T sum{};
	for(int i=0;i<size;++i)
	{
		sum += parr[i];
	}
	return sum;
}
int main()
{
	const char *b {"B"};
	const char *a {"A"};
	auto s = Max(a,b);
	cout<<s<<endl; // This will show "A" w/o Explicit specialization, which is wrong
	//Max considered address rather than char so it gave wrong answers
	//Will show correct answer in Explicit specialization

	Print<3>();
	int i = 10;
	//Print<i>(); // This is invalid
	//Only Const expression must be used
	Print<sizeof(i)>();

	int arr[]={1,2,3,4};
	int (&ref)[4] = arr; //[4] Denotes array size
	int sum = Sum(arr,4);//When array is passed, first address and size of array must be passed
	cout<<sum<<endl;
	return 0;
}
