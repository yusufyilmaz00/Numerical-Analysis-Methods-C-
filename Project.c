#include <stdio.h>
#include <math.h>

#define MAX 25


typedef struct term{
	double coef;
	int exponent;
}TERM;

typedef struct poly{
	TERM t[MAX];
	int n;
}POLY;

void getFunction(POLY* p);
double calculateFunction(POLY p,double x,int N);
double calculateDerivative(POLY p,double x,int N);
void getMatrix(double matrix[MAX][MAX],int N,int M);
void showMatrix(double matrix[MAX][MAX], int N,int M);


void bisection(POLY p,int N);
void regulaFalsi(POLY p, int N);
void newtonRaphson(POLY p,int N);
void matrixInverse(double matrix[MAX][MAX],int N);
void gaussElimination();
void numericalDerivative(POLY p,int N);
void trapezoidal(POLY p,int N);


int main(){
	POLY p;
	int i,N,flag,choice;
	flag =1;
	while(flag==1){
		printf("\n0)QUIT\n1)Bisection Method\n2)Regula Falsi Method\n3)Newton Rapshon Method\n4)Inverse Matrix\n5)Gauss Elimination Method\n");
		printf("6)\n7)Numerical Derivative\n8)\n9)Trapezoidal Rule\n10)\n");
		printf("Seciminizi giriniz: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 0:
				flag=0;
				break;
				
			case 1:
				printf("\n|~~ Bisection Method ~~|\n");
				getFunction(&p);
				N= p.n;
				bisection(p,N);
				printf("Ana Menu (1)\nProgrami Kapat (0)\nSecim: ");
				scanf("%d",flag);
				break;
			
			case 2:
				printf("\n|~~ Regula Falsi Method ~~|\n");
				getFunction(&p);
				N= p.n;
				regulaFalsi(p,N);
				printf("Ana Menu (1)\nProgrami Kapat (0)\nSecim: ");
				scanf("%d",flag);
				break;
			
			case 3:
				printf("\n|~~ Newton Rapshon Method ~~|\n");
				getFunction(&p);
				N= p.n;
				newtonRaphson(p,N);
				
				printf("Ana Menu (1)\nProgrami Kapat (0)\nSecim: ");
				scanf("%d",flag);
				
				break;
			
			case 4:
				printf("\n|~~ Inverse Matrix ~~|\n");
				double matrix[MAX][MAX];
				int N;
				
				printf("Enter a matrix size: ");
				scanf("%d",&N);
				
				getMatrix(matrix,N,N);
				matrixInverse(matrix,N);
				
				printf("Ana Menu (1)\nProgrami Kapat (0)\nSecim: ");
				scanf("%d",flag);
				break;
			
			case 5:
				printf("\n|~~ Gauss Elimination Method ~~|\n");
				
				gaussElimination();
				break;
			
			case 6:
				
				break;
			
			case 7:
				printf("\n|~~ Numerical Derivative ~~|\n");
				getFunction(&p);
				N= p.n;
				numericalDerivative(p,N);
				break;
			
			case 8:
				
				break;
			
			case 9:
				printf("\n|~~ Trapezoidal Rule ~~|\n");
				getFunction(&p);
				N= p.n;
				trapezoidal(p,N);
				break;
				
			case 10:
				
				break;
			
			default:
				printf("Gecerli Deger Giriniz !\n");
		}
			
		
	}
	
	
	return 0;
}

void getFunction(POLY* p){
	int i,N;
	printf("Please enter how many x do you want in your polynomial (For example ax2 + bx + c has 3 x values): ");
	scanf("%d",&N);
	p->n = N;
	for(i=0;i<N;i++){
		printf("Enter x's coefficient: ");
		scanf("%lf",&p->t[i].coef);
		printf("Enter x's power: ");
		scanf("%d",&p->t[i].exponent);
	}
	printf("\n");
	for(i=0;i<N-1;i++){
		printf("%.2lf * X^%d + ",p->t[i].coef,p->t[i].exponent);
	}
	printf("%.2lf* X^%d \n",p->t[i].coef,p->t[i].exponent);
}

double calculateFunction(POLY p,double x,int N){
	int i;
	double result;
	result = 0.0;

	for(i=0;i<N;i++){
		result += p.t[i].coef * pow(x , p.t[i].exponent);
	}
	return result; 
}

double calculateDerivative(POLY p,double x,int N){
	int i,j;
	double result,number,powResult;
	result = 0.0;

	for(i=0;i<N;i++){
		number = p.t[i].coef * p.t[i].exponent ;
		powResult = 1.0;
		if(p.t[i].exponent !=0){
			for(j=0;j < p.t[i].exponent-1 ;j++){
				powResult *= x;
			}	
		}
	result += number * powResult;  		
	}
	return result; 
}

void getMatrix(double matrix[MAX][MAX], int N,int M){
	int i,j;
	    
    for(i=0;i<N;i++){
    	for(j=0;j<M;j++){
    		printf("A[%d][%d]: ",i,j);
			scanf("%lf",&matrix[i][j]);
		}
	}	
}

void showMatrix(double matrix[MAX][MAX], int N,int M){
	int i,j;
	
	for (i=0;i<N;i++){
    	printf("|");
        for (j=0;j<M;j++){
        	if(matrix[i][j] >=10)
        		printf(" %.2lf  |",matrix[i][j]);
        	else if(matrix[i][j] >=0)
				printf(" %.2lf   |",matrix[i][j]);
			else if(matrix[i][j] <0 && matrix[i][j] > -10)
				printf(" %.2lf  |",matrix[i][j]);
			else
				printf(" %.2lf |",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


//Numeric Analysis Methods 
void bisection(POLY p,int N){
	double  l,r,m,f_l,f_r,f_m,tolerance;
	int i,iterMax;
	
	printf("Enter a max iteration value: ");
    scanf("%d",&iterMax);
    
	do{
	printf("\nEnter an {a} value for [a,b]: ");
	scanf("%lf",&l);
	printf("Enter a {b} value for [a,b]: ");
	scanf("%lf",&r);
	}while(calculateFunction(p,l,N) * calculateFunction(p,r,N) > 0);
	
	printf("Enter a tolerance value: ");
    scanf("%lf",&tolerance);
	printf("\n");
	
	i=1;
	f_l =calculateFunction(p,l,N);
	f_r =calculateFunction(p,r,N);
	
	while ( (r-l)/pow(2,i) > tolerance && i <= iterMax &&(f_l * f_r) < 0 ){
		m = (l+r)/2 ; 
		f_m =calculateFunction(p,m,N); 
		
		printf("Iteration #%d\n",i);
		printf("left  -> F(%lf): %lf\n",l,f_l);
		printf("mid   -> F(%lf): %lf\n",m,f_m);
		printf("right -> F(%lf): %lf\n\n",r,f_r);
		
		if(f_l * f_m  < 0)
			r = m;
		else if(f_r * f_m < 0)
			l = m;		
			
		f_l =calculateFunction(p,l,N);
		f_r =calculateFunction(p,r,N); 
		i +=1;
	}
	
	printf("Result : %lf\n\n",m);
}

void regulaFalsi(POLY p, int N){
	double  a,b,c,c2,f_a,f_b,f_c,tolerance;
	int i,iterMax;
	
	printf("Enter a max iteration value: ");
    scanf("%d",&iterMax);
    
	do{
	printf("\nEnter an {a} value for [a,b]: ");
	scanf("%lf",&a);
	printf("Enter a {b} value for [a,b]: ");
	scanf("%lf",&b);
	}while(calculateFunction(p,a,N) * calculateFunction(p,b,N) > 0);
	
	printf("Enter a tolerance value: ");
    scanf("%lf",&tolerance);
	printf("\n");
	
	i=1;
	f_a =calculateFunction(p,a,N);
	f_b =calculateFunction(p,b,N);
	
	
	while ( fabs(b-a) / pow(2,i) > tolerance && i <= iterMax && (f_a * f_b) < 0 ){	
		c= ( (b* f_a) - (a * f_b) ) / (f_a - f_b); 	
		f_c = calculateFunction(p, c, N);
		
		printf("Iteration #%d\n",i);
		printf("start -> F(%lf): %lf\n",a,f_a);
		printf("point -> F(%lf): %lf\n",c,f_c);
		printf("end   -> F(%lf): %lf\n\n",b,f_b);
		
		if(f_b * f_c  < 0)
			a = c;
		else if(f_a * f_c < 0)
			b = c;
			
		c= ( (b* f_a) - (a * f_b) ) / (f_a - f_b); 	
		f_a =calculateFunction(p,a,N);
		f_b =calculateFunction(p,b,N);
		f_c = calculateFunction(p, c, N); 
		i +=1;
	}
	printf("Result: %lf\n\n",c);
}

void newtonRaphson(POLY p,int N){
	double  tolerance,x,xnew,f_x,f_dx;
	int i,is_value,iterMax;
	
	printf("\nEnter an x0 starting value: ");
	scanf("%lf",&xnew);
	printf("Enter a tolerance value: ");
    scanf("%lf",&tolerance);
    printf("Enter a max iteration value: ");
    scanf("%d",&iterMax);
    x = xnew + 2 * tolerance; // temporary value to satisfy the loop condition
	printf("\n");
	i=1;
	while( fabs(xnew - x) > tolerance && i <= iterMax){
		x = xnew;
		f_x = calculateFunction(p,x,N);
		f_dx = calculateDerivative(p,x,N);
		xnew  = x - (f_x / f_dx);
		printf("Iteration #%d\n",i);
		printf("x(n)   : %lf\n",x);
		printf("x(n+1) : %lf\n",xnew);
		printf("f(xn)  : %lf\n",f_x);
		printf("f'(xn) : %lf\n\n",f_dx);
		
		i +=1;
	}
	printf("Result: %lf\n\n",xnew);
}

void matrixInverse(double matrix[MAX][MAX],int N){
    double temp,identity[MAX][MAX];
	int i,j,k;
	
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            if(i==j)
				identity[i][j] = 1.0;
			else
				identity[i][j] = 0.0;
        }
    }
    
    // Calculate inverse matrix with Gauss-Jordan method
    for (i=0;i<N; i++){
		temp = matrix[i][i];
		
        for (j=0;j<N;j++){
            matrix[i][j] /= temp;
            identity[i][j] /= temp;
        }
        
        for (j=0;j<N;j++){
            if (j != i){
                temp = matrix[j][i];
                
                for (k=0;k<N;k++){
                    matrix[j][k] -= matrix[i][k] * temp;
                    identity[j][k] -= identity[i][k] * temp;
                }
            }
        }
    }
    printf("Inverse Matrix:\n");
    showMatrix(identity,N,N);	
}

void gaussElimination(){
	int i,j,k,N;
	double matrix[MAX][MAX],solution[MAX];
	double ratio,sum;
	
	printf("Enter a equations count: ");
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		printf("Enter the coefficients\n");
		for(j=0;j<N;j++){
			printf("x%d: ",j+1);
			scanf("%lf",&matrix[i][j]);
		}
		printf("result = ");
		scanf("%lf",&matrix[i][j]);
	}
	
	printf("\nOur Matrix:\n");
	showMatrix(matrix,N,N+1);
	
	//transform into triangular matrix
	for (i=0;i<N-1;i++){
        if(matrix[i][i] == 0.0){
            printf("The pivot element is zero. Exiting....\n");
            return;
        }
		
		for(j=i+1;j<N;j++){
			ratio = matrix[j][i] / matrix[i][i];
			for(k=0;k<=N;k++){
				matrix[j][k] -= ratio * matrix[i][k];	
			}
		}
	}
	
	//getting solutions
	for(i=N-1;i>=0;i--){
        sum = 0.0;    
        for(j=i+1;j<N;j++){
            sum += matrix[i][j] * solution[j];
        }
        solution[i] = (matrix[i][N] - sum) / matrix[i][i];
    }
    printf("Matrix after Gaussian elimination:\n");
	showMatrix(matrix,N,N+1);
	
	printf("Solutions:\n");
    for (i=0;i<N;i++){
        printf("x%d = %.2lf\n",i+1,solution[i]);
    }
}

void numericalDerivative(POLY p,int N){
	int subType;
	double h,x,f_dx,f_x,f_xi;
	
	printf("Choose sub-method:\n1)Forward differencing\n2)Backward differencing\n3)Centered differencing\n4)Show result with every sub-method\n");
	scanf("%d",&subType);
	printf("Enter a delta x value: ");
	scanf("%lf",&h);
	printf("Enter a X value that you want to calculate F'(x): ");
	scanf("%lf",&x);
	
	switch(subType){
		case 1:
				printf("\n|~~ Forward differencing ~~|\n\n");
				f_x = calculateFunction(p,x,N);
				f_xi = calculateFunction(p,x+h,N);
				f_dx = (f_xi - f_x) / h;
				printf("f(x): %.3lf\n",f_x);
				printf("f(x+i): %.3lf\n",f_xi);
				printf("f'(x): %.3lf\n\n",f_dx); 
			break;
		
		case 2:
				printf("\n|~~ Backward differencing ~~|\n");
				f_x = calculateFunction(p,x,N);
				f_xi = calculateFunction(p,x-h,N);
				f_dx = (f_x - f_xi) / h;
				printf("f(x): %.3lf\n",f_x);
				printf("f(x-i): %.3lf\n",f_xi);
				printf("f'(x): %.3lf\n\n",f_dx); 
			break;
			
		case 3:
				printf("\n|~~ Centered differencing ~~|\n");
				f_x = calculateFunction(p,x-h,N);
				f_xi = calculateFunction(p,x+h,N);
				f_dx = (f_xi - f_x) / (2*h);
				printf("f(x-i): %.3lf\n",f_x);
				printf("f(x+i): %.3lf\n",f_xi);
				printf("f'(x): %.3lf\n\n",f_dx); 
			break;
		
		case 4:
			printf("\n|~~ All Sub-methods ~~|\n");
				f_x = calculateFunction(p,x,N);
				
				printf("f(x): %.3lf\n",f_x);
				f_dx = ( calculateFunction(p,x+h,N) - f_x) / h;
				printf("Forward  -> f'(x): %.3lf\n", f_dx );
				f_dx = ( f_x - calculateFunction(p,x-h,N) ) / h;
				printf("Backward -> f'(x): %.3lf\n", f_dx);
				f_dx = ( calculateFunction(p,x+h,N) - calculateFunction(p,x-h,N) ) / (2*h);
				printf("Centered -> f'(x): %.3lf\n\n",f_dx);
				break;
		default:
			printf("Gecerli Deger Giriniz !\n");
			break;
	}
	
}

void trapezoidal(POLY p,int N){
	double a,b,h,f_x,result;
	int i,n;
	result =0.0;
	printf("Enter the starting point [a,b]: ");
	scanf("%lf",&a);
	printf("Enter the ending point [a,b]: ");
	scanf("%lf",&b);
	
	printf("Provide n value: ");
	scanf("%d",&n);
	h = (b-a) / n;
	
	for(i=1;i<n;i++){
		result += calculateFunction(p, a+(i*h) ,N);
	}
	result *= h;
	result += ( calculateFunction(p,a,N) + calculateFunction(p,b,N) ) * h/2 ;
	printf("\nYour Result: %.4lf\n\n",result);	
}
