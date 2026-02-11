#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace task {

enum class CSTaskGroupIndex : std::uint32_t {
  FrameBegin = 0,
  SteamThread0 = 1,
  SteamThread1 = 2,
  SteamThread2 = 3,
  SteamThread3 = 4,
  SteamThread4 = 5,
  SteamThread5 = 6,
  SystemStep = 7,
  ResStep = 8,
  PadStep = 9,
  GameFlowStep = 10,
  EndShiftWorldPosition = 11,
  GameMan = 12,
  TaskLineIdx_Sys = 13,
  TaskLineIdx_Test = 14,
  TaskLineIdx_NetworkFlowStep = 15,
  TaskLineIdx_InGame_InGameStep = 16,
  TaskLineIdx_InGame_InGameStayStep = 17,
  MovieStep = 18,
  RemoStep = 19,
  TaskLineIdx_InGame_MoveMapStep = 20,
  FieldArea_EndWorldAiManager = 21,
  EmkSystem_Pre = 22,
  EmkSystem_ConditionStatus = 23,
  EmkSystem_Post = 24,
  EventMan = 25,
  FlverResDelayDelectiionBegin = 26,
  TaskLineIdx_InGame_FieldAreaStep = 27,
  TaskLineIdx_InGame_TestNetStep = 28,
  TaskLineIdx_InGame_InGameMenuStep = 29,
  TaskLineIdx_InGame_TitleMenuStep = 30,
  TaskLineIdx_InGame_CommonMenuStep = 31,
  TaskLineIdx_FrpgNet_Sys = 32,
  TaskLineIdx_FrpgNet_Lobby = 33,
  TaskLineIdx_FrpgNet_ConnectMan = 34,
  TaskLineIdx_FrpgNet_Connect = 35,
  TaskLineIdx_FrpgNet_Other = 36,
  SfxMan = 37,
  FaceGenMan = 38,
  FrpgNetMan = 39,
  NetworkUserManager = 40,
  SessionManager = 41,
  BlockList = 42,
  LuaConsoleServer = 43,
  RmiMan = 44,
  ResMan = 45,
  SfxDebugger = 46,
  REMOTEMAN = 47,
  Geom_WaitActivateFade = 48,
  Geom_UpdateDraw = 49,
  Grass_BatchUpdate = 50,
  Grass_ResourceLoadKick = 51,
  Grass_ResourceLoad = 52,
  Grass_ResourceCleanup = 53,
  WorldChrMan_Respawn = 54,
  WorldChrMan_Prepare = 55,
  ChrIns_CalcUpdateInfo_PerfBegin = 56,
  ChrIns_CalcUpdateInfo = 57,
  ChrIns_CalcUpdateInfo_PerfEnd = 58,
  WorldChrMan_PrePhysics = 59,
  WorldChrMan_CalcOmissionLevel_Begin = 60,
  WorldChrMan_CalcOmissionLevel = 61,
  WorldChrMan_CalcOmissionLevel_End = 62,
  WorldChrMan_ConstructUpdateList = 63,
  WorldChrMan_ChrNetwork = 64,
  ChrIns_Prepare = 65,
  ChrIns_NaviCache = 66,
  ChrIns_AILogic_PerfBegin = 67,
  ChrIns_AILogic = 68,
  ChrIns_AILogic_PerfEnd = 69,
  AI_SimulationStep = 70,
  ChrIns_PreBehavior = 71,
  ChrIns_PreBehaviorSafe = 72,
  GeomModelInsCreatePartway_Begin = 73,
  HavokBehavior = 74,
  GeomModelInsCreatePartway_End = 75,
  ChrIns_BehaviorSafe = 76,
  ChrIns_PrePhysics_Begin = 77,
  ChrIns_PrePhysics = 78,
  ChrIns_PrePhysics_End = 79,
  NetFlushSendData = 80,
  ChrIns_PrePhysicsSafe = 81,
  ChrIns_RagdollSafe = 82,
  ChrIns_GarbageCollection = 83,
  GeomModelInsCreate = 84,
  AiBeginCollectGabage = 85,
  WorldChrMan_Update_RideCheck = 86,
  InGameDebugViewer = 87,
  LocationStep = 88,
  LocationUpdate_PrePhysics = 89,
  LocationUpdate_PrePhysics_Parallel = 90,
  LocationUpdate_PrePhysics_Post = 91,
  LocationUpdate_PostCloth = 92,
  LocationUpdate_PostCloth_Parallel = 93,
  LocationUpdate_PostCloth_Post = 94,
  LocationUpdate_DebugDraw = 95,
  EventCondition_BonfireNearEnemyCheck = 96,
  HavokWorldUpdate_Pre = 97,
  RenderingSystemUpdate = 98,
  HavokWorldUpdate_Post = 99,
  ChrIns_PreCloth = 100,
  ChrIns_PreClothSafe = 101,
  HavokClothUpdate_Pre_AddRemoveRigidBody = 102,
  HavokClothUpdate_Pre_ClothModelInsSafe = 103,
  HavokClothUpdate_Pre_ClothModelIns = 104,
  HavokClothUpdate_Pre_ClothManager = 105,
  CameraStep = 106,
  DrawParamUpdate = 107,
  GetNPAuthCode = 108,
  SoundStep = 109,
  HavokClothUpdate_Post_ClothManager = 110,
  HavokClothUpdate_Post_ClothModelIns = 111,
  HavokClothVertexUpdateFinishWait = 112,
  ChrIns_PostPhysics = 113,
  ChrIns_PostPhysicsSafe = 114,
  CSDistViewManager_Update = 115,
  HavokAi_SilhouetteGeneratorHelper_Begin = 116,
  WorldChrMan_PostPhysics = 117,
  GameFlowInGame_MoveMap_PostPhysics_0 = 118,
  HavokAi_SilhouetteGeneratorHelper_End = 119,
  DmgMan_Pre = 120,
  DmgMan_ShapeCast = 121,
  DmgMan_Post = 122,
  GameFlowInGame_MoveMap_PostPhysics_1_Core0 = 123,
  GameFlowInGame_MoveMap_PostPhysics_1_Core1 = 124,
  GameFlowInGame_MoveMap_PostPhysics_1_Core2 = 125,
  MenuMan = 126,
  WorldChrMan_Update_BackreadRequestPre = 127,
  ChrIns_Update_BackreadRequest = 128,
  WorldChrMan_Update_BackreadRequestPost = 129,
  HavokAi_World = 130,
  WorldAiManager_BeginUpdateFormation = 131,
  WorldAiManager_EndUpdateFormation = 132,
  GameFlowInGame_TestNet = 133,
  GameFlowInGame_InGameMenu = 134,
  GameFlowInGame_TitleMenu = 135,
  GameFlowInGame_CommonMenu = 136,
  GameFlowFrpgNet_Sys = 137,
  GameFlowFrpgNet_Lobby = 138,
  GameFlowFrpgNet_ConnectMan = 139,
  GameFlowFrpgNet_Connect = 140,
  GameFlowStep_Post = 141,
  ScaleformStep = 142,
  FlverResDelayDelectiionEnd = 143,
  Draw_Pre = 144,
  GraphicsStep = 145,
  DebugDrawMemoryBar = 146,
  DbgMenuStep = 147,
  DbgRemoteStep = 148,
  PlaylogSystemStep = 149,
  ReviewMan = 150,
  ReportSystemStep = 151,
  DbgDispStep = 152,
  DrawStep = 153,
  DrawBegin = 154,
  GameSceneDraw = 155,
  AdhocDraw = 156,
  DrawEnd = 157,
  Draw_Post = 158,
  SoundPlayLimitterUpdate = 159,
  BeginShiftWorldPosition = 160,
  FileStep = 161,
  FileStepUpdate_Begin = 162,
  FileStepUpdate_End = 163,
  Flip = 164,
  DelayDeleteStep = 165,
  AiEndCollectGabage = 166,
  RecordHeapStats = 167,
  FrameEnd = 168,
};

struct TaskGroupConcurrencySlot {
  std::uint32_t task_group_index;
  std::uint32_t task_group_concurrency_type;
};

struct TaskGroupConcurrency {
  std::array<eldenring::cs::task::TaskGroupConcurrencySlot, 6> slots;
};

struct CSTaskRunnerEx {
};

struct TaskGroupEntry {
  std::uint32_t index;
  std::array<std::uint16_t, 64> name;
  bool active;
};

struct CSTaskBase {
  std::uintptr_t vftable;
  std::uintptr_t allocator;
  eldenring::Vector<eldenring::cs::task::TaskGroupEntry> task_groups;
  std::uint32_t task_group_index_max;
  std::uint32_t _pad34;
};

struct CSEzTask;

struct CSEzRabbitTaskBase;

struct CSEzRabbitNoUpdateTask;

template <typename TEzTask, typename TSubject>
struct CSEzUpdateTask;

struct CSEzRabbitTask;

template <typename TEzTask, typename TSubject>
struct CSEzVoidTask;

struct CSEzTaskProxy;

struct CSTaskGroup;

struct CSTaskGroupIns;

struct CSTimeLineTaskGroupIns;

struct CSTaskImp;

struct CSTask;

struct CSTaskRunner;

struct CSTaskRunnerManager;

}
}
}
