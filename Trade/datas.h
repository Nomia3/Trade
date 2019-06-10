#pragma once
#include "class.h"
#include "DxLib.h"

GOODS Goods[32];
CITY City[16];
MARKET Market[16][32];
MARKET HerMarket[16][32];
TRANSPORT Trans[8];
BUILDING CityBuilding[16][3];
BUILDING HerBuilding[16][3][99];
COMPANY Comp[16];
WAREHOUSE Ware[16][16];
extern HEROINE her;
extern SYSTEM sys;
extern INIT init;

void SYSTEM::MessageWindowMessage(const char* String) {

	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64), String, GetColor(255, 255, 255), init.FontHandle);
}

//���b�Z�[�W������ǉ�����Ƃ��ǉ�
void SYSTEM::DrawMessageWindow() {

	TCHAR Temp[64];
	MWX = 480;
	MWY = 800;
	DrawExtendGraph(MultiResoIntX(MWX), MultiResoIntY(MWY), MultiResoIntX(MWX + 960), MultiResoIntY(MWY +200), init.GraMW, TRUE);

	sys.MOver = FALSE;
	switch (BtnSwitch) {
	case Sw_QUIT:
		MessageWindowMessage("�I�����܂����H");
		SetTwoBtn("�͂�", "������");
		break;
	case Sw_CARGO:

		MessageWindowMessage("�ωׂ̐�������\������\��ł�");

		break;
	case Sw_TRANS:
		MessageWindowMessage("�A����i�̐�������\������\��ł�");
		SetSingleBtn("����");
		break;
	case Sw_FINAN:
		MessageWindowMessage("�����󋵂̉����������\��ł�");
		SetSingleBtn("����");
		break;
	case Sw_QUEST:
		MessageWindowMessage("���C���N�G�X�g�Ƃ��T�u�Ƃ�");
		SetSingleBtn("����");
		break;
	case Sw_PRICES:
		MessageWindowMessage("���������X��I��ł�");
		SetSingleBtn("����");
		break;
	case Sw_PRICES2:
		sprintf_s(Temp, 64, "%s�̑���ł�", City[ClickedBtn].Name);
		MessageWindowMessage(Temp);
		SetSingleBtn("����");
		break;
	case Sw_SAVE:
		MessageWindowMessage("�Z�[�u����X���b�g��I��ł�");
		SetSingleBtn("����");
		break;
	case Sw_LOAD:
		MessageWindowMessage("���[�h����X���b�g��I��ł�");
		SetSingleBtn("����");
		break;
	case Sw_OPTION:
		MessageWindowMessage("�I�v�V�������ڂ̐�����������\��ł�");
		SetSingleBtn("����");
		break;
	case Sw_CITY:
		switch (TalkNumber) {
		case 0:
			MessageWindowMessage("�i�C���悭���Ɋ��C������B");
			break;
		case 1:
			MessageWindowMessage("����ɂ��ȁI�����̓��w�~���`������I");
			break;
		case 2:
			MessageWindowMessage("���͂悤�@�_���[�W�B�����@�������悢�B");
			break;
		case 3:
			MessageWindowMessage("����@�e�C�f�����~");
			break;
		case 4:
			MessageWindowMessage("�i�C���悭���Ɋ��C������B");
			TalkNumber = 0;
			break;
		}
		break;
	case Sw_BUY:

		MessageWindowMessage("�w������f�Օi��I��ł�������");

		break;
	case Sw_SALE:
		MessageWindowMessage("���p����f�Օi��I��ł�������");
		SetSingleBtn("�߂�");
		break;
	case Sw_INVEST:
	case Sw_INVESTT:
	case Sw_INVESTB:
		MessageWindowMessage("������ʂł�");
		SetSingleBtn("�߂�");
		break;
	case Sw_INVESTI:
		MessageWindowMessage("��������");
		SetSingleBtn("�߂�");
		break;
	case Sw_MANAGE:
		MessageWindowMessage("�o�c��ʂł�");
		SetSingleBtn("�߂�");
		break;
	case Sw_TALK2:

		break;
	case Sw_EXIT:
		MessageWindowMessage("�X���o�܂����H");
		SetTwoBtn("�͂�", "������");
		break;
	}

}

//ID�@���O�@��{�l�@�W���@�H�Ɖe���x�@�Z�p�e���x�@���Y��{�l�@���Y�W���@�H�Ɛ��Y�e���x�@�Z�p���Y�e���x
void GOODS::SetGoods(int i, char* n, int b, double ind, double tech, int bp, double ipi, double tpi, int bs) {
	ID = i;
	Name = n;
	BasePrice = b;
	IndIDemandmpact = ind;
	TechDemandImpact = tech;
	BaseProd = bp;
	IndSupplyImpact = ipi;
	TechSupplyImpact = tpi;
	BaseSize = bs;
}

//ID�@���O�@��{�l�@�H�Ɖe���x�@�Z�p�e���x�@���Y��{�l�@�H�Ɛ��Y�e���x�@�Z�p���Y�e���x�@�H�Ǝs��K�͉e���x�@�Z�p�s��K�͉e���x
void GOODS::InitGoods() {
	Goods[0].SetGoods(0, (char*)"�H��", 100, 1, 1, 100, 1, 1, 100);
	Goods[1].SetGoods(1, (char*)"�ΒY", 100, 1, 1, 100, 1, 1, 100);
	Goods[2].SetGoods(2, (char*)"�z��", 100, 1, 1, 100, 1, 1, 100);
	Goods[3].SetGoods(3, (char*)"���A���^��", 100, 1, 1, 100, 1, 1, 100);
	Goods[4].SetGoods(4, (char*)"�؍�", 100, 1, 1, 100, 1, 1, 100);
	Goods[5].SetGoods(5, (char*)"����", 100, 1, 1, 100, 1, 1, 100);
	Goods[6].SetGoods(6, (char*)"�ʋl", 100, 1, 1, 100, 1, 1, 100);
	Goods[7].SetGoods(7, (char*)"�e�Ί�", 100, 1, 1, 100, 1, 1, 100);
	Goods[8].SetGoods(8, (char*)"��", 100, 1, 1, 100, 1, 1, 100);
	Goods[9].SetGoods(9, (char*)"����", 100, 1, 1, 100, 1, 1, 100);
	Goods[10].SetGoods(10, (char*)"���m�ґ�i", 100, 1, 1, 100, 1, 1, 100);
	Goods[11].SetGoods(11, (char*)"���m�ґ�i", 100, 1, 1, 100, 1, 1, 100);
	Goods[12].SetGoods(12, (char*)"�_���ґ�i", 100, 1, 1, 100, 1, 1, 100);
	Goods[13].SetGoods(13, (char*)"�ȉ�", 100, 1, 1, 100, 1, 1, 100);
	Goods[14].SetGoods(14, (char*)"����", 100, 1, 1, 100, 1, 1, 100);
	Goods[15].SetGoods(15, (char*)"�ȐD��", 100, 1, 1, 100, 1, 1, 100);
	Goods[16].SetGoods(16, (char*)"���D��", 100, 1, 1, 100, 1, 1, 100);
	Goods[17].SetGoods(17, (char*)"�Ζ�", 100, 1, 1, 100, 1, 1, 100);
}


//��{�l�@���v�@�����@�J���x�@�C���t��
int MARKET::CalcPrice(int herOn, int ID) {

	int b = Goods[ID].BasePrice;
	double d = Market[herOn][ID].Demand;
	double s = Market[herOn][ID].Supply;
	double dev = City[herOn].Develop; 
	double inf = City[herOn].Infra;

	double CalclatedPrice = b * ((std::pow(d / s, 2) + (-0.05 * dev + 1) + (-0.1 * inf + 1)) / 3);

//	double CalclatedPrice = b * ((e + (d / s) * (d / s) + (i * indimp) + (t * techimp) + (-0.05 * dev + 1) + (-0.1 * inf + 1)) / 6);

//	double CalclatedPrice = b + p * e * d / s * (i * indimp) * (t * techimp) * (-0.05 * dev + 1) * (-0.1 * inf + 1);

	return (int)CalclatedPrice;
}

int MARKET::SaleCalcPrice(int herOn, int ID) {

	int b = Goods[ID].BasePrice;
	double d = Market[herOn][ID].Demand;
	double s = Market[herOn][ID].Supply;
	double dev = City[herOn].Develop;
	double inf = City[herOn].Infra;

	double CalclatedPrice = (b * ((std::pow(d / s, 2) + (-0.05 * dev + 1) + (-0.1 * inf + 1)) / 3) ) * 0.8;

	return (int)CalclatedPrice;
}

//�i����{�l�@�����@�l���@�J���x�@���v
int MARKET::CalcProduction(int herOn, int ID) {

	int bp = Goods[ID].BaseProd;
	double p = City[herOn].Population;
	double dev = City[herOn].Develop;
	double d = Market[herOn][ID].Demand;
	double s = Market[herOn][ID].Supply;

	double CalclatedProduction = bp * (( std::pow(s, 2.0) + (p / 10000000) + dev + (0.1 * d + 1)) / 4);

	//double CalclatedProduction = bp * ((p / 10000000) + dev + tech * techimp + inf + std::pow(s, 4.0) + (0.1*d + 1) + (0.1*ind*indimp + 1) / 7);

	//double CalclatedProduction = bp + (((p / 10000000) + dev + tech * techimp + inf + s * 2 + (0.1*d+1) + (0.1*ind*indimp+1)) * pm) / 8;

	return (int)CalclatedProduction;
}

int MARKET::CalcMarketSize(int ID, int herOn) {

	int bp = Goods[ID].BaseProd;
	double p = City[herOn].Population;
	double dev = City[herOn].Develop;
	double d = Market[herOn][ID].Demand;
	double s = Market[herOn][ID].Supply;

	double CalclatedMarketSize = bp * ((std::pow(d, 2.0) + (p / 10000000) + dev + (0.1 * s + 1)) / 4);

	//double CalclatedMarketSize = bp * ((p / 10000000) + dev + tech * techimp + inf + d * d + (0.1*s + 1) + (0.1*ind*indimp + 1) / 7);

	return (int)CalclatedMarketSize;
}

void SYSTEM::CalcDemand(int herOn) {

	double bd;
	double t = City[herOn].Technology;
	double timp;
	double ind = City[herOn].Industry;
	double iimp;
	double e = City[herOn].Economy;

	for (int i = 0; i < 17; i++) {
		bd = Market[herOn][i].BaseDemand;
		timp = Goods[i].TechDemandImpact;
		iimp = Goods[i].IndIDemandmpact;

		Market[herOn][i].Demand = bd + (((t * timp) + (ind * iimp) + e) / 3);
	}

}

void SYSTEM::CalcSupply(int herOn) {

	double bs;
	double t = City[herOn].Technology;
	double timp;
	double ind = City[herOn].Industry;
	double iimp;
	double inf = City[herOn].Infra;

	for (int i = 0; i < 17; i++) {
		bs = Market[herOn][i].BaseSupply;
		timp = Goods[i].TechSupplyImpact;
		iimp = Goods[i].IndSupplyImpact;

		Market[herOn][i].Supply = bs + (((t * timp) + (ind * iimp) + inf) / 3);
	}

}

void MARKET::SetMarket(double D, double S) {

	BaseDemand = D;
	BaseSupply = S;
}

/*
	Goods[0].SetGoods(0, (char*)"�H��", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[1].SetGoods(1, (char*)"�ΒY", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[2].SetGoods(2, (char*)"�z��", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[3].SetGoods(3, (char*)"���A���^��", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[4].SetGoods(4, (char*)"�؍�", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[5].SetGoods(5, (char*)"����", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[6].SetGoods(6, (char*)"�ʋl", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[7].SetGoods(7, (char*)"�e�Ί�", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[8].SetGoods(8, (char*)"��", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[9].SetGoods(9, (char*)"����", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[10].SetGoods(10, (char*)"���m�ґ�i", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[11].SetGoods(11, (char*)"���m�ґ�i", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[12].SetGoods(12, (char*)"�_���ґ�i", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[13].SetGoods(13, (char*)"�ȉ�", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[14].SetGoods(14, (char*)"����", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[15].SetGoods(15, (char*)"�ȐD��", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[16].SetGoods(16, (char*)"���D��", 100, 1, 1, 100, 1, 1, 100, 1, 1);
	Goods[17].SetGoods(17, (char*)"�Ζ�", 100, 1, 1, 100, 1, 1, 100, 1, 1);
*/

void INIT::InitMarket() {

	Market[0][0].SetMarket(1.3, 0.5);
	Market[0][1].SetMarket(1.4, 0.4);
	Market[0][2].SetMarket(0.5, 0.1);
	Market[0][3].SetMarket(1.3, 1.0);
	Market[0][4].SetMarket(1.3, 0.95);
	Market[0][5].SetMarket(1.8, 1.4);
	Market[0][6].SetMarket(1.3, 1.0);
	Market[0][7].SetMarket(1.3, 0.8);
	Market[0][8].SetMarket(1.3, 0.5);
	Market[0][9].SetMarket(1.3, 0.5);
	Market[0][10].SetMarket(1.3, 0.5);
	Market[0][11].SetMarket(1.0, 1.7);
	Market[0][12].SetMarket(0.8, 1.2);
	Market[0][13].SetMarket(1.3, 0.5);
	Market[0][14].SetMarket(1.3, 0.5);
	Market[0][15].SetMarket(1.3, 0.5);
	Market[0][16].SetMarket(1.0, 1.7);
	Market[0][17].SetMarket(0.8, 1.2);

	Market[1][0].SetMarket(1.3, 0.5);
	Market[1][1].SetMarket(1.4, 0.4);
	Market[1][2].SetMarket(0.5, 0.1);
	Market[1][3].SetMarket(1.3, 1.0);
	Market[1][4].SetMarket(1.3, 0.95);
	Market[1][5].SetMarket(0.01, 0.01);
	Market[1][6].SetMarket(1.3, 1.0);
	Market[1][7].SetMarket(1.3, 0.8);
	Market[1][8].SetMarket(1.3, 0.5);
	Market[1][9].SetMarket(1.3, 0.5);
	Market[1][10].SetMarket(1.3, 0.5);
	Market[1][11].SetMarket(1.3, 0.5);
	Market[1][12].SetMarket(1.5, 0.3);
	Market[1][13].SetMarket(1.3, 0.5);
	Market[1][14].SetMarket(1.3, 0.5);
	Market[1][15].SetMarket(1.3, 0.5);
	Market[1][16].SetMarket(1.0, 1.7);
	Market[1][17].SetMarket(0.8, 1.2);
}

void CITY::SetCity(int I, const char* T, const char* N, double P, double D, double E, double Tech, double Ind, double Inf) {

	ID = I;
	Type = T;
	Name = N;
	Population = P;
	Develop = D;
	Economy = E;
	Technology = Tech;
	Industry = Ind;
	Infra = Inf;
}

void CITY::InitCity() {

	//ID �^�C�v ���O�@�l���@�J���x�@�i�C�@�Z�p�@�H�Ɓ@�C���t��
	City[0].SetCity(0, "��s", "���C�A", 8000000, 0.7, 1.3, 1.0, 0.2, 0.2);
	City[1].SetCity(0, "�M���̒�", "�Z�J���h", 8000000, 0.5, 1.0, 0.2, 0.2, 0.2);
	City[2].SetCity(0, "", "���C�A", 8000000, 0.7, 1.3, 0.2, 0.2, 0.2);
	City[3].SetCity(0, "", "�Z�J���h", 8000000, 0.7, 1.0, 0.2, 0.2, 0.2);
	City[4].SetCity(0, "", "���C�A", 8000000, 0.7, 1.3, 0.2, 0.2, 0.2);
	City[5].SetCity(0, "", "�Z�J���h", 8000000, 0.7, 1.0, 0.2, 0.2, 0.2);
	City[6].SetCity(0, "", "���C�A", 8000000, 0.7, 1.3, 0.2, 0.2, 0.2);
	City[7].SetCity(0, "", "�Z�J���h", 8000000, 0.7, 1.0, 0.2, 0.2, 0.2);
	City[8].SetCity(0, "", "���C�A", 8000000, 0.7, 1.3, 0.2, 0.2, 0.2);
	City[9].SetCity(0, "", "�Z�J���h", 8000000, 0.7, 1.0, 0.2, 0.2, 0.2);
}

void SYSTEM::SetHerPrices(int ID) {

	for (int i = 0; i < 32; i++) {
		HerMarket[ID][i].Demand = Market[ID][i].Demand;
		HerMarket[ID][i].Supply = Market[ID][i].Supply;
	}
}

/*
	Goods[0].SetGoods(0, (char*)"�H��", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[1].SetGoods(1, (char*)"�ΒY", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[2].SetGoods(2, (char*)"�z��", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[3].SetGoods(3, (char*)"���A���^��", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[4].SetGoods(4, (char*)"�؍�", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[5].SetGoods(5, (char*)"����", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[6].SetGoods(6, (char*)"�ʋl", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[7].SetGoods(7, (char*)"�e�Ί�", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[8].SetGoods(8, (char*)"��", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[9].SetGoods(9, (char*)"����", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[10].SetGoods(10, (char*)"���m�ґ�i", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[11].SetGoods(11, (char*)"���m�ґ�i", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[12].SetGoods(12, (char*)"�_���ґ�i", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[13].SetGoods(13, (char*)"�ȉ�", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[14].SetGoods(14, (char*)"����", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[15].SetGoods(15, (char*)"�ȐD��", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[16].SetGoods(16, (char*)"���D��", 100, 1, 1, 100, 1, 1, 1, 1);
	Goods[17].SetGoods(17, (char*)"�Ζ�", 100, 1, 1, 100, 1, 1, 1, 1);
*/

void SYSTEM::BuyData() {

	switch (her.On) {
	case 0:
		BuySort(0);
		BuySort(3);
		BuySort(6);
		BuySort(7);
		BuySort(8);
		BuySort(11);
		break;
	case 1:
		BuySort(0);
		BuySort(1);
		BuySort(4);
		BuySort(5);
		BuySort(6);
		BuySort(12);
	}
}

void TRANSPORT::SetTrans(int i, const char* n, int c, int p, bool s) {

	ID = i;
	Name = n;
	Capacity = c;
	Price = p;
	Sea = s;
}

void TRANSPORT::InitTrans() {

	Trans[0].SetTrans(0, "�n��", 50, 500, FALSE);
	Trans[1].SetTrans(1, "���D", 200, 5000, TRUE);
	Trans[2].SetTrans(2, "��^�n��", 100, 1500, FALSE);
	Trans[3].SetTrans(3, "��^���D", 300, 10000, TRUE);
	Trans[4].SetTrans(4, "�g���b�N", 50, 500, FALSE);
	Trans[5].SetTrans(5, "���C�D", 50, 500, TRUE);
	Trans[6].SetTrans(6, "��^�g���b�N", 50, 500, FALSE);
	Trans[7].SetTrans(7, "��^���C�D", 50, 500, TRUE);
}

void BUILDING::SetBuilding(int p, int m , int r) {

	Price = p;
	Maint = m;
	Rent = r;
}

//[�X�ԍ�][0������ 1�q�� 2�H��]
//�l�i, �ێ���, �ƒ�

void INIT::InitBuilding() {

	CityBuilding[0][0].SetBuilding(20000, 200, 1000);
	CityBuilding[0][1].SetBuilding(30000, 400, 1500);
	CityBuilding[0][2].SetBuilding(100000, 2000, 5000);
	CityBuilding[1][0].SetBuilding(20000, 200, 1000);
	CityBuilding[1][1].SetBuilding(20000, 200, 1000);
	CityBuilding[1][2].SetBuilding(20000, 200, 1000);
	CityBuilding[2][0].SetBuilding(20000, 200, 1000);
	CityBuilding[2][1].SetBuilding(20000, 200, 1000);
	CityBuilding[2][2].SetBuilding(20000, 200, 1000);
	CityBuilding[3][0].SetBuilding(20000, 200, 1000);
	CityBuilding[3][1].SetBuilding(20000, 200, 1000);
	CityBuilding[3][2].SetBuilding(20000, 200, 1000);
	CityBuilding[4][0].SetBuilding(20000, 200, 1000);
	CityBuilding[4][1].SetBuilding(20000, 200, 1000);
	CityBuilding[4][2].SetBuilding(20000, 200, 1000);
	CityBuilding[5][0].SetBuilding(20000, 200, 1000);
	CityBuilding[5][1].SetBuilding(20000, 200, 1000);
	CityBuilding[5][2].SetBuilding(20000, 200, 1000);
	CityBuilding[6][0].SetBuilding(20000, 200, 1000);
	CityBuilding[6][1].SetBuilding(20000, 200, 1000);
	CityBuilding[6][2].SetBuilding(20000, 200, 1000);
	CityBuilding[7][0].SetBuilding(20000, 200, 1000);
	CityBuilding[7][1].SetBuilding(20000, 200, 1000);
	CityBuilding[7][2].SetBuilding(20000, 200, 1000);
	CityBuilding[8][0].SetBuilding(20000, 200, 1000);
	CityBuilding[8][1].SetBuilding(20000, 200, 1000);
	CityBuilding[8][2].SetBuilding(20000, 200, 1000);
	CityBuilding[9][0].SetBuilding(20000, 200, 1000);
	CityBuilding[9][1].SetBuilding(20000, 200, 1000);
	CityBuilding[9][2].SetBuilding(20000, 200, 1000);
}