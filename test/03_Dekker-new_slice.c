void reach_error ( ) { 
} 

void abort ( ) { 
} 

extern void abort ( void ) ; 
void reach_error ( ) { 
} 

int flag1 = 0 , flag2 = 0 ; 
int turn = 0 ; 
int x ; 
void * thr1 ( void * arg ) { 
flag1 = 1 ; 
while ( flag2 >= 1 ) { 
if ( turn != 0 ) { 
flag1 = 0 ; 
while ( turn != 0 ) { 
} 

flag1 = 1 ; 
} 

} 

x = 0 ; 
if ( ! ( x <= 0 ) ) { 
reach_error ( ) ; 
abort ( ) ; 
} 

turn = 1 ; 
flag1 = 0 ; 
} 

void * thr2 ( void * arg ) { 
flag2 = 1 ; 
while ( flag1 >= 1 ) { 
if ( turn != 1 ) { 
flag2 = 0 ; 
while ( turn != 1 ) { 
} 

flag2 = 1 ; 
} 

} 

x = 4 ; 
x = 1 ; 
if ( ! ( x >= 1 ) ) { 
reach_error ( ) ; 
abort ( ) ; 
} 

turn = 1 ; 
flag2 = 0 ; 
} 

int main ( ) { 
pthread_t t ; 
pthread_create ( & t , 0 , thr1 , 0 ) ; 
thr2 ( 0 ) ; 
} 
