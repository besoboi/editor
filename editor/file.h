#include <QFile>
#include <QTextStream>

class fileInstance {
public:
	QByteArray open(QString& name);
	void save(QString& name, QString& text);
};