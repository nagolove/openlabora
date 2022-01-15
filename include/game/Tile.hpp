#ifndef TILE_HPP_
#define TILE_HPP_

#include <cmath>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <unordered_map>
#include "resource/IResourceManager.hpp"
#include "Entity.hpp"

class Tile final : public Entity
{
public:
    enum class TileType
    {
        None, Begin = None, Forest,
        Hill, Mountain, Water, Coast,
        Peat, End
    };
private:
    TileType mType{ TileType::None };

public:

    struct TileInfo
    {
        sf::Vector2f coord{ 0.f, 0.f };
        TileType type{ TileType::None };
    };

    // TODO make constexpr with latest SFML ver.
    inline static const TileInfo kBadTile
    {
        sf::Vector2f{ 0.f, 0.f },
        TileType{ TileType::None }
    };

    static constexpr unsigned int kTileHeight{ 150u };
    static constexpr unsigned int kTileWidth{ 100u };

    using TileToTextureNameMap =
        const std::unordered_map<TileType, std::string_view>;

    inline static const TileToTextureNameMap kTileToTextureMap {
        { TileType::Forest, "forest" },
        { TileType::Coast, "coast" },
        { TileType::Water, "water" },
        { TileType::Peat, "peat_empty" },
        { TileType::Hill, "hill" },
        { TileType::Mountain, "mountain" }
    };

    Tile(TileType type, const IResourceManager& res_mgr) :
        mType{ type }
    {
        if (type != TileType::None) {
            mObject.setTexture(res_mgr.GetTextureByName(kTileToTextureMap
                                                    .find(type)->second), true);
        }
    };

    TileInfo GetTileInfo() const
    {
        return TileInfo{ mObject.getPosition(), mType };
    }

    bool IsValid() const noexcept { return mType != TileType::None; }
};


inline Tile::TileType operator++ (Tile::TileType& type) {
    if (type == Tile::TileType::End) {
        return type;
    }
    type = static_cast<Tile::TileType>(static_cast<int>(type) + 1);
    return type;
}

inline bool operator==(const Tile::TileInfo& lhs,
                       const Tile::TileInfo& rhs)
{
    return !std::islessgreater(lhs.coord.x, rhs.coord.x) &&
        !std::islessgreater(lhs.coord.y, rhs.coord.y) &&
        lhs.type == rhs.type;
}

#endif // TILE_HPP_