
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SPOEM_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SPOEM_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
/////for download algo
#if !defined(AFX_TESTDLG_H__70C37AAE_7985_11D8_80A8_0007E9C099CC__INCLUDED_)
#define AFX_TESTDLG_H__70C37AAE_7985_11D8_80A8_0007E9C099CC__INCLUDED_

#ifdef SPOEM_EXPORTS
	#define SPOEM_API __declspec(dllexport)
#else
	#define SPOEM_API __declspec(dllimport)
    #pragma message("automatic link to spoem.lib")   // <== add this line
    #pragma comment(lib, "spoem.lib")                // <== add this line
#endif

typedef struct _OEMDATAFILEPARA{
	char chFileName[256];
	BOOL bSpecialLoadMode;
	unsigned char chType;     //0  binary
					 //1  Intel hex
					 //2  Motorola
					 //3  Tek
					 //4  Extend Tek
					 //5  Holtek .OTP 

					 //0  jed

	__int64 nBufferAddress; //used as BufferStart in SaveFile
	__int64 nFileAddress;   //used as nSize in SaveFile
	char chFileMode;	//0 normal
						//1 Even[1st of 2]
						//2 Odd[2nd of 2]
						//3 1st byte of 4
						//4 2nd byte of 4
						//5 3rd byte of 4
						//6 4th byte of 4
						//7 1st 2_byte of 4
						//8 2nd 2_byte of 4
					    //remain error
	BOOL bInitBuffer;   // 1, fill buffer with initvalue
	unsigned char chFillData;
	int nWhichBufferSelect;
}OEMDATAFILEPARA, *LPOEMDATAFILEPARA;

typedef struct _OEMBUFFERPARA{
	BOOL bExisting;
	char chName[30];
}OEMBUFFERPARA,*LPOEMBUFFERPARA;

typedef struct _OEMPROJECTPARA{
	char chMfg[33];
	char chDev[33];
	char chAuto[17];
}OEMPROJECTPARA,*LPOEMPROJECTPARA;

typedef struct _OEMPROGRAMSTATUS{
	BOOL bProgramming;
	BOOL bResult;
	char chFunction;
	char chProcess;
}OEMPROGRAMSTATUS,*LPOEMPROGRAMSTATUS;

typedef struct _OEMOPERATIONERROR{
	char chStep;
	char chType;

}OEMOPERATIONERROR,*LPOEMOPERATIONERROR;

typedef struct _OEMLOADDATAPARA{
	BOOL bWritetoBuffer;  // if TRUE, Data from chData to Buffer
						  //    FALSE,	Data from Buffer to chData
	__int64 nStartAddress; //used as BufferStart in SaveFile
	__int64 nEndAddress;   //used as nSize in SaveFile
	char chDataType;  //0 Data
					  //5 EncrypTion
					  //6 ConfigWord (128 Bytes)	
	unsigned char* chData;
}OEMLOADDATAPARA,*LPOEMLOADDATAPARA;

typedef struct _OEMSAVEDATAPARA{
	char chFileName[256];
	__int64 nStartAddress;
	__int64 nSize;
	unsigned char chType;     //0  binary
					 //1  Intel hex
					 //2  Motorola
					 //0  jed
	int nWhichBufferSelect;
}OEMSAVEDATAPARA,*LPOEMSAVEDATAPARA;

typedef struct _OEMOPERATIONOPTION{
	char chEnable;  //bit0 = 1, bIDCheck Enable
					//bit1 = 1, bBeeper Enable
	BOOL bIDCheck;
	BOOL bBeeper;
}OEMOPERATIONOPTION,*LPOEMOPERATIONOPTION;

// This class is exported from the spoem.dll
class SPOEM_API CSpoem {
public:
	CSpoem(void);
	// TODO: add your methods here.
	void InitParameter(char* chSPDir);
	void ExitSpDll();

	BOOL USBCommunication();
	BOOL SelectDevice(char* chMFG,char* chDEV);
	
	BOOL LoadDataFile(LPOEMDATAFILEPARA lpDataFilePara);
	BOOL LoadDataDirectly(LPOEMLOADDATAPARA LoadDataPara);

//////////////////////////////////////////////////////////////////
	BOOL SaveDataFile(LPOEMSAVEDATAPARA lpSaveFilePara);

//////////////////////////////////////////////////////////////////
	
	BOOL BeginProgram(char* chAuto);
	void GetProgramStatus(LPOEMPROGRAMSTATUS ProgramStatus);
	unsigned int GetCheckSum(BOOL bRecalc);
	BOOL CheckPin();
	void OemGetError(LPOEMOPERATIONERROR OperationError);
	void OperationOption(LPOEMOPERATIONOPTION OperOption);
	BOOL CancelProgram();

////////////////////////////////////
	void GetBufferParamter(LPOEMBUFFERPARA BufferPara);
	BOOL LoadProject(char* chPrjName,LPOEMPROJECTPARA prjpara);
};

#endif