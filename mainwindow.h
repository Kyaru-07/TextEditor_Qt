#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class aboutDialog;
class FindDialog;
class ReplaceDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_actionAbout_triggered();
    void on_actionFind_triggered();
    void onFindNextRequested(const QString &text,bool caseSensitive,bool backward);

    void on_actionReplace_triggered();
    void onReplaceFindNext(const QString &text, bool caseSensitive);
    void onReplaceRequested(const QString &text, const QString &with, bool caseSensitive);
    void onReplaceAllRequested(const QString &text, const QString &with, bool caseSensitive);

private:
    Ui::MainWindow *ui;
    FindDialog *m_findDlg=nullptr;
    ReplaceDialog *m_replaceDlg=nullptr;
};
#endif // MAINWINDOW_H
