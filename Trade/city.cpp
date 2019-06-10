#include "Dxlib.h"
#include "class.h"

#define TransportTech (i == 0) || (i == 1 && City[her.On].Technology * 100 >= 30) || (i == 2 && City[her.On].Technology * 100 >= 30) || (i == 3 && City[her.On].Technology * 100 >= 40) || (i == 4 && City[her.On].Technology * 100 >= 70) || (i == 5 && City[her.On].Technology * 100 >= 80) || (i == 6 && City[her.On].Technology * 100 >= 90) || (i == 7 && City[her.On].Technology * 100 >= 100) || (i == 8) || (i == 9 && City[her.On].Technology * 100 >= 30) || (i == 10 && City[her.On].Technology * 100 >= 30) || (i == 11 && City[her.On].Technology * 100 >= 40) || (i == 12 && City[her.On].Technology * 100 >= 70) || (i == 13 && City[her.On].Technology * 100 >= 80) || (i == 14 && City[her.On].Technology * 100 >= 90) || (i == 15 && City[her.On].Technology * 100 >= 100) || (i == 16) || (i == 17 && City[her.On].Technology * 100 >= 30) || (i == 18 && City[her.On].Technology * 100 >= 30) || (i == 19 && City[her.On].Technology * 100 >= 40) || (i == 20 && City[her.On].Technology * 100 >= 70) || (i == 21 && City[her.On].Technology * 100 >= 80) || (i == 22 && City[her.On].Technology * 100 >= 90) || (i == 23 && City[her.On].Technology * 100 >= 100)

extern FUN fun;
extern INIT init;
extern HEROINE her;
extern GOODS Goods[32];
extern CITY City[16];
extern MARKET Market[16][32];
extern MARKET HerMarket[16][32];
extern TRANSPORT Trans[8];
extern BUILDING CityBuilding[16][3];
extern BUILDING HerBuilding[16][3][99];
extern COMPANY Comp[16];
extern WAREHOUSE Ware[16][16];

void SYSTEM::ResetCity() {

	for (int i = 0; i < 64; i++) {
		GoodsOn[i] = FALSE;
		BtnX[i] = -1;
		BtnY[i] = -1;
	}
	ClearDrawScreen();
	DrawExtendGraph(0, 0, init.WinX, init.WinY, init.GraCity, TRUE);
	DrawWindow(160, 120, 1, 8);
	DrawWindow(1480, 120, 2, 12);
	DrawButton(-1);
	DrawMessageWindow();
	CityData();
	if (DebugMode == TRUE) {
		DebugBox();
	}
}

void SYSTEM::CalcMarket() {

	CalcDemand(her.On);
	CalcSupply(her.On);
}

void SYSTEM::CityBtnOver(int i) {

	int x = MultiResoIntX(24);
	int y = MultiResoIntY(8);

	switch (i) {
	case 0:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[0] + x, BtnY[0] + y, "Purchase", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 1:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[1] + x, BtnY[1] + y, "Sale", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 2:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[2] + x, BtnY[2] + y, "Invest", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 3:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[3] + x, BtnY[3] + y, "Manage", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 4:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[4] + x, BtnY[4] + y, "Talk", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 5:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[5] + x, BtnY[5] + y, "Exit", GetColor(255, 0, 0), init.FontHandle);
	}
}

void SYSTEM::CityBtnOut(int OveredBtn) {

	int x = MultiResoIntX(24);
	int y = MultiResoIntY(8);

	switch (OveredBtn) {
	case 0:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[0] + x, BtnY[0] + y, "Purchase", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 1:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[1] + x, BtnY[1] + y, "Sale", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 2:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[2] + x, BtnY[2] + y, "Invest", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 3:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[3] + x, BtnY[3] + y, "Manage", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 4:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[4] + x, BtnY[4] + y, "Talk", GetColor(0, 0, 0), init.FontHandle);
		break;
	case 5:
		ResetCity();
		CityData();
		DrawStringToHandle(BtnX[5] + x, BtnY[5] + y, "Exit", GetColor(0, 0, 0), init.FontHandle);
	}
}


void SYSTEM::CityBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 0:
		BtnSwitch = Sw_BUY;
		ResetButton();
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		DrawBuyString();
		BuyData();
		if (DebugMode == TRUE) {
			DebugBox();
		}
		break;
	case 1:
		BtnSwitch = Sw_SALE;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		SaleData();
		break;
	case 2:
		BtnSwitch = Sw_INVEST;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		InvestData(-1);
		break;
	case 3:
		BtnSwitch = Sw_MANAGE;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		ManageData(-1);
		break;
	case 4:

		for (int i = 0; i < 128; i++) {
			if (EventFlag[i] == TRUE) {
				BtnSwitch = Sw_TALK;
				EventNumber = i;
				Event(EventNumber);
				return;
			}
		}
		TalkNumber++;
		ResetCity();
		break;
	case 5:
		BtnSwitch = Sw_EXIT;
		ResetCity();
		break;
	}
}

void SYSTEM::CityData() {

	TCHAR Temp[32];
	int x = 1500;
	int y = 140;

	DrawStringToHandle(MultiResoIntX(x + 100), MultiResoIntY(y), City[her.On].Name, GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x), MultiResoIntY(y + 60), "Feature", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x), MultiResoIntY(y + 100), "Population", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x), MultiResoIntY(y + 140), "Development", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x), MultiResoIntY(y + 180), "Economy", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x), MultiResoIntY(y + 220), "Technology", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x), MultiResoIntY(y + 260), "Industry", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(x), MultiResoIntY(y + 300), "Infrastructure", GetColor(0, 0, 0), init.FontHandle);

	sprintf_s(Temp, 32, "%s", City[her.On].Type);
	DrawStringToHandle(MultiResoIntX(x + 200), MultiResoIntY(y + 20 + 40), Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%.0lf", City[her.On].Population);
	DrawStringToHandle(MultiResoIntX(x + 200), MultiResoIntY(y + 20 + 40 * 2), Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Develop * 100));
	DrawStringToHandle(MultiResoIntX(x + 200), MultiResoIntY(y + 20 + 40 * 3), Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Economy * 100));
	DrawStringToHandle(MultiResoIntX(x + 200), MultiResoIntY(y + 20 + 40 * 4), Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Technology * 100));
	DrawStringToHandle(MultiResoIntX(x + 200), MultiResoIntY(y + 20 + 40 * 5), Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Industry * 100));
	DrawStringToHandle(MultiResoIntX(x + 200), MultiResoIntY(y + 20 + 40 * 6), Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d%%", (int)(City[her.On].Infra * 100));
	DrawStringToHandle(MultiResoIntX(x + 200), MultiResoIntY(y + 20 + 40 * 7), Temp, GetColor(0, 0, 0), init.FontHandle);
}

void SYSTEM::ResetButton() {
	for (int i = 0; i < 64; i++) {
		GoodsOn[i] = FALSE;
		BtnX[i] = -1;
		BtnY[i] = -1;
	}
	OveredBtn = -1;
}

void SYSTEM::BuySort(int ID) {

	TCHAR Temp[32];

	for (int i = 0; i < 16; i++) {
		SortX[i] = 560;
		SortY[i] = 240 + i * 42;
	}

	for (int i = 0; i < 63; i++) {
		if (GoodsOn[i] == FALSE) {
			BtnX[ID] = SortX[i];
			BtnY[ID] = SortY[i];
			BtnW[ID] = 150;
			BtnH[ID] = 42;
			GoodsOn[i] = TRUE;
			BtnOn[ID] = TRUE;
			MultiResoBtn(ID);
			break;
		}
	}
	Goods[ID].CalcedPrice = Market[her.On][ID].CalcPrice(her.On, ID);
	Goods[ID].CalcedProd = Market[her.On][ID].CalcProduction(her.On, ID);

	if (OveredBtn != ID)
		DrawStringToHandle(BtnX[ID], BtnY[ID], Goods[ID].Name, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d", Goods[ID].CalcedPrice);
	DrawStringToHandle(BtnX[ID] + MultiResoIntX(200), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%d", Goods[ID].CalcedProd);
	DrawStringToHandle(BtnX[ID] + MultiResoIntX(360), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%3.0lf%%", Market[her.On][ID].Demand * 100);
	DrawStringToHandle(BtnX[ID] + MultiResoIntX(520), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
	sprintf_s(Temp, 32, "%3.0lf%%", Market[her.On][ID].Supply * 100);
	DrawStringToHandle(BtnX[ID] + MultiResoIntX(520 + 160), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
}



//Goods.Name�͕i�ڂ̖��O

void SYSTEM::BuyBtnOver(int i) {

	if (i == 63) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		DrawBuyString();
		BuyData();
		DrawStringToHandle(BtnX[63], BtnY[63], "�߂�", GetColor(255, 0, 0), init.FontHandle);
	}
	else if (BtnOn[i] == TRUE) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		DrawBuyString();
		BuyData();
		DrawStringToHandle(BtnX[i], BtnY[i], Goods[i].Name, GetColor(255, 0, 0), init.FontHandle);
	}
}

void SYSTEM::BuyBtnOut(int OveredBtn) {

	if (OveredBtn == 63) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		DrawBuyString();
		BuyData();
		DrawStringToHandle(BtnX[63], BtnY[63], "�߂�", GetColor(255, 255, 255), init.FontHandle);
	}
	else if (BtnOn[OveredBtn] == TRUE) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		DrawBuyString();
		BuyData();
		DrawStringToHandle(BtnX[OveredBtn], BtnY[OveredBtn], Goods[OveredBtn].Name, GetColor(0, 0, 0), init.FontHandle);
	}
}

void SYSTEM::BuyBtnSys(int OveredBtn) {

	if (OveredBtn == 63) {
		BtnSwitch = Sw_CITY;
		ResetCity();
	}
	else if (OveredBtn != -1) {
		BtnSwitch = Sw_BUY2;
		ResetCity();
		BuySys(OveredBtn);
	}
}

void SYSTEM::DrawBuyString() {

	BtnX[63] = MWX + 640;
	BtnY[63] = MWY + 140;
	BtnW[63] = 90;
	BtnH[63] = 42;

	MultiResoBtn(63);

	DrawStringToHandle(BtnX[63], BtnY[63], "�߂�", GetColor(255, 255, 255), init.FontHandle);

	int X = 560;
	int Y = MultiResoIntY(160);

	DrawStringToHandle(MultiResoIntX(X), Y, "���O", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 200), Y, "�l�i", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 200 + 160), Y, "����", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 200 + 160 * 2), Y, "���v", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 200 + 160 * 3), Y, "����", GetColor(0, 0, 0), init.FontHandle);
}

//BuyData��datas.h�ֈړ�

void SYSTEM::BuySys(int ID) {

	if (ID < 0 || OveredBtn == 63 || OveredBtn == 62) {
		BtnSwitch = Sw_BUY;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		DrawBuyString();
		BuyData();
		OveredBtn = -1;
		return;
	}
	SearchEmpty(ID);

	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64) , "�����w�����܂����H", GetColor(255, 255, 255), init.FontHandle);
	printfDx("SlotNumber=%d\n", SlotNumber);

	TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), 9999, 0, FALSE);
	TempPrice = Goods[ID].CalcedPrice * TempNumber;

	printfDx("BoughtNumber=%d\n", TempNumber);
	printfDx("BoughtPrice=%d\n", TempPrice);
	printfDx("CargoPrice=%d\n", her.CargoPrice[SlotNumber]);

	if (TempPrice > her.Money) {
		ResetCity();
		MessageWindowMessage("������������܂���");
		WaitClick();
	}
	else if (TempNumber + her.CargoWeight > her.MaxWeight) {
		ResetCity();
		MessageWindowMessage("�d�ʃI�[�o�[�ł�");
		WaitClick();
	}
	else if (TempNumber != 0)
	{
		her.CargoPrice[SlotNumber] += Goods[ID].CalcedPrice * TempNumber;
		her.Cargo[SlotNumber] += TempNumber;
		her.Money -= TempPrice;
		her.CargoWeight += TempNumber;
		her.HiddenID[SlotNumber] = ID;

		if (her.Cargo[SlotNumber] != 0) {
			ResetCity();
			MessageWindowMessage("�w�����܂���");
			WaitClick();
		}
	}
	BtnSwitch = Sw_BUY;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	DrawBuyString();
	OveredBtn = -1;
	BuyData();
}

void SYSTEM::SaleSort(int ID) {

	TCHAR Temp[32];

	for (int i = 0; i < 16; i++) {
		SortX[i] = 560;
		SortY[i] = 240 + i * 42;
	}

	for (int i = 0; i < 63; i++) {
		if (GoodsOn[i] == FALSE) {
			BtnX[ID] = SortX[i];
			BtnY[ID] = SortY[i];
			BtnW[ID] = 150;
			BtnH[ID] = 42;
			BtnOn[ID] = TRUE;
			GoodsOn[i] = TRUE;

			MultiResoBtn(ID);

			sprintf_s(Temp, 32, "%d", her.CargoPrice[i] / her.Cargo[i]);	//������l
			DrawStringToHandle(BtnX[ID] + MultiResoIntX(190), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%d", her.Cargo[i]);	//�ωא���
			DrawStringToHandle(BtnX[ID] + MultiResoIntX(210 + 110 * 2), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
			break;
		}
	}

	Goods[ID].CalcedPrice = Market[her.On][ID].SaleCalcPrice(her.On, ID);

	if (OveredBtn != ID)
		DrawStringToHandle(BtnX[ID], BtnY[ID], Goods[ID].Name, GetColor(0, 0, 0), init.FontHandle);

	sprintf_s(Temp, 32, "%d", Goods[ID].CalcedPrice); //���l
	DrawStringToHandle(BtnX[ID] + MultiResoIntX(210 + 110), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);

}


void SYSTEM::SaleBtnOver(int i) {

	if (i == 63) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		SaleData();
		DrawStringToHandle(BtnX[63], BtnY[63], "�߂�", GetColor(255, 0, 0), init.FontHandle);
	}
	else if (BtnOn[i] == TRUE) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		SaleData();
		DrawStringToHandle(BtnX[i], BtnY[i], Goods[i].Name, GetColor(255, 0, 0), init.FontHandle);
	}
}

void SYSTEM::SaleBtnOut(int OveredBtn) {

	if (OveredBtn == 63) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		SaleData();
		DrawStringToHandle(BtnX[63], BtnY[63], "�߂�", GetColor(255, 255, 255), init.FontHandle);
	}
	else if (BtnOn[OveredBtn] == TRUE) {
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		SaleData();
		DrawStringToHandle(BtnX[OveredBtn], BtnY[OveredBtn], Goods[OveredBtn].Name, GetColor(0, 0, 0), init.FontHandle);
	}
}

void SYSTEM::SaleBtnSys(int OveredBtn) {

	if (OveredBtn == 63) {
		BtnSwitch = Sw_CITY;
		ResetCity();
	}
	else if (OveredBtn == 62) {

	}
	else if (OveredBtn != -1) {
		BtnSwitch = Sw_SALE2;
		ResetCity();
		SaleSys(OveredBtn);
	}
}

void SYSTEM::SaleData() {

	int X = 560;
	int Y = MultiResoIntY(160);

	DrawStringToHandle(MultiResoIntX(X), Y, "���O", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 190), Y, "������l", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 210 + 110), Y, "���l", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 210 + 110 * 2), Y, "����", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 210 + 110 * 3), Y, "�����", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 210 + 110 * 4), Y, "���v", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 210 + 110 * 5), Y, "����", GetColor(0, 0, 0), init.FontHandle);

	for (int i = 0; i < 8; i++) {
		if (her.HiddenID[i] != -1)
			SaleSort(her.HiddenID[i]);
	}
}

void SYSTEM::SaleSys(int ID) {

	for (int i = 0; i < 64; i++) {
		if (her.HiddenID[i] == ID) {
			SlotNumber = i;
			break;
		}
	}

	MessageWindowMessage("�������p���܂����H");
	printfDx("SlotNumber=%d\n", SlotNumber);

	TempNumber = KeyInputNumber(MWX + 64 + 32, MWY + 96, 9999, 0, FALSE);
	TempPrice = Goods[ID].CalcedPrice * TempNumber;

	printfDx("BoughtNumber=%d\n", TempNumber);
	printfDx("BoughtPrice=%d\n", TempPrice);
	printfDx("CargoPrice=%d\n", her.CargoPrice[SlotNumber]);

	if (TempNumber > her.Cargo[SlotNumber]) {
		ResetCity();
		MessageWindowMessage("���L�ʂ𒴂��Ă��܂�");
		WaitClick();
	}
	else if (TempNumber != 0)
	{
		her.CargoPrice[SlotNumber] -= her.CargoPrice[SlotNumber] / her.Cargo[SlotNumber] * TempNumber;
		her.Cargo[SlotNumber] -= TempNumber;
		her.Money += TempPrice;
		her.CargoWeight -= TempNumber;
		if (her.Cargo[SlotNumber] == 0)
			her.HiddenID[SlotNumber] = -1;

		ResetCity();
		MessageWindowMessage("���p���܂���");
		WaitClick();

	}
	BtnSwitch = Sw_SALE;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	OveredBtn = -1;
	SaleData();
}

void SYSTEM::InvestBtnOver(int i) {

	switch (BtnSwitch) {
	case Sw_INVEST:
	case Sw_INVESTT:
	case Sw_INVESTB:
	case Sw_INVESTI:
		if (i == 63) {
			ResetCity();
			DrawWindow(520, 140, 5, 16);
			InvestData(i);
			DrawStringToHandle(BtnX[63], BtnY[63], "�߂�", GetColor(255, 0, 0), init.FontHandle);
		}
		else if (BtnOn[i] == TRUE) {
			if (TransportTech) {
				ResetCity();
				DrawWindow(520, 140, 5, 16);
				InvestData(i);
				DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(255, 0, 0), init.FontHandle);
			}
		}
		break;
	case Sw_INVESTBUYB:
	case Sw_INVESTRENTB:
		if (BtnOn[i] == TRUE) {
			ResetCity();
			if (BtnSwitch == Sw_INVESTBUYB)
				MessageWindowMessage("�w�����܂����H");
			else
				MessageWindowMessage("�_�񂵂܂����H");
			SetTwoBtn("�͂�", "������");
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(255, 0, 0), init.FontHandle);
		}
		break;
	}
}

void SYSTEM::InvestBtnOut(int i) {

	switch (BtnSwitch) {
	case Sw_INVEST:
	case Sw_INVESTT:
	case Sw_INVESTB:
	case Sw_INVESTI:
		if (i == 63) {
			ResetCity();
			DrawWindow(520, 140, 5, 16);
			InvestData(i);
			DrawStringToHandle(BtnX[63], BtnY[63], "�߂�", GetColor(255, 255, 255), init.FontHandle);
		}
		else if (BtnOn[i] == TRUE) {
			if (TransportTech) {
				ResetCity();
				DrawWindow(520, 140, 5, 16);
				InvestData(i);
				DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
			}
		}
		break;
	case Sw_INVESTBUYB:
	case Sw_INVESTRENTB:
		if (BtnOn[i] == TRUE) {
			ResetCity();
			if (BtnSwitch == Sw_INVESTBUYB)
				MessageWindowMessage("�w�����܂����H");
			else
				MessageWindowMessage("�_�񂵂܂����H");
			SetTwoBtn("�͂�", "������");
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(255, 255, 255), init.FontHandle);
		}
		break;
	}
}

void SYSTEM::InvestBtnSys(int i) {

	switch (i) {
	case 63:
		BtnSwitch = Sw_CITY;
		ResetCity();
		break;
	case 0:
		BtnSwitch = Sw_INVESTT;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		InvestData(-1);
		break;
	case 1:
		BtnSwitch = Sw_INVESTB;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		InvestData(-1);
		break;
	case 2:
		BtnSwitch = Sw_INVESTI;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		InvestData(-1);
		break;
	}
}

void SYSTEM::InvestData(int Btn) {

	switch (BtnSwitch) {

	case Sw_INVEST:
		for (int i = 0; i < 3; i++) {
			BtnX[i] = 600;
			BtnY[i] = 200 + i * 70;
			BtnOn[i] = TRUE;
			MultiResoBtn(i);
		}
		TempChar[0] = "�A����i����";
		TempChar[1] = "��������";
		TempChar[2] = "����";

		if (Btn != 0)
			DrawStringToHandle(BtnX[0], BtnY[0], TempChar[0], GetColor(0, 0, 0), init.FontHandle);
		if (Btn != 1)
			DrawStringToHandle(BtnX[1], BtnY[1], TempChar[1], GetColor(0, 0, 0), init.FontHandle);
		if (Btn != 2)
			DrawStringToHandle(BtnX[2], BtnY[2], TempChar[2], GetColor(0, 0, 0), init.FontHandle);
		break;
	case Sw_INVESTT:
		InvestDataT(-1);
		break;
	case Sw_INVESTB:
		InvestDataB(-1);
		break;
	case Sw_INVESTI:
		InvestDataI(-1);
		break;
	}
}

void SYSTEM::InvestBtnSysT(int i) {

	if (i == 63) {
		BtnSwitch = Sw_INVEST;
		ResetCity();
	}
	else if (TransportTech) {
		if (i < 8) {
			BtnSwitch = Sw_INVESTBUYT;
			ResetCity();
			InvestBuySysT(i);
		}
		else if (i >= 8 && i < 16) {
			BtnSwitch = Sw_INVESTSALET;
			ResetCity();
			InvestSaleSysT(i - 8);
		}
	}
}

void SYSTEM::InvestDataT(int Btn) {

	int x = 0;
	int y = 0;
	int i = 0;

	TempChar[0] = "�w��";
	TempChar[1] = "�w��";
	TempChar[2] = "�w��";
	TempChar[3] = "�w��";
	TempChar[4] = "�w��";
	TempChar[5] = "�w��";
	TempChar[6] = "�w��";
	TempChar[7] = "�w��";
	TempChar[8] = "���p";
	TempChar[9] = "���p";
	TempChar[10] = "���p";
	TempChar[11] = "���p";
	TempChar[12] = "���p";
	TempChar[13] = "���p";
	TempChar[14] = "���p";
	TempChar[15] = "���p";
	TempChar[16] = "�n��";
	TempChar[17] = "���D";
	TempChar[18] = "��^�n��";
	TempChar[19] = "��^���D";
	TempChar[20] = "�g���b�N";
	TempChar[21] = "���C�D";
	TempChar[22] = "��^�g���b�N";
	TempChar[23] = "��^���C�D";

	//0�n��0�@1���D30�@2��^�n��30�@3��^���D40�@4�g���b�N70�@5���C�D80�@6��^�g���b�N90�@7��^���C�D100
	while (i < 24) {
		BtnX[i] = 1000 + x * 200;
		BtnY[i] = 180 + y * 50;
		BtnW[i] = 180;
		BtnH[i] = 42;
		MultiResoBtn(i);
		if (i < 16)
			BtnOn[i] = TRUE;
		if (Btn != i)
			if (TransportTech)
				DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
		y++;
		i++;
		if (i == 8) {
			x++;
			y = 0;
		}
		if (i == 16) {
			x = -2;
			y = 0;
		}
	}
}

void SYSTEM::InvestBuySysT(int ID) {

	MessageWindowMessage("�����w�����܂����H");

	TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), 1000000, 0, FALSE);
	TempPrice = Trans[ID].Price * TempNumber;

	if (TempPrice > her.Money) {
		ResetCity();
		MessageWindowMessage("������������܂���B");
		WaitClick();
	}
	else if (Trans[ID].Sea == FALSE && TempNumber + her.MaxWeight > 999999999) {
		ResetCity();
		MessageWindowMessage("����ȏ㔃���܂���B");
		WaitClick();
	}
	else if (Trans[ID].Sea == TRUE && TempNumber + her.ShipMaxWeight > 999999999 ) {
		ResetCity();
		MessageWindowMessage("����ȏ㔃���܂���B");
		WaitClick();
	}
	else if (TempNumber != 0)
	{
		her.Transport[ID] += TempNumber;
		her.Money -= TempPrice;
		ResetCity();
		MessageWindowMessage("�w�����܂����B");
		WaitClick();
	}
	BtnSwitch = Sw_INVESTT;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	InvestData(-1);
	OveredBtn = -1;
	printfDx("%d\n", her.Transport[0]);
}

void SYSTEM::InvestSaleSysT(int ID) {

	TCHAR Temp[32];
	if (her.Transport[ID] == 0) {
		ResetCity();
		MessageWindowMessage("�������Ă��܂���B");
		WaitClick();
	}
	else {
		MessageWindowMessage("�������p���܂����H");
		sprintf_s(Temp, 32, "0�`%d", her.Transport[ID]);
		DrawStringToHandle(MultiResoIntX(MWX + 64 + 32 + 256), MultiResoIntY(MWY + 64), Temp, GetColor(255, 255, 255), init.FontHandle);

		TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), 1000000, 0, FALSE);
		TempPrice = (int)(Trans[ID].Price * TempNumber * 0.8);


		if (her.Transport[ID] < TempNumber) {
			ResetCity();
			MessageWindowMessage("�������𒴂��Ă��܂��B");
			WaitClick();
		}
		else if (TempNumber != 0)
		{
			her.Transport[ID] -= TempNumber;
			her.Money += TempPrice;
			ResetCity();
			MessageWindowMessage("���p���܂����B");
			WaitClick();
		}
	}
	BtnSwitch = Sw_INVESTT;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	InvestData(-1);
	OveredBtn = -1;
}

void SYSTEM::InvestBtnSysB(int i) {

	switch (BtnSwitch) {
	case Sw_INVESTB:
		if (i == 63) {
			BtnSwitch = Sw_INVEST;
			ResetCity();
		}
		else {
			if (3 <= i && i <= 5) {
				BtnSwitch = Sw_INVESTRENTB;
				ResetCity();
				InvestRentSysB(i - 3);
			}
			else if (6 <= i && i <= 8) {
				BtnSwitch = Sw_INVESTENDB;
				ResetCity();
				InvestEndSysB(i - 6);
			}
			else if (9 <= i && i <= 11) {
				BtnSwitch = Sw_INVESTBUYB;
				ResetCity();
				InvestBuySysB(i - 9);
			}
			else if (12 <= i && i <= 14) {
				BtnSwitch = Sw_INVESTSALEB;
				ResetCity();
				InvestSaleSysB(i - 12);
			}
		}
		break;
	case Sw_INVESTBUYB:
		if (i == 63) {
			BtnSwitch = Sw_INVESTB;
			ResetCity();
		}
		else if (i == 62) {
			BuyFlag = TRUE;
			InvestBuySysB(0);
		}
		break;
	case Sw_INVESTRENTB:
		if (i == 63) {
			BtnSwitch = Sw_INVESTB;
			ResetCity();
		}
		else if (i == 62) {
			BuyFlag = TRUE;
			InvestRentSysB(0);
		}
		break;
	}
}

void SYSTEM::InvestDataB(int Btn) {

	int x = 0;
	int y = 0;
	char* Temp;

	TempChar[0] = "�ؐ�";
	TempChar[1] = "���L��";
	TempChar[2] = "����";
	TempChar[3] = "����";

	for (int i = 0; i < 16; i++) {
		if (i <= 9) {
			TempValueX[i] = 650 + x * 50;
			TempValueY[i] = 180 + y * 70;
			MultiResoValue(i);
		}
		else {
			TempValueX[i] = 660 + x * 50;
			TempValueY[i] = 180 + y * 70;
			MultiResoValue(i);
		}

		if (i <= 3) {
			DrawStringToHandle(TempValueX[i], TempValueY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
			x += 2;
		}
		if (i == 3) {
			x = 0;
			y = 1;
		}
		if (i >= 4) {
			if (i >= 4 && i <= 6)
				sprintf_s(TempT, 32, "%d", CityBuilding[her.On][i - 4].RentNumber);
			if (i >= 7 && i <= 9) {
				CountBuilding(i - 7);
				sprintf_s(TempT, 32, "%d", BuildingCount);
				BuildingCount = 0;
			}
			if (i >= 10 && i <= 12) {
				Temp = AddCommaN(CityBuilding[her.On][i - 10].Rent);
				sprintf_s(TempT, 32, "%s", Temp);
			}
			if (i >= 13 && i <= 15){
				Temp = AddCommaN(CityBuilding[her.On][i - 13].Price);
				sprintf_s(TempT, 32, "%s", Temp);
			}
			DrawStringToHandle(TempValueX[i], TempValueY[i], TempT, GetColor(0, 0, 0), init.FontHandle);

			y++;

			if (i == 6 || i == 12) {
				x += 2;
				y = 1;
			}
			if (i == 9) {
				x++;
				y = 1;
			}
		}
	}

	x = 0;
	y = 0;

	TempChar[0] = "������";
	TempChar[1] = "�q��";
	TempChar[2] = "�H��";
	TempChar[3] = "����";
	TempChar[4] = "����";
	TempChar[5] = "����";
	TempChar[6] = "���";
	TempChar[7] = "���";
	TempChar[8] = "���";
	TempChar[9] = "�w��";
	TempChar[10] = "�w��";
	TempChar[11] = "�w��";
	TempChar[12] = "���p";
	TempChar[13] = "���p";
	TempChar[14] = "���p";

	for (int i = 0; i <= 2; i++) {
	
		BtnX[i] = 550 + x * 95;
		BtnY[i] = 250 + y * 70;
		BtnW[i] = 180;
		BtnH[i] = 42;
		MultiResoBtn(i);

		y++;

		if (Btn != i)
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
	}

	y = 0;

	for (int i = 3; i <= 14; i++) {

		if (i == 6 || i == 9 || i == 12) {
			x++;
			y = 0;
		}

		BtnX[i] = 1030 + x * 100;
		BtnY[i] = 250 + y * 70;
		BtnW[i] = 90;
		BtnH[i] = 42;
		MultiResoBtn(i);

		y++;

		BtnOn[i] = TRUE;

		if (Btn != i)
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
	}
}

void SYSTEM::InvestBuySysB(int ID) {
	
	if (ID == 0 && BuyFlag == FALSE) {
		BtnSwitch = Sw_INVESTBUYB;
		MessageWindowMessage("�w�����܂����H");
		SetTwoBtn("�͂�", "������");
		return;
	}
	else if (ID == 0 && (CountBuilding(ID) >= 1 || CityBuilding[her.On][ID].RentNumber >= 1)) {
		ResetCity();
		MessageWindowMessage("���������Ă��܂��B");
		BuyFlag = FALSE;
		WaitClick();
	}
	else if (BuyFlag == TRUE) {
		TempNumber = 1;
		TempPrice = CityBuilding[her.On][ID].Price;

		for (int i = 0; i < TempNumber; i++) {
			SearchBuildingEmpty(ID);
			HerBuilding[her.On][ID][BuildingSlot].Number++;
		}
		her.Money -= TempPrice;
		ResetCity();
		MessageWindowMessage("�w�����܂����B");
		BuyFlag = FALSE;
		WaitClick();
	}
	else {
		MessageWindowMessage("�����w�����܂����H");

		TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), 1000000, 0, FALSE);
		TempPrice = CityBuilding[her.On][ID].Price * TempNumber;

		if (TempPrice > her.Money) {
			ResetCity();
			MessageWindowMessage("������������܂���B");
			WaitClick();
		}
		else if (CountBuilding(ID) + CityBuilding[her.On][ID].RentNumber + TempNumber > 99) {
			ResetCity();
			MessageWindowMessage("����Ȃɔ����܂���B");
			WaitClick();
		}
		else if (TempNumber != 0)
		{
			for (int i = 0; i < TempNumber; i++) {
				SearchBuildingEmpty(ID);
				HerBuilding[her.On][ID][BuildingSlot].Number++;
			}
			her.Money -= TempPrice;
			ResetCity();
			MessageWindowMessage("�w�����܂����B");
			WaitClick();
		}
	}
		BtnSwitch = Sw_INVESTB;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		InvestData(-1);
		OveredBtn = -1;
		printfDx("%d\n", CityBuilding[her.On][ID].Number);
	
}

void SYSTEM::InvestSaleSysB(int ID) {

	TCHAR Temp[32];
	if (CountBuilding(ID) == 0) {
		ResetCity();
		MessageWindowMessage("�������Ă��܂���B");
		WaitClick();
	}
	else {
		MessageWindowMessage("�������p���܂����H");
		sprintf_s(Temp, 32, "0�`%d", CountBuilding(ID));
		DrawStringToHandle(MultiResoIntX(MWX + 64 + 32 + 256), MultiResoIntY(MWY + 64), Temp, GetColor(255, 255, 255), init.FontHandle);

		TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), CountBuilding(ID), 0, FALSE);
		TempPrice = (int)CalcSellBuilding(ID);


		if (CountBuilding(ID) < TempNumber) {
			ResetCity();
			MessageWindowMessage("�������𒴂��Ă��܂��B");
			WaitClick();
		}
		else if (TempNumber != 0)
		{
			for (int i = 0; i < TempNumber; i++) {
				SearchCheapestBuilding(ID);
				HerBuilding[her.On][ID][CheapestBuildingID].Reset(ID);
			}
			her.Money += TempPrice;
			ResetCity();
			MessageWindowMessage("���p���܂����B");
			WaitClick();
		}
	}
	BtnSwitch = Sw_INVESTB;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	InvestData(-1);
	OveredBtn = -1;
}

void SYSTEM::InvestRentSysB(int ID) {

	TCHAR Temp[64];

	if (ID == 0 && BuyFlag == FALSE) {
		BtnSwitch = Sw_INVESTRENTB;
		MessageWindowMessage("�_�񂵂܂����H");
		SetTwoBtn("�͂�", "������");
		return;
	}
	else if (ID == 0 && (CountBuilding(ID) >= 1 || CityBuilding[her.On][ID].RentNumber >= 1)) {
		ResetCity();
		MessageWindowMessage("���������Ă��܂��B");
		BuyFlag = FALSE;
		WaitClick();
	}
	else if (BuyFlag == TRUE) {

		CityBuilding[her.On][ID].RentNumber++;
		her.Money -= CityBuilding[her.On][ID].Rent * 2;
		ResetCity();
		MessageWindowMessage("�_�񂵂܂����B");
		BuyFlag = FALSE;
		WaitClick();
	}
	else {

		sprintf_s(Temp, 64, "�����_�񂵂܂����H(�����͒����̓�{�ł��B) 0�`%d", 99 - CityBuilding[her.On][ID].RentNumber);
		DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64), Temp, GetColor(255, 255, 255), init.FontHandle);

		TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), 99 - CityBuilding[her.On][ID].RentNumber, 0, FALSE);
		TempPrice = CityBuilding[her.On][ID].Rent * TempNumber * 2;

		if (TempPrice > her.Money) {
			ResetCity();
			MessageWindowMessage("������������܂���B");
			WaitClick();
		}
		else if (CityBuilding[her.On][ID].RentNumber + CountBuilding(ID) + TempNumber > 99) {
			ResetCity();
			MessageWindowMessage("����ȂɎ؂��܂���B");
			WaitClick();
		}
		else if (TempNumber != 0)
		{
			CityBuilding[her.On][ID].RentNumber += TempNumber;
			her.Money -= TempPrice;
			ResetCity();
			MessageWindowMessage("�_�񂵂܂����B");
			WaitClick();
		}
	}
	BtnSwitch = Sw_INVESTB;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	InvestData(-1);
	OveredBtn = -1;
	printfDx("%d\n", CityBuilding[her.On][ID].Number);
}

void SYSTEM::InvestEndSysB(int ID) {

	TCHAR Temp[32];
	if (CityBuilding[her.On][ID].RentNumber == 0) {
		ResetCity();
		MessageWindowMessage("�؂�Ă��܂���B");
		WaitClick();
	}
	else {
		MessageWindowMessage("������񂵂܂����H");
		sprintf_s(Temp, 32, "0�`%d", CityBuilding[her.On][ID].RentNumber);
		DrawStringToHandle(MultiResoIntX(MWX + 64 + 32 + 256), MultiResoIntY(MWY + 64), Temp, GetColor(255, 255, 255), init.FontHandle);

		TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), CityBuilding[her.On][ID].RentNumber, 0, FALSE);

		if (CityBuilding[her.On][ID].RentNumber < TempNumber) {
			ResetCity();
			MessageWindowMessage("�_�񐔂𒴂��Ă��܂��B");
			WaitClick();
		}
		else if (TempNumber != 0)
		{
			CityBuilding[her.On][ID].RentNumber -= TempNumber;
			ResetCity();
			MessageWindowMessage("��񂵂܂����B");
			WaitClick();
		}
	}
	BtnSwitch = Sw_INVESTB;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	InvestData(-1);
	OveredBtn = -1;
}

void SYSTEM::InvestBtnSysI(int i) {

	if (i == 63) {
		BtnSwitch = Sw_CITY;
		ResetCity();
	}
}

void SYSTEM::InvestDataI(int i) {


}

void SYSTEM::InvestBuySysI(int i) {


}

void SYSTEM::InvestSaleSysI(int i) {


}

void SYSTEM::ManageBtnOver(int i) {

	switch (BtnSwitch) {
	case Sw_MANAGE:
	case Sw_MANAGEO:
	case Sw_MANAGEW:
	case Sw_MANAGEWIN:
	case Sw_MANAGEWOUT:
	case Sw_MANAGEF:
		if (i == 63) {
			ResetCity();
			DrawWindow(520, 140, 5, 16);
			ManageData(i);
			DrawStringToHandle(BtnX[63], BtnY[63], "�߂�", GetColor(255, 0, 0), init.FontHandle);
		}
		else if (BtnOn[i] == TRUE) {
			ResetCity();
			DrawWindow(520, 140, 5, 16);
			ManageData(i);
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(255, 0, 0), init.FontHandle);
		}
		break;
	}
}

void SYSTEM::ManageBtnOut(int i) {

	switch (BtnSwitch) {
	case Sw_MANAGE:
	case Sw_MANAGEO:
	case Sw_MANAGEW:
	case Sw_MANAGEWIN:
	case Sw_MANAGEWOUT:
	case Sw_MANAGEF:
		if (i == 63) {
			ResetCity();
			DrawWindow(520, 140, 5, 16);
			ManageData(i);
			DrawStringToHandle(BtnX[63], BtnY[63], "�߂�", GetColor(255, 255, 255), init.FontHandle);
		}
		else if (BtnOn[i] == TRUE) {
			ResetCity();
			DrawWindow(520, 140, 5, 16);
			ManageData(i);
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
		}
		break;
	}
}

void SYSTEM::ManageBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 63:
		BtnSwitch = Sw_CITY;
		ResetCity();
		break;
	case 0:
		BtnSwitch = Sw_MANAGEO;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		ManageDataO(-1);
		break;
	case 1:
		BtnSwitch = Sw_MANAGEW;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		ManageDataW(-1);
		break;
	case 2:
		BtnSwitch = Sw_MANAGEF;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		ManageDataF(-1);
		break;
	}
}

void SYSTEM::ManageData(int Btn) {

	switch (BtnSwitch) {

	case Sw_MANAGE:
		for (int i = 0; i < 3; i++) {
			BtnX[i] = 600;
			BtnY[i] = 200 + i * 70;
			BtnOn[i] = TRUE;
			MultiResoBtn(i);
		}
		TempChar[0] = "������";
		TempChar[1] = "�q��";
		TempChar[2] = "�H��";

		if (Btn != 0)
			DrawStringToHandle(BtnX[0], BtnY[0], TempChar[0], GetColor(0, 0, 0), init.FontHandle);
		if (Btn != 1)
			DrawStringToHandle(BtnX[1], BtnY[1], TempChar[1], GetColor(0, 0, 0), init.FontHandle);
		if (Btn != 2)
			DrawStringToHandle(BtnX[2], BtnY[2], TempChar[2], GetColor(0, 0, 0), init.FontHandle);
		break;
	case Sw_MANAGEO:
		ManageDataO(Btn);
		break;
	case Sw_MANAGEW:
		ManageDataW(Btn);
		break;
	case Sw_MANAGEWIN:
		ManageDataWIn();
		break;
	case Sw_MANAGEF:
		ManageDataF(Btn);
		break;
	}
}

void SYSTEM::ManageBtnSysO(int i) {

	if (i == 63) {
		BtnSwitch = Sw_MANAGE;
		ResetCity();
	}
	else if (i == 0) {
		BtnSwitch = Sw_MANAGEEMPO;
		ResetCity();
		ManageEmpSysO();
	}
	else if (i == 1) {
		BtnSwitch = Sw_MANAGEENDO;
		ResetCity();
		ManageEmpEndSysO();
	}
}

void SYSTEM::ManageDataO(int Btn) {

	TCHAR Temp[32];
	int x = 0;
	int y = 0;

	SetSingleBtn("�߂�");

	TempChar[0] = "�]�ƈ���";
	TempChar[1] = "�f�՘H�ꗗ";

	for (int i = 0; i < 2; i++) {
		TempValueX[i] = 600;
		TempValueY[i] = 200 + i * 84;
		MultiResoValue(i);
		DrawStringToHandle(TempValueX[i], TempValueY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
		y++;
	}
	for (int i = 0; i < 1; i++) {
		TempValueX[i] = 800;
		TempValueY[i] = 200 + i * 42;
		MultiResoValue(i);
		sprintf_s(Temp, 32, "%d", Comp[her.On].OEmployee);
		DrawStringToHandle(TempValueX[i], TempValueY[i], Temp, GetColor(0, 0, 0), init.FontHandle);
		y++;
	}

	y = 0;
	TempChar[0] = "�]�ƈ��ٗp";
	TempChar[1] = "�]�ƈ�����";
	TempChar[2] = "�f�՘H�ݒ�";

	for (int i = 0; i <= 2; i++) {

		BtnX[i] = 1000;
		BtnY[i] = 200 + y * 42;
		BtnW[i] = 180;
		BtnH[i] = 42;
		MultiResoBtn(i);

		y++;

		if (Btn != i)
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);

		BtnOn[i] = TRUE;
	}
}

void SYSTEM::ManageEmpSysO() {

	TCHAR Temp[64];

	sprintf_s(Temp, 64, "���Z�b�g�ٗp���܂����H(1�Z�b�g5�l 0�`%d", 10 - Comp[her.On].OEmpSet);
	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64), Temp, GetColor(255, 255, 255), init.FontHandle);

	TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 96), 10 - Comp[her.On].OEmpSet, 0, FALSE);

	if (Comp[her.On].OEmpSet + TempNumber > 10) {
		ResetCity();
		MessageWindowMessage("����ȂɌق��܂���B");
		WaitClick();
	}
	else if (TempNumber != 0)
	{
		Comp[her.On].OEmployee += TempNumber * 5;
		Comp[her.On].OEmpSet += TempNumber;
		ResetCity();
		MessageWindowMessage("�ٗp���܂����B");
		WaitClick();
	}
	BtnSwitch = Sw_MANAGEO;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	ManageData(-1);
	OveredBtn = -1;
}

void SYSTEM::ManageEmpEndSysO() {

	TCHAR Temp[64];

	sprintf_s(Temp, 64, "���Z�b�g���ق��܂����H 0�`%d", Comp[her.On].OEmpSet);
	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64), Temp, GetColor(255, 255, 255), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64 + 32), "�ސE���Ƃ��ċ���6���������x�����`��������܂��B", GetColor(255, 255, 255), init.FontHandle);

	TempNumber = KeyInputNumber(MultiResoIntX(MWX + 64 + 32), MultiResoIntY(MWY + 64 + 64), Comp[her.On].OEmpSet, 0, FALSE);

	if (TempNumber > Comp[her.On].OEmpSet) {
		ResetCity();
		MessageWindowMessage("����ȂɌق��Ă܂���B");
		WaitClick();
	}
	else if (TempNumber != 0)
	{
		Comp[her.On].OEmployee -= TempNumber * 5;
		Comp[her.On].OEmpSet -= TempNumber;
		her.Money -= Comp[her.On].OSalary * 6;
		ResetCity();
		MessageWindowMessage("���ق��܂����B");
		WaitClick();
	}
	BtnSwitch = Sw_MANAGEO;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	ManageData(-1);
	OveredBtn = -1;
}

void SYSTEM::ManageBtnSysW(int i) {

	if (i == 63) {
		BtnSwitch = Sw_MANAGE;
		OveredBtn = -1;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		ManageData(-1);
	}
	else if (i == 0) {
		BtnSwitch = Sw_MANAGEWIN;
		ResetCity();
		OveredBtn = -1;
		ManageDataWIn();
	}
	else if (i == 1) {
		BtnSwitch = Sw_MANAGEWOUT;
		ResetCity();
		OveredBtn = -1;
		ManageDataWOut();
	}
}

void SYSTEM::ManageDataW(int Btn) {

	int x = 0;
	int y = 0;

	SetSingleBtn("�߂�");

	TempChar[0] = "����";
	TempChar[1] = "�o��";

	for (int i = 0; i < 2; i++) {
		BtnX[i] = 600;
		BtnY[i] = 200 + i * 84;
		MultiResoBtn(i);
		if (Btn != i)
			DrawStringToHandle(BtnX[i], BtnY[i], TempChar[i], GetColor(0, 0, 0), init.FontHandle);
		y++;

		BtnOn[i] = TRUE;
	}
}

void SYSTEM::ManageDataWInSort(int ID) {

	TCHAR Temp[32];

	for (int i = 0; i < 16; i++) {
		SortX[i] = 560;
		SortY[i] = 240 + i * 42;
	}

	for (int i = 0; i < 63; i++) {
		if (GoodsOn[i] == FALSE) {
			BtnX[ID] = SortX[i];
			BtnY[ID] = SortY[i];
			BtnW[ID] = 150;
			BtnH[ID] = 42;
			BtnOn[ID] = TRUE;
			GoodsOn[i] = TRUE;

			MultiResoBtn(ID);


			sprintf_s(Temp, 32, "%s", AddCommaL(her.CargoPrice[i]));	//���l
			DrawStringToHandle(BtnX[ID] + MultiResoIntX(190), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%s", AddCommaL(her.Cargo[i]));	//�ωא���
			DrawStringToHandle(BtnX[ID] + MultiResoIntX(210 + 150), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
			sprintf_s(Temp, 32, "%s", AddCommaL(her.CargoPrice[i] / her.Cargo[i]));	//������l
			DrawStringToHandle(BtnX[ID] + MultiResoIntX(210 + 150 * 2), BtnY[ID], Temp, GetColor(0, 0, 0), init.FontHandle);
			break;
		}
	}

	TempChar[ID] = Goods[ID].Name;

	if (OveredBtn != ID)
		DrawStringToHandle(BtnX[ID], BtnY[ID], TempChar[ID], GetColor(0, 0, 0), init.FontHandle);
}

void SYSTEM::ManageDataWIn() {

	DrawWindow(520, 140, 5, 16);

	int X = 560;
	int Y = MultiResoIntY(160);

	DrawStringToHandle(MultiResoIntX(X), Y, "���O", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 190), Y, "���l", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 210 + 150), Y, "����", GetColor(0, 0, 0), init.FontHandle);
	DrawStringToHandle(MultiResoIntX(X + 210 + 150 * 2), Y, "������l", GetColor(0, 0, 0), init.FontHandle);

	MessageWindowMessage("�ǂ����ɂ��܂����H");
	SetSingleBtn("�߂�");

	for (int i = 0; i < 8; i++) {
		if (her.HiddenID[i] != -1)
			ManageDataWInSort(her.HiddenID[i]);
	}
}

void SYSTEM::ManageBtnSysWIn(int i) {

	if (i == 63) {
		BtnSwitch = Sw_MANAGEW;
		ResetCity();
		DrawWindow(520, 140, 5, 16);
		OveredBtn = -1;
		ManageDataW(-1);
	}
	else if (BtnOn[i] == TRUE) {
		ResetCity();
		ManageSysWIn(OveredBtn);
	}
}

void SYSTEM::ManageSysWIn(int ID) {

	for (int i = 0; i < 64; i++) {
		if (her.HiddenID[i] == ID) {
			SlotNumber = i;
			break;
		}
	}

	MessageWindowMessage("�������ɂ��܂����H");
	printfDx("SlotNumber=%d\n", SlotNumber);

	TempNumber = KeyInputNumber(MWX + 64 + 32, MWY + 96, her.Cargo[SlotNumber], 0, FALSE);
	TempPrice = Goods[ID].CalcedPrice * TempNumber;

	printfDx("BoughtNumber=%d\n", TempNumber);
	printfDx("BoughtPrice=%d\n", TempPrice);
	printfDx("CargoPrice=%d\n", her.CargoPrice[SlotNumber]);

	if (TempNumber > her.Cargo[SlotNumber]) {
		ResetCity();
		MessageWindowMessage("���L�ʂ𒴂��Ă��܂��B");
		WaitClick();
	}
	else if (TempNumber != 0)
	{
		her.CargoPrice[SlotNumber] -= her.CargoPrice[SlotNumber] / her.Cargo[SlotNumber] * TempNumber;
		her.Cargo[SlotNumber] -= TempNumber;
		her.CargoWeight -= TempNumber;

		Ware[her.On][SlotNumber].HiddenID = ID;
		Ware[her.On][SlotNumber].InNumber += TempNumber;
		Ware[her.On][SlotNumber].InPrice += (int)TempPrice;

		if (her.Cargo[SlotNumber] == 0)
			her.HiddenID[SlotNumber] = -1;

		ResetCity();
		MessageWindowMessage("���ɂ��܂����B");
		WaitClick();

	}
	BtnSwitch = Sw_MANAGEWIN;
	ResetCity();
	DrawWindow(520, 140, 5, 16);
	OveredBtn = -1;
	ManageDataWIn();
}

void SYSTEM::ManageDataWOutSort(int) {

}

void SYSTEM::ManageDataWOut() {


}
void SYSTEM::ManageBtnSysWOut() {


}

void SYSTEM::ManageSysWOut() {


}

void SYSTEM::ManageDataF(int Btn) {


}

void SYSTEM::TalkBtnOver(int i) {

	switch (i) {
	case 62:
		ResetTalk();

		DrawStringToHandle(BtnX[62], BtnY[62], TempChar[62], GetColor(255, 0, 0), init.FontHandle);
		break;
	case 63:
		ResetTalk();

		DrawStringToHandle(BtnX[63], BtnY[63], TempChar[63], GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::TalkBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 62:
		ResetTalk();

		DrawStringToHandle(BtnX[62], BtnY[62], TempChar[62], GetColor(255, 255, 255), init.FontHandle);
		break;
	case 63:
		ResetTalk();

		DrawStringToHandle(BtnX[63], BtnY[63], TempChar[63], GetColor(255, 255, 255), init.FontHandle);
		break;
	}
}

void SYSTEM::TalkBtnSys(int OveredBtn) {

	switch (BtnSwitch) {
	case Sw_TALK:
		Event(EventNumber);
		break;
	case Sw_TALK2:
		EventSwitch = OveredBtn;
		Event(EventNumber);
		break;
	}
}

void SYSTEM::TalkData() {

}

void SYSTEM::ResetTalk() {

	for (int i = 0; i < 64; i++) {
		GoodsOn[i] = FALSE;
		BtnX[i] = -1;
		BtnY[i] = -1;
	}
	ClearDrawScreen();
	DrawExtendGraph(0, 0, init.WinX, init.WinY, init.GraCity, TRUE);
	DrawWindow(160, 120, 1, 8);
	DrawWindow(1480, 120, 2, 12);
	DrawButton(-1);
	DrawMessageWindow();
	CityData();
	Event(EventNumber);
}

void SYSTEM::ExitBtnOver(int i) {

	switch (i) {
	case 62:
		ResetCity();
		DrawStringToHandle(BtnX[62], BtnY[62], "�͂�", GetColor(255, 0, 0), init.FontHandle);
		break;
	case 63:
		ResetCity();
		DrawStringToHandle(BtnX[63], BtnY[63], "������", GetColor(255, 0, 0), init.FontHandle);
		break;
	}
}

void SYSTEM::ExitBtnOut(int OveredBtn) {

	switch (OveredBtn) {
	case 62:
		ResetCity();
		DrawStringToHandle(BtnX[62], BtnY[62], "�͂�", GetColor(255, 255, 255), init.FontHandle);
		break;
	case 63:
		ResetCity();
		DrawStringToHandle(BtnX[63], BtnY[63], "������", GetColor(255, 255, 255), init.FontHandle);
		break;
	}
}

void SYSTEM::ExitBtnSys(int OveredBtn) {

	switch (OveredBtn) {
	case 62:
		fun.FStat = fun.F_MAIN;
		BtnSwitch = Sw_MMAP;
		Fade(init.GraCity, init.GraMap, "Field");
		ResetMap();
		SpawnHer();
		break;
	case 63:
		BtnSwitch = Sw_CITY;
		ResetCity();
		break;
	}
}