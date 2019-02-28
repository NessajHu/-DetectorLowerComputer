#include "lineedit.h"

LineEdit::LineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    
}

void LineEdit::focusInEvent(QFocusEvent *e)
{
    emit focusInSignal();
    QLineEdit::focusInEvent(e);
}

void LineEdit::focusOutEvent(QFocusEvent *e)
{
    emit focusOutSignal();
    QLineEdit::focusOutEvent(e);
}
