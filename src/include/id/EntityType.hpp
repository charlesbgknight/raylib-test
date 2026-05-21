struct  EntityType
{
    enum Type {
    PLAYER,
    NUM_ENTITIES
    };
    Type t;
    EntityType(Type nt) : t(nt) {};
    EntityType() : t{(Type)0} {};
    operator int() const { return static_cast<int>(t); }
};