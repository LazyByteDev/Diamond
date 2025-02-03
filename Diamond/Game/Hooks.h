#pragma once
#include "Functions.h"
#include "Global.h"

namespace Hooks {

	namespace Unreal {
		void ProcessEventHook(UObject* Object, UFunction* Function, void* Params) {

			if (!Object || !Function)
				return Functions::Unreal::ProcessEvent(Object, Function, Params);

			auto ObjName = Object->GetFullName();
			auto FunName = Function->GetFullName();
		
			return Functions::Unreal::ProcessEvent(Object, Function, Params);
		}

		
		FString GetLocalUserNameHook(FString a1, const UObject* b2) {
			return Utilities::SoftFString(Utilities::ToWide(Globals::User::displayName).c_str());
		}

		void ServerAssignDisplayNameHook(ABasePlayerState* a1, const struct FString b2) {
			std::cout << "attempting server display name override" << std::endl;
			auto softFString = Utilities::SoftFString(Utilities::ToWide(Globals::User::displayName).c_str());
			Functions::ABasePlayerState::SetPlayerDisplayName(a1, softFString);

			a1->PlayerName = Utilities::SoftFString(Utilities::ToWide(Globals::User::displayName).c_str()); // should work
			a1->MDisplayName = Utilities::SoftFString(Utilities::ToWide(Globals::User::displayName).c_str());
			a1->OnRep_PlayerName();
			a1->OnRep_DisplayName();
			return;
		}
	}
}