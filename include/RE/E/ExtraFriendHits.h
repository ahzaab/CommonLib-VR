#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/A/AITimeStamp.h"


namespace RE
{
	class ExtraFriendHits : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraFriendHits;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kFriendHits;


		virtual ~ExtraFriendHits();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kFriendHits; }


		// members
		BSTArray<AITimeStamp> hits;	 // 10
	};
	static_assert(sizeof(ExtraFriendHits) == 0x28);
}
