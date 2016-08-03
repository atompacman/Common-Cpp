#ifndef FXGUILD_COMMON_DEBUG
#define FXGUILD_COMMON_DEBUG

namespace FXG { namespace Common { namespace Debug {

#define TOGGABLE_BLOCK(flagName)  \
    static bool flagName = false; \
    if (flagName)

enum class ConditionModifier
{
    NORMAL_COND,
    NEGATE_COND,
    ALWAYS_TRUE,
    ALWAYS_FALSE
};

#define DEBUG_CONDITION_BLOCK(cond, condModVarName)                           \
    bool resolved = false;                                                    \
    static ConditionModifier condModVarName = ConditionModifier::NORMAL_COND; \
    switch (condModVarName)                                                   \
    {                                                                         \
    case ConditionModifier::NORMAL_COND : resolved =  cond; break;            \
    case ConditionModifier::NEGATE_COND : resolved = !cond; break;            \
    case ConditionModifier::ALWAYS_TRUE : resolved =  true; break;            \
    case ConditionModifier::ALWAYS_FALSE: resolved = false; break;            \
    }                                                                         \
    if (resolved)

}}}

#endif // FXGUILD_COMMON_DEBUG