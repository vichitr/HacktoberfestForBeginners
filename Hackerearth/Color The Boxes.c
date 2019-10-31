#include<stdio.h>
#include<math.h>
int main()
{
  unsigned long int n,m,val=1,i,mod=1000000007;
  scanf("%lu %lu",&n,&m);
  for(i=1;i<=m;i++) {
    val=(val*i)%mod;
  }
  printf("%lu",val);
  return 0;
}
