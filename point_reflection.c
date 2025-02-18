#include<stdio.h>
int main(){
    int px,py,qx,qy,rx,ry;
    
    printf("Enter the co-ordinates of point P : ");
    scanf("%d%d",&px,&py);
    printf("Enter the co-ordinates of point Q: ");
    scanf("%d%d",&qx,&qy);
    
    rx= 2*qx-px;
    ry = 2*qy-py;
    printf("The co-ordinates of r are : %d %d ",rx,ry);
    return 0;
}
