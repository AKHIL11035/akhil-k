#include<stdio.h>
#include<math.h>
double largest(int rows,double mat[rows][rows]){
   double Largest=0.00;
    for (int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
            if(i!=j){
               if(fabs(mat[i][j])>Largest){
                Largest=fabs(mat[i][j]);
               }
            }
        }
    }
    return Largest;
}
void mat_transpose(int rows,double A[rows][rows],double B[rows][rows]){
     for (int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
            B[i][j]=A[j][i];
        }
     }
}
void mat_multiply(int rows,double a[rows][rows],double identity[rows][rows],double c[rows][rows]){
	for(int i=0;i<rows;i++){
            for(int j=0;j<rows;j++){
                   c[i][j]=0.0;
	    }
	}
  for(int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
           for(int k=0;k<rows;k++){
           c[i][j]+=a[i][k]*identity[k][j];
	  }
        }
    }
}
int diagonal(int rows,double k[rows][rows]){
    double tol=1e-6;
     for (int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
            if(i!=j&&fabs(k[i][j])>tol){
              return 0;
            }
           
        }
     }
     return 1;
}
    

int main(){
    int rows;
    scanf("%d",&rows);
    double mat[rows][rows];
for (int i=0;i<rows;i++){
    for(int j=0;j<rows;j++){
    scanf("%lf",&mat[i][j]);
    }
   }
printf("The Entered Matrix is :\n");
for(int i=0;i<rows;i++){
	for(int j=0;j<rows;j++){
		printf("%lf ",mat[i][j]);
	}
	printf("\n");
}

while(!diagonal(rows,mat)){
double Large_offdiag=largest(rows,mat);
int p=0;
int q=0;
for (int i=0;i<rows;i++){
    for(int j=0;j<rows;j++){
        if(i!=j&&fabs(mat[i][j])==Large_offdiag){
            p=i;
            q=j;
        }
    }
}
double angle;
if(fabs(mat[p][p]-mat[q][q])<1e-9){
	angle=M_PI/4;}
	else{
		angle=0.5*atan(2.0*mat[p][q]/(mat[p][p]-mat[q][q]));}

double sin_value=sin(angle);
double cos_value=cos(angle);
//printf("sin:%lf,cos:%lf\n",sin_value,cos_value);
double identity[rows][rows];
for (int i=0;i<rows;i++){
    for(int j=0;j<rows;j++){
        if(i==j){
            identity[i][j]=1.00;
        }
        else{
            identity[i][j]=0.00;
        }
    }
}
identity[p][p]=cos_value;
identity[q][q]=cos_value;
identity[p][q]= -sin_value;
identity[q][p]=sin_value;

    double temp[rows][rows];
    double identityT[rows][rows];
    double B[rows][rows];
 
    mat_transpose(rows,identity,identityT);
    mat_multiply(rows,mat,identity,temp); 
 
    mat_multiply(rows,identityT,temp,B);

    for (int i=0;i<rows;i++){
    for(int j=0;j<rows;j++){
    mat[i][j]=B[i][j];
   
    }
}
}

printf("The Eigen Values of the Matrix are :\n");
for (int i=0;i<rows;i++){
   printf("%lf\n", mat[i][i]);
}

return 0;
}
