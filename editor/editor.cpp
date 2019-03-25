#include "editor.h"
#include "textEdit.h"

editor::editor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	textEdit current;
	current.textEditField = ui.textEdit;
	current.fontColorEdit = ui.fontColor;
	current.fontSizeEdit = ui.fontSize;
	connect(current.textEditField, SIGNAL(currentFontChanged()), this, SLOT(current.changeFont()));
	connect(current.fontColorEdit, SIGNAL(activated()), this, SLOT(current.changeFontColor()));
	connect(current.fontSizeEdit, SIGNAL(activated()), this, SLOT(current.changeFontSize()));

}
