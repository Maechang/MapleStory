#pragma once
#include "CComponent.h"
class CTransform :
	public CComponent
{
public:
	CTransform();
	~CTransform();

private:
	virtual void Awake()		override;
	virtual void Start()		override;
	virtual void Update()		override;
	virtual void FixedUpdate()	override;
	virtual void LateUpdate()	override;
	virtual void OnRender()		override;
	virtual void OnDestory()	override;
	virtual void OnEnable()		override;
	virtual void OnDisable()	override;
	virtual void OnCollisionEnter(CGameObject * _pGameObject)	override;
	virtual void OnCollisionStay(CGameObject * _pGameObject)	override;
	virtual void OnCollisionExit(CGameObject * _pGameObject)	override;


private:
	Vector3 m_vPosition;
	Vector3 m_vRotation;
	Vector3 m_vScale;

};

