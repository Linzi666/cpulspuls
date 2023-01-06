#pragma once


template<class Iterator,class Ref,class Ptr>
class _reverse_iterator
{
	typedef _reverse_iterator<Iterator, Ref, Ptr> self;
public:
	_reverse_iterator(const Iterator& it)
		:_it(it){}

	//++
	self& operator++()
	{
		--_it;
		return *this;
	}

	self operator++(int)
	{
		self tmp(_it);
		--_it;
		return tmp;
	}

	//--
	self& operator--()
	{
		++_it;
		return *this;
	}

	self operator--(int)
	{
		self tmp(_it);
		tmp(_it);
		++_it;
		return tmp;
	}

	Ref operator*()
	{
		Iterator tmp(_it);
		return *(--tmp);
	}

	bool operator!=(const self& it)const
	{
		return _it != it._it;
	}

	bool operator==(const self& it)const
	{
		return _it == it._it;
	}

	bool operator!=(self& it)
	{
		return _it != it._it;
	}

	bool operator==( self& it)
	{
		return _it == it._it;
	}

private:
	Iterator _it;
};