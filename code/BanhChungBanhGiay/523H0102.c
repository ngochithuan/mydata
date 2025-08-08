//By: Ngo Chi Thuan
//Student ID: 523H0102
//Started in Nov. 26


//Khai bao thu vien
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//Define
#define PI 3.1415926535

int main () {
	//Bien Input
	int n, dc, dg, ld;
	char w[100];
	//Bien
	double n_du, n_bc, n_bg, total_n_bc, total_n_bg;
	int so_bc, so_bg, i = 0, loop_avr, rainn;
	int result_bc =0, result_bg = 0;
	int ldc, ldg, loop_ldc, loop_ldg, total_ldc, total_ldg;
	int done = 0, sum_uoc_n = 0, sum_uoc_ld = 0;
	int f0 = 0, f1 = 1, af, dc_fibo, dg_fibo;   //Fibonacci
	int G, H, X, Mthod, intCovert;
	//double f_dc, f_dg;;
	//float fn, fdc, fdg, fld; //Check input 
		int False_Input = 0;
	char str1[100], str2[100], str3[100], str4[100];
	
	 
	int Sun_Arr[5][6] =
	{ 	{ 5,   7,   10,   12,   15,   20},
		{20,   5,    7,   10,   12,   15},
		{15,  20,    5,    7,   10,   12},	
		{12,  15,   20,    5,    7,   10},
		{10,  12,   15,   20,    5,    7},
	};
	
	//Bien Output
	int bc, bg;
	
	FILE *file_pointer;
	
	//Doc du lieu tu input.inp
	if ((file_pointer = fopen("input.inp","r")) == NULL)
	{
		printf("Error! opening file");
		//Chuong trinh se thoat neu file tra ve gia tri NULL
		exit(1);
	}
	
	//Nhap du lieu trong input thanh cac bien
	fscanf(file_pointer,"%s %s %s %s %s", str1, str2, str3, str4, w);
	//In cac gia tri
	//printf("Ta co: n=%s, dc=%s, dg=%s, ld=%s, w=%s", str1, str2, str3, str4, w);
//-----------------------------------------------------------------------------

//Xet Inputs

//Xu li chuoi Input

	for (i = 0; i < strlen(str1); i++)
	{
		if (!(((str1[i]) >= '0') && (str1[i] <= '9')))
		{
			if(str1[i] == '.' || str1[i] == ',')
			{
				False_Input++;
			}
			else
			{
				False_Input++;	
			}
		}
	}
	for (i = 0; i < strlen(str2); i++)
	{
		if (!(((str2[i]) >= '0') && (str2[i] <= '9')))
		{
			if(str2[i] == '.' || str2[i] == ',')
			{
				False_Input++;
			}
			else
			{
				False_Input++;	
			}
		}
	}
	for (i = 0; i < strlen(str3); i++)
	{
		if (!(((str3[i]) >= '0') && (str3[i] <= '9')))
		{
			if(str3[i] == '.' || str3[i] == ',')
			{
				False_Input++;
			}
			else
			{
				False_Input++;	
			}
		}
	}
	for (i = 0; i < strlen(str1); i++)
	{
		if (!(((str4[i]) >= '0') && (str4[i] <= '9')))
		{
			if(str4[i] == '.' || str4[i] == ',')
			{
				False_Input++;
			}
			else
			{
				False_Input++;	
			}
		}
	}
	
	//printf("%d", False_Input);
	if (False_Input > 2)
	{
		file_pointer = fopen("output.out","w");
		fprintf(file_pointer,"-1 -1 %s", str1);
		
		fclose(file_pointer);
		return 5230102;
	}
	else
	{
		//Convert thanh so int     //atoi: string to int
		n = atoi(str1);
		dc = atoi(str2);
		dg = atoi(str3);
		ld = atoi(str4);
	}
	
//Chech converted inputs	
//printf("\nTa co: n=%d, dc=%d, dg=%d, ld=%d, w=%s", n, dc, dg, ld, w);

if((n < 1) || (n > 2000) || ((dg == 0) && (dc == 0)) || (ld < 1) || (ld > 600))
{
	file_pointer = fopen("output.out","w");
	fprintf(file_pointer,"-1 -1 %s", str1);
	
	fclose(file_pointer);
	return 5230102;	
}
else
{

//Tinh so la dong can cho moi loai banh
if (dc < 8)
{
	ldc = 1;
}
else
{
	ldc = 2;
}

if (dg < 5)
{
	ldg = 1;
}
else
{
	ldg = 2;
}
n_du = n;


//WIND
if ((strcmp(w, "Wind")) == 0) 
{
	if (dc > 0)
	{
		n_bc = pow(dc, 2)*sqrt(dc);
		so_bc = n_du / n_bc;
		total_ldc = ldc * so_bc;

	}
	else
	{
		so_bc = 0;
	}
	
	
	if (dg > 0)
	{
		n_bg = (pow(dg, 2)*PI)/3;
		so_bg = n_du / n_bg;
		total_ldg = ldg * so_bg;

	}
	else
	{
		so_bg = 0;
	}
	
	
	if (total_ldc > ld)
	{
		loop_ldc = ld / ldc;
		loop_ldg = loop_ldc;
		//printf("\n%d", total_ldc);       //Check
		//printf("\n0");
		
	}
	if (total_ldc <= ld)
	{
		loop_ldg = ld / ldg;
		loop_ldc = loop_ldg;
	}

	if ((dc < dg) && /* tested*/ ((total_ldc) > ld))
	{

	while (done != 2)
	{
		for(i = 1; i <= so_bg && i <= loop_ldg; i++)
		{
			if ((ld - ldg >= 0) && (n_du - n_bg >= 0))
			{
				n_du = n_du - n_bg;
				ld = ld - ldg;
				result_bg++;
				loop_ldc = loop_ldc - 1;
			}
		}
		done++;
		//printf("\n%lf", n_du);

		
		for(i = 1; i <= so_bc && i <= loop_ldc;i++)
		{
			if ((ld - ldc >= 0) && (n_du - n_bc >= 0))
			{
				n_du = n_du - n_bc;
				ld = ld - ldc;
				result_bc++;
			}
		}
		done++;
	}
	//Print result
	//printf("\n%d %d %.3lf", result_bc, result_bg, n_du);
	}
	
	else
	{
	
	while (done != 2)
	{
		for(i = 1; i <= so_bc && i <= loop_ldc; i++)
		{
			if ((ld - ldc >= 0) && (n_du - n_bc >= 0))
			{
				n_du = n_du - n_bc;
				ld = ld - ldc;
				result_bc++;
				loop_ldg = loop_ldg - 1;
			}
		}
		done++;
	//printf("\n%lf", n_du);

		
		for(i = 1; i <= so_bg && i <= loop_ldg; i++)
		{
			if ((ld - ldg >= 0) && (n_du - n_bg >= 0))
			{
				n_du = n_du - n_bg;
				ld = ld - ldg;
				result_bg++;
			}
		}
		done++;
	}
	//Print result
	//printf("\n%d %d %.3lf", result_bc, result_bg, n_du);
	}	
	}
	


//RAIN
else if ((strcmp(w, "Rain")) == 0)
{
	if (dc > 0)
	{
		n_bc = pow(dc, 2)*sqrt(dc);
		so_bc = n_du / n_bc;
	}
	else
	{
		so_bc = 0;
	}
	
	
	if (dg > 0)
	{
		n_bg = (pow(dg, 2)*PI)/3;
		so_bg = n_du / n_bg;
	}
	else
	{
		so_bg =0;
	}
	loop_avr = (so_bc + so_bg)/2;
	
	for(i = 1; i <= loop_avr; i = i + 1)
	{
		if ((ld - (ldc + ldg) >= 0) && (n_du - (n_bc + n_bg) >= 0))
		{
			n_du = n_du - (n_bc + n_bg);
			ld = ld - (ldc + ldg);
			result_bc++;
			result_bg++;
			
		}

	}

	if (so_bg < so_bc)
	{
		rainn = 1;
	}
	else
	{
		rainn = 0;
	}
	
	if (rainn == 1)
	{
		while ((n_du - n_bg >= 0) && (ld - ldg >= 0))
		{
			n_du = n_du - n_bg;
			ld = ld - ldg;
			result_bg++;
		}
		while ((n_du - n_bc >= 0) && (ld - ldc >= 0))
		{
			n_du = n_du - n_bc;
			ld = ld - ldc;
			result_bc++;
		}

	}
	if (rainn == 0)
	{
		
		while ((n_du - n_bc >= 0) && (ld - ldc >= 0))
		{
			n_du = n_du - n_bc;
			ld = ld - ldc;
			result_bc++;	
		}
		while ((n_du - n_bg >= 0) && (ld - ldg >= 0))
		{
			n_du = n_du - n_bg;
			ld = ld - ldg;
			result_bg++;
		}
	}

	//Print result
	//printf("\n%d %d %.3lf", result_bc, result_bg, n_du);
	

}

//CLOUD
else if ((strcmp(w, "Cloud")) == 0)
{
//So ban be
	for(i = 1;i < n_du;i++)
	{
		if (n % i == 0)
		{
			sum_uoc_n = sum_uoc_n + i;
		}
	}
	for(i = 1;i < ld;i++)
	{
		if (ld % i == 0)
		{
			sum_uoc_ld = sum_uoc_ld + i;
		}
	}
	
	if ((n_du == sum_uoc_ld) && (ld == sum_uoc_n)) //Neu so nep va so la dong la cap so ban be
	{
		result_bc = 0;
		result_bg = 0;
	}
	if ((n != sum_uoc_ld) || (ld != sum_uoc_n))//Nguoc lai voi Wind//
	{
		if (dc > 0)
	{
		n_bc = pow(dc, 2)*sqrt(dc);
		so_bc = n_du / n_bc;
		total_ldc = ldc * n_bc;

	}
	else
	{
		so_bc = 0;
	}
	
	
	if (dg > 0)
	{
		n_bg = (pow(dg, 2)*PI)/3;
		so_bg = n_du / n_bg;
		total_ldg = ldg * n_bg;

	}
	else
	{
		so_bg = 0;
	}
	
	
	if (total_ldc > ld)
	{
		loop_ldc = ld / ldc;
		loop_ldg = loop_ldc;
	
		
	}
	if (total_ldc <= ld)
	{
		loop_ldg = ld / ldg;
		loop_ldc = loop_ldg;
	}
		
	while (done != 2)
	{
		for(i = 1; i <= so_bg && i <= loop_ldg; i++)
		{
			if ((ld - ldg >= 0) && (n_du - n_bg >= 0))
			{
				n_du = n_du - n_bg;
				ld = ld - ldg;
				result_bg++;
				loop_ldc = loop_ldc - 1;
			}
		}
		done++;

		//Check
		if ((i >= loop_ldg) && (n_du - n_bc >= 0) && (ld - ldc >= 0))
		{
			loop_ldc++;
		}
		
		for(i = 1; i <= so_bc && i <= loop_ldc; i++)
		{
			if ((ld - ldc >= 0) && (n_du - n_bc >= 0))
			{
				n_du = n_du - n_bc;
				ld = ld - ldc;
				result_bc++;
			}
		}
		done++;
	}
	//Print result
	//printf("\n%d %d %.3lf", result_bc, result_bg, n_du);
	
	}
}

//FOG
/*
Fibonacci -> decrease dc, dg by 50%
Not Fibonacci -> increase dc, dg by 50%
*/


else if ((strcmp(w, "Fog")) == 0)
{

if (dc == f0 || dc == f1)
{
	dc_fibo = 1;    //dc_fibo = 1 -> Fibonacci
}                   //        = 0 -> not Fibonacci
else
{
	af = f0 + f1;
	while (af < dc)
	{
		f0 = f1;
		f1 = af;
		af = f0 + f1;
	}
	if (af == dc)
	{
		dc_fibo = 1;
	}
	else
	{
		dc_fibo = 0;
	}
}

f0 = 0;
f1 = 1;

if (dg == f0 || dg == f1)
{
	dg_fibo = 1;    //dg_fibo = 1 -> Fibonacci
}                   //        = 0 -> not Fibonacci
else
{
	af = f0 + f1;
	while (af < dg)
	{
		f0 = f1;
		f1 = af;
		af = f0 + f1;
	}
	if (af == dg)
	{
		dg_fibo = 1;
	}
	else
	{
		dg_fibo = 0;
	}
}

/////  If both are fibonacci  /////
if ((dc_fibo == 1) && (dg_fibo == 1))
{
	dc = dc / 2;
	dg = dg / 2;

}
else //  If not
{
	dc = dc * 2;
	dg = dg * 2;

}


if (dc == 0 && dc == 0)
{
	file_pointer = fopen("output.out","w");
	fprintf(file_pointer,"-1 -1 %s", str1);
	
	fclose(file_pointer);
	return 5230102;
}

if  (((pow(dg, 2)*PI)/3) > (pow(dc, 2)*sqrt(dc)))
{
	if (dg > 0)
	{
		n_bg = (pow(dg, 2)*PI)/3;
		so_bg = n_du / n_bg;
		total_ldg = ldg * so_bg;



	}
	else
	{
		so_bg = 0;
		total_ldg = ldg * so_bg;
	}
	

	
	if (dc > 0)
	{
		n_bc = pow(dc, 2)*sqrt(dc);
		so_bc = n_du - (so_bg * n_bg) / n_bc;
		total_ldc = ldc * so_bc;

	}
	else
	{
		so_bc = 0;
		total_ldc = ldc * so_bc;
	}
}	
else
{
	if (dc > 0)
	{
		n_bc = pow(dc, 2)*sqrt(dc);
		so_bc = n_du / n_bc;
		total_ldc = ldc * so_bc;
	}
	else
	{
		so_bc = 0;
		total_ldc = ldc * so_bc;
	}
	if (dg > 0)
	{
		n_bg = (pow(dg, 2)*PI)/3;
		so_bg = (n_du - (so_bc*n_bc))/ n_bg;
		total_ldg = ldg * so_bg;

	}
	else
	{
		so_bg = 0;
		total_ldg = ldg * so_bg;
	}
}
	

if (so_bc == 0 && so_bg == 0)
{
	file_pointer = fopen("output.out","w");
	fprintf(file_pointer,"-1 -1 %s", str1);
	
	fclose(file_pointer);
	return 5230102;
}	


//// CHECK LAN 2 SO LD CAN CHO MOI LOAI BANH ////
if (dc < 8)
{
	ldc = 1;
}
else
{
	ldc = 2;
}

if (dg < 5)
{
	ldg = 1;
}
else
{
	ldg = 2;
}

	//Check so banh sau khi d
	
	/*
	printf("\n%d", so_bc);
	printf("\n%d", so_bg);
	*/
	if (n_bg <= n_bc)
	{
		loop_ldc = ld / ldc;
		loop_ldg = loop_ldc;
		
	}
	if (n_bg > n_bc)
	{
		loop_ldg = ld / ldg;
		loop_ldc = loop_ldg;
	
	}


while (done != 2)
{
	if (n_bg >= n_bc)
	{
		for(i = 1; i <= so_bg && i <= loop_ldg; i++)
		{
			if ((ld - ldg >= 0) && (n_du - n_bg >= 0))
			{
				n_du = n_du - n_bg;
				ld = ld - ldg;
				result_bg++;
				loop_ldc = loop_ldc - 1;
			}
		}
		done++;
		
		for(i = 1; i <= so_bc && i <= loop_ldc;i++)
		{
			if ((ld - ldc >= 0) && (n_du - n_bc >= 0))
			{
				n_du = n_du - n_bc;
				ld = ld - ldc;
				result_bc++;
			}
		}
	}
	else
	{
		while (done != 2)
		{
			for(i = 1; i <= so_bc && i <= loop_ldc; i++)
			{
				if ((ld - ldc >= 0) && (n_du - n_bc >= 0))
				{
					n_du = n_du - n_bc;
					ld = ld - ldc;
					result_bc++;
					loop_ldg = loop_ldg - 1;
				}
			}
			done++;
			
			for(i = 1; i <= so_bg && i <= loop_ldg; i++)
			{
				if ((ld - ldg >= 0) && (n_du - n_bg >= 0))
				{
					n_du = n_du - n_bg;
					ld = ld - ldg;
					result_bg++;
				}
			}
			done++;
	}
	
	}	
	
	}
}


//SUN
else if ((strcmp(w, "Sun")) == 0)
{
	G = dc % 6;
	H = ld % 5;
	X = Sun_Arr[H][G];

	n = n + (n * X /100);
	ld = ld - X;

if (n <= 0 || ld <= 0)
{
	file_pointer = fopen("output.out","w");
	fprintf(file_pointer,"-1 -1 %d", n);
	
	fclose(file_pointer);
	return 5230102;
}
	n_du = n;	
	Mthod = ((dc + dg) % 3);
	if (Mthod == 0)
	{
		if (dc > 0)
	{
		n_bc = pow(dc, 2)*sqrt(dc);
		so_bc = n_du / n_bc;
	}
	else
	{
		so_bc = 0;
	}
	
	
	if (dg > 0)
	{
		n_bg = (pow(dg, 2)*PI)/3;
		so_bg = n_du / n_bg;
	}
	else
	{
		so_bg =0;
	}
	loop_avr = (so_bc + so_bg)/2;
	
	for(i = 1; i <= loop_avr; i = i + 1)
	{
		if ((ld - (ldc + ldg) >= 0) && (n_du - (n_bc + n_bg) >= 0))
		{
			n_du = n_du - (n_bc + n_bg);
			ld = ld - (ldc + ldg);
			result_bc++;
			result_bg++;
			
		}

	}

	if (n_bg >= n_bc)  
	{
		rainn = 1;
	}
	else
	{
		rainn = 0;
	}
	
	if (rainn == 1)
	{
		while ((n_du - n_bg >= 0) && (ld - ldg >= 0))
		{
			n_du = n_du - n_bg;
			ld = ld - ldg;
			result_bg++;
		}
		while ((n_du - n_bc >= 0) && (ld - ldc >= 0))
		{
			n_du = n_du - n_bc;
			ld = ld - ldc;
			result_bc++;
		}

	}
	if (rainn == 0)
	{
		
		while ((n_du - n_bc >= 0) && (ld - ldc >= 0))
		{
			n_du = n_du - n_bc;
			ld = ld - ldc;
			result_bc++;	
		}
		while ((n_du - n_bg >= 0) && (ld - ldg >= 0))
		{
			n_du = n_du - n_bg;
			ld = ld - ldg;
			result_bg++;
		}
	}
	}
	if (Mthod == 1)
	{
	if (dc > 0)
	{
		n_bc = pow(dc, 2)*sqrt(dc);
		so_bc = n_du / n_bc;
		total_ldc = ldc * so_bc;

	}
	else
	{
		so_bc = 0;
	}
	
	
	if (dg > 0)
	{
		n_bg = (pow(dg, 2)*PI)/3;
		so_bg = n_du / n_bg;
		total_ldg = ldg * so_bg;

	}
	else
	{
		so_bg = 0;
	}
	
	
	if (total_ldc > ld)
	{
		loop_ldc = ld / ldc;
		loop_ldg = loop_ldc;

		
	}
	if (total_ldc <= ld)
	{
		loop_ldg = ld / ldg;
		loop_ldc = loop_ldg;

	}

	if ((dc < dg) && (total_ldc > ld))
	{

	while (done != 2)
	{
		for(i = 1; i <= so_bg && i <= loop_ldg; i++)
		{
			if ((ld - ldg >= 0) && (n_du - n_bg >= 0))
			{
				n_du = n_du - n_bg;
				ld = ld - ldg;
				result_bg++;
				loop_ldc = loop_ldc - 1;
			}
		}
		done++;
		//printf("\n%lf", n_du);

		
		for(i = 1; i <= so_bc && i <= loop_ldc;i++)
		{
			if ((ld - ldc >= 0) && (n_du - n_bc >= 0))
			{
				n_du = n_du - n_bc;
				ld = ld - ldc;
				result_bc++;
			}
		}
		done++;
	}
	//printf("\n%d %d %.3lf", result_bc, result_bg, n_du);
	}
	
	else
	{
	
	while (done != 2)
	{
		for(i = 1; i <= so_bc && i <= loop_ldc; i++)
		{
			if ((ld - ldc >= 0) && (n_du - n_bc >= 0))
			{
				n_du = n_du - n_bc;
				ld = ld - ldc;
				result_bc++;
				loop_ldg = loop_ldg - 1;
			}
		}
		done++;
	//printf("\n%lf", n_du);

		
		for(i = 1; i <= so_bg && i <= loop_ldg; i++)
		{
			if ((ld - ldg >= 0) && (n_du - n_bg >= 0))
			{
				n_du = n_du - n_bg;
				ld = ld - ldg;
				result_bg++;
			}
		}
		done++;
	}
	//printf("\n%d %d %.3lf", result_bc, result_bg, n_du);
	}			
	}
	if (Mthod == 2)
	{
	if (dc > 0)
	{
		n_bc = pow(dc, 2)*sqrt(dc);
		so_bc = n_du / n_bc;
		total_ldc = ldc * n_bc;

	}
	else
	{
		so_bc = 0;
	}
	
	
	if (dg > 0)
	{
		n_bg = (pow(dg, 2)*PI)/3;
		so_bg = n_du / n_bg;
		total_ldg = ldg * n_bg;

	}
	else
	{
		so_bg = 0;
	}	
	if (so_bc < so_bg)
	{
		loop_ldc = ld / ldc;
		loop_ldg = loop_ldc;
		
	}
	if (so_bc >= so_bg)
	{
		loop_ldg = ld / ldg;
		loop_ldc = loop_ldg;

	}


	if ((so_bc >= so_bg) && (total_ldg <= ld))
	{

	while (done != 2)
	{
		for(i = 1; i <= so_bg && i <= loop_ldg; i++)
		{
			if ((ld - ldg >= 0) && (n_du - n_bg >= 0))
			{
				n_du = n_du - n_bg;
				ld = ld - ldg;
				result_bg++;
				loop_ldc = loop_ldc - 1;
			}
		}
		done++;

		
		for(i = 1; i <= so_bc && i <= loop_ldc;i++)
		{
			if ((ld - ldc >= 0) && (n_du - n_bc >= 0))
			{
				n_du = n_du - n_bc;
				ld = ld - ldc;
				result_bc++;
			}
		}
		done++;
	}
	//printf("\n%d %d %.3lf", result_bc, result_bg, n_du);
	}
	if ((so_bc < so_bg) && (total_ldc <= ld))
	{

	while (done != 2)
	{
		for(i = 1; i <= so_bc && i <= loop_ldc;i++)
		{
			if ((ld - ldc >= 0) && (n_du - n_bc >= 0))
			{
				n_du = n_du - n_bc;
				ld = ld - ldc;
				result_bc++;
			}
		}
		done++;

		for(i = 1; i <= so_bg && i <= loop_ldg; i++)
		{
			if ((ld - ldg >= 0) && (n_du - n_bg >= 0))
			{
				n_du = n_du - n_bg;
				ld = ld - ldg;
				result_bg++;
				loop_ldc = loop_ldc - 1;
			}
		}
		
		done++;
	}
	//printf("\n%d %d %.3lf", result_bc, result_bg, n_du);
	}
	}
}

else
{

	file_pointer = fopen("output.out","w");
	fprintf(file_pointer,"-1 -1 %s", str1);
	fclose(file_pointer);
	return 5230102;
}

//-----------------------------------------------------------------------------
//Chuyen ket qua tu chuong trinh thanh file output.out
	file_pointer = fopen("output.out","w");
	
   	if(file_pointer == NULL)
   	{
      	printf("Error!");
      	exit(1);
   	}
   	//Chuyen cac gia tri vao file
	fprintf(file_pointer,"%d %d %.3lf", result_bc, result_bg, n_du);
	fclose(file_pointer);
	return 5230102;
	
}

	return 5230102;
}

