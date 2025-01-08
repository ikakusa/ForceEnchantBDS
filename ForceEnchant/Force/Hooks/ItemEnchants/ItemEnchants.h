#pragma once
#include <MemUtils.h>
#include "../Hooks.h"
#include "../../SDK/EnchantResult.h"

namespace ItemEnchantsHook {
	class canEnchant : public Hook {
	private:
		static inline std::unique_ptr<FuncHook> funcPtr;
	public:
		canEnchant() : Hook("ItemEnchants::canEnchant") {};
		static __int64* handle(__int64 _this, __int64* result, __int64 en, bool allowNonVanilla);
		bool Initialize() override {
			uintptr_t address = SigScan("4C 89 44 24 18 53 55 56 57 41 55 41 56 41 57 48 83 EC 40");
			return CreateHook(funcPtr, address, handle);
		}
	};
}