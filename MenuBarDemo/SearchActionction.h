#ifndef SEARCHACTION_H
#define SEARCHACTION_H

#include <QWidget>
#include <QWidgetAction>

class SearchAction : public QWidgetAction
{
    Q_OBJECT
public:
    explicit SearchAction(QWidgetAction *parent = nullptr);

signals:

};

#endif // SEARCHACTION_H
