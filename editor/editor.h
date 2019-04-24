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
	QMenu *fileMenu;
	QString openedFileName;
	Highlighter *codeHighlighter;
	QTextEdit *textEditField;
	QPushButton *fontEdit;
	QPushButton *fontColorEdit;
	QPushButton *bgColorButton;
	QShortcut *keyCtrlS;
	QComboBox *codecEdit;
	QTextCodec *codec;
};
