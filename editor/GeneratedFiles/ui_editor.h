/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editorClass
{
public:
    QAction *open;
    QAction *create;
    QAction *save;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFontComboBox *fontBox;
    QComboBox *fontSizeBox;
    QComboBox *fontColorBox;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *compile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *editorClass)
    {
        if (editorClass->objectName().isEmpty())
            editorClass->setObjectName(QStringLiteral("editorClass"));
        editorClass->setWindowModality(Qt::NonModal);
        editorClass->resize(984, 823);
        QFont font;
        font.setPointSize(8);
        editorClass->setFont(font);
        open = new QAction(editorClass);
        open->setObjectName(QStringLiteral("open"));
        create = new QAction(editorClass);
        create->setObjectName(QStringLiteral("create"));
        save = new QAction(editorClass);
        save->setObjectName(QStringLiteral("save"));
        centralWidget = new QWidget(editorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        fontBox = new QFontComboBox(centralWidget);
        fontBox->setObjectName(QStringLiteral("fontBox"));

        gridLayout->addWidget(fontBox, 0, 0, 1, 1);

        fontSizeBox = new QComboBox(centralWidget);
        fontSizeBox->setObjectName(QStringLiteral("fontSizeBox"));

        gridLayout->addWidget(fontSizeBox, 0, 1, 1, 1);

        fontColorBox = new QComboBox(centralWidget);
        fontColorBox->setObjectName(QStringLiteral("fontColorBox"));

        gridLayout->addWidget(fontColorBox, 0, 2, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QFont font1;
        font1.setPointSize(12);
        textEdit->setFont(font1);

        gridLayout->addWidget(textEdit, 1, 0, 1, 3);

        editorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(editorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 984, 23));
        fileMenu = new QMenu(menuBar);
        fileMenu->setObjectName(QStringLiteral("fileMenu"));
        compile = new QMenu(menuBar);
        compile->setObjectName(QStringLiteral("compile"));
        editorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(editorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        editorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(editorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        editorClass->setStatusBar(statusBar);

        menuBar->addAction(fileMenu->menuAction());
        menuBar->addAction(compile->menuAction());
        fileMenu->addAction(open);
        fileMenu->addAction(create);
        fileMenu->addAction(save);

        retranslateUi(editorClass);

        QMetaObject::connectSlotsByName(editorClass);
    } // setupUi

    void retranslateUi(QMainWindow *editorClass)
    {
        editorClass->setWindowTitle(QApplication::translate("editorClass", "editor", Q_NULLPTR));
        open->setText(QApplication::translate("editorClass", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", Q_NULLPTR));
        create->setText(QApplication::translate("editorClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", Q_NULLPTR));
        save->setText(QApplication::translate("editorClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        fileMenu->setTitle(QApplication::translate("editorClass", "\320\244\320\260\320\271\320\273", Q_NULLPTR));
        compile->setTitle(QApplication::translate("editorClass", "\320\232\320\276\320\274\320\277\320\270\320\273\321\217\321\206\320\270\321\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class editorClass: public Ui_editorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
