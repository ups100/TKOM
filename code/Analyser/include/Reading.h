///////////////////////////////////////////////////////////
//  Reading.h
//  Implementation of the Class Reading
//  Created on:      19-maj-2013 18:10:42
//  Original author: kopasiak
///////////////////////////////////////////////////////////

#if !defined(EA_FBA7C0B1_879C_46ef_A585_5ADEA78C21EB__INCLUDED_)
#define EA_FBA7C0B1_879C_46ef_A585_5ADEA78C21EB__INCLUDED_

class Reading
{

public:
	Reading();
	virtual ~Reading();

	QMap<QString, QVariant> getReadingData();
	void setUnit(const QString& unit);
	void setValue(const QString& value);

private:
	QString m_unit;
	float m_value;

};
#endif // !defined(EA_FBA7C0B1_879C_46ef_A585_5ADEA78C21EB__INCLUDED_)
