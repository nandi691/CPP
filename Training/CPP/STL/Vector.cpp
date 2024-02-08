/*
 * Dynamic array
 * Grows automatically
 * Efficient for addition/removal at end
 * Provides random access
 * No good for insertion or deletion
 *
 */

#include <iostream>
#include <vector>


void Vector(){
	std::vector<int> coll{1,2,3,4};
	for(int i=0;i<5;++i){
		coll.push_back(i+10);
		std::cout<< "size is "<<coll.size()<<std::endl;
		//we can observe that size will be increasing
	}


	for (int i =0; i < coll.size();++i){ //One of the way to iterate through all elements
		std::cout<<coll[i]<<" ";
	}
	std::cout<<std::endl;



	auto itr = coll.begin();
	while(itr != coll.end()){
		std::cout<< *itr++<< " ";
	}
	std::cout<<std::endl;

	coll.insert(coll.begin(),700); //This will have performance implications
	coll.erase(coll.end()-5);
	coll.pop_back(); //removes the last element

	coll[6] = 123;
	for(auto x : coll){
		std::cout<<x<<" ";
	}
	std::cout<<std::endl;
}

int main()
{
	Vector();
	return 0;
}
