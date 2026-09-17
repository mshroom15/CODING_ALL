#include<iostream>
#include<vector>
#include<random>
#include <chrono>

using namespace std;

int count_mult = 0;
int count_add =0;
int count_sub = 0;
using matrix=vector<vector<long long>>;
matrix generate_matrix(long long n, int min_val=0, int max_value=100){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    matrix a (n, vector<long long>(n,0));
    uniform_int_distribution<long long>dist(min_val,max_value);
    for(auto& p:a){
        for(auto& r:p){
            r=dist(rng);
        }
    }
    return a;
}

matrix matrix_mult(matrix& a, matrix& b, matrix& c){
    long long n = a.size();
    for(int i=0;i<n;i++){

        for(int j=0; j<n;j++){

            for(int k = 0;k<n;k++){
            c[i][j]+=a[i][k]*b[k][j];
            count_mult++;
            }
            
        }
    }
    return c;
}
matrix add(const matrix& a ,const matrix& b){
    int n = a.size();
    matrix res(n, vector<long long>(n));
    for(int i=0;i<n;i++){

        for(int j=0; j<n;j++){
            res[i][j]=a[i][j]+b[i][j];
            count_add++;
        }
    }
    
    return res;
}
matrix sub(const matrix& a , const matrix& b){
    int n = a.size();
    matrix res(n, vector<long long>(n));
    for(int i=0;i<n;i++){

        for(int j=0; j<n;j++){
            res[i][j]=a[i][j]-b[i][j];
            count_sub++;
        }
    }
    
    return res;
}
matrix get(const matrix& a , int row , int col , int n){
    matrix res(n, vector<long long>(n));
    for(int i=0;i<n;i++){

        for(int j=0; j<n;j++){
            res[i][j]=a[row+i][col+j];
        }
    }
    return res;
    
}
void put(matrix& c , const matrix& a ,  int row , int col , int n){
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            c[row+i][col+j]=a[i][j];
        }
    }
}
matrix matrix_div_con(matrix& a, matrix& b){
    if (a.size()==1){
        count_mult++;
        return {{a[0][0]*b[0][0]}};
    }
    int n = a.size();
    matrix c(n, vector<long long>(n));
    
    int h = a.size()/2;
    matrix A11 = get(a,0,0,h);
    matrix A12 = get(a,0,h,h);
    matrix A21 = get(a,h,0,h);
    matrix A22 = get(a,h,h,h);

    matrix B11 = get(b,0,0,h);
    matrix B12 = get(b,0,h,h);
    matrix B21 = get(b,h,0,h);
    matrix B22 = get(b,h,h,h);

    matrix C11 = add(matrix_div_con(A11,B11),matrix_div_con(A12,B21));
    matrix C12 = add(matrix_div_con(A11,B12),matrix_div_con(A12,B22));
    matrix C21 = add(matrix_div_con(A21,B11),matrix_div_con(A22,B21));
    matrix C22 = add(matrix_div_con(A21,B12),matrix_div_con(A22,B22));

    put(c, C11, 0,0,h);
    put(c, C12, 0,h,h);
    put(c, C21, h,0,h);
    put(c, C22, h,h,h);
    return c;
}

matrix matrix_stress(const matrix& a, const matrix& b){
    if (a.size()==1){
        count_mult++;
        return {{a[0][0]*b[0][0]}};
        
    }
    int n = a.size();
    matrix c(n, vector<long long>(n));
    
    int h = a.size()/2;
    matrix A11 = get(a,0,0,h);
    matrix A12 = get(a,0,h,h);
    matrix A21 = get(a,h,0,h);
    matrix A22 = get(a,h,h,h);

    matrix B11 = get(b,0,0,h);
    matrix B12 = get(b,0,h,h);
    matrix B21 = get(b,h,0,h);
    matrix B22 = get(b,h,h,h);

    matrix M1 =matrix_stress(add(A11,A22), add(B11,B22));
    matrix M2 =matrix_stress(add (A21, A22),B11);
    matrix M3 =matrix_stress(A11, sub(B12,B22));
    matrix M4 =matrix_stress(A22, sub(B21,B11));
    matrix M5 =matrix_stress(add(A11,A12),B22);
    matrix M6 =matrix_stress(sub(A21,A11),add(B11,B12));
    matrix M7 =matrix_stress(sub(A12,A22),add(B21,B22));

    matrix C11 =add(sub(add(M1,M4),M5),M7);
    matrix C12 =add(M3, M5);
    matrix C21 =add(M2,M4);
    matrix C22 =add(add(sub(M1,M2),M3),M6);

    put(c, C11, 0,0,h);
    put(c, C12, 0,h,h);
    put(c, C21, h,0,h);
    put(c, C22, h,h,h);

    return c;
}
int main(){
    
    int in;
    cin>>in;
    
    matrix matrixA = generate_matrix(in);
 
    matrix matrixB = generate_matrix(in);
    int n = matrixA.size();
    matrix result_it(n, vector<long long>(n,0));
    matrix result_dc(n, vector<long long>(n,0));
    matrix result_sc(n, vector<long long>(n,0));
    
    auto start = chrono::high_resolution_clock::now();
    result_it = matrix_mult(matrixA, matrixB, result_it);
    auto end = chrono::high_resolution_clock::now();
    long long total_it = chrono::duration_cast<chrono::microseconds>(end-start).count();
    auto it_mult = count_mult;
    count_mult=0;
    cout<<total_it<<"  "<<it_mult<<endl;

    
    start = chrono::high_resolution_clock::now();
    result_dc = matrix_div_con(matrixA, matrixB);
    end = chrono::high_resolution_clock::now();
    long long total_dc = chrono::duration_cast<chrono::microseconds>(end-start).count();
    auto dc_mult = count_mult;
    auto dc_add = count_add;
    count_mult = 0;
    count_add =0;
    cout<<total_dc<<"  "<<dc_mult<<"  "<<dc_add<<endl;


    
    start = chrono::high_resolution_clock::now();
    result_sc = matrix_stress(matrixA, matrixB);
    end = chrono::high_resolution_clock::now();
    long long total_sc = chrono::duration_cast<chrono::microseconds>(end-start).count();
    auto ss_mult= count_mult;
    auto ss_add = count_add;
    auto ss_sub = count_sub;
    cout<<total_sc<<"  "<<ss_mult<<"  "<<ss_add<<"  "<<ss_sub<<endl;
}