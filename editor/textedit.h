#pragma once
#include <QTextEdit>
#include <QPushButton>
#include <QWidget>
#include "highlighter.h"
#include "ui_editor.h"

class customTextEdit : public QTextEdit {
	void keyPressEvent(QKeyEvent * event);
};