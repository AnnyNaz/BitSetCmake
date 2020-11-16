#pragma once
#include <vector>
#include <string>
using namespace std;
class BitSet 
{
	public:
		BitSet() {};
		BitSet(int num);
		BitSet(std::initializer_list<int> l);
		BitSet(const BitSet& a);
		bool setBit(int bit);
		bool clearBit(int bit);
		bool getBit(int bit) const;
		string toString()const ;
		bool  operator==(const BitSet &rhs) const;
		BitSet  operator&(const BitSet &rhs) const;
		BitSet  operator|(const BitSet &rhs) const;
		BitSet operator>>(int pos) const;
		BitSet operator<<(int pos) const;
	private:
		int m_num = 0;
		const int SIZE_INT = 32;
};