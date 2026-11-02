#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>

namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QWidget *parent = nullptr);
    ~ReplaceDialog();

    void setFindText(const QString &text);
    QString findText() const;
    QString replaceText() const;
    void showResult(const QString &text,bool isError=false);

signals:
    void findNextRequested(const QString &text,bool caseSensitive);
    void replaceRequested(const QString &text,const QString &with,bool caseSensitive);
    void replaceAllRequested(const QString &text,const QString &with,bool caseSensitive);

private slots:
    void on_btnFindNext_clicked();
    void on_btnReplace_clicked();
    void on_btnReplaceAll_clicked();
    void on_btnClose_clicked();

private:
    bool checkInput();

    Ui::ReplaceDialog *ui;
};

#endif // REPLACEDIALOG_H
