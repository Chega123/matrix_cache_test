#include <iostream>
#include <chrono>
#include <cstdlib> 
#include <ctime>   

#define Max 1000
using namespace std;
using namespace std::chrono;

void printMatrix(double** matrix) {
    for (int i = 0; i < Max; ++i) {
        for (int j = 0; j < Max; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl; 
    }
}

int main() {

    double** A = new double*[Max];
    for(int i = 0; i < Max; i++) {
        A[i] = new double[Max];
    }
    
    double* X = new double[Max];
    double* Y = new double[Max];

    double** matrizA = new double*[Max];
    double** matrizB = new double*[Max];
    double** AnswerMatriz = new double*[Max];
    
    for(int i = 0; i < Max; i++) {
        matrizA[i] = new double[Max];
        matrizB[i] = new double[Max];
        AnswerMatriz[i] = new double[Max];
    }

    double time1, time2;
    duration<double> interval;
    srand(time(0));
    high_resolution_clock::time_point start, end;

    for (int i = 0; i < Max; i++) {
        X[i] = i;
        Y[i] = 0.0; 
        for (int j = 0; j < Max; j++) {
            A[i][j] = i + j;
        }
    }

    start = high_resolution_clock::now();
    for (int i = 0; i < Max; i++) {
        for (int j = 0; j < Max; j++) {
            Y[i] += A[i][j] * X[j];
        }
    }
    end = high_resolution_clock::now();
    interval = duration_cast<duration<double>>(end - start);
    time1 = interval.count();


    for (int i = 0; i < Max; i++) {
        Y[i] = 0.0;
    }

    start = high_resolution_clock::now();
    for (int j = 0; j < Max; j++) {
        for (int i = 0; i < Max; i++) {
            Y[i] += A[i][j] * X[j];
        }
    }
    end = high_resolution_clock::now();
    interval = duration_cast<duration<double>>(end - start);
    time2 = interval.count();

    cout << "Tiempo del primer bucle: " << time1 << " segundos" << endl;
    cout << "Tiempo del segundo bucle: " << time2 << " segundos" << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////

    double time3, time4;

    for (int i = 0; i < Max; i++) {
        for (int j = 0; j < Max; j++) {
            matrizA[i][j] = rand() % Max;
            matrizB[i][j] = rand() % Max;
        }
    }
    start = high_resolution_clock::now();
    for (int fila = 0; fila < Max; fila++) {
        for (int col = 0; col < Max; col++) {
            for (int index = 0; index < Max; index++) {
                AnswerMatriz[fila][col] += matrizA[fila][index] * matrizB[index][col];
            }
        }
    }

    end = high_resolution_clock::now();
    interval = duration_cast<duration<double>>(end - start);
    time3 = interval.count();  
    //printMatrix(AnswerMatriz);


 cout << "Tiempo del primer bucle multiplicacion matriz: " << time3 << " segundos" << endl;


    for (int i = 0; i < Max; i++) {
        for (int j = 0; j < Max; j++) {
            AnswerMatriz[i][j] = 0;
        }
    }
    start = high_resolution_clock::now();
    for (int col = 0; col < Max; col++) {
        for (int fila = 0; fila < Max; fila++) {
            for (int index = 0; index < Max; index++) {
                AnswerMatriz[fila][col] += matrizA[fila][index] * matrizB[index][col];
            }
        }
    }
    end = high_resolution_clock::now();
    interval = duration_cast<duration<double>>(end - start);
    time4 = interval.count();

     cout<<endl;


   
  cout << "Tiempo del segundo bucle multiplicacion matriz: " << time4 << " segundos" << endl;

    /////////////////////////////////////////////////////////////////////////////////////
    
   for (int i = 0; i < Max; i++) {
        for (int j = 0; j < Max; j++) {
            AnswerMatriz[i][j] = 0;
        }
    }
    int N=5;//tam del bloque
    int b=Max/N;
    start = high_resolution_clock::now();
    for (int ii =0; ii<N;ii++){
        for(int jj=0; jj<N;jj++){
            for (int kk=0;kk<N;kk++){
                for(int i=(ii)*b;i<(ii+1)*b;i++){
                    for(int j=(jj)*b;j<(jj+1)*b;j++){
                        for(int k=(kk)*b;k<(kk+1)*b;k++){
                          AnswerMatriz[i][j]+=matrizA[i][k]*matrizB[k][j];
                        }
                    }
                }
            }
        }
    } 
    end = high_resolution_clock::now();
    interval = duration_cast<duration<double>>(end - start);
    double time5 = interval.count();
   // printMatrix(AnswerMatriz);

    cout<<"la multiplicacion por bloques demora: "<<time5<<endl;
    

    return 0;
}

