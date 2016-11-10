// Fill out your copyright notice in the Description page of Project Settings.

#include "CodeG29.h"
#include "G29InputComponent.h"

// Sets default values for this component's properties
UG29InputComponent::UG29InputComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}


UG29InputComponent::~UG29InputComponent()
{
	ILogitechG::Get().WheelShutdown();
}

// Called when the game starts
void UG29InputComponent::BeginPlay()
{
	Super::BeginPlay();
	FModuleManager::LoadModuleChecked< IModuleInterface >("LogitechG");
	if (ILogitechG::IsAvailable())
	{
		ILogitechG::Get().WheelInit();
	}
}


// Called every frame
void UG29InputComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//if the return value is false, means that the application has not been initialized yet and there is no hwnd available
	if (ILogitechG::Get().WheelUpdate())
	{
		//// call this every frame in case a wheel gets plugged in.
		/*ILogitechG::Get().WheelGenerateNonLinearValues(0, -40);
		ILogitechG::Get().WheelGenerateNonLinearValues(1, 80);*/

		m_DIJoyState2Device = ILogitechG::Get().WheelGetState(0);

		/*for (size_t i = 0; i < 128; i++)
		{
			if (ILogitechG::Get().WheelButtonTriggered(0, i))
			{
				UE_LOG(LogTemp, Warning, TEXT("Your message"));
			}
		}*/



		/*CurrentLogitState.lX = m_DIJoyState2Device->lX;
		CurrentLogitState.lY = m_DIJoyState2Device->lY;
		CurrentLogitState.lZ = m_DIJoyState2Device->lZ;
		CurrentLogitState.lRx = m_DIJoyState2Device->lRx;
		CurrentLogitState.lRy = m_DIJoyState2Device->lRy;
		CurrentLogitState.lRz = m_DIJoyState2Device->lRz;
		CurrentLogitState.lVX = m_DIJoyState2Device->lVX;
		CurrentLogitState.lVY = m_DIJoyState2Device->lVY;
		CurrentLogitState.lVZ = m_DIJoyState2Device->lVZ;
		CurrentLogitState.lVRx = m_DIJoyState2Device->lVRx;
		CurrentLogitState.lVRy = m_DIJoyState2Device->lVRy;
		CurrentLogitState.lVRz = m_DIJoyState2Device->lVRz;
		CurrentLogitState.lAX = m_DIJoyState2Device->lAX;
		CurrentLogitState.lAY = m_DIJoyState2Device->lAY;
		CurrentLogitState.lAZ = m_DIJoyState2Device->lAZ;
		CurrentLogitState.lARx = m_DIJoyState2Device->lARx;
		CurrentLogitState.lARy = m_DIJoyState2Device->lARy;
		CurrentLogitState.lARz = m_DIJoyState2Device->lARz;
		CurrentLogitState.lFX = m_DIJoyState2Device->lFX;
		CurrentLogitState.lFY = m_DIJoyState2Device->lFY;
		CurrentLogitState.lFZ = m_DIJoyState2Device->lFZ;
		CurrentLogitState.lFRx = m_DIJoyState2Device->lFRx;
		CurrentLogitState.lFRy = m_DIJoyState2Device->lFRy;
		CurrentLogitState.lFRz = m_DIJoyState2Device->lFRz;

		for (size_t i = 0; i < 2; i++)
		{
			CurrentLogitState.rglSlider[i] = m_DIJoyState2Device->rglSlider[i];
			CurrentLogitState.rglVSlider[i] = m_DIJoyState2Device->rglVSlider[i];
			CurrentLogitState.rglASlider[i] = m_DIJoyState2Device->rglASlider[i];
			CurrentLogitState.rglFSlider[i] = m_DIJoyState2Device->rglFSlider[i];
		}

		for (size_t i = 0; i < 4; i++)
		{
			CurrentLogitState.rgdwPOV[i] = m_DIJoyState2Device->rgdwPOV[i];
		}

		for (size_t i = 0; i < 128; i++)
		{
			CurrentLogitState.rgbButtons[i] = m_DIJoyState2Device->rgbButtons[i];
		}*/
	}
}

float UG29InputComponent::GetMAXSTEERING()
{
	return UG29InputComponent::MAXSTEERING;
}


int UG29InputComponent::GetLogitStateValue(ELogitState InputLogit)
{

	if (m_DIJoyState2Device == NULL)
	{
		return 0;
	}


	switch (InputLogit)
	{
	case X_AXIS_POSITION:
		return m_DIJoyState2Device->lX;
	case Y_AXIS_POSITION:
		return m_DIJoyState2Device->lY;
	case Z_AXIS_POSITION:
		return m_DIJoyState2Device->lZ;
	case X_AXIS_ROTATION:
		return m_DIJoyState2Device->lRx;
	case Y_AXIS_ROTATION:
		return m_DIJoyState2Device->lRy;
	case Z_AXIS_ROTATION:
		return m_DIJoyState2Device->lRz;
	case X_AXIS_VELOCITY:
		return m_DIJoyState2Device->lVX;
	case Y_AXIS_VELOCITY:
		return m_DIJoyState2Device->lVY;
	case Z_AXIS_VELOCITY:
		return m_DIJoyState2Device->lVZ;
	case X_AXIS_ANGULAR_VELOCITY:
		return m_DIJoyState2Device->lVRx;
	case Y_AXIS_ANGULAR_VELOCITY:
		return m_DIJoyState2Device->lVRy;
	case Z_AXIS_ANGULAR_VELOCITY:
		return m_DIJoyState2Device->lVRz;
	case X_AXIS_ACCELERATION:
		return m_DIJoyState2Device->lAX;
	case Y_AXIS_ACCELERATION:
		return m_DIJoyState2Device->lAY;
	case Z_AXIS_ACCELERATION:
		return m_DIJoyState2Device->lAZ;
	case X_AXIS_ANGULAR_ACCELERATION:
		return m_DIJoyState2Device->lARx;
	case Y_AXIS_ANGULAR_ACCELERATION:
		return m_DIJoyState2Device->lARy;
	case Z_AXIS_ANGULAR_ACCELERATION:
		return m_DIJoyState2Device->lARz;
	case X_AXIS_FORCE:
		return m_DIJoyState2Device->lFX;
	case Y_AXIS_FORCE:
		return m_DIJoyState2Device->lFY;
	case Z_AXIS_FORCE:
		return m_DIJoyState2Device->lFZ;
	case X_AXIS_TORQUE:
		return m_DIJoyState2Device->lFRx;
	case Y_AXIS_TORQUE:
		return m_DIJoyState2Device->lFRy;
	case Z_AXIS_TORQUE:
		return m_DIJoyState2Device->lFRz;

	}
	return 0;
}



int UG29InputComponent::GetExtraAxesPositions(int index)
{
	if (index < 0 || index >= 2)
	{
		return 0;
	}


	if (m_DIJoyState2Device == NULL)
	{
		return 0;
	}


	return m_DIJoyState2Device->rglSlider[index];
}


int UG29InputComponent::GetPOVDirections(int index)
{
	if (index < 0 || index >= 4)
	{
		return 0;
	}

	if (m_DIJoyState2Device == NULL)
	{
		return 0;
	}

	return m_DIJoyState2Device->rgdwPOV[index];
}


FString UG29InputComponent::GetButtons(int index)
{
	if (m_DIJoyState2Device == NULL)
	{
		return "";
	}


	FString tempChart = "";

	if (index >= 0 && index < 128)
	{
		const TCHAR tempChar = (m_DIJoyState2Device->rgbButtons[index]);
		tempChart.AppendChar(tempChar);
	}

	return tempChart;
}


int UG29InputComponent::GetExtraAxesVelocities(int index)
{
	if (index < 0 || index >= 2)
	{
		return 0;
	}

	if (m_DIJoyState2Device == NULL)
	{
		return 0;
	}

	return m_DIJoyState2Device->rglVSlider[index];
}


int UG29InputComponent::GetExtraAxesAccelerations(int index)
{
	if (index < 0 || index >= 2)
	{
		return 0;
	}

	if (m_DIJoyState2Device == NULL)
	{
		return 0;
	}

	return m_DIJoyState2Device->rglASlider[index];
}


int UG29InputComponent::GetExtraAxesForces(int index)
{
	if (index < 0 || index >= 2)
	{
		return 0;
	}

	if (m_DIJoyState2Device == NULL)
	{
		return 0;
	}

	return m_DIJoyState2Device->rglFSlider[index];
}

bool UG29InputComponent::IsButtonTrigger(int index)
{
	if (ILogitechG::Get().WheelIsConnected(0))
	{
		return ILogitechG::Get().WheelButtonTriggered(0, index);
	}
	return false;
}

bool UG29InputComponent::IsButtonPressed(int index)
{

	if (ILogitechG::Get().WheelIsConnected(0))
	{
		return ILogitechG::Get().WheelButtonIsPressed(0, index);
	}
	return false;
}

bool UG29InputComponent::IsButtonRelease(int index)
{
	if (ILogitechG::Get().WheelIsConnected(0))
	{
		return ILogitechG::Get().WheelButtonReleased(0, index);
	}
	return false;
}


bool UG29InputComponent::OnLogitButtonTrigger(ELogitBUTTOM button)
{
	return IsButtonTrigger(button);
}

bool UG29InputComponent::OnLogitPressed(ELogitBUTTOM button)
{

	return IsButtonPressed(button);
}

bool UG29InputComponent::OnLogitRelease(ELogitBUTTOM button)
{
	return IsButtonRelease(button);
}


///////////////////////////////////////////////////////////
bool UG29InputComponent::WheelGenerateNonLinearValues(const int index, const int nonLinCoeff) {
	return ILogitechG::Get().WheelGenerateNonLinearValues(index, nonLinCoeff);
}
int UG29InputComponent::WheelGetNonLinearValue(const int index, const int inputValue) {
	return  ILogitechG::Get().WheelGetNonLinearValue(index, inputValue);
}
bool UG29InputComponent::WheelHasForceFeedback(const int index) {
	return  ILogitechG::Get().WheelHasForceFeedback(index);
}
bool UG29InputComponent::WheelIsPlaying(const int index, const int forceType) {
	return  ILogitechG::Get().WheelIsPlaying(index, forceType);
}

bool UG29InputComponent::WheelPlaySpringForce(const int index, const int offsetPercentage, const int saturationPercentage, const int coefficientPercentage)
{
	return  ILogitechG::Get().WheelPlaySpringForce(index, offsetPercentage, saturationPercentage, coefficientPercentage);
}

bool UG29InputComponent::WheelStopSpringForce(const int index) {
	return  ILogitechG::Get().WheelStopSpringForce(index);
}
bool UG29InputComponent::WheelPlayConstantForce(const int index, const int magnitudePercentage) {
	return  ILogitechG::Get().WheelPlayConstantForce(index, magnitudePercentage);
}
bool UG29InputComponent::WheelStopConstantForce(const int index) {
	return  ILogitechG::Get().WheelStopConstantForce(index);
}

bool UG29InputComponent::WheelPlayDamperForce(const int index, const int coefficientPercentage) {
	return ILogitechG::Get().WheelPlayDamperForce(index, coefficientPercentage);
}

bool UG29InputComponent::WheelStopDamperForce(const int index) {
	return  ILogitechG::Get().WheelStopDamperForce(index);
}
bool UG29InputComponent::WheelPlaySideCollisionForce(const int index, const int magnitudePercentage) {
	return ILogitechG::Get().WheelPlaySideCollisionForce(index, magnitudePercentage);
}
bool UG29InputComponent::WheelPlayFrontalCollisionForce(const int index, const int magnitudePercentage) {
	return ILogitechG::Get().WheelPlayFrontalCollisionForce(index, magnitudePercentage);
}
bool UG29InputComponent::WheelPlayDirtRoadEffect(const int index, const int magnitudePercentage) {
	return ILogitechG::Get().WheelPlayDirtRoadEffect(index, magnitudePercentage);
}
bool UG29InputComponent::WheelStopDirtRoadEffect(const int index) {
	return ILogitechG::Get().WheelStopDirtRoadEffect(index);
}
bool UG29InputComponent::WheelPlayBumpyRoadEffect(const int index, const int magnitudePercentage) {
	return ILogitechG::Get().WheelPlayBumpyRoadEffect(index, magnitudePercentage);
}
bool UG29InputComponent::WheelStopBumpyRoadEffect(const int index) {
	return ILogitechG::Get().WheelStopBumpyRoadEffect(index);
}
bool UG29InputComponent::WheelPlaySlipperyRoadEffect(const int index, const int magnitudePercentage) {
	return ILogitechG::Get().WheelPlaySlipperyRoadEffect(index, magnitudePercentage);
}
bool UG29InputComponent::WheelStopSlipperyRoadEffect(const int index) {
	return ILogitechG::Get().WheelStopSlipperyRoadEffect(index);
}

bool UG29InputComponent::WheelPlaySurfaceEffect(const int index, const int type, const int magnitudePercentage, const int period)
{
	return ILogitechG::Get().WheelPlaySurfaceEffect( index,  type,  magnitudePercentage,  period);
}
bool UG29InputComponent::WheelStopSurfaceEffect(const int index) {
	return ILogitechG::Get().WheelStopSurfaceEffect(index);
}

bool UG29InputComponent::WheelPlayCarAirborne(const int index) {
	return ILogitechG::Get().WheelPlayCarAirborne(index);
}
bool UG29InputComponent::WheelStopCarAirborne(const int index) {
	return  ILogitechG::Get().WheelStopCarAirborne(index);
}
bool UG29InputComponent::WheelPlaySoftstopForce(const int index, const int usableRangePercentage) {
	return ILogitechG::Get().WheelPlaySoftstopForce(index, usableRangePercentage);
}
bool UG29InputComponent::WheelStopSoftstopForce(const int index) {
	return ILogitechG::Get().WheelStopSoftstopForce(index);
}


bool UG29InputComponent::WheelSetPreferredControllerProperties(const FControllerPropertiesData properties) {
	
	ControllerPropertiesData tempData;
	ZeroMemory(&tempData, sizeof(tempData));

	tempData.forceEnable = properties.forceEnable;;
	tempData.overallGain = properties.overallGain;
	tempData.springGain = properties.springGain;
	tempData.damperGain = properties.damperGain;
	tempData.defaultSpringEnabled = properties.defaultSpringEnabled;
	tempData.defaultSpringGain = properties.defaultSpringGain;
	tempData.combinePedals = properties.combinePedals;
	tempData.wheelRange = properties.wheelRange;
	tempData.gameSettingsEnabled = properties.gameSettingsEnabled;
	tempData.allowGameSettings = properties.allowGameSettings;
	return ILogitechG::Get().WheelSetPreferredControllerProperties(tempData);
}
bool UG29InputComponent::WheelGetCurrentControllerProperties(const int index, FControllerPropertiesData& properties) {

	ControllerPropertiesData  tempData;
	ZeroMemory(&tempData, sizeof(tempData));

	bool tempProperty = ILogitechG::Get().WheelGetCurrentControllerProperties(index, tempData);

	properties.forceEnable = tempData.forceEnable;
	properties.overallGain = tempData.overallGain;
	properties.springGain = tempData.springGain;
	properties.damperGain = tempData.damperGain;
	properties.defaultSpringEnabled = tempData.defaultSpringEnabled;
	properties.defaultSpringGain = tempData.defaultSpringGain;
	properties.combinePedals = tempData.combinePedals;
	properties.wheelRange = tempData.wheelRange;
	properties.gameSettingsEnabled = tempData.gameSettingsEnabled;
	properties.allowGameSettings = tempData.allowGameSettings;

	return tempProperty;
}


int UG29InputComponent::WheelGetShifterMode(const int index) {
	return ILogitechG::Get().WheelGetShifterMode(index);
}


bool UG29InputComponent::WheelSetOperatingRange(const int index, const int range) {
	return ILogitechG::Get().WheelSetOperatingRange(index, range);
}
bool UG29InputComponent::WheelGetOperatingRange(const int index, int& range) {
	return ILogitechG::Get().WheelGetOperatingRange(index, range);
}
bool UG29InputComponent::WheelPlayLeds(const int index, const float currentRPM, const float rpmFirstLedTurnsOn, const float rpmRedLine) {
	return ILogitechG::Get().WheelPlayLeds(index, currentRPM, rpmFirstLedTurnsOn, rpmRedLine);
}