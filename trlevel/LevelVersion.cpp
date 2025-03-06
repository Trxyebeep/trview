#include "LevelVersion.h"

namespace trlevel
{
    // Converts the level version number into a level version enumeration.
    // This will never return tomb5 as more information is required in order to 
    // make that determination.
    // version: The version to convert.
    // Returns: The level version.
    PlatformAndVersion convert_level_version(uint32_t version)
    {
        if (version == 0x34585254)
        {
            return { .platform = Platform::PC, .version = LevelVersion::Tomb4, .remastered = true, .raw_version = version };
        }
        else if (version == 0x35585254)
        {
            return { .platform = Platform::PC, .version = LevelVersion::Tomb5, .remastered = true, .raw_version = version };
        }

        switch (version & 0xff)
        {
        case 0x20:
            return { .platform = (version & 0xff00) ? Platform::PSX : Platform::PC, .version = LevelVersion::Tomb1, .raw_version = version };
        case 0x2D:
            return { .platform = Platform::PC, .version = LevelVersion::Tomb2, .raw_version = version };
        case 0x34:
        case 0x38:
            return { .platform = Platform::PC, .version = LevelVersion::Tomb3, .raw_version = version }; 
        case 0xc8:
        case 0xcb:  //TR3 PSX ECTS Demo
            return { .platform = Platform::PSX, .version = LevelVersion::Tomb3, .raw_version = version };
        case 0x54:
            return { .platform = Platform::PC, .version = LevelVersion::Tomb4, .raw_version = version };
        }
        return { .platform = Platform::Unknown, .version = LevelVersion::Unknown, .raw_version = version };
    }
}