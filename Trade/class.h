#pragma once
#include "DxLib.h"
#include <string>

class INIT {
public:
	int FontHandle;
	int WinX;
	int WinY;
	int GraT;
	int GraBtn, GraBtn2, GraBtn3, GraBtn4;
	int GraMW;
	int GraMap;
	int GraCity;
	int GraHer;
	int GraCalender, GraGold, GraIdea, GraFactory;
	int GraCarriage[12];
	int GraShip[12];
	int SHandle;
	void SetFont();
	void LoadGra();
	void LoadSE();
	void InitMarket();
	void InitBuilding();
	void Cargo();
};

class FUN {
public:
	void main();
	enum {
		F_TITLE,
		F_MAIN,
		F_CITY,
		F_ENDING,
		F_END,
	};

	int FStat = F_TITLE;
};

class SYSTEM {
	int BtnX[64], BtnY[64], BtnW[64], BtnH[64], BtnCx[64], BtnCy[64];
	int TempValueX[64], TempValueY[64];
	int MouseX, MouseY;
	int MInput,MInput1F;
	bool KeyInput, KeyInput1F;
	int OveredBtn = -1;
	int ClickedBtn = -1;
	int ButtonNumber = 64;
	int SortX[16];
	int SortY[16];
	bool GoodsOn[16];
	bool BtnOn[64];
	int CargoNumber;
	int MWX,MWY;

	long long TempPrice;
	int TempNumber;
	int TalkNumber = 0;
	int ETalkCount = 0;

	int SlotNumber;
	int BuildingSlot;
	int CheapestBuildingID;
	int BuildingCount;

	TCHAR CommedValue[64];
	const char* SelectString[8];
	double VolumeMulti;
	double VolumeMultiSE;

	typedef struct Quad {
		int a, b, c, d;
	} QuadS;
	QuadS Quad;

	double Angle, Angle2;
	bool MOver = FALSE;
	bool LEnd = FALSE;
	bool Stopper = TRUE;
	bool DragStopper = FALSE;
	bool PressedBtn = FALSE;

	bool BuyFlag;
	enum {
		Sw_TITLE,
		Sw_NEW,
		Sw_SAVE,
		Sw_LOAD,
		Sw_OPTION,
		Sw_QUIT,
		Sw_MMAP,
		Sw_CARGO,
		Sw_TRANS,
		Sw_FINAN,
		Sw_QUEST,
		Sw_PRICES,
		Sw_PRICES2,
		//��������X
		Sw_CITY,
		Sw_BUY,
		Sw_BUY2,
		Sw_SALE,
		Sw_SALE2,
		Sw_INVEST,
		Sw_INVESTT,
		Sw_INVESTB,
		Sw_INVESTI,
		Sw_INVESTBUYT,
		Sw_INVESTSALET,
		Sw_INVESTBUYB,
		Sw_INVESTSALEB,
		Sw_INVESTRENTB,
		Sw_INVESTENDB,
		Sw_INVESTBUYI,
		Sw_INVESTSALEI,
		Sw_MANAGE,
		Sw_MANAGEO,
		Sw_MANAGEEMPO,
		Sw_MANAGEENDO,
		Sw_MANAGEW,
		Sw_MANAGEWIN,
		Sw_MANAGEWOUT,
		Sw_MANAGEF,
		Sw_TALK,
		Sw_TALK2,
		Sw_EXIT,
	};
	int BtnSwitch = Sw_TITLE;
public:
	//�V�X�e���Z�[�u�f�[�^
	int VolumeBGM;
	int VolumeSE;


	bool DebugMode = TRUE;
	bool EventFlag[128];
	int EventSwitch;
	int EventNumber;
	const char* TempChar[32];
	TCHAR TempT[32];

	//���C���V�X�e��
	void ButtonOver();
	void ButtonSys();
	void DragSys();
	void DaySys();

	void DrawMessageWindow();
	void MessageWindowMessage(const char*);
	void DrawWindow(int, int, int, int);
	void Fade(int, int, const char*);

	void InitSys();
	void ResetButton();
	void ResetBtnOn();

	char* AddComma(int);
	char* AddCommaN(int);
	char* AddCommaL(int);

	void WaitClick();
	void WaitYesNo();

	void SearchEmpty(int);
	void SearchBuildingEmpty(int);
	void SearchCheapestBuilding(int);
	int CalcSellBuilding(int);
	int CountBuilding(int);

	void SetSingleBtn(const char*);
	void SetTwoBtn(const char*, const char*);
	void SetFullBtn();

	void LoopMusic(const char*);
	double GetVolumeMulti(const char*);
	void SetSEVolume();

	void MultiResoBtn(int);
	void MultiResoValue(int);
	int MultiResoIntX(int);
	int MultiResoIntY(int);
	QuadS MultiResoIntQuad(int, int, int, int);

	int GetCheapest();
	//�^�C�g��
	void ResetTitle();
	void DrawButton(int);
	void TitleBtnOver(int);
	void TitleBtnOverOut(int);
	void TitleBtnSys(int);
	void QuitBtnOver(int);
	void QuitBtnOut(int);
	void QuitBtnSys(int);
	void QuitBtnReset();
	//���C���}�b�v
	void ResetMap();
	void InitMap();
	void DrawValue();
	void SetMapBtn();

	void MapBtnOver(int);
	void MapBtnOut(int);
	void MapBtnSys(int);

	void CargoBtnOver(int);
	void CargoBtnOut(int);
	void CargoBtnSys(int);
	void CargoData();

	void TransBtnOver(int);
	void TransBtnOut(int);
	void TransBtnSys(int);
	void TransData();

	void FinanBtnOver(int);
	void FinanBtnOut(int);
	void FinanBtnSys(int);
	void FinanDrawString();

	void QuestBtnOver(int);
	void QuestBtnOut(int);
	void QuestBtnSys(int);

	void QuestData();
	void PricesBtnOver(int);
	void PricesBtnOut(int);
	void PricesBtnSys(int);
	void PricesData();
	void PricesData2(int, int);

	void SaveBtnOver(int);
	void SaveBtnOut(int);
	void SaveBtnSys(int);
	void SaveData();

	void LoadBtnOver(int);
	void LoadBtnOut(int);
	void LoadBtnSys(int);
	void LoadData();

	void OptionBtnOver(int);
	void OptionBtnOut(int);
	void OptionBtnSys(int);
	void OptionData();

	void DrawOptionString();
	void DrawOptionBtn();
	void DebugBox();
	void DebugMap();
	void InitHer();
	void SpawnHer();
	void Move(int);
	void MoveRoute();
	void WarpHer(int);
	//�X
	void CalcSupply(int);
	void CalcDemand(int);
	void CalcMarket();
	void SetHerPrices(int);
	void ResetCity();
	void ResetTalk();

	void CityBtnOver(int);
	void CityBtnOut(int);
	void CityBtnSys(int);
	void CityData();

	void BuyBtnOver(int);
	void BuyBtnOut(int);
	void BuyBtnSys(int);
	void DrawBuyString();
	void BuyData();
	void BuySys(int);
	void BuySort(int);

	void SaleBtnOver(int);
	void SaleBtnOut(int);
	void SaleBtnSys(int);
	void SaleData();
	void SaleSys(int);
	void SaleSort(int);

	void InvestBtnOver(int);
	void InvestBtnOut(int);
	void InvestBtnSys(int);
	void InvestData(int);

	void InvestBtnSysT(int);	//�A��
	void InvestDataT(int);
	void InvestBuySysT(int);
	void InvestSaleSysT(int);

	void InvestBtnSysB(int);	//����
	void InvestDataB(int);
	void InvestBuySysB(int);
	void InvestSaleSysB(int);
	void InvestRentSysB(int);
	void InvestEndSysB(int);

	void InvestBtnSysI(int);	//����
	void InvestDataI(int);
	void InvestBuySysI(int);
	void InvestSaleSysI(int);

	void ManageBtnOver(int);
	void ManageBtnOut(int);
	void ManageBtnSys(int);
	void ManageData(int);

	void ManageBtnSysO(int);
	void ManageDataO(int);
	void ManageEmpSysO();
	void ManageEmpEndSysO();

	void ManageBtnSysW(int);
	void ManageDataW(int);

	void ManageDataWInSort(int);
	void ManageDataWIn();
	void ManageBtnSysWIn(int);
	void ManageSysWIn(int);

	void ManageDataWOutSort(int);
	void ManageDataWOut();
	void ManageBtnSysWOut();
	void ManageSysWOut();

	void ManageBtnSysF(int);
	void ManageDataF(int);

	void TalkBtnOver(int);
	void TalkBtnOut(int);
	void TalkBtnSys(int);
	void TalkData();

	void Event(int);
	void EventFunc(const char*, const char*);
	void EventFunc2(const char*, const char*, const char*);
	void EventMessage(const char*);
	void EventEnd(int);

	void ExitBtnOver(int);
	void ExitBtnOut(int);
	void ExitBtnSys(int);
};

class HEROINE {
public:
	double X, Y;
	int On;
	int Year, Month, Day;
	long long Money;
	int HiddenID[8];	//�X���b�g�ɓ����Ă�f�Օi��ID
	int Cargo[8];
	int CargoPrice[32];
	int CargoWeight;
	int MaxWeight;
	int ShipWeight;
	int ShipMaxWeight;
	int MoveSpeed;
	int ShipMoveSpeed;
	int WTech;
	int WIndustry;
	int Transport[8];	//0�n��0�@1���D10�@2��^�n��30�@3��^���D40�@4�g���b�N70�@5���C�D80�@6��^�g���b�N90�@7��^���C�D100
	bool HaveShip = FALSE;
	bool OnShip = FALSE;
};

class GOODS {
public:
	int ID;
	const char* Name;
	int BasePrice;
	double IndIDemandmpact;
	double TechDemandImpact;
	int BaseProd;
	double IndSupplyImpact;
	double TechSupplyImpact;
	int BaseSize;

	int CalcedPrice;
	int CalcedProd;
	int CalcedSize;

	void InitGoods();
	//ID�@���O�@��{�l�@�H�Ɖe���x�@�Z�p�e���x�@���Y��{�l�@�H�Ɛ��Y�e���x�@�Z�p���Y�e���x
	void SetGoods(int, char*, int, double, double, int, double, double, int);
};

class MARKET {
public:
	double Demand;
	double Supply;
	double BaseDemand;
	double BaseSupply;

	//��{�l�@���v�@�����@�J���x�@�C���t��
	int CalcPrice(int, int);
	int SaleCalcPrice(int, int);

	//�i����{�l�@�i���W���@�l���@�J���x�@�Z�p�@�Z�p���Y�e���x�@�C���t���@�����@���v�@�H�Ɓ@�H�Ɛ��Y�e���x
	int CalcProduction(int, int);
	int CalcMarketSize(int, int);
	void SetMarket(double, double);
};

class CITY {
public:
	int ID;
	const char* Name;
	const char* Type;
	double Population;
	double Develop;
	double Economy;
	double Technology;
	double Industry;
	double Infra;

	void SetCity(int, const char*, const char*, double, double, double, double, double, double);
	void InitCity();
};

class TRANSPORT {
public:
	int ID;
	const char* Name;
	int Capacity;
	int Price;
	bool Sea;

	void SetTrans(int, const char*, int, int, bool);
	void InitTrans();
};

class BUILDING {
public:
	int Number;
	int RentNumber;
	int Price;
	int Maint;
	int Rent;

	void SetBuilding(int, int, int);
	void Reset(int);
};

class COMPANY {
public:
	int OEmployee;
	int OEmpSet;
	int OSalary;
	int FEmployee;
	int FProductID;
	int FRoute;
	int FEquip;
	int WID;
	int WNumber;
};

class TRADEROUTE {
public:
	int Route;
	bool BuySale;
	int GoodsID;
	int BuySaleNumber;
};

class WAREHOUSE {
public:
	int HiddenID;
	int InPrice;
	int InNumber;

};