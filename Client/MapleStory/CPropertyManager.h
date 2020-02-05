#pragma once
class CPropertyManager :
	public CSingleton< CPropertyManager>
{
public:
	CPropertyManager();
	~CPropertyManager();

public:
	void ReadProperty();
	void WriteProperty();

	int GetWidth()  { return m_iWidth; }
	int GetHeight() { return m_iHeight; }

private:
	int  m_iWidth;
	int  m_iHeight;
	bool m_bWindowed;
	float m_fTargetFrame;
	 
private:
	void InitSetting();
};

#define PROPERTY (*CPropertyManager::GetInstance())