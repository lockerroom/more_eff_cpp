#ifndef AUDIO_CLIP_H_
#define AUDIO_CLIP_H_

#include "../../common/common.h"

class CAudioClip
{
public:
    CAudioClip(const std::string& audioDataFileName)
    : m_audio_data_file_name(audioDataFileName)
    {
        
    }

private:
    std::string m_audio_data_file_name;
};

#endif