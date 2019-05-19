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

#include "ui_editor.h"
#include "Source.h"
#include "file.h"

class editor : public QMainWindow
{
	Q_OBJECT

public:
	editor(QWidget *parent = Q_NULLPTR);


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
private:
	Ui::editorClass ui;
	QMenu *_fileMenu;
	QString _openedFileName;
	Highlighter *_codeHighlighter;
	QTextEdit *_textEditField;
	QPushButton *_fontEdit;
	QPushButton *_fontColorEdit;
	QPushButton *_bgColorButton;
	QShortcut *_keyCtrlS;
	QComboBox *_codecEdit;
	QTextCodec *_codec;
	fileInstance _file;
};
