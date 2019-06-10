#include "DxLib.h"
#include "class.h"

FUN Mfun;
extern INIT init;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	if (DxLib_Init() == -1)    // �c�w���C�u��������������
	{
		return -1;    // �G���[���N�����璼���ɏI��
	}

	//�𑜓x�擾
	init.WinX = GetSystemMetrics(SM_CXSCREEN);
	init.WinY = GetSystemMetrics(SM_CYSCREEN);

	//�𑜓x�Z�b�g
	SetGraphMode(init.WinX, init.WinY, 32, 60);

	//�}�E�X
	SetMouseDispFlag(TRUE);

	//���C��
	Mfun.main();

	DxLib_End();        // �c�w���C�u�����g�p�̏I������

	return 0;        // �\�t�g�̏I��
}