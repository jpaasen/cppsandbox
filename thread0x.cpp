#include <vector>
#include <thread>
#include <iostream>

/**
* This example uses c++11. 
* For now compile using -std=c++0x -pthread
**/

using namespace std;

static const int num_threads = 10;//5;//20;

/**
* Calculates the power given by pow of all values in the given vector from index f to t.
**/
void vectorPow(const int &thread_id, vector<double> &vector, const int &pow, const int &f, const int &t) {
   //cout << "Thread " << thread_id << " working from " << f << " to " << t << endl;
   for (int i = f; i < t; ++i) {
      const double value = vector[i];
      for (int j = 0; j < pow-1; ++j) {
	vector[i] *= value;
      }
   }
}

int main() {
     
   const int N = 1e6;
   vector<double> vector;
   int pow = 2000;

   thread t[num_threads];
   const int idx_per_thread = N / num_threads; // TODO: Handle rest indices if num_threads is not i multiple of N

   for (int i = 0; i < N; ++i) {
      vector.push_back(i);
   }

   for (int i = 0; i < num_threads; ++i) {
      t[i] = thread(vectorPow, i, vector, pow, i*idx_per_thread, (i+1)*idx_per_thread);
   }

   for (int i = 0; i < num_threads; ++i) {
      t[i].join();
   }

   return 0;
}
