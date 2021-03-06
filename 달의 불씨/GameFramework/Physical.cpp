#include "Physical.h"
#include <iostream>
#define PIXCEL 11	//픽셀체크간격
#define GRAVITY 10 	//중력
Physical::Physical()
{
	m_pPhy = this;
}


Physical::~Physical()
{
}

void Physical::Update(float eTime){
	ISceneNode::Update(eTime);

}
void Physical::Render(){
	ISceneNode::Render();

}

int Physical::FindPoint(int x){// 화면 이동할 때 카메라 위치 조절 함수
	int mid, left, right;
	mid = (max) / 2;
	left = 0;
	right = max - 1;
	while (1){
		if (m_pGroundPoint[mid].x > x){//캐릭터 x좌표가 화면중심보다 뒤에 있을때
			right = mid;
			mid = right / 2;
		}
		else if (m_pGroundPoint[mid].x < x){//캐릭터가 중심 앞에 있을때
			left = mid;
			mid = right / 2;
		}
		else{//캐릭터가중심에붙어있을경우
			break;
			return mid;
		}
	}
}

int Physical::EllipseX(int x, int mp){//타원의 y값을 x값으로 구함
	return mp*sqrt((pow(lowRadian, 2.0) *pow(spanRadian, 2.0) - (pow(spanRadian, 2.0)*pow(x, 2.0))) / pow(lowRadian, 2.0)) + (int)centerPoint.y;
}

int Physical::EllipseY(int y, int mp){//타원의 x값을 y값으로 구함
	return mp*sqrt((pow(lowRadian, 2.0) * pow(spanRadian, 2.0) - (pow(lowRadian, 2.0)*pow(y, 2.0))) / pow(spanRadian, 2.0)) + (int)centerPoint.x;
}


bool Physical::Crush(Physical *phy1){//캐릭터가 아이템과 충돌하는지 체크
	RECT phy2Rect;
	SetTemCollison();
	phy1->SetTemCollison();

	phy2Rect = phy1->GetRect();
	if (phy1->GetRenderBool()){
		for (int i = -1 * phy1->GetLowRadian(); i <= phy1->GetLowRadian(); i += PIXCEL){
			for (int j = -1; j <= 1; j += 2){
				int y = phy1->EllipseX(i, j);
				int x = phy1->EllipseY(y - phy1->centerPoint.y, j);
				if ((phy2Rect.left <= m_rColl.left&&m_rColl.left <= phy2Rect.right) || (phy2Rect.left <= m_rColl.right&&m_rColl.right <= phy2Rect.right) ||
					(m_rColl.left <= phy2Rect.left&&phy2Rect.left <= m_rColl.right) || (m_rColl.left <= phy2Rect.right&&phy2Rect.right <= m_rColl.right)){
					if (EllipseRX(x, -1) <= y&&y <= EllipseRX(x, 1)){
						return true;
					}
				}
			}
		}

	}
	return false;
	
}

bool Physical::GroundCheck(int *move,bool stop){//물리를 적용받는오브젝트가 땅에 충돌하는지 체크
	int x, groundY;
	
	for (int i = -1 * lowRadian; i <= lowRadian; i += PIXCEL){
		x = i + (int)centerPoint.x;
		
		if (stop == true){
			groundY = (int)m_pGroundPoint[x +*move].y;
		}
		else{
			if (*move <= 0){
				groundY = (int)m_pGroundPoint[x].y;
			}
			else if (x + 512 * ((*move) / 512) + 75 > 6200){
				groundY = (int)m_pGroundPoint[x + 512 * (((*move) / 512)-1) + 75].y;
			}
			else{
				groundY = (int)m_pGroundPoint[x + 512 * ((*move) / 512)+75].y;

			}
		}
		if ((EllipseX(i, 1)) >= groundY-GRAVITY){
			crashPoint = D3DXVECTOR2(m_pObject->GetPosition().x, groundY - 2 * spanRadian);
			return true;
			break;
		}

	}
	return false;
}

void Physical::SetGravityObject(Sprite *object){//중력을  적용받을 오브젝트 등록
	m_pObject = object;
	startPos = m_pObject->GetPosition();
	//printf("Gravity		 %d		%d\n", this,m_pObject);
}

void Physical::Gravity(int *move,bool stop){//충돌할때까지 중력적용
	SetCollosion(4);
	if (GroundCheck(move,stop) == true)
		m_pObject->SetPosition(crashPoint);
	else
		m_pObject->SetPosition(D3DXVECTOR2(m_pObject->GetPosition().x, m_pObject->GetPosition().y + GRAVITY));
}

void Physical::SetCollosion(int length){//collosion설정인ㄴ듯
	Physical::length = length;
	m_rColl.left		= m_pObject->GetPosition().x;
	m_rColl.top			= m_pObject->GetPosition().y;
	m_rColl.right		= m_pObject->GetPosition().x + m_pObject->GetRect().right;
	m_rColl.bottom		= m_pObject->GetPosition().y + m_pObject->GetRect().bottom;

	lowRadian			= abs((m_rColl.right - m_rColl.left) / 2);
	spanRadian			= abs((m_rColl.bottom - m_rColl.top) / 2);
	centerPoint			= D3DXVECTOR2(lowRadian + m_rColl.left, spanRadian + m_rColl.top);

}

void Physical::SetTemCollison(){//타원콜리즌설정인듯
	//printf("Update		 %d		%d\n", this, m_pObject);
	int cnt = 0;
	m_rColl.left		= m_pObject->GetPosition().x;
	m_rColl.top			= m_pObject->GetPosition().y;
	m_rColl.right		= m_pObject->GetPosition().x + m_pObject->GetRect().right;
	m_rColl.bottom		= m_pObject->GetPosition().y + m_pObject->GetRect().bottom;

	lowRadian			= abs((m_rColl.right - m_rColl.left) / 2);
	spanRadian			= abs((m_rColl.bottom - m_rColl.top) / 2);
	centerPoint			= D3DXVECTOR2(lowRadian + m_rColl.left, spanRadian + m_rColl.top);
	phyMax				= lowRadian * 2 / PIXCEL;
	/*elliPoint = new D3DXVECTOR2[phyMax];
	for (int i = -1 * lowRadian; i <= lowRadian; i += PIXCEL){
		elliPoint[cnt++] = D3DXVECTOR2(EllipseX(i, -1),EllipseX(i, 1));
	}*/
	
}

//x©÷ / a©÷ + y©÷ / b©÷ = 1
//printf("::%4d %4d| %4d <  %4d |\n", i, 1, EllipseX(i, 1), (int)m_pGroundPoint[i + (int)centerPoint.x].y);
//printf("%f %f\n", centerPoint.x, centerPoint.y);
//printf("%ld %ld %ld %ld\n", m_rColl.left, m_rColl.right, m_rColl.top, m_rColl.bottom);
//printf("::%4d %4d| %4d <  %4d |\n", i, j, EllipseX(i, j), (int)m_pGroundPoint[i + (int)centerPoint.x].y);
//printf("%d %d %d %d\n", crashPointX, crashPointY, (int)centerPoint.x, (int)centerPoint.y);
//printf("%f %f\n", m_rColl.left, m_rColl.right);
//printf("phy %3d| %3d %3d\n", j, x, y);
//printf("cha %3d| %3.0f %3d\n\n\n", j, ((x - centerPoint.x) - (int)(x - centerPoint.x) % 10), EllipseRX(x, j));
//printf("%ld %ld %ld %ld\n", m_rColl.left, m_rColl.right, phy2Rect.left, phy2Rect.right);
/*for (int i = 0; i < phyMax; ++i){
for (int j = 0; j < phy2Max; ++j){
if ((m_rColl.left <= phy2Rect.left&&phy2Rect.left <= m_rColl.right) || (m_rColl.left <= phy2Rect.right&&phy2Rect.right <= m_rColl.right)){
if ((elliPoint[i].x <= phy2Coll[j].x && phy2Coll[j].x <= elliPoint[i].y) ||
(elliPoint[i].x <= phy2Coll[j].y && phy2Coll[j].y <= elliPoint[i].y)){
return true;
}
}
}
}
*/
