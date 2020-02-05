#pragma once
template <class T>
class CSingleton
{
public:
	CSingleton() {}
	virtual ~CSingleton() {}

private:
	static T* m_pInstance;

public:
	static T* GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new T();
		}
		return m_pInstance;
	}
	static void ReleaseInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
};

template <class T>
T * CSingleton<T>::m_pInstance = nullptr;