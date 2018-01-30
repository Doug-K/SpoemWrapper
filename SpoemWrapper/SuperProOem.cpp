// SuperProOem.cpp : Implementation of CSuperProOem

#include "stdafx.h"
#include "SuperProOem.h"


// CSuperProOem



STDMETHODIMP CSuperProOem::USBCommunication(VARIANT_BOOL* Result)
{
   
   *Result = spoem.USBCommunication();

   return S_OK;
}


STDMETHODIMP CSuperProOem::SelectDevice(CHAR* Manufacturer, CHAR* Device, VARIANT_BOOL* Result)
{
   
   *Result = spoem.SelectDevice(Manufacturer, Device);

   return S_OK;
}


STDMETHODIMP CSuperProOem::LoadDataFile(LPSPOEMDATAFILEPARA lpDataFilePara, VARIANT_BOOL* Result)
{
   OEMDATAFILEPARA oem_buffer_para;

   oem_buffer_para.bInitBuffer = lpDataFilePara->bInitBuffer;
   oem_buffer_para.bSpecialLoadMode = lpDataFilePara->bSpecialLoadMode;
   oem_buffer_para.chFileMode = lpDataFilePara->chFileMode;
   strcpy_s(oem_buffer_para.chFileName, (const char*)lpDataFilePara->FileName);
   oem_buffer_para.chFillData = lpDataFilePara->chFillData;
   oem_buffer_para.chType = lpDataFilePara->chType;
   oem_buffer_para.nBufferAddress = lpDataFilePara->nBufferAddress;
   oem_buffer_para.nFileAddress = lpDataFilePara->nFileAddress;
   oem_buffer_para.nWhichBufferSelect = lpDataFilePara->nWhichBufferSelect;

   *Result = spoem.LoadDataFile(&oem_buffer_para);

   return S_OK;
}


STDMETHODIMP CSuperProOem::LoadDataDirectly(LPSPOEMLOADDATAPARA lpSpOemLoadDataPara, VARIANT_BOOL* Result)
{
   OEMLOADDATAPARA oem_load_data_para;

   oem_load_data_para.bWritetoBuffer = lpSpOemLoadDataPara->bWritetoBuffer;
   oem_load_data_para.chData = lpSpOemLoadDataPara->chData;
   oem_load_data_para.chDataType = lpSpOemLoadDataPara->chDataType;
   oem_load_data_para.nEndAddress = lpSpOemLoadDataPara->nEndAddress;
   oem_load_data_para.nStartAddress = lpSpOemLoadDataPara->nStartAddress;

   *Result = spoem.LoadDataDirectly(&oem_load_data_para);

   return S_OK;
}


STDMETHODIMP CSuperProOem::SaveDataFile(LPSPOEMSAVEDATAPARA lpSpOemSaveDataPara, VARIANT_BOOL* Result)
{
   OEMSAVEDATAPARA oem_save_data_para;

   strcpy_s(oem_save_data_para.chFileName, (const char*)lpSpOemSaveDataPara->chFileName);
   oem_save_data_para.chType = lpSpOemSaveDataPara->chType;
   oem_save_data_para.nSize = lpSpOemSaveDataPara->nSize;
   oem_save_data_para.nStartAddress = lpSpOemSaveDataPara->nStartAddress;
   oem_save_data_para.nWhichBufferSelect = lpSpOemSaveDataPara->nWhichBufferSelect;

   *Result = spoem.SaveDataFile(&oem_save_data_para);

   return S_OK;
}


STDMETHODIMP CSuperProOem::BeginProgram(CHAR* Auto, VARIANT_BOOL* Result)
{
   
   *Result = spoem.BeginProgram(Auto);
   
   return S_OK;
}


STDMETHODIMP CSuperProOem::GetProgramStatus(LPSPOEMPROGRAMSTATUS lpSpOemProgramStatus)
{
   OEMPROGRAMSTATUS oem_program_status;

   spoem.GetProgramStatus(&oem_program_status);

   lpSpOemProgramStatus->bProgramming = oem_program_status.bProgramming;
   lpSpOemProgramStatus->bResult = oem_program_status.bResult;
   lpSpOemProgramStatus->chFunction = oem_program_status.chFunction;
   lpSpOemProgramStatus->chProcess = oem_program_status.chProcess;

   return S_OK;
}


STDMETHODIMP CSuperProOem::GetCheckSum(VARIANT_BOOL reCalc, ULONG* CheckSum)
{
   
   *CheckSum = spoem.GetCheckSum(reCalc);

   return S_OK;
}


STDMETHODIMP CSuperProOem::CheckPin(VARIANT_BOOL* Result)
{
   
   *Result = spoem.CheckPin();

   return S_OK;
}


STDMETHODIMP CSuperProOem::OemGetError(SPOEMOPERATIONERROR* spOperationError)
{
   OEMOPERATIONERROR oem_operation_error;

   spoem.OemGetError(&oem_operation_error);

   spOperationError->chStep = oem_operation_error.chStep;
   spOperationError->chType = oem_operation_error.chType;

   return S_OK;
}


STDMETHODIMP CSuperProOem::OperationOption(SPOEMOPERATIONOPTION* spOemOperationOption)
{
   OEMOPERATIONOPTION oem_operation_option;

   oem_operation_option.bBeeper = spOemOperationOption->bBeeper;
   oem_operation_option.bIDCheck = spOemOperationOption->bIDCheck;
   oem_operation_option.chEnable = spOemOperationOption->chEnable;

   spoem.OperationOption(&oem_operation_option);

   return S_OK;
}


STDMETHODIMP CSuperProOem::CancelProgram(VARIANT_BOOL* Result)
{
   
   *Result = spoem.CancelProgram();

   return S_OK;
}


STDMETHODIMP CSuperProOem::GetBufferParameter(SPOEMBUFFERPARA* SpOemBufferPara)
{
   OEMBUFFERPARA oem_buffer_data;

   spoem.GetBufferParamter(&oem_buffer_data);

   SpOemBufferPara->bExisting = oem_buffer_data.bExisting;
   memcpy_s(SpOemBufferPara->chName, sizeof(SpOemBufferPara->chName) / sizeof(char), oem_buffer_data.chName, sizeof(oem_buffer_data.chName) / sizeof(char));

   return S_OK;
}


STDMETHODIMP CSuperProOem::LoadProject(CHAR* PrjName, SPOEMPROJECTPARA* SpOemProjectPara, VARIANT_BOOL* Result)
{
   OEMPROJECTPARA oem_project_para;

   memcpy_s(oem_project_para.chAuto, sizeof(oem_project_para.chAuto) / sizeof(char),  SpOemProjectPara->chAuto, sizeof(SpOemProjectPara->chAuto) / sizeof(char));
   memcpy_s(oem_project_para.chDev, sizeof(oem_project_para.chDev) / sizeof(char), SpOemProjectPara->chDev, sizeof(SpOemProjectPara->chDev) / sizeof(char));
   memcpy_s(oem_project_para.chMfg, sizeof(oem_project_para.chMfg) / sizeof(char), SpOemProjectPara->chMfg, sizeof(SpOemProjectPara->chMfg) / sizeof(char) );

   *Result = spoem.LoadProject(PrjName, &oem_project_para);

   return S_OK;
}
