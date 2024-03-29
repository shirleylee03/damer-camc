extern void abort(void); 
void reach_error(){}

#include <pthread.h>

#define assert(e) { if(!(e)) { ERROR: {reach_error();abort();}(void)0; } }

int flag1 = 1, flag2 = 1; // N integer flags 
int x, y; // variable to test mutual exclusion

void* thr1(void* arg) {
  while (1) {
    flag1 = 1;
    while (flag2 >= 3); 
    flag1 = 3;
    if (flag2 == 1) {
      flag1 = 2;
      while (flag2 != 4);
    }
    flag1 = 4;
    while (flag2 >= 2);
    // begin critical section
    x = 0;
    assert(x<=0);
    // end critical section
    while (2 <= flag2 && flag2 <= 3);
    flag1 = 0;
  }

  return 0;
}

void* thr2(void* arg) {
  while (1) {
    flag2 = 1;
    while (flag1 >= 3);
    flag2 = 3;
    if (flag1 == 1) {
      flag2 = 2;
      while (flag1 != 4);
    }
    flag2 = 4;
    while (flag1 >= 2);
    // begin critical section
	  x = 2;
    assert(x>=1);
    // end critical section
    while (2 <= flag1 && flag1 <= 3);
    flag2 = 0;
  }

  return 0;
}

int main()
{
  pthread_t t;

  pthread_create(&t, 0, thr1, 0);
  thr2(0);
  y = 2;

  return 0;
}

