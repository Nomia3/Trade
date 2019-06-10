#pragma once
#include "class.h"
#include "DxLib.h"

extern INIT init;

void SYSTEM::EventFunc(const char* Name, const char* string) {

	ResetCity();
	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64 - 16), Name, GetColor(255, 255, 255), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64 + 16), string, GetColor(255, 255, 255), init.FontHandle);
	WaitClick();
}

void SYSTEM::EventFunc2(const char* Name, const char* string, const char* string2) {

	ResetCity();
	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64 - 16), Name, GetColor(255, 255, 255), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64 + 16), string, GetColor(255, 255, 255), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64 + 16 + 32), string2, GetColor(255, 255, 255), init.FontHandle);
	WaitClick();
}

void SYSTEM::EventMessage(const char* string) {

	ResetCity();
	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64), string, GetColor(255, 255, 255), init.FontHandle);
	WaitClick();
}

void SYSTEM::EventEnd(int Num) {

	ETalkCount = 0;
	EventFlag[Num] = FALSE;
	Stopper = TRUE;
	BtnSwitch = Sw_CITY;
	ResetCity();
}

void SYSTEM::Event(int Num) {

	switch (Num) {

	case 0:
		switch (ETalkCount) {
		case 0:
			//�q���C���@���l�b�g
			//�c��������V�[�Y�@��l���������@�Ƒ��������X
			//�J�̂Ȃ���̑O�ɖ����ŘȂގ�l��
			//�����ŋ���
			//��ʓ]��
			EventFunc("���l�b�g", "��������A���񂶂�����E�E�E");
			EventFunc("���l�b�g", "�c�����͔̂n�Ԃ����E�E�E");
			EventFunc("���l�b�g", "�����E�E�E���ꂩ��ǂ������炢���̂��ȁE�E�E");
			EventFunc("����", "�E�E�E");
			EventFunc("���l�b�g", "���ꂳ����̂��������A�����撣��Ȃ��ƁE�E�E");
			EventFunc("����", "����������ʖڂ���B");
			EventFunc("����", "���͔��Ă�񂾁B");
			EventFunc("���l�b�g", "�����ˁE�E�E���肪�Ƃ��B");
			//��ʓ]��
			EventFunc("���l�b�g", "�f�Ղ�����I");
			EventFunc("����", "�͂��I�H");
			EventFunc("���l�b�g", "�ȒP�Ȃ��Ƃ������̂�I");
			EventFunc("���l�b�g", "��������̎d�����p���΂����񂾂�I");
			EventFunc("����", "���₢�₻��Ȃ��ƌ���������");
			EventFunc("���l�b�g", "���v�I����������`�������Ƃ����邩��I");
			EventFunc("����", "�f�Ղ��Ă��������Ĕ����Ĕ��邾������Ȃ��񂾂�I�H");
			EventFunc("����", "������Ə��ނȂ񂩂��쐬���Ȃ��Ƃ����Ȃ����B");
			EventFunc("����", "�E�E�E�܂����B");
			EventFunc("���l�b�g", "�����o����ł���H");
			EventFunc("���l�b�g", "���傤�ǎd�����Ȃ����ˁH");
			EventFunc("����", "���傤�ǂ��ĂȂ񂾂�I�Ȃ����ǂ��I");
			EventFunc("���l�b�g", "�����ł���H");
			EventFunc("����", "�E�E�E�킩�����A����B");
			EventFunc("����", "��邩��ɂ͗e�͂��Ȃ�����ȁB");
			EventFunc("���l�b�g", "�ȁA�Ȃɂ�e�͂��āB");
			EventFunc("����", "�����Ă����l�b�g���В�������ˁA�Œ���̂��Ƃ͊o���Ă����Ȃ��Ɖ��������Y�����B");
			EventFunc("���l�b�g", "�����Y�����āE�E�E");
			EventFunc("����", "�e�͂��Ȃ����Ă����䂤���Ƃ���A�����������������Ă邩��ˁB");
			EventFunc("���l�b�g", "�E�E�E�킩�������A����Ă���B");
			EventFunc("���l�b�g", "�Ȃ�ł����Ȃ����A�������Ċo�傪�����B");
			EventFunc("����", "�悵�A�_�񐬗����B��낵�����肢���܂���A�В��H");
			EventFunc("���l�b�g", "��k��߂Ă�C�F�����B���l�b�g�ł�����B");
			EventFunc("����", "�e�͂��Ȃ����Č���������H");
			//��ʓ]��
			EventFunc("���l�b�g", "���Ⴀ�s�����B");
			EventFunc("����", "�s�����Ăǂ��ɁH");
			EventFunc("���l�b�g", "���܂��Ă邶��Ȃ��A�s���B");
			EventFunc("����", "����Ȃ����Ȃ�E�E�E");
			EventFunc("���l�b�g", "�f�Ճ��[�g�͒����ς݂�B");
			EventFunc("���l�b�g", "�����Ő��m�ґ�i�𔃂���[�X�̖��O]�Ŕ���΂�����B");
			EventFunc("����", "���̊ԂɁI�H");
			EventFunc("���l�b�g", "�ق�s�����B");
			//�`���[�g���A�����o
			//Purchase�U��
			//���m�ґ�i�U��
			//���p�Ő�������͂���Enter�������Ă�������
			EventFunc("���l�b�g", "��������ˁB���Ⴀ[�X�̖��O]�܂ŏo���I");
			EventFunc("����", "���v���ȥ��");
			//�ړ���
			EventFunc("���l�b�g", "�s��͂�������I");
			//sale�U��
			//���m�ґ�i�U��
			//�w�����Ɠ����悤�ɂ���n���p���Ă��������B
			EventFunc("���l�b�g", "�悵�A����ŗ��v���E�E�E����H");
			EventFunc("���l�b�g", "���Ŕ������Ƃ����莝���������Ă�́E�E�E�H");
			EventFunc("����", "�����t���Ă����Ă悩�����B");
			EventFunc("����", "��������āB");
			//�����`���[�g���A��
			EventFunc("���l�b�g", "����H����ɓ����������Ă���̂ˁH");
			EventFunc("����", "���̒ʂ�B�����Ƃ����A�o�����グ�������Ă�B");
			EventFunc("���l�b�g", "���H���Ⴀ�����Ɩׂ���f�՘H��T���Ȃ��Ƃ����Ȃ��́H");
			EventFunc("����", "����A���_���猾���Ɣn�Ԃ���t�ɂȂ邮�炢�f�Օi��ςݍ��߂΂����B");
			EventFunc("����", "�ϓ���ƌŒ����Č����񂾂��ǐ�������H");
			ETalkCount++;
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn("���Ăق���", "���_�����ŏ\��");
			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}

			if (EventSwitch == 62) {
				EventFunc2("����", "�ϓ�����Ă����͔̂���Δ���قǑ�����o��̂��Ƃ���B", "�F�X���邯�ǎd�����p����\���ȁB");
				EventFunc2("����", "�Œ��͏��������Ȃ��Ă�������o��̂��Ƃ��B", "�������̌����Ƃ��n�̉a��A���̑��e��ێ���Ȃ񂩂����ꂾ�ˁB");
				EventFunc("����", "���̌Œ���d����悤�ɐςׂ݉���t�ςޕK�v������񂾁B");
				EventFunc("���l�b�g", "�ł���t�ςׂ݉�ς񂾂炻�́A�ϓ����������񂶂�Ȃ��H");
				EventFunc2("����", "�m���ɂ��������ǁA��p�S�̂̌Œ��̊����͉�����B", "�����āA�ϓ���̊����͕ς��Ȃ��񂾁B");
				EventFunc("���l�b�g", "�����I����Ȃ猋�ʓI�ɏ��i1������ɂ�����o����������Ȃ�̂ˁI");
				EventFunc2("����", "���̒ʂ�B���͏��i1������̌o������Ă��Ԃ�����A", "������������邽�߂Ɏ��Ƃ��g�傷��K�v������񂾁B");
			}
			else if (EventSwitch == 63) {
				EventFunc2("����", "�������ˁA��邱�Ƃ͕ς��Ȃ��B", "���Ƃ��g�傷��΂����B");

				EventEnd(Num);

			}
			ETalkCount++;
		case 2:
			EventFunc("���l�b�g", "�ł�����Ȃ����ǂ��ɂ��E�E�E");
			EventFunc("����", "�؂�邵���Ȃ����낤�ˁB");
			EventFunc("���l�b�g", "��s�ˁB�ł��݂��Ă���邩����H");
			EventFunc("����", "���[�񥥥�s�������s���Ă݂悤���B");
			EventMessage("1���Ԍ�");
			EventFunc("����", "�ʖڂ������˥��");
			EventFunc("���l�b�g", "�ǂ�����́I�H�����Ȃ�|�Y�͂��₾��I");
			EventFunc("����", "���̗��e���������Ă݂悤�B");
		//�N�G�X�g�`���[�g���A��
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			EventFunc("", "");
			break;
		}

		break;
	case 1:
		switch (ETalkCount) {
		case 0:
		EventFunc("���l�b�g", "���q�͂ǂ��H");
		EventFunc("�H�꒷", "�В�����Ȃ��ł����A�ڂ��ڂ��ł���B");
		EventFunc("���l�b�g", "���̂��ɂ͗��v���o�Ă��Ȃ��悤�����ǁH");
		EventFunc("�H�꒷", "���[�A���ꂪ�ł��ˁB�ݔ��̒��q�������Đ��Y����������ł��ł��B");
		EventFunc("���l�b�g", "�C���͂ł��Ȃ��́H");
		EventFunc("�H�꒷", "�o����ɂ͏o�����ł���������ꂻ���ɂȂ���ł��B");
		EventFunc("���l�b�g", "�V�����ݔ��𓱓�������ǂꂮ�炢�Ō�������H");
		EventFunc("�H�꒷", "3�N�͂�����܂��ˁE�E�E");
		ETalkCount++;
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn("�ݔ����������", "���̂܂܊撣����");

			DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64), "���Ⴀ�E�E�E", GetColor(255, 255, 255), init.FontHandle);
			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}

			if (EventSwitch == 62) {
				EventFunc("�H�꒷", "������ł����H����͏�����܂��B");
				EventFunc("�H�꒷", "�����ɕK�v�ȏ��ނ��쐬���Ď������̂ق��ɑ���܂��ˁB");
/*
���i����
������

�������p��100,000�@���i500,000
�����@�@�@300,000
���i���p��100,000

���i�@1,500,000�@������1,500,000
*/
				EventEnd(Num);
			}
			else if (EventSwitch == 63) {
				EventFunc("�H�꒷", "�킩��܂����A���ꂩ����ǂ����̂����܂���I");
			
				EventEnd(Num);

			}
			break;
		}
		break;
	case 2:
		//�s�i�C��
		switch (ETalkCount) {
		case 0:
			EventFunc("���l�b�g", "�ŋߕs�i�C�ˁB");
			EventFunc("����", "����΂�����͂��傤���Ȃ��ȁA�i�C�ɂ͔g������B");
			EventFunc("���l�b�g", "�i�C�������Ƃ��ł��ǂ����ɖׂ���b�͓]�����Ă��������ǁB");
			EventFunc("����", "����Ȃ��܂��b�E�E�E");
			EventFunc("�X�̒j", "���肢���܂��In���C���ł�����ŁI");
			EventFunc("���l", "���߂��߁A���̌i�C���ᔃ���Ă��J���Ȃ���B");
			EventFunc("���l�b�g", "��������ˁH");
			EventFunc("���l�b�g", "������Ƃ���������H���𔃂��Ă��J���Ȃ����āH");
			EventFunc2("�X�̒j", "���Ȃ����l�ł����I�H���肢���܂��Ia��n���C����i�����Ă��������I", "�������邠�Ă�������ł��I");
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn("����", "����Ȃ�");

			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}

			if (EventSwitch == 62) {
				EventFunc("�X�̒j", "�ق�Ƃł����I���肪�Ƃ��������܂��I");
				//���낢�돈��
				EventEnd(Num);
			}
			else if (EventSwitch == 63) {
				EventFunc("�X�̒j", "�����ł����E�E�E����������܂��E�E�E");

				EventEnd(Num);

			}
			break;
		}
		break;
	case 3:
		//��������
		switch (ETalkCount) {
		case 0:
			EventFunc("���l�b�g", "�悤�₭��Ђ炵���Ȃ��Ă�����ˁB");
			EventFunc("����", "�������ˁA���ꂩ������Ƒ傫���Ȃ��B");
			EventFunc("����", "���̂��߂ɂ����v�������Ȃ���ˁB");
			EventFunc("���l�b�g", "�����W�߂܂��傤�A�s��ɍs�����B");
			//�Ó]
			//�w�i�ύX
			EventFunc("�s��̐l", "���������ΐV�����@�D��H�ꂪ�o����񂾂��ĂȁA�m���Ă����H");
			EventFunc("�s��̐l", "�Ȃ�ł��@�B�łԂ�[���č��炵���񂾂��ǂȁB");
			EventFunc("�s��̐l", "���͒[�����߂č��ꂽ�H�[�̕����D�����ȁB");
			ETalkCount++;
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn("�s���Ă݂�", "��������");

			DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64), "�H��ˁE�E�E", GetColor(255, 255, 255), init.FontHandle);

			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}

			if (EventSwitch == 62) {

				EventSwitch = -1;
				Stopper = TRUE;
				OveredBtn = -1;
				EventFunc("���l�b�g", "������ƌ��Ă��悤������B");
				//�Ó]
				EventFunc("�c�ƒS��", "�悤������������Ⴂ�܂����B");
				EventFunc2("�c�ƒS��", "���ЍH��ł͂����ӗl���W���ł��āA", "�����X�l�����D�c�l�܂ŕ��L�����_�񂢂������Ă���܂��B");
				EventFunc("�c�ƒS��", "�܂��͏��i���������������܂����H");
				//�Ó]�̂�
				EventFunc("���l�b�g", "��v�ȕ��ˁA�f�U�C���͋C�ɓ���Ȃ����ǁB");
				EventFunc2("���l�b�g", "���v�͏\�����肻������B", "�����́H");
				//������
				EventFunc("�c�ƒS��", "�������������܂����H");
				ETalkCount++;
		case 2:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn("�_�񂷂�", "�_�񂵂Ȃ�");

			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}

			if (EventSwitch == 62) {
				EventFunc("�c�ƒS��", "���肪�Ƃ��������܂��A�ł͂�����ɃT�C�����B");

				EventEnd(Num);
			}
			else if (EventSwitch == 63) {
				EventFunc("�c�ƒS��", "�킩��܂����A����������܂����炻�̂Ƃ��͂�낵�����肢���܂��B");

				EventEnd(Num);
			}
			}
			else if (EventSwitch == 63) {
				EventFunc("�s��̐l", "��������H����ς���肾��ȁI");

				EventEnd(Num);

			}
			break;
		}
		break;
	case 4:
		switch (ETalkCount) {
		case 0:
			//�H�ƈ��ȉ�
			//�Z�p���ȏ�

			//�s��ɂ�

			//���ʉ�
			//������ۂ��w�i
			EventFunc("���l�b�g", "�������ˁA�ǂ��̂��̂�����B");
			EventFunc("�X��", "���q���񂨖ڂ������ˁB");
			EventFunc("�X��", "����̓��[���b�g�H�[�̕i���B");
			EventFunc("����", "�ł��E�E�E�����ˁB");
			EventFunc2("�X��", "�����A�i�͂����񂾂��Ȃ��Ȃ�����Ȃ��񂾂�ȁB", "�d��������~�߂悤���Ǝv�����炢���B");
			EventFunc("����", "�E�E�E");
			ETalkCount++;
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn("���ꎎ���ł��邩����H", "�������̍H�ꐻ�̕��𔃂���B");

			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}
			if (EventSwitch == 63) {
				EventFunc("�X��", "�܂��ǁI��������������Ǝv���܂���B");
				EventEnd(Num);
			}
			else if (EventSwitch == 62) {

				EventFunc("�X��", "�������B�������g���Ă���B");
				//�Ó]
				EventFunc("���l�b�g", "�ǂ��H");
				EventFunc("����", "�������I�������惊�l�b�g�I");
				EventFunc("�X��", "�����A�悭�������Ă�B");
				EventFunc("���l�b�g", "�C�ɓ�������A���ꂭ������H");
				//�Ó]
				//�w�i�]��
				EventFunc("����", "���߂񂭂����[���B");
				//���ʉ�
				EventFunc("���[���b�g�v�l", "���炠��B���q���񂩂���A�ǂ�Ȃ��p���H");
				EventFunc("����", "���͂��̍H�[��");
				EventFunc("���[���b�g�v�l", "����I���ꂤ���̕��ˁI�킴�킴���A�ɂ��Ă��ꂽ�̂ˁI�オ���ďオ���āI�����🹂�Ă����ˁI");
				EventFunc("����", "���₻��");
				EventFunc("���l�b�g", "���ז����܂��B");
				//�Ó]
				EventFunc("���[���b�g�v�l", "����ł����̒U�߂��ˁ\�\�\");
				EventFunc("���l�b�g", "����́\�\�\");
				EventFunc("����", "�͂͂́E�E�E");
				//���ʉ�
				EventFunc("���[���b�g", "�q���B");
				EventFunc("���[���b�g�v�l", "�����Ȃ̂�I�����̕����C�ɓ����Ă킴�킴�\�\�\");
				EventFunc("���[���b�g", "���񂽏��l���ȁH");
				EventFunc("���[���b�g�v�l", "���H");
				EventFunc("���l�b�g", "�����A���̍H�[�̕����d���ꂽ���́B");
				EventFunc("���[���b�g", "�d���ꂽ�Ƃ���Ŕ����肪���Ȃ����낤�B");
				EventFunc("���[���b�g", "�����Ĕ���Ȃ�����Ƃ����ǂ����d����₵�Ȃ��B");
				EventFunc("���[���b�g", "��̉������ł�H");
				EventFunc("���l�b�g", "���͂��̍H�[�̕����C�ɓ�����������B");
				EventFunc("���l�b�g", "����ȑf�G�ȕ������ɏo�Ȃ��̂͐ɂ����B");
				EventFunc("���[���b�g", "������d�������āH����Ŕ����Ȃ��J�͂��Ȃ��B");
				EventFunc("���l�b�g", "���Z�Ȃ炠���B");
				EventFunc("���[���b�g", "���H");
				EventFunc("���l�b�g", "�ݔ����������āB�P����������ΕK��������B");
				EventFunc("���[���b�g", "�n���n�������B�I���`���ŉ��̕������邩�B");
				EventFunc("���l�b�g", "�����B���̍��̋Z�p�͑f���炵���B");
				EventFunc("���l�b�g", "�ō��̋@�B�E�l����t����B");
				EventFunc("���l�b�g", "������񃍁[���b�g����̑S�ʓI�ȋ��͂��K�v�ɂȂ邯�ǁB");
				EventFunc("���[���b�g", "�E�E�E�킩������B�ǂ������̂܂܂���X���܂����A�Ō�ɓq���Ă݂�̂������Ȃ��B");
				EventFunc("���[���b�g", "�����Ă�������͓̂����������񂽂������B");
				EventFunc("���l�b�g", "���̒ʂ��B���Ⴀ���ꂪ�_�񏑁B");
				EventFunc("���[���b�g", "�ق��B���āA�Ō�Ɉ�撣�肷�邩�B");
				EventFunc("���l�b�g", "�Ōザ��Ȃ���B");
				EventFunc("���[���b�g", "���H");
				EventFunc("���l�b�g", "���ꂩ��n�܂�̂�B");
				//������������
				//��������Ɍ��ʂ��o��
				EventEnd(Num);
			}
		}
		break;
	case 5:
		switch (ETalkCount) {
		case 0:
			EventFunc("�X�̒j","�悤�A�����̏삿���B���񂽏��l����H������Ɨ��܂�Ă����B");
			EventFunc("���l�b�g", "���e�ɂ���B");
			EventFunc("�X�̒j","�ȂɁA������Ƃ����𔃂�����ė~�����̂��B");
			EventFunc("���l�b�g", "����́E�E�E");
			EventFunc("����","�ǂ��D�����B�ł��Ȃ�ł�����H");
			EventFunc("�X�̒j","���Ӑ悪�|�ꂿ�܂��ĂȁA���铖�Ă������񂾁B");
			EventFunc("�X�̒j","�ꔠ70���C����300�����A�����Ȃ��b����H");
			ETalkCount++;
		case 1:
			BtnSwitch = Sw_TALK2;
			ResetCity();
			SetTwoBtn("����", "����Ȃ�");

			DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64) , "�ǂ�����H", GetColor(255, 255, 255), init.FontHandle);
			if (Stopper == TRUE) {
				WaitClick();
				Stopper = FALSE;
			}

			if (EventSwitch == 62) {
				EventFunc("���l�b�g", "�킩�����A�ꔠ65���C���łǂ��H");
				EventFunc("�X�̒j","68���B����ȏ�͂܂��Ȃ����B");
				EventFunc("���l�b�g", "�������ˁB���؎�ł���������H");
				EventFunc("�X�̒j","�����A20400���C���������肢�����������B���肪�Ƃ��ȁB");
				EventFunc("���l�b�g", "�����炱���A�ǂ�������ł��Ă悩������B�܂���܂��傤�B");

				SearchEmpty(16);
				her.CargoPrice[SlotNumber] += 20400;
				her.Cargo[SlotNumber] += 300;
				her.Money -= 20400;
				her.CargoWeight += 300;
				her.HiddenID[SlotNumber] = 16;

				EventEnd(Num);
			}
			else if (EventSwitch == 63) {
				EventFunc("���l�b�g", "���߂�Ȃ����A���͗]�T���Ȃ��́B�����������Ă��傤�����B");
				EventFunc("�X�̒j","�������A���������Ȗ��������āB�����������炻�̂Ƃ��͂�낵���ȁB");
				EventFunc("���l�b�g", "�����炱����낵���B�܂���܂��傤�B");
				
				EventEnd(Num);

			}
			break;
		}
		break;
	case 6:

		//�N�����ȏ�H
		//�����V�[�Y�ߋ���
		//�Z�p���

		//�n�Ԃ��K�^�S�g���ʉ�
		EventFunc("���l�b�g", "�����E�E�E�����E�E�E");
		EventFunc("����", "���ς�炸�悭�Q��ȁA�܂�Ŏq���݂����ɁB");
		EventFunc("����", "�o�������Ƃ����炻���������ȁE�E�E");
		//�Ó]
		//�w�i�]��
		//�Z�s�A���班�����F�t��
		EventFunc2("�����V�[�Y", "����Ȃ��񂩁A��x�݂��Ă������ȁB", "���̖؂̉A�Ƃ����傤�ǂ悳�������B");
		EventFunc("�����V�[�Y", "����H����ȂƂ���ɒu�����E�E�E");
		EventFunc("�����V�[�Y", "����A�l���I�l���|��Ă�I");
		//�킯�����ʉ�
		EventFunc("����", "�����E�E�E�����E�E�E");
		EventFunc("�����V�[�Y", "�Ȃ񂾁E�E�E�Q�Ă邾�����B");
		EventFunc("�����V�[�Y", "�����A����ȂƂ���ŐQ�Ă�ƈ����ɏP��ꂿ�Ⴄ���B");
		EventFunc("����", "���񂤁H");
		EventFunc("����", "���Ȃ�������H");
		EventFunc("�����V�[�Y", "���̓����V�[�Y�B���X���ČĂ�Ł\�\�\");
		EventFunc("����", "�킽�����l�b�g�I�����V�[�Y�����烆�����ČĂԂˁI");
		EventFunc("����", "���E�E�E�܂��������B");
		EventFunc("���l�b�g", "��낵���ˁI�����I");
		EventFunc("���l�b�g", "���������������C�ɓ���Ȃ́H");
		EventFunc("����", "����A�w�Z�̉ۑ�ŐA���𒲂ׂĂ����񂾁B");
		EventFunc("���l�b�g", "�Ȃ񂾁E�E�E�������D���Ȃ킯����Ȃ��񂾁E�E�E");
		EventFunc("����", "����Ȃ��ƂȂ���A���߂ė������ǂ����Ƃ��낾�B�C�ɓ�������B");
		EventFunc("���l�b�g", "���ւցB������ˁI�������ɗ��āI�������i�F�������́I");
		EventFunc("����", "���A�����I");
		//�Ó]
		//�[��
		EventFunc("���l�b�g", "���A��������Ȏ��ԁA�����A��Ȃ��Ƃ�������ɓ{��ꂿ�Ⴄ��B");
		EventFunc("���l�b�g", "�����̂������͂ǂ����H");
		EventFunc("����", "�K���X�H�[�̋߂�����B");
		EventFunc("���l�b�g", "���\�߂�����Ȃ��I���x�V�тɍs���ˁI");
		EventFunc("����", "�{���H���Ⴀ�A�ꂳ��Ɍ����Ă����Ȃ��ƂȁB");
		EventFunc("���l�b�g", "���ւցB�y���݂ˁA���Ⴀ�ꏏ�ɋA��܂���I");
		//�Ó]
		//�[���̊X
		EventFunc("���l�b�g", "�������񂽂����܁[�I");
		EventFunc("���l�b�g��", "���A�胊�l�b�g�B���F�B�����H");
		EventFunc("���l�b�g", "�����Ȃ́I�������Ă����񂾂�I");
		EventFunc("����", "�����V�[�Y�Ƃ����܂��B");
		EventFunc("���l�b�g��", "�����V�[�Y���B���X����Ȃ��̂����H");
		EventFunc("����", "���[�ƁE�E�E");
		EventFunc("���l�b�g", "�����̓�������H�ςȂ�������B");
		EventFunc("���l�b�g��", "�͂͂́I�������������B��낵���ȃ����B");
		EventFunc("����", "�͂��A��낵�����肢���܂��B");
		EventFunc("���l�b�g��", "�����x���A�����Ă�����B");
		EventFunc("����", "��������ȁE�E�E");
		//�X�Y���V�I�Ȍ��ʉ�
		EventFunc("����", "�킩��܂����A���Ⴀ�����t�ɊÂ��āB");
		//�Ó]
		EventFunc("���l�b�g��", "�����͏������ɂȂ�̂��ȁH");
		EventFunc2("����", "��w�ɍs���ĕ׋����悤�Ǝv���܂��B", "�����Đl�̖��ɗ����Ƃ��������ł��B");
		EventFunc("���l�b�g��", "��w���I�����͑傫���o���ȁB");
		EventFunc("���l�b�g��", "�撣���B�����̂��Ƃł͂Ȃ�����ȁB");
		EventFunc("����", "�͂��B");
		//����
		EventFunc("����", "���A�����ł��B");
		EventFunc("���l�b�g��", "�悵�A���A���Ă������B");
		//�m�b�N��
		//�h�A��
		EventFunc("������", "�ǂȂ��H");
		EventFunc2("���l�b�g��", "���̓����V�[�Y�N�̗F�B�̕��ł��B", "�x�������̂ő��点�Ă��炢�܂����B");
		EventFunc("������", "���炠��B�킴�킴���肪�Ƃ��������܂��B");
		EventFunc("����", "�ꂳ�񂽂����܁B");
		EventFunc("������", "��������Ȃ����A���X�B�[�тł��Ă���B");
		EventFunc("���l�b�g��", "�ł͎��͂��̂ւ�ŁB");
		EventFunc("������", "�͂��A���C�����āB");
		//�h�A��
		EventFunc("����", "�ꂳ�񂠂̂ˁ\�\�\");
		//�Ó]
		//�n�ԃK�^�S�g
		//�n���~�܂銴���̉�
		EventFunc("����", "���l�b�g�A��������B");
		EventFunc("���l�b�g", "���񂤁H����A�Q������Ă��̂ˁB");
		EventFunc("����", "�ӂӂ��B");
		EventFunc("���l�b�g", "����H");
		EventFunc("����", "���ł��Ȃ���B������Ɛ̂̂��Ƃ��v���o���Ă��������B");
		EventFunc2("���l�b�g", "�H", "�܂�������B���A�s�����B");
		EventFunc("����", "�����A�������ς������B");
		break;
	}
}