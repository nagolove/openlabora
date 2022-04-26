#ifndef ENUMMAP_HPP_
#define ENUMMAP_HPP_

#include <type_traits>
#include <utility>
#include <array>
#include <stdexcept>

namespace OpenLabora
{

/**
 * EnumMap - associative container that contains key-value pairs. Enum members
 * are used as keys.
 *
 * @tparam TEnumKey - Enum to use as keys. Enum must be contiguous. Enum must
 * contain members ::Begin and ::End to help calculate its size.
 *
 * @tparam TValue - Type of mapped values
 */
template<class TEnumKey, class TValue>
requires requires
{
    std::is_enum_v<TEnumKey>;
    { TEnumKey::Begin };
    { TEnumKey::End };
    TEnumKey::Begin < TEnumKey::End;
}
class EnumMap final
{
    using Item = std::pair<TEnumKey, TValue>;

    static constexpr size_t kItemCount =
        static_cast<size_t>(TEnumKey::End) - static_cast<size_t>(TEnumKey::Begin);

    std::array<TValue, kItemCount> mItems;

public:
    constexpr const TValue& Get(TEnumKey key) const
    {
        if (key < TEnumKey::Begin || key >= TEnumKey::End) {
            throw std::range_error("EnumMap: Enum value outside of range");
        }

        return mItems[static_cast<size_t>(key)];
    }

    TValue& Get(TEnumKey key)
    {
        if (key < TEnumKey::Begin || key >= TEnumKey::End) {
            throw std::range_error("EnumMap: Enum value outside of range");
        }

        return mItems[static_cast<size_t>(key)];
    }

    // @arg list - initializer that contains ALL keys of enum and maps all values
    constexpr EnumMap(const std::initializer_list<Item>& list)
    {
        if (list.size() != kItemCount) {
            throw std::invalid_argument("Not all enum values are used");
        }

        for (size_t i = 0; auto&& item : list) {
            const auto index = static_cast<size_t>(item.first);
            const bool is_in_range = item.first >= TEnumKey::Begin &&
                                     item.first < TEnumKey::End;

            if (!is_in_range) {
                throw std::invalid_argument("Enum value outside of range");
            }

            for (size_t j = 0; auto&& inner : list) {
                if (j == i) {
                    ++j;
                    continue;
                }

                if (inner.first == item.first) {
                    constexpr std::string_view err_msg =
                        "Multiple values for one key are not allowed";
                    throw std::invalid_argument(err_msg.data());
                }
                ++j;
            }

            mItems[static_cast<size_t>(item.first)] = item.second;
            mItems[index] = item.second;
            ++i;
        }
    }

    constexpr size_t GetSize() const noexcept
    { return kItemCount; }
};

} // namespace OpenLabora

#endif // ENUMMAP_HPP_