/**
 * @file FileReader.h
 *
 * @date 19-05-2013
 *
 * @author Opasiak Krzsztof <ups100@tlen.pl>
 *
 * @brief Implementation of the Class TKOM_project::Analyser::FileReader
 *
 * @par Project
 * This is a part of project realized on Warsaw University of Technology
 * on TKOM lectures. Project was created to IPMI log analysis.
 */

#if !defined(EA_C5749D62_4930_4767_9B73_45CB2D0E0467__INCLUDED_)
#define EA_C5749D62_4930_4767_9B73_45CB2D0E0467__INCLUDED_

#include <QString>
#include <QFile>

namespace TKOM_project {
namespace Analyser {

class FileReader
{

public:
    /**
     * @brief Constructor
     *
     * @param[in] source path to file
     */
    FileReader(const QString& source);

    /**
     * @brief Destructor
     */
    virtual ~FileReader();

    /**
     * @brief Adjusts the position in file with offset length
     *
     * @param offset to be set
     */
    void adjustPosition(int offset);

    /**
     * @brief Gets next character from file
     *
     * @return character from file
     */
    char getNextChar();

private:
    /**
     * @brief Source file
     */
    QFile m_file;

    /**
     * @brief Current position in file.
     */
    qint64 m_position;
};

} //namespace Analyser
} //namespace TKOM_project
#endif // !defined(EA_C5749D62_4930_4767_9B73_45CB2D0E0467__INCLUDED_)
