#include "ISceneNode.h"

ISceneNode::ISceneNode() :
	m_pParent(NULL), m_rotation(0.f), m_update(true), m_erase(false)
{
	D3DXMatrixIdentity(&m_matrix);
	m_scale = D3DXVECTOR2(1.f, 1.f);
	m_scalingCenter = D3DXVECTOR2(0.f, 0.f);
	m_rotationCenter = D3DXVECTOR2(0.f, 0.f);
	m_position = D3DXVECTOR2(0.f, 0.f);
}
ISceneNode::~ISceneNode() {
	for(std::list<ISceneNode*>::iterator it = m_child.begin(); it != m_child.end(); ++it) {
		delete (*it);
	}
	m_child.clear();
}
void ISceneNode::Update(float eTime) {
	for(std::list<ISceneNode*>::iterator it = m_child.begin(); it != m_child.end(); ++it) {
		if((*it)->m_update) {
			(*it)->Update(eTime);
		}

		if(!(*it)->m_erase) continue;

		delete (*it);
		it = m_child.erase(it);
		if(it == m_child.end())
			break;
	}
}
void ISceneNode::Render() {
	D3DXMatrixTransformation2D(
		&m_matrix,
		&m_scalingCenter,
		NULL,
		&m_scale,
		&m_rotationCenter,
		m_rotation,
		&m_position);
	if(m_pParent != NULL) m_matrix *= m_pParent->m_matrix;
}
void ISceneNode::PushScene(ISceneNode* p, bool update) {
	p->m_update = update;
	p->m_pParent = this;
	m_child.push_back(p);
}
void ISceneNode::PopScene(ISceneNode* p, bool erase) {
	p->m_erase = erase;
	for(std::list<ISceneNode*>::iterator it = m_child.begin(); it != m_child.end(); ++it) {
		if((*it) == p) {
			(*it)->m_pParent = NULL;
			it = m_child.erase(it);
			if(it == m_child.end()) {
				break;
			}
		}
	}
}