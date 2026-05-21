struct TileType
{
    enum Type {
        AIR,
        DIRT,
        NUM_TILES
    };
    Type t;
    TileType (Type nt) : t(nt) /* i'm dynamite */{};
    TileType(): t((Type)0){};
    operator int() const { return static_cast<int>(t); }
};