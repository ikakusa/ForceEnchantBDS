#include "ItemEnchants.h"

__int64* ItemEnchantsHook::canEnchant::handle(__int64 _this, __int64* result, __int64 en, bool allowNonVanilla) {
	static auto oFunc = funcPtr->GetFastcall<__int64*, __int64, __int64*, __int64, bool>();
	return oFunc(_this, result, en, true);
}