# cpp match

A type matching function for ``std::variant``s with support for a variadic number of functions.

And the variant being matched goes in front (cough cough, why std::visit? cough cough).

## Usage

```cpp
#include <print>
#include "match.hpp"

auto main() -> int
{
    std::variant<int, float, const char *> my_variant = 1.0f;
    match(
        my_variant,
        [](int value)
        {
            std::println("int: {}", value);
        },
        [](float value)
        {
            std::println("float: {}", value);
        },
        [](auto value)
        {
            std::println("other: {}", value);
        });
    
    const auto value = match(
        my_variant,
        [](int value)
        {
            return 0;
        },
        [](float value)
        {
            return 1;
        },
        [](auto value)
        {
            return 2;
        });
    std::println("{}", value);
}
```