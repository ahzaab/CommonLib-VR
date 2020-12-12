#pragma once

#include "RE/T/TESModel.h"


namespace RE
{
	class TESModelRDT : public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESModelRDT;


		virtual ~TESModelRDT();	 // 00
	};
	static_assert(sizeof(TESModelRDT) == 0x28);
}
