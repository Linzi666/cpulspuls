#pragma once

template<class iterator,class Ref,class Ptr>
class _reverse_iterator
{
	typedef _reverse_iterator<iterator, Ref, Ptr> self;
public:	
	_reverse_iterator(iterator it)
		:_it(it)
	{}
	//ǰ��++
	self& operator++()
	{
		--_it;
		return *this;
	}
	//����++
	self operator++(int)
	{
		self tmp(*this);
		--_it;
		return tmp;
	}

	//ǰ��--
	self& operator--()
	{
		++_it;
		return *this;
	}
	//����--
	self operator--(int)
	{
		self tmp(*this);
		++_it;
		return tmp;
	}

	Ref operator*()
	{
		iterator tmp = (*this)._it;
		return *(--tmp);
	}

	Ptr operator->()
	{
		Ptr tmp = (*this)._it;
		return --tmp;
	}

	bool operator!=(const self& it)
	{
		return _it != it._it;
	}

	bool operator!=(const self& it)const
	{
		return _it != it._it;
	}

	bool operator==(const self& it)
	{
		return _it == it._it;
	}

	bool operator==(const self& it)const
	{
		return _it == it._it;
	}


private:
	iterator _it;
};