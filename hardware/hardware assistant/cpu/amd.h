#pragma once
#include "CPUBase.h"
#include "CPUWMI.h"
#include <bitset>


//L1 Cache and TLB Information CPUID = 0x80000005
//EAX
#define INSTRUCTION_TLB_SIZE				0x000000FF
#define INSTRUCTION_TLB_ASSOC				0x0000FF00
#define DATA_TLB_SIZE						0x00FF0000
#define DATA_TLB_ASSOC						0xFF000000
//EBX
#define KB4_INSTRUCTION_TLB_SIZE			0x000000FF
#define KB4_INSTRUCTION_TLB_ASSOC			0x0000FF00
#define KB4_DATA_TLB_SIZE					0x00FF0000
#define KB4_DATA_TLB_ASSOC					0xFF000000
//ECX
#define L1_DATA_CACHE_SIZE					0xFF000000
#define L1_DATA_CACHE_ASSOC					0x00FF0000
#define L1_DATA_CACHE_LINE_PER_TAG			0x0000FF00
#define L1_DATA_CACHE_LINE_SIZE				0x000000FF
//EDX
#define L1_INSTRUCTION_CACHE_SIZE			0xFF000000
#define L1_INSTRUCTION_CACHE_ASSOC			0x00FF0000
#define L1_INSTRUCTION_CACHE_LINE_PER_TAG	0x0000FF00
#define L1_INSTRUCTION_CACHE_LINE_SIZE		0x000000FF

//L2 Cache and TLB and L3 Cache Information CPUID = 0x80000006
//EAX
#define L2_INSTRUCTION_TLB_ASSOC			0x0000F000
#define L2_INSTRUCTION_TLB_SIZE				0x00000FFF
#define L2_DATA_TLB_SIZE					0x0FFF0000
#define L2_DATA_TLB_ASSOC					0xF0000000
//EBX
#define KB4_L2_INSTRUCTION_TLB_SIZE			0x00000FFF
#define KB4_L2_INSTRUCTION_TLB_ASSOC		0x0000F000
#define KB4_L2_DATA_TLB_SIZE				0x0FFF0000
#define KB4_L2_DATA_TLB_ASSOC				0xF0000000
//ECX
#define L2_DATA_CACHE_SIZE					0xFFFF0000
#define L2_DATA_CACHE_ASSOC					0x0000F000
#define L2_DATA_CACHE_LINE_PER_TAG			0x00000F00
#define L2_DATA_CACHE_LINE_SIZE				0x000000FF
//EDX
#define L3_INSTRUCTION_CACHE_SIZE			0xFFFC0000
#define L3_INSTRUCTION_CACHE_ASSOC			0x0000F000
#define L3_INSTRUCTION_CACHE_LINE_PER_TAG	0x00000F00
#define L3_INSTRUCTION_CACHE_LINE_SIZE		0x000000FF

class AMD : public CPUBASE
{
public:
	AMD();
	~AMD();
protected:
	void Init(void);
	void UpDateData(void);
	void ExecFeature();
	void ExecCache();
private:
	inline __int64 findcpuid(int value);
	std::bitset<32> f1_ecx;
	std::bitset<32> f1_edx;
	std::bitset<32> f7_ebx;
	std::bitset<32> f7_ecx;
	std::bitset<32> f81_ecx;
	std::bitset<32> f81_edx;
};
