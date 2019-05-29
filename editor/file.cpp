#include "file.h"

QByteArray fileInstance::open(QString& name) {
	QFile openedFile(name);
	openedFile.open(QIODevice::ReadOnly | QIODevice::Text);
	return openedFile.readAll();
}

void fileInstance::save(QString& name, QString& text) {
	QFile out(name);
	if (out.open(QIODevice::WriteOnly)) {
		QTextStream stream(&out);
		stream << text;
		out.flush();
		out.close();
	}
}