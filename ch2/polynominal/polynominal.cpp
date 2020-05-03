#include <iostream>
#include <string>
using namespace std;

/* polynominal data structure
*    arr[] = { polynominal total sum | polynominal exp, polynominal value, ... , polynominal exp, polynominal value};
*/

void Padd(int a[], int b[], int c[]);
char compare(int x, int y);
void output(string tags, int p[], int n);

const int a_size = 7;
const int b_size = 7;
const int c_size = 14;

int main(){

    int a[a_size] = {3, 4, 5, 2, 3, 0, 2};
    int b[b_size] = {3, 3, 6, 2, 2, 0, 1};
    int c[c_size];

    for(int i = 0 ; i < c_size ; ++i) {
        c[i] = -1;
    }

    Padd(a, b, c);
    output("a: ", a, a[0]);
    output("b: ", b, b[0]);
    output("c: ", c, c[0]);

    return 0;
}

void Padd(int a[], int b[], int c[]) {

    int pa_sum = a[0];
    int pb_sum = b[0];

    int pa_idx = 1;
    int pb_idx = 1;
    int pc_idx = 1;

    while((pa_sum > 0) && (pb_sum > 0)) {

        char result = compare(a[pa_idx], b[pb_idx]);
        switch (result) {
            case '=':
                c[pc_idx + 1] = a[pa_idx + 1] + b[pb_idx + 1];
                c[pc_idx] = a[pa_idx];
                pa_sum--;
                pb_sum--;
                pa_idx = pa_idx + 2;
                pb_idx = pb_idx + 2;
                pc_idx = pc_idx + 2;
                break;
            case '<':
                c[pc_idx + 1] = b[pb_idx + 1];
                c[pc_idx] = b[pb_idx];
                pb_sum--;
                pb_idx = pb_idx + 2;
                pc_idx = pc_idx + 2;
                break;
            case '>':
                c[pc_idx + 1] = a[pa_idx + 1];
                c[pc_idx] = a[pa_idx];
                pa_sum--;
                pa_idx = pa_idx + 2;
                pc_idx = pc_idx + 2;
                break;
            default:
                break;
        }
    }

    while(pa_sum > 0) {
        c[pc_idx + 1] = a[pa_idx + 1];
        c[pc_idx] = a[pa_idx];
        pa_sum--;
        pa_idx = pa_idx + 2;
    }

    while(pb_sum > 0) {
        c[pc_idx + 1] = b[pa_idx + 1];
        c[pc_idx] = b[pb_idx];
        pb_sum--;
        pb_idx= pb_idx + 2;
    }

    int count = 0;
    for(int i = 1 ; i < c_size - 1; ++i ) {
        if (c[i] != -1) {
            count++;
        }
    }

    c[0] = count / 2;
}

char compare(int x, int y) {
    if (x > y) {
        return '>';
    } else if (x < y) {
        return '<';
    } else {
        return '=';
    }
}

void output(string tags, int p[], int n) {

    int i;
    cout << tags << " ( ";
    cout << p[0];

    for(int i = 1; i < 2 * n ; ++i) {
        cout << "    " << p[i];
    }
    cout << " )" << endl;
}
