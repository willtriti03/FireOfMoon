#include "SpriteManager.h"
#include "Application.h"

SpriteManager::SpriteManager() : m_pSprite(NULL) {}
SpriteManager::~SpriteManager() {}
LPD3DXSPRITE SpriteManager::Sprite() {
	return m_pSprite;
}
void SpriteManager::Initialize() {
	D3DXCreateSprite(GameApp->GetDevice(), &m_pSprite);
}
void SpriteManager::Release() {
	m_pSprite->Release();
}