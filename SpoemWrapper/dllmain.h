// dllmain.h : Declaration of module class.

class CSpoemWrapperModule : public ATL::CAtlDllModuleT< CSpoemWrapperModule >
{
public :
	DECLARE_LIBID(LIBID_SpoemWrapperLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SPOEMWRAPPER, "{7BF36E28-A177-4BCD-9134-4ED82DA092B9}")
};

extern class CSpoemWrapperModule _AtlModule;
