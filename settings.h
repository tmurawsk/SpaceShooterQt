#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QSplitter>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

signals:
    void returnValues(int, int);

private slots:
    void on_okButton_clicked();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
