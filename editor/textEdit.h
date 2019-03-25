#pragma once

#include <QTextEdit>
#include <QComboBox>
#include <QFontComboBox>

#include "ui_editor.h"

class textEdit : public QWidget
{
	Q_OBJECT

public slots :
	void changeFont();
	void changeFontColor();
	void changeFontSize();

public:
	QTextEdit *textEditField;
	QComboBox *fontColorEdit;
	QComboBox *fontSizeEdit;
	QFontComboBox *fontEdit;

};
