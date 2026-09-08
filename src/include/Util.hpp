#pragma once
class Util {
    public:
        struct Coord
        {
            int x;
            int y;
            Coord(int a, int b) : x{a}, y { b } {};
            Coord() : x{0}, y {0} {};
        } ;
};