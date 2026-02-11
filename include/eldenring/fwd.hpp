#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>

namespace eldenring {
namespace cs {
namespace action_button {
struct CSActionButtonManImp;
}
}
}

namespace eldenring {
namespace cs {
namespace auto_invade_point {
struct AutoInvadePoint;
struct AutoInvadePointBlockEntry;
struct CSAutoInvadePoint;
}
}
}

namespace eldenring {
namespace cs {
namespace block_id {
struct BlockId;
}
}
}

namespace eldenring {
namespace cs {
namespace bullet_ins {
struct BulletParamLookupResult;
struct BulletPhysics;
struct CSBulletExplosionState;
struct CSBulletFlyState;
struct CSBulletIns;
struct CSBulletNULLState;
struct CSBulletState;
struct CSBulletWaitState;
}
}
}

namespace eldenring {
namespace cs {
namespace bullet_manager {
template <typename T, typename BUFFER_SIZE, typename MAX_ALLOCS>
struct BufferAndAllocLinkedList;
struct BulletSpawnData;
struct CSBulletManager;
}
}
}

namespace eldenring {
namespace cs {
namespace camera {
struct CSCam;
struct CSCamera;
struct ChrCam;
enum class ChrCamType : std::uint32_t;
}
}
}

namespace eldenring {
namespace cs {
namespace character_type_properties {
struct CharacterTypePropertiesEntry;
struct CharacterTypePropertiesTable;
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
struct AtkParamLookupResult;
struct CSChrModelIns;
struct CSFD4LocationGxModelMatricesAndAabbExporter;
struct CSFD4ModelItem;
struct CSModelIns;
struct ChrCtrl;
struct ChrCtrlChrProxyFlags;
struct ChrCtrlFlags;
struct ChrCtrlModifier;
struct ChrCtrlModifierActionFlags;
struct ChrCtrlModifierData;
struct ChrCtrlModifierHksFlags;
struct ChrDebugFlags;
struct ChrIns;
struct ChrInsActivationFlags;
struct ChrInsFlags1c4;
struct ChrInsFlags1c5;
struct ChrInsFlags1c6;
struct ChrInsFlags1c7;
struct ChrInsFlags1c8;
struct ChrInsFlags1ca;
enum class ChrMovementLimit : std::uint32_t;
enum class ChrType : std::int32_t;
struct EnemyIns;
enum class HandIndex : std::uint32_t;
struct NetChrSyncFlags;
enum class OmissionMode : std::int32_t;
struct P2PEntityHandle;
struct P2PEntitySelector;
struct PlayerIns;
struct PlayerSessionHolder;
struct ReplayRecorder;
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
struct ChrInsModuleContainer;
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace action_flag {
struct CSChrActionFlagModule;
struct ChrActionAnimationFlags;
struct ChrActionModifiersFlags;
enum class SpEffectWetConditionDepth : std::uint8_t;
enum class WeaponModelChangeType : std::int8_t;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace action_request {
struct ActionTimers;
struct AiActionCancels;
struct CSChrActionRequestModule;
struct ChrActions;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace behavior {
struct CSChrBehaviorModule;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace behavior_data {
struct CSChrBehaviorDataModule;
struct EnableTwistModifierArgs;
struct TwistModifierBehaviorData;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace data {
struct CSChrDataModule;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace event {
struct CSChrEventModule;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace fall {
struct CSChrFallModule;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace grass_hit {
struct CSChrGrassHitModule;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace kw_throw {
struct CSChrThrowModule;
struct CSThrowNode;
struct ThrowModuleFlags;
enum class ThrowNodeState : std::uint32_t;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace material {
struct CSChrMaterialModule;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace model_param_modifier {
struct CSChrModelParamModifierModule;
struct CSChrModelParamModifierModuleEntry;
struct CSChrModelParamModifierModuleEntryValue;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace physics {
struct CSChrPhysicsModule;
struct ChrPhysicsMaterialInfo;
struct ChrPhysicsSlideInfo;
struct MoveTypeFlags;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace ride {
struct CSChrRideModule;
struct CSChrRideModuleMountData;
struct CSRideNode;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace super_armor {
struct CSChrSuperArmorModule;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace time_act {
struct CSChrTimeActModule;
struct CSChrTimeActModuleAnim;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace toughness {
struct CSChrToughnessModule;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace wet {
struct CSChrWetModule;
}
}
}
}
}

namespace eldenring {
namespace cs {
namespace chr_manipulator {
struct ChrManipulator;
enum class ManipulatorType : std::uint32_t;
}
}
}

namespace eldenring {
namespace cs {
namespace chr_slot {
struct ChrSlotBase;
}
}
}

namespace eldenring {
namespace cs {
namespace cs_rand {
struct CSRand;
struct CSRandSFMT;
struct CSRandXorshift;
struct DLRandomGeneratorSFMT;
struct DLRandomGeneratorXorshift;
}
}
}

namespace eldenring {
namespace cs {
namespace event_flag {
struct CSEventFlagMan;
struct CSFD4VirtualMemoryFlag;
struct EventFlag;
struct FlagBlock;
struct FlagBlockDescriptor;
enum class FlagBlockLocation;
}
}
}

namespace eldenring {
namespace cs {
namespace event_man {
struct CSEventManImp;
struct CSEventSosSignCtrl;
struct CSEventWorldAreaTimeCtrl;
struct TimeTransitionParams;
}
}
}

namespace eldenring {
namespace cs {
namespace ez_select_bot {
struct CSEzSelectBot;
}
}
}

namespace eldenring {
namespace cs {
namespace ez_state_talk {
struct CSEzStateTalkEnv;
struct CSEzStateTalkEvent;
}
}
}

namespace eldenring {
namespace cs {
namespace fade {
struct CSFD4FadePlate;
struct CSFD4FadePlateColor;
struct CSFD4FadeSystem;
struct CSFade;
}
}
}

namespace eldenring {
namespace cs {
namespace fe_man {
struct BossHealthDisplayEntry;
enum class CSFeManHudState : std::uint8_t;
struct CSFeManImp;
struct CSFeSpiritAshDisplay;
struct ChrEnemyTagEntry;
struct ChrFriendTagEntry;
struct FrontEndView;
struct FrontEndViewValues;
enum class FullScreenMessage : std::int32_t;
struct MenuString;
struct SummonMsgData;
struct SummonMsgQueue;
struct TagHudData;
}
}
}

namespace eldenring {
namespace cs {
namespace field_area {
struct FieldArea;
struct WorldAreaInfo;
struct WorldAreaInfoBase;
struct WorldBlockInfo;
struct WorldBlockInfoCeremony;
struct WorldGridAreaInfo;
struct WorldGridAreaInfoBlockElement;
struct WorldInfo;
struct WorldInfoOwner;
struct WorldRes;
}
}
}

namespace eldenring {
namespace cs {
namespace field_ins {
struct FieldInsHandle;
struct FieldInsSelector;
enum class FieldInsType : std::uint32_t;
}
}
}

namespace eldenring {
namespace cs {
namespace file {
struct CSFileImp;
struct CSFileRepository;
struct CSFileRepositoryMutex;
}
}
}

namespace eldenring {
namespace cs {
namespace flipper {
struct CSFlipper;
struct CSFlipperVsyncHistoryEntry;
enum class FlipMode : std::uint32_t;
}
}
}

namespace eldenring {
namespace cs {
namespace gaitem {
struct CSGaitemGameData;
struct CSGaitemGameDataEntry;
struct CSGaitemImp;
struct CSGaitemImpEntry;
struct CSGaitemIns;
struct CSGemGaitemIns;
struct CSGemSlot;
struct CSGemSlotTable;
struct CSWepGaitemIns;
enum class GaitemCategory : std::uint8_t;
struct GaitemHandle;
enum class GaitemHandleError;
}
}
}

namespace eldenring {
namespace cs {
namespace game_data_man {
enum class DeathState : std::int32_t;
enum class DisplayBlood : std::uint8_t;
struct GameDataMan;
struct GameSettings;
struct GameVersionData;
enum class HudType : std::uint8_t;
enum class PerformanceSetting : std::uint8_t;
enum class RemotePlayerDataSlotState : std::uint8_t;
}
}
}

namespace eldenring {
namespace cs {
namespace game_man {
enum class EventWorldType : std::uint8_t;
enum class ForceCamRotationMethod : std::uint32_t;
struct GameMan;
}
}
}

namespace eldenring {
namespace cs {
namespace havok_man {
struct CSHavokMan;
struct CSPhysWorld;
}
}
}

namespace eldenring {
namespace cs {
namespace item {
struct MapItemMan;
}
}
}

namespace eldenring {
namespace cs {
namespace item_id {
enum class ItemCategory : std::uint8_t;
struct ItemId;
enum class ItemIdError;
struct OptionalItemId;
}
}
}

namespace eldenring {
namespace cs {
namespace item_lot {
struct ItemLotUtil;
}
}
}

namespace eldenring {
namespace cs {
namespace job {
struct FixOrderJobSequenceBase;
struct MenuJobBase;
struct MenuJobResult;
}
}
}

namespace eldenring {
namespace cs {
namespace location {
struct CSFD4LocationNode;
struct CSFD4LocationPose;
}
}
}

namespace eldenring {
namespace cs {
namespace menu_man {
struct BackScreenData;
struct CSChrMenuFlags;
struct CSMenuData;
struct CSMenuGaitemUseState;
struct CSMenuManImp;
struct CSPlayerMenuCtrl;
struct CSPopupMenu;
struct ChrMenuFlags;
struct FeSystemAnnounceViewModel;
struct FeSystemAnnounceViewModelMessageQueue;
struct LoadingScreenData;
}
}
}

namespace eldenring {
namespace cs {
namespace menu_type {
enum class MenuType : std::int32_t;
}
}
}

namespace eldenring {
namespace cs {
namespace msb {
struct MsbFileCap;
struct MsbRepository;
}
}
}

namespace eldenring {
namespace cs {
namespace multiplay_type {
enum class JoinType : std::uint32_t;
enum class MatchingCooldownType : std::int32_t;
struct MultiplayProperties;
struct MultiplayPropertyEntry;
struct MultiplayPropertyEntryFlags;
enum class MultiplayRole : std::uint8_t;
enum class MultiplayType : std::uint8_t;
enum class SummonParamType : std::int32_t;
}
}
}

namespace eldenring {
namespace cs {
namespace net_chr_sync {
struct ChrSyncHealthUpdate;
struct ChrSyncPlacementUpdate;
struct ChrSyncUpdateFlags;
struct NetChrSetSync;
struct NetChrSync;
}
}
}

namespace eldenring {
namespace cs {
namespace net_man {
struct CSBattleRoyalContext;
struct CSNetBloodMessageDb;
struct CSNetBloodMessageDbItem;
struct CSNetMan;
struct CSQuickMatchContext;
struct CSQuickMatchingCtrl;
enum class CSQuickMatchingCtrlState : std::uint32_t;
enum class QuickMatchArena : std::uint32_t;
enum class QuickMatchSettings : std::uint32_t;
enum class QuickMatchVenue : std::uint32_t;
struct QuickmatchManager;
struct QuickmatchParticipant;
struct QuickmatchSpawnData;
}
}
}

namespace eldenring {
namespace cs {
namespace network_session {
struct PlayerNetworkSession;
struct PlayerSession;
struct ReceivePacketAllocation;
struct ReceivedPacketReader;
}
}
}

namespace eldenring {
namespace cs {
namespace now_loading {
struct CSNowLoadingHelper;
}
}
}

namespace eldenring {
namespace cs {
namespace pair_anim {
struct CSPairAnimManager;
struct CSPairAnimManager20Entry;
struct CSPairAnimNode;
}
}
}

namespace eldenring {
namespace cs {
namespace party_member_info {
enum class CeremonyState : std::uint32_t;
enum class MemberType : std::uint32_t;
enum class PartyMemberEntryState : std::uint32_t;
struct PartyMemberInfo;
struct PartyMemberInfoEntry;
}
}
}

namespace eldenring {
namespace cs {
namespace player_game_data {
struct BrokenEquipmentSlots;
struct ChrAsm;
enum class ChrAsmArmStyle : std::uint32_t;
struct ChrAsmEquipEntries;
struct ChrAsmEquipment;
struct ChrAsmEquipmentSlots;
enum class ChrAsmSlot : std::uint32_t;
enum class ChrAsmSlotError;
struct EquipDataItem;
struct EquipGameData;
struct EquipInventoryData;
struct EquipInventoryDataListEntry;
struct EquipItemData;
struct EquipMagicData;
struct EquipMagicItem;
enum class EquipmentDurabilityStatus : std::uint8_t;
struct FaceData;
struct FaceDataBuffer;
struct InventoryItemListAccessor;
struct InventoryItemsData;
struct ItemIdMapping;
struct ItemReplenishStateEntry;
struct ItemReplenishStateEntryUnk;
struct ItemReplenishStateTracker;
enum class LastAddItemResult : std::uint32_t;
struct PlayerDataAttackRating;
enum class PlayerDataInvasionItemType : std::uint8_t;
struct PlayerGameData;
struct PlayerGameDataFrontendFlags;
struct PlayerGameDataSpEffect;
struct QMItemBackupVectorItem;
enum class SellRegion : std::uint8_t;
}
}
}

namespace eldenring {
namespace cs {
namespace rend_man {
struct CSEzDraw;
struct DlColor32;
enum class EzDrawFillMode : std::uint32_t;
struct EzDrawFlags;
enum class EzDrawTextCoordMode : std::uint32_t;
struct FD4EzDrawState;
struct FD4HkEzDrawCommandBuffer;
struct FD4HkEzDrawContext;
struct FD4HkEzDrawState;
struct RendMan;
}
}
}

namespace eldenring {
namespace cs {
namespace session_manager {
struct CSSessionManager;
struct CSSessionManager0x20;
struct CSSessionManagerP2PInboundQueueStats;
struct CSSessionManagerP2PSendQueue;
struct CSSessionManagerP2PSendQueueEntry;
struct CSStayInMultiplayAreaWarpData;
enum class LobbyState : std::uint32_t;
enum class ProtocolState : std::uint32_t;
struct SessionManagerPlayerEntry;
struct SessionManagerPlayerEntryBase;
struct StayInMultiplayFadeTrackerEntry;
}
}
}

namespace eldenring {
namespace cs {
namespace sfx {
struct CSSfxImp;
}
}
}

namespace eldenring {
namespace cs {
namespace sos_sign_man {
struct CSSosSignMan;
struct CSSosSignSfx;
struct DisplayGhostData;
struct ObjectIdentifier;
struct PhantomJoinData;
enum class PhantomJoinState : std::uint32_t;
struct SignTreeEntry;
struct SosSignData;
struct SteamIdStr;
enum class SummonJobErrorCode : std::int32_t;
}
}
}

namespace eldenring {
namespace cs {
namespace sp_effect {
struct NpcSpEffectEquipCtrl;
struct SpEffectEquipCtrl;
struct SpecialEffect;
struct SpecialEffectEntry;
struct SpecialEffectEntryAccumulatorInfo;
}
}
}

namespace eldenring {
namespace cs {
namespace talk_script {
struct CSNpcTalkIns;
struct CSTalkIns;
enum class EzStateInvokeError;
struct NpcMenuState;
struct OpenMenuJob;
struct TalkScript;
struct TalkScriptMachineHolder;
}
}
}

namespace eldenring {
namespace cs {
namespace targeting {
struct CSAiTargetingSystemOwner;
struct CSBulletTargetingSystemOwner;
struct CSTargetSearchSys;
struct CSTargetingSystemBase;
struct CSTargetingSystemOwner;
struct NpcThinkParamLookupResult;
}
}
}

namespace eldenring {
namespace cs {
namespace task {
struct CSEzRabbitNoUpdateTask;
struct CSEzRabbitTask;
struct CSEzRabbitTaskBase;
struct CSEzTask;
struct CSEzTaskProxy;
template <typename TEzTask, typename TSubject>
struct CSEzUpdateTask;
template <typename TEzTask, typename TSubject>
struct CSEzVoidTask;
struct CSTask;
struct CSTaskBase;
struct CSTaskGroup;
enum class CSTaskGroupIndex : std::uint32_t;
struct CSTaskGroupIns;
struct CSTaskImp;
struct CSTaskRunner;
struct CSTaskRunnerEx;
struct CSTaskRunnerManager;
struct CSTimeLineTaskGroupIns;
struct TaskGroupConcurrency;
struct TaskGroupConcurrencySlot;
struct TaskGroupEntry;
}
}
}

namespace eldenring {
namespace cs {
namespace team_relation {
struct CSTeamTypeBase;
struct CSTeamTypeEnemy;
struct CSTeamTypeFriend;
struct CSTeamTypeNeutral;
struct CSTeamTypeRival;
struct TeamRelationTargetInfo;
}
}
}

namespace eldenring {
namespace cs {
namespace trophy {
struct CSTrophy;
struct CSTrophyPlatformImp;
struct CSTrophyPlatformImp_forSteam;
struct CSTrophyPlatformImp_forSteamAchievementItem;
struct CSTrophyTitleInfo;
}
}
}

namespace eldenring {
namespace cs {
namespace window {
struct CSWindowImp;
struct CSWindowScreenConfig;
enum class CSWindowType : std::uint32_t;
enum class FpsTarget : std::uint32_t;
enum class GrassQuality : std::uint32_t;
enum class OnOffSetting : std::uint32_t;
enum class QualityLevelSetting : std::uint32_t;
enum class QualitySetting : std::uint32_t;
enum class ToggleableGraphicsQuality : std::uint32_t;
}
}
}

namespace eldenring {
namespace cs {
namespace world_area_time {
enum class AiSightTimeOfDay : std::uint32_t;
struct WorldAreaTime;
}
}
}

namespace eldenring {
namespace cs {
namespace world_chr_man {
struct CSBuddyStoneEliminateTargetCalc;
struct CSDebugChrCreator;
struct CSDebugChrCreatorInitData;
struct ChrDebugSpawnRequest;
struct ChrInsDistanceEntry;
enum class ChrLoadStatus : std::uint8_t;
template <typename T>
struct ChrSet;
template <typename T>
struct ChrSetEntityIdMapping;
template <typename T>
struct ChrSetEntry;
template <typename T>
struct ChrSetGroupMapping;
template <typename T>
struct ChrSetHolder;
enum class ChrUpdateType : std::uint8_t;
struct IChrFinder;
struct NearEnemyFinder;
struct OpenFieldChrSet;
struct OpenFieldChrSetList1Entry;
struct OpenFieldChrSetList2Entry;
struct SummonBuddyGroup;
struct SummonBuddyGroupEntry;
struct SummonBuddyManager;
struct SummonBuddyStoneEliminateTargetEntry;
struct SummonBuddyWarpEntry;
struct SummonBuddyWarpManager;
enum class SummonBuddyWarpStage : std::uint8_t;
template <typename T>
struct WorldAreaChr;
struct WorldAreaChrBase;
template <typename T>
struct WorldBlockChr;
struct WorldChrMan;
struct WorldGridAreaChr;
}
}
}

namespace eldenring {
namespace cs {
namespace world_chr_man_dbg {
struct OmissionUpdateNum;
enum class OmissionUpdateNumType : std::int32_t;
struct WorldChrManDbg;
struct WorldChrManDbgFlags;
}
}
}

namespace eldenring {
namespace cs {
namespace world_geom_man {
struct CSMsbParts;
struct CSMsbPartsEne;
struct CSMsbPartsGeom;
struct CSWorldGeomInfo;
struct CSWorldGeomInfoUnk;
struct CSWorldGeomIns;
struct CSWorldGeomMan;
struct CSWorldGeomManBlockData;
struct CSWorldGeomManBlocksEntry;
struct GeometrySpawnParameters;
struct GeometrySpawnRequest;
struct MsbPart;
}
}
}

namespace eldenring {
namespace cs {
namespace world_scene_draw_param_manager {
struct CSFD4SceneDrawParam;
struct CSGparamIdLerper;
struct CSWorldAreaBlockSceneDrawParam;
struct CSWorldSceneDrawParamManager;
}
}
}

namespace eldenring {
namespace cs {
namespace world_sfx_man {
struct WorldAreaSfx;
struct WorldAreaSfxBase;
struct WorldBlockSfx;
struct WorldGridAreaSfx;
struct WorldSfxMan;
}
}
}

namespace eldenring {
namespace dlcr {
struct AESDecrypter;
struct AESEncrypter;
struct CipherInitParams;
enum class CipherMode : std::uint16_t;
enum class CipherPaddingMode : std::uint16_t;
enum class CipherType : std::uint16_t;
struct CryptoKeyParams;
enum class CryptoKeyType : std::uint16_t;
struct CryptoSPIRegistry;
struct DLCipherKey;
struct DLCipherSPI;
struct DLDecrypter;
struct DLKeyGeneratorSPI;
struct DLRijndaelAlgorithm;
struct DLSerialCipherKey;
enum class KeyType : std::uint16_t;
enum class KeyUsageType : std::uint16_t;
struct OpenSslAesCipher;
struct OpenSslAesDecrypter;
struct OpenSslRsaCipher;
struct OpenSslRsaDecrypter;
}
}

namespace eldenring {
namespace dlio {
namespace common {
enum class DLFileSeekDirection : std::uint32_t;
enum class DLIOResult : std::int32_t;
struct OpenFileMode;
}
}
}

namespace eldenring {
namespace dlio {
namespace file_device {
template <typename R>
struct AdapterFileOperator;
struct BndEntry;
struct DLFileDeviceBase;
enum class DLFileDeviceDriveType : std::uint32_t;
struct DLFileDeviceImageSPIBase;
struct DLFileDeviceManager;
struct DLFileEnumeratorSPIBase;
template <typename T>
struct DLFileOperatorBase;
struct DLFileOperatorContainer;
struct DLFileOperatorIOState;
}
}
}

namespace eldenring {
namespace dlio {
namespace stream {
struct DLBufferedInputStream;
struct DLFileInputStream;
struct DLFileOutputStream;
struct DLMemoryInputStream;
struct DLMemoryOutputStream;
struct DLPseudoAsyncInputStream;
struct DLStreamBuffer;
}
}
}

namespace eldenring {
namespace dlkr {
namespace allocator {
struct DLAllocatorBase;
struct DLAllocatorRef;
}
}
}

namespace eldenring {
namespace dlkr {
namespace mutex {
struct DLPlainLightMutex;
}
}
}

namespace eldenring {
namespace dlkr {
namespace signal {
struct DLPlainConditionSignal;
}
}
}

namespace eldenring {
namespace dlrf {
struct DLRuntimeClass;
}
}

namespace eldenring {
namespace dltx {
enum class DLCharacterSet : std::uint8_t;
struct DLEucJpStringKind;
struct DLISO8859_1StringKind;
template <typename T, typename N>
struct DLInplaceStr;
template <typename T>
struct DLRawString;
struct DLShiftJisStringKind;
template <typename T>
struct DLString;
enum class DLStringEncodingError;
struct DLUTF16StringKind;
struct DLUTF32StringKind;
struct DLUTF8StringKind;
}
}

namespace eldenring {
namespace dlut {
struct DLDateTime;
template <typename T, typename C>
struct DLFixedVector;
struct DLReferenceCountObjectBase;
struct PackedDate;
}
}

namespace eldenring {
namespace ez_state {
struct EzStateMachineImpl;
}
}

namespace eldenring {
namespace ez_state {
namespace environment_query {
struct EzStateEnvironmentQuery;
}
}
}

namespace eldenring {
namespace ez_state {
namespace event {
struct EzStateEvent;
}
}
}

namespace eldenring {
namespace ez_state {
namespace value {
struct EzStateRawValue;
enum class EzStateValue;
}
}
}

namespace eldenring {
namespace fd4 {
namespace basic_hash_string {
template <typename T>
struct FD4BasicHashString;
}
}
}

namespace eldenring {
namespace fd4 {
namespace param_repository {
struct FD4ParamRepository;
struct FD4ParamResCap;
struct ParamFile;
template <typename O>
struct RowDescriptor;
}
}
}

namespace eldenring {
namespace fd4 {
namespace resource {
struct FD4FileCap;
enum class FD4FileCapState : std::uint8_t;
struct FD4FileCapUnk89Properties;
struct FD4FileCapUnk8AProperties;
struct FD4ResCap;
template <typename T>
struct FD4ResCapHolder;
template <typename T>
struct FD4ResRep;
}
}
}

namespace eldenring {
namespace fd4 {
namespace slot {
struct FD4SlotInsBase;
struct FD4SlotSysBase;
}
}
}

namespace eldenring {
namespace fd4 {
namespace step {
template <typename N, typename T>
struct FD4StepBaseInterface;
template <typename N, typename T>
struct FD4StepTemplateBase;
struct FD4StepTemplateBase0x18;
template <typename T>
struct StepperFn;
}
}
}

namespace eldenring {
namespace fd4 {
namespace task {
struct FD4TaskBase;
struct FD4TaskData;
struct FD4TaskGroup;
struct FD4TaskQueue;
struct FD4TaskRequestEntry;
}
}
}

namespace eldenring {
namespace fd4 {
namespace time {
struct FD4Time;
}
}
}

namespace eldenring {
namespace ffx {
struct FXAppearanceBase;
}
}

namespace eldenring {
namespace gxffx {
struct FxrListNode;
struct FxrResourceContainer;
struct FxrWrapper;
struct GXFfxGraphicsResourceManager;
struct GXFfxSceneCtrl;
}
}

namespace eldenring {
namespace param {
namespace generated {
struct ACTIONBUTTON_PARAM_ST;
struct AI_SOUND_PARAM_ST;
struct ASSET_GEOMETORY_PARAM_ST;
struct ASSET_MATERIAL_SFX_PARAM_ST;
struct ASSET_MODEL_SFX_PARAM_ST;
struct ATK_PARAM_ST;
struct ATTACK_ELEMENT_CORRECT_PARAM_ST;
struct AUTO_CREATE_ENV_SOUND_PARAM_ST;
struct BASECHR_SELECT_MENU_PARAM_ST;
struct BEHAVIOR_PARAM_ST;
struct BONFIRE_WARP_PARAM_ST;
struct BONFIRE_WARP_SUB_CATEGORY_PARAM_ST;
struct BONFIRE_WARP_TAB_PARAM_ST;
struct BUDDY_PARAM_ST;
struct BUDDY_STONE_PARAM_ST;
struct BUDGET_PARAM_ST;
struct BULLET_CREATE_LIMIT_PARAM_ST;
struct BULLET_PARAM_ST;
struct CACL_CORRECT_GRAPH_ST;
struct CAMERA_FADE_PARAM_ST;
struct CEREMONY_PARAM_ST;
struct CHARACTER_INIT_PARAM;
struct CHARMAKEMENUTOP_PARAM_ST;
struct CHARMAKEMENU_LISTITEM_PARAM_ST;
struct CHR_ACTIVATE_CONDITION_PARAM_ST;
struct CHR_EQUIP_MODEL_PARAM_ST;
struct CHR_MODEL_PARAM_ST;
struct CLEAR_COUNT_CORRECT_PARAM_ST;
struct COMMON_SYSTEM_PARAM_ST;
struct COOL_TIME_PARAM_ST;
struct CS_AA_QUALITY_DETAIL;
struct CS_DECAL_QUALITY_DETAIL;
struct CS_DOF_QUALITY_DETAIL;
struct CS_EFFECT_QUALITY_DETAIL;
struct CS_GRAPHICS_CONFIG_PARAM_ST;
struct CS_KEY_ASSIGN_MENUITEM_PARAM;
struct CS_LIGHTING_QUALITY_DETAIL;
struct CS_MOTION_BLUR_QUALITY_DETAIL;
struct CS_RAYTRACING_QUALITY_DETAIL;
struct CS_REFLECTION_QUALITY_DETAIL;
struct CS_SHADER_QUALITY_DETAIL;
struct CS_SHADOW_QUALITY_DETAIL;
struct CS_SSAO_QUALITY_DETAIL;
struct CS_TEXTURE_FILTER_QUALITY_DETAIL;
struct CS_VOLUMETRIC_EFFECT_QUALITY_DETAIL;
struct CS_WATER_QUALITY_DETAIL;
struct CUTSCENE_GPARAM_TIME_PARAM_ST;
struct CUTSCENE_GPARAM_WEATHER_PARAM_ST;
struct CUTSCENE_MAP_ID_PARAM_ST;
struct CUTSCENE_TEXTURE_LOAD_PARAM_ST;
struct CUTSCENE_TIMEZONE_CONVERT_PARAM_ST;
struct CUTSCENE_WEATHER_OVERRIDE_GPARAM_ID_CONVERT_PARAM_ST;
struct DECAL_PARAM_ST;
struct DEFAULT_KEY_ASSIGN;
struct DIRECTION_CAMERA_PARAM_ST;
struct ENEMY_COMMON_PARAM_ST;
struct ENV_OBJ_LOT_PARAM_ST;
struct EQUIP_MTRL_SET_PARAM_ST;
struct EQUIP_PARAM_ACCESSORY_ST;
struct EQUIP_PARAM_CUSTOM_WEAPON_ST;
struct EQUIP_PARAM_GEM_ST;
struct EQUIP_PARAM_GOODS_ST;
struct EQUIP_PARAM_PROTECTOR_ST;
struct EQUIP_PARAM_WEAPON_ST;
struct ESTUS_FLASK_RECOVERY_PARAM_ST;
struct FACE_PARAM_ST;
struct FACE_RANGE_PARAM_ST;
struct FE_TEXT_EFFECT_PARAM_ST;
struct FINAL_DAMAGE_RATE_PARAM_ST;
struct FOOT_SFX_PARAM_ST;
struct GAME_AREA_PARAM_ST;
struct GAME_SYSTEM_COMMON_PARAM_ST;
struct GESTURE_PARAM_ST;
struct GPARAM_REF_SETTINGS_PARAM_ST;
struct GRAPHICS_COMMON_PARAM_ST;
struct GRASS_LOD_RANGE_PARAM_ST;
struct GRASS_TYPE_PARAM_ST;
struct HIT_EFFECT_SE_PARAM_ST;
struct HIT_EFFECT_SFX_CONCEPT_PARAM_ST;
struct HIT_EFFECT_SFX_PARAM_ST;
struct HIT_MTRL_PARAM_ST;
struct ITEMLOT_PARAM_ST;
struct KEY_ASSIGN_PARAM_ST;
struct KNOCKBACK_PARAM_ST;
struct KNOWLEDGE_LOADSCREEN_ITEM_PARAM_ST;
struct LEGACY_DISTANT_VIEW_PARTS_REPLACE_PARAM;
struct LOAD_BALANCER_DRAW_DIST_SCALE_PARAM_ST;
struct LOAD_BALANCER_NEW_DRAW_DIST_SCALE_PARAM_ST;
struct LOAD_BALANCER_PARAM_ST;
struct LOCK_CAM_PARAM_ST;
struct MAGIC_PARAM_ST;
struct MAP_DEFAULT_INFO_PARAM_ST;
struct MAP_GD_REGION_DRAW_PARAM;
struct MAP_GD_REGION_ID_PARAM_ST;
struct MAP_GRID_CREATE_HEIGHT_LIMIT_DETAIL_INFO_PARAM_ST;
struct MAP_GRID_CREATE_HEIGHT_LIMIT_INFO_PARAM_ST;
struct MAP_MIMICRY_ESTABLISHMENT_PARAM_ST;
struct MAP_NAME_TEX_PARAM_ST;
struct MAP_NAME_TEX_PARAM_ST_DLC02;
struct MAP_PIECE_TEX_PARAM_ST;
struct MAP_PIECE_TEX_PARAM_ST_DLC02;
struct MATERIAL_EX_PARAM_ST;
struct MENUPROPERTY_LAYOUT;
struct MENUPROPERTY_SPEC;
struct MENU_COMMON_PARAM_ST;
struct MENU_OFFSCR_REND_PARAM_ST;
struct MENU_PARAM_COLOR_TABLE_ST;
struct MENU_VALUE_TABLE_SPEC;
struct MIMICRY_ESTABLISHMENT_TEX_PARAM_ST;
struct MIMICRY_ESTABLISHMENT_TEX_PARAM_ST_DLC02;
struct MOVE_PARAM_ST;
struct MULTI_ESTUS_FLASK_BONUS_PARAM_ST;
struct MULTI_PLAY_CORRECTION_PARAM_ST;
struct MULTI_SOUL_BONUS_RATE_PARAM_ST;
struct NETWORK_AREA_PARAM_ST;
struct NETWORK_MSG_PARAM_ST;
struct NETWORK_PARAM_ST;
struct NPC_AI_ACTION_PARAM_ST;
struct NPC_AI_BEHAVIOR_PROBABILITY_PARAM_ST;
struct NPC_PARAM_ST;
struct NPC_THINK_PARAM_ST;
struct OBJ_ACT_PARAM_ST;
struct PARTS_DRAW_PARAM_ST;
struct PHANTOM_PARAM_ST;
struct PLAYER_COMMON_PARAM_ST;
struct PLAY_REGION_PARAM_ST;
struct POSTURE_CONTROL_PARAM_GENDER_ST;
struct POSTURE_CONTROL_PARAM_PRO_ST;
struct POSTURE_CONTROL_PARAM_WEP_LEFT_ST;
struct POSTURE_CONTROL_PARAM_WEP_RIGHT_ST;
struct RANDOM_APPEAR_PARAM_ST;
struct REINFORCE_PARAM_PROTECTOR_ST;
struct REINFORCE_PARAM_WEAPON_ST;
struct RESIST_CORRECT_PARAM_ST;
struct REVERB_AUX_SEND_BUS_PARAM_ST;
struct RIDE_PARAM_ST;
struct ROLE_PARAM_ST;
struct ROLLING_OBJ_LOT_PARAM_ST;
struct RUNTIME_BONE_CONTROL_PARAM_ST;
struct SE_ACTIVATION_RANGE_PARAM_ST;
struct SE_MATERIAL_CONVERT_PARAM_ST;
struct SFX_BLOCK_RES_SHARE_PARAM;
struct SHOP_LINEUP_PARAM;
struct SIGN_PUDDLE_PARAM_ST;
struct SIGN_PUDDLE_SUB_CATEGORY_PARAM_ST;
struct SIGN_PUDDLE_TAB_PARAM_ST;
struct SOUND_ASSET_SOUND_OBJ_ENABLE_DIST_PARAM_ST;
struct SOUND_AUTO_ENV_SOUND_GROUP_PARAM_ST;
struct SOUND_AUTO_REVERB_EVALUATION_DIST_PARAM_ST;
struct SOUND_AUTO_REVERB_SELECT_PARAM_ST;
struct SOUND_CHR_PHYSICS_SE_PARAM_ST;
struct SOUND_COMMON_INGAME_PARAM_ST;
struct SOUND_COMMON_SYSTEM_PARAM_ST;
struct SOUND_CUTSCENE_PARAM_ST;
struct SPEEDTREE_MODEL_PARAM_ST;
struct SP_EFFECT_PARAM_ST;
struct SP_EFFECT_SET_PARAM_ST;
struct SP_EFFECT_VFX_PARAM_ST;
struct SWORD_ARTS_PARAM_ST;
struct TALK_PARAM_ST;
struct THROW_DIRECTION_SFX_PARAM_ST;
struct THROW_PARAM_ST;
struct TOUGHNESS_PARAM_ST;
struct TUTORIAL_PARAM_ST;
struct WAYPOINT_PARAM_ST;
struct WEATHER_ASSET_CREATE_PARAM_ST;
struct WEATHER_ASSET_REPLACE_PARAM_ST;
struct WEATHER_LOT_PARAM_ST;
struct WEATHER_LOT_TEX_PARAM_ST;
struct WEATHER_LOT_TEX_PARAM_ST_DLC02;
struct WEATHER_PARAM_ST;
struct WEP_ABSORP_POS_PARAM_ST;
struct WET_ASPECT_PARAM_ST;
struct WHITE_SIGN_COOL_TIME_PARAM_ST;
struct WORLD_MAP_LEGACY_CONV_PARAM_ST;
struct WORLD_MAP_PIECE_PARAM_ST;
struct WORLD_MAP_PLACE_NAME_PARAM_ST;
struct WORLD_MAP_POINT_PARAM_ST;
struct WWISE_VALUE_TO_STR_CONVERT_PARAM_ST;
}
}
}

namespace eldenring {
namespace position {
struct BlockPosition;
struct DirectionalVector;
struct HavokPosition;
struct PositionDelta;
}
}

namespace eldenring {
namespace rotation {
struct EulerAngles;
struct Quaternion;
}
}

namespace eldenring {
namespace rva {
namespace bundle {
struct RvaBundle;
}
}
}

namespace eldenring {
namespace shared {
namespace dl_math {
namespace linear {
struct Aabb;
struct Frustum;
struct Line;
struct Lss;
struct Obb;
struct Plane;
struct Ray;
struct Rectangle;
struct Rss;
struct Segment;
struct Sphere;
struct Triangle;
struct Triangle3;
}
}
}
}

namespace eldenring {
namespace shared {
namespace dl_math {
namespace matrix {
struct F32Matrix2x2;
struct F32Matrix2x3;
struct F32Matrix2x4;
struct F32Matrix3x2;
struct F32Matrix3x3;
struct F32Matrix3x4;
struct F32Matrix4x2;
struct F32Matrix4x3;
struct F32Matrix4x4;
}
}
}
}

namespace eldenring {
namespace shared {
namespace dl_math {
namespace special {
struct F32ModelMatrix;
struct F32PackedModelMatrix;
}
}
}
}

namespace eldenring {
namespace shared {
namespace dl_math {
namespace vector {
struct F32Vector2;
struct F32Vector3;
struct F32Vector4;
}
}
}
}

namespace eldenring {
namespace shared {
namespace empty {
template <typename T>
struct MaybeEmpty;
template <typename E, typename I>
struct NonEmptyIter;
template <typename E, typename I>
struct NonEmptyIterMut;
}
}
}

namespace eldenring {
namespace shared {
namespace kw_static {
enum class InstanceError;
}
}
}

namespace eldenring {
namespace shared {
namespace owned_pointer {
template <typename T>
struct OwnedPtr;
}
}
}

namespace eldenring {
namespace shared {
namespace program {
enum class Program;
}
}
}

namespace eldenring {
namespace shared {
namespace rtti {
template <typename T>
struct Class;
}
}
}

namespace eldenring {
namespace shared {
namespace steam {
struct CCallback;
}
}
}

namespace eldenring {
namespace shared {
namespace subclass {
struct TryFromSuperclassError;
}
}
}

namespace eldenring {
namespace shared {
namespace task {
template <typename TTaskData>
struct RecurringTask;
template <typename TTaskData>
struct RecurringTaskHandle;
}
}
}

namespace eldenring {
namespace shared {
namespace util {
namespace incomplete_array_field {
template <typename T>
struct IncompleteArrayField;
}
}
}
}

namespace eldenring {
namespace shared {
namespace util {
namespace unknown_struct {
template <typename N>
struct UnknownStruct;
}
}
}
}

namespace eldenring {
namespace stl {
struct AllocationHeader;
template <typename T>
struct ArrayWithHeader;
template <typename T>
struct BasicVector;
template <typename T, typename N>
struct CSFixedList;
template <typename T>
struct CSFixedListEntry;
template <typename T>
struct ChainingMapBucketEntry;
template <typename K, typename V>
struct ChainingTree;
template <typename T>
struct DoublyLinkedList;
template <typename T>
struct DoublyLinkedListNode;
template <typename K, typename V>
struct Pair;
template <typename T>
struct Tree;
template <typename T>
struct TreeNode;
template <typename T>
struct Vector;
}
}

namespace eldenring {
namespace util {
namespace system {
enum class SystemInitError;
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
using ActionTimers = eldenring::cs::chr_ins::module::action_request::ActionTimers;
using AiActionCancels = eldenring::cs::chr_ins::module::action_request::AiActionCancels;
using CSChrActionFlagModule = eldenring::cs::chr_ins::module::action_flag::CSChrActionFlagModule;
using CSChrActionRequestModule = eldenring::cs::chr_ins::module::action_request::CSChrActionRequestModule;
using CSChrBehaviorDataModule = eldenring::cs::chr_ins::module::behavior_data::CSChrBehaviorDataModule;
using CSChrBehaviorModule = eldenring::cs::chr_ins::module::behavior::CSChrBehaviorModule;
using CSChrDataModule = eldenring::cs::chr_ins::module::data::CSChrDataModule;
using CSChrEventModule = eldenring::cs::chr_ins::module::event::CSChrEventModule;
using CSChrFallModule = eldenring::cs::chr_ins::module::fall::CSChrFallModule;
using CSChrGrassHitModule = eldenring::cs::chr_ins::module::grass_hit::CSChrGrassHitModule;
using CSChrMaterialModule = eldenring::cs::chr_ins::module::material::CSChrMaterialModule;
using CSChrModelParamModifierModule = eldenring::cs::chr_ins::module::model_param_modifier::CSChrModelParamModifierModule;
using CSChrModelParamModifierModuleEntry = eldenring::cs::chr_ins::module::model_param_modifier::CSChrModelParamModifierModuleEntry;
using CSChrModelParamModifierModuleEntryValue = eldenring::cs::chr_ins::module::model_param_modifier::CSChrModelParamModifierModuleEntryValue;
using CSChrPhysicsModule = eldenring::cs::chr_ins::module::physics::CSChrPhysicsModule;
using CSChrRideModule = eldenring::cs::chr_ins::module::ride::CSChrRideModule;
using CSChrRideModuleMountData = eldenring::cs::chr_ins::module::ride::CSChrRideModuleMountData;
using CSChrSuperArmorModule = eldenring::cs::chr_ins::module::super_armor::CSChrSuperArmorModule;
using CSChrThrowModule = eldenring::cs::chr_ins::module::kw_throw::CSChrThrowModule;
using CSChrTimeActModule = eldenring::cs::chr_ins::module::time_act::CSChrTimeActModule;
using CSChrTimeActModuleAnim = eldenring::cs::chr_ins::module::time_act::CSChrTimeActModuleAnim;
using CSChrToughnessModule = eldenring::cs::chr_ins::module::toughness::CSChrToughnessModule;
using CSChrWetModule = eldenring::cs::chr_ins::module::wet::CSChrWetModule;
using CSRideNode = eldenring::cs::chr_ins::module::ride::CSRideNode;
using CSThrowNode = eldenring::cs::chr_ins::module::kw_throw::CSThrowNode;
using ChrActionAnimationFlags = eldenring::cs::chr_ins::module::action_flag::ChrActionAnimationFlags;
using ChrActionModifiersFlags = eldenring::cs::chr_ins::module::action_flag::ChrActionModifiersFlags;
using ChrActions = eldenring::cs::chr_ins::module::action_request::ChrActions;
using ChrPhysicsMaterialInfo = eldenring::cs::chr_ins::module::physics::ChrPhysicsMaterialInfo;
using ChrPhysicsSlideInfo = eldenring::cs::chr_ins::module::physics::ChrPhysicsSlideInfo;
using EnableTwistModifierArgs = eldenring::cs::chr_ins::module::behavior_data::EnableTwistModifierArgs;
using MoveTypeFlags = eldenring::cs::chr_ins::module::physics::MoveTypeFlags;
using SpEffectWetConditionDepth = eldenring::cs::chr_ins::module::action_flag::SpEffectWetConditionDepth;
using ThrowModuleFlags = eldenring::cs::chr_ins::module::kw_throw::ThrowModuleFlags;
using ThrowNodeState = eldenring::cs::chr_ins::module::kw_throw::ThrowNodeState;
using TwistModifierBehaviorData = eldenring::cs::chr_ins::module::behavior_data::TwistModifierBehaviorData;
using WeaponModelChangeType = eldenring::cs::chr_ins::module::action_flag::WeaponModelChangeType;
}
}
}
}

namespace eldenring {
namespace shared {
namespace dl_math {
namespace special {
using F32ViewMatrix = eldenring::shared::dl_math::special::F32ModelMatrix;
}
}
}
}

namespace eldenring {
namespace cs {
namespace camera {
using CSPersCam = eldenring::cs::camera::CSCam;
}
}
}

namespace eldenring {
namespace cs {
namespace chr_ins {
using ActionTimers = eldenring::cs::chr_ins::module::action_request::ActionTimers;
using AiActionCancels = eldenring::cs::chr_ins::module::action_request::AiActionCancels;
using CSChrActionFlagModule = eldenring::cs::chr_ins::module::action_flag::CSChrActionFlagModule;
using CSChrActionRequestModule = eldenring::cs::chr_ins::module::action_request::CSChrActionRequestModule;
using CSChrBehaviorDataModule = eldenring::cs::chr_ins::module::behavior_data::CSChrBehaviorDataModule;
using CSChrBehaviorModule = eldenring::cs::chr_ins::module::behavior::CSChrBehaviorModule;
using CSChrDataModule = eldenring::cs::chr_ins::module::data::CSChrDataModule;
using CSChrEventModule = eldenring::cs::chr_ins::module::event::CSChrEventModule;
using CSChrFallModule = eldenring::cs::chr_ins::module::fall::CSChrFallModule;
using CSChrGrassHitModule = eldenring::cs::chr_ins::module::grass_hit::CSChrGrassHitModule;
using CSChrMaterialModule = eldenring::cs::chr_ins::module::material::CSChrMaterialModule;
using CSChrModelParamModifierModule = eldenring::cs::chr_ins::module::model_param_modifier::CSChrModelParamModifierModule;
using CSChrModelParamModifierModuleEntry = eldenring::cs::chr_ins::module::model_param_modifier::CSChrModelParamModifierModuleEntry;
using CSChrModelParamModifierModuleEntryValue = eldenring::cs::chr_ins::module::model_param_modifier::CSChrModelParamModifierModuleEntryValue;
using CSChrPhysicsModule = eldenring::cs::chr_ins::module::physics::CSChrPhysicsModule;
using CSChrRideModule = eldenring::cs::chr_ins::module::ride::CSChrRideModule;
using CSChrRideModuleMountData = eldenring::cs::chr_ins::module::ride::CSChrRideModuleMountData;
using CSChrSuperArmorModule = eldenring::cs::chr_ins::module::super_armor::CSChrSuperArmorModule;
using CSChrThrowModule = eldenring::cs::chr_ins::module::kw_throw::CSChrThrowModule;
using CSChrTimeActModule = eldenring::cs::chr_ins::module::time_act::CSChrTimeActModule;
using CSChrTimeActModuleAnim = eldenring::cs::chr_ins::module::time_act::CSChrTimeActModuleAnim;
using CSChrToughnessModule = eldenring::cs::chr_ins::module::toughness::CSChrToughnessModule;
using CSChrWetModule = eldenring::cs::chr_ins::module::wet::CSChrWetModule;
using CSRideNode = eldenring::cs::chr_ins::module::ride::CSRideNode;
using CSThrowNode = eldenring::cs::chr_ins::module::kw_throw::CSThrowNode;
using ChrActionAnimationFlags = eldenring::cs::chr_ins::module::action_flag::ChrActionAnimationFlags;
using ChrActionModifiersFlags = eldenring::cs::chr_ins::module::action_flag::ChrActionModifiersFlags;
using ChrActions = eldenring::cs::chr_ins::module::action_request::ChrActions;
using ChrInsModuleContainer = eldenring::cs::chr_ins::module::ChrInsModuleContainer;
using ChrPhysicsMaterialInfo = eldenring::cs::chr_ins::module::physics::ChrPhysicsMaterialInfo;
using ChrPhysicsSlideInfo = eldenring::cs::chr_ins::module::physics::ChrPhysicsSlideInfo;
using EnableTwistModifierArgs = eldenring::cs::chr_ins::module::behavior_data::EnableTwistModifierArgs;
using MoveTypeFlags = eldenring::cs::chr_ins::module::physics::MoveTypeFlags;
using SpEffectWetConditionDepth = eldenring::cs::chr_ins::module::action_flag::SpEffectWetConditionDepth;
using ThrowModuleFlags = eldenring::cs::chr_ins::module::kw_throw::ThrowModuleFlags;
using ThrowNodeState = eldenring::cs::chr_ins::module::kw_throw::ThrowNodeState;
using TwistModifierBehaviorData = eldenring::cs::chr_ins::module::behavior_data::TwistModifierBehaviorData;
using WeaponModelChangeType = eldenring::cs::chr_ins::module::action_flag::WeaponModelChangeType;
}
}
}

namespace eldenring {
namespace shared {
namespace dl_math {
using Aabb = eldenring::shared::dl_math::linear::Aabb;
using F32Matrix2x2 = eldenring::shared::dl_math::matrix::F32Matrix2x2;
using F32Matrix2x3 = eldenring::shared::dl_math::matrix::F32Matrix2x3;
using F32Matrix2x4 = eldenring::shared::dl_math::matrix::F32Matrix2x4;
using F32Matrix3x2 = eldenring::shared::dl_math::matrix::F32Matrix3x2;
using F32Matrix3x3 = eldenring::shared::dl_math::matrix::F32Matrix3x3;
using F32Matrix3x4 = eldenring::shared::dl_math::matrix::F32Matrix3x4;
using F32Matrix4x2 = eldenring::shared::dl_math::matrix::F32Matrix4x2;
using F32Matrix4x3 = eldenring::shared::dl_math::matrix::F32Matrix4x3;
using F32Matrix4x4 = eldenring::shared::dl_math::matrix::F32Matrix4x4;
using F32ModelMatrix = eldenring::shared::dl_math::special::F32ModelMatrix;
using F32PackedModelMatrix = eldenring::shared::dl_math::special::F32PackedModelMatrix;
using F32Vector2 = eldenring::shared::dl_math::vector::F32Vector2;
using F32Vector3 = eldenring::shared::dl_math::vector::F32Vector3;
using F32Vector4 = eldenring::shared::dl_math::vector::F32Vector4;
using F32ViewMatrix = eldenring::shared::dl_math::special::F32ViewMatrix;
using Frustum = eldenring::shared::dl_math::linear::Frustum;
using Line = eldenring::shared::dl_math::linear::Line;
using Lss = eldenring::shared::dl_math::linear::Lss;
using Obb = eldenring::shared::dl_math::linear::Obb;
using Plane = eldenring::shared::dl_math::linear::Plane;
using Ray = eldenring::shared::dl_math::linear::Ray;
using Rectangle = eldenring::shared::dl_math::linear::Rectangle;
using Rss = eldenring::shared::dl_math::linear::Rss;
using Segment = eldenring::shared::dl_math::linear::Segment;
using Sphere = eldenring::shared::dl_math::linear::Sphere;
using Triangle = eldenring::shared::dl_math::linear::Triangle;
using Triangle3 = eldenring::shared::dl_math::linear::Triangle3;
}
}
}

namespace eldenring {
namespace shared {
namespace util {
template <typename T>
using IncompleteArrayField = eldenring::shared::util::incomplete_array_field::IncompleteArrayField<T>;
template <typename N>
using UnknownStruct = eldenring::shared::util::unknown_struct::UnknownStruct<N>;
}
}
}

namespace eldenring {
namespace cs {
using ActionTimers = eldenring::cs::chr_ins::module::action_request::ActionTimers;
using AiActionCancels = eldenring::cs::chr_ins::module::action_request::AiActionCancels;
using AiSightTimeOfDay = eldenring::cs::world_area_time::AiSightTimeOfDay;
using AtkParamLookupResult = eldenring::cs::chr_ins::AtkParamLookupResult;
using AutoInvadePoint = eldenring::cs::auto_invade_point::AutoInvadePoint;
using AutoInvadePointBlockEntry = eldenring::cs::auto_invade_point::AutoInvadePointBlockEntry;
using BackScreenData = eldenring::cs::menu_man::BackScreenData;
using BlockId = eldenring::cs::block_id::BlockId;
using BossHealthDisplayEntry = eldenring::cs::fe_man::BossHealthDisplayEntry;
using BrokenEquipmentSlots = eldenring::cs::player_game_data::BrokenEquipmentSlots;
template <typename T, typename BUFFER_SIZE, typename MAX_ALLOCS>
using BufferAndAllocLinkedList = eldenring::cs::bullet_manager::BufferAndAllocLinkedList<T, BUFFER_SIZE, MAX_ALLOCS>;
using BulletParamLookupResult = eldenring::cs::bullet_ins::BulletParamLookupResult;
using BulletPhysics = eldenring::cs::bullet_ins::BulletPhysics;
using BulletSpawnData = eldenring::cs::bullet_manager::BulletSpawnData;
using CSActionButtonManImp = eldenring::cs::action_button::CSActionButtonManImp;
using CSAiTargetingSystemOwner = eldenring::cs::targeting::CSAiTargetingSystemOwner;
using CSAutoInvadePoint = eldenring::cs::auto_invade_point::CSAutoInvadePoint;
using CSBattleRoyalContext = eldenring::cs::net_man::CSBattleRoyalContext;
using CSBuddyStoneEliminateTargetCalc = eldenring::cs::world_chr_man::CSBuddyStoneEliminateTargetCalc;
using CSBulletExplosionState = eldenring::cs::bullet_ins::CSBulletExplosionState;
using CSBulletFlyState = eldenring::cs::bullet_ins::CSBulletFlyState;
using CSBulletIns = eldenring::cs::bullet_ins::CSBulletIns;
using CSBulletManager = eldenring::cs::bullet_manager::CSBulletManager;
using CSBulletNULLState = eldenring::cs::bullet_ins::CSBulletNULLState;
using CSBulletState = eldenring::cs::bullet_ins::CSBulletState;
using CSBulletTargetingSystemOwner = eldenring::cs::targeting::CSBulletTargetingSystemOwner;
using CSBulletWaitState = eldenring::cs::bullet_ins::CSBulletWaitState;
using CSCam = eldenring::cs::camera::CSCam;
using CSCamera = eldenring::cs::camera::CSCamera;
using CSChrActionFlagModule = eldenring::cs::chr_ins::module::action_flag::CSChrActionFlagModule;
using CSChrActionRequestModule = eldenring::cs::chr_ins::module::action_request::CSChrActionRequestModule;
using CSChrBehaviorDataModule = eldenring::cs::chr_ins::module::behavior_data::CSChrBehaviorDataModule;
using CSChrBehaviorModule = eldenring::cs::chr_ins::module::behavior::CSChrBehaviorModule;
using CSChrDataModule = eldenring::cs::chr_ins::module::data::CSChrDataModule;
using CSChrEventModule = eldenring::cs::chr_ins::module::event::CSChrEventModule;
using CSChrFallModule = eldenring::cs::chr_ins::module::fall::CSChrFallModule;
using CSChrGrassHitModule = eldenring::cs::chr_ins::module::grass_hit::CSChrGrassHitModule;
using CSChrMaterialModule = eldenring::cs::chr_ins::module::material::CSChrMaterialModule;
using CSChrMenuFlags = eldenring::cs::menu_man::CSChrMenuFlags;
using CSChrModelIns = eldenring::cs::chr_ins::CSChrModelIns;
using CSChrModelParamModifierModule = eldenring::cs::chr_ins::module::model_param_modifier::CSChrModelParamModifierModule;
using CSChrModelParamModifierModuleEntry = eldenring::cs::chr_ins::module::model_param_modifier::CSChrModelParamModifierModuleEntry;
using CSChrModelParamModifierModuleEntryValue = eldenring::cs::chr_ins::module::model_param_modifier::CSChrModelParamModifierModuleEntryValue;
using CSChrPhysicsModule = eldenring::cs::chr_ins::module::physics::CSChrPhysicsModule;
using CSChrRideModule = eldenring::cs::chr_ins::module::ride::CSChrRideModule;
using CSChrRideModuleMountData = eldenring::cs::chr_ins::module::ride::CSChrRideModuleMountData;
using CSChrSuperArmorModule = eldenring::cs::chr_ins::module::super_armor::CSChrSuperArmorModule;
using CSChrThrowModule = eldenring::cs::chr_ins::module::kw_throw::CSChrThrowModule;
using CSChrTimeActModule = eldenring::cs::chr_ins::module::time_act::CSChrTimeActModule;
using CSChrTimeActModuleAnim = eldenring::cs::chr_ins::module::time_act::CSChrTimeActModuleAnim;
using CSChrToughnessModule = eldenring::cs::chr_ins::module::toughness::CSChrToughnessModule;
using CSChrWetModule = eldenring::cs::chr_ins::module::wet::CSChrWetModule;
using CSDebugChrCreator = eldenring::cs::world_chr_man::CSDebugChrCreator;
using CSDebugChrCreatorInitData = eldenring::cs::world_chr_man::CSDebugChrCreatorInitData;
using CSEventFlagMan = eldenring::cs::event_flag::CSEventFlagMan;
using CSEventManImp = eldenring::cs::event_man::CSEventManImp;
using CSEventSosSignCtrl = eldenring::cs::event_man::CSEventSosSignCtrl;
using CSEventWorldAreaTimeCtrl = eldenring::cs::event_man::CSEventWorldAreaTimeCtrl;
using CSEzDraw = eldenring::cs::rend_man::CSEzDraw;
using CSEzRabbitNoUpdateTask = eldenring::cs::task::CSEzRabbitNoUpdateTask;
using CSEzRabbitTask = eldenring::cs::task::CSEzRabbitTask;
using CSEzRabbitTaskBase = eldenring::cs::task::CSEzRabbitTaskBase;
using CSEzSelectBot = eldenring::cs::ez_select_bot::CSEzSelectBot;
using CSEzStateTalkEnv = eldenring::cs::ez_state_talk::CSEzStateTalkEnv;
using CSEzStateTalkEvent = eldenring::cs::ez_state_talk::CSEzStateTalkEvent;
using CSEzTask = eldenring::cs::task::CSEzTask;
using CSEzTaskProxy = eldenring::cs::task::CSEzTaskProxy;
template <typename TEzTask, typename TSubject>
using CSEzUpdateTask = eldenring::cs::task::CSEzUpdateTask<TEzTask, TSubject>;
template <typename TEzTask, typename TSubject>
using CSEzVoidTask = eldenring::cs::task::CSEzVoidTask<TEzTask, TSubject>;
using CSFD4FadePlate = eldenring::cs::fade::CSFD4FadePlate;
using CSFD4FadePlateColor = eldenring::cs::fade::CSFD4FadePlateColor;
using CSFD4FadeSystem = eldenring::cs::fade::CSFD4FadeSystem;
using CSFD4LocationGxModelMatricesAndAabbExporter = eldenring::cs::chr_ins::CSFD4LocationGxModelMatricesAndAabbExporter;
using CSFD4LocationNode = eldenring::cs::location::CSFD4LocationNode;
using CSFD4LocationPose = eldenring::cs::location::CSFD4LocationPose;
using CSFD4ModelItem = eldenring::cs::chr_ins::CSFD4ModelItem;
using CSFD4SceneDrawParam = eldenring::cs::world_scene_draw_param_manager::CSFD4SceneDrawParam;
using CSFD4VirtualMemoryFlag = eldenring::cs::event_flag::CSFD4VirtualMemoryFlag;
using CSFade = eldenring::cs::fade::CSFade;
using CSFeManHudState = eldenring::cs::fe_man::CSFeManHudState;
using CSFeManImp = eldenring::cs::fe_man::CSFeManImp;
using CSFeSpiritAshDisplay = eldenring::cs::fe_man::CSFeSpiritAshDisplay;
using CSFileImp = eldenring::cs::file::CSFileImp;
using CSFileRepository = eldenring::cs::file::CSFileRepository;
using CSFileRepositoryMutex = eldenring::cs::file::CSFileRepositoryMutex;
using CSFlipper = eldenring::cs::flipper::CSFlipper;
using CSFlipperVsyncHistoryEntry = eldenring::cs::flipper::CSFlipperVsyncHistoryEntry;
using CSGaitemGameData = eldenring::cs::gaitem::CSGaitemGameData;
using CSGaitemGameDataEntry = eldenring::cs::gaitem::CSGaitemGameDataEntry;
using CSGaitemImp = eldenring::cs::gaitem::CSGaitemImp;
using CSGaitemImpEntry = eldenring::cs::gaitem::CSGaitemImpEntry;
using CSGaitemIns = eldenring::cs::gaitem::CSGaitemIns;
using CSGemGaitemIns = eldenring::cs::gaitem::CSGemGaitemIns;
using CSGemSlot = eldenring::cs::gaitem::CSGemSlot;
using CSGemSlotTable = eldenring::cs::gaitem::CSGemSlotTable;
using CSGparamIdLerper = eldenring::cs::world_scene_draw_param_manager::CSGparamIdLerper;
using CSHavokMan = eldenring::cs::havok_man::CSHavokMan;
using CSMenuData = eldenring::cs::menu_man::CSMenuData;
using CSMenuGaitemUseState = eldenring::cs::menu_man::CSMenuGaitemUseState;
using CSMenuManImp = eldenring::cs::menu_man::CSMenuManImp;
using CSModelIns = eldenring::cs::chr_ins::CSModelIns;
using CSMsbParts = eldenring::cs::world_geom_man::CSMsbParts;
using CSMsbPartsEne = eldenring::cs::world_geom_man::CSMsbPartsEne;
using CSMsbPartsGeom = eldenring::cs::world_geom_man::CSMsbPartsGeom;
using CSNetBloodMessageDb = eldenring::cs::net_man::CSNetBloodMessageDb;
using CSNetBloodMessageDbItem = eldenring::cs::net_man::CSNetBloodMessageDbItem;
using CSNetMan = eldenring::cs::net_man::CSNetMan;
using CSNowLoadingHelper = eldenring::cs::now_loading::CSNowLoadingHelper;
using CSNpcTalkIns = eldenring::cs::talk_script::CSNpcTalkIns;
using CSPairAnimManager = eldenring::cs::pair_anim::CSPairAnimManager;
using CSPairAnimManager20Entry = eldenring::cs::pair_anim::CSPairAnimManager20Entry;
using CSPairAnimNode = eldenring::cs::pair_anim::CSPairAnimNode;
using CSPersCam = eldenring::cs::camera::CSPersCam;
using CSPhysWorld = eldenring::cs::havok_man::CSPhysWorld;
using CSPlayerMenuCtrl = eldenring::cs::menu_man::CSPlayerMenuCtrl;
using CSPopupMenu = eldenring::cs::menu_man::CSPopupMenu;
using CSQuickMatchContext = eldenring::cs::net_man::CSQuickMatchContext;
using CSQuickMatchingCtrl = eldenring::cs::net_man::CSQuickMatchingCtrl;
using CSQuickMatchingCtrlState = eldenring::cs::net_man::CSQuickMatchingCtrlState;
using CSRand = eldenring::cs::cs_rand::CSRand;
using CSRandSFMT = eldenring::cs::cs_rand::CSRandSFMT;
using CSRandXorshift = eldenring::cs::cs_rand::CSRandXorshift;
using CSRideNode = eldenring::cs::chr_ins::module::ride::CSRideNode;
using CSSessionManager = eldenring::cs::session_manager::CSSessionManager;
using CSSessionManager0x20 = eldenring::cs::session_manager::CSSessionManager0x20;
using CSSessionManagerP2PInboundQueueStats = eldenring::cs::session_manager::CSSessionManagerP2PInboundQueueStats;
using CSSessionManagerP2PSendQueue = eldenring::cs::session_manager::CSSessionManagerP2PSendQueue;
using CSSessionManagerP2PSendQueueEntry = eldenring::cs::session_manager::CSSessionManagerP2PSendQueueEntry;
using CSSfxImp = eldenring::cs::sfx::CSSfxImp;
using CSSosSignMan = eldenring::cs::sos_sign_man::CSSosSignMan;
using CSSosSignSfx = eldenring::cs::sos_sign_man::CSSosSignSfx;
using CSStayInMultiplayAreaWarpData = eldenring::cs::session_manager::CSStayInMultiplayAreaWarpData;
using CSTalkIns = eldenring::cs::talk_script::CSTalkIns;
using CSTargetSearchSys = eldenring::cs::targeting::CSTargetSearchSys;
using CSTargetingSystemBase = eldenring::cs::targeting::CSTargetingSystemBase;
using CSTargetingSystemOwner = eldenring::cs::targeting::CSTargetingSystemOwner;
using CSTask = eldenring::cs::task::CSTask;
using CSTaskBase = eldenring::cs::task::CSTaskBase;
using CSTaskGroup = eldenring::cs::task::CSTaskGroup;
using CSTaskGroupIndex = eldenring::cs::task::CSTaskGroupIndex;
using CSTaskGroupIns = eldenring::cs::task::CSTaskGroupIns;
using CSTaskImp = eldenring::cs::task::CSTaskImp;
using CSTaskRunner = eldenring::cs::task::CSTaskRunner;
using CSTaskRunnerEx = eldenring::cs::task::CSTaskRunnerEx;
using CSTaskRunnerManager = eldenring::cs::task::CSTaskRunnerManager;
using CSTeamTypeBase = eldenring::cs::team_relation::CSTeamTypeBase;
using CSTeamTypeEnemy = eldenring::cs::team_relation::CSTeamTypeEnemy;
using CSTeamTypeFriend = eldenring::cs::team_relation::CSTeamTypeFriend;
using CSTeamTypeNeutral = eldenring::cs::team_relation::CSTeamTypeNeutral;
using CSTeamTypeRival = eldenring::cs::team_relation::CSTeamTypeRival;
using CSThrowNode = eldenring::cs::chr_ins::module::kw_throw::CSThrowNode;
using CSTimeLineTaskGroupIns = eldenring::cs::task::CSTimeLineTaskGroupIns;
using CSTrophy = eldenring::cs::trophy::CSTrophy;
using CSTrophyPlatformImp = eldenring::cs::trophy::CSTrophyPlatformImp;
using CSTrophyPlatformImp_forSteam = eldenring::cs::trophy::CSTrophyPlatformImp_forSteam;
using CSTrophyPlatformImp_forSteamAchievementItem = eldenring::cs::trophy::CSTrophyPlatformImp_forSteamAchievementItem;
using CSTrophyTitleInfo = eldenring::cs::trophy::CSTrophyTitleInfo;
using CSWepGaitemIns = eldenring::cs::gaitem::CSWepGaitemIns;
using CSWindowImp = eldenring::cs::window::CSWindowImp;
using CSWindowScreenConfig = eldenring::cs::window::CSWindowScreenConfig;
using CSWindowType = eldenring::cs::window::CSWindowType;
using CSWorldAreaBlockSceneDrawParam = eldenring::cs::world_scene_draw_param_manager::CSWorldAreaBlockSceneDrawParam;
using CSWorldGeomInfo = eldenring::cs::world_geom_man::CSWorldGeomInfo;
using CSWorldGeomInfoUnk = eldenring::cs::world_geom_man::CSWorldGeomInfoUnk;
using CSWorldGeomIns = eldenring::cs::world_geom_man::CSWorldGeomIns;
using CSWorldGeomMan = eldenring::cs::world_geom_man::CSWorldGeomMan;
using CSWorldGeomManBlockData = eldenring::cs::world_geom_man::CSWorldGeomManBlockData;
using CSWorldGeomManBlocksEntry = eldenring::cs::world_geom_man::CSWorldGeomManBlocksEntry;
using CSWorldSceneDrawParamManager = eldenring::cs::world_scene_draw_param_manager::CSWorldSceneDrawParamManager;
using CeremonyState = eldenring::cs::party_member_info::CeremonyState;
using CharacterTypePropertiesEntry = eldenring::cs::character_type_properties::CharacterTypePropertiesEntry;
using CharacterTypePropertiesTable = eldenring::cs::character_type_properties::CharacterTypePropertiesTable;
using ChrActionAnimationFlags = eldenring::cs::chr_ins::module::action_flag::ChrActionAnimationFlags;
using ChrActionModifiersFlags = eldenring::cs::chr_ins::module::action_flag::ChrActionModifiersFlags;
using ChrActions = eldenring::cs::chr_ins::module::action_request::ChrActions;
using ChrAsm = eldenring::cs::player_game_data::ChrAsm;
using ChrAsmArmStyle = eldenring::cs::player_game_data::ChrAsmArmStyle;
using ChrAsmEquipEntries = eldenring::cs::player_game_data::ChrAsmEquipEntries;
using ChrAsmEquipment = eldenring::cs::player_game_data::ChrAsmEquipment;
using ChrAsmEquipmentSlots = eldenring::cs::player_game_data::ChrAsmEquipmentSlots;
using ChrAsmSlot = eldenring::cs::player_game_data::ChrAsmSlot;
using ChrAsmSlotError = eldenring::cs::player_game_data::ChrAsmSlotError;
using ChrCam = eldenring::cs::camera::ChrCam;
using ChrCamType = eldenring::cs::camera::ChrCamType;
using ChrCtrl = eldenring::cs::chr_ins::ChrCtrl;
using ChrCtrlChrProxyFlags = eldenring::cs::chr_ins::ChrCtrlChrProxyFlags;
using ChrCtrlFlags = eldenring::cs::chr_ins::ChrCtrlFlags;
using ChrCtrlModifier = eldenring::cs::chr_ins::ChrCtrlModifier;
using ChrCtrlModifierActionFlags = eldenring::cs::chr_ins::ChrCtrlModifierActionFlags;
using ChrCtrlModifierData = eldenring::cs::chr_ins::ChrCtrlModifierData;
using ChrCtrlModifierHksFlags = eldenring::cs::chr_ins::ChrCtrlModifierHksFlags;
using ChrDebugFlags = eldenring::cs::chr_ins::ChrDebugFlags;
using ChrDebugSpawnRequest = eldenring::cs::world_chr_man::ChrDebugSpawnRequest;
using ChrEnemyTagEntry = eldenring::cs::fe_man::ChrEnemyTagEntry;
using ChrFriendTagEntry = eldenring::cs::fe_man::ChrFriendTagEntry;
using ChrIns = eldenring::cs::chr_ins::ChrIns;
using ChrInsActivationFlags = eldenring::cs::chr_ins::ChrInsActivationFlags;
using ChrInsDistanceEntry = eldenring::cs::world_chr_man::ChrInsDistanceEntry;
using ChrInsFlags1c4 = eldenring::cs::chr_ins::ChrInsFlags1c4;
using ChrInsFlags1c5 = eldenring::cs::chr_ins::ChrInsFlags1c5;
using ChrInsFlags1c6 = eldenring::cs::chr_ins::ChrInsFlags1c6;
using ChrInsFlags1c7 = eldenring::cs::chr_ins::ChrInsFlags1c7;
using ChrInsFlags1c8 = eldenring::cs::chr_ins::ChrInsFlags1c8;
using ChrInsFlags1ca = eldenring::cs::chr_ins::ChrInsFlags1ca;
using ChrInsModuleContainer = eldenring::cs::chr_ins::module::ChrInsModuleContainer;
using ChrLoadStatus = eldenring::cs::world_chr_man::ChrLoadStatus;
using ChrManipulator = eldenring::cs::chr_manipulator::ChrManipulator;
using ChrMenuFlags = eldenring::cs::menu_man::ChrMenuFlags;
using ChrMovementLimit = eldenring::cs::chr_ins::ChrMovementLimit;
using ChrPhysicsMaterialInfo = eldenring::cs::chr_ins::module::physics::ChrPhysicsMaterialInfo;
using ChrPhysicsSlideInfo = eldenring::cs::chr_ins::module::physics::ChrPhysicsSlideInfo;
template <typename T>
using ChrSet = eldenring::cs::world_chr_man::ChrSet<T>;
template <typename T>
using ChrSetEntityIdMapping = eldenring::cs::world_chr_man::ChrSetEntityIdMapping<T>;
template <typename T>
using ChrSetEntry = eldenring::cs::world_chr_man::ChrSetEntry<T>;
template <typename T>
using ChrSetGroupMapping = eldenring::cs::world_chr_man::ChrSetGroupMapping<T>;
template <typename T>
using ChrSetHolder = eldenring::cs::world_chr_man::ChrSetHolder<T>;
using ChrSlotBase = eldenring::cs::chr_slot::ChrSlotBase;
using ChrSyncHealthUpdate = eldenring::cs::net_chr_sync::ChrSyncHealthUpdate;
using ChrSyncPlacementUpdate = eldenring::cs::net_chr_sync::ChrSyncPlacementUpdate;
using ChrSyncUpdateFlags = eldenring::cs::net_chr_sync::ChrSyncUpdateFlags;
using ChrType = eldenring::cs::chr_ins::ChrType;
using ChrUpdateType = eldenring::cs::world_chr_man::ChrUpdateType;
using DLRandomGeneratorSFMT = eldenring::cs::cs_rand::DLRandomGeneratorSFMT;
using DLRandomGeneratorXorshift = eldenring::cs::cs_rand::DLRandomGeneratorXorshift;
using DeathState = eldenring::cs::game_data_man::DeathState;
using DisplayBlood = eldenring::cs::game_data_man::DisplayBlood;
using DisplayGhostData = eldenring::cs::sos_sign_man::DisplayGhostData;
using DlColor32 = eldenring::cs::rend_man::DlColor32;
using EnableTwistModifierArgs = eldenring::cs::chr_ins::module::behavior_data::EnableTwistModifierArgs;
using EnemyIns = eldenring::cs::chr_ins::EnemyIns;
using EquipDataItem = eldenring::cs::player_game_data::EquipDataItem;
using EquipGameData = eldenring::cs::player_game_data::EquipGameData;
using EquipInventoryData = eldenring::cs::player_game_data::EquipInventoryData;
using EquipInventoryDataListEntry = eldenring::cs::player_game_data::EquipInventoryDataListEntry;
using EquipItemData = eldenring::cs::player_game_data::EquipItemData;
using EquipMagicData = eldenring::cs::player_game_data::EquipMagicData;
using EquipMagicItem = eldenring::cs::player_game_data::EquipMagicItem;
using EquipmentDurabilityStatus = eldenring::cs::player_game_data::EquipmentDurabilityStatus;
using EventFlag = eldenring::cs::event_flag::EventFlag;
using EventWorldType = eldenring::cs::game_man::EventWorldType;
using EzDrawFillMode = eldenring::cs::rend_man::EzDrawFillMode;
using EzDrawFlags = eldenring::cs::rend_man::EzDrawFlags;
using EzDrawTextCoordMode = eldenring::cs::rend_man::EzDrawTextCoordMode;
using EzStateInvokeError = eldenring::cs::talk_script::EzStateInvokeError;
using FD4EzDrawState = eldenring::cs::rend_man::FD4EzDrawState;
using FD4HkEzDrawCommandBuffer = eldenring::cs::rend_man::FD4HkEzDrawCommandBuffer;
using FD4HkEzDrawContext = eldenring::cs::rend_man::FD4HkEzDrawContext;
using FD4HkEzDrawState = eldenring::cs::rend_man::FD4HkEzDrawState;
using FaceData = eldenring::cs::player_game_data::FaceData;
using FaceDataBuffer = eldenring::cs::player_game_data::FaceDataBuffer;
using FeSystemAnnounceViewModel = eldenring::cs::menu_man::FeSystemAnnounceViewModel;
using FeSystemAnnounceViewModelMessageQueue = eldenring::cs::menu_man::FeSystemAnnounceViewModelMessageQueue;
using FieldArea = eldenring::cs::field_area::FieldArea;
using FieldInsHandle = eldenring::cs::field_ins::FieldInsHandle;
using FieldInsSelector = eldenring::cs::field_ins::FieldInsSelector;
using FieldInsType = eldenring::cs::field_ins::FieldInsType;
using FixOrderJobSequenceBase = eldenring::cs::job::FixOrderJobSequenceBase;
using FlagBlock = eldenring::cs::event_flag::FlagBlock;
using FlagBlockDescriptor = eldenring::cs::event_flag::FlagBlockDescriptor;
using FlagBlockLocation = eldenring::cs::event_flag::FlagBlockLocation;
using FlipMode = eldenring::cs::flipper::FlipMode;
using ForceCamRotationMethod = eldenring::cs::game_man::ForceCamRotationMethod;
using FpsTarget = eldenring::cs::window::FpsTarget;
using FrontEndView = eldenring::cs::fe_man::FrontEndView;
using FrontEndViewValues = eldenring::cs::fe_man::FrontEndViewValues;
using FullScreenMessage = eldenring::cs::fe_man::FullScreenMessage;
using GaitemCategory = eldenring::cs::gaitem::GaitemCategory;
using GaitemHandle = eldenring::cs::gaitem::GaitemHandle;
using GaitemHandleError = eldenring::cs::gaitem::GaitemHandleError;
using GameDataMan = eldenring::cs::game_data_man::GameDataMan;
using GameMan = eldenring::cs::game_man::GameMan;
using GameSettings = eldenring::cs::game_data_man::GameSettings;
using GameVersionData = eldenring::cs::game_data_man::GameVersionData;
using GeometrySpawnParameters = eldenring::cs::world_geom_man::GeometrySpawnParameters;
using GeometrySpawnRequest = eldenring::cs::world_geom_man::GeometrySpawnRequest;
using GrassQuality = eldenring::cs::window::GrassQuality;
using HandIndex = eldenring::cs::chr_ins::HandIndex;
using HudType = eldenring::cs::game_data_man::HudType;
using IChrFinder = eldenring::cs::world_chr_man::IChrFinder;
using InventoryItemListAccessor = eldenring::cs::player_game_data::InventoryItemListAccessor;
using InventoryItemsData = eldenring::cs::player_game_data::InventoryItemsData;
using ItemCategory = eldenring::cs::item_id::ItemCategory;
using ItemId = eldenring::cs::item_id::ItemId;
using ItemIdError = eldenring::cs::item_id::ItemIdError;
using ItemIdMapping = eldenring::cs::player_game_data::ItemIdMapping;
using ItemLotUtil = eldenring::cs::item_lot::ItemLotUtil;
using ItemReplenishStateEntry = eldenring::cs::player_game_data::ItemReplenishStateEntry;
using ItemReplenishStateEntryUnk = eldenring::cs::player_game_data::ItemReplenishStateEntryUnk;
using ItemReplenishStateTracker = eldenring::cs::player_game_data::ItemReplenishStateTracker;
using JoinType = eldenring::cs::multiplay_type::JoinType;
using LastAddItemResult = eldenring::cs::player_game_data::LastAddItemResult;
using LoadingScreenData = eldenring::cs::menu_man::LoadingScreenData;
using LobbyState = eldenring::cs::session_manager::LobbyState;
using ManipulatorType = eldenring::cs::chr_manipulator::ManipulatorType;
using MapItemMan = eldenring::cs::item::MapItemMan;
using MatchingCooldownType = eldenring::cs::multiplay_type::MatchingCooldownType;
using MemberType = eldenring::cs::party_member_info::MemberType;
using MenuJobBase = eldenring::cs::job::MenuJobBase;
using MenuJobResult = eldenring::cs::job::MenuJobResult;
using MenuString = eldenring::cs::fe_man::MenuString;
using MenuType = eldenring::cs::menu_type::MenuType;
using MoveTypeFlags = eldenring::cs::chr_ins::module::physics::MoveTypeFlags;
using MsbFileCap = eldenring::cs::msb::MsbFileCap;
using MsbPart = eldenring::cs::world_geom_man::MsbPart;
using MsbRepository = eldenring::cs::msb::MsbRepository;
using MultiplayProperties = eldenring::cs::multiplay_type::MultiplayProperties;
using MultiplayPropertyEntry = eldenring::cs::multiplay_type::MultiplayPropertyEntry;
using MultiplayPropertyEntryFlags = eldenring::cs::multiplay_type::MultiplayPropertyEntryFlags;
using MultiplayRole = eldenring::cs::multiplay_type::MultiplayRole;
using MultiplayType = eldenring::cs::multiplay_type::MultiplayType;
using NearEnemyFinder = eldenring::cs::world_chr_man::NearEnemyFinder;
using NetChrSetSync = eldenring::cs::net_chr_sync::NetChrSetSync;
using NetChrSync = eldenring::cs::net_chr_sync::NetChrSync;
using NetChrSyncFlags = eldenring::cs::chr_ins::NetChrSyncFlags;
using NpcMenuState = eldenring::cs::talk_script::NpcMenuState;
using NpcSpEffectEquipCtrl = eldenring::cs::sp_effect::NpcSpEffectEquipCtrl;
using NpcThinkParamLookupResult = eldenring::cs::targeting::NpcThinkParamLookupResult;
using ObjectIdentifier = eldenring::cs::sos_sign_man::ObjectIdentifier;
using OmissionMode = eldenring::cs::chr_ins::OmissionMode;
using OmissionUpdateNum = eldenring::cs::world_chr_man_dbg::OmissionUpdateNum;
using OmissionUpdateNumType = eldenring::cs::world_chr_man_dbg::OmissionUpdateNumType;
using OnOffSetting = eldenring::cs::window::OnOffSetting;
using OpenFieldChrSet = eldenring::cs::world_chr_man::OpenFieldChrSet;
using OpenFieldChrSetList1Entry = eldenring::cs::world_chr_man::OpenFieldChrSetList1Entry;
using OpenFieldChrSetList2Entry = eldenring::cs::world_chr_man::OpenFieldChrSetList2Entry;
using OpenMenuJob = eldenring::cs::talk_script::OpenMenuJob;
using OptionalItemId = eldenring::cs::item_id::OptionalItemId;
using P2PEntityHandle = eldenring::cs::chr_ins::P2PEntityHandle;
using P2PEntitySelector = eldenring::cs::chr_ins::P2PEntitySelector;
using PartyMemberEntryState = eldenring::cs::party_member_info::PartyMemberEntryState;
using PartyMemberInfo = eldenring::cs::party_member_info::PartyMemberInfo;
using PartyMemberInfoEntry = eldenring::cs::party_member_info::PartyMemberInfoEntry;
using PerformanceSetting = eldenring::cs::game_data_man::PerformanceSetting;
using PhantomJoinData = eldenring::cs::sos_sign_man::PhantomJoinData;
using PhantomJoinState = eldenring::cs::sos_sign_man::PhantomJoinState;
using PlayerDataAttackRating = eldenring::cs::player_game_data::PlayerDataAttackRating;
using PlayerDataInvasionItemType = eldenring::cs::player_game_data::PlayerDataInvasionItemType;
using PlayerGameData = eldenring::cs::player_game_data::PlayerGameData;
using PlayerGameDataFrontendFlags = eldenring::cs::player_game_data::PlayerGameDataFrontendFlags;
using PlayerGameDataSpEffect = eldenring::cs::player_game_data::PlayerGameDataSpEffect;
using PlayerIns = eldenring::cs::chr_ins::PlayerIns;
using PlayerNetworkSession = eldenring::cs::network_session::PlayerNetworkSession;
using PlayerSession = eldenring::cs::network_session::PlayerSession;
using PlayerSessionHolder = eldenring::cs::chr_ins::PlayerSessionHolder;
using ProtocolState = eldenring::cs::session_manager::ProtocolState;
using QMItemBackupVectorItem = eldenring::cs::player_game_data::QMItemBackupVectorItem;
using QualityLevelSetting = eldenring::cs::window::QualityLevelSetting;
using QualitySetting = eldenring::cs::window::QualitySetting;
using QuickMatchArena = eldenring::cs::net_man::QuickMatchArena;
using QuickMatchSettings = eldenring::cs::net_man::QuickMatchSettings;
using QuickMatchVenue = eldenring::cs::net_man::QuickMatchVenue;
using QuickmatchManager = eldenring::cs::net_man::QuickmatchManager;
using QuickmatchParticipant = eldenring::cs::net_man::QuickmatchParticipant;
using QuickmatchSpawnData = eldenring::cs::net_man::QuickmatchSpawnData;
using ReceivePacketAllocation = eldenring::cs::network_session::ReceivePacketAllocation;
using ReceivedPacketReader = eldenring::cs::network_session::ReceivedPacketReader;
using RemotePlayerDataSlotState = eldenring::cs::game_data_man::RemotePlayerDataSlotState;
using RendMan = eldenring::cs::rend_man::RendMan;
using ReplayRecorder = eldenring::cs::chr_ins::ReplayRecorder;
using SellRegion = eldenring::cs::player_game_data::SellRegion;
using SessionManagerPlayerEntry = eldenring::cs::session_manager::SessionManagerPlayerEntry;
using SessionManagerPlayerEntryBase = eldenring::cs::session_manager::SessionManagerPlayerEntryBase;
using SignTreeEntry = eldenring::cs::sos_sign_man::SignTreeEntry;
using SosSignData = eldenring::cs::sos_sign_man::SosSignData;
using SpEffectEquipCtrl = eldenring::cs::sp_effect::SpEffectEquipCtrl;
using SpEffectWetConditionDepth = eldenring::cs::chr_ins::module::action_flag::SpEffectWetConditionDepth;
using SpecialEffect = eldenring::cs::sp_effect::SpecialEffect;
using SpecialEffectEntry = eldenring::cs::sp_effect::SpecialEffectEntry;
using SpecialEffectEntryAccumulatorInfo = eldenring::cs::sp_effect::SpecialEffectEntryAccumulatorInfo;
using StayInMultiplayFadeTrackerEntry = eldenring::cs::session_manager::StayInMultiplayFadeTrackerEntry;
using SteamIdStr = eldenring::cs::sos_sign_man::SteamIdStr;
using SummonBuddyGroup = eldenring::cs::world_chr_man::SummonBuddyGroup;
using SummonBuddyGroupEntry = eldenring::cs::world_chr_man::SummonBuddyGroupEntry;
using SummonBuddyManager = eldenring::cs::world_chr_man::SummonBuddyManager;
using SummonBuddyStoneEliminateTargetEntry = eldenring::cs::world_chr_man::SummonBuddyStoneEliminateTargetEntry;
using SummonBuddyWarpEntry = eldenring::cs::world_chr_man::SummonBuddyWarpEntry;
using SummonBuddyWarpManager = eldenring::cs::world_chr_man::SummonBuddyWarpManager;
using SummonBuddyWarpStage = eldenring::cs::world_chr_man::SummonBuddyWarpStage;
using SummonJobErrorCode = eldenring::cs::sos_sign_man::SummonJobErrorCode;
using SummonMsgData = eldenring::cs::fe_man::SummonMsgData;
using SummonMsgQueue = eldenring::cs::fe_man::SummonMsgQueue;
using SummonParamType = eldenring::cs::multiplay_type::SummonParamType;
using TagHudData = eldenring::cs::fe_man::TagHudData;
using TalkScript = eldenring::cs::talk_script::TalkScript;
using TalkScriptMachineHolder = eldenring::cs::talk_script::TalkScriptMachineHolder;
using TaskGroupConcurrency = eldenring::cs::task::TaskGroupConcurrency;
using TaskGroupConcurrencySlot = eldenring::cs::task::TaskGroupConcurrencySlot;
using TaskGroupEntry = eldenring::cs::task::TaskGroupEntry;
using TeamRelationTargetInfo = eldenring::cs::team_relation::TeamRelationTargetInfo;
using ThrowModuleFlags = eldenring::cs::chr_ins::module::kw_throw::ThrowModuleFlags;
using ThrowNodeState = eldenring::cs::chr_ins::module::kw_throw::ThrowNodeState;
using TimeTransitionParams = eldenring::cs::event_man::TimeTransitionParams;
using ToggleableGraphicsQuality = eldenring::cs::window::ToggleableGraphicsQuality;
using TwistModifierBehaviorData = eldenring::cs::chr_ins::module::behavior_data::TwistModifierBehaviorData;
using WeaponModelChangeType = eldenring::cs::chr_ins::module::action_flag::WeaponModelChangeType;
template <typename T>
using WorldAreaChr = eldenring::cs::world_chr_man::WorldAreaChr<T>;
using WorldAreaChrBase = eldenring::cs::world_chr_man::WorldAreaChrBase;
using WorldAreaInfo = eldenring::cs::field_area::WorldAreaInfo;
using WorldAreaInfoBase = eldenring::cs::field_area::WorldAreaInfoBase;
using WorldAreaSfx = eldenring::cs::world_sfx_man::WorldAreaSfx;
using WorldAreaSfxBase = eldenring::cs::world_sfx_man::WorldAreaSfxBase;
using WorldAreaTime = eldenring::cs::world_area_time::WorldAreaTime;
template <typename T>
using WorldBlockChr = eldenring::cs::world_chr_man::WorldBlockChr<T>;
using WorldBlockInfo = eldenring::cs::field_area::WorldBlockInfo;
using WorldBlockInfoCeremony = eldenring::cs::field_area::WorldBlockInfoCeremony;
using WorldBlockSfx = eldenring::cs::world_sfx_man::WorldBlockSfx;
using WorldChrMan = eldenring::cs::world_chr_man::WorldChrMan;
using WorldChrManDbg = eldenring::cs::world_chr_man_dbg::WorldChrManDbg;
using WorldChrManDbgFlags = eldenring::cs::world_chr_man_dbg::WorldChrManDbgFlags;
using WorldGridAreaChr = eldenring::cs::world_chr_man::WorldGridAreaChr;
using WorldGridAreaInfo = eldenring::cs::field_area::WorldGridAreaInfo;
using WorldGridAreaInfoBlockElement = eldenring::cs::field_area::WorldGridAreaInfoBlockElement;
using WorldGridAreaSfx = eldenring::cs::world_sfx_man::WorldGridAreaSfx;
using WorldInfo = eldenring::cs::field_area::WorldInfo;
using WorldInfoOwner = eldenring::cs::field_area::WorldInfoOwner;
using WorldRes = eldenring::cs::field_area::WorldRes;
using WorldSfxMan = eldenring::cs::world_sfx_man::WorldSfxMan;
}
}

namespace eldenring {
namespace dlio {
template <typename R>
using AdapterFileOperator = eldenring::dlio::file_device::AdapterFileOperator<R>;
using BndEntry = eldenring::dlio::file_device::BndEntry;
using DLBufferedInputStream = eldenring::dlio::stream::DLBufferedInputStream;
using DLFileDeviceBase = eldenring::dlio::file_device::DLFileDeviceBase;
using DLFileDeviceDriveType = eldenring::dlio::file_device::DLFileDeviceDriveType;
using DLFileDeviceImageSPIBase = eldenring::dlio::file_device::DLFileDeviceImageSPIBase;
using DLFileDeviceManager = eldenring::dlio::file_device::DLFileDeviceManager;
using DLFileEnumeratorSPIBase = eldenring::dlio::file_device::DLFileEnumeratorSPIBase;
using DLFileInputStream = eldenring::dlio::stream::DLFileInputStream;
template <typename T>
using DLFileOperatorBase = eldenring::dlio::file_device::DLFileOperatorBase<T>;
using DLFileOperatorContainer = eldenring::dlio::file_device::DLFileOperatorContainer;
using DLFileOperatorIOState = eldenring::dlio::file_device::DLFileOperatorIOState;
using DLFileOutputStream = eldenring::dlio::stream::DLFileOutputStream;
using DLFileSeekDirection = eldenring::dlio::common::DLFileSeekDirection;
using DLIOResult = eldenring::dlio::common::DLIOResult;
using DLMemoryInputStream = eldenring::dlio::stream::DLMemoryInputStream;
using DLMemoryOutputStream = eldenring::dlio::stream::DLMemoryOutputStream;
using DLPseudoAsyncInputStream = eldenring::dlio::stream::DLPseudoAsyncInputStream;
using DLStreamBuffer = eldenring::dlio::stream::DLStreamBuffer;
using OpenFileMode = eldenring::dlio::common::OpenFileMode;
}
}

namespace eldenring {
namespace dlkr {
using DLAllocatorBase = eldenring::dlkr::allocator::DLAllocatorBase;
using DLAllocatorRef = eldenring::dlkr::allocator::DLAllocatorRef;
using DLPlainConditionSignal = eldenring::dlkr::signal::DLPlainConditionSignal;
using DLPlainLightMutex = eldenring::dlkr::mutex::DLPlainLightMutex;
}
}

namespace eldenring {
namespace dltx {
template <typename T>
using DLCodedString = eldenring::dltx::DLRawString<T>;
}
}

namespace eldenring {
namespace ez_state {
using EzStateEnvironmentQuery = eldenring::ez_state::environment_query::EzStateEnvironmentQuery;
using EzStateEvent = eldenring::ez_state::event::EzStateEvent;
using EzStateRawValue = eldenring::ez_state::value::EzStateRawValue;
using EzStateValue = eldenring::ez_state::value::EzStateValue;
}
}

namespace eldenring {
namespace fd4 {
template <typename T>
using FD4BasicHashString = eldenring::fd4::basic_hash_string::FD4BasicHashString<T>;
using FD4FileCap = eldenring::fd4::resource::FD4FileCap;
using FD4FileCapState = eldenring::fd4::resource::FD4FileCapState;
using FD4FileCapUnk89Properties = eldenring::fd4::resource::FD4FileCapUnk89Properties;
using FD4FileCapUnk8AProperties = eldenring::fd4::resource::FD4FileCapUnk8AProperties;
using FD4ParamRepository = eldenring::fd4::param_repository::FD4ParamRepository;
using FD4ParamResCap = eldenring::fd4::param_repository::FD4ParamResCap;
using FD4ResCap = eldenring::fd4::resource::FD4ResCap;
template <typename T>
using FD4ResCapHolder = eldenring::fd4::resource::FD4ResCapHolder<T>;
template <typename T>
using FD4ResRep = eldenring::fd4::resource::FD4ResRep<T>;
using FD4SlotInsBase = eldenring::fd4::slot::FD4SlotInsBase;
using FD4SlotSysBase = eldenring::fd4::slot::FD4SlotSysBase;
template <typename N, typename T>
using FD4StepBaseInterface = eldenring::fd4::step::FD4StepBaseInterface<N, T>;
template <typename N, typename T>
using FD4StepTemplateBase = eldenring::fd4::step::FD4StepTemplateBase<N, T>;
using FD4StepTemplateBase0x18 = eldenring::fd4::step::FD4StepTemplateBase0x18;
using FD4TaskBase = eldenring::fd4::task::FD4TaskBase;
using FD4TaskData = eldenring::fd4::task::FD4TaskData;
using FD4TaskGroup = eldenring::fd4::task::FD4TaskGroup;
using FD4TaskQueue = eldenring::fd4::task::FD4TaskQueue;
using FD4TaskRequestEntry = eldenring::fd4::task::FD4TaskRequestEntry;
using FD4Time = eldenring::fd4::time::FD4Time;
using ParamFile = eldenring::fd4::param_repository::ParamFile;
template <typename O>
using RowDescriptor = eldenring::fd4::param_repository::RowDescriptor<O>;
template <typename T>
using StepperFn = eldenring::fd4::step::StepperFn<T>;
}
}

namespace eldenring {
namespace param {
using ACTIONBUTTON_PARAM_ST = eldenring::param::generated::ACTIONBUTTON_PARAM_ST;
using AI_SOUND_PARAM_ST = eldenring::param::generated::AI_SOUND_PARAM_ST;
using ASSET_GEOMETORY_PARAM_ST = eldenring::param::generated::ASSET_GEOMETORY_PARAM_ST;
using ASSET_MATERIAL_SFX_PARAM_ST = eldenring::param::generated::ASSET_MATERIAL_SFX_PARAM_ST;
using ASSET_MODEL_SFX_PARAM_ST = eldenring::param::generated::ASSET_MODEL_SFX_PARAM_ST;
using ATK_PARAM_ST = eldenring::param::generated::ATK_PARAM_ST;
using ATTACK_ELEMENT_CORRECT_PARAM_ST = eldenring::param::generated::ATTACK_ELEMENT_CORRECT_PARAM_ST;
using AUTO_CREATE_ENV_SOUND_PARAM_ST = eldenring::param::generated::AUTO_CREATE_ENV_SOUND_PARAM_ST;
using BASECHR_SELECT_MENU_PARAM_ST = eldenring::param::generated::BASECHR_SELECT_MENU_PARAM_ST;
using BEHAVIOR_PARAM_ST = eldenring::param::generated::BEHAVIOR_PARAM_ST;
using BONFIRE_WARP_PARAM_ST = eldenring::param::generated::BONFIRE_WARP_PARAM_ST;
using BONFIRE_WARP_SUB_CATEGORY_PARAM_ST = eldenring::param::generated::BONFIRE_WARP_SUB_CATEGORY_PARAM_ST;
using BONFIRE_WARP_TAB_PARAM_ST = eldenring::param::generated::BONFIRE_WARP_TAB_PARAM_ST;
using BUDDY_PARAM_ST = eldenring::param::generated::BUDDY_PARAM_ST;
using BUDDY_STONE_PARAM_ST = eldenring::param::generated::BUDDY_STONE_PARAM_ST;
using BUDGET_PARAM_ST = eldenring::param::generated::BUDGET_PARAM_ST;
using BULLET_CREATE_LIMIT_PARAM_ST = eldenring::param::generated::BULLET_CREATE_LIMIT_PARAM_ST;
using BULLET_PARAM_ST = eldenring::param::generated::BULLET_PARAM_ST;
using CACL_CORRECT_GRAPH_ST = eldenring::param::generated::CACL_CORRECT_GRAPH_ST;
using CAMERA_FADE_PARAM_ST = eldenring::param::generated::CAMERA_FADE_PARAM_ST;
using CEREMONY_PARAM_ST = eldenring::param::generated::CEREMONY_PARAM_ST;
using CHARACTER_INIT_PARAM = eldenring::param::generated::CHARACTER_INIT_PARAM;
using CHARMAKEMENUTOP_PARAM_ST = eldenring::param::generated::CHARMAKEMENUTOP_PARAM_ST;
using CHARMAKEMENU_LISTITEM_PARAM_ST = eldenring::param::generated::CHARMAKEMENU_LISTITEM_PARAM_ST;
using CHR_ACTIVATE_CONDITION_PARAM_ST = eldenring::param::generated::CHR_ACTIVATE_CONDITION_PARAM_ST;
using CHR_EQUIP_MODEL_PARAM_ST = eldenring::param::generated::CHR_EQUIP_MODEL_PARAM_ST;
using CHR_MODEL_PARAM_ST = eldenring::param::generated::CHR_MODEL_PARAM_ST;
using CLEAR_COUNT_CORRECT_PARAM_ST = eldenring::param::generated::CLEAR_COUNT_CORRECT_PARAM_ST;
using COMMON_SYSTEM_PARAM_ST = eldenring::param::generated::COMMON_SYSTEM_PARAM_ST;
using COOL_TIME_PARAM_ST = eldenring::param::generated::COOL_TIME_PARAM_ST;
using CS_AA_QUALITY_DETAIL = eldenring::param::generated::CS_AA_QUALITY_DETAIL;
using CS_DECAL_QUALITY_DETAIL = eldenring::param::generated::CS_DECAL_QUALITY_DETAIL;
using CS_DOF_QUALITY_DETAIL = eldenring::param::generated::CS_DOF_QUALITY_DETAIL;
using CS_EFFECT_QUALITY_DETAIL = eldenring::param::generated::CS_EFFECT_QUALITY_DETAIL;
using CS_GRAPHICS_CONFIG_PARAM_ST = eldenring::param::generated::CS_GRAPHICS_CONFIG_PARAM_ST;
using CS_KEY_ASSIGN_MENUITEM_PARAM = eldenring::param::generated::CS_KEY_ASSIGN_MENUITEM_PARAM;
using CS_LIGHTING_QUALITY_DETAIL = eldenring::param::generated::CS_LIGHTING_QUALITY_DETAIL;
using CS_MOTION_BLUR_QUALITY_DETAIL = eldenring::param::generated::CS_MOTION_BLUR_QUALITY_DETAIL;
using CS_RAYTRACING_QUALITY_DETAIL = eldenring::param::generated::CS_RAYTRACING_QUALITY_DETAIL;
using CS_REFLECTION_QUALITY_DETAIL = eldenring::param::generated::CS_REFLECTION_QUALITY_DETAIL;
using CS_SHADER_QUALITY_DETAIL = eldenring::param::generated::CS_SHADER_QUALITY_DETAIL;
using CS_SHADOW_QUALITY_DETAIL = eldenring::param::generated::CS_SHADOW_QUALITY_DETAIL;
using CS_SSAO_QUALITY_DETAIL = eldenring::param::generated::CS_SSAO_QUALITY_DETAIL;
using CS_TEXTURE_FILTER_QUALITY_DETAIL = eldenring::param::generated::CS_TEXTURE_FILTER_QUALITY_DETAIL;
using CS_VOLUMETRIC_EFFECT_QUALITY_DETAIL = eldenring::param::generated::CS_VOLUMETRIC_EFFECT_QUALITY_DETAIL;
using CS_WATER_QUALITY_DETAIL = eldenring::param::generated::CS_WATER_QUALITY_DETAIL;
using CUTSCENE_GPARAM_TIME_PARAM_ST = eldenring::param::generated::CUTSCENE_GPARAM_TIME_PARAM_ST;
using CUTSCENE_GPARAM_WEATHER_PARAM_ST = eldenring::param::generated::CUTSCENE_GPARAM_WEATHER_PARAM_ST;
using CUTSCENE_MAP_ID_PARAM_ST = eldenring::param::generated::CUTSCENE_MAP_ID_PARAM_ST;
using CUTSCENE_TEXTURE_LOAD_PARAM_ST = eldenring::param::generated::CUTSCENE_TEXTURE_LOAD_PARAM_ST;
using CUTSCENE_TIMEZONE_CONVERT_PARAM_ST = eldenring::param::generated::CUTSCENE_TIMEZONE_CONVERT_PARAM_ST;
using CUTSCENE_WEATHER_OVERRIDE_GPARAM_ID_CONVERT_PARAM_ST = eldenring::param::generated::CUTSCENE_WEATHER_OVERRIDE_GPARAM_ID_CONVERT_PARAM_ST;
using DECAL_PARAM_ST = eldenring::param::generated::DECAL_PARAM_ST;
using DEFAULT_KEY_ASSIGN = eldenring::param::generated::DEFAULT_KEY_ASSIGN;
using DIRECTION_CAMERA_PARAM_ST = eldenring::param::generated::DIRECTION_CAMERA_PARAM_ST;
using ENEMY_COMMON_PARAM_ST = eldenring::param::generated::ENEMY_COMMON_PARAM_ST;
using ENV_OBJ_LOT_PARAM_ST = eldenring::param::generated::ENV_OBJ_LOT_PARAM_ST;
using EQUIP_MTRL_SET_PARAM_ST = eldenring::param::generated::EQUIP_MTRL_SET_PARAM_ST;
using EQUIP_PARAM_ACCESSORY_ST = eldenring::param::generated::EQUIP_PARAM_ACCESSORY_ST;
using EQUIP_PARAM_CUSTOM_WEAPON_ST = eldenring::param::generated::EQUIP_PARAM_CUSTOM_WEAPON_ST;
using EQUIP_PARAM_GEM_ST = eldenring::param::generated::EQUIP_PARAM_GEM_ST;
using EQUIP_PARAM_GOODS_ST = eldenring::param::generated::EQUIP_PARAM_GOODS_ST;
using EQUIP_PARAM_PROTECTOR_ST = eldenring::param::generated::EQUIP_PARAM_PROTECTOR_ST;
using EQUIP_PARAM_WEAPON_ST = eldenring::param::generated::EQUIP_PARAM_WEAPON_ST;
using ESTUS_FLASK_RECOVERY_PARAM_ST = eldenring::param::generated::ESTUS_FLASK_RECOVERY_PARAM_ST;
using FACE_PARAM_ST = eldenring::param::generated::FACE_PARAM_ST;
using FACE_RANGE_PARAM_ST = eldenring::param::generated::FACE_RANGE_PARAM_ST;
using FE_TEXT_EFFECT_PARAM_ST = eldenring::param::generated::FE_TEXT_EFFECT_PARAM_ST;
using FINAL_DAMAGE_RATE_PARAM_ST = eldenring::param::generated::FINAL_DAMAGE_RATE_PARAM_ST;
using FOOT_SFX_PARAM_ST = eldenring::param::generated::FOOT_SFX_PARAM_ST;
using GAME_AREA_PARAM_ST = eldenring::param::generated::GAME_AREA_PARAM_ST;
using GAME_SYSTEM_COMMON_PARAM_ST = eldenring::param::generated::GAME_SYSTEM_COMMON_PARAM_ST;
using GESTURE_PARAM_ST = eldenring::param::generated::GESTURE_PARAM_ST;
using GPARAM_REF_SETTINGS_PARAM_ST = eldenring::param::generated::GPARAM_REF_SETTINGS_PARAM_ST;
using GRAPHICS_COMMON_PARAM_ST = eldenring::param::generated::GRAPHICS_COMMON_PARAM_ST;
using GRASS_LOD_RANGE_PARAM_ST = eldenring::param::generated::GRASS_LOD_RANGE_PARAM_ST;
using GRASS_TYPE_PARAM_ST = eldenring::param::generated::GRASS_TYPE_PARAM_ST;
using HIT_EFFECT_SE_PARAM_ST = eldenring::param::generated::HIT_EFFECT_SE_PARAM_ST;
using HIT_EFFECT_SFX_CONCEPT_PARAM_ST = eldenring::param::generated::HIT_EFFECT_SFX_CONCEPT_PARAM_ST;
using HIT_EFFECT_SFX_PARAM_ST = eldenring::param::generated::HIT_EFFECT_SFX_PARAM_ST;
using HIT_MTRL_PARAM_ST = eldenring::param::generated::HIT_MTRL_PARAM_ST;
using ITEMLOT_PARAM_ST = eldenring::param::generated::ITEMLOT_PARAM_ST;
using KEY_ASSIGN_PARAM_ST = eldenring::param::generated::KEY_ASSIGN_PARAM_ST;
using KNOCKBACK_PARAM_ST = eldenring::param::generated::KNOCKBACK_PARAM_ST;
using KNOWLEDGE_LOADSCREEN_ITEM_PARAM_ST = eldenring::param::generated::KNOWLEDGE_LOADSCREEN_ITEM_PARAM_ST;
using LEGACY_DISTANT_VIEW_PARTS_REPLACE_PARAM = eldenring::param::generated::LEGACY_DISTANT_VIEW_PARTS_REPLACE_PARAM;
using LOAD_BALANCER_DRAW_DIST_SCALE_PARAM_ST = eldenring::param::generated::LOAD_BALANCER_DRAW_DIST_SCALE_PARAM_ST;
using LOAD_BALANCER_NEW_DRAW_DIST_SCALE_PARAM_ST = eldenring::param::generated::LOAD_BALANCER_NEW_DRAW_DIST_SCALE_PARAM_ST;
using LOAD_BALANCER_PARAM_ST = eldenring::param::generated::LOAD_BALANCER_PARAM_ST;
using LOCK_CAM_PARAM_ST = eldenring::param::generated::LOCK_CAM_PARAM_ST;
using MAGIC_PARAM_ST = eldenring::param::generated::MAGIC_PARAM_ST;
using MAP_DEFAULT_INFO_PARAM_ST = eldenring::param::generated::MAP_DEFAULT_INFO_PARAM_ST;
using MAP_GD_REGION_DRAW_PARAM = eldenring::param::generated::MAP_GD_REGION_DRAW_PARAM;
using MAP_GD_REGION_ID_PARAM_ST = eldenring::param::generated::MAP_GD_REGION_ID_PARAM_ST;
using MAP_GRID_CREATE_HEIGHT_LIMIT_DETAIL_INFO_PARAM_ST = eldenring::param::generated::MAP_GRID_CREATE_HEIGHT_LIMIT_DETAIL_INFO_PARAM_ST;
using MAP_GRID_CREATE_HEIGHT_LIMIT_INFO_PARAM_ST = eldenring::param::generated::MAP_GRID_CREATE_HEIGHT_LIMIT_INFO_PARAM_ST;
using MAP_MIMICRY_ESTABLISHMENT_PARAM_ST = eldenring::param::generated::MAP_MIMICRY_ESTABLISHMENT_PARAM_ST;
using MAP_NAME_TEX_PARAM_ST = eldenring::param::generated::MAP_NAME_TEX_PARAM_ST;
using MAP_NAME_TEX_PARAM_ST_DLC02 = eldenring::param::generated::MAP_NAME_TEX_PARAM_ST_DLC02;
using MAP_PIECE_TEX_PARAM_ST = eldenring::param::generated::MAP_PIECE_TEX_PARAM_ST;
using MAP_PIECE_TEX_PARAM_ST_DLC02 = eldenring::param::generated::MAP_PIECE_TEX_PARAM_ST_DLC02;
using MATERIAL_EX_PARAM_ST = eldenring::param::generated::MATERIAL_EX_PARAM_ST;
using MENUPROPERTY_LAYOUT = eldenring::param::generated::MENUPROPERTY_LAYOUT;
using MENUPROPERTY_SPEC = eldenring::param::generated::MENUPROPERTY_SPEC;
using MENU_COMMON_PARAM_ST = eldenring::param::generated::MENU_COMMON_PARAM_ST;
using MENU_OFFSCR_REND_PARAM_ST = eldenring::param::generated::MENU_OFFSCR_REND_PARAM_ST;
using MENU_PARAM_COLOR_TABLE_ST = eldenring::param::generated::MENU_PARAM_COLOR_TABLE_ST;
using MENU_VALUE_TABLE_SPEC = eldenring::param::generated::MENU_VALUE_TABLE_SPEC;
using MIMICRY_ESTABLISHMENT_TEX_PARAM_ST = eldenring::param::generated::MIMICRY_ESTABLISHMENT_TEX_PARAM_ST;
using MIMICRY_ESTABLISHMENT_TEX_PARAM_ST_DLC02 = eldenring::param::generated::MIMICRY_ESTABLISHMENT_TEX_PARAM_ST_DLC02;
using MOVE_PARAM_ST = eldenring::param::generated::MOVE_PARAM_ST;
using MULTI_ESTUS_FLASK_BONUS_PARAM_ST = eldenring::param::generated::MULTI_ESTUS_FLASK_BONUS_PARAM_ST;
using MULTI_PLAY_CORRECTION_PARAM_ST = eldenring::param::generated::MULTI_PLAY_CORRECTION_PARAM_ST;
using MULTI_SOUL_BONUS_RATE_PARAM_ST = eldenring::param::generated::MULTI_SOUL_BONUS_RATE_PARAM_ST;
using NETWORK_AREA_PARAM_ST = eldenring::param::generated::NETWORK_AREA_PARAM_ST;
using NETWORK_MSG_PARAM_ST = eldenring::param::generated::NETWORK_MSG_PARAM_ST;
using NETWORK_PARAM_ST = eldenring::param::generated::NETWORK_PARAM_ST;
using NPC_AI_ACTION_PARAM_ST = eldenring::param::generated::NPC_AI_ACTION_PARAM_ST;
using NPC_AI_BEHAVIOR_PROBABILITY_PARAM_ST = eldenring::param::generated::NPC_AI_BEHAVIOR_PROBABILITY_PARAM_ST;
using NPC_PARAM_ST = eldenring::param::generated::NPC_PARAM_ST;
using NPC_THINK_PARAM_ST = eldenring::param::generated::NPC_THINK_PARAM_ST;
using OBJ_ACT_PARAM_ST = eldenring::param::generated::OBJ_ACT_PARAM_ST;
using PARTS_DRAW_PARAM_ST = eldenring::param::generated::PARTS_DRAW_PARAM_ST;
using PHANTOM_PARAM_ST = eldenring::param::generated::PHANTOM_PARAM_ST;
using PLAYER_COMMON_PARAM_ST = eldenring::param::generated::PLAYER_COMMON_PARAM_ST;
using PLAY_REGION_PARAM_ST = eldenring::param::generated::PLAY_REGION_PARAM_ST;
using POSTURE_CONTROL_PARAM_GENDER_ST = eldenring::param::generated::POSTURE_CONTROL_PARAM_GENDER_ST;
using POSTURE_CONTROL_PARAM_PRO_ST = eldenring::param::generated::POSTURE_CONTROL_PARAM_PRO_ST;
using POSTURE_CONTROL_PARAM_WEP_LEFT_ST = eldenring::param::generated::POSTURE_CONTROL_PARAM_WEP_LEFT_ST;
using POSTURE_CONTROL_PARAM_WEP_RIGHT_ST = eldenring::param::generated::POSTURE_CONTROL_PARAM_WEP_RIGHT_ST;
using RANDOM_APPEAR_PARAM_ST = eldenring::param::generated::RANDOM_APPEAR_PARAM_ST;
using REINFORCE_PARAM_PROTECTOR_ST = eldenring::param::generated::REINFORCE_PARAM_PROTECTOR_ST;
using REINFORCE_PARAM_WEAPON_ST = eldenring::param::generated::REINFORCE_PARAM_WEAPON_ST;
using RESIST_CORRECT_PARAM_ST = eldenring::param::generated::RESIST_CORRECT_PARAM_ST;
using REVERB_AUX_SEND_BUS_PARAM_ST = eldenring::param::generated::REVERB_AUX_SEND_BUS_PARAM_ST;
using RIDE_PARAM_ST = eldenring::param::generated::RIDE_PARAM_ST;
using ROLE_PARAM_ST = eldenring::param::generated::ROLE_PARAM_ST;
using ROLLING_OBJ_LOT_PARAM_ST = eldenring::param::generated::ROLLING_OBJ_LOT_PARAM_ST;
using RUNTIME_BONE_CONTROL_PARAM_ST = eldenring::param::generated::RUNTIME_BONE_CONTROL_PARAM_ST;
using SE_ACTIVATION_RANGE_PARAM_ST = eldenring::param::generated::SE_ACTIVATION_RANGE_PARAM_ST;
using SE_MATERIAL_CONVERT_PARAM_ST = eldenring::param::generated::SE_MATERIAL_CONVERT_PARAM_ST;
using SFX_BLOCK_RES_SHARE_PARAM = eldenring::param::generated::SFX_BLOCK_RES_SHARE_PARAM;
using SHOP_LINEUP_PARAM = eldenring::param::generated::SHOP_LINEUP_PARAM;
using SIGN_PUDDLE_PARAM_ST = eldenring::param::generated::SIGN_PUDDLE_PARAM_ST;
using SIGN_PUDDLE_SUB_CATEGORY_PARAM_ST = eldenring::param::generated::SIGN_PUDDLE_SUB_CATEGORY_PARAM_ST;
using SIGN_PUDDLE_TAB_PARAM_ST = eldenring::param::generated::SIGN_PUDDLE_TAB_PARAM_ST;
using SOUND_ASSET_SOUND_OBJ_ENABLE_DIST_PARAM_ST = eldenring::param::generated::SOUND_ASSET_SOUND_OBJ_ENABLE_DIST_PARAM_ST;
using SOUND_AUTO_ENV_SOUND_GROUP_PARAM_ST = eldenring::param::generated::SOUND_AUTO_ENV_SOUND_GROUP_PARAM_ST;
using SOUND_AUTO_REVERB_EVALUATION_DIST_PARAM_ST = eldenring::param::generated::SOUND_AUTO_REVERB_EVALUATION_DIST_PARAM_ST;
using SOUND_AUTO_REVERB_SELECT_PARAM_ST = eldenring::param::generated::SOUND_AUTO_REVERB_SELECT_PARAM_ST;
using SOUND_CHR_PHYSICS_SE_PARAM_ST = eldenring::param::generated::SOUND_CHR_PHYSICS_SE_PARAM_ST;
using SOUND_COMMON_INGAME_PARAM_ST = eldenring::param::generated::SOUND_COMMON_INGAME_PARAM_ST;
using SOUND_COMMON_SYSTEM_PARAM_ST = eldenring::param::generated::SOUND_COMMON_SYSTEM_PARAM_ST;
using SOUND_CUTSCENE_PARAM_ST = eldenring::param::generated::SOUND_CUTSCENE_PARAM_ST;
using SPEEDTREE_MODEL_PARAM_ST = eldenring::param::generated::SPEEDTREE_MODEL_PARAM_ST;
using SP_EFFECT_PARAM_ST = eldenring::param::generated::SP_EFFECT_PARAM_ST;
using SP_EFFECT_SET_PARAM_ST = eldenring::param::generated::SP_EFFECT_SET_PARAM_ST;
using SP_EFFECT_VFX_PARAM_ST = eldenring::param::generated::SP_EFFECT_VFX_PARAM_ST;
using SWORD_ARTS_PARAM_ST = eldenring::param::generated::SWORD_ARTS_PARAM_ST;
using TALK_PARAM_ST = eldenring::param::generated::TALK_PARAM_ST;
using THROW_DIRECTION_SFX_PARAM_ST = eldenring::param::generated::THROW_DIRECTION_SFX_PARAM_ST;
using THROW_PARAM_ST = eldenring::param::generated::THROW_PARAM_ST;
using TOUGHNESS_PARAM_ST = eldenring::param::generated::TOUGHNESS_PARAM_ST;
using TUTORIAL_PARAM_ST = eldenring::param::generated::TUTORIAL_PARAM_ST;
using WAYPOINT_PARAM_ST = eldenring::param::generated::WAYPOINT_PARAM_ST;
using WEATHER_ASSET_CREATE_PARAM_ST = eldenring::param::generated::WEATHER_ASSET_CREATE_PARAM_ST;
using WEATHER_ASSET_REPLACE_PARAM_ST = eldenring::param::generated::WEATHER_ASSET_REPLACE_PARAM_ST;
using WEATHER_LOT_PARAM_ST = eldenring::param::generated::WEATHER_LOT_PARAM_ST;
using WEATHER_LOT_TEX_PARAM_ST = eldenring::param::generated::WEATHER_LOT_TEX_PARAM_ST;
using WEATHER_LOT_TEX_PARAM_ST_DLC02 = eldenring::param::generated::WEATHER_LOT_TEX_PARAM_ST_DLC02;
using WEATHER_PARAM_ST = eldenring::param::generated::WEATHER_PARAM_ST;
using WEP_ABSORP_POS_PARAM_ST = eldenring::param::generated::WEP_ABSORP_POS_PARAM_ST;
using WET_ASPECT_PARAM_ST = eldenring::param::generated::WET_ASPECT_PARAM_ST;
using WHITE_SIGN_COOL_TIME_PARAM_ST = eldenring::param::generated::WHITE_SIGN_COOL_TIME_PARAM_ST;
using WORLD_MAP_LEGACY_CONV_PARAM_ST = eldenring::param::generated::WORLD_MAP_LEGACY_CONV_PARAM_ST;
using WORLD_MAP_PIECE_PARAM_ST = eldenring::param::generated::WORLD_MAP_PIECE_PARAM_ST;
using WORLD_MAP_PLACE_NAME_PARAM_ST = eldenring::param::generated::WORLD_MAP_PLACE_NAME_PARAM_ST;
using WORLD_MAP_POINT_PARAM_ST = eldenring::param::generated::WORLD_MAP_POINT_PARAM_ST;
using WWISE_VALUE_TO_STR_CONVERT_PARAM_ST = eldenring::param::generated::WWISE_VALUE_TO_STR_CONVERT_PARAM_ST;
}
}

namespace eldenring {
namespace rva {
using RvaBundle = eldenring::rva::bundle::RvaBundle;
}
}

namespace eldenring {
namespace shared {
using Aabb = eldenring::shared::dl_math::linear::Aabb;
using CCallback = eldenring::shared::steam::CCallback;
template <typename T>
using Class = eldenring::shared::rtti::Class<T>;
using F32Matrix2x2 = eldenring::shared::dl_math::matrix::F32Matrix2x2;
using F32Matrix2x3 = eldenring::shared::dl_math::matrix::F32Matrix2x3;
using F32Matrix2x4 = eldenring::shared::dl_math::matrix::F32Matrix2x4;
using F32Matrix3x2 = eldenring::shared::dl_math::matrix::F32Matrix3x2;
using F32Matrix3x3 = eldenring::shared::dl_math::matrix::F32Matrix3x3;
using F32Matrix3x4 = eldenring::shared::dl_math::matrix::F32Matrix3x4;
using F32Matrix4x2 = eldenring::shared::dl_math::matrix::F32Matrix4x2;
using F32Matrix4x3 = eldenring::shared::dl_math::matrix::F32Matrix4x3;
using F32Matrix4x4 = eldenring::shared::dl_math::matrix::F32Matrix4x4;
using F32ModelMatrix = eldenring::shared::dl_math::special::F32ModelMatrix;
using F32PackedModelMatrix = eldenring::shared::dl_math::special::F32PackedModelMatrix;
using F32Vector2 = eldenring::shared::dl_math::vector::F32Vector2;
using F32Vector3 = eldenring::shared::dl_math::vector::F32Vector3;
using F32Vector4 = eldenring::shared::dl_math::vector::F32Vector4;
using F32ViewMatrix = eldenring::shared::dl_math::special::F32ViewMatrix;
using Frustum = eldenring::shared::dl_math::linear::Frustum;
template <typename T>
using IncompleteArrayField = eldenring::shared::util::incomplete_array_field::IncompleteArrayField<T>;
using Line = eldenring::shared::dl_math::linear::Line;
using Lss = eldenring::shared::dl_math::linear::Lss;
template <typename T>
using MaybeEmpty = eldenring::shared::empty::MaybeEmpty<T>;
template <typename E, typename I>
using NonEmptyIter = eldenring::shared::empty::NonEmptyIter<E, I>;
template <typename E, typename I>
using NonEmptyIterMut = eldenring::shared::empty::NonEmptyIterMut<E, I>;
using Obb = eldenring::shared::dl_math::linear::Obb;
template <typename T>
using OwnedPtr = eldenring::shared::owned_pointer::OwnedPtr<T>;
using Plane = eldenring::shared::dl_math::linear::Plane;
using Program = eldenring::shared::program::Program;
using Ray = eldenring::shared::dl_math::linear::Ray;
using Rectangle = eldenring::shared::dl_math::linear::Rectangle;
template <typename TTaskData>
using RecurringTask = eldenring::shared::task::RecurringTask<TTaskData>;
template <typename TTaskData>
using RecurringTaskHandle = eldenring::shared::task::RecurringTaskHandle<TTaskData>;
using Rss = eldenring::shared::dl_math::linear::Rss;
using Segment = eldenring::shared::dl_math::linear::Segment;
using Sphere = eldenring::shared::dl_math::linear::Sphere;
using Triangle = eldenring::shared::dl_math::linear::Triangle;
using Triangle3 = eldenring::shared::dl_math::linear::Triangle3;
using TryFromSuperclassError = eldenring::shared::subclass::TryFromSuperclassError;
template <typename N>
using UnknownStruct = eldenring::shared::util::unknown_struct::UnknownStruct<N>;
}
}

namespace eldenring {
using AllocationHeader = eldenring::stl::AllocationHeader;
template <typename T>
using ArrayWithHeader = eldenring::stl::ArrayWithHeader<T>;
template <typename T>
using BasicVector = eldenring::stl::BasicVector<T>;
template <typename T, typename N>
using CSFixedList = eldenring::stl::CSFixedList<T, N>;
template <typename T>
using CSFixedListEntry = eldenring::stl::CSFixedListEntry<T>;
template <typename T>
using ChainingMapBucketEntry = eldenring::stl::ChainingMapBucketEntry<T>;
template <typename K, typename V>
using ChainingTree = eldenring::stl::ChainingTree<K, V>;
template <typename T>
using DoublyLinkedList = eldenring::stl::DoublyLinkedList<T>;
template <typename T>
using DoublyLinkedListNode = eldenring::stl::DoublyLinkedListNode<T>;
template <typename K, typename V>
using Pair = eldenring::stl::Pair<K, V>;
template <typename T>
using Tree = eldenring::stl::Tree<T>;
template <typename T>
using TreeNode = eldenring::stl::TreeNode<T>;
template <typename T>
using Vector = eldenring::stl::Vector<T>;
}

