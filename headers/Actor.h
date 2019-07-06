class Actor : public IActor {
  protected:
    size_t m_refs;
    uint32_t m_id;
    class IUE4Actor *m_target;
    class TimerSet *m_timers;
    std::string m_blueprintName;
    class ActorRef<IActor> m_owner;
    int32_t m_health;
    class std::map<std::basic_string<char>, bool, std::less<std::basic_string<char> >, std::allocator<std::pair<std::basic_string<char> const, bool> > > m_states;
    float m_forwardMovementFraction;
    float m_strafeMovementFraction;
    struct Vector3 m_remotePosition;
    struct Vector3 m_remoteVelocity;
    struct Rotation m_remoteRotation;
    float m_remoteLocationBlendFactor;
    class Spawner *m_spawner;

    virtual void OnKilled(class IActor *, class IItem *);
    virtual void OnTargetKilled(class IActor *, class IItem *);
  public:
    Actor(const std::string &);
    virtual ~Actor();
    virtual bool IsValid() const;
    virtual void * GetUE4Actor();
    virtual void AddRef();
    virtual void Release();
    void RemoveFromWorld();
    virtual void OnSpawnActor(class IUE4Actor *);
    virtual void OnDestroyActor();
    virtual std::string GetDeathMessage();
    virtual const char * GetBlueprintName();
    virtual bool IsCharacter();
    virtual bool IsNPC();
    virtual bool IsProjectile();
    virtual bool IsPlayer();
    virtual class IPlayer * GetPlayerInterface();
    virtual bool ShouldSendPositionUpdates();
    virtual bool ShouldReceivePositionUpdates();
    uint32_t GetId() const;
    void SetId(uint32_t);
    struct Vector3 GetPosition();
    struct Vector3 GetProjectilePosition();
    virtual struct Vector3 GetLookPosition();
    struct Rotation GetRotation();
    virtual struct Rotation GetLookRotation();
    struct Vector3 GetVelocity();
    float GetForwardMovementFraction() const;
    float GetStrafeMovementFraction() const;
    bool IsOnGround();
    void SetPosition(const struct Vector3 &);
    void SetRotation(const struct Rotation &);
    void SetVelocity(const struct Vector3 &);
    void SetForwardAndStrafeMovement(float, float);
    void SetRemotePositionAndRotation(const struct Vector3 &, const struct Rotation &);
    void InterpolateRemotePosition(float);
    virtual class IActor * GetOwner();
    void LocalRespawn(const struct Vector3 &, const struct Rotation &);
    bool MoveToLocation(const struct Vector3 &);
    bool MoveToRandomLocationInRadius(float);
    bool MoveToActor(class IActor *);
    bool GetState(const std::string &);
    virtual void UpdateState(const std::string &, bool);
    virtual void TriggerEvent(const std::string &, class IActor *, bool);
    const class std::map<std::basic_string<char>, bool, std::less<std::basic_string<char> >, std::allocator<std::pair<std::basic_string<char> const, bool> > > & GetStates();
    class IActor * LineTraceTo(const struct Vector3 &);
    void FireBullets(class IItem *, int32_t, enum DamageType, float, uint32_t, float);
    void FireBullets(class IItem *, int32_t, enum DamageType, const struct Vector3 &, float, uint32_t, float);
    virtual bool CanBeDamaged(class IActor *);
    virtual float GetMaximumDamageDistance();
    virtual int32_t GetHealth();
    virtual int32_t GetMaxHealth();
    virtual void Damage(class IActor *, class IItem *, int32_t, enum DamageType);
    void PerformSetHealth(int32_t);
    virtual void Tick(float);
    virtual bool CanUse(class IPlayer *);
    virtual void OnUse(class IPlayer *);
    virtual void PerformUse(class IPlayer *);
    virtual void OnHit(class IActor *, const struct Vector3 &, const struct Vector3 &);
    virtual void OnAIMoveComplete();
    virtual const char * GetDisplayName();
    virtual bool IsElite();
    virtual bool IsPvPEnabled();
    virtual class IItem ** GetShopItems(size_t &);
    virtual class std::vector<IItem*, std::allocator<IItem*> > GetShopItems();
    virtual void FreeShopItems(class IItem **);
    virtual class std::vector<IItem*, std::allocator<IItem*> > GetValidBuyItems();
    virtual float GetShopBuyPriceMultiplier();
    virtual float GetShopSellPriceMultiplier();
    virtual int32_t GetBuyPriceForItem(class IItem *);
    virtual int32_t GetSellPriceForItem(class IItem *);
    void SetSpawner(class Spawner *);
    void AddTimer(const std::string &, float, const class std::function<void ()> &);
    void AddTimerWithContext(const std::string &, float, const class std::function<void (Actor *)> &);
    void AddRecurringTimer(const std::string &, float, const class std::function<void ()> &);
    void AddRecurringTimerWithContext(const std::string &, float, const class std::function<void (Actor *)> &);
    void CancelTimer(const std::string &);
    void PerformReloadNotification(uint32_t);
}

class ActorFactory<AngryBear> [with T = class AngryBear] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<BallmerPeakEgg> [with T = class BallmerPeakEgg] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<Bear> [with T = class Bear] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<BearChest> [with T = class BearChest] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<BlockyChest> [with T = class BlockyChest] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<BlueDrop> [with T = class BlueDrop] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<CaveSpider> [with T = class CaveSpider] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<CowChest> [with T = class CowChest] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<CowKing> [with T = class CowKing] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<Farmer> [with T = class Farmer] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<Fireball> [with T = class Fireball] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<GiantRat> [with T = class GiantRat] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<GoldenEggPickup<1> > [with T = class GoldenEggPickup<1>] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<GoldenEggPickup<2> > [with T = class GoldenEggPickup<2>] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<GoldenEggPickup<3> > [with T = class GoldenEggPickup<3>] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<GoldenEggPickup<4> > [with T = class GoldenEggPickup<4>] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<GoldenEggPickup<5> > [with T = class GoldenEggPickup<5>] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<GoldenEggPickup<6> > [with T = class GoldenEggPickup<6>] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<GoldenEggPickup<7> > [with T = class GoldenEggPickup<7>] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<GoldenEggPickup<8> > [with T = class GoldenEggPickup<8>] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<GoldenEggPickup<9> > [with T = class GoldenEggPickup<9>] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<GreatBallsOfFirePickup> [with T = class GreatBallsOfFirePickup] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<GreenDrop> [with T = class GreenDrop] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<GunShopOwner> [with T = class GunShopOwner] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<HandCannonProjectile> [with T = class HandCannonProjectile] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<HolyHandGrenadeProjectile> [with T = class HolyHandGrenadeProjectile] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<IceSpiderQueen> [with T = class IceSpiderQueen] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<IceSpiderQueenProjectile> [with T = class IceSpiderQueenProjectile] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<JustinTolerable> [with T = class JustinTolerable] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<LavaChest> [with T = class LavaChest] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<LostCaveBush> [with T = class LostCaveBush] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<MadCow> [with T = class MadCow] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<Magmarok> [with T = class Magmarok] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<MagmarokFireball> [with T = class MagmarokFireball] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<MichaelAngelo> [with T = class MichaelAngelo] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<OPFireballProjectile> [with T = class OPFireballProjectile] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<PurpleDrop> [with T = class PurpleDrop] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<WhiteDrop> [with T = class WhiteDrop] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactory<ZeroCoolProjectile> [with T = class ZeroCoolProjectile] : public IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class ActorFactoryWithOwner<Fireball> [with T = class Fireball] : public IActorFactoryWithOwner {
  public:
    virtual class Actor * CreateActor(class IActor *);
}

class ActorFactoryWithOwner<HandCannonProjectile> [with T = class HandCannonProjectile] : public IActorFactoryWithOwner {
  public:
    virtual class Actor * CreateActor(class IActor *);
}

class ActorFactoryWithOwner<HolyHandGrenadeProjectile> [with T = class HolyHandGrenadeProjectile] : public IActorFactoryWithOwner {
  public:
    virtual class Actor * CreateActor(class IActor *);
}

class ActorFactoryWithOwner<IceSpiderQueenProjectile> [with T = class IceSpiderQueenProjectile] : public IActorFactoryWithOwner {
  public:
    virtual class Actor * CreateActor(class IActor *);
}

class ActorFactoryWithOwner<MagmarokFireball> [with T = class MagmarokFireball] : public IActorFactoryWithOwner {
  public:
    virtual class Actor * CreateActor(class IActor *);
}

class ActorFactoryWithOwner<OPFireballProjectile> [with T = class OPFireballProjectile] : public IActorFactoryWithOwner {
  public:
    virtual class Actor * CreateActor(class IActor *);
}

class ActorFactoryWithOwner<ZeroCoolProjectile> [with T = class ZeroCoolProjectile] : public IActorFactoryWithOwner {
  public:
    virtual class Actor * CreateActor(class IActor *);
}

class ActorRef<Actor> [with T = class Actor] {
  private:
    class T *m_object;

  public:
    ActorRef();
    ActorRef(class T *);
    ActorRef(const class ActorRef<T> &);
    class ActorRef<T> & operator=(class T *);
    class ActorRef<T> & operator=(const class ActorRef<T> &);
    class T * operator->() const;
    operator _Bool() const;
    operator class Actor *() const;
    class T * Get() const;
    bool operator<(const class ActorRef<T> &) const;
}

class ActorRef<Bear> [with T = class Bear] {
  private:
    class T *m_object;

  public:
    ActorRef();
    ActorRef(class T *);
    ActorRef(const class ActorRef<T> &);
    class ActorRef<T> & operator=(class T *);
    class ActorRef<T> & operator=(const class ActorRef<T> &);
    class T * operator->() const;
    operator _Bool() const;
    operator class Bear *() const;
    class T * Get() const;
    bool operator<(const class ActorRef<T> &) const;
}

class ActorRef<BearChest> [with T = class BearChest] {
  private:
    class T *m_object;

  public:
    ActorRef();
    ActorRef(class T *);
    ActorRef(const class ActorRef<T> &);
    class ActorRef<T> & operator=(class T *);
    class ActorRef<T> & operator=(const class ActorRef<T> &);
    class T * operator->() const;
    operator _Bool() const;
    operator class BearChest *() const;
    class T * Get() const;
    bool operator<(const class ActorRef<T> &) const;
}

class ActorRef<IActor> [with T = class IActor] {
  private:
    class T *m_object;

  public:
    ActorRef();
    ActorRef(class T *);
    ActorRef(const class ActorRef<T> &);
    class ActorRef<T> & operator=(class T *);
    class ActorRef<T> & operator=(const class ActorRef<T> &);
    class T * operator->() const;
    operator _Bool() const;
    operator class IActor *() const;
    class T * Get() const;
    bool operator<(const class ActorRef<T> &) const;
}

class ActorRef<IPlayer> [with T = class IPlayer] {
  private:
    class T *m_object;

  public:
    ActorRef();
    ActorRef(class T *);
    ActorRef(const class ActorRef<T> &);
    class ActorRef<T> & operator=(class T *);
    class ActorRef<T> & operator=(const class ActorRef<T> &);
    class T * operator->() const;
    operator _Bool() const;
    operator class IPlayer *() const;
    class T * Get() const;
    bool operator<(const class ActorRef<T> &) const;
}

class ActorRef<NPC> [with T = class NPC] {
  private:
    class T *m_object;

  public:
    ActorRef();
    ActorRef(class T *);
    ActorRef(const class ActorRef<T> &);
    class ActorRef<T> & operator=(class T *);
    class ActorRef<T> & operator=(const class ActorRef<T> &);
    class T * operator->() const;
    operator _Bool() const;
    operator class NPC *() const;
    class T * Get() const;
    bool operator<(const class ActorRef<T> &) const;
}

class IActor {
  public:
    virtual ~IActor();
    virtual void * GetUE4Actor();
    virtual bool IsNPC();
    virtual bool IsPlayer();
    virtual class IPlayer * GetPlayerInterface();
    virtual void AddRef();
    virtual void Release();
    virtual void OnSpawnActor(class IUE4Actor *);
    virtual void OnDestroyActor();
    virtual const char * GetBlueprintName();
    virtual bool IsCharacter();
    virtual bool CanBeDamaged(class IActor *);
    virtual int32_t GetHealth();
    virtual int32_t GetMaxHealth();
    virtual void Damage(class IActor *, class IItem *, int32_t, enum DamageType);
    virtual void Tick(float);
    virtual bool CanUse(class IPlayer *);
    virtual void OnUse(class IPlayer *);
    virtual void OnHit(class IActor *, const struct Vector3 &, const struct Vector3 &);
    virtual void OnAIMoveComplete();
    virtual const char * GetDisplayName();
    virtual bool IsElite();
    virtual bool IsPvPEnabled();
    virtual class IItem ** GetShopItems(size_t &);
    virtual void FreeShopItems(class IItem **);
    virtual int32_t GetBuyPriceForItem(class IItem *);
    virtual int32_t GetSellPriceForItem(class IItem *);
    virtual struct Vector3 GetLookPosition();
    virtual struct Rotation GetLookRotation();
    virtual class IActor * GetOwner();
}

class IActorFactory {
  public:
    virtual class Actor * CreateActor();
}

class IActorFactoryWithOwner {
  public:
    virtual class Actor * CreateActor(class IActor *);
}

class IUE4Actor {
  public:
    virtual void * GetUE4Actor();
    virtual void RemoveFromWorld();
    virtual struct Vector3 GetPosition();
    virtual struct Rotation GetRotation();
    virtual struct Vector3 GetProjectilePosition();
    virtual struct Vector3 GetCharacterVelocity();
    virtual void SetPosition(const struct Vector3 &);
    virtual void SetRotation(const struct Rotation &);
    virtual void SetCharacterVelocity(const struct Vector3 &);
    virtual void SetForwardAndStrafeMovement(float, float);
    virtual void InterpolatePositionAndRotation(const struct Vector3 &, const struct Rotation &, float, float);
    virtual bool MoveToLocation(const struct Vector3 &);
    virtual bool MoveToRandomLocationInRadius(float);
    virtual bool MoveToActor(class IActor *);
    virtual void OnUpdateState(const char *, bool);
    virtual void OnTriggerEvent(const char *, class IActor *);
    virtual void OnUpdatePvPEnabled(bool);
    virtual class IActor * LineTraceTo(const struct Vector3 &);
    virtual void FireBullets(class IItem *, int32_t, enum DamageType, const struct Vector3 &, uint32_t, float);
    virtual void LocalRespawn(const struct Vector3 &, const struct Rotation &);
    virtual bool IsOnGround();
    virtual void OnReload(uint32_t);
}

class RemoteActor : public Actor {
  private:
    bool m_isCharacter;

  public:
    RemoteActor(const std::string &, bool);
    virtual bool IsCharacter();
}
