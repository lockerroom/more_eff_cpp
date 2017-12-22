/*****************************************************************************/
/* File Name: rc_widget.h                                                  */
/* Description: class CRCWidget, like class CMyString         */
/*                                                                                    */
/* Author: TyLuo                                                               */
/* Creation Date: Dece 19, 2017                                      */
/* Last Revision:                                                              */
/*****************************************************************************/

#ifndef RC_WIDGET_H_
#define RC_WIDGET_H_

#include "../../common/common.h"
#include "rci_ptr.h"
#include "widget.h"

class CRCWidget
{
public:
    CRCWidget(int);
    void doThis();
    int showWhat() const;

private:
    CRIPtr<CWidget> value;
};

#endif