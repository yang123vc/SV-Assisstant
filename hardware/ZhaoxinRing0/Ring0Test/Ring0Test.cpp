// Ring0Test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "..\Driverdll\Driverdll.h"
#include "..\Driverdll\Function\Intel\IntelMSR.h"

using namespace SV_ASSIST;
using namespace std;

int main()
{
	int te = 0;
	SYSTEM_INFO si;
	GetSystemInfo(&si);
	for (size_t i = 0; i < si.dwNumberOfProcessors / 2; i++)
	{
		CPU::INTELMSR::Intel_Temperature(i, te);
		cout << "Core " << i << " Temperature:" << te << endl;
	}

	DWORD FID = 0, VID = 0;
	CPU::INTELMSR::Intel_FIDVID(0, FID, VID);
	
	ULONG base = 0;
	Ring0::GetSMbusBaseAddr(0x8086, base);

// 	DDR3_INFO data[DIMMSlotNum] = {};
// 	for (int i = 0; i < DIMMSlotNum; i++)
// 		Ring0::ReadSPD(base , DIMMADDR[i], data[i]);

	auto pci = Ring0::GetAllPciInfo();
	for (const auto& item : pci.pciconfig)
	{
		std::string Vendor, Device;
		ULONG  bus,dev, func;
		Ring0::PCIstringToBDF(item.first, bus, dev, func);
		Ring0::GetPCIDeviceName(item.second.VendorID, item.second.DeviceID,Vendor, Device);
		cout << hex << "Bus:" << bus << " Dev:" << dev << " Func:" << func << "	Vendor Info:" << Vendor << "	Device Info:" << Device << endl;
	}

    return 0;
}

