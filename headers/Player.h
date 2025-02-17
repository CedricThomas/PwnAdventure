struct FastTravelInfo {
    std::string region;
    std::string displayName;
}

class FastTravelList : public IFastTravel {
  private:
    class std::vector<FastTravelInfo, std::allocator<FastTravelInfo> > m_destinations;

  public:
    FastTravelList(const class std::vector<FastTravelInfo, std::allocator<FastTravelInfo> > &);
    virtual size_t GetCount();
    virtual const char * GetRegionName(size_t);
    virtual const char * GetDisplayName(size_t);
    virtual void Destroy();
}

class IFastTravel {
  public:
    virtual ~IFastTravel();
    virtual size_t GetCount();
    virtual const char * GetRegionName(size_t);
    virtual const char * GetDisplayName(size_t);
    virtual void Destroy();
}

class IInventory {
  public:
    virtual ~IInventory();
    virtual size_t GetCount();
    virtual class IItem * GetItem(size_t);
    virtual uint32_t GetItemCount(size_t);
    virtual uint32_t GetItemLoadedAmmo(size_t);
    virtual void Destroy();
}

class ILocalPlayer : public IUE4Actor {
  public:
    virtual void SetPlayerInterface(class IPlayer *);
    virtual struct Vector3 GetLookPosition();
    virtual struct Rotation GetLookRotation();
    virtual float GetForwardMovementFraction();
    virtual float GetStrafeMovementFraction();
    virtual void SetCurrentQuest(class IQuest *, class IQuestState *, uint32_t);
    virtual void DisplayMessage(const char *, const char *);
    virtual void DisplayEvent(const char *, const char *);
    virtual void OnEquip(size_t, class IItem *);
    virtual void OnChangeSlot(size_t);
    virtual void OnUpdateCountdown(int32_t);
    virtual void OnUpdatePvPCountdown(bool, int32_t);
    virtual void OnNewItem(const char *, uint32_t);
    virtual void OnNPCConversationState(class IActor *, const char *, const char **, const char **, size_t);
    virtual void OnNPCConversationEnd();
    virtual void OnNPCShop(class IActor *);
    virtual void OnChatMessage(const char *, bool, const char *);
    virtual void OnPlayerKillMessage(const char *, bool, const char *, bool, class IItem *);
    virtual void OnPlayerSuicideMessage(const char *, bool, class IItem *);
    virtual void OnPlayerDeadMessage(const char *, bool, const char *);
    virtual void OnAchievement(const char *);
    virtual void OnLocalDeath(class IActor *, class IItem *);
}

class IPlayer {
  public:
    virtual class IActor * GetActorInterface();
    void AddRef();
    void Release();
    virtual bool IsLocalPlayer() const;
    virtual class ILocalPlayer * GetLocalPlayer() const;
    virtual const char * GetPlayerName();
    virtual const char * GetTeamName();
    virtual uint8_t GetAvatarIndex();
    virtual const uint32_t * GetColors();
    virtual bool IsPvPDesired();
    virtual void SetPvPDesired(bool);
    virtual class IInventory * GetInventory();
    virtual uint32_t GetItemCount(class IItem *);
    virtual uint32_t GetLoadedAmmo(class IItem *);
    virtual bool AddItem(class IItem *, uint32_t, bool);
    virtual bool RemoveItem(class IItem *, uint32_t);
    virtual bool AddLoadedAmmo(class IItem *, class IItem *, uint32_t);
    virtual bool RemoveLoadedAmmo(class IItem *, uint32_t);
    virtual class IItem * GetItemForSlot(size_t);
    virtual void EquipItem(size_t, class IItem *);
    virtual size_t GetCurrentSlot();
    virtual void SetCurrentSlot(size_t);
    virtual class IItem * GetCurrentItem();
    virtual int32_t GetMana();
    virtual bool UseMana(int32_t);
    virtual void SetItemCooldown(class IItem *, float, bool);
    virtual bool IsItemOnCooldown(class IItem *);
    virtual float GetItemCooldown(class IItem *);
    virtual bool HasPickedUp(const char *);
    virtual void MarkAsPickedUp(const char *);
    virtual class IQuest ** GetQuestList(size_t *);
    virtual void FreeQuestList(class IQuest **);
    virtual class IQuest * GetCurrentQuest();
    virtual void SetCurrentQuest(class IQuest *);
    virtual struct PlayerQuestState GetStateForQuest(class IQuest *);
    virtual void StartQuest(class IQuest *);
    virtual void AdvanceQuestToState(class IQuest *, class IQuestState *);
    virtual void CompleteQuest(class IQuest *);
    virtual bool IsQuestStarted(class IQuest *);
    virtual bool IsQuestCompleted(class IQuest *);
    virtual void EnterAIZone(const char *);
    virtual void ExitAIZone(const char *);
    virtual void UpdateCountdown(int32_t);
    void HideCountdown();
    virtual bool CanReload();
    virtual void RequestReload();
    virtual float GetWalkingSpeed();
    virtual float GetSprintMultiplier();
    virtual float GetJumpSpeed();
    virtual float GetJumpHoldTime();
    virtual bool CanJump();
    virtual void SetJumpState(bool);
    virtual void SetSprintState(bool);
    virtual void SetFireRequestState(bool);
    virtual void TransitionToNPCState(const char *);
    virtual void BuyItem(class IActor *, class IItem *, uint32_t);
    virtual void SellItem(class IActor *, class IItem *, uint32_t);
    virtual void EnterRegion(const char *);
    virtual void Respawn();
    virtual void Teleport(const char *);
    virtual void Chat(const char *);
    virtual class IFastTravel * GetFastTravelDestinations(const char *);
    virtual void FastTravel(const char *, const char *);
    virtual void MarkAsAchieved(class IAchievement *);
    virtual bool HasAchieved(class IAchievement *);
    virtual void SubmitDLCKey(const char *);
    virtual uint32_t GetCircuitInputs(const char *);
    virtual void SetCircuitInputs(const char *, uint32_t);
    virtual void GetCircuitOutputs(const char *, bool *, size_t);
}

class Inventory : public IInventory {
  private:
    class std::vector<ItemAndCount, std::allocator<ItemAndCount> > m_items;

  public:
    Inventory(const class std::vector<ItemAndCount, std::allocator<ItemAndCount> > &);
    virtual size_t GetCount();
    virtual class IItem * GetItem(size_t);
    virtual uint32_t GetItemCount(size_t);
    virtual uint32_t GetItemLoadedAmmo(size_t);
    virtual void Destroy();
}

struct ItemAndCount {
    class IItem *item;
    uint32_t count;
    uint32_t loadedAmmo;
}

struct ItemCountInfo {
    uint32_t count;
    uint32_t loadedAmmo;
}

class Player : public Actor, public IPlayer {
  private:
    uint32_t m_characterId;
    std::string m_playerName;
    std::string m_teamName;
    uint8_t m_avatarIndex;
    uint32_t m_colors[4];
    class std::map<IItem*, ItemAndCount, std::less<IItem*>, std::allocator<std::pair<IItem* const, ItemAndCount> > > m_inventory;
    class std::set<std::basic_string<char>, std::less<std::basic_string<char> >, std::allocator<std::basic_string<char> > > m_pickups;
    class std::map<IItem*, float, std::less<IItem*>, std::allocator<std::pair<IItem* const, float> > > m_cooldowns;
    class std::map<std::basic_string<char>, unsigned int, std::less<std::basic_string<char> >, std::allocator<std::pair<std::basic_string<char> const, unsigned int> > > m_circuitInputs;
    class std::map<std::basic_string<char>, std::vector<class std::allocator<bool>>, std::less<std::basic_string<char> >, std::allocator<std::pair<std::basic_string<char> const, std::vector<class std::allocator<bool>> > > > m_circuitOutputs;
    bool m_admin;
    bool m_pvpEnabled;
    bool m_pvpDesired;
    float m_pvpChangeTimer;
    int32_t m_pvpChangeReportedTimer;
    bool m_changingServerRegion;
    std::string m_currentRegion;
    std::string m_changeRegionDestination;
    class std::set<std::basic_string<char>, std::less<std::basic_string<char> >, std::allocator<std::basic_string<char> > > m_aiZones;
    int32_t m_mana;
    float m_manaRegenTimer;
    float m_healthRegenCooldown;
    float m_healthRegenTimer;
    int32_t m_countdown;
    struct Vector3 m_remoteLookPosition;
    struct Rotation m_remoteLookRotation;
    class IItem *m_equipped[10];
    size_t m_currentSlot;
    class std::map<IQuest*, PlayerQuestState, std::less<IQuest*>, std::allocator<std::pair<IQuest* const, PlayerQuestState> > > m_questStates;
    class IQuest *m_currentQuest;
    float m_walkingSpeed;
    float m_jumpSpeed;
    float m_jumpHoldTime;
    class ActorRef<NPC> m_currentNPC;
    std::string m_currentNPCState;
    class ILocalPlayer *m_localPlayer;
    class WriteStream *m_eventsToSend;
    bool m_itemsUpdated;
    float m_itemSyncTimer;
    uint32_t m_chatMessageCounter;
    float m_chatFloodDecayTimer;
    class IItem *m_lastHitByItem;
    float m_lastHitItemTimeLeft;
    float m_circuitStateCooldownTimer;

  protected:
    virtual void OnKilled(class IActor *, class IItem *);
  public:
    Player(bool);
    virtual ~Player();
    virtual bool IsPlayer();
    virtual class IPlayer * GetPlayerInterface();
    virtual class IActor * GetActorInterface();
    virtual bool CanBeDamaged(class IActor *);
    virtual bool IsCharacter();
    virtual bool ShouldSendPositionUpdates();
    virtual bool ShouldReceivePositionUpdates();
    virtual void Tick(float);
    virtual void Damage(class IActor *, class IItem *, int32_t, enum DamageType);
    virtual void OnDestroyActor();
    void OnKillEvent(class IPlayer *, class IActor *, class IItem *);
    virtual struct Vector3 GetLookPosition();
    virtual struct Rotation GetLookRotation();
    void SetRemoteLookPosition(const struct Vector3 &);
    void SetRemoteLookRotation(const struct Rotation &);
    virtual bool CanJump();
    virtual bool IsLocalPlayer() const;
    virtual class ILocalPlayer * GetLocalPlayer() const;
    void InitLocalPlayer(class ILocalPlayer *);
    bool IsAdmin() const;
    void SetPlayerName(const std::string &);
    void SetTeamName(const std::string &);
    void SetAvatarIndex(uint8_t);
    void SetColors(const uint32_t *);
    void SetCharacterId(uint32_t);
    virtual bool IsPvPEnabled();
    virtual bool IsPvPDesired();
    virtual void SetPvPDesired(bool);
    void PerformSetPvPEnabled(bool);
    void PerformSetPvPDesired(bool);
    void PerformUpdatePvPCountdown(bool, int32_t);
    virtual void UpdateState(const std::string &, bool);
    virtual const char * GetPlayerName();
    virtual const char * GetTeamName();
    virtual uint8_t GetAvatarIndex();
    virtual const uint32_t * GetColors();
    uint32_t GetCharacterId() const;
    const class std::map<IItem*, ItemAndCount, std::less<IItem*>, std::allocator<std::pair<IItem* const, ItemAndCount> > > & GetItemList() const;
    virtual class IInventory * GetInventory();
    virtual uint32_t GetItemCount(class IItem *);
    virtual uint32_t GetLoadedAmmo(class IItem *);
    virtual bool AddItem(class IItem *, uint32_t, bool);
    virtual bool RemoveItem(class IItem *, uint32_t);
    bool PerformAddItem(class IItem *, uint32_t, bool);
    bool PerformRemoveItem(class IItem *, uint32_t);
    virtual bool AddLoadedAmmo(class IItem *, class IItem *, uint32_t);
    virtual bool RemoveLoadedAmmo(class IItem *, uint32_t);
    void PerformSetLoadedAmmo(class IItem *, uint32_t);
    virtual class IItem * GetItemForSlot(size_t);
    virtual void EquipItem(size_t, class IItem *);
    void PerformEquipItem(size_t, class IItem *);
    virtual size_t GetCurrentSlot();
    virtual class IItem * GetCurrentItem();
    virtual void SetCurrentSlot(size_t);
    void PerformSetCurrentSlot(size_t);
    void SetRemoteItem(class IItem *);
    virtual int32_t GetMana();
    virtual bool UseMana(int32_t);
    void PerformSetMana(int32_t);
    virtual void SetItemCooldown(class IItem *, float, bool);
    virtual bool IsItemOnCooldown(class IItem *);
    virtual float GetItemCooldown(class IItem *);
    virtual bool HasPickedUp(const char *);
    virtual void MarkAsPickedUp(const char *);
    void PerformMarkAsPickedUp(const std::string &);
    virtual class IQuest ** GetQuestList(size_t *);
    virtual void FreeQuestList(class IQuest **);
    virtual class IQuest * GetCurrentQuest();
    virtual struct PlayerQuestState GetStateForQuest(class IQuest *);
    virtual bool IsQuestStarted(class IQuest *);
    virtual bool IsQuestCompleted(class IQuest *);
    virtual void SetCurrentQuest(class IQuest *);
    virtual void StartQuest(class IQuest *);
    virtual void AdvanceQuestToState(class IQuest *, class IQuestState *);
    virtual void CompleteQuest(class IQuest *);
    void PerformSetCurrentQuest(class IQuest *);
    void PerformStartQuest(class IQuest *);
    void PerformAdvanceQuestToState(class IQuest *, class IQuestState *);
    void PerformCompleteQuest(class IQuest *);
    void SetInitialQuestStates(const class std::map<std::basic_string<char>, QuestStateInfo, std::less<std::basic_string<char> >, std::allocator<std::pair<std::basic_string<char> const, QuestStateInfo> > > &, const std::string &);
    void SetInitialItemState(const class std::map<std::basic_string<char>, ItemCountInfo, std::less<std::basic_string<char> >, std::allocator<std::pair<std::basic_string<char> const, ItemCountInfo> > > &, const class std::vector<std::basic_string<char>, std::allocator<std::basic_string<char> > > &, uint8_t);
    void SetInitialPickupState(const class std::set<std::basic_string<char>, std::less<std::basic_string<char> >, std::allocator<std::basic_string<char> > > &);
    virtual void EnterAIZone(const char *);
    virtual void ExitAIZone(const char *);
    virtual void UpdateCountdown(int32_t);
    void PerformUpdateCountdown(int32_t);
    virtual void TriggerEvent(const std::string &, class IActor *, bool);
    virtual bool CanReload();
    virtual void RequestReload();
    void PerformRequestReload();
    virtual float GetWalkingSpeed();
    virtual float GetSprintMultiplier();
    virtual float GetJumpSpeed();
    virtual float GetJumpHoldTime();
    virtual void SetJumpState(bool);
    virtual void SetSprintState(bool);
    virtual void SetFireRequestState(bool);
    void SetCurrentNPCState(class NPC *, const std::string &);
    void EndNPCConversation();
    void EnterNPCShop(class NPC *);
    class NPC * GetCurrentNPC() const;
    const std::string & GetCurrentNPCState() const;
    virtual void TransitionToNPCState(const char *);
    void PerformTransitionToNPCState(const std::string &);
    virtual void BuyItem(class IActor *, class IItem *, uint32_t);
    void PerformBuyItem(class IActor *, class IItem *, uint32_t);
    virtual void SellItem(class IActor *, class IItem *, uint32_t);
    void PerformSellItem(class IActor *, class IItem *, uint32_t);
    virtual void EnterRegion(const char *);
    bool IsChangingRegion() const;
    const std::string & GetChangeRegionDestination() const;
    void PerformEnterRegion(const std::string &);
    struct LocationAndRotation GetSpawnLocation();
    virtual void Respawn();
    void PerformRespawn();
    void PerformRespawnAtLocation(const struct Vector3 &, const struct Rotation &);
    virtual void Teleport(const char *);
    void PerformTeleport(const std::string &);
    virtual void SendEvent(const class WriteStream &);
    virtual void WriteAllEvents(class WriteStream &);
    void SyncItems();
    virtual void Chat(const char *);
    void PerformChat(const std::string &);
    void ReceiveChat(class Player *, const std::string &);
    virtual class IFastTravel * GetFastTravelDestinations(const char *);
    virtual void FastTravel(const char *, const char *);
    void PerformFastTravel(const std::string &, const std::string &);
    void OnTravelComplete(const std::string &);
    class IItem * GetLastHitByItem() const;
    void PerformSetLastHitByItem(class IItem *);
    virtual void MarkAsAchieved(class IAchievement *);
    virtual bool HasAchieved(class IAchievement *);
    virtual void SubmitDLCKey(const char *);
    void PerformSubmitDLCKey(const std::string &);
    virtual uint32_t GetCircuitInputs(const char *);
    virtual void SetCircuitInputs(const char *, uint32_t);
    void PerformSetCircuitInputs(const std::string &, uint32_t);
    virtual void GetCircuitOutputs(const char *, bool *, size_t);
    void PerformSetCircuitOutputs(const std::string &, std::vector<class std::allocator<bool>>);
    void InitCircuitStates();
}


struct PlayerQuestState {
    class IQuestState *state;
    uint32_t count;
}

struct QuestStateInfo {
    std::string state;
    uint32_t count;
}
