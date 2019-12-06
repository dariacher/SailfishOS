#ifndef SOLVE_H
#define SOLVE_H
#include <QObject>
#include <QMetaObject>
#include <QDebug>

class Solve : public QObject
{
    Q_OBJECT
   Q_PROPERTY(float* matr READ getMatr WRITE setMatr NOTIFY matrChange)
public:

   Q_INVOKABLE Solve(){
        matr = new float[9];
        res = new float[3];
    }

    float* getMatr(){
        return matr;
    }

    void setMatr(float* m){
        for (int i = 0; i < size*size; i++){
            matr[i] = m[i];
        }
    }

    Q_INVOKABLE void setElement(float el, int idx){
        matr[idx] = el;
    }

    float getElement(int idx){
        return matr[idx];
    }

    Q_INVOKABLE void Matr(){
        float w0[size], w[size], summ = 0, e, d, d0;
        int i, j;
        for (i = 0; i<size; i++)
            w0[i] = 0;
        w0[0] = 1;
        do
        {
            for (i = 0; i<size; i++)
                summ = summ + w0[i] * w0[i];
             d0 = sqrt(summ);
            for (i = 0; i<size; i++)
                res[i] = w0[i] / d0;
                for (i = 0; i<size; i++)
                {
                    w[i] = 0;
                    for (j = 0; j<size; j++)
                    w[i] = w[i] + matr[i*3 + j] * res[j];
                }
                summ = 0;
                for (i = 0; i<size; i++)
                    summ = summ + w[i] * w[i];
                d = sqrt(summ);
                e = fabs(d - d0);
                for (i = 0; i<size; i++)
                    w0[i] = w[i];
                    summ = 0;
        }
        while (e>0.001);
        emit matrChange();
    }
private:
    float *a;
    float *res;
    int size = 3;
signals:
    void matrChange();
private slots:
    void print(){
        for (int i = 0; i < size; i++) {
            qDebug<<res[i];
        }
    }
};

#endif // SOLVE_H
