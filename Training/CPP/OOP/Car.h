#ifndef CAR_H
#define CAR_H

class Car{
private:
	float fuel{0}; //Non static data member initialisation in C++11
	float speed{0}; //Compiler will insert this value into constructor
	int passengers{0};
	int arr[3] = {1,2,3};
	char *p = new char;
	char *ptr{};//ptr is nullptr assigned by default
	//auto i = 5; //error: non-static data member declared with placeholder ‘auto’
	static int totalcount;
public:
	Car();
	~Car();
	Car(float amount); //Parameterized constructor
	void FillFuel(float amount);
	void Accelerate();
	void Brake();
	void AddPassengers(int count);
	void DashBoard() const;
	static void ShowCount();
};

#endif
