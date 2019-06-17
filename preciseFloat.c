// preciseFloat.c

#include <stdio.h>
#include <stdlib.h>


void KahnSummation()
{
  float sum = 0.0;
  float c = 0.0;
  for(int i = 0; i < 20000000; i++)
  {
    float x = 1.0;
    float y = x - c;
    float t = sum + y;
    c = t-sum-y;
    sum = t;
  }
  printf("Kahn Summation->sum: %f\n",sum);
}


int main()
{
    float sum = 0.0;
    for(int i = 0; i < 20000000; i++)
    {
	float x = 1.0;
        sum += x;
    }
    printf("sum: %f\n",sum);
    KahnSummation();
}

