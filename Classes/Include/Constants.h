//
//  Constants.h
//  TyphoonTycoon
//
//  Created by calintz1jin on 2018. 7. 10..
//

#ifndef Constants_h
#define Constants_h

//! @brief 타일의 크기.
const int TILE_WIDTH    = 10;
const int TILE_HEIGHT   = 10;

//! @brief 타일의 종류.
enum TAG_TILE_TYPE
{
    TTT_NONE    = -1,
    TTT_LAND    = 0,
    TTT_WATER,
    
    TTT_END
};

//! @brief 타일의 상태
enum TAG_TILE_STATE
{
    TTS_NORMAL  = 0,
    TTS_DAMAGED_25,
    TTS_DAMAGED_50,
    TTS_DAMAGED_75,
    TTS_DAMAGED_100,
    
    
    TTS_END
};

#endif /* Constants_h */
