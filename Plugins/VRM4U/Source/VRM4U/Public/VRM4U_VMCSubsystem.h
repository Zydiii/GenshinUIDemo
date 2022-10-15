// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "Misc/EngineVersionComparison.h"
#include "VRM4U_VMCSubsystem.generated.h"


#if	UE_VERSION_OLDER_THAN(4,22,0)

//Couldn't find parent type for 'VRM4U_VMCSubsystem' named 'UEngineSubsystem'
#error "please remove VRM4U_VMCSubsystem.h/cpp  for <=UE4.21"

#endif


USTRUCT()
struct FVrmVMC_Data {
	GENERATED_USTRUCT_BODY()

public:
	int port = 0;

//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = VRM4U)
	UPROPERTY()
	TMap<FString, FTransform> BoneTransform;

//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = VRM4U)
	UPROPERTY()
	TMap<FString, FTransform> RawData;
};

UCLASS()
class VRM4U_API UVRM4U_VMCSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:

//	TMap<FString, FTransform>;

	TArray<FVrmVMC_Data> baseData;

	UFUNCTION(BlueprintCallable, Category = VRM4U)
	void Clear();

	UFUNCTION(BlueprintCallable, Category = VRM4U)
	void GetBoneByIndex(int index, TMap<FString, FTransform>&trans);

	UFUNCTION(BlueprintCallable, Category = VRM4U)
	void GetBoneByPort(int port, TMap<FString, FTransform>& trans);

	UFUNCTION(BlueprintCallable, Category = VRM4U)
	void GetRawdataByIndex(int index, TMap<FString, FTransform>& trans);

	UFUNCTION(BlueprintCallable, Category = VRM4U)
	void GetRawdataByPort(int port, TMap<FString, FTransform>& trans);


	UFUNCTION(BlueprintCallable, Category = VRM4U)
	void SetBoneTransform(int port, const TMap<FString, FTransform>& trans);

	UFUNCTION(BlueprintCallable, Category = VRM4U)
	void SetRawData(int port, const TMap<FString, FTransform>& trans);

};
