class BallmerPeakPoster : public Actor {
  public:
    BallmerPeakPoster();
    virtual bool CanBeDamaged(class IActor *);
    virtual void Damage(class IActor *, class IItem *, int32_t, enum DamageType);
}
