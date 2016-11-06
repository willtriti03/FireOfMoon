#include "Drag.h"

void DragFile::DragsFile(HDROP hDrop){
	// Index Value를 0xFFFFFFFF로 주면 드랍된 파일의 총 갯수가 리턴.
	int nFile = DragQueryFileA(hDrop, 0xFFFFFFFF, NULL, 0);
	int i = 0;
	CHAR szFilePath[MAX_PATH] = { 0, };

	if (nFile > 0)
	{
		for (i = 0; i<nFile; i++)
		{
			// 파일 알아내기
			DragQueryFileA(hDrop, i, szFilePath, MAX_PATH);
			printf("%s", szFilePath);
		}
	}




	// 드롭된 정보 없애기
	DragFinish(hDrop);
}