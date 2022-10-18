#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "finddialog.h"
#include "fontdialog.h"
#include "settings.h"
#include <stdlib.h>
#include <stdio.h>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    find_dialog = new FindDialog(this);
    connect(find_dialog, &FindDialog::findNext, this, &MainWindow::findNext);
    connect(find_dialog, &FindDialog::findPrev, this, &MainWindow::findPrev);
    connect(find_dialog, &FindDialog::replace, this, &MainWindow::replace);
    connect(find_dialog, &FindDialog::replaceAll, this, &MainWindow::replaceAll);
    QFont font;
    Settings::readSettings(&m_current_file_path, &font, &m_load_recent,
                                   &m_word_wrap, &m_status_bar);

    // Setup Text Edit
    ui->textEdit->setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Confirmation",
                                                                    tr("Do you want to save the changes?\n"),
                                                                    QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                    QMessageBox::Yes);
    if (resBtn == QMessageBox::Yes) {
        on_actionSave_triggered();
        if(saved)
            event->accept();
        else
            event->ignore();
    }
    else if (resBtn == QMessageBox::Cancel) {
        event->ignore();
    }
    else {
        event->accept();
    }
}

void MainWindow::fileInfo(QFile *file){
    currentFile = file->fileName();
    QFileInfo file_info(*file);
    m_file_extention = file_info.suffix();
    m_current_dir = file_info.absolutePath();
    m_current_file_path = file_info.filePath();

    //setWindowTitle("Notebook - " + file_info.fileName());
}

void MainWindow::on_actionNew_triggered()
{
    if (!ui->textEdit->toPlainText().isEmpty()) {
      auto save =
          currentFile == "Untitled"
              ? QMessageBox::question(this, tr("Unsaved Changes"),
                                      "Do you want to save these changes?")
              : QMessageBox::question(
                    this, tr("Unsaved Changes"),
                    "Do you want to save changes to " + currentFile + "?");
      if (save == QMessageBox::Yes) on_actionSave_triggered();
    }
    currentFile.clear();
    ui->textEdit->setText(QString());
}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot Open file : " + file.errorString());
        return;
    }
    fileInfo(&file);
    currentFile = filename;
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);    
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }
    fileInfo(&file);
    currentFile = filename;
    setWindowTitle(filename);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
    saved = true;
}


void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Warning", "Cannot Access printer");
        return;
    }
    ui->textEdit->print(&printer);
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionCopy_triggered()
{
    QTextCursor cursor(ui->textEdit->textCursor());
    QString selected_text = cursor.selectedText();

    //qDebug() << selected_text;

    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(selected_text);

    //ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    const QClipboard *clipboard = QApplication::clipboard();
    const QMimeData *mimeData = clipboard->mimeData();
    QString str="";
    if(mimeData->hasText()){
        str=mimeData->text();

    }
    //qDebug() << str;
    QTextCursor cursor(ui->textEdit->textCursor());
    //cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor, 1);
    cursor.insertText(str);
    //ui->textEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
    QTextCursor cursor(ui->textEdit->textCursor());
    QString selected_text = cursor.selectedText();

    //qDebug() << selected_text;

    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(selected_text);

    cursor.removeSelectedText();

    //ui->textEdit->cut();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}



void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionSave_triggered()
{
    QFile file(currentFile);
    if (file.exists())  // If file exists, overwrite it
    {
      if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
      }
    } else  // If file doesn't exist, prompt user to save as a new file
    {
        QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), "*.txt", tr("Text Documents(*.txt)"));
        QFile file(filename);
        if(!file.open(QIODevice::WriteOnly | QFile::Text)){
            QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
            return;
        }
        fileInfo(&file);
        currentFile = filename;
        setWindowTitle(filename);
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out << text;
        file.close();
        saved = true;
    }
}

void MainWindow::findNext(QString text) {
  bool success;
  if (find_dialog->isMatchCase())
    success = ui->textEdit->find(text, QTextDocument::FindCaseSensitively);
  else
    success = ui->textEdit->find(text);

  // If unsuccessful and in wrap-around mode, try again from the beginning of
  // the document
  if (!success && find_dialog->isWrapAround()) {
    QTextCursor cursor = QTextCursor(ui->textEdit->document());
    cursor.movePosition(QTextCursor::Start);
    ui->textEdit->setTextCursor(cursor);

    if (find_dialog->isMatchCase())
      success = ui->textEdit->find(text, QTextDocument::FindCaseSensitively);
    else
      success = ui->textEdit->find(text);
  }

  if (!success) {
    QMessageBox::warning(this, "Notepad", "Cannot find \"" + text + "\"");
  } else {
    activateWindow();  // this is done so that highlighted text is in focus.
                       // However, Enter key can no longer be used to Find Next
  }
}

void MainWindow::findPrev(QString text) {
  bool success;
  if (find_dialog->isMatchCase())
    success = ui->textEdit->find(
        text, QTextDocument::FindCaseSensitively | QTextDocument::FindBackward);
  else
    success = ui->textEdit->find(text, QTextDocument::FindBackward);

  // If unsuccessful and in wrap-around mode, try again from the end of the
  // document
  if (!success && find_dialog->isWrapAround()) {
    QTextCursor cursor = QTextCursor(ui->textEdit->document());
    cursor.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(cursor);

    if (find_dialog->isMatchCase())
      success = ui->textEdit->find(text, QTextDocument::FindCaseSensitively |
                                             QTextDocument::FindBackward);
    else
      success = ui->textEdit->find(text, QTextDocument::FindBackward);
  }

  if (!success) {
    QMessageBox::warning(this, "Notebook", "Cannot find \"" + text + "\"");
  } else
    activateWindow();  // this is done so that highlighted text is in focus.
                       // However, Enter key can no longer be used to Find Next
}

/*!
    \fn Notebook::replace(QString original, QString target)

\brief Replaces the next instance of <original> with <target>
        */
void MainWindow::replace(QString original, QString target) {
  // If a copy of <original> isn't highlighted, find the next instance of
  // <original>
  if (ui->textEdit->textCursor().selectedText() != original) {
    findNext(original);
  } else  // else replace it with <target> and then find next <original>
  {
    ui->textEdit->textCursor().removeSelectedText();
    ui->textEdit->textCursor().insertText(target);
    findNext(original);
  }
}

/*!
    \fn Notebook::replaceAll(QString original, QString target)

\brief Replaces all instances of <original> with <target>
        */
void MainWindow::replaceAll(QString original, QString target) {
  // Set wrap-around to true so we comb through the whole doc
  bool is_wrap_around = find_dialog->isWrapAround();
  find_dialog->setWrapAround(true);

  while (ui->textEdit->toPlainText().contains(original)) {
    replace(original, target);
  }

  find_dialog->setWrapAround(
      is_wrap_around);  // return wrap-around setting to original value
}

void MainWindow::on_actionFind_triggered()
{
    find_dialog->openFindDialog();
}

void MainWindow::on_actionTime_Date_triggered()
{
    QDateTime date = QDateTime::currentDateTime();
    QString time = date.toString("hh:mm dd.MM.yyyy");

    ui->textEdit->setText(time);
}


void MainWindow::on_actionFonts_triggered()
{
    FontDialog font_dialog(ui->textEdit->font(), this);
    connect(&font_dialog, &FontDialog::fontChanged, this, &MainWindow::fontChanged);
    font_dialog.exec();
}

void MainWindow::fontChanged(QFont font) {
    ui->textEdit->setFont(font);
}


void MainWindow::on_actionCompile_triggered()
{
    on_actionSave_triggered();
    p.setWorkingDirectory(m_current_dir);
    //qDebug()<< m_current_dir;
    p.execute("gcc", QStringList() << currentFile << "-o" << m_current_dir+"/a");
    //p.execute("powershell", QStringList() << m_current_dir+"/./a.exe");
}

void MainWindow::on_actionOpen_Terminal_triggered()
{
    QString command = "C:\\Windows\\SysWOW64\\WindowsPowerShell\\v1.0\\powershell.exe";
    QDesktopServices::openUrl(QUrl("file:///"+command, QUrl::TolerantMode));
}

