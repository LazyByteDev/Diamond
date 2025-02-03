#pragma once
#include <cstdint>

namespace GameOffsets {
	namespace Unreal {
		uintptr_t StaticLoadObject = 0x17D57B0;
	}
	namespace UCreateDungeonsSessionCallbackProxy {
		uintptr_t GetLocalUserName = 0xE43300; // UCreateDungeonsSessionCallbackProxy::GetLocalUserName(FString *result, const UObject *WorldContextObject)
	}

	namespace ABasePlayerState {
		uintptr_t ServerAssignDisplayName = 0xF689A0; // ABasePlayerState::ServerAssignDisplayName(ABasePlayerState *__hidden this, const struct FString *)
		uintptr_t GetOnlineName = 0xB971C0; // FString *__fastcall ABasePlayerState::GetOnlineName(ABasePlayerState *this, FString *result)
		uintptr_t SetPlayerDisplayName = 0xBB2510; // void __fastcall ABasePlayerState::SetPlayerDisplayName(ABasePlayerState *this, const FString *name)
		uintptr_t GetRespawnSeconds = 0xB97F50; // float __fastcall ABasePlayerState::GetRespawnSeconds(ABasePlayerState *this)
		uintptr_t SetRespawnSeconds = 0xBB2710; // void __fastcall ABasePlayerState::SetRespawnSeconds(ABasePlayerState *this, float seconds)
	}

	namespace ADungeonsGameState {
		uintptr_t GetLives = 0xAE8BF0; // ADungeonsGameState::GetLives(ADungeonsGameState *this)
		uintptr_t GetMissionProgressOnServer = 0xAE8D00; // ADungeonsGameState::GetMissionProgressOnServer(ADungeonsGameState *this, ELevelNames LevelName)
		uintptr_t GetPlayerCount = 0xAE8D50; // __int64 ADungeonsGameState::GetPlayersCount(ADungeonsGameState *this)
		uintptr_t GetPlayersMatchingAliveStateCount = 0xAE8E40; // int ADungeonsGameState::GetPlayersMatchingAliveStateCount(ADungeonsGameState *this, EAliveState aliveState)
		uintptr_t GetReviveEnabled = 0xAE92E0; // _BOOL8 __fastcall ADungeonsGameState::GetReviveEnabled(ADungeonsGameState *this)
		uintptr_t GetShowLives = 0xAE9380; // _BOOL8 __fastcall ADungeonsGameState::GetShowLives(ADungeonsGameState *this)
	}

	namespace UDungeonsGameInstance {
		uintptr_t GetRewardItems = 0xAE92F0; // const TArray<FInventoryItemData,FDefaultAllocator> *__fastcall UDungeonsGameInstance::GetRewardItems(UDungeonsGameInstance *this)
		uintptr_t GetSaveState = 0xAE9300; // const save::State *__fastcall UDungeonsGameInstance::GetSaveState(UDungeonsGameInstance *this)
		uintptr_t GetTimeRemainingToNextDeferredWrite = 0xAE9390; // float __fastcall UDungeonsGameInstance::GetTimeRemainingToNextDeferredWrite(UDungeonsGameInstance *this)
		uintptr_t isTutorialCompleted = 0xAEA890; // bool __fastcall UDungeonsGameInstance::IsTutorialCompleted(UDungeonsGameInstance *this)
	}

	namespace ADungeonsGameMode {
		uintptr_t GetPlayerTrackers = 0xAE8D40; // const TMap<int,DungeonsPlayerStatTracker,FDefaultSetAllocator,TDefaultMapHashableKeyFuncs<int,DungeonsPlayerStatTracker,0> > *__fastcall ADungeonsGameMode::GetPlayerTrackers(ADungeonsGameMode *this)
		uintptr_t KickPlayer = 0xAEA920; // char __fastcall ADungeonsGameMode::KickPlayer(ADungeonsGameMode *this, APlayerController *playerController, FText *KickReason)
		uintptr_t UseDifficulty = 0xAF0470; // void __fastcall ADungeonsGameMode::UseDifficulty(ADungeonsGameMode *this, EGameDifficulty difficulty)
	}

	namespace ADungeonsGameState {
		uintptr_t isLobby = 0xAEA380; // bool __fastcall ADungeonsGameState::IsLobby(ADungeonsGameState *this)
		uintptr_t SetLives = 0xAEEC50; // void __fastcall ADungeonsGameState::SetLives(ADungeonsGameState *this, int newLives)
		uintptr_t SetReviveEnabled = 0xAEEC70; // void __fastcall ADungeonsGameState::SetReviveEnabled(ADungeonsGameState *this, bool Enabled)
		uintptr_t SetShowLives = 0xAEECD0; // void __fastcall ADungeonsGameState::SetShowLives(ADungeonsGameState *this, bool areLivesLimited)
		uintptr_t SubtractLives = 0xAEF680; // void __fastcall ADungeonsGameState::SubtractLives(ADungeonsGameState *this, int livesToSubtract)
	}

	namespace ADungeonsGameSession {
		uintptr_t KickPlayer = 0xAEAC00; // bool __fastcall ADungeonsGameSession::KickPlayer(ADungeonsGameSession *this, APlayerController *KickedPlayer, const FText *KickReason)
	}

	namespace UDungeonsCheatManager {
		uintptr_t ShowDebugInfo = 0xAEECF0; // void __fastcall UDungeonsCheatManager::ShowDebugInfo(UDungeonsCheatManager *this, bool toggleShow)
		uintptr_t Suicide = 0xAEF7B0; // void __fastcall UDungeonsCheatManager::Suicide(UDungeonsCheatManager *this)
	}

}