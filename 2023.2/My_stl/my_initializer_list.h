//
// Created by 王有林 on 2023/2/2.
//

#ifndef MY_STL_MY_INITIALIZER_LIST_H
#define MY_STL_MY_INITIALIZER_LIST_H

#endif //MY_STL_MY_INITIALIZER_LIST_H


template<class T>
 class my_initializer_list
 {
 public:
     typedef  T* iterator;
     typedef const T* const_iterator;

     my_initializer_list():_first(nullptr),_last(nullptr){};
     my_initializer_list(const T* first,const T* last)
     :_first(first),_last(last){};

     iterator begin()
     {
         return _first;
     }

     iterator end()
     {
         return _last;
     }

     const_iterator begin()const
     {
         return _first;
     }

     const_iterator end()const
     {
         return _last;
     }


 private:
     T* _first;
     T* _last;
 };