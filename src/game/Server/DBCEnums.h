/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef DBCENUMS_H
#define DBCENUMS_H

// Client expected level limitation, like as used in DBC item max levels for "until max player level"
// use as default max player level, must be fit max level for used client
// also see MAX_LEVEL and STRONG_MAX_LEVEL define
#define DEFAULT_MAX_LEVEL 60

// client supported max level for player/pets/etc. Avoid overflow or client stability affected.
// also see GT_MAX_LEVEL define
#define MAX_LEVEL    100

// Server side limitation. Base at used code requirements.
// also see MAX_LEVEL and GT_MAX_LEVEL define
#define STRONG_MAX_LEVEL 255

#pragma pack(push, 1)

struct DBCPosition2D
{
    float X;
    float Y;
};

struct DBCPosition3D
{
    float X;
    float Y;
    float Z;
};

#pragma pack(pop)

enum AreaTeams
{
    AREATEAM_NONE  = 0,
    AREATEAM_ALLY  = 2,
    AREATEAM_HORDE = 4
};

enum AreaFlags
{
    AREA_FLAG_SNOW                  = 0x00000001,           // snow (only Dun Morogh, Naxxramas, Razorfen Downs and Winterspring)
    AREA_FLAG_UNK1                  = 0x00000002,           // unknown, (only Naxxramas and Razorfen Downs)
    AREA_FLAG_UNK2                  = 0x00000004,           // Only used on development map
    AREA_FLAG_SLAVE_CAPITAL         = 0x00000008,           // slave capital city flag?
    AREA_FLAG_UNK3                  = 0x00000010,           // unknown
    AREA_FLAG_SLAVE_CAPITAL2        = 0x00000020,           // slave capital city flag?
    AREA_FLAG_DUEL                  = 0x00000040,           // zones where duels allowed
    AREA_FLAG_ARENA                 = 0x00000080,           // arena, both instanced and world arenas
    AREA_FLAG_CAPITAL               = 0x00000100,           // main capital city flag
    AREA_FLAG_CITY                  = 0x00000200,           // only for one zone named "City" (where it located?)
};

enum FactionTemplateFlags
{
    FACTION_TEMPLATE_FLAG_PVP               = 0x00000800,   // flagged for PvP
    FACTION_TEMPLATE_FLAG_CONTESTED_GUARD   = 0x00001000,   // faction will attack players that were involved in PvP combats
};

enum FactionGroupMask
{
    FACTION_GROUP_MASK_PLAYER   = 1,                              // any player
    FACTION_GROUP_MASK_ALLIANCE = 2,                              // player or creature from alliance team
    FACTION_GROUP_MASK_HORDE    = 4,                              // player or creature from horde team
    FACTION_GROUP_MASK_MONSTER  = 8                               // aggressive creature from monster team
                                  // if none flags set then non-aggressive creature
};

enum MapTypes
{
    MAP_COMMON          = 0,
    MAP_INSTANCE        = 1,
    MAP_RAID            = 2,
    MAP_BATTLEGROUND    = 3,
};

enum AbilytyLearnType
{
    ABILITY_LEARNED_ON_GET_PROFESSION_SKILL     = 1,
    ABILITY_LEARNED_ON_GET_RACE_OR_CLASS_SKILL  = 2
};

enum SkillRaceClassInfoFlags
{
    SKILL_FLAG_NONE                     = 0x000,
    SKILL_FLAG_UNK0                     = 0x001,
    SKILL_FLAG_DISPLAY_SILENCED         = 0x002,    // Clientside: no skillup messages
    SKILL_FLAG_UNK2                     = 0x004,
    SKILL_FLAG_UNK3                     = 0x008,
    SKILL_FLAG_MAXIMIZED                = 0x010,    // Always at max value
    SKILL_FLAG_CAN_UNLEARN              = 0x020,
    SKILL_FLAG_UNK6                     = 0x040,
    SKILL_FLAG_DISPLAY_SORTED           = 0x080,    // Clientside: affects spellbook sorting for dependent spells
    SKILL_FLAG_NOT_TRAINABLE            = 0x100,
    SKILL_FLAG_UNK9                     = 0x200,
    SKILL_FLAG_DISPLAY_AS_MONO          = 0x400     // Clientside: appear as greyed out bar (1/1)
};

enum ItemEnchantmentType
{
    ITEM_ENCHANTMENT_TYPE_NONE             = 0,
    ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL     = 1,
    ITEM_ENCHANTMENT_TYPE_DAMAGE           = 2,
    ITEM_ENCHANTMENT_TYPE_EQUIP_SPELL      = 3,
    ITEM_ENCHANTMENT_TYPE_RESISTANCE       = 4,
    ITEM_ENCHANTMENT_TYPE_STAT             = 5,
    ITEM_ENCHANTMENT_TYPE_TOTEM            = 6
};

enum SpellEffectIndex
{
    EFFECT_INDEX_0 = 0,
    EFFECT_INDEX_1 = 1,
    EFFECT_INDEX_2 = 2
};

#define MAX_EFFECT_INDEX 3

enum SpellEffectIndexMask
{
    EFFECT_MASK_INDEX_0 = (1 << EFFECT_INDEX_0),
    EFFECT_MASK_INDEX_1 = (1 << EFFECT_INDEX_1),
    EFFECT_MASK_INDEX_2 = (1 << EFFECT_INDEX_2),
    EFFECT_MASK_ALL = (EFFECT_MASK_INDEX_0 | EFFECT_MASK_INDEX_1 | EFFECT_MASK_INDEX_2)
};

enum SpellFamily
{
    SPELLFAMILY_GENERIC     = 0,
    SPELLFAMILY_UNK1        = 1,                            // events, holidays
    // 2 - unused
    SPELLFAMILY_MAGE        = 3,
    SPELLFAMILY_WARRIOR     = 4,
    SPELLFAMILY_WARLOCK     = 5,
    SPELLFAMILY_PRIEST      = 6,
    SPELLFAMILY_DRUID       = 7,
    SPELLFAMILY_ROGUE       = 8,
    SPELLFAMILY_HUNTER      = 9,
    SPELLFAMILY_PALADIN     = 10,
    SPELLFAMILY_SHAMAN      = 11,
    SPELLFAMILY_UNK2        = 12,
    SPELLFAMILY_POTION      = 13,
    // 14 - unused
    SPELLFAMILY_DEATHKNIGHT = 15,
    // 16 - unused
    SPELLFAMILY_UNK3        = 17
};

#endif
