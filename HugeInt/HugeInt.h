#ifndef HugeInt_H
#define HugeInt_H

class HugeInt
{
private:
	int size = 0;
	int sign = 0;
	int num[40];
public:
	HugeInt(int razr, char str[], int sign);
	HugeInt(const HugeInt &h);
	HugeInt();
	~HugeInt();
	void print();
	void input();
	int GetNum(int i) const;
	int GetSize()const;
	int GetSign()const;
	void SetNum(int value, int i);
	void SetSize(int value_size);
	void SetSign(int value_sign);
	bool zero()const;
	HugeInt operator +(const HugeInt &temp)const;
	HugeInt operator -(const HugeInt &temp)const;
	HugeInt operator *(const HugeInt &temp)const;
	HugeInt &operator =(const HugeInt &h);
	bool operator >(const HugeInt &temp)const;
	bool operator ==(const HugeInt &temp)const;
	bool operator <(const HugeInt &temp)const;
	bool operator !=(const HugeInt &temp)const;
};

#endif