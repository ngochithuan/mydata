#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI 3.1415926535
// Khai bao bien input
int  n,dc, dg, ld,bc=0,bg=0;
float i;
char w[10];
//Khai bao bien output
double nd;
int temp;
int main(){
	FILE *f;												// Dat con tro la f
	f=fopen("input.INP","r");								// Mo file chua input
	if (f==NULL){											// Check mo duoc file khong	
		printf("\n Error! Opening file!");
		exit(1);}
	fscanf(f,"%d %d %d %d %s", &n, &dc, &dg, &ld, w);		// Lay data tu file input.INP
    fclose(f);
	f=fopen("output.OUT","w");
	if (f==NULL){
		printf("Error!");
		exit(1);}
	// Kiem tra du lieu rang buoc
	if (n<=0||n>2000||dc<0||dg<0||ld<=0||ld>600||(dc==0&&dg==0)) {temp=0; goto output;}
	else temp=1;
	double a_bc = pow(dc,2) * sqrt(dc);
	double a_bg = (pow(dg,2) * PI)/3;
	double nn=(double)n;
	//Calculate theo cac thuoc tinh thoi tiet
	// Thoi tiet Sun
		if ((strcmp(w, "Sun"))==0){
			int X;
			int G=dc%6, H=ld%5; 
			//Ma tran tinh X
			if (G==H){X=5;}
			if (G==H+1){X=7;}	
			if (G==(H+2)%6){X=10;}
			if (G==(H+3)%6){X=12;}
			if (G==(H+4)%6){X=15;}
			if (G==(H+5)%6){X=20;}	
			//Tang X% nep 
			//Thu hoi X la dong
			nn*=((100+X)*0.01);
			n = (int)nn;
			nn = (double)n;
			ld-=X;
			if (ld<=0){temp=0; goto output;}
			if (((dc+dg)%3)==0){printf("Rain"); goto Rain;}
			if (((dc+dg)%3)==1){printf("Wind");  goto Wind;}
			if (((dc+dg)%3)==2){printf("Cloud"); goto Cloud;}
		}	
		//Thoi tiet Wind
		//tinh so banh chung nhieu nhat
		if ((strcmp(w, "Wind"))==0){										
		 	Wind:
		 	if (dc==0){
				while (ld>0){
					bg+=1;
					nd = nn - a_bg;
					nn-= a_bg;
					if (dg<5)ld-=1;
					else ld-=2;
					if(ld==-1){
						bg-=1;
						nd+=a_bg;
						ld+=2;
						goto output;				
					}
					if (nd<0){
						bg-=1;
						nd+=a_bg;
						goto output;	
					}
				}
				if (ld == 0){goto output;}
			}	
			if (dg==0){
				while (ld>0){
					bc+=1;
					nd = nn- a_bc;
					nn -=a_bc;
					if (dc < 8) ld-=1;
					else ld-=2;
					if (ld==-1){
						bc-=1;
						nd+=a_bc;
						ld+=2;
						goto output;
					}
					if(nd<0){
						bc-=1;
						nd+=a_bc;
						goto output;
					}
				}
				if (ld == 0){goto output;}
			}
			while (ld>0){
				bc+=1;
				nd = nn - a_bc;
				nn-=a_bc;
				if (dc<8) ld-=1;
				else ld-=2;
				if (ld==0){
					if (((dc>=8&&dg<5)&&(a_bc>2*a_bg))||((dc<8&&dg>=5))&&(2*a_bc>a_bg)||((a_bc>a_bg)&&(dc<8&&dg<5))||((a_bc>a_bg)&&(dc>=8&&dg>=5)))
					{goto output;}
					else {
						if (dc<8) ld+=bc;
						else ld+=2*bc;
						nn=(double)n;
						bc=0,bg=0;
						goto lam_bg_w;
					}
				}
				if (ld==-1){
					ld+=2;
					bc-=1;
					nd += a_bc;
					nn += a_bc;
					if (((dc>=8&&dg<5)&&(a_bc>2*a_bg))||((dc<8&&dg>=5))&&(2*a_bc>a_bg)||((a_bc>a_bg)&&(dc<8&&dg<5))||((a_bc>a_bg)&&(dc>=8&&dg>=5))){
						if (dc<5){ goto lam_bg_w;}
						else{ goto output;}
					}
					else{
						ld+=2*bc;
						nn=(double)n;
						bc=0;bg=0;
						goto lam_bg_w;
					}
				}
				if (nd<a_bc&&nd>0) break;
				if (nd<0){
					bc-=1;
					nd+=a_bc;
					nn+=a_bc;
				}
			}
			if (nd<a_bc|| ld==0){ goto output;}
			else {
				while (ld>0){
					lam_bg_w:
					bg+=1;
					nd = nn - a_bg;
					nn-= a_bg;
					if ( dg<5) ld-=1;
					else ld -=2;
					if (ld==-1){
						nd+= a_bg;
						ld+=2;
						bg-=1;
						goto output;
					}
					if (nd<0){
						bg-=1;
						nd+=a_bg;
						nn+=a_bg;					
					}
					if (nd<a_bg&&nd>a_bc&&ld>0){goto lam_bc_w;}
					if (nd<a_bg){goto output;}				
				}
				if (ld==0){goto output;}
			}
			while (ld>0){
				lam_bc_w:
				bc+=1;
				nd = nn - a_bc;
				nn-= a_bc;
				if(dc<8) ld-=1;
				else ld-=2;
				if (ld==-1){
					nd+=a_bc;
					nn+=a_bc;
					ld+=2;
					bc-=1;
					goto output;
				}
				if (nd<a_bc&&nd>0) goto output;
				if (nd<0){
					bc-=1;
					nd+=a_bc;
					goto output;
				}
			}
			if (ld==0){goto output;}
		}				
		if ((strcmp(w, "Cloud"))==0){
			Cloud:
			if (dc==0){
				while(ld>0){
					bg +=1;
					nd  = nn - a_bg;
					nn -=a_bg;
					if (dg<5) ld-=1;
					else ld -=2;
					if (ld==-1){
						nd += a_bg;
						ld += 2;
						bg -= 1;
						goto output;
					}
					if (nd<0){
						bg-=1;
						nd+= a_bg;
						goto output;
					}
				}
				if (ld==0){goto output;}
			}
			if (dg==0){
				while (ld>0){
					bc +=1;
					nd  = nn - a_bc;
					nn -= a_bc;
					if (dc<8) ld-=1;
					else ld-=2;
					if (ld==-1){
						nd += a_bc;
						ld += 2;
						bc =-1;
						goto output;
					}					
					if (nd<0){
						bc -= 1;
						nd +=a_bc;
						goto output;
					}
				}
				if (ld==0){goto output;}
			}
			int check=0, check1=0,i,j;
			for (i=1;i<n;i++){if (n%i==0) check+=i;}
			for (j=1;j<ld;j++){if (ld%j==0) check1+=j;}
			if (check==ld&&check1==n){
				nd=(double)n;
				goto output;
			}
			else{
				while (ld>0){
					bg +=1;
					nd  = nn - a_bg;
					nn -=a_bg;
					if (dg<5) ld-=1;
					else ld-=2;
					if (ld==0){
						if (((dc>=8&&dg<5)&&(a_bc<2*a_bg))||((dc<8&&dg>=5))&&(2*a_bc<a_bg)||((a_bc<a_bg)&&(dc<8&&dg<5))||((a_bc<a_bg)&&(dc>=8&&dg>=5)))
						{goto output;}
						else {
							if (dg<5) ld+=bg;
							else ld+= 2*bg;
							nn = (double)n;
							bc=0, bg=0;
							goto lam_bc_C;
						}
					}
					if (ld==-1){
						nd += a_bg;
						nn += a_bg;
						ld +=2;
						bg -=1;
						if (((dc>=8&&dg<5)&&(a_bc<2*a_bg))||((dc<8&&dg>=5))&&(2*a_bc<a_bg)||((a_bc<a_bg)&&(dc<8&&dg<5))||((a_bc<a_bg)&&(dc>=8&&dg>=5))){
							if (dc<8) goto lam_bc_C;
							else goto output;
						}
						else{
							ld += 2*bg;
							nn  = (double)n;
							bc=0, bg=0;
							goto lam_bc_C;
						}
					}
					if (nd< a_bg && nd>0) break;
					if (nd<0){
						bg -= 1;
						nd += a_bg;
						nn += a_bg;
					}
				}
				if (nd<a_bc|| ld==0){ goto output;}
				else {
					while (ld>0){
						lam_bc_C:
						bc+=1;
						nd = nn - a_bc;
						nn -= a_bc;
						if (dc<8) ld-=1;
						else ld-=2;
						if (ld==-1){
							nd += a_bc;
							nn += a_bc;
							ld += 2;
							bc -= 1;
							if (nd>=a_bg &&dg<5) goto lam_bg_C;
							else goto output;
						}
						if ( nd<0){
							bc -= 1;
							nd += a_bc;
							nn += a_bc;
						}
						if (nd>a_bc) {continue;}
						if (nd<a_bc && nd>a_bg&&ld>0){goto lam_bg_C;}
						if (nd< a_bg){goto output;}
					}
				}
				if (ld==0){ goto output;}
				while (ld>0){
					lam_bg_C:
					bg+=1;
					nd  = nn - a_bg;
					nn -= a_bg;
					if (dg<5) ld-=1;
					else ld-=2;
					if (ld==-1){
						nd+=a_bg;
						nn+=a_bg;
						ld+=2;
						bg-=1;
						goto output;
					}
					if (nd<a_bg && nd>0) goto output;
					if (nd<0){
						bg=-1;
						nd+=a_bg;
						goto output;
					}
				}
				if (ld==0){ goto output;}
			}
		}
		if ((strcmp(w, "Fog"))==0){
			Fog:
			if (dc == 0){
				while (ld>0){
					bg +=1;
					nd  = nn - a_bg;
					nn -= a_bg;
					if (dg<5) ld-=1;
					else ld -= 2;
					if (ld == -1){
						nd += a_bg;
						ld +=2;
						bg -=1;
						goto output;
					}
					if (nd<0){
						bg -= 1;
						nd += a_bg;
						goto output;
					}
				}
				if (ld==0){goto output;}
			}
			if (dg == 0){
				while (ld > 0){
					bc +=1;
					nd  = nn - a_bc;
					nn -= a_bc;
					if (dc<8) ld -= 1;
					else ld -= 2;
					if (ld==-1){
						nd += a_bc;
						ld += 2;
						bc -= 1;
						goto output;
					}
					if (nd<0){
						bc -= 1;
						nd += a_bc;
						goto output;
					}
				}
				if (ld==0){goto output;}
			}
			int i, count=0;
			int a[1000];
			a[0]=0;
			a[1]=1;
			for (i=2; i<20;i++){a[i] = a[i-1] + a[i-2];}
			for (i=0; i<20;i++){
				if( a[i]==dc && a[i]==dg){
					count=2;
					break;
				}
				if (a[i]==dc || a[i]==dg ){
					count+=1;
					if (i==1) i++;
				}
			}
			if (count==2){
				dc/=2;
				dg/=2;
				if (dc==0&&dg==0){temp = 0; goto output;}
				double a_bc = pow(dc,2) * sqrt(dc);
				double a_bg = (pow(dg,2) * PI)/3;
				if (dc==0){
					while (ld>0){
						bg += 1;
						nd  = nn - a_bg;
						nn -= a_bg;
						if (dc<5) ld-=1;
						else ld-=2;
						if (ld==-1){
							nd += a_bg;
							ld += 2;
							bg -= 1;
							goto output;
						}
						if (nd<0){
							bg -= 1;
							nd += a_bg;
							goto output;
						}
					}
					if(ld==0){goto output;}
				}
				if (dg==0){
					while (ld>0){
						bc +=1;
						nd  = nn - a_bc;
						nn -= a_bc;
						if (dc<8) ld-=1;
						else ld-=2;
						if (ld ==-1){
							nd +=a_bc;
							ld +=2;
							bc -=1;
							goto output;}
						
						if (nd<0){
							bc -=1;
							nd += a_bc;
							goto output;
						}
					}
					if(ld==0){ goto output;}
				}	
				if (a_bc > a_bg){
					goto bc_fibo;
					while (ld>0){
						if (nd<a_bc&&nd>a_bg) goto lam_bg_2;
						if (nd<a_bc&&nd<a_bg) goto output;
						bc_fibo:
						bc +=1;
						nd  = nn - a_bc;
						nn -= a_bc;
						if (dc<8) ld-=1;
						else ld-=2;
						if (ld==-1){
							nd += a_bc;
							ld += 2;
							bc -= 1;
							goto output;
						}
						if (nd<0){
							bc -= 1;
							nd += a_bc;
							nn += a_bc;
						}
						continue;
						
						lam_bg_2:
						bg +=1;
						nd  = nn - a_bg;
						nn -= a_bg;
						if (dg<5) ld-=1;
						else ld-=2;
						if (ld==-1){
							nd += a_bg;
							ld += 2;
							bg -= 1;
							goto output;
						}
						if (nd<0){
							bg -=1;
							nd += a_bg;
							nn += a_bg;
						}
						if (nd<a_bg) goto output;
					}
					if (ld==0){goto output;}
				}
				if ( a_bc < a_bg){
					goto lam_bg_truoc_F;
					while (ld>0){
						if (nd<a_bg&&nd>a_bc) goto lam_bc_2;
						if (nd<a_bg&&nd<a_bc) goto output;
						lam_bg_truoc_F:
						bg +=1;
						nd  = nn - a_bg;
						nn -= a_bg;
						if (dg<5) ld-=1;
						else ld-=2;
						if (ld==-1){
							nd += a_bg;
							ld += 2;
							bg -= 1;
							goto output;
						}
						if (nd<0){
							bg -= 1;
							nd += a_bg;
							nn += a_bg;
						}
						continue;
						
						lam_bc_2:
						bc +=1;
						nd  = nn - a_bc;
						nn -=a_bc;
						if (dc<8) ld-=1;
						else ld-=2;
						if (ld==-1){
							nd += a_bc;
							ld += 2;
							bc -= 1;
							goto output;
						}
						if (nd<0){
							bc -= 1;
							nd += a_bc;
							nn += a_bc;
						}
						if (nd<a_bc) goto output;
					}
					if (ld==0) {goto output;}
				}
			}
			else{
				dc*=2;
				dg*=2;
				double a_bc = pow(dc,2) * sqrt(dc);
				double a_bg = (pow(dg,2) * PI)/3;
				if (a_bc>a_bg){
					goto a_f;
					while (ld>0){
						if(nd<a_bc && nd>a_bg) goto lam_bg_4;
						if(nd<a_bc && nd<a_bg) goto output;
						a_f:
						bc += 1;
						nd  = nn - a_bc;
						nn -= a_bc;
						if (dc<8) ld-=1;
						else ld-=2;
						if (ld==-1){
							nd += a_bc;
							ld += 2;
							bc -= 1;
							goto output;
						}
						if (nd<0){
							bc -= 1;
							nd += a_bc;
							nn += a_bc;
							goto lam_bg_4;
						}
						continue;
						
						lam_bg_4:
						bg += 1;
						nd  = nn - a_bg;
						nn -= a_bg;
						if (dg<5) ld-=1;
						else ld-=2;
						if (ld==-1)
						{
							nd += a_bg;
							ld += 2;
							bc -= 1;
							goto output;
						}
						if (nd<0)
						{
							bg -= 1;
							nd += a_bg;
							nn += a_bg;
						}
						if (nd<a_bg) goto output;
					}
					if (ld==0){goto output;}
				}
				if (a_bc<a_bg){
					goto b_f;
					while (ld>0){
						if(nd<a_bg && nd>a_bc) goto lam_bc_4;
						if(nd<a_bg && nd<a_bc) goto output;
						b_f:
						bg += 1;
						nd  = nn - a_bg;
						nn -= a_bg;
						if (dg<5) ld-=1;
						else ld-=2;
						if (ld==-1){
							nd += a_bg;
							ld += 2;
							bg -= 1;
							goto output;
						}
						if (nd<0)
						{
							bg -= 1;
							nd += a_bg;
							nn += a_bg;
						}
						continue;
						lam_bc_4:
						bc += 1;
						nd  = nn - a_bc;
						nn -= a_bc;
						if (dc<8) ld-=1;
						else ld-=2;
						if (ld==-1){
							nd += a_bc;
							ld += 2;
							bc -= 1;
							goto output;
						}
						if (nd<0){
							bc -= 1;
							nd += a_bc;
							nn += a_bc;
						}
						if (nd<a_bc) goto output;
					}
					if(ld==0){goto output;}
				}
			}
		}
		if ((strcmp(w, "Rain"))==0){
			Rain:
			if (dc==0){
				while (ld>0){
					bg+=1;
					nd = nn - a_bg;
					nn-= a_bg;
					if(dg<5) ld-=1;
					else ld-=2;
					if (ld==-1){
						bg-=1;
						ld+=2;
						goto output;
					}
					if (nd<0){
						bg-=1;
						nd+=a_bg;
						goto output;
					}
				}
			}
			if (dg==0){
				while (ld>0){
					bc+=1;
					nd = nn - a_bc;
					nn-= a_bc;
					if(dc<8) ld-=1;
					else ld-=2;
					if (ld==-1){
						ld+=2;
						bc-=1;
						goto output;
					}
					if (nd<0){
						bc-=1;
						nd+=a_bc;
						goto output;
					}
				}
			}
			if (((dc>=8&&dg<5)&&(a_bc>2*a_bg))|| ((dc<8&&dg>=5) && (2*a_bc>a_bg)) || ((a_bc>a_bg) && (dc<8 && dg<5)) || ((a_bc>a_bg) && (dc>=8 && dg>=5))){
				goto bc_truoc;}
			else{goto bg_truoc;}
			while (ld>0){
				if (nd<a_bg && nd>a_bc) goto lam_bc;
				if (nd<a_bg && nd<a_bc) goto output;
				bg_truoc:
				bg+=1;
				nd = nn - a_bg;
				nn-= a_bg;
				if(dg<5) ld-=1;
				else ld-=2;
				if (ld==-1){
					nd+=a_bg;
					ld+=2;
					bg-=1;
					goto output;}
				if (nd<0){
					bg-=1;
					nd += a_bg;
					nn += a_bg;
				}
				lam_bc:
				bc+=1;
				nd = nn - a_bc;
				nn-= a_bc;
				if(dg<8) ld-=1;
				else ld-=2;
				if (ld==-1){
					nd+=a_bc;
					ld+=2;
					bc-=1;
					goto output;	
				}
				if (nd<0){
					bc-=1;
					nd += a_bg;
					nn += a_bg;
				}
				if (nd<a_bc) goto output;
			}
			while (ld>0){
				if (nd<a_bc && nd>a_bg) goto lam_bg;
				if (nd<a_bc && nd<a_bg) goto output;
				bc_truoc:
				bc+=1;
				nd = nn - a_bc;
				nn-= a_bc;
				if(dc<8) ld-=1;
				else ld-=2;
				if (ld==-1){
					nd+=a_bc;
					ld+=2;
					bc-=1;
					goto output;
				}
				if(ld==0) {goto output;}
				if (nd<0){
					bc-=1;
					nd+=a_bc;
					nn+=a_bc;
				}	
				lam_bg:
				bg+=1;
				nd = nn - a_bg;
				nn-= a_bg;
				if(dg<5) ld-=1;
				else ld-=2;
				if (ld==-1){
					nd+=a_bg;
					nn+=a_bg;
					ld+=2;
					bg-=1;
					if(dc<8 && nd>a_bc) goto bc_truoc;
					goto output;	
				}
				if (nd<0){
					bg-=1;
					nd += a_bg;
					nn += a_bg;
				}
				if (nd< a_bg) goto output;
			}
		}
		else{temp=0; goto output;}
		output:
		if (temp==0){ fprintf(f,"-1 -1 %d",n);goto skip;}
		fprintf(f,"%d %d %.3f",bc,bg,nd);
		skip:
		fclose(f);
		return 0;
}
