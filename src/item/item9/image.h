#ifndef IMAGE_H_
#define IMAGE_H_

#include "../../common/common.h"

class CImage
{
public:
    CImage(const std::string& imgDataFileName)
    : m_img_data_file_name(imgDataFileName)
    {
    }

private:
    std::string m_img_data_file_name;
};

#endif
