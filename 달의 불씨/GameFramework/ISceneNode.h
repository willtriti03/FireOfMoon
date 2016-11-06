#ifndef _ISCENENODE_H_
#define _ISCENENODE_H_

#include <list>
#include "DXUT.h"

class ISceneNode {
protected:
	ISceneNode* m_pParent; //부모노드
	std::list<ISceneNode*> m_child; //자식노드

protected:
	D3DXMATRIX m_matrix; //변환행렬
	D3DXVECTOR2 m_scale; //크기비율
	D3DXVECTOR2 m_scalingCenter; //크기가 변하는 중심점
	D3DXVECTOR2 m_rotationCenter; //회전 중심점
	D3DXVECTOR2 m_position; //위치
	float m_rotation; //회전각도 (라디안)
	bool m_erase; //지워지는 여부
	bool m_update; //업데이트 여부

public:
	ISceneNode();
	virtual ~ISceneNode();

	virtual void Update(float eTime);
	virtual void Render();

public:
	void PushScene(ISceneNode* p, bool update = true);
	void PopScene(ISceneNode* p, bool erase = false);

public:
	//set함수
	void SetMatrix(D3DXMATRIX m)				{ m_matrix = m; }
	void SetScale(D3DXVECTOR2 s)					{ m_scale = s; }
	void SetScalingCenter(D3DXVECTOR2 sc)	{ m_scalingCenter = sc; }
	void SetRotation(float angle)						{ m_rotation = angle; }
	void SetRotationCenter(D3DXVECTOR2 rc)	{ m_rotationCenter = rc; }
	void SetPosition(D3DXVECTOR2 p)				{ m_position = p; }
	void SetPosition(int x,int y)				{ m_position = D3DXVECTOR2(x,y); }


public:
	//get함수
	D3DXMATRIX	GetMatrix()						{ return m_matrix; }
	D3DXVECTOR2 GetScale()					{ return m_scale; }
	D3DXVECTOR2 GetScalingCenter()		{ return m_scalingCenter; }
	D3DXVECTOR2 GetRotationCenter()		{ return m_rotationCenter; }
	D3DXVECTOR2 GetPosition()					{ return m_position; }
	float		GetRotation()								{ return m_rotation; }
};

#endif