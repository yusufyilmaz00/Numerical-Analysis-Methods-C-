#include <stdio.h>
#include <math.h>

#define MAX 20
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
void bisection(POLY p,int N);
void regulaFalsi(POLY p, int N);

int main(){
	POLY p;
	int i,N,flag,choice;
	flag =1;
	while(flag==1){
		printf("\n0)QUIT\n1)Bisection Yontemi\n2)Regula Falsi Yontemi\n3)\n4)\n5)\n");
		printf("6)\n7)\n8)\n9)\n10)\n");
		printf("Seciminizi giriniz: ");
		scanf("%d",&choice);
		
		switch(choice){
			
			case 1:
				printf("\n|~~ Bisection Yontemi ~~|\n");
				getFunction(&p);
				N= p.n;
				bisection(p,N);
				printf("Ana Menu (1)\nProgrami Kapat (0)\nSecim: ");
				scanf("%d",flag);
				break;
			
			case 2:
				printf("\n|~~ Regula Falsi Yontemi ~~|\n");
				getFunction(&p);
				N= p.n;
				regulaFalsi(p,N);
				printf("Ana Menu (1)\nProgrami Kapat (0)\nSecim: ");
				scanf("%d",flag);
				break;
			
			case 3:
				
				break;
			
			case 4:
				
				break;
			
			case 5:
				
				break;
			
			case 6:
				
				break;
			
			case 7:
				
				break;
			
			case 8:
				
				break;
			
			case 9:
				
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
		
		printf("Iteration #%d\n",i,m,f_m);
		printf("L-> F(%lf): %lf\n",l,f_l);
		printf("M-> F(%lf): %lf\n",m,f_m);
		printf("R-> F(%lf): %lf\n\n",r,f_r);
		
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
		printf("A-> F(%lf): %lf\n",a,f_a);
		printf("C-> F(%lf): %lf\n",c,f_c);
		printf("B-> F(%lf): %lf\n\n",b,f_b);
		
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
	printf("Denklem koku: %lf\n\n",c);
}

	
