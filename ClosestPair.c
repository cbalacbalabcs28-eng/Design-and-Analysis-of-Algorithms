#include<stdio.h>
#include<math.h>
#include<float.h>
int main(){
   int n,i,j;
   int p1=0,p2=0;
   float x[50],y[50];
   float min_dist,dist;
   printf("Enter no.of points:");
   scanf("%d",&n);
   printf("Enter the points (xy):\n");
   for(i=0;i<n;i++){
      scanf("%f %f",&x[i],&y[i]);
   }
   min_dist =FLT_MAX;
   for(i=0;i<n-1;i++){
      for(j=i+1;j<n;j++){
         dist=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
         if(dist<min_dist){
            min_dist=dist;
            p1=i;
            p2=j;
         }
      }
   }
   printf("p%d (%.2f,%.2f)and p%d (%.2f,%.2f)\n",p1+1,x[p1],y[p1],p2+1,x[p2],y[p2]);
   printf("Minimum distance between closest pair is:%.2f\n",min_dist);
   return 0;
}
