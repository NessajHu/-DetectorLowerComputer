#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class Keyboard : public QWidget
{
    Q_OBJECT
public:
    explicit Keyboard(QWidget *parent = nullptr);
    ~Keyboard();
private:
    QVector<QPushButton*> buttonList;
    QPushButton *closeButton;
    QPushButton *deleteButton;
    QGridLayout *layout;
signals:
    
public slots:
};

#endif // KEYBOARD_H
