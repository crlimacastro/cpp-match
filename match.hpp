#pragma once

#include <variant>
#include <utility>

template <typename... ts>
struct match_arms_fnctor : ts...
{
    using ts::operator()...;
};

/*
type matching function for std::variants
e.g.
std::variant<int, float> my_variant;
fae::match(
    my_variant,
    [&](int value) {
        // do something if int type value
    },
    [&](float value) {
        // do something if float type value
    },
    [&](auto value) {
        // do something generic for all other types
});
*/
template <typename... ts, typename... tarms>
constexpr auto match(std::variant<ts...> variant, tarms &&...arms)
{
    return std::visit(match_arms_fnctor{std::forward<tarms>(arms)...}, variant);
}
