#include "editor.h"
#include <QFileDialog>
#include <QFont>
#include <QAction>
#include <string>
#include <QColorDialog>
#include <QFontDialog>
#include <QSysInfo>

editor::editor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	_codec = QTextCodec::codecForName("Windows-1251");
	_fileMenu = ui.fileMenu;
	_textEditField = ui.textEdit;
	_fontEdit = ui.fontButton;
	_fontColorEdit = ui.colorButton;
	_codecEdit = ui.codecComboBox;
	_bgColorButton = ui.backgroundColorButton;
	_keyCtrlS = new QShortcut(this);
	_keyCtrlS->setKey(Qt::CTRL + Qt::Key_S);
	_hlCheckBox = ui.hlCheckBox;
	_selectionColor = ui.selectionColor;
	_selectionTextColor = ui.selectionTextColor;
	_textBGColor = ui.textColorBG;
	#ifdef Q_OS_WIN
	ui.compile->setDisabled(true);
	#endif

	connect(_fontEdit, SIGNAL(released()), this, SLOT(changeFont()));
	connect(_fontColorEdit, SIGNAL(released()), this, SLOT(changeFontColor()));
	connect(_bgColorButton, SIGNAL(released()), this, SLOT(bgColorChange()));
	connect(ui.open, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(ui.create, SIGNAL(triggered()), this, SLOT(makeFile()));
	connect(ui.save, SIGNAL(triggered()), this, SLOT(saveFile()));
	connect(ui.fastSave, SIGNAL(triggered()), this, SLOT(fastSave()));
	connect(ui.compile, SIGNAL(triggered()), this, SLOT(compile()));
	connect(_keyCtrlS, SIGNAL(activated()), this, SLOT(fastSave()));
	connect(_codecEdit, SIGNAL(activated(int)) , this, SLOT(codecChange()));
	connect(_hlCheckBox, SIGNAL(stateChanged(int)), this, SLOT(turnOnHL()));
	connect(_selectionColor, SIGNAL(released()), this, SLOT(selectionColorChange()));
	connect(_selectionTextColor, SIGNAL(released()), this, SLOT(selectionTextColorChange()));
	connect(_textBGColor, SIGNAL(released()), this, SLOT(textBGColorChange()));
}

void editor::openFile() {
	makeFile();
	_openedFileName = QFileDialog::getOpenFileName();
	QString text = _codec->toUnicode(_file.open(_openedFileName));
	_textEditField->setText(text);
}

void editor::makeFile() {
	_textEditField->clear();
	_openedFileName = "clear";
}

void editor::saveFile() {
	_openedFileName = QFileDialog::getSaveFileName();
	_file.save(_openedFileName, _textEditField->toPlainText());
}

void editor::changeFont() {
	bool ok;
	QFont font = QFontDialog::getFont(&ok, this);
	if (ok) {
		_textEditField->setFont(font);
	}
	else {
		return;
	}
}

void editor::changeFontColor() {
	QColor selected = QColorDialog::getColor();
	_textEditField->setTextColor(selected);
}

void editor::fastSave() {
	if (_openedFileName != "clear") {
		_file.save(_openedFileName, _textEditField->toPlainText());
	}
}

void editor::codecChange() {
	if (_codecEdit->currentIndex() != -1) {
		if (_codecEdit->currentIndex() == 0) {
			_codec = QTextCodec::codecForName("Windows-1251");
		}
		if (_codecEdit->currentIndex() == 1) {
			_codec = QTextCodec::codecForName("UTF-8");
		}
		if (_codecEdit->currentIndex() == 2) {
			_codec = QTextCodec::codecForName("IBM 866");
		}
		if (_codecEdit->currentIndex() == 3) {
			_codec = QTextCodec::codecForName("CP-1251");
		}
	}
#ifdef Q_OS_WIN 
	QString text = _codec->toUnicode(QTextCodec::codecForName("Windows-1251")->fromUnicode(_textEditField->toPlainText().toStdString().c_str()));
	_textEditField->setText(text);
#endif 
#ifdef Q_OS_LINUX
	QString text = _codec->toUnicode(QTextCodec::codecForName("Windows-1251")->fromUnicode(_textEditField->toPlainText().toStdString().c_str()));
	_textEditField->setText(text);
#endif 
}

void editor::bgColorChange() {
	QColor selected = QColorDialog::getColor();
	_textEditField->setStyleSheet("QTextEdit { background-color : " + selected.name() + "}");
}

void editor::compile() {
#ifdef Q_OS_LINUX
	if (_openedFileName != "clear"){
		QStringList filePath = _openedFileName.split("/");
		QString newFileName = filePath.takeLst();
		string command = "g++ " + _openedFileName + " -o " + newFileName;
		system(command);
	}
#endif
}

void editor::turnOnHL() {
	highliterIsOn = !highliterIsOn;
	if (highliterIsOn == 1) {
		if (_codeHighlighter) {
		}
		else {
			_codeHighlighter = new Highlighter(_textEditField->document());
		}
	}
	else {
		if (_codeHighlighter) {
			delete _codeHighlighter;
			_codeHighlighter = NULL;
		}
	}

}

void editor::selectionColorChange() {
	QColor selected = QColorDialog::getColor();
	_textEditField->setStyleSheet("QTextEdit { selection-background-color : " + selected.name() + "}");
}

void editor::selectionTextColorChange() {
	QColor selected = QColorDialog::getColor();
	_textEditField->setStyleSheet("QTextEdit { selection-color : " + selected.name() + "}");
}

void editor::textBGColorChange() {
	QColor selected = QColorDialog::getColor();
	_textEditField->setTextBackgroundColor(selected);
}