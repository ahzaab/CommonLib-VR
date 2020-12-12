#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/M/MemoryManager.h"


namespace RE
{
	class TESGlobal;
	class TESObjectREFR;


	enum class CONDITIONITEMOBJECT
	{
		kSelf = 0,
		kTarget = 1,
		kRef = 2,
		kCombatTarget = 3,
		kLinkedRef = 4,
		kQuestAlias = 5,
		kPackData = 6,
		kEventData = 7,
		kCommandTarget = 8
	};


	struct FUNCTION_DATA
	{
	public:
		// Betheseda keeps these in a giant lookup table
		// using func_t = bool(TESObjectREFR* a_thisObj, void* a_param1, void* a_param2, double& a_result);
		enum class FunctionID
		{
			kGetWantBlocking = 0,
			kGetDistance = 1,
			kAddItem = 2,
			kSetEssential = 3,
			kRotate = 4,
			kGetLocked = 5,
			kGetPos = 6,
			kSetPos = 7,
			kGetAngle = 8,
			kSetAngle = 9,
			kGetStartingPos = 10,
			kGetStartingAngle = 11,
			kGetSecondsPassed = 12,
			kActivate = 13,
			kGetActorValue = 14,
			kGetAV = kGetActorValue,
			kSetActorValue = 15,
			kSetAV = kSetActorValue,
			kModActorValue = 16,
			kModAV = kModActorValue,
			kSetAtStart = 17,
			kGetCurrentTime = 18,
			kPlayGroup = 19,
			kLoopGroup = 20,
			kSkipAnim = 21,
			kStartCombat = 22,
			kStopCombat = 23,
			kGetScale = 24,
			kIsMoving = 25,
			kIsTurning = 26,
			kGetLineOfSight = 27,
			kGetLOS = kGetLineOfSight,
			kAddSpell = 28,
			kRemoveSpell = 29,
			kCast = 30,
			kGetButtonPressed = 31,
			kGetInSameCell = 32,
			kEnable = 33,
			kDisable = 34,
			kGetDisabled = 35,
			kMenuMode = 36,
			kPlaceAtMe = 37,
			kPlaySound = 38,
			kGetDisease = 39,
			kFailAllObjectives = 40,
			kGetClothingValue = 41,
			kSameFaction = 42,
			kSameRace = 43,
			kSameSex = 44,
			kGetDetected = 45,
			kGetDead = 46,
			kGetItemCount = 47,
			kGetGold = 48,
			kGetSleeping = 49,
			kGetTalkedToPC = 50,
			kSay = 51,
			kSayTo = 52,
			kGetScriptVariable = 53,
			kStartQuest = 54,
			kStopQuest = 55,
			kGetQuestRunning = 56,
			kGetQR = kGetQuestRunning,
			kSetStage = 57,
			kGetStage = 58,
			kGetStageDone = 59,
			kGetFactionRankDifference = 60,
			kGetAlarmed = 61,
			kIsRaining = 62,
			kGetAttacked = 63,
			kGetIsCreature = 64,
			kGetLockLevel = 65,
			kGetShouldAttack = 66,
			kGetInCell = 67,
			kGetIsClass = 68,
			kGetIsRace = 69,
			kGetIsSex = 70,
			kGetInFaction = 71,
			kGetIsID = 72,
			kGetFactionRank = 73,
			kGetGlobalValue = 74,
			kIsSnowing = 75,
			kFastTravel = 76,
			kFT = kFastTravel,
			kGetRandomPercent = 77,
			kRemoveMusic = 78,
			kGetQuestVariable = 79,
			kGetLevel = 80,
			kIsRotating = 81,
			kRemoveItem = 82,
			kGetLeveledEncounterValue = 83,
			kGetDeadCount = 84,
			kAddToMap = 85,
			kShowMap = kAddToMap,
			kStartConversation = 86,
			kDrop = 87,
			kAddTopic = 88,
			kShowMessage = 89,
			kSetAlert = 90,
			kGetIsAlerted = 91,
			kLook = 92,
			kStopLook = 93,
			kEvaluatePackage = 94,
			kEvP = kEvaluatePackage,
			kSendAssaultAlarm = 95,
			kEnablePlayerControls = 96,
			kEPC = kEnablePlayerControls,
			kDisablePlayerControls = 97,
			kDPC = kDisablePlayerControls,
			kGetPlayerControlsDisabled = 98,
			kGPC = kGetPlayerControlsDisabled,
			kGetHeadingAngle = 99,
			kPickIdle = 100,
			kIsWeaponMagicOut = 101,
			kIsTorchOut = 102,
			kIsShieldOut = 103,
			kCreateDetectionEvent = 104,
			kIsActionRef = 105,
			kIsFacingUp = 106,
			kGetKnockedState = 107,
			kGetWeaponAnimType = 108,
			kIsWeaponSkillType = 109,
			kGetCurrentAIPackage = 110,
			kIsWaiting = 111,
			kIsIdlePlaying = 112,
			kCompleteQuest = 113,
			kLock = 114,
			kUnLock = 115,
			kIsIntimidatedByPlayer = 116,
			kIsPlayerInRegion = 117,
			kGetActorAggroRadiusViolated = 118,
			kGetCrimeKnown = 119,
			kSetEnemy = 120,
			kSetAlly = 121,
			kGetCrime = 122,
			kIsGreetingPlayer = 123,
			kStartMisterSandMan = 124,
			kIsGuard = 125,
			kStartCannibal = 126,
			kHasBeenEaten = 127,
			kGetStaminaPercentage = 128,
			kGetStamina = kGetStaminaPercentage,
			kGetPCIsClass = 129,
			kGetPCIsRace = 130,
			kGetPCIsSex = 131,
			kGetPCInFaction = 132,
			kSameFactionAsPC = 133,
			kSameRaceAsPC = 134,
			kSameSexAsPC = 135,
			kGetIsReference = 136,
			kSetFactionRank = 137,
			kModFactionRank = 138,
			kKillActor = 139,
			kkill = kKillActor,
			kResurrectActor = 140,
			kResurrect = kResurrectActor,
			kIsTalking = 141,
			kGetWalkSpeed = 142,
			kGetWalk = kGetWalkSpeed,
			kGetCurrentAIProcedure = 143,
			kGetTrespassWarningLevel = 144,
			kIsTrespassing = 145,
			kIsInMyOwnedCell = 146,
			kGetWindSpeed = 147,
			kGetCurrentWeatherPercent = 148,
			kGetweatherpct = kGetCurrentWeatherPercent,
			kGetIsCurrentWeather = 149,
			kGetweather = kGetIsCurrentWeather,
			kIsContinuingPackagePCNear = 150,
			kSetCrimeFaction = 151,
			kGetIsCrimeFaction = 152,
			kCanHaveFlames = 153,
			kHasFlames = 154,
			kAddFlames = 155,
			kRemoveFlames = 156,
			kGetOpenState = 157,
			kMoveToMarker = 158,
			kMoveTo = kMoveToMarker,
			kGetSitting = 159,
			kGetFurnitureMarkerID = 160,
			kGetIsCurrentPackage = 161,
			kIsCurrentFurnitureRef = 162,
			kIsCurrentFurnitureObj = 163,
			kSetSize = 164,
			kCSize = kSetSize,
			kRemoveMe = 165,
			kDropMe = 166,
			kGetFactionReaction = 167,
			kSetFactionReaction = 168,
			kModFactionReaction = 169,
			kGetDayOfWeek = 170,
			kIgnoreCrime = 171,
			kGetTalkedToPCParam = 172,
			kRemoveAllItems = 173,
			kWakeUpPC = 174,
			kIsPCSleeping = 175,
			kIsPCAMurderer = 176,
			kSetCombatStyle = 177,
			kSetCS = kSetCombatStyle,
			kPlaySound3D = 178,
			kSelectPlayerSpell = 179,
			kSPSpell = kSelectPlayerSpell,
			kHasSameEditorLocAsRef = 180,
			kHasSameEditorLocAsRefAlias = 181,
			kGetEquipped = 182,
			kWait = 183,
			kStopWaiting = 184,
			kIsSwimming = 185,
			kScriptEffectElapsedSeconds = 186,
			kSetCellPublicFlag = 187,
			kSetPublic = kSetCellPublicFlag,
			kGetPCSleepHours = 188,
			kSetPCSleepHours = 189,
			kGetAmountSoldStolen = 190,
			kModAmountSoldStolen = 191,
			kGetIgnoreCrime = 192,
			kGetPCExpelled = 193,
			kSetPCExpelled = 194,
			kGetPCFactionMurder = 195,
			kSetPCFactionMurder = 196,
			kGetPCEnemyofFaction = 197,
			kSetPCEnemyofFaction = 198,
			kGetPCFactionAttack = 199,
			kSetPCFactionAttack = 200,
			kStartScene = 201,
			kStopScene = 202,
			kGetDestroyed = 203,
			kSetDestroyed = 204,
			kGetActionRef = 205,
			kGetAR = kGetActionRef,
			kGetSelf = 206,
			kThis = kGetSelf,
			kGetContainer = 207,
			kGetForceRun = 208,
			kSetForceRun = 209,
			kGetForceSneak = 210,
			kSetForceSneak = 211,
			kAdvancePCSkill = 212,
			kAdvSkill = kAdvancePCSkill,
			kAdvancePCLevel = 213,
			kAdvLevel = kAdvancePCLevel,
			kHasMagicEffect = 214,
			kGetDefaultOpen = 215,
			kSetDefaultOpen = 216,
			kShowClassMenu = 217,
			kShowRaceMenu = 218,
			kSetPlayerRace = kShowRaceMenu,
			kGetAnimAction = 219,
			kShowNameMenu = 220,
			kSetOpenState = 221,
			kResetReference = 222,
			kRecycleActor = kResetReference,
			kIsSpellTarget = 223,
			kGetVATSMode = 224,
			kGetPersuasionNumber = 225,
			kGetVampireFeed = 226,
			kGetCannibal = 227,
			kGetIsClassDefault = 228,
			kGetClassDefaultMatch = 229,
			kGetInCellParam = 230,
			kUnusedFunction1 = 231,
			kGetCombatTarget = 232,
			kGetPackageTarget = 233,
			kShowSpellMaking = 234,
			kGetVatsTargetHeight = 235,
			kSetGhost = 236,
			kGetIsGhost = 237,
			kEquipItem = 238,
			kEquipObject = kEquipItem,
			kUnequipItem = 239,
			kUnEquipObject = kUnequipItem,
			kSetClass = 240,
			kSetUnconscious = 241,
			kGetUnconscious = 242,
			kSetRestrained = 243,
			kGetRestrained = 244,
			kForceFlee = 245,
			kFlee = kForceFlee,
			kGetIsUsedItem = 246,
			kGetIsUsedItemType = 247,
			kIsScenePlaying = 248,
			kIsInDialogueWithPlayer = 249,
			kGetLocationCleared = 250,
			kSetLocationCleared = 251,
			kForceRefIntoAlias = 252,
			kEmptyRefAlias = 253,
			kGetIsPlayableRace = 254,
			kGetOffersServicesNow = 255,
			kGetGameSetting = 256,
			kGetGS = kGetGameSetting,
			kStopCombatAlarmOnActor = 257,
			kSCAOnActor = kStopCombatAlarmOnActor,
			kHasAssociationType = 258,
			kHasFamilyRelationship = 259,
			kFamily = kHasFamilyRelationship,
			kSetWeather = 260,
			kSW = kSetWeather,
			kHasParentRelationship = 261,
			kIsParent = kHasParentRelationship,
			kIsWarningAbout = 262,
			kIsWeaponOut = 263,
			kHasSpell = 264,
			kIsTimePassing = 265,
			kIsPleasant = 266,
			kIsCloudy = 267,
			kTrapUpdate = 268,
			kShowQuestObjectives = 269,
			kSQO = kShowQuestObjectives,
			kForceActorValue = 270,
			kForceAV = kForceActorValue,
			kIncrementPCSkill = 271,
			kIncPCS = kIncrementPCSkill,
			kDoTrap = 272,
			kEnableFastTravel = 273,
			kEnableFast = kEnableFastTravel,
			kIsSmallBump = 274,
			kGetParentRef = 275,
			kPlayBink = 276,
			kGetBaseActorValue = 277,
			kGetBaseAV = kGetBaseActorValue,
			kIsOwner = 278,
			kSetOwnership = 279,
			kIsCellOwner = 280,
			kSetCellOwnership = 281,
			kIsHorseStolen = 282,
			kSetCellFullName = 283,
			kSetActorFullName = 284,
			kIsLeftUp = 285,
			kIsSneaking = 286,
			kIsRunning = 287,
			kGetFriendHit = 288,
			kIsInCombat = 289,
			kSetPackDuration = 290,
			kSPDur = kSetPackDuration,
			kPlayMagicShaderVisuals = 291,
			kPMS = kPlayMagicShaderVisuals,
			kPlayMagicEffectVisuals = 292,
			kPME = kPlayMagicEffectVisuals,
			kStopMagicShaderVisuals = 293,
			kSMS = kStopMagicShaderVisuals,
			kStopMagicEffectVisuals = 294,
			kSME = kStopMagicEffectVisuals,
			kResetInterior = 295,
			kIsAnimPlaying = 296,
			kSetActorAlpha = 297,
			kSAA = kSetActorAlpha,
			kEnableLinkedPathPoints = 298,
			kDisableLinkedPathPoints = 299,
			kIsInInterior = 300,
			kForceWeather = 301,
			kFW = kForceWeather,
			kToggleActorsAI = 302,
			kIsActorsAIOff = 303,
			kIsWaterObject = 304,
			kGetPlayerAction = 305,
			kIsActorUsingATorch = 306,
			kSetLevel = 307,
			kResetFallDamageTimer = 308,
			kIsXBox = 309,
			kGetInWorldspace = 310,
			kModPCMiscStat = 311,
			kModPCMS = kModPCMiscStat,
			kGetPCMiscStat = 312,
			kGetPCMS = kGetPCMiscStat,
			kGetPairedAnimation = 313,
			kGPA = kGetPairedAnimation,
			kIsActorAVictim = 314,
			kGetTotalPersuasionNumber = 315,
			kSetScale = 316,
			kModScale = 317,
			kGetIdleDoneOnce = 318,
			kKillAllActors = 319,
			kkillall = kKillAllActors,
			kGetNoRumors = 320,
			kSetNoRumors = 321,
			kDispel = 322,
			kGetCombatState = 323,
			kTriggerHitShader = 324,
			kTHS = kTriggerHitShader,
			kGetWithinPackageLocation = 325,
			kReset3DState = 326,
			kIsRidingMount = 327,
			kDispelAllSpells = 328,
			kIsFleeing = 329,
			kAddAchievement = 330,
			kDuplicateAllItems = 331,
			kIsInDangerousWater = 332,
			kEssentialDeathReload = 333,
			kSetShowQuestItems = 334,
			kDuplicateNPCStats = 335,
			kResetHealth = 336,
			kSetIgnoreFriendlyHits = 337,
			kSIFH = kSetIgnoreFriendlyHits,
			kGetIgnoreFriendlyHits = 338,
			kGIFH = kGetIgnoreFriendlyHits,
			kIsPlayersLastRiddenMount = 339,
			kSetActorRefraction = 340,
			kSAR = kSetActorRefraction,
			kSetItemValue = 341,
			kSetRigidBodyMass = 342,
			kShowViewerStrings = 343,
			kSVS = kShowViewerStrings,
			kReleaseWeatherOverride = 344,
			kRWO = kReleaseWeatherOverride,
			kSetAllReachable = 345,
			kSetAllVisible = 346,
			kSetNoAvoidance = 347,
			kSendTrespassAlarm = 348,
			kSetSceneIsComplex = 349,
			kAutosave = 350,
			kStartMasterFileSeekData = 351,
			kDumpMasterFileSeekData = 352,
			kIsActor = 353,
			kIsEssential = 354,
			kPreloadMagicEffect = 355,
			kShowDialogSubtitles = 356,
			kSetPlayerResistingArrest = 357,
			kIsPlayerMovingIntoNewSpace = 358,
			kGetInCurrentLoc = 359,
			kGetInCurrentLocAlias = 360,
			kGetTimeDead = 361,
			kHasLinkedRef = 362,
			kGetLinkedRef = 363,
			kDamageObject = 364,
			kDO = kDamageObject,
			kIsChild = 365,
			kGetStolenItemValueNoCrime = 366,
			kGetLastPlayerAction = 367,
			kIsPlayerActionActive = 368,
			kSetTalkingActivatorActor = 369,
			kIsTalkingActivatorActor = 370,
			kShowBarterMenu = 371,
			kSBM = kShowBarterMenu,
			kIsInList = 372,
			kGetStolenItemValue = 373,
			kAddPerk = 374,
			kGetCrimeGoldViolent = 375,
			kGetviolent = kGetCrimeGoldViolent,
			kGetCrimeGoldNonviolent = 376,
			kGetnonviolent = kGetCrimeGoldNonviolent,
			kShowRepairMenu = 377,
			kSRM = kShowRepairMenu,
			kHasShout = 378,
			kAddNote = 379,
			kAN = kAddNote,
			kRemoveNote = 380,
			kRN = kRemoveNote,
			kGetHasNote = 381,
			kGetN = kGetHasNote,
			kAddToFaction = 382,
			kAddFac = kAddToFaction,
			kRemoveFromFaction = 383,
			kRemoveFac = kRemoveFromFaction,
			kDamageActorValue = 384,
			kDamageAV = kDamageActorValue,
			kRestoreActorValue = 385,
			kRestoreAV = kRestoreActorValue,
			kTriggerHUDShudder = 386,
			kHudSH = kTriggerHUDShudder,
			kGetObjectiveFailed = 387,
			kSetObjectiveFailed = 388,
			kSetGlobalTimeMultiplier = 389,
			kSGTM = kSetGlobalTimeMultiplier,
			kGetHitLocation = 390,
			kIsPC1stPerson = 391,
			kPC1st = kIsPC1stPerson,
			kPurgeCellBuffers = 392,
			kPCB = kPurgeCellBuffers,
			kPushActorAway = 393,
			kSetActorsAI = 394,
			kClearOwnership = 395,
			kGetCauseofDeath = 396,
			kIsLimbGone = 397,
			kIsWeaponInList = 398,
			kPlayIdle = 399,
			kApplyImageSpaceModifier = 400,
			kIMod = kApplyImageSpaceModifier,
			kRemoveImageSpaceModifier = 401,
			kRIMod = kRemoveImageSpaceModifier,
			kIsBribedbyPlayer = 402,
			kGetRelationshipRank = 403,
			kSetRelationshipRank = 404,
			kSetCellImageSpace = 405,
			kShowChargenMenu = 406,
			kSCGM = kShowChargenMenu,
			kGetVATSValue = 407,
			kIsKiller = 408,
			kIsKillerObject = 409,
			kGetFactionCombatReaction = 410,
			kUseWeapon = 411,
			kEvaluateSpellConditions = 412,
			kESC = kEvaluateSpellConditions,
			kToggleMotionBlur = 413,
			kTMB = kToggleMotionBlur,
			kExists = 414,
			kGetGroupMemberCount = 415,
			kGetGroupTargetCount = 416,
			kSetObjectiveCompleted = 417,
			kSetObjectiveDisplayed = 418,
			kGetObjectiveCompleted = 419,
			kGetObjectiveDisplayed = 420,
			kSetImageSpace = 421,
			kPipboyRadio = 422,
			kPRad = kPipboyRadio,
			kRemovePerk = 423,
			kDisableAllActors = 424,
			kDisAA = kDisableAllActors,
			kGetIsFormType = 425,
			kGetIsVoiceType = 426,
			kGetPlantedExplosive = 427,
			kCompleteAllObjectives = 428,
			kIsScenePackageRunning = 429,
			kGetHealthPercentage = 430,
			kSetAudioMultithreading = 431,
			kSAM = kSetAudioMultithreading,
			kGetIsObjectType = 432,
			kShowChargenMenuParams = 433,
			kSCGMP = kShowChargenMenuParams,
			kGetDialogueEmotion = 434,
			kGetDialogueEmotionValue = 435,
			kExitGame = 436,
			kExit = kExitGame,
			kGetIsCreatureType = 437,
			kPlayerCreatePotion = 438,
			kPlayerEnchantObject = 439,
			kShowWarning = 440,
			kEnterTrigger = 441,
			kMarkForDelete = 442,
			kSetPlayerAIDriven = 443,
			kGetInCurrentLocFormList = 444,
			kGetInZone = 445,
			kGetVelocity = 446,
			kGetGraphVariableFloat = 447,
			kHasPerk = 448,
			kGetFactionRelation = 449,
			kIsLastIdlePlayed = 450,
			kSetNPCRadio = 451,
			kSNR = kSetNPCRadio,
			kSetPlayerTeammate = 452,
			kGetPlayerTeammate = 453,
			kGetPlayerTeammateCount = 454,
			kOpenActorContainer = 455,
			kClearFactionPlayerEnemyFlag = 456,
			kClearActorsFactionsPlayerEnemyFlag = 457,
			kGetActorCrimePlayerEnemy = 458,
			kGetCrimeGold = 459,
			kSetCrimeGold = 460,
			kModCrimeGold = 461,
			kGetPlayerGrabbedRef = 462,
			kIsPlayerGrabbedRef = 463,
			kPlaceLeveledActorAtMe = 464,
			kGetKeywordItemCount = 465,
			kShowLockpickMenu = 466,
			kSLPM = kShowLockpickMenu,
			kGetBroadcastState = 467,
			kSetBroadcastState = 468,
			kStartRadioConversation = 469,
			kGetDestructionStage = 470,
			kClearDestruction = 471,
			kCastImmediateOnSelf = 472,
			kCIOS = kCastImmediateOnSelf,
			kGetIsAlignment = 473,
			kResetQuest = 474,
			kSetQuestDelay = 475,
			kIsProtected = 476,
			kGetThreatRatio = 477,
			kMatchFaceGeometry = 478,
			kGetIsUsedItemEquipType = 479,
			kGetPlayerName = 480,
			kFireWeapon = 481,
			kPayCrimeGold = 482,
			kUnusedFunction2 = 483,
			kMatchRace = 484,
			kSetPCYoung = 485,
			kSexChange = 486,
			kIsCarryable = 487,
			kGetConcussed = 488,
			kSetZoneRespawns = 489,
			kSetVATSTarget = 490,
			kGetMapMarkerVisible = 491,
			kResetInventory = 492,
			kPlayerKnows = 493,
			kGetPermanentActorValue = 494,
			kGetPermAV = kGetPermanentActorValue,
			kGetKillingBlowLimb = 495,
			kGoToJail = 496,
			kCanPayCrimeGold = 497,
			kServeTime = 498,
			kGetDaysInJail = 499,
			kEPAlchemyGetMakingPoison = 500,
			kEPAlchemyEffectHasKeyword = 501,
			kShowAllMapMarkers = 502,
			kTMM = kShowAllMapMarkers,
			kGetAllowWorldInteractions = 503,
			kResetAI = 504,
			kSetRumble = 505,
			kSetNoActivationSound = 506,
			kClearNoActivationSound = 507,
			kGetLastHitCritical = 508,
			kAddMusic = 509,
			kUnusedFunction3 = 510,
			kUnusedFunction4 = 511,
			kSetPCToddler = 512,
			kIsCombatTarget = 513,
			kTriggerScreenBlood = 514,
			kTSB = kTriggerScreenBlood,
			kGetVATSRightAreaFree = 515,
			kGetVATSLeftAreaFree = 516,
			kGetVATSBackAreaFree = 517,
			kGetVATSFrontAreaFree = 518,
			kGetIsLockBroken = 519,
			kIsPS3 = 520,
			kIsWin32 = 521,
			kGetVATSRightTargetVisible = 522,
			kGetVATSLeftTargetVisible = 523,
			kGetVATSBackTargetVisible = 524,
			kGetVATSFrontTargetVisible = 525,
			kAttachAshPile = 526,
			kSetCriticalStage = 527,
			kIsInCriticalStage = 528,
			kRemoveFromAllFactions = 529,
			kGetXPForNextLevel = 530,
			kShowLockpickMenuDebug = 531,
			kSLPMD = kShowLockpickMenuDebug,
			kForceSave = 532,
			kGetInfamy = 533,
			kGetInfamyViolent = 534,
			kGetInfamyNonViolent = 535,
			kUnusedFunction5 = 536,
			kSin = 537,
			kCos = 538,
			kTan = 539,
			kSqrt = 540,
			kLog = 541,
			kAbs = 542,
			kGetQuestCompleted = 543,
			kGetQC = kGetQuestCompleted,
			kUnusedFunction6 = 544,
			kPipBoyRadioOff = 545,
			kAutoDisplayObjectives = 546,
			kIsGoreDisabled = 547,
			kFadeSFX = 548,
			kFSFX = kFadeSFX,
			kSetMinimalUse = 549,
			kIsSceneActionComplete = 550,
			kShowQuestStages = 551,
			kSQS = kShowQuestStages,
			kGetSpellUsageNum = 552,
			kForceRadioStationUpdate = 553,
			kFRSU = kForceRadioStationUpdate,
			kGetActorsInHigh = 554,
			kHasLoaded3D = 555,
			kDisableAllMines = 556,
			kSetLastExtDoorActivated = 557,
			kKillQuestUpdates = 558,
			kKQU = kKillQuestUpdates,
			kIsImageSpaceActive = 559,
			kHasKeyword = 560,
			kHasRefType = 561,
			kLocationHasKeyword = 562,
			kLocationHasRefType = 563,
			kCreateEvent = 564,
			kGetIsEditorLocation = 565,
			kGetIsAliasRef = 566,
			kGetIsEditorLocAlias = 567,
			kIsSprinting = 568,
			kIsBlocking = 569,
			kHasEquippedSpell = 570,
			kGetCurrentCastingType = 571,
			kGetCasting = kGetCurrentCastingType,
			kGetCurrentDeliveryType = 572,
			kGetDelivery = kGetCurrentDeliveryType,
			kEquipSpell = 573,
			kGetAttackState = 574,
			kGetAliasedRef = 575,
			kGetEventData = 576,
			kIsCloserToAThanB = 577,
			kEquipShout = 578,
			kGetEquippedShout = 579,
			kIsBleedingOut = 580,
			kUnlockWord = 581,
			kTeachWord = 582,
			kAddToContainer = 583,
			kGetRelativeAngle = 584,
			kSendAnimEvent = 585,
			kSAE = kSendAnimEvent,
			kShout = 586,
			kAddShout = 587,
			kRemoveShout = 588,
			kGetMovementDirection = 589,
			kIsInScene = 590,
			kGetRefTypeDeadCount = 591,
			kGetRefTypeAliveCount = 592,
			kApplyHavokImpulse = 593,
			kGetIsFlying = 594,
			kIsCurrentSpell = 595,
			kSpellHasKeyword = 596,
			kGetEquippedItemType = 597,
			kGetLocationAliasCleared = 598,
			kSetLocationAliasCleared = 599,
			kGetLocAliasRefTypeDeadCount = 600,
			kGetLocAliasRefTypeAliveCount = 601,
			kIsWardState = 602,
			kIsInSameCurrentLocAsRef = 603,
			kIsInSameCurrentLocAsRefAlias = 604,
			kLocAliasIsLocation = 605,
			kGetKeywordDataForLocation = 606,
			kSetKeywordDataForLocation = 607,
			kGetKeywordDataForAlias = 608,
			kSetKeywordDataForAlias = 609,
			kLocAliasHasKeyword = 610,
			kIsNullPackageData = 611,
			kGetNumericPackageData = 612,
			kIsFurnitureAnimType = 613,
			kIsFurnitureEntryType = 614,
			kGetHighestRelationshipRank = 615,
			kGetLowestRelationshipRank = 616,
			kHasAssociationTypeAny = 617,
			kHasFamilyRelationshipAny = 618,
			kGetPathingTargetOffset = 619,
			kGetPathingTargetAngleOffset = 620,
			kGetPathingTargetSpeed = 621,
			kGetPathingTargetSpeedAngle = 622,
			kGetMovementSpeed = 623,
			kGetInContainer = 624,
			kIsLocationLoaded = 625,
			kIsLocAliasLoaded = 626,
			kIsDualCasting = 627,
			kDualCast = 628,
			kGetVMQuestVariable = 629,
			kGetVMScriptVariable = 630,
			kIsEnteringInteractionQuick = 631,
			kIsCasting = 632,
			kGetFlyingState = 633,
			kSetFavorState = 634,
			kIsInFavorState = 635,
			kHasTwoHandedWeaponEquipped = 636,
			kIsExitingInstant = 637,
			kIsInFriendStateWithPlayer = 638,
			kGetWithinDistance = 639,
			kGetActorValuePercent = 640,
			kIsUnique = 641,
			kGetLastBumpDirection = 642,
			kCameraShake = 643,
			kIsInFurnitureState = 644,
			kGetIsInjured = 645,
			kGetIsCrashLandRequest = 646,
			kGetIsHastyLandRequest = 647,
			kUpdateQuestInstanceGlobal = 648,
			kSetAllowFlying = 649,
			kIsLinkedTo = 650,
			kGetKeywordDataForCurrentLocation = 651,
			kGetInSharedCrimeFaction = 652,
			kGetBribeAmount = 653,
			kGetBribeSuccess = 654,
			kGetIntimidateSuccess = 655,
			kGetArrestedState = 656,
			kGetArrestingActor = 657,
			kClearArrestState = 658,
			kEPTemperingItemIsEnchanted = 659,
			kEPTemperingItemHasKeyword = 660,
			kGetReceivedGiftValue = 661,
			kGetGiftGivenValue = 662,
			kForceLocIntoAlias = 663,
			kGetReplacedItemType = 664,
			kSetHorseActor = 665,
			kPlayReferenceEffect = 666,
			kPRE = kPlayReferenceEffect,
			kStopReferenceEffect = 667,
			kSRE = kStopReferenceEffect,
			kPlayShaderParticleGeometry = 668,
			kPSPG = kPlayShaderParticleGeometry,
			kStopShaderParticleGeometry = 669,
			kSSPG = kStopShaderParticleGeometry,
			kApplyImageSpaceModifierCrossFade = 670,
			kIModCF = kApplyImageSpaceModifierCrossFade,
			kRemoveImageSpaceModifierCrossFade = 671,
			kRIModCF = kRemoveImageSpaceModifierCrossFade,
			kIsAttacking = 672,
			kIsPowerAttacking = 673,
			kIsLastHostileActor = 674,
			kGetGraphVariableInt = 675,
			kGetCurrentShoutVariation = 676,
			kPlayImpactEffect = 677,
			kPIE = kPlayImpactEffect,
			kShouldAttackKill = 678,
			kSendStealAlarm = 679,
			kSteal = kSendStealAlarm,
			kGetActivationHeight = 680,
			kEPModSkillUsage_IsAdvanceSkill = 681,
			kWornHasKeyword = 682,
			kGetPathingCurrentSpeed = 683,
			kGetPathingCurrentSpeedAngle = 684,
			kKnockAreaEffect = 685,
			kKAE = kKnockAreaEffect,
			kInterruptCast = 686,
			kAddFormToFormList = 687,
			kRevertFormList = 688,
			kAddFormToLeveledList = 689,
			kRevertLeveledList = 690,
			kEPModSkillUsage_AdvanceObjectHasKeyword = 691,
			kEPModSkillUsage_IsAdvanceAction = 692,
			kEPMagic_SpellHasKeyword = 693,
			kGetNoBleedoutRecovery = 694,
			kSetNoBleedoutRecovery = 695,
			kEPMagic_SpellHasSkill = 696,
			kIsAttackType = 697,
			kIsAllowedToFly = 698,
			kHasMagicEffectKeyword = 699,
			kIsCommandedActor = 700,
			kIsStaggered = 701,
			kIsRecoiling = 702,
			kIsExitingInteractionQuick = 703,
			kIsPathing = 704,
			kGetShouldHelp = 705,
			kHasBoundWeaponEquipped = 706,
			kGetCombatTargetHasKeyword = 707,
			kGCTHK = kGetCombatTargetHasKeyword,
			kUpdateLevel = 708,
			kGetCombatGroupMemberCount = 709,
			kGCGMC = kGetCombatGroupMemberCount,
			kIsIgnoringCombat = 710,
			kGetLightLevel = 711,
			kGLL = kGetLightLevel,
			kSavePCFace = 712,
			kSPF = kSavePCFace,
			kSpellHasCastingPerk = 713,
			kIsBeingRidden = 714,
			kIsUndead = 715,
			kGetRealHoursPassed = 716,
			kUnequipAll = 717,
			kIsUnlockedDoor = 718,
			kIsHostileToActor = 719,
			kGetTargetHeight = 720,
			kIsPoison = 721,
			kWornApparelHasKeywordCount = 722,
			kGetItemHealthPercent = 723,
			kEffectWasDualCast = 724,
			kGetKnockStateEnum = 725,
			kDoesNotExist = 726,
			kUnequipItemSlot = 727,
			kMountActor = 728,
			kDismountActor = 729,
			kIsOnFlyingMount = 730,
			kCanFlyHere = 731,
			kIsFlyingMountPatrolQueued = 732,
			kIsFlyingMountFastTravelling = 733,
			kIsOverEncumbered = 734,
			kGetActorWarmth = 735,

			kTotal
		};


		FUNCTION_DATA();
		~FUNCTION_DATA() = default;


		// members
		stl::enumeration<FunctionID, std::uint16_t> function;	// 00
		std::uint16_t								pad02;		// 02
		std::uint32_t								pad04;		// 04
		void*										params[2];	// 08
	};
	static_assert(sizeof(FUNCTION_DATA) == 0x18);


	struct CONDITION_ITEM_DATA
	{
	public:
		enum class OpCode : std::uint8_t
		{
			kEqualTo,				// ==
			kNotEqualTo,			// !=
			kGreaterThan,			// >
			kGreaterThanOrEqualTo,	// >=
			kLessThan,				// <
			kLessThanOrEqualTo,		// <=
		};


		union GlobalOrFloat
		{
			GlobalOrFloat();
			~GlobalOrFloat() = default;


			TESGlobal* g;
			float	   f;
		};
		static_assert(sizeof(GlobalOrFloat) == 0x8);


		struct Flags
		{
		public:
			Flags();
			~Flags() = default;


			// members
			bool   isOR : 1;		 // 0 - false == AND, true == OR
			bool   usesAliases : 1;	 // 1
			bool   global : 1;		 // 2
			bool   usePackData : 1;	 // 3
			bool   swapTarget : 1;	 // 4
			OpCode opCode : 3;		 // 5
		};
		static_assert(sizeof(Flags) == 0x1);


		CONDITION_ITEM_DATA();
		~CONDITION_ITEM_DATA() = default;


		// members
		GlobalOrFloat										comparisonValue;  // 08
		ObjectRefHandle										runOnRef;		  // 10 - kReference
		std::uint32_t										dataID;			  // 14
		FUNCTION_DATA										functionData;	  // 18
		Flags												flags;			  // 30
		stl::enumeration<CONDITIONITEMOBJECT, std::uint8_t> object;			  // 31
		std::uint16_t										pad32;			  // 32
		std::uint32_t										pad34;			  // 34
	};
	static_assert(sizeof(CONDITION_ITEM_DATA) == 0x30);


	struct ConditionCheckParams
	{
	public:
		constexpr ConditionCheckParams(TESObjectREFR* a_actionRef, TESObjectREFR* a_targetRef) :
			actionRef(a_actionRef),
			targetRef(a_targetRef),
			unk10(nullptr),
			unk18(nullptr),
			unk20(nullptr),
			unk28(nullptr)
		{}


		// members
		TESObjectREFR* actionRef;  // 00
		TESObjectREFR* targetRef;  // 08
		void*		   unk10;	   // 10
		void*		   unk18;	   // 18
		void*		   unk20;	   // 20
		void*		   unk28;	   // 28
	};
	static_assert(sizeof(ConditionCheckParams) == 0x30);


	struct TESConditionItem	 // CTDA
	{
		TESConditionItem();
		~TESConditionItem() = default;

		TES_HEAP_REDEFINE_NEW();

		bool operator()(ConditionCheckParams& a_solution) const;
		bool IsTrue(ConditionCheckParams& a_solution) const;


		// members
		TESConditionItem*	next;  // 00
		CONDITION_ITEM_DATA data;  // 08
	};
	static_assert(sizeof(TESConditionItem) == 0x38);


	class TESCondition
	{
	public:
		TESCondition();
		~TESCondition();

		TES_HEAP_REDEFINE_NEW();

		[[nodiscard]] explicit operator bool() const;

		bool operator()(TESObjectREFR* a_actionRef, TESObjectREFR* a_targetRef) const;
		bool IsTrue(TESObjectREFR* a_actionRef, TESObjectREFR* a_targetRef) const;	// Perk fragments will short circuit


		// members
		TESConditionItem* head;	 // 0
	};
	static_assert(sizeof(TESCondition) == 0x8);
}
