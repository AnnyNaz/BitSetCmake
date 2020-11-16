#include "BitSet.h"
#include <algorithm>

BitSet::BitSet(int num) : m_num(num){	};

BitSet::BitSet(std::initializer_list<int> l)
{
	
	for (auto it:l) 
	{
		setBit(it);
	}
};
bool BitSet::setBit(int bit) 
{
	bit = bit - 1;
	if (bit > SIZE_INT)
	{
		return false;
	}
	m_num = m_num | (1 << bit);
	return true;
}
bool BitSet::getBit(int bit) const
{
	bit = bit - 1;
	if (bit >= SIZE_INT)
	{
		return false;
	}
	return (m_num&(1<<bit));
}
string  BitSet::toString() const
{
	string res = "";
	bool isNotZero = true;
	for (int i = SIZE_INT - 1; i >0 ;  --i)
	{
		bool cur = getBit(i);
		if (isNotZero && cur == true)
			isNotZero = false;
		if (!isNotZero)
			res = res + to_string(getBit(i));
	}
	return res;
}
bool BitSet::clearBit(int bit)
{
	bit = bit - 1;
	if ((bit >= SIZE_INT))
	{
		return false;
	}
	m_num = m_num & (~(1 << bit));
	return true;

}
bool  BitSet::operator==(const BitSet &rhs)  const
{
	
	return rhs.m_num == m_num;
}

BitSet::BitSet(const BitSet& bitset)
{
	m_num = bitset.m_num;
}
BitSet BitSet::operator&(const BitSet &rhs) const
{
	
	BitSet res(rhs.m_num&m_num);
	return res;
}
BitSet BitSet::operator|(const BitSet &rhs) const
{
	BitSet res(m_num|rhs.m_num);
	return res;
}
BitSet BitSet::operator>>(int pos) const
{
	BitSet res((m_num>>pos));
	return res;
}
BitSet BitSet::operator<<(int pos) const
{
	BitSet res((m_num << pos));
	return res;
}