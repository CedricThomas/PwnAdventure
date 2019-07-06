enum DamageType {PhysicalDamage, FireDamage, ColdDamage, ShockDamage}

class GameAPI {
  private:
    void InitObjects();
    void StartServerListener(const struct ServerInfo &);
  public:
    GameAPI();
    void InitLocal(class ILocalPlayer *);
    void InitClient(class ILocalPlayer *);
    void InitServer(const char *, uint16_t, int32_t, const char *, uint16_t, const char *, const char *, const char *);
    void Shutdown();
    void Tick(float);
    bool IsAuthority();
    bool IsDedicatedServer();
    bool IsTransitioningToNewServer();
    class IItem * GetItemByName(const char *);
    class IQuest * GetQuestByName(const char *);
    class FastTravelDestination * GetFastTravelDestination(const std::string &);
    class IAchievement * GetAchievement(const char *);
    class IAchievementList * GetAchievements();
    class std::vector<IAchievement*, std::allocator<IAchievement*> > GetAchievementList();
    class std::vector<ItemPickup*, std::allocator<ItemPickup*> > GetGoldenEggList();
    size_t GetGoldenEggCount();
    virtual bool SpawnActor(class IActor *, const struct Vector3 &, const struct Rotation &, bool);
    virtual bool SpawnActorAtNamedLocation(class IActor *, const char *);
    virtual bool SpawnRemotePlayer(class IPlayer *, const struct Vector3 &, const struct Rotation &);
    virtual void DamageInRadius(class IActor *, class IItem *, const struct Vector3 &, float, int32_t, enum DamageType);
    virtual size_t GetNamedLocationPoints(const char *, struct LocationAndRotation *&);
    virtual void FreeNamedLocationPoints(struct LocationAndRotation *);
    class std::vector<LocationAndRotation, std::allocator<LocationAndRotation> > GetNamedLocationPointList(const char *);
    bool GetNamedLocationPoint(const std::string &, struct LocationAndRotation &);
    class std::vector<LocationAndRotation, std::allocator<LocationAndRotation> > GetSpawnPoints(const char *);
    void GiveAll(class IPlayer *);
    virtual struct Vector3 GetDirectionFromRotation(const struct Rotation &);
    virtual struct Rotation GetRotationFromDirection(const struct Vector3 &);
    virtual void OnWeaponFired(class IItem *, const struct Vector3 &, const struct Vector3 &);
    virtual void OnBulletHitActor(class IItem *, class IActor *, const struct Vector3 &, const struct Vector3 &);
    virtual void OnBulletHitWorld(class IItem *, const struct Vector3 &, const struct Vector3 &);
    virtual void OnLog(const char *);
    void Log(const char *);
    virtual void OnMasterServerConnected(bool, const char *, const char *);
    virtual void OnLoginComplete(bool, const char *, bool, struct CharacterInfo *, size_t);
    virtual void OnRegisterComplete(bool, const char *, const char *, bool);
    virtual void OnCreateCharacterComplete(bool, const char *, int32_t);
    virtual void OnDeleteCharacterComplete(bool, int32_t);
    virtual void OnJoinGameServerComplete(bool, const char *, bool, const char *, uint16_t, const char *);
    virtual void OnGameServerConnected(bool, const char *, const struct Vector3 &, const struct Rotation &);
    virtual void OnTransitionToNewServer();
    virtual void OnSubmitAnswerComplete(bool, const char *);
    virtual void OnTeammatesListed(const char **, const char **, size_t);
    virtual uint32_t GetDefaultCircuitInputs(const char *);
    virtual size_t GetCircuitOutputCount(const char *);
    virtual void GetCircuitOutputs(const char *, uint32_t, bool *, size_t, bool *);
    class LootTier * GetLootTier(uint32_t);
    void Enqueue(const class std::function<void ()> &);
    void Process(const class std::function<void ()> &);
    class MasterServerConnection * GetMasterServer();
    void UpdatePlayerCounts();
    void GetTeammates();
    void Login(const char *, const char *);
    void CreateCharacter(const char *, uint8_t, uint32_t *);
    void DeleteCharacter(int32_t);
    void JoinGameServer(int32_t, bool);
    void SubmitAnswer(const char *, const char *);
    class GameServerConnection * GetGameServer();
    void ConnectToGameServer(const char *, uint16_t, int32_t, const char *);
    bool IsConnectedToMasterServer();
    bool IsConnectedToGameServer();
    int32_t GetUserId();
    int32_t GetCharacterId();
    const char * GetUserName();
    const char * GetTeamName();
    const char * GetTeamHash();
    void ConnectToMasterServer(const char *, uint16_t, const char *);
    void DisconnectFromMasterServer();
    void Register(const char *, const char *, const char *);
    void TransitionToNewGameServer();
    class Actor * CreateRemoteActorByName(const std::string &, bool);
    class Actor * CreateRemoteActorByNameWithOwner(const std::string &, bool, class IActor *);
    bool HasActorFactory(const std::string &);
    int32_t GetTeamPlayerCount();
    int32_t GetTotalPlayerCount();
}

struct LocationAndRotation {
    struct Vector3 location;
    struct Rotation rotation;
}

struct Rotation {
    float pitch;
    float yaw;
    float roll;
  public:
    Rotation();
    Rotation(float, float, float);
}

struct ServerInfo {
    std::string masterHost;
    uint16_t masterPort;
    std::string certPath;
    std::string username;
    std::string password;
    std::string hostname;
    uint16_t serverPort;
}

struct Vector3 {
    float x;
    float y;
    float z;
  public:
    Vector3();
    Vector3(float, float, float);
    struct Vector3 operator*(float) const;
    struct Vector3 & operator*=(float);
    struct Vector3 operator+(const struct Vector3 &) const;
    struct Vector3 & operator+=(const struct Vector3 &);
    struct Vector3 operator-(const struct Vector3 &) const;
    struct Vector3 & operator-=(const struct Vector3 &);
    float MagnitudeSquared() const;
    float Magnitude() const;
    static float DistanceSquared(const struct Vector3 &, const struct Vector3 &);
    static float Distance(const struct Vector3 &, const struct Vector3 &);
    void Normalize();
    static struct Vector3 Normalize(const struct Vector3 &);
}
