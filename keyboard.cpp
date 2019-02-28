#include "keyboard.h"

Keyboard::Keyboard(QWidget *parent) : 
    QWidget(parent),
    buttonList(10),
    closeButton(new QPushButton(this)),
    deleteButton(new QPushButton(this)),
    layout(new QGridLayout(this))
{
    for(int i = 0; i < 10; i++)
    {
        QPushButton *tempButton = new QPushButton(this);
        layout->addWidget(tempButton, i / 3, i % 3, 1, 1);
        tempButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        tempButton->setText(QString::number(i));
        buttonList.push_back(tempButton);
    }
    closeButton->setText("Close");
    closeButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    deleteButton->setText("Delete");
    deleteButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(closeButton, 3, 1, 1, 1);
    layout->addWidget(deleteButton, 3, 2, 1, 1);
    layout->setSpacing(10);
    layout->setMargin(10);
}

Keyboard::~Keyboard()
{
    for(auto i : buttonList)
        delete i;
}
