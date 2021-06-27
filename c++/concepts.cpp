#define __cpp_lib_concepts
#include <concepts>
#include <iostream>

/**
 * @brief Concept constraining a type to only types which uses a type
 * called `type`.
 * 
 * @tparam T 
 */
template <typename T>
concept HasTypeMember = requires {
    typename T::type;
};

template <typename T>
concept HasTypeId = requires {
    {T::value} -> std::convertible_to<int>;
};

template <typename T, typename U>
concept CanAdd = requires(T t, U u) {
    {t + u} -> std::same_as<T>;
};

template <typename T, typename U>
concept Amalgam = requires {
    HasTypeMember<T>;
    HasTypeId<T>;
    CanAdd<T, U>;
};

class AmalgamImplementor {
    public:
        using type = double;
        static const int value = 5;
        int internal;
        AmalgamImplementor(void) noexcept : internal(0) {}
        AmalgamImplementor(int internal) noexcept: internal(internal) {}
        AmalgamImplementor operator+(int another) {
            return AmalgamImplementor(internal + another);
        }
};

template <typename T>
    requires Amalgam<T, int>
T add_five(T &t) {
    return t + 5;
}

int main(int argc, char **argv) {
    AmalgamImplementor a(0);
    auto b = add_five(a);
    std::cout << b.internal << std::endl;
    return 0;
}