#pragma once
#include "CGameObject.h"
class CGameObject;
class CComponent
{
public:
	CComponent();
	~CComponent();

private:
	virtual void Awake()		PURE;
	virtual void Start()		PURE;
	virtual void Update()		PURE;
	virtual void FixedUpdate()	PURE;
	virtual void LateUpdate()	PURE;
	virtual void OnRender()		PURE;
	virtual void OnDestory()	PURE;
	virtual void OnEnable()		PURE;
	virtual void OnDisable()	PURE;
	virtual void OnCollisionEnter(CGameObject * _pGameObject)	PURE;
	virtual void OnCollisionStay(CGameObject * _pGameObject)	PURE;
	virtual void OnCollisionExit(CGameObject * _pGameObject)	PURE;

private:
	bool m_bEnable;
	bool m_bStart;
	
	CGameObject * m_pGameObject;

public:
	bool GetEnable() { return m_bEnable; }
	void SetEnable(bool _bEnable) { m_bEnable = _bEnable; }


};

