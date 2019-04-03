#include "editor.h"
#include <QFileDialog>
#include <QFont>
#include <QFile>
#include <QTextStream>
#include <QAction>
#include <string>

editor::editor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	fileMenu = ui.fileMenu;
	textEditField = ui.textEdit;
	fontEdit = ui.fontBox;
	fontSizeEdit = ui.fontSizeBox;
	fontColorEdit = ui.fontColorBox;
	for (int i = 2; i < 28; i += 1) {
		fontSizeEdit->addItem(QString::number(i));
	}
	connect(fontEdit, SIGNAL(&QFontComboBox::currentFontChanged), this, SLOT(changeFont(font)));
	connect(fontSizeEdit, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeFontSize(QString)));
	connect(fontColorEdit, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeFontColor(QString)));
	connect(ui.open, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(ui.create, SIGNAL(triggered()), this, SLOT(makeFile()));
	connect(ui.save, SIGNAL(triggered()), this, SLOT(saveFile()));

}


void editor::openFile() {
	openedFileName = QFileDialog::getOpenFileName();
	QFile openedFile(openedFileName);
	openedFile.open(QIODevice::ReadOnly | QIODevice::Text);
	while (!openedFile.atEnd()){
		QByteArray line = openedFile.readLine();
		textEditField->setText(textEditField->toPlainText() + line + "\n");
}

}

void editor::makeFile() {
	textEditField->clear();
	openedFileName = "clear";
}

void editor::saveFile() {
	openedFileName = QFileDialog::getSaveFileName();
	QFile out(openedFileName);
	if (out.open(QIODevice::WriteOnly)) {
		QTextStream stream(&out);
		out.close();
	}
}

void editor::changeFont(const QFont &font) {
	QFont f = font;
	f.setPixelSize(fontSizeEdit->currentIndex());
	textEditField->setFont(f);
}

void editor::changeFontSize(const QString& selected) {
	textEditField->setFontPointSize(selected.toInt());
}

void editor::changeFontColor(const QString& selected) {
	
}