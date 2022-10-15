// VRM4U Copyright (c) 2021-2022 Haruyoshi Yamamoto. This software is released under the MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Components/PoseableMeshComponent.h"
#include "Misc/CoreDelegates.h"

#if WITH_EDITOR
#include "Editor/UnrealEdTypes.h"
#else

#if PLATFORM_ANDROID || PLATFORM_IOS || PLATFORM_LINUX
enum ELevelViewportType {};
#endif

#endif


#include "VrmCameraCheckComponent.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class VRM4U_API UVrmCameraCheckComponent : public UActorComponent
{
	GENERATED_UCLASS_BODY()
	
public:

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FVrmCameraCheckDelegate);

	UPROPERTY(BlueprintAssignable)
	FVrmCameraCheckDelegate OnCameraMove;

	UFUNCTION(BlueprintCallable, Category = "VRM4U", meta = (DynamicOutputParam = "OutVrmAsset"))
	void SetCameraCheck(bool bCheckOn);

public:
	void OnRegister() override;
	void OnUnregister() override;

private:
	void OnCameraTransformChanged(const FVector&, const FRotator&, enum ELevelViewportType, int32);

	FDelegateHandle handle;
};
