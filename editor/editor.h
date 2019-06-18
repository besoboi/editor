#pragma once

#include <QtWidgets/QMainWindow>
#include <QMenu>
#include <QString>
#include <QTextEdit>
#include <QComboBox>
#include <QFont>
#include <QPushButton>
#include <QShortcut>
#include <QTextCodec>
#include <QCheckBox>

#include "ui_editor.h"
#include "Source.h"
#include "file.h"


class Gui : public QMainWindow
{
	Q_OBJECT
public:
	Gui(QWidget *parent = Q_NULLPTR);
	~Gui();
	bool highliterIsOn = 0;
	QString textInDefaultCoding;

private slots:
	void openFile();
	void changeFont();
	void changeFontColor();
	void makeFile();
	void saveFile();
	void fastSave();
	void codecChange();
	void bgColorChange();
	void compile();
	void turnOnHL();
	void selectionColorChange();
	void selectionTextColorChange();
	void textBGColorChange();
	void refreshText();
private:
	Ui::editorClass ui;
	QMenu *_fileMenu;
	QString _openedFileName;
	Highlighter *_codeHighlighter = NULL;
	QTextEdit *_textEditField;
	QPushButton *_fontEdit;
	QPushButton *_fontColorEdit;
	QPushButton *_bgColorButton;
	QPushButton *_selectionColor;
	QPushButton *_selectionTextColor;
	QPushButton *_textBGColor;
	QShortcut *_keyCtrlS;
	QComboBox *_codecEdit;
	QTextCodec *_codec;
	fileInstance _file;
	QCheckBox *_hlCheckBox;
};
