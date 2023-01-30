#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace wyl
{

	enum status
	{
		EXIST, // ��ʾ��ϣ������������
		DELETE,//��ʾ���������ϣ���Ƴ�
		EMPTY//��ʾ���λ��Ϊ��
	};

	template<class K,class V>
	struct HashData
	{
		pair<K, V> _kv;
		status _status = EMPTY;
	};

	template<class K, class V>
	class CloseHash
	{
	public:
		bool insert(const pair<K,V>& kv)
		{
			//��������ظ����֣�����ʧ��
			if (find(kv.first))
				return false;

			if (_tables.size()== 0 || _n * 10 / _tables.size() == 7) //���Ԫ�����������鳤�ȵ�0.7���ϣ���������
			{
				//����
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				//����һ���µĹ�ϣ����ת������
				CloseHash<K, V> newHT;
				newHT._tables.resize(newSize);
				for (int i = 0; i < _tables.size(); i++)
				{
					//����ת��
					newHT.insert(_tables[i]._kv);
				}
				//ת��2�ű�
				_tables.swap(newHT._tables);
			}

			//��������
			size_t start = kv.first % _tables.size(); //��ʼλ��
			size_t i = 0;
			size_t index = start;
			while (_tables[index]._status == EXIST) //��λ�ú�DELETEλ�ö����Բ���
			{
				index = start + i * i;
				index %= _tables.size();
				++i;
			}
			//�ҵ���λ��
			_tables[index]._kv = kv;
			_tables[index]._status = EXIST; //״̬��Ϊ����
			_n++;
			return true;
		}


		HashData<K,V>* find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;

			size_t start = key % _tables.size(); //��ʼλ��
			size_t i = 0;
			size_t index = start;
			while (_tables[index]._status != EMPTY) //�ҵ���λ�ã�����
			{
				if (_tables[index]._status == EXIST && _tables[index]._kv.first == key)
				{
					//�ҵ���
					return &_tables[index];
				}
				index = start + i * i;
				index %= _tables.size();
				++i;
			}
			return nullptr;
		}

		bool erase(const K& key)
		{
			HashData<K, V>* ret = find(key);
			if (ret)
			{
				ret->_status = DELETE;
				_n--;
				return true;
			}
			else
				return false;
		}

	private:
		std::vector<HashData<K,V>> _tables;
		size_t _n = 0;
	};


	void HashTest1()
	{
		CloseHash<int, int> ch;
		ch.insert(make_pair(11, 11));
		ch.insert(make_pair(21, 21));
		ch.insert(make_pair(31, 31));
		ch.insert(make_pair(41, 41));
		ch.erase(11);
		ch.erase(21);
		ch.erase(51);
		ch.erase(41);
		cout << ch.find(11) << endl;
		cout << ch.find(21) << endl;
		cout << ch.find(31) << endl;
		cout << ch.find(41) << endl;

	}

}