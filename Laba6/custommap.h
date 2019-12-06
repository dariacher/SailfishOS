#ifndef CUSTOMMAP_H
#define CUSTOMMAP_H
#include <QObject>
#include <QMetaObject>
#include <QDebug>
#include <QString>
#include <QList>


class CustomMap : public QObject
{
     Q_OBJECT
    Q_PROPERTY(QString mystr READ getText NOTIFY listChange)

public:
    Q_INVOKABLE CustomMap():QObject(){}


    Q_INVOKABLE void add(QString ms){
        mylist.append(ms.toLower());
        emit listChange();
    }

    Q_INVOKABLE void deleteLast(){
      mylist.removeLast();
      emit listChange();
    }

//    QString getString(){
//        return mylist.takeLast();
//    }

    QString getText(){
        QString text = mylist.join(", ");
        return text.replace(0,1,text[0].toUpper());
    }
private:
    QList<QString> mylist;
signals:
    void listChange();
private slots:
    void print(){
        qDebug()<<mylist;
    }
};

#endif // CUSTOMMAP_H
