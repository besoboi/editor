#include "editor.h"
#include <QFileDialog>
#include <QFont>
#include <QAction>
#include <string>
#include <QColorDialog>
#include <QFontDialog>
#include <QSysInfo>

gui::gui(QWidget *parent)
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
	ui.fastSave->setDisabled(true);
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
	connect(_textEditField, SIGNAL(textChanged()), this, SLOT(refreshText()));
}

void gui::openFile() {
	makeFile();
	ui.fastSave->setDisabled(false);
	_openedFileName = QFileDialog::getOpenFileName();
	QString text = _codec->toUnicode(_file.open(_openedFileName));
	_textEditField->setText(text);
}

void gui::makeFile() {
	_textEditField->clear();
	_openedFileName = "clear";
}

void gui::saveFile() {
	_openedFileName = QFileDialog::getSaveFileName();
	_file.save(_openedFileName, _textEditField->toPlainText());
}

void gui::changeFont() {
	bool ok;
	QFont font = QFontDialog::getFont(&ok, this);
	if (ok) {
		_textEditField->setCurrentFont(font);
	}
	else {
		return;
	}
}

void gui::changeFontColor() {
	QColor selected = QColorDialog::getColor();
	_textEditField->setTextColor(selected);
}

void gui::fastSave() {
	if (_openedFileName != "clear") {
		_file.save(_openedFileName, _textEditField->toPlainText());
	}
}

void gui::codecChange() {
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
	QString text = _codec->toUnicode(textInDefaultCoding.toLocal8Bit());
	_textEditField->blockSignals(true);
	_textEditField->setText(text);
	_textEditField->blockSignals(false);

}

void gui::bgColorChange() {
	QColor selected = QColorDialog::getColor();
	_textEditField->setStyleSheet("QTextEdit { background-color : " + selected.name() + "}");
}

void gui::compile() {
#ifdef Q_OS_LINUX
	if (_openedFileName != "clear"){
		QStringList filePath = _openedFileName.split("/");
		QString newFileName = filePath.takeLast();
		newFileName = newFileName.split(".")[0];
		QString command = "g++ " + _openedFileName + " -o " + newFileName;
		system(qPrintable(command));
		command = filePath.join("/") + "/" + newFileName;
		system(qPrintable(command));
	}
#endif
}

void gui::turnOnHL() {
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

void gui::selectionColorChange() {
	QColor selected = QColorDialog::getColor();
	_textEditField->setStyleSheet("QTextEdit { selection-background-color : " + selected.name() + "}");
}

void gui::selectionTextColorChange() {
	QColor selected = QColorDialog::getColor();
	_textEditField->setStyleSheet("QTextEdit { selection-color : " + selected.name() + "}");
}

void gui::textBGColorChange() {
	QColor selected = QColorDialog::getColor();
	_textEditField->setTextBackgroundColor(selected);
}

void gui::refreshText() {
	textInDefaultCoding = (QString)_textEditField->toPlainText();
}

gui::~gui() {
	delete _fileMenu;
	delete _codeHighlighter;
	delete _textEditField;
	delete _fontEdit;
	delete _fontColorEdit;
	delete _bgColorButton;
	delete _selectionColor;
	delete _selectionTextColor;
	delete _textBGColor;
	delete _keyCtrlS;
	delete _codecEdit;
	delete _hlCheckBox;
}

