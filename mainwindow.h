#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QKeyEvent>
#include <QTime>
#include <QDebug>
#include <QProcess>
#include <stdio.h>
#include <QDesktopServices>
#include <QUrl>
#include <QCloseEvent>
#include <QClipboard>
#include <QTextCursor>
#include <QMimeData>

class FindDialog;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void closeEvent(QCloseEvent*);

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionSave_triggered();

    void on_actionFind_triggered();

    void fileInfo(QFile*);

    // Find/Replace Slots
    void findNext(QString text);
    void findPrev(QString text);
    void replace(QString original, QString target);
    void replaceAll(QString original, QString target);

    void on_actionTime_Date_triggered();

    void on_actionFonts_triggered();
    void fontChanged(QFont font);

    void on_actionCompile_triggered();

    void on_actionOpen_Terminal_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile = "Untitled";
    QString     m_current_file_path="";
    QString     m_current_dir="";
    QString     m_file_extention="";
    FindDialog  *find_dialog;
    QProcess p;
    QCloseEvent *event;
    bool saved = false;
//    QList<QChar> strm;
//    QVector<QList<QChar>> liststack;
//    QVector<QList<QChar>> redoliststack;
//    QVector<int> cursorStack;
//    QVector<int> redocursorStack;


    bool m_load_recent = false, m_word_wrap = false, m_status_bar = false;
};
#endif // MAINWINDOW_H
