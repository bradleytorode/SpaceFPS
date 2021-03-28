// Fill out your copyright notice in the Description page of Project Settings.


#include "Water.h"

AWater::AWater() {
	smPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WaterPlane"));
	smPlane->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SMPlane(TEXT("StaticMesh'/Game/CalgreghardStuff/Assets/Objects/Water/Water_Plane.Water_Plane'"));
	if (SMPlane.Succeeded()) {
		smPlane->SetStaticMesh(SMPlane.Object);
	}
	

	///*Create material interface*/
	//UMaterialInterface* SKMat = smPlane->GetMaterial(0);
	///*Create dynamic instance*/ 
	//DynMaterial = UMaterialInstanceDynamic::Create(SKMat, this);
	//	
	//smPlane->SetMaterial(0, DynMaterial);

	//DynMaterial->SetVectorParameterValue(TEXT("WaterColour"), WaterProperties.WaterColour);

	/*DynMaterial->SetScalarParameterValue(TEXT("BottomSideOpacity"), WaterProperties.BottomOpacity);
	DynMaterial->SetScalarParameterValue(TEXT("FadeDistance"), WaterProperties.FadeDistance);
	DynMaterial->SetScalarParameterValue(TEXT("Metalic"), WaterProperties.Metalic);
	DynMaterial->SetScalarParameterValue(TEXT("Refraction"), WaterProperties.Refraction);
	DynMaterial->SetScalarParameterValue(TEXT("Roughness"), WaterProperties.Roughness);
	DynMaterial->SetScalarParameterValue(TEXT("Specular"), WaterProperties.Specular);
	DynMaterial->SetScalarParameterValue(TEXT("TopSideOpacity"), WaterProperties.TopOpacity);
	DynMaterial->SetScalarParameterValue(TEXT("WaveContrast"), WaterProperties.WaveContrast);
	DynMaterial->SetScalarParameterValue(TEXT("WaveSize"), WaterProperties.WaveSize);
	DynMaterial->SetScalarParameterValue(TEXT("WaveSpeed"), WaterProperties.WaveSpeed);
	DynMaterial->SetScalarParameterValue(TEXT("WaveStrength"), WaterProperties.WaveStrength);*/
}
