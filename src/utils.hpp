#include <math.h>
#include <cstdlib>
#include <sys/time.h>

#define DEG2RAD(x) (M_PI/180.0)*x

/*
 * measure time in milliseconds
 */
double mstime()
{
  timeval tv;
  gettimeofday(&tv,NULL);
  long long ts = tv.tv_sec;
  ts *= 1000000;
  ts += tv.tv_usec;
  return (double)ts*.001;
}

/*
 * set a seed for random number generation
 * @param seed the seed
 */
void setSeed( const unsigned long int _seed )
{
  srand48( _seed );
}

/*
 * sample from the given gaussian distribution (zero mean, std)
 * @param std standard deviation
 * @return resulting sample
 */
double sampleGaussian( const double _std )
{
  double x1, x2, w;
  double r;
  do
  {
    do
    {
      r= drand48();
    }while( r == 0.0f );
    x1= 2.0f * r - 1.0f;
    do
    {
      r= drand48();
    }while( r == 0.0f );
    x2= 2.0f * drand48() - 1.0f;
    w= x1*x1 + x2*x2;
  }while( w > 1.0f || w==0.0f );

  return( _std * x2 * sqrt(-2.0*log(w)/w) );
}
