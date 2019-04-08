#pragma once

#include <QtWidgets/QMainWindow>
#include <QMenu>
#include <QString>
#include <QTextEdit>
#include <QComboBox>
#include <QFontComboBox>
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

private:
	Ui::editorClass ui;
	QMenu *fileMenu;
	QString openedFileName;
	QTextEdit *textEditField;
	QPushButton *fontEdit;
	QPushButton *fontColorEdit;
};
