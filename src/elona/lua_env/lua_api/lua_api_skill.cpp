#include "lua_api_skill.hpp"
#include "../../ability.hpp"
#include "../../character.hpp"
#include "../enums/enums.hpp"
#include "../handle_manager.hpp"



namespace elona
{
namespace lua
{

int LuaApiSkill::level(int skill, LuaCharacterHandle handle)
{
    if (skill < 0 || skill >= 600)
    {
        return -1;
    }
    auto& chara = lua::lua->get_handle_manager().get_ref<Character>(handle);
    return elona::sdata(skill, chara.index);
}

int LuaApiSkill::resistance(
    const EnumString& element_name,
    LuaCharacterHandle handle)
{
    auto& chara = lua::lua->get_handle_manager().get_ref<Character>(handle);
    Element element = LuaEnums::ElementTable.ensure_from_string(element_name);
    return elona::sdata(static_cast<int>(element), chara.index);
}

void LuaApiSkill::bind(sol::table& api_table)
{
    LUA_API_BIND_FUNCTION(api_table, LuaApiSkill, level);
    LUA_API_BIND_FUNCTION(api_table, LuaApiSkill, resistance);
}

} // namespace lua
} // namespace elona
