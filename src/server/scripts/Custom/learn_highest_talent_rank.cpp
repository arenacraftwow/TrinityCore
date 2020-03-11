/* ================================================================
    AzerothCore 3.3.5 module ~ coded by mindsear
	
    Players will automatically learn the highest talent rank
	when they click on a talent spell
	Intended for "instant level 80" private servers
	
   ================================================================ */

#include "Player.h"
#include "ScriptMgr.h"

enum Hunter_Talents
{
    Wyvern_Sting = 19386, 
    Explosive_Shot = 53301, 
    Counter_Attack = 19306,
    Aimed_Shot = 19434,
    Black_Arrow = 3674
};

enum Death_Kight_Talents
{
    Heart_Strike = 55050, 
    Frost_Strike = 49143, 
    Howling_Blast = 49184, 
    Scourge_Strike = 55090, 
    Corpse_Explosion = 49158
};

enum Warrior_Talents
{
    Mortal_Strike = 12294,
    Devastate = 20243
};

enum Paladin_Talents
{
    Holy_Shield = 20925,
    Avengers_Shield = 31935,
    Holy_Shock = 20473,
    Blessing_of_Sanctuary = 20911,
    Greater_Blessing_of_Sanctuary = 25899
};

enum Mage_Talents
{
    Pyroblast = 11366,
    Ice_Barrier = 11426,
    Living_Bomb = 44457,
    Dragons_Breath = 31661,
    Blast_Wave = 11113,
    Arcane_Barrage = 44425
};

enum Warlock_Talents
{
    Shadowburn = 17877,
    Shadowfury = 30283,
    Unstable_Affliction = 30108,
    Chaos_Bolt = 50796,
    Haunt = 48181,
    Dark_Pact = 18220
};

enum Rogue_Talents
{
    Hemorrhage = 16511, 
    Mutilate = 1329
};

enum Priest_Talents
{
    Vampiric_Touch = 34914,
    Penance = 47540, 
    Lightwell = 724, 
    Desperate_Prayer = 19236, 
    Circle_of_Healing = 34861, 
    Mind_Flay = 15407
};

enum Shaman_Talents
{
    Riptide = 61295,
    Earth_Shield = 974,
    Totem_of_Wrath = 30706,
    Thunderstorm = 51490
};

enum Druid_Talents
{
    Typhoon = 50516, 
    Starfall = 48505, 
    Wild_Growth = 48438, 
    Insect_Swarm = 5570, 
    Mangle_Cat = 33876, 
    Mangle_Bear = 33878 
};

enum WeaponProficiencies
{
    BLOCK = 107,
    BOWS = 264,
    CROSSBOWS = 5011,
    DAGGERS = 1180,
    FIST_WEAPONS = 15590,
    GUNS = 266,
    ONE_H_AXES = 196,
    ONE_H_MACES = 198,
    ONE_H_SWORDS = 201,
    POLEARMS = 200,
    SHOOT = 5019,
    STAVES = 227,
    TWO_H_AXES = 197,
    TWO_H_MACES = 199,
    TWO_H_SWORDS = 202,
    WANDS = 5009,
    THROW_WAR = 2567
};

enum ARMOR_TYPES
{
    PLATE_MAIL = 750,
    MAIL = 8737
};


static void LearnPlateMailSpells(Player* player)
{
    switch (player->GetClass())
    {
    case CLASS_WARRIOR:
    case CLASS_PALADIN:
    case CLASS_DEATH_KNIGHT:
        player->LearnSpell(PLATE_MAIL, true);
        break;
    case CLASS_SHAMAN:
    case CLASS_HUNTER:
        player->LearnSpell(MAIL, true);
        break;
    default:
        break;
    }
}

static void LearnWeaponSkills(Player* player)
{
    WeaponProficiencies wepSkills[] = {
        BLOCK, BOWS, CROSSBOWS, DAGGERS, FIST_WEAPONS, GUNS, ONE_H_AXES, ONE_H_MACES,
        ONE_H_SWORDS, POLEARMS, SHOOT, STAVES, TWO_H_AXES, TWO_H_MACES, TWO_H_SWORDS, WANDS, THROW_WAR
    };

    uint32 size = 17;

    for (uint32 i = 0; i < size; ++i)
        if (player->HasSpell(wepSkills[i]))
            continue;

    switch (player->GetClass())
    {
    case CLASS_WARRIOR:
        player->LearnSpell(THROW_WAR, false);
        player->LearnSpell(TWO_H_SWORDS, false);
        player->LearnSpell(TWO_H_MACES, false);
        player->LearnSpell(TWO_H_AXES, false);
        player->LearnSpell(STAVES, false);
        player->LearnSpell(POLEARMS, false);
        player->LearnSpell(ONE_H_SWORDS, false);
        player->LearnSpell(ONE_H_MACES, false);
        player->LearnSpell(ONE_H_AXES, false);
        player->LearnSpell(GUNS, false);
        player->LearnSpell(FIST_WEAPONS, false);
        player->LearnSpell(DAGGERS, false);
        player->LearnSpell(CROSSBOWS, false);
        player->LearnSpell(BOWS, false);
        player->LearnSpell(BLOCK, false);
        break;
    case CLASS_PRIEST:
        player->LearnSpell(WANDS, false);
        player->LearnSpell(STAVES, false);
        player->LearnSpell(SHOOT, false);
        player->LearnSpell(ONE_H_MACES, false);
        player->LearnSpell(DAGGERS, false);
        break;
    case CLASS_PALADIN:
        player->LearnSpell(TWO_H_SWORDS, false);
        player->LearnSpell(TWO_H_MACES, false);
        player->LearnSpell(TWO_H_AXES, false);
        player->LearnSpell(POLEARMS, false);
        player->LearnSpell(ONE_H_SWORDS, false);
        player->LearnSpell(ONE_H_MACES, false);
        player->LearnSpell(ONE_H_AXES, false);
        player->LearnSpell(BLOCK, false);
        break;
    case CLASS_ROGUE:
        player->LearnSpell(ONE_H_SWORDS, false);
        player->LearnSpell(ONE_H_MACES, false);
        player->LearnSpell(ONE_H_AXES, false);
        player->LearnSpell(GUNS, false);
        player->LearnSpell(FIST_WEAPONS, false);
        player->LearnSpell(DAGGERS, false);
        player->LearnSpell(CROSSBOWS, false);
        player->LearnSpell(BOWS, false);
        break;
    case CLASS_DEATH_KNIGHT:
        player->LearnSpell(TWO_H_SWORDS, false);
        player->LearnSpell(TWO_H_MACES, false);
        player->LearnSpell(TWO_H_AXES, false);
        player->LearnSpell(POLEARMS, false);
        player->LearnSpell(ONE_H_SWORDS, false);
        player->LearnSpell(ONE_H_MACES, false);
        player->LearnSpell(ONE_H_AXES, false);
        break;
    case CLASS_MAGE:
        player->LearnSpell(WANDS, false);
        player->LearnSpell(STAVES, false);
        player->LearnSpell(SHOOT, false);
        player->LearnSpell(ONE_H_SWORDS, false);
        player->LearnSpell(DAGGERS, false);
        break;
    case CLASS_SHAMAN:
        player->LearnSpell(TWO_H_MACES, false);
        player->LearnSpell(TWO_H_AXES, false);
        player->LearnSpell(STAVES, false);
        player->LearnSpell(ONE_H_MACES, false);
        player->LearnSpell(ONE_H_AXES, false);
        player->LearnSpell(FIST_WEAPONS, false);
        player->LearnSpell(DAGGERS, false);
        player->LearnSpell(BLOCK, false);
        break;
    case CLASS_HUNTER:
        player->LearnSpell(THROW_WAR, false);
        player->LearnSpell(TWO_H_SWORDS, false);
        player->LearnSpell(TWO_H_AXES, false);
        player->LearnSpell(STAVES, false);
        player->LearnSpell(POLEARMS, false);
        player->LearnSpell(ONE_H_SWORDS, false);
        player->LearnSpell(ONE_H_AXES, false);
        player->LearnSpell(GUNS, false);
        player->LearnSpell(FIST_WEAPONS, false);
        player->LearnSpell(DAGGERS, false);
        player->LearnSpell(CROSSBOWS, false);
        player->LearnSpell(BOWS, false);
        break;
    case CLASS_DRUID:
        player->LearnSpell(TWO_H_MACES, false);
        player->LearnSpell(STAVES, false);
        player->LearnSpell(POLEARMS, false);
        player->LearnSpell(ONE_H_MACES, false);
        player->LearnSpell(FIST_WEAPONS, false);
        player->LearnSpell(DAGGERS, false);
        break;
    case CLASS_WARLOCK:
        player->LearnSpell(WANDS, false);
        player->LearnSpell(STAVES, false);
        player->LearnSpell(SHOOT, false);
        player->LearnSpell(ONE_H_SWORDS, false);
        player->LearnSpell(DAGGERS, false);
        break;
    default:
        break;
    }
    player->UpdateWeaponsSkillsToMaxSkillsForLevel();

}


class learn_highest_talent_rank : public PlayerScript
{
public:
    learn_highest_talent_rank() : PlayerScript("learn_highest_talent_rank") {}

    void OnLogin(Player* p, bool firstLogin) override 
    {
        if (firstLogin) {
             // heartstone
            WorldLocation loc(4116.0, 3065.0, 339.50, 4.9);
            p->SetHomebind(loc, 3738);
            p->AddItem(6948,1);

            // riding skills
            p->LearnSpell(34091, false);
            p->LearnSpell(54197, false);

            LearnWeaponSkills(p);
            LearnPlateMailSpells(p);
        }
    }

    // Called when a player's free talent points change (right before the change is applied)
    void OnFreeTalentPointsChanged(Player* player, uint32 /* points */)
    {
        uint32 Talent_First_Rank[] =
        {
            Wyvern_Sting,
            Explosive_Shot,
            Counter_Attack,
            Aimed_Shot,
            Black_Arrow,

            Heart_Strike,
            Frost_Strike,
            Howling_Blast,
            Scourge_Strike,
            Corpse_Explosion,

            Mortal_Strike,
            Devastate,

            Holy_Shield,
            Avengers_Shield,
            Holy_Shock,

            Pyroblast,
            Ice_Barrier,
            Living_Bomb,
            Dragons_Breath,
            Blast_Wave,
            Arcane_Barrage,

            Shadowburn,
            Shadowfury,
            Unstable_Affliction,
            Chaos_Bolt,
            Haunt,
            Dark_Pact,

            Hemorrhage,
            Mutilate,

            Vampiric_Touch,
            Penance,
            Lightwell,
            Desperate_Prayer,
            Circle_of_Healing,
            Mind_Flay,

            Riptide,
            Earth_Shield,
            Totem_of_Wrath,
            Thunderstorm,

            Typhoon,
            Starfall,
            Wild_Growth,
            Insect_Swarm,
            Mangle_Cat,
            Mangle_Bear
        };

        for (uint32 i = 0; i < sizeof(Talent_First_Rank) / sizeof(uint32); i++)
            if (player->HasSpell(Talent_First_Rank[i]))
                player->LearnSpellHighestRank(Talent_First_Rank[i]);

        // Special case for Paladin-protection
        if (player->HasSpell(Blessing_of_Sanctuary))
            player->LearnSpell(Greater_Blessing_of_Sanctuary, false);
    }
};

void AddHighestTalentRankScript()
{
    new learn_highest_talent_rank();
}