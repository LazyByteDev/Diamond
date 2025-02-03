#pragma once
#include <Windows.h>
#include <cstdio>
#include "SDK.hpp"

using namespace SDK;

namespace Utilities {
	void createConsole() {
		FILE* fDummy;
		AllocConsole();
		freopen_s(&fDummy, "CONIN$", "r", stdin);
		freopen_s(&fDummy, "CONOUT$", "w", stdout);
	}

    inline std::wstring ToWide(std::string text)
    {
        return std::wstring(text.begin(), text.end());
    }

    inline FString SoftFString(const class FString& InString)
    {
        auto text = ((UKismetTextLibrary*)UKismetTextLibrary::StaticClass()->DefaultObject)->Conv_StringToText(InString);
        return ((UKismetTextLibrary*)UKismetTextLibrary::StaticClass()->DefaultObject)->Conv_TextToString(text);
    }

    uintptr_t GetOffset(uintptr_t Offset)
    {
        return __int64(GetModuleHandleW(0)) + Offset;
    }

}