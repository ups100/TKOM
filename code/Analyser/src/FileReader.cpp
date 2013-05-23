/**
 * @file FileReader.cpp
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

#include "FileReader.h"

namespace TKOM_project {
namespace Analyser {

FileReader::FileReader(const QString& source)
: m_file(source), m_position(0)
{
    if(!m_file.exists()) throw QString("File does not exist");
    if(!m_file.open(QIODevice::ReadOnly))
    {
        throw QString("Unable to open a file.");
    }
}

FileReader::~FileReader()
{
    m_file.close();
}

void FileReader::adjustPosition(int offset)
{
    m_position += offset;
    m_file.seek(m_position);
}

char FileReader::getNextChar()
{
    char ch = '\0';

    m_file.read(&ch, 1);

    return ch;
}

} //namespace Analyser
} //namespace TKOM_project
