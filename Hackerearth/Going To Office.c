#include<stdio.h>
int main()
{
  long int D,Oc,Of,Od,Cs,Cb,Cm,Cd;
  float O,C;
  scanf("%ld",&D);
  scanf("%ld%ld%ld",&Oc,&Of,&Od);
  scanf("%ld%ld%ld%ld",&Cs,&Cb,&Cm,&Cd);
  O=(Oc+(D-Of)*Od);
  C=Cb+((D/Cs)+Cm)+(D*Cd);
  if(O<=C)
    printf("Online Taxi");
  else
    printf("Classic Taxi");
return 0;
}
