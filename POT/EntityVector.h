#ifndef _EntityVector_included_
#define _EntityVector_included_

#include <vector>
#include <functional>

#include "Tools.h"

template<class T>
class EntityVector
{
public:
	void constructVector(std::vector<XMLSerializable*> & vVector)
	{
		for (auto pObject : vVector)
		{
			T * pT = dynamic_cast<T*>(pObject);

			if (pT != NULL)
			{
				m_vTs.push_back(pT);
			}
		}
	}

	T * generate(std::function<bool(T*)> pFunc)
	{
		std::vector<T*> vTemp;

		for (auto pT : m_vTs)
		{
			if (pFunc(pT))
			{
				vTemp.push_back(pT);
			}
		}

		if (vTemp.size() == 0)
			return NULL;

		return new T(*vTemp[Tools::randomValue(vTemp.size())]);

	}

private:
	std::vector<T*> m_vTs;
};


#endif



