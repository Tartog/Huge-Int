#include <iostream>
#include <string.h>
#include "HugeInt.h"

using namespace std;

HugeInt::HugeInt(int razr, char str[], int s){
	sign = s;
	int p = strlen(str) - 2;
	size = razr;
	for (int i = 39; i >= 0; i--){
		if (p >= 0){
			num[i] = str[p--] - '0';
		}
		else{
			num[i] = 0;
		}
	}
};
HugeInt::HugeInt(){
	for (int i = 39; i >= 0; i--){
		num[i] = 0;
	}
	size = 0;
	sign = 0;
}
HugeInt::HugeInt(const HugeInt &h){
	sign = h.sign;
	size = h.size;
	for (int i = 0; i < 40; i++){
		num[i] = h.num[i];
	}
}
bool HugeInt::operator >(const HugeInt &other)const{
	if (other.sign == 0 && this->sign == 1){
		return false;
	}
	if (other.sign == 1 && this->sign == 0){
		return true;
	}
	if (this->size != other.size){
		if (this->size > other.size){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		int i = 40 - this->size;
		while (this->num[i] == other.num[i] && i < 40){
			i++;
		}
		if (this->num[i] > other.num[i] && i != 40){
			return true;
		}
		else{
			return false;
		}
	}
	return true;
}
bool HugeInt::operator ==(const HugeInt &h)const{
	if ((*this > h) || (*this < h) || (this->sign != h.sign) || (this->size != h.size)){
		return false;
	}
	return true;
}
bool HugeInt::operator !=(const HugeInt &h)const{
	if (*this == h){
		return false;
	}
	return true;
}
bool HugeInt::operator <(const HugeInt &h)const
{
	int i;
	if (*this > h){
		return false;
	}
	if (this->sign == 1 && h.sign == 0){
		return true;
	}
	if (this->sign == 0 && h.sign == 1){
		return false;
	}
	for (i = 0; i < 40; i++){
		if (this->num[i] < h.num[i]){
			return true;
		}
		if (this->num[i] > h.num[i]){
			return false;
		}
	}
	return false;
}
HugeInt HugeInt::operator -(const HugeInt &other)const
{
	HugeInt s(other);
	s.SetSign(1);
	return *this + s;
}
HugeInt& HugeInt::operator =(const HugeInt &other){
	if (&other == this){
		return *this;
	}
	this->sign = other.sign;
	this->size = other.size;
	for (int g = 0; g < 40; g++){
		this->num[g] = other.num[g];
	}
	return *this;
}
void  HugeInt::print(){
	if (size == 0){
		size = 1;
	}
	cout << "size =\t" << size << endl;
	int g = 0;
	while (num[g] == 0 && num[g + 1] == 0){
		g++;
	}
	cout << "num =\t";
	if (sign == 1){
		cout << "-";
	}
	if (g == 39){
		cout << "0";
	}
	g++;
	for (g; g < 40; g++){
		cout << num[g];
	}
	cout << endl;
	cout << "sign =\t" << sign << endl;
}
int HugeInt::GetNum(int i) const{
	return num[i];
}
int HugeInt::GetSize() const{
	return size;
}
int HugeInt::GetSign() const{
	return sign;
}
void HugeInt::SetNum(int value, int i){
	num[i] = value;
}
void HugeInt::SetSize(int value_size){
	size = value_size;
}
void HugeInt::SetSign(int value_sign){
	sign = value_sign;
}
void HugeInt::input(){
	char y;
	char str[40];
	cout << "num =\t";
	for (int i = 0; i < 40; i++){
		str[i] = getchar();
		if (str[i] == '\n'){
			str[i] = '\0';
			break;
		}
	}
	int p = strlen(str);
	int g = p;
	int i = 0;
	int j = 40 - p;
	size = p;
	if (str[0] >= '0' && str[9] <= '9'){
		sign = 0;
	}
	else{
		sign = 1;
		i = 1;
		j++;
		size--;
	}
	while (str[i] != '\0'){
		num[j] = str[i] - '0';
		i++;
		j++;
	}
}
bool HugeInt::zero()const
{
	for (int i = 0; i <= 39; i++){
		if (num[i] != 0){
			return false;
		}
	}
	return true;
}
HugeInt::~HugeInt()
{};
HugeInt HugeInt::operator +(const HugeInt &other)const{
	HugeInt temp;
	int pere = 0;
	if (this->sign == other.sign){
		int i = 39;
		for (int j = 39; i > -1; i--, j--){
			temp.num[j] = this->num[i] + other.num[i] + temp.num[i];
			if (temp.num[j] >= 10){
				temp.num[j - 1] = temp.num[j - 1] + 1;
				temp.num[j] = temp.num[j] - 10;
			}
		}
		temp.sign = other.sign;
		i = 0;
		while (temp.num[i] == 0){
			i++;
		}
		i = 40 - i;
		temp.size = i;
	}
	else{
		int g = 0;
		int kost = 0;
		int zaim = 0;
		int u = 1;
		int x = 0;
		int m = other.size;
		temp.sign = 1;
		if (((this->sign == 0 && other.sign == 1) && (this->size > other.size)) || ((this->sign == 1 && other.sign == 0) && (this->size > other.size))){
			u = 0;
			x = 1;
			m = this->size;
			temp.sign = this->sign;
		}
		if (((this->sign == 0 && other.sign == 1) && (this->size < other.size)) || ((this->sign == 1 && other.sign == 0) && (this->size < other.size))){
			u = 1;
			x = 0;
			m = other.size;
			temp.sign = other.sign;
		}
		if ((this->sign == 0 && other.sign == 1) && (this->size == other.size)){
			for (int i = 0; i < 40; i++){
				if (this->num[i] > other.num[i]){
					u = 0;
					x = 1;
					m = this->size;
					temp.sign = 0;
					break;
				}
				if (this->num[i] < other.num[i]){
					u = 1;
					x = 0;
					m = other.size;
					temp.sign = 1;
					break;
				}
			}
		}
		if ((this->sign == 1 && other.sign == 0) && (this->size == other.size)){
			for (int i = 0; i < 40; i++){
				if (this->num[i] > other.num[i]){
					u = 0;
					x = 1;
					m = this->size;
					temp.sign = 1;
					break;
				}
				if (this->num[i] < other.num[i]){
					u = 1;
					x = 0;
					m = other.size;
					temp.sign = 0;
					break;
				}
			}
		}
		int MAX = 39 - m;
		for (int i = 39; i >= MAX; i--){
			if (kost > 0){
				temp.num[i] = kost - other.num[i] * x - this->num[i] * u;
				if (((this->num[i - 1] > 0) && (u == 0)) || ((other.num[i - 1] > 0) && (u == 1))){
					kost = 0;
				}
				zaim = 1;
			}
			else{
				if (((this->num[i] - zaim >= other.num[i]) && (u == 0)) || ((other.num[i] - zaim >= this->num[i]) && (u == 1))){
					temp.num[i] = this->num[i] * x - other.num[i] * x - zaim + other.num[i] * u - this->num[i] * u;
					zaim = 0;
				}
				else{
					if (((this->num[i - 1] > 0) && (u == 0)) || ((other.num[i - 1] > 0) && (u == 1))){
						temp.num[i] = this->num[i] * x - other.num[i] * x + 10 - zaim - this->num[i] * u + other.num[i] * u;
						zaim = 1;
					}
					else{
						kost = 9;
						temp.num[i] = this->num[i] * x - other.num[i] * x + 10 - zaim - this->num[i] * u + other.num[i] * u;
					}
				}
			}
		}
		g = 0;
		while (g != 39){
			if (temp.num[g] == 0){
				g++;
			}
			else{
				temp.size = 40 - g;
				break;
			}
		}
	}
	int i;
	for (i = 0; i < 40; i++){
		if (temp.num[i] != 0){
			break;
		}
	}
	if (i == 40){
		temp.SetSign(0);
	}
	return temp;
}
HugeInt HugeInt::operator *(const HugeInt &other)const{
	HugeInt second;
	int i = 0;
	int pere = 0, pere_2 = 0;
	int j;
	int k = 39;
	for (j = 39; j > 39 - other.size; j--){
		HugeInt temp;
		for (i = 39; i > 39 - this->size - 1; i--){
			temp.num[i] = this->num[i] * other.num[j] + pere;
			pere = 0;
			if (temp.num[i] >= 10){
				pere = temp.num[i] / 10;
				temp.num[i] = temp.num[i] % 10;
			}
		}
		i = 39;
		for (int g = k; g > -1; g--){
			second.num[g] = second.num[g] + temp.num[i] + pere_2;
			pere_2 = 0;
			if (second.num[g] >= 10){
				pere_2 = 1;
				second.num[g] = second.num[g] % 10;
			}
			i--;
		}
		k--;
	}
	if (this->sign != other.sign){
		second.sign = 1;
	}
	else{
		second.sign = 0;
	}
	for (int i = 39; i > -1; i--){
		if (second.num[i] != 0){
			break;
		}
	}
	if (i == -1){
		second.sign = 0;
	}
	second.size = 1;
	i = 0;
	while (second.num[i] == 0){
		i++;
	}
	second.size = 40 - i;
	return second;
}