#include "editor.h"
#include <QFileDialog>
#include <QFont>
#include <QFile>
#include <QTextStream>
#include <QAction>
#include <string>
#include <QColorDialog>
#include <QFontDialog>
#include <shlwapi.h>
#include <windows.h>




editor::editor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	fileMenu = ui.fileMenu;
	compileMenu = ui.compileMenu;
	textEditField = ui.textEdit;
	fontEdit = ui.fontButton;
	fontColorEdit = ui.colorButton;
	connect(fontEdit, SIGNAL(released()), this, SLOT(changeFont()));
	connect(fontColorEdit, SIGNAL(released()), this, SLOT(changeFontColor()));
	connect(ui.open, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(ui.create, SIGNAL(triggered()), this, SLOT(makeFile()));
	connect(ui.save, SIGNAL(triggered()), this, SLOT(saveFile()));
	connect(ui.compile, SIGNAL(triggered()), this, SLOT(compileFile()));
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

void editor::changeFont() {
	bool ok;
	QFont font = QFontDialog::getFont(&ok, this);
	if (ok) textEditField->setFont(font);
	else return;
}

void editor::changeFontColor() {
	QColor selected = QColorDialog::getColor();
	textEditField->setTextColor(selected);
}

void editor::compileFile() {
	compiledFileName = QFileDialog::getSaveFileName();
	ShellExecuteA(0, "cmd.exe", "c:\\tmp\\prog.exe", "keys", 0, SW_SHOWNORMAL);
	system("");
}