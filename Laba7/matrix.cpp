#include "matrix.h"
#include <QDebug>
using namespace std;


Matrix::Matrix() : QObject()
{
    size = 3;
    mas = new float*[size];
    res = new float[size];
    for(int i=0; i<size; i++)
    {
        mas[i]=new float[size];
    }
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            mas[i][j]=1;
            res[j]=1;
        }
    }
}

Matrix::Matrix(int size_) : QObject()
{
    size=size_;
    mas = new float*[size];
    res = new float[size];
    for(int i=0; i<size; i++)
    {
        mas[i]=new float[size];
    }
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            mas[i][j]=1;
            res[j]=1;
        }
    }
}

int Matrix::getSize()
{
    return this->size;
}


void Matrix::solve()
{
//    float w0[3],w[3];
//    float summ=0,e,d,d0;
//    int i,j;
//    for (i=0;i<size;i++)
//        w0[i]=0;
//    w0[0]=1;
//    do
//    {
//        for (i=0;i<size;i++)
//            summ=summ+w0[i]*w0[i];
//        d0=sqrt(summ);
//        for (i=0;i<size;i++)
//            res[i]=w0[i]/d0;
//        for (i=0;i<size;i++)
//        {
//            w[i]=0;
//            for (j=0;j<size;j++)
//                w[i]=w[i]+mas[i][j]*res[j];
//        }
//        summ=0;
//        for (i=0;i<size;i++)
//        summ=summ+w[i]*w[i];
//        d=sqrt(summ);
//        e=fabs(d-d0);
//        for (i=0;i<size;i++)
//            w0[i]=w[i];
//        summ=0;
//    }
//    while(e>0.001);
    int i, k, j;
    float tmp;
    for (i = 0; i < this->size; i++){
        int iMax = i;
        for (int j = 1; j < this->size; j++){
            if (abs(this->mas[j][i]) > abs(this->mas[iMax][i])){
                iMax = j;
            }
        }
            if (abs(this->mas[iMax][i]) < 0.001)
                continue;
            for (k = 0; k < this->size; k++){
                tmp = this->mas[i][k];
                this->mas[i][k] = this->mas[iMax][k];
                this->mas[iMax][k] = tmp;
            }

            for (j = i + 1; j < this->size; j++){
                float q = -this->mas[j][i] / this->mas[i][i];
                for (k = this->size - 1; k >=i; k--)
                    this->mas[j][k] += q * this->mas[i][k];
            }

    }
}

Matrix::Matrix(const Matrix& m)
{
    size=m.size;
    mas = new float*[size];
    for(int i=0; i<size; i++)
    {
        mas[i]=new float[size];
    }
    for(int i=0; i<m.size; i++)
    {
        for(int j=0; j<m.size; j++)
        {
            mas[i][j]=m.mas[i][j];
        }
    }
}




float Matrix::getElement(int i, int j)
{
    return this->mas[i][j];
}

float Matrix::getResElement(int i)
{
    return this->res[i];
}

void Matrix::setElement(QString a, int i, int j)
{
    float a_ = a.toFloat();
    this->mas[i][j] = a_;
    emit matrixChanged();
}

void Matrix::print()
{
    int l = this->size;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            qDebug() << this->mas[i][j] << " ";
        }
        qDebug() << "\n";
    }
}

void Matrix::setSize(int s) {
    this->size = s;
    emit sizeChanged();
}

float** Matrix::getMas() {
    return this->mas;
}

float* Matrix::getRes() {
    return this->res;
}


