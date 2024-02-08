/*
 * Lambda Expressions
 * defines function object
 * Syntactic shortcut for function object
 * nameless function object
 *
 *
 * [] (<args>)  // [] -> Lambda introducer
 * {
 *
 * }
 */

#include <iostream>

int main()
{
	[](){
		std::cout<<"This is a lambda expression"<<std::endl;
	}();

	auto fn = [](){
		std::cout<<"This is a lambda expression with fn"<<std::endl;
	};
	fn();




	std::cout<<typeid(fn).name()<<std::endl; //This will be class internally

	auto sum = [](int x, int y) -> double { //-> Specifying the return type of lambda
		return x+y;
	};

	std::cout<<"sum is "<<sum(3,4)<<std::endl;
	auto sum2 = [](auto x, auto y)  { //generic lambda , will work with any type
			return x+y;
		};
	std::cout<<"int sum2 is "<<sum2(3,4)<<std::endl;
	std::cout<<"Float sum2 is "<<sum2(5.6f,8.9f)<<std::endl;


	auto sum3 = [](auto x, auto y)noexcept{ //Does not throw any exception
				return x+y;
			};

	auto sum4 = [](auto x, auto y)noexcept(false){ //Throws exception
					return x+y;
				};
	return 0;
}
//compiler synthesizes type conversion operator
/*
 * This is a lambda expression
This is a lambda expression with fn
Z4mainEUlvE0_
 *
 */
