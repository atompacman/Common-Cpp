#ifndef FXGUILD_COMMON_PARSABLEENUM
#define FXGUILD_COMMON_PARSABLEENUM

#include <map>
#include <sstream>

#define DECLARE_ENUM_WITH_STRING_CONVERSION_MAPS(Name, ...)                                 \
                                                                                            \
    enum class Name                                                                         \
    {                                                                                       \
        __VA_ARGS__                                                                         \
    };                                                                                      \
                                                                                            \
    std::map<Name, std::string> const Name##ToStr = createEnumToStrMap<Name>(#__VA_ARGS__); \
    std::map<std::string, Name> const StrTo##Name = createStrToEnumMap<Name>(Name##ToStr);

template <typename E>
std::map<E, std::string> createEnumToStrMap(std::string i_Elements)
{
    std::map<E, std::string> map;
    std::stringstream ss(i_Elements);
    std::string elem;

    int i = 0;
    while (std::getline(ss, elem, ',')) 
    {
        map[E(i)] = i == 0 ? elem : elem.substr(1);
        ++i;
    }
    return map;
}

template <typename E>
std::map<std::string, E> createStrToEnumMap(std::map<E, std::string> const & i_Map)
{
    std::map<std::string, E> map;
    for (auto const & entry : i_Map)
    {
        map[entry.second] = entry.first;
    }
    return map;
}

#endif // FXGUILD_COMMON_PARSABLEENUM