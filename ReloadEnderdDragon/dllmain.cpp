#include "pch.h"
#include "framework.h"

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" {
    _declspec(dllexport) void onPostInit() {
        std::ios::sync_with_stdio(false);
        //entry();
    }
}

void* endspawn() {
    //error
    return *(void**)dlsym_real("?END_PODIUM_LOCATION@EndPodiumFeature@@2VBlockPos@@B");
    //error
}

Block& Str2Block() {
    return **(Block**)dlsym_real("?mDragonEgg@VanillaBlocks@@3PEBVBlock@@EB");
}

THook(void, "?setDragonKilled@EndDragonFight@@QEAAXAEAVEnderDragon@@@Z", void* a1, void* a2) {
    SymCall("?setBlock@BlockSource@@QEAA_NHHHAEBVBlock@@H@Z", bool, BlockSource*, int, int, int, Block&, int)(*(BlockSource**)a1, 0, 68, 0, Str2Block(), 3);
    return original(a1, a2);
}
