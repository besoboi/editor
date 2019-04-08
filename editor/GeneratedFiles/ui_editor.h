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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QAction *compChooser;
    QAction *compile;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *colorButton;
    QTextEdit *textEdit;
    QPushButton *fontButton;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *compileMenu;
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
        compChooser = new QAction(editorClass);
        compChooser->setObjectName(QStringLiteral("compChooser"));
        compile = new QAction(editorClass);
        compile->setObjectName(QStringLiteral("compile"));
        centralWidget = new QWidget(editorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        colorButton = new QPushButton(centralWidget);
        colorButton->setObjectName(QStringLiteral("colorButton"));

        gridLayout->addWidget(colorButton, 0, 1, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QFont font1;
        font1.setPointSize(12);
        textEdit->setFont(font1);

        gridLayout->addWidget(textEdit, 1, 0, 1, 2);

        fontButton = new QPushButton(centralWidget);
        fontButton->setObjectName(QStringLiteral("fontButton"));

        gridLayout->addWidget(fontButton, 0, 0, 1, 1);

        editorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(editorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 984, 26));
        fileMenu = new QMenu(menuBar);
        fileMenu->setObjectName(QStringLiteral("fileMenu"));
        compileMenu = new QMenu(menuBar);
        compileMenu->setObjectName(QStringLiteral("compileMenu"));
        editorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(editorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        editorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(editorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        editorClass->setStatusBar(statusBar);

        menuBar->addAction(fileMenu->menuAction());
        menuBar->addAction(compileMenu->menuAction());
        fileMenu->addAction(open);
        fileMenu->addAction(create);
        fileMenu->addAction(save);
        compileMenu->addAction(compChooser);
        compileMenu->addAction(compile);

        retranslateUi(editorClass);

        QMetaObject::connectSlotsByName(editorClass);
    } // setupUi

    void retranslateUi(QMainWindow *editorClass)
    {
        editorClass->setWindowTitle(QApplication::translate("editorClass", "editor", Q_NULLPTR));
        open->setText(QApplication::translate("editorClass", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", Q_NULLPTR));
        create->setText(QApplication::translate("editorClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", Q_NULLPTR));
        save->setText(QApplication::translate("editorClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        compChooser->setText(QApplication::translate("editorClass", "\320\222\321\213\320\261\320\276\321\200 \320\272\320\276\320\274\320\277\320\270\320\273\321\217\321\202\320\276\321\200\320\260", Q_NULLPTR));
        compile->setText(QApplication::translate("editorClass", "\320\241\320\272\320\276\320\274\320\277\320\270\320\273\320\270\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        colorButton->setText(QApplication::translate("editorClass", "\320\241\320\274\320\265\320\275\320\260 \321\206\320\262\320\265\321\202\320\260 \321\210\321\200\320\270\321\204\321\202\320\260", Q_NULLPTR));
        fontButton->setText(QApplication::translate("editorClass", "\320\241\320\274\320\265\320\275\320\260 \321\210\321\200\320\270\321\204\321\202\320\260", Q_NULLPTR));
        fileMenu->setTitle(QApplication::translate("editorClass", "\320\244\320\260\320\271\320\273", Q_NULLPTR));
        compileMenu->setTitle(QApplication::translate("editorClass", "\320\232\320\276\320\274\320\277\320\270\320\273\321\217\321\206\320\270\321\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class editorClass: public Ui_editorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
