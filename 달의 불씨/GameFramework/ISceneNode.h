#ifndef _ISCENENODE_H_
#define _ISCENENODE_H_

#include <list>
#include "DXUT.h"

class ISceneNode {
protected:
	ISceneNode* m_pParent; //�θ���
	std::list<ISceneNode*> m_child; //�ڽĳ��

protected:
	D3DXMATRIX m_matrix; //��ȯ���
	D3DXVECTOR2 m_scale; //ũ�����
	D3DXVECTOR2 m_scalingCenter; //ũ�Ⱑ ���ϴ� �߽���
	D3DXVECTOR2 m_rotationCenter; //ȸ�� �߽���
	D3DXVECTOR2 m_position; //��ġ
	float m_rotation; //ȸ������ (����)
	bool m_erase; //�������� ����
	bool m_update; //������Ʈ ����

public:
	ISceneNode();
	virtual ~ISceneNode();

	virtual void Update(float eTime);
	virtual void Render();

public:
	void PushScene(ISceneNode* p, bool update = true);
	void PopScene(ISceneNode* p, bool erase = false);

public:
	//set�Լ�
	void SetMatrix(D3DXMATRIX m)				{ m_matrix = m; }
	void SetScale(D3DXVECTOR2 s)					{ m_scale = s; }
	void SetScalingCenter(D3DXVECTOR2 sc)	{ m_scalingCenter = sc; }
	void SetRotation(float angle)						{ m_rotation = angle; }
	void SetRotationCenter(D3DXVECTOR2 rc)	{ m_rotationCenter = rc; }
	void SetPosition(D3DXVECTOR2 p)				{ m_position = p; }
	void SetPosition(int x,int y)				{ m_position = D3DXVECTOR2(x,y); }


public:
	//get�Լ�
	D3DXMATRIX	GetMatrix()						{ return m_matrix; }
	D3DXVECTOR2 GetScale()					{ return m_scale; }
	D3DXVECTOR2 GetScalingCenter()		{ return m_scalingCenter; }
	D3DXVECTOR2 GetRotationCenter()		{ return m_rotationCenter; }
	D3DXVECTOR2 GetPosition()					{ return m_position; }
	float		GetRotation()								{ return m_rotation; }
};

#endif