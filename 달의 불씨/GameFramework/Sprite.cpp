#include "Sprite.h"
#include "TextureManager.h"
#include "SpriteManager.h"
#include "Application.h"

Sprite::Sprite(string path) : texture(NULL), device(false) {
	color = D3DXCOLOR(1.0f ,1.0f, 1.0f, 1.0f);
	texture = TextureMgr->LoadTextureFromFile(path);
	D3DSURFACE_DESC desc;
	texture->GetLevelDesc(0, &desc);
	width = desc.Width;
	height = desc.Height;

	rect.left = 0;
	rect.top = 0;
	rect.right = width;
	rect.bottom = height;
	relativeRect = rect;
}
Sprite::~Sprite() {}

void Sprite::SetImage(string path){
	color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	texture = TextureMgr->LoadTextureFromFile(path);
	D3DSURFACE_DESC desc;
	texture->GetLevelDesc(0, &desc);
	width = desc.Width;
	height = desc.Height;

	rect.left = 0;
	rect.top = 0;
	rect.right = width;
	rect.bottom = height;
	relativeRect = rect;
}

void Sprite::Update(float eTime) {
	ISceneNode::Update(eTime);
}
void Sprite::Render() {
	ISceneNode::Render();
	SpriteMgr->Sprite()->SetTransform(&m_matrix);
	SpriteMgr->Sprite()->Begin(D3DXSPRITE_ALPHABLEND);

	if(device) {
		GameApp->GetDevice()->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		GameApp->GetDevice()->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_ONE);
		GameApp->GetDevice()->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	}

	SpriteMgr->Sprite()->Draw(texture, &rect, NULL, NULL, color);
	SpriteMgr->Sprite()->End();
}