void reach_error ( ) { 
} 

void abort ( ) { 
} 

extern void abort ( void ) ; 
void reach_error ( ) { 
} 

int x , y ; 
int b1 , b2 ; 
int X ; 
void * thr1 ( void * _ ) { 
while ( 1 ) { 
b1 = 1 ; 
x = 1 ; 
if ( y != 0 ) { 
b1 = 0 ; 
while ( y != 0 ) { 
} 

} 

y = 1 ; 
if ( x != 1 ) { 
b1 = 0 ; 
while ( b2 >= 1 ) { 
} 

if ( y != 1 ) { 
while ( y != 0 ) { 
} 

} 

} 

} 

X = 0 ; 
if ( ! ( X <= 0 ) ) reach_error ( ) ; 

y = 0 ; 
b1 = 0 ; 
} 

void * thr2 ( void * _ ) { 
while ( 1 ) { 
b2 = 1 ; 
x = 2 ; 
if ( y != 0 ) { 
b2 = 0 ; 
while ( y != 0 ) { 
} 

} 

y = 2 ; 
if ( x != 2 ) { 
b2 = 0 ; 
while ( b1 >= 1 ) { 
} 

if ( y != 2 ) { 
while ( y != 0 ) { 
} 

} 

} 

} 

X = 3 ; 
if ( ! ( X >= 1 ) ) reach_error ( ) ; 

y = 0 ; 
b2 = 0 ; 
} 

int main ( ) { 
pthread_t t1 , t2 ; 
pthread_create ( & t1 , 0 , thr1 , 0 ) ; 
pthread_create ( & t2 , 0 , thr2 , 0 ) ; 
pthread_join ( t1 , 0 ) ; 
pthread_join ( t2 , 0 ) ; 
} 

