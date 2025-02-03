#pragma once
#include "../SDK.hpp"
#include "../Utilities.h"
#include "Offsets.h"

using namespace SDK;

namespace Functions {
	namespace Unreal {
		void (*ProcessEvent)(UObject*, UFunction*, void*) = decltype(ProcessEvent)(Utilities::GetOffset(Offsets::ProcessEvent));
		inline UObject* (*StaticLoadObject)(SDK::UClass* ObjectClass, SDK::UObject* InOuter, const TCHAR* InName, const TCHAR* Filename, uint32_t LoadFlags, SDK::UPackageMap* Sandbox, bool bAllowObjectReconciliation) = decltype(StaticLoadObject)(Utilities::GetOffset(GameOffsets::Unreal::StaticLoadObject)); // jko
	}

	namespace UCreateDungeonsSessionCallbackProxy {
		FString(*GetLocalUserName)(FString*, const UObject*) = decltype(GetLocalUserName)(Utilities::GetOffset(GameOffsets::UCreateDungeonsSessionCallbackProxy::GetLocalUserName));
	}

	namespace ABasePlayerState {
		void (*ServerAssignDisplayName)(SDK::ABasePlayerState*, const struct FString) = decltype(ServerAssignDisplayName)(Utilities::GetOffset(GameOffsets::ABasePlayerState::ServerAssignDisplayName));
		FString (*GetOnlineName)(SDK::ABasePlayerState*, const FString) = decltype(GetOnlineName)(Utilities::GetOffset(GameOffsets::ABasePlayerState::GetOnlineName));
		void (*SetPlayerDisplayName)(SDK::ABasePlayerState*, const FString) = decltype(SetPlayerDisplayName)(Utilities::GetOffset(GameOffsets::ABasePlayerState::SetPlayerDisplayName));
		float (*GetRespawnSeconds)(SDK::ABasePlayerState*) = decltype(GetRespawnSeconds)(Utilities::GetOffset(GameOffsets::ABasePlayerState::GetRespawnSeconds));
		void (*SetRespawnSeconds)(SDK::ABasePlayerState*, float) = decltype(SetRespawnSeconds)(Utilities::GetOffset(GameOffsets::ABasePlayerState::SetRespawnSeconds));
	}

	namespace ADungeonsGameState {
		__int64 (*GetLives)(SDK::ADungeonsGameState*) = decltype(GetLives)(Utilities::GetOffset(GameOffsets::ADungeonsGameState::GetLives));
		const FMissionProgress* (*GetMissionProgressOnServer)(SDK::ADungeonsGameState*, ELevelNames) = decltype(GetMissionProgressOnServer)(Utilities::GetOffset(GameOffsets::ADungeonsGameState::GetMissionProgressOnServer));
		__int64 (*GetPlayersCount)(SDK::ADungeonsGameState*) = decltype(GetPlayersCount)(Utilities::GetOffset(GameOffsets::ADungeonsGameState::GetPlayerCount));
		int (*GetPlayersMatchingAliveStateCount)(SDK::ADungeonsGameState*, EAliveState aliveState) = decltype(GetPlayersMatchingAliveStateCount)(Utilities::GetOffset(GameOffsets::ADungeonsGameState::GetPlayersMatchingAliveStateCount));
		bool (*GetReviveEnabled)(SDK::ADungeonsGameState*) = decltype(GetReviveEnabled)(Utilities::GetOffset(GameOffsets::ADungeonsGameState::GetReviveEnabled));
		bool (*GetShowLives)(SDK::ADungeonsGameState*) = decltype(GetShowLives)(Utilities::GetOffset(GameOffsets::ADungeonsGameState::GetShowLives));
	}

	namespace UDungeonsGameInstance {
		//const TArray<FInventoryItemData, >* __fastcall UDungeonsGameInstance::GetRewardItems(UDungeonsGameInstance* this) (!! MISSING STRUCT !!)
		// const save::State *__fastcall UDungeonsGameInstance::GetSaveState(UDungeonsGameInstance *this) (!! MISSING SOMETHING !!)
		float (*GetTimeRemainingToNextDeferredWrite)(SDK::UDungeonsGameInstance*) = decltype(GetTimeRemainingToNextDeferredWrite)(Utilities::GetOffset(GameOffsets::UDungeonsGameInstance::GetTimeRemainingToNextDeferredWrite));
		bool (*IsTutorialCompleted)(SDK::UDungeonsGameInstance*) = decltype(IsTutorialCompleted)(Utilities::GetOffset(GameOffsets::UDungeonsGameInstance::isTutorialCompleted));
	}

	namespace ADungeonsGameMode {
		//const TMap<int,DungeonsPlayerStatTracker,FDefaultSetAllocator,TDefaultMapHashableKeyFuncs<int,DungeonsPlayerStatTracker,0> > *__fastcall ADungeonsGameMode::GetPlayerTrackers(ADungeonsGameMode *this) (!! MISSING STRUCTS !!)
		char (*KickPlayer)(SDK::ADungeonsGameMode*, APlayerController*, FText*) = decltype(KickPlayer)(Utilities::GetOffset(GameOffsets::ADungeonsGameMode::KickPlayer));
		void  (*UseDifficulty)(SDK::ADungeonsGameMode*, EGameDifficulty difficulty) = decltype(UseDifficulty)(Utilities::GetOffset(GameOffsets::ADungeonsGameMode::UseDifficulty));
	}

	namespace ADungeonsGameState {
		bool (*IsLobby)(SDK::ADungeonsGameState*) = decltype(IsLobby)(Utilities::GetOffset(GameOffsets::ADungeonsGameState::isLobby));
		void (*SetLives)(SDK::ADungeonsGameState*, int) = decltype(SetLives)(Utilities::GetOffset(GameOffsets::ADungeonsGameState::SetLives));
		void (*SetReviveEnabled)(SDK::ADungeonsGameState*, bool) = decltype(SetReviveEnabled)(Utilities::GetOffset(GameOffsets::ADungeonsGameState::SetReviveEnabled));
		void (*SetShowLives)(SDK::ADungeonsGameState*, bool) = decltype(SetShowLives)(Utilities::GetOffset(GameOffsets::ADungeonsGameState::SetShowLives));
		void (*SubtractLives)(SDK::ADungeonsGameState*, int) = decltype(SubtractLives)(Utilities::GetOffset(GameOffsets::ADungeonsGameState::SubtractLives));
	}

	namespace ADungeonsGameSession {
		bool (*KickPlayer)(SDK::ADungeonsGameSession*, APlayerController*, const FText*) = decltype(KickPlayer)(Utilities::GetOffset(GameOffsets::ADungeonsGameSession::KickPlayer));
	}

	namespace UDungeonsCheatManager {
		void (*ShowDebugInfo)(SDK::UDungeonsCheatManager*, bool ) = decltype(ShowDebugInfo)(Utilities::GetOffset(GameOffsets::UDungeonsCheatManager::ShowDebugInfo));
		void (*Suicide)(SDK::UDungeonsCheatManager*) = decltype(Suicide)(Utilities::GetOffset(GameOffsets::UDungeonsCheatManager::Suicide));
	}

	
}