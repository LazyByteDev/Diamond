// Diamond
#include <Windows.h>
#include "SDK.hpp"
#include "Minhook.h"
#include "Utilities.h"
#include "Game/Hooks.h"
#include "Game/Functions.h"
#include "Game/Global.h"
#include "Game/UI.h"
using namespace SDK;

DWORD WINAPI GameThread(LPVOID) {
    Utilities::createConsole(); // create Console to see output.

    std::cout << "Initalizing Diamond" << std::endl;

    MH_Initialize(); // Minhook shit
    InitGObjects(); // SDK Initalization

    auto ProcessEventAddr = Utilities::GetOffset(Offsets::ProcessEvent);
    auto ServerAssignDisplayNameAddr = Utilities::GetOffset(GameOffsets::ABasePlayerState::ServerAssignDisplayName);
    auto getlocaladdr = Utilities::GetOffset(GameOffsets::UCreateDungeonsSessionCallbackProxy::GetLocalUserName);

    Globals::Unreal::engine = UObject::FindObject<UGameEngine>("GameEngine Transient.GameEngine_0"); // get the Engine

    Globals::Unreal::refreshWorld(); // get world.
    Globals::Unreal::gameMode = (ADungeonsGameMode*)Globals::Unreal::world->AuthorityGameMode;
    Globals::Unreal::gameState = (ADungeonsGameState*)Globals::Unreal::world->GameState;

    MH_CreateHook((void*)ProcessEventAddr, Hooks::Unreal::ProcessEventHook, (void**)&Functions::Unreal::ProcessEvent);
    MH_EnableHook((void*)ProcessEventAddr);

    MH_CreateHook((void*)ServerAssignDisplayNameAddr, Hooks::Unreal::ServerAssignDisplayNameHook, (void**)&Functions::ABasePlayerState::ServerAssignDisplayName);
    MH_EnableHook((void*)ServerAssignDisplayNameAddr);

    MH_CreateHook((void*)getlocaladdr, Hooks::Unreal::GetLocalUserNameHook, (void**)&Functions::UCreateDungeonsSessionCallbackProxy::GetLocalUserName);
    MH_EnableHook((void*)getlocaladdr);

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, GameThread, 0, 0, 0); // Main Thread
        CreateThread(nullptr, 0, ImUI::ImGuiThread, hModule, 0, nullptr); // UI Thread
        break;
    }
    return TRUE;
}

