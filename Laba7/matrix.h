#ifndef MATRIX_H
#define MATRIX_H

#include <QObject>
//using namespace std;

class Matrix : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float** mas READ getMas NOTIFY matrixChanged)
    Q_PROPERTY(float* res READ getRes NOTIFY resChanged)
    Q_PROPERTY(int size READ getSize WRITE setSize NOTIFY sizeChanged)

private:
    int size;
    float **mas;
    float *res;

public:
    Q_INVOKABLE Matrix();
    Q_INVOKABLE Matrix(int size);
    Matrix(const Matrix& m);
    Q_INVOKABLE void setSize(int s);
    Q_INVOKABLE int getSize();
    Q_INVOKABLE float getElement(int i, int j);
    Q_INVOKABLE float getResElement(int i);
    Q_INVOKABLE void setElement(QString element, int i, int j);
    float** getMas();
    float* getRes();
    Q_INVOKABLE void solve();
private slots:
    void print();
signals:
    void matrixChanged();
    void resChanged();
    void sizeChanged();
};

#endif // MATRIX_H
