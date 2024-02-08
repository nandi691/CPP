#ifndef CAR_DELEGATED_H
#define CAR_DELEGATED_H

class Car{
private:
	float fuel;
	float speed;
	int passengers;
	static int totalcount;
public:
	Car();
	~Car();
	Car(float amount); //Parameterized constructor
	Car(float amount, float speed);
	Car(float amount, float speed, int passengers);
	void FillFuel(float amount);
	void Accelerate();
	void Brake();
	void AddPassengers(int count);
	void DashBoard() const;
	static void ShowCount();
};

#endif