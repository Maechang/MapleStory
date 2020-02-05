#pragma once
#include "CComponent.h"
enum ObjectTag
{
	Untagged
}Tag;
class CGameObject
{
public:
	CGameObject();
	~CGameObject();

private:
	list<CComponent *> m_listComponent;
	bool m_bDestroy;
	ObjectTag m_Tag;

public:
	template <typename T>
	void AddComponent()
	{
		if (FALSE == std::is_base_of<CComponent, T>::value)
			return nullptr;
		else if (nullptr != this->GetComponent<T>())
			return this->GetComponent<T>();

		T * pComponent = new T();
		pComponent->m_pObject = this;
		pComponent->Transform = this->Transform;
		pComponent->Awake();
		pComponent->m_bIsEnable = true;
		m_listComponent.push_back(pComponent);

		return pComponent;
	}

	template <typename T>
	T*  GetComponent()
	{
		if (TRUE == std::is_base_of<CComponent, T>::value)
		{
			T * pComponent;
			for (auto iter : m_listComponent)
			{
				pComponent = dynamic_cast<T*>(pComponent);
				if (pComponent != nullptr) 
					return pComponent;
			}
		}
		return nullptr;
	}

	 
};

