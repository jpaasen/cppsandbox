#include <iostream>
#include <vector>

using namespace std;

/**
* Calculates the power given by pow of all values in the given vector.
* Compiled with -fopenmp the operation will execute in parallel.
**/
void vectorPow(vector<double> &vector, const int &pow) {
   #pragma omp parallel for
   for (size_t i = 0; i < vector.size(); ++i) {
      double value = vector[i];
      //#pragma omp parallel for // The code runs faster with this commented out
      for (int j = 0; j < pow-1; ++j) {
	vector[i] *= value;
      }
   }
}

int main() {
     
   const int N = 1e6;
   vector<double> vector;
   int pow = 2000;

   for (int i = 0; i < N; ++i) {
      vector.push_back(i);
   }

   vectorPow(vector, pow);

   return 0;
}
