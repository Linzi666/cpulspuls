#pragma once




template<class Iterator,class Ref,class Ptr>
class _reverse_iterator
{
	typedef _reverse_iterator<Iterator, Ref, Ptr> self;
public:
	_reverse_iterator(Iterator it)
		:_it(it){}

	self& operator++()
	{
		--_it;
		return *this;
	}

	self& operator--()
	{
		++_it;
		return *this;
	}

	self operator++(int)
	{
		self tmp(*this);
		--_it;
		return tmp;
	}

	self operator--(int)
	{
		self tmp(*this);
		++_it;
		return tmp;
	}

	Ref operator*()
	{
		Iterator tmp = _it;
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

private:
	Iterator _it;
};