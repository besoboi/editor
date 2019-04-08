#pragma once

#include <QtWidgets/QMainWindow>
#include <QMenu>
#include <QString>
#include <QTextEdit>
#include <QFont>
#include <QPushButton>
#include "ui_editor.h"

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
	void compileFile();

private:
	Ui::editorClass ui;
	QMenu *fileMenu;
	QString openedFileName;
	QString compiledFileName;
	QTextEdit *textEditField;
	QPushButton *fontEdit;
	QPushButton *fontColorEdit;
	QMenu *compileMenu;
};
