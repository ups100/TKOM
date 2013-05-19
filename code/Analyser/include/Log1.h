///////////////////////////////////////////////////////////
//  Log1.h
//  Implementation of the Class Log1
//  Created on:      19-maj-2013 18:10:40
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_940C978A_7D43_44bc_B7FB_91EAD5D96A77__INCLUDED_)
#define EA_940C978A_7D43_44bc_B7FB_91EAD5D96A77__INCLUDED_

#include "Reading.h"
#include "Log1Base.h"
#include <QMap>
#include <QVariant>
#include <QString>

namespace TKOM_project {
namespace Analyser {

class Log1 : public Reading, public Log1Base
{

public:
    Log1();
    virtual ~Log1();

    virtual QMap<QString, QVariant> getValues();
    void setHex(const QString& hex);
    void setOwn(const QString& own);
    void setSensDesc(const QString& desc);
    void setSnum(const QString& snum);
    void setTyp(const QString& typ);

private:
    QString m_hex;
    int m_own;
    QString m_sensDesc;
    int m_snum;
    QString m_typ;

};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_940C978A_7D43_44bc_B7FB_91EAD5D96A77__INCLUDED_)
