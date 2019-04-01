#include "editor.h"
//#include "textEdit.h"
#include <QFileDialog>
#include <QFont>
#include <QFile>
#include <QTextStream>

editor::editor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	fileMenu = ui.fileMenu;
	textEditField = ui.textEdit;
	fontEdit = ui.fontBox;
	fontSizeEdit = ui.fontSizeBox;
	fontColorEdit = ui.fontColorBox;
	connect(fontEdit, SIGNAL(currentFontChanged(const QFont &font)), this, SLOT(changeFont(font)));
	connect(fontSizeEdit, SIGNAL(activated()), this, SLOT(changeFontSize()));
	connect(fontColorEdit, SIGNAL(activated()), this, SLOT(changeFontColor()));
	connect(fileMenu, SIGNAL(), this, SLOT(openFile()));
}

void editor::openFile() {
	openedFileName = QFileDialog::getOpenFileName();
	QFile openedFile(openedFileName);
	QTextStream in(&openedFile);
	QString line = in.readLine();
	while (!line.isNull()) {
		textEditField->setText(textEditField->toPlainText() + line + "\n");
	}
}

void editor::changeFont(const QFont &font) {
	textEditField->setFont(font);
}

void editor::changeFontSize() {

}

void editor::changeFontColor() {

}