// VRM4U Copyright (c) 2021-2022 Haruyoshi Yamamoto. This software is released under the MIT License.

#include "VrmCameraCheckComponent.h"

#if WITH_EDITOR
#include "Editor.h"
#include "EditorViewportClient.h"
#include "LevelEditorViewport.h"
#endif




UVrmCameraCheckComponent::UVrmCameraCheckComponent(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void UVrmCameraCheckComponent::OnRegister() {
	Super::OnRegister();
}
void UVrmCameraCheckComponent::OnUnregister() {
	Super::OnUnregister();
}

void UVrmCameraCheckComponent::OnCameraTransformChanged(const FVector&, const FRotator&, ELevelViewportType, int32) {
	OnCameraMove.Broadcast();
}

void UVrmCameraCheckComponent::SetCameraCheck(bool bCheckOn) {
#if WITH_EDITOR
	if (bCheckOn) {
		//GEditor->OnEndCameraMovement.Assign(OnCameraMove)
		//if (GEditor->GetActiveViewport()) {
		//	FEditorViewportClient* ViewportClient = StaticCast<FEditorViewportClient*>(GEditor->GetActiveViewport()->GetClient());
		//	if (ViewportClient) {
		//		ViewportClient->SetActorLock(this->GetOwner());
		//	}
		//}
		//GCurrentLevelEditingViewportClient->SetActorLock(this->GetOwner());
		//GEditor->OnEndCameraMovement().AddUObject(this, &UVrmCameraCheckComponent::OnCameraTransformChanged);
		//GEditor->OnBeginCameraMovement().AddUObject(this, &UVrmCameraCheckComponent::OnCameraTransformChanged);
		handle = FEditorDelegates::OnEditorCameraMoved.AddUObject(this, &UVrmCameraCheckComponent::OnCameraTransformChanged);
	} else {
		if (handle.IsValid()) {
			FEditorDelegates::OnEditorCameraMoved.Remove(handle);
		}
		//GEditor->OnEndCameraMovement().Remove
	}
	//FOnEndTransformCamera& () { return OnEndCameraTransformEvent; }
#endif
}

