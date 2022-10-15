// Fill out your copyright notice in the Description page of Project Settings.


#include "VRM4U_VMCSubsystem.h"


void UVRM4U_VMCSubsystem::Clear() {
	baseData.Empty();
}

void UVRM4U_VMCSubsystem::GetBoneByIndex(int index, TMap<FString, FTransform>& trans) {
	if (baseData.IsValidIndex(index)) {
		trans = baseData[index].BoneTransform;
	}
}

void UVRM4U_VMCSubsystem::GetBoneByPort(int port, TMap<FString, FTransform>& trans) {
	for (auto& a : baseData) {
		if (a.port == port) {
			trans = a.BoneTransform;
			return;
		}
	}
	FVrmVMC_Data a;
	a.port = port;
	baseData.Add(a);
	trans = baseData.Last(0).BoneTransform;
}

void UVRM4U_VMCSubsystem::GetRawdataByIndex(int index, TMap<FString, FTransform>& trans) {
	if (baseData.IsValidIndex(index)) {
		trans = baseData[index].RawData;
	}
}

void UVRM4U_VMCSubsystem::GetRawdataByPort(int port, TMap<FString, FTransform>& trans) {
	for (auto& a : baseData) {
		if (a.port == port) {
			trans = a.RawData;
			return;
		}
	}
	FVrmVMC_Data a;
	a.port = port;
	baseData.Add(a);
	trans = baseData.Last(0).RawData;
}

void UVRM4U_VMCSubsystem::SetBoneTransform(int port, const TMap<FString, FTransform>& trans) {
	for (auto& a : baseData) {
		if (a.port == port) {
			a.BoneTransform = trans;
			return;
		}
	}
	FVrmVMC_Data a;
	a.port = port;
	a.BoneTransform = trans;
	baseData.Add(a);
}

void UVRM4U_VMCSubsystem::SetRawData(int port, const TMap<FString, FTransform>& trans) {
	for (auto& a : baseData) {
		if (a.port == port) {
			a.RawData = trans;
			return;
		}
	}
	FVrmVMC_Data a;
	a.port = port;
	a.RawData = trans;
	baseData.Add(a);
}
