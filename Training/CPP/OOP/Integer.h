#ifndef INTEGER_H
#define INTEGER_H
class Integer{
	int *m_pInt{};

public:
	Integer();
	Integer(int value);
	Integer(const Integer &obj);//Copy Constructor
	Integer(Integer &&obj);
	//If passed by value another copy would be created and it will be loop
	//hence obj must be passed by reference
	~Integer();

	int GetValue() const;
	void SetValue(int val);
};
#endif
