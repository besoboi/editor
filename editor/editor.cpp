#include "editor.h"
#include <QFileDialog>
#include <QFont>
#include <QFile>
#include <QTextStream>
#include <QAction>
#include <string>
#include <QColorDialog>
#include <QFontDialog>
#include <QSysInfo>

editor::editor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	codec = QTextCodec::codecForName("Windows-1251");
	fileMenu = ui.fileMenu;
	textEditField = ui.textEdit;
	fontEdit = ui.fontButton;
	fontColorEdit = ui.colorButton;
	codecEdit = ui.codecComboBox;
	bgColorButton = ui.backgroundColorButton;
	codeHighlighter = new Highlighter(textEditField->document());
	keyCtrlS = new QShortcut(this);
	keyCtrlS->setKey(Qt::CTRL + Qt::Key_S);

	connect(fontEdit, SIGNAL(released()), this, SLOT(changeFont()));
	connect(fontColorEdit, SIGNAL(released()), this, SLOT(changeFontColor()));
	connect(bgColorButton, SIGNAL(released()), this, SLOT(bgColorChange()));
	connect(ui.open, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(ui.create, SIGNAL(triggered()), this, SLOT(makeFile()));
	connect(ui.save, SIGNAL(triggered()), this, SLOT(saveFile()));
	connect(ui.fastSave, SIGNAL(triggered()), this, SLOT(fastSave()));
	connect(ui.compile, SIGNAL(triggered()), this, SLOT(compile()));
	connect(keyCtrlS, SIGNAL(activated()), this, SLOT(fastSave()));
	connect(codecEdit, SIGNAL(activated(int)) , this, SLOT(codecChange()));
}

void editor::openFile() {
	makeFile();
	openedFileName = QFileDialog::getOpenFileName();
	QFile openedFile(openedFileName);
	openedFile.open(QIODevice::ReadOnly | QIODevice::Text);
	while (!openedFile.atEnd()){
		QString line = codec->toUnicode(openedFile.readLine());
		textEditField->setText(textEditField->toPlainText() + line + "\n");
	}
	codeHighlighter = new Highlighter(textEditField->document());
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
		QString text = textEditField->toPlainText();
		stream << text;
		out.flush();
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

void editor::fastSave() {
	if (openedFileName != "clear") {
		QFile out(openedFileName);
		if (out.open(QIODevice::WriteOnly)) {
			QTextStream stream(&out);
			QString text = textEditField->toPlainText();
			stream << text;
			out.flush();
			out.close();
		}
	}
}

void editor::codecChange() {
	if (codecEdit->currentIndex() != -1) {
		if (codecEdit->currentIndex() == 0) codec = QTextCodec::codecForName("Windows-1251");
		if (codecEdit->currentIndex() == 1) codec = QTextCodec::codecForName("UTF-8");
		if (codecEdit->currentIndex() == 2) codec = QTextCodec::codecForName("IBM 866");
		if (codecEdit->currentIndex() == 3) codec = QTextCodec::codecForName("CP-1251");
	}
	
}

void editor::bgColorChange() {
	QColor selected = QColorDialog::getColor();
	
	textEditField->setStyleSheet("QTextEdit { background-color : " + selected.name() + "}");
};

void editor::compile() {
	
};

