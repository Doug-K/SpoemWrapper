// SuperProOem.h : Declaration of the CSuperProOem

#pragma once
#include "resource.h"       // main symbols



#include "SpoemWrapper_i.h"
#include "spoem.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CSuperProOem

class ATL_NO_VTABLE CSuperProOem :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSuperProOem, &CLSID_SuperProOem>,
	public IDispatchImpl<ISuperProOem, &IID_ISuperProOem, &LIBID_SpoemWrapperLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSuperProOem()
	{
      spoem.InitParameter("c:\\Sp6100\\bin");
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SUPERPROOEM)


BEGIN_COM_MAP(CSuperProOem)
	COM_INTERFACE_ENTRY(ISuperProOem)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
      spoem.ExitSpDll();
	}

public:

private:
   CSpoem spoem;

public:
   STDMETHOD(USBCommunication)(VARIANT_BOOL* Result);
   STDMETHOD(SelectDevice)(CHAR* Manufacturer, CHAR* Device, VARIANT_BOOL* Result);
   STDMETHOD(LoadDataFile)(LPSPOEMDATAFILEPARA lpDataFilePara, VARIANT_BOOL* Result);
   STDMETHOD(LoadDataDirectly)(LPSPOEMLOADDATAPARA lpSpOemLoadDataPara, VARIANT_BOOL* Result);
   STDMETHOD(SaveDataFile)(LPSPOEMSAVEDATAPARA lpSpOemSaveDataPara, VARIANT_BOOL* Result);
   STDMETHOD(BeginProgram)(CHAR* Auto, VARIANT_BOOL* Result);
   STDMETHOD(GetProgramStatus)(LPSPOEMPROGRAMSTATUS lpSpOemProgramStatus);
   STDMETHOD(GetCheckSum)(VARIANT_BOOL reCalc, ULONG* CheckSum);
   STDMETHOD(CheckPin)(VARIANT_BOOL* Result);
   STDMETHOD(OemGetError)(SPOEMOPERATIONERROR* spOperationError);
   STDMETHOD(OperationOption)(SPOEMOPERATIONOPTION* spOemOperationOption);
   STDMETHOD(CancelProgram)(VARIANT_BOOL* Result);
   STDMETHOD(GetBufferParameter)(SPOEMBUFFERPARA* SpOemBufferPara);
   STDMETHOD(LoadProject)(CHAR* PrjName, SPOEMPROJECTPARA* SpOemProjectPara, VARIANT_BOOL* Result);
};

OBJECT_ENTRY_AUTO(__uuidof(SuperProOem), CSuperProOem)
