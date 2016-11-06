#ifndef _DRAG_H_
#define _DRAG_H_

#define Drag DragFile::GetInstance()
#include "ISceneNode.h"
class DragFile{
public:
	static DragFile* GetInstance() {
		static DragFile Instance;
		return &Instance;
	}

	void DragsFile(HDROP hDrop);



};


#endif