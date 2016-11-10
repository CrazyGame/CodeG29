// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "ILogitechG.h"
#include "Components/ActorComponent.h"
#include "G29InputComponent.generated.h"

UENUM()
enum ELogitState
{
	X_AXIS_POSITION = 0,
	Y_AXIS_POSITION = 1,
	Z_AXIS_POSITION = 2,
	X_AXIS_ROTATION = 3,
	Y_AXIS_ROTATION = 4,
	Z_AXIS_ROTATION = 5,
	X_AXIS_VELOCITY = 6,
	Y_AXIS_VELOCITY = 7,
	Z_AXIS_VELOCITY = 8,
	X_AXIS_ANGULAR_VELOCITY = 9,
	Y_AXIS_ANGULAR_VELOCITY = 10,
	Z_AXIS_ANGULAR_VELOCITY = 11,
	X_AXIS_ACCELERATION = 12,
	Y_AXIS_ACCELERATION = 13,
	Z_AXIS_ACCELERATION = 14,
	X_AXIS_ANGULAR_ACCELERATION = 15,
	Y_AXIS_ANGULAR_ACCELERATION = 16,
	Z_AXIS_ANGULAR_ACCELERATION = 17,
	X_AXIS_FORCE = 18,
	Y_AXIS_FORCE = 19,
	Z_AXIS_FORCE = 20,
	X_AXIS_TORQUE = 21,
	Y_AXIS_TORQUE = 22,
	Z_AXIS_TORQUE = 23
};

UENUM()
enum ELogitBUTTOM
{
	XButton = 0,
	SQUARE = 1,
	CIRCLE = 2,
	TRIANGLE = 3
};

USTRUCT()
struct FControllerPropertiesData
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
	bool forceEnable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
	int overallGain;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
	int springGain;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
	int damperGain;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
	bool defaultSpringEnabled;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
	int defaultSpringGain;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
	bool combinePedals;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
	int wheelRange;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
	bool gameSettingsEnabled;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
	bool allowGameSettings;
};


USTRUCT()
struct FLogitState
{
	GENERATED_USTRUCT_BODY()

public:

	int rglSlider[2];           /* extra axes positions     [2]    */
	unsigned int	rgdwPOV[4];             /* POV directions           [4]    */
	unsigned char   rgbButtons[128];        /* 128 buttons    [128]              */
	int	rglVSlider[2];          /* extra axes velocities  [2]      */
	int	rglASlider[2];          /* extra axes accelerations  [2]   */
	int	rglFSlider[2];          /* extra axes forces    [2]        */


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int 				lX;                     /* x-axis position              */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int 				lY;                     /* y-axis position              */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int           lZ;                     /* z-axis position              */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lRx;                    /* x-axis rotation              */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lRy;                    /* y-axis rotation              */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lRz;                    /* z-axis rotation              */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lVX;                    /* x-axis velocity              */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lVY;                    /* y-axis velocity              */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lVZ;                    /* z-axis velocity              */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lVRx;                   /* x-axis angular velocity      */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lVRy;                   /* y-axis angular velocity      */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lVRz;                   /* z-axis angular velocity      */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lAX;                    /* x-axis acceleration          */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lAY;                    /* y-axis acceleration          */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lAZ;                    /* z-axis acceleration          */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lARx;                   /* x-axis angular acceleration  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lARy;                   /* y-axis angular acceleration  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lARz;                   /* z-axis angular acceleration  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lFX;                    /* x-axis force                 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lFY;                    /* y-axis force                 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lFZ;                    /* z-axis force                 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lFRx;                   /* x-axis torque                */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lFRy;                   /* y-axis torque                */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
		int				lFRz;                   /* z-axis torque                */

};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UG29InputComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UG29InputComponent();
	~UG29InputComponent();

	const float MAXSTEERING = 32767;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "G29Input")
	struct FLogitState CurrentLogitState;*/

	DIJOYSTATE *m_DIJoyState2Device;

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		float GetMAXSTEERING();

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		int GetLogitStateValue(ELogitState InputLogit);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		int GetExtraAxesPositions(int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		int GetPOVDirections(int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		FString GetButtons(int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		int GetExtraAxesVelocities(int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		int GetExtraAxesAccelerations(int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		int GetExtraAxesForces(int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool IsButtonTrigger(int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool IsButtonPressed(int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool IsButtonRelease(int index);


	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool OnLogitButtonTrigger(ELogitBUTTOM button);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool OnLogitPressed(ELogitBUTTOM button);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool OnLogitRelease(ELogitBUTTOM button);


	////////////// For the easy use in blueprint ///////////////////////

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelGenerateNonLinearValues(const int index, const int nonLinCoeff);


	UFUNCTION(BlueprintCallable, Category = "G29Input")
		int WheelGetNonLinearValue(const int index, const int inputValue);


	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelHasForceFeedback(const int index);


	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelIsPlaying(const int index, const int forceType);


	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelPlaySpringForce(const int index, const int offsetPercentage, const int saturationPercentage, const int coefficientPercentage);


	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelStopSpringForce(const int index);


	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelPlayConstantForce(const int index, const int magnitudePercentage);


	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelStopConstantForce(const int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelPlayDamperForce(const int index, const int coefficientPercentage);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelStopDamperForce(const int index);
	bool WheelPlaySideCollisionForce(const int index, const int magnitudePercentage);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelPlayFrontalCollisionForce(const int index, const int magnitudePercentage);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelPlayDirtRoadEffect(const int index, const int magnitudePercentage);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelStopDirtRoadEffect(const int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelPlayBumpyRoadEffect(const int index, const int magnitudePercentage);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelStopBumpyRoadEffect(const int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelPlaySlipperyRoadEffect(const int index, const int magnitudePercentage);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelStopSlipperyRoadEffect(const int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelPlaySurfaceEffect(const int index, const int type, const int magnitudePercentage, const int period);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelStopSurfaceEffect(const int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelPlayCarAirborne(const int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelStopCarAirborne(const int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelPlaySoftstopForce(const int index, const int usableRangePercentage);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelStopSoftstopForce(const int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelSetPreferredControllerProperties(const FControllerPropertiesData properties);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelGetCurrentControllerProperties(const int index, FControllerPropertiesData& properties);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		int WheelGetShifterMode(const int index);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelSetOperatingRange(const int index, const int range);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelGetOperatingRange(const int index, int& range);

	UFUNCTION(BlueprintCallable, Category = "G29Input")
		bool WheelPlayLeds(const int index, const float currentRPM, const float rpmFirstLedTurnsOn, const float rpmRedLine);


};

