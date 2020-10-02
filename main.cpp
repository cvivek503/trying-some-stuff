#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

double A[3][3]={0.0};
double f=1;



void shear(double A[3][3],double Shx,double Shy,int n)
{

     if(n>1)
        line(A[0][0],A[1][0],A[0][1],A[1][1]);
         if(n>2)
         {

           line(A[0][0],A[1][0],A[0][2],A[1][2]);
            line(A[0][1],A[1][1],A[0][2],A[1][2]);}
     double SH[3][3] = { { 1, Shx, 0 },
                    { Shy, 1, 0 },
                    { 0, 0, 1 } };

            double result[3][3];

    m(SH,A,result);

     if(n>1)
        line(A[0][0],A[1][0],A[0][1],A[1][1]);
         if(n>2)
         {

           line(A[0][0],A[1][0],A[0][2],A[1][2]);
            line(A[0][1],A[1][1],A[0][2],A[1][2]);}

}

void scale(double A[3][3],double Sx,double Sy,int n)
{
     double S[3][3] = { { Sx, 0, 0 },
                    { 0, Sy, 0 },
                    { 0, 0, 1 } };


            double result[3][3];

    m(S,A,result);

    if(n>1)
        line(A[0][0],A[1][0],A[0][1],A[1][1]);
         if(n>2)
         {

           line(A[0][0],A[1][0],A[0][2],A[1][2]);
            line(A[0][1],A[1][1],A[0][2],A[1][2]);}


}
void rot(double A[3][3],double angle,int n)
{
    double cost,sint;
	double result[3][3];
    angle = angle*(3.1415)/180;

      cost=cos(angle);    sint=sin(angle);
       double re[3][3] = {
                        { cost,(-1.0*sint) , 0 },
                        { sint, cost, 0 },
                         { 0, 0, 1 } };
           m(re,A,result);
           if(n>1)
        line(A[0][0],A[1][0],A[0][1],A[1][1]);
         if(n>2)
         {

           line(A[0][0],A[1][0],A[0][2],A[1][2]);
            line(A[0][1],A[1][1],A[0][2],A[1][2]);}


}

int main()
{
   initwindow(1000,800);
    A[2][0]=A[2][1]=A[2][2]=1;
     int n,y;

   char g='y';
   int v=0;

   while(g=='y'||g=='Y')
   {
       cout<<"Which operation you wanna perform ?"<<endl;
       cout<<" 1. Translation"<<endl;
       cout<<" 2. Rotation"<<endl;
       cout<<" 3. Scaling"<<endl;
       cout<<" 4. Shearing"<<endl;
       cout<<" 5. reflection about x axis"<<endl;
       cout<<"6. reflection about y axis"<<endl;
       cout<<" 7. reflection about ax+by=c:"<<endl;
       cin>>y;
       if(v==0)
       {  cout<<" no. of points ? "<<endl;
   cin>>n;
for(int j=0;j<n;++j)
    for(int i=0;i<2;++i)
        cin>>A[i][j];



       }
       if(n>1)
        line(A[0][0],A[1][0],A[0][1],A[1][1]);
         if(n>2)
         {

           line(A[0][0],A[1][0],A[0][2],A[1][2]);
            line(A[0][1],A[1][1],A[0][2],A[1][2]);}

       v=1;
       if(y==1)
       { double tx,ty;
       cout<<"enter tx,ty";
       cin>>tx>>ty;
       translation(A,tx,ty,n);
       }
       else if(y==2)
       {
         double angle;
         cout<<"enter angle to rotate:";
         cin>>angle;
        rot(A,angle,n);


       }
       else if(y==3){
        cout<<"enter Sx and Sy:";
        double Sx,Sy;
        cin>>Sx>>Sy;
    scale(A,Sx,Sy,n);

       }
       else if(y==4)
       { cout<<"Enter Shx and Shy :"<<endl;
       double Shx,Shy;
       cin>>Shx>>Shy;
       shear(A,Shx,Shy,n);



       }
       else if(y==5)
       {
           refx(A,n);
       }
       else if(y==6)
       {
          refy(A,n);


       }
       else{
         cout<<"Enter a,b and c:"<<endl;

         double a,b,c,g,h;
         cin>>a>>b>>c;
            if(b!=0)
         reff(-1*a/b,c/b);
         else
         {
             refs(c/a,n);


         }


       }

       cout<<"Want to perform further operations on this point?"<<endl;
       cin>>g;
       if(g=='n'||g=='N')
        break;

   }
return 0;

}
