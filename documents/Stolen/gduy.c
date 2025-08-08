#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI 3.1415926535
int main()
{
	char w[20];
	int H=0,G=0,z=0;
	int cf,qw;
 	int n=0,dc=0,dg=0,ld=0,bc=0,bg=0,sbc=0,sbg=0,tsldbc=0,tsldbg=0,sbccheck=0,i,sldbgcheck=0,tsldbg1 =0,sbgcheck=0;;
	int sldbccheck=0,tsldbc1=0,sldbc=0,sldbg=0,ldsau=0,bcend=0,bgend=0,tsld1cap=0,capbanhtheonep=0,capldtheold=0,ldconlai=0;;
 	float ctbc=0,ctbg=0,nd=0,nep1capbanh=0,neptheocap1=0,nepsau=0,mid=0; 
    int a = 0, b = 1,temp;
    
    FILE *fptr;

	//read input.inp file
	if ((fptr = fopen("input.inp","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
	}

	//Assign values to variable from file
	fscanf(fptr,"%d %d %d %d %s",&n,&dc,&dg,&ld,&w);


    int isNum1Fibonacci = 0,isNum2Fibonacci = 0,sum_a = 1, sum_b = 1;
    
    if (n > 2000 || n < 0 || (dg == 0 && dc == 0) || ld < 0 || ld > 600)
    {
    	fptr = fopen("output.out", "w");
		//write values to file
		fprintf(fptr,"-1 -1 %d", n);
								
		fclose(fptr); 
								  
		return 0;

    
	}
    else
    {

    //Winddddddddddddddddddddddddddddd
    if((strcmp(w,"Wind")) == 0 )
    {
    	if((n > 0 && n <= 2000 && dc >= 0 && dg>0 &&ld >= 1 && ld <= 600) || ( dg >= 0 && dc>0 && n > 0 && n <= 2000 && ld >= 1 && ld <= 600))
		{
	    	ctbc = pow(dc, 2.5);
			ctbg = (pow(dg, 2) * PI) / 3;
			sbccheck = n / ctbc;
			
    		if (dc < 8) {
        		sldbccheck = 1;
    		}else if (dc >=8) {
        		sldbccheck = 2;}
			tsldbc1 = sbccheck * sldbccheck;
			if(ctbg>ctbc && tsldbc1 > ld){
				
				sbg = n / ctbg;
				if (dg < 5) {
            		sldbg = 1;
        		}else if( dg >=5) {
            		sldbg = 2;}
        		tsldbg = sbg * sldbg;
        		if (tsldbg <= ld && dg < 5) {
            		bg = tsldbg;
            		ldsau = ld - tsldbg;
        		}else if (tsldbg <= ld && dg >= 5){
            		bg = tsldbg / 2;
            		ldsau = ld - tsldbg;
        		}else if (tsldbg > ld && dg < 5){
            		bg = ld;
            		ldsau = ld - ld;
        		}else if (tsldbg > ld && dg >= 5){
        			bg = ld/2;
            		ldsau = ld - ( bg * 2 );}       
        		if(ctbc > 0){
					sbc= ((n - (bg * ctbg)) / (ctbc));	
				}else{
					sbc= 0;}
        		if (dc < 8) {
            		sldbc = 1;
        		}else if( dc >=8) {
            		sldbc = 2;}
            
        		tsldbc = sbc * sldbc;  
        		if (tsldbc <= ldsau && dc < 8){
            		bc = tsldbc;
        		}else if (tsldbc <= ldsau && dc >= 8){
					bc = tsldbc / 2;
        		}else if (tsldbc > ldsau && dc< 8){
            		bc = ldsau;
        		}else if (tsldbc > ldsau && dc>= 8){
            		bc = ldsau/2;}	
							 
			}
			else if( dc == 0 ){
				
				bc=0;
				sbg = n / ctbg;
				if (dg < 5) {
            		sldbg = 1;
        		}else if( dg >=5) {
            		sldbg = 2;}
        		tsldbg = sbg * sldbg;
        
				if(tsldbg<=ld && dg < 5){
					bg = tsldbg; 
				}else if(tsldbg<=ld && dg >= 5){
					bg = tsldbg/2;
				}else if(tsldbg>ld && dg < 5){
					bg = ld;
				}else if(tsldbg>ld && dg >= 5){
					bg = ld/2;}
					
			}
			else if( dg == 0 ){
				bg=0;
				sbc = n / ctbc;
				if (dc < 8) {
            	sldbc = 1;
        		}else if( dc >=8) {
            	sldbc = 2;}
        		tsldbc = sbc * sldbc;
        
				if(tsldbc<=ld && dc < 8){
					bc = tsldbc; 
				}else if(tsldbc<=ld && dc >= 8){
					bc = tsldbc/2;
				}else if(tsldbc>ld && dc < 8){
					bc = tsldbc;
				}else if(tsldbc>ld && dc >= 8){
					bc = tsldbc/2;}
					  
				}	
			else{
        		sbc = n / ctbc;
        		if (dc < 8) {
            		sldbc = 1;
        		}else if (dc >=8) {
            		sldbc = 2;}

        		tsldbc = sbc * sldbc;

        		if (tsldbc <= ld && dc < 8) {
            		bc = tsldbc;
            		ldsau = ld - tsldbc;
        		}else if (tsldbc <= ld && dc >= 8) {
            		bc = tsldbc / 2;
            		ldsau = ld - tsldbc;
        		} else if (tsldbc > ld && dc < 8) {
            		bc = ld;
        		} else if (tsldbc > ld && dc >= 8) {
            		bc = ld/2;
            		ldsau = ld- ( bc * 2 );}
        		if(ctbg > 0){
					sbg= ((n - (bc * ctbc)) / (ctbg));
				}else{
					sbg= 0;}							
        		if (dg < 5) {
            		sldbg = 1;
        		}else if( dg >=5) {
            		sldbg = 2;}
        		tsldbg = sbg * sldbg;  
        		if (tsldbg <= ldsau && dg < 5) {
            		bg = tsldbg;
        		}else if (tsldbg <= ldsau && dg >= 5) {
            		bg = tsldbg / 2;
        		} else if (tsldbg > ldsau && dg < 5) {
            		bg = ldsau;
        		} else if (tsldbg > ldsau && dg >= 5) {
            		bg = ldsau/2;}       
			}
		nd = n - (bc*ctbc+bg*ctbg);
		fptr = fopen("output.out", "w");
		//write values to file
		fprintf(fptr,"%d %d %.3f",bc,bg,nd);
									
		fclose(fptr); 
								  
		return 0;

		}
		else
		{
			fptr = fopen("output.out", "w");
			//write values to file
			fprintf(fptr,"-1 -1 %d",n);
									
			fclose(fptr); 
								  
			return 0;

		}}///////////////////////////////////////////////////////////////////
	//Rainnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
	else if((strcmp(w,"Rain")) == 0 )
    {
    	if(n > 0 && n <= 2000 && dc > 0 && dg > 0 &&ld >= 1 && ld <= 600)
    	{
	    	ctbc = pow(dc, 2.5);
			ctbg = (pow(dg, 2) * PI) / 3;
	    	if (dc < 8) {
	    		sldbc = 1;
	    	}else if (dc >=8) {
	    		sldbc = 2;}
	   		if (dg < 5) {
	    		sldbg = 1;
	    	}else if( dg >=5) {
	    		sldbg = 2;}
		    nep1capbanh = ctbc + ctbg;
		    tsld1cap = sldbc + sldbg;
			capbanhtheonep = n / nep1capbanh;
			capldtheold = ld / tsld1cap;
			if(capbanhtheonep <= capldtheold){
				neptheocap1 = (capbanhtheonep * nep1capbanh );
				nepsau = n - neptheocap1;
				ldconlai = ld - (capbanhtheonep*tsld1cap);
				if (ctbc>ctbg) {
		            sbc = nepsau / ctbc;
		            if (dc < 8) {
		                sldbc = 1;
		            }else if (dc >=8) {
		                sldbc = 2;}
		            tsldbc = sbc * sldbc;
		            if (tsldbc <= ldconlai && dc < 8) {
		                bc = tsldbc;
		                ldsau = ldconlai - tsldbc;
		            } else if (tsldbc <= ldconlai && dc >= 8) {
		                bc = tsldbc / 2;
		                ldsau = ldconlai - tsldbc;
		            } else if (tsldbc > ldconlai && dc < 8) {
		                bc = ldconlai;
		            } else if (tsldbc > ldconlai && dc >= 8) {
		                bc = ldconlai/2;
		                ldsau = ldconlai- ( bc * 2 );}
		            if(ctbg > 0){
						sbg= ((nepsau - (bc * ctbc)) / (ctbg));
					}else{
						sbg= 0;}
		            if (dg < 5) {
		                sldbg = 1;
		            }else if( dg >=5){
		                sldbg = 2;}
		            tsldbg = sbg * sldbg;
		            if (tsldbg <= ldsau && dg < 5) {
		                bg = tsldbg;
		            } else if (tsldbg <= ldsau && dg >= 5) {
		                bg = tsldbg / 2;
		            } else if (tsldbg > ldsau && dg < 5) {
		                bg = ldsau;
		            } else if (tsldbg > ldsau && dg >= 5) {
		                bg = ldsau/2;}            
				}
				else if (ctbc<ctbg) {
					sbg = nepsau / ctbg;
					if (dg < 5) {
		                sldbg = 1;
		            }else if( dg >=5) {
		                sldbg = 2;}
		        	tsldbg = sbg * sldbg;
		            if (tsldbg <= ldconlai && dg < 5) {
		                bg = tsldbg;
		                ldsau = ldconlai - tsldbg;
		            } else if (tsldbg <= ldconlai && dg >= 5) {
		                bg = tsldbg / 2;
		                ldsau = ldconlai - tsldbg;
		            } else if (tsldbg > ldconlai && dg < 5){
		                bg = ldconlai;
		                ldsau = ldconlai - ldconlai;
		            } else if (tsldbg > ldconlai && dg >= 5) {
		                bg = ldconlai/2;
		                ldsau = ldconlai - ( bg * 2 );} 
		            if(ctbc > 0){
						sbc= ((nepsau - (bg * ctbg)) / (ctbc));	
					}else{
						sbc= 0;}
		            if (dc < 8) {
		                sldbc = 1;
		            }else if( dc >=8) {
		                sldbc = 2;}            
		            tsldbc = sbc * sldbc;
		            if (tsldbc <= ldsau && dc < 8) {
		                bc = tsldbc;
		            } else if (tsldbc <= ldsau && dc >= 8) {
		                bc = tsldbc / 2;
		            } else if (tsldbc > ldsau && dc< 8) {
		                bc = ldsau;
		            } else if (tsldbc > ldsau && dc>= 8) {
		                bc = ldsau/2;}			                    
				}
					bcend = bc + capbanhtheonep;
					bgend = bg + capbanhtheonep;
					nd = n - (bcend* ctbc + bgend*ctbg);
					fptr = fopen("output.out", "w");
				   	//write values to file
					fprintf(fptr,"%d %d %.3f",bcend,bgend,nd);
									
					fclose(fptr); 
								  
					return 0;

			}
			else if (capbanhtheonep > capldtheold){
				neptheocap1 = (capldtheold * nep1capbanh );
				nepsau = n - neptheocap1;
				ldconlai = ld - (capldtheold*tsld1cap);
				if (ctbc>ctbg) {
		            sbc = nepsau / ctbc;
		            if (dc < 8) {
		                sldbc = 1;
		            }else if (dc >=8){
		                sldbc = 2;}
		            tsldbc = sbc * sldbc;
		            if (tsldbc <= ldconlai && dc < 8) {
		                bc = tsldbc;
		                ldsau = ldconlai - tsldbc;
		            } else if (tsldbc <= ldconlai && dc >= 8) {
		                bc = tsldbc / 2;
		                ldsau = ldconlai - tsldbc;
		            } else if (tsldbc > ldconlai && dc < 8) {
		                bc = ldconlai;
		            } else if (tsldbc > ldconlai && dc >= 8) {
		                bc = ldconlai/2;
		                ldsau = ldconlai- ( bc * 2 );}
		            if(ctbg > 0){
						sbg= ((nepsau - (bc * ctbc)) / (ctbg));
					}else{
						sbg= 0;}							
		            if (dg < 5) {
		                sldbg = 1;
		            }else if( dg >=5) {
		                sldbg = 2;}
		            tsldbg = sbg * sldbg;
		            if (tsldbg <= ldsau && dg < 5) {
		                bg = tsldbg;
		            } else if (tsldbg <= ldsau && dg >= 5) {
		                bg = tsldbg / 2;
		            } else if (tsldbg > ldsau && dg < 5) {
		                bg = ldsau;
		            } else if (tsldbg > ldsau && dg >= 5) {
		                bg = ldsau/2;}            
				}
				else if (ctbc<ctbg) {
					sbg = nepsau / ctbg;
					if (dg < 5) {
		                sldbg = 1;
		            }else if( dg >=5) {
		                sldbg = 2;}
		        	tsldbg = sbg * sldbg;
		            if (tsldbg <= ldconlai && dg < 5) {
		                bg = tsldbg;
		                ldsau = ldconlai - tsldbg;
		            } else if (tsldbg <= ldconlai && dg >= 5) {
		                bg = tsldbg / 2;
		                ldsau = ldconlai - tsldbg;
		            } else if (tsldbg > ldconlai && dg < 5){
		                bg = ldconlai;
		                ldsau = ldconlai - bg;
		            } else if (tsldbg > ldconlai && dg >= 5) {
		                bg = ldconlai/2;
		                ldsau = ldconlai - ( bg * 2 );} 
		            if(ctbc > 0){
						sbc= ((nepsau - (bg * ctbg)) / (ctbc));	
					}else{
						sbc= 0;}
		            if (dc < 8) {
		                sldbc = 1;
		            }else if( dc >=8) {
		                sldbc = 2;}
		            tsldbc = sbc * sldbc;
		            if (tsldbc <= ldsau && dc < 8) {
		                bc = tsldbc;
		            } else if (tsldbc <= ldsau && dc >= 8) {
		                bc = tsldbc / 2;
		            } else if (tsldbc > ldsau && dc< 8) {
		                bc = ldsau;
		            } else if (tsldbc > ldsau && dc>= 8) {
		                bc = ldsau/2;}			                    		
				}
					bcend = bc + capldtheold;
					bgend = bg + capldtheold;
					nd = n - bcend*ctbc + bgend*ctbg;
					fptr = fopen("output.out", "w");
				   	//write values to file
					fprintf(fptr,"%d %d %.3f",bcend,bgend,nd);
									
					fclose(fptr); 
								  
					return 0;

			}
		}else if (n > 0 && n <= 2000 && dc == 0 && dg>0 &&ld >= 1 && ld <= 600)
		{
	    	ctbc = pow(dc, 2.5);
			ctbg = (pow(dg, 2) * PI) / 3;
			bc = 0 ;
			sbg = n / ctbg;
            if (dg < 5) {
                sldbg = 1;
            }else if( dg >=5) {
                sldbg = 2;}
            tsldbg = sbg * sldbg;
            
			if(tsldbg<=ld && dg < 5)
			{
				bg = tsldbg; 
			}else if(tsldbg<=ld && dg >= 5)
			{
				bg = tsldbg/2;
			}else if(tsldbg>ld && dg < 5)
			{
				bg = ld;
			}else if(tsldbg>ld&& dg >= 5)
			{
				bg =ld/2;
			}		
					nd = n - bg* ctbg;	
					fptr = fopen("output.out", "w");
				   	//write values to file
					fprintf(fptr,"%d %d %.3f",bc,bg,nd);
									
					fclose(fptr); 
								  
					return 0;

		}else if (n > 0 && n <= 2000 && dg == 0 && dc>0 &&ld >= 1 && ld <= 600)
		{
			ctbc = pow(dc, 2.5);
			ctbg = (pow(dg, 2) * PI) / 3;
			bg = 0 ;
			sbc = n / ctbc;
            if (dc < 8) {
                sldbc = 1;
            }else if( dc >=8) {
                sldbc = 2;}
            tsldbc = sbc * sldbc;
			if(tsldbc<=ld && dc < 8)
			{
				bc = tsldbc; 
			}else if(tsldbc<=ld && dc >= 8)
			{
				bc = tsldbc/2;
			}else if(tsldbc>ld && dc < 8)
			{
				bc = ld;
			}else if(tsldbc>ld&& dc >= 8)
			{
				bc=ld/2;
			}
					nd = n - bc* ctbc;
					printf("%d %d %.3f",bc,bg,nd);
		}
		else
		{
			fptr = fopen("output.out", "w");
		   	//write values to file
			fprintf(fptr,"-1 -1 %d",n);
							
			fclose(fptr); 
						  
			return 0;

		}}////////////////////////////////////////////
	//Fogggggggggggggggggggggggggggggggg
    else if((strcmp(w,"Fog")) == 0 )
	{
    	if((n > 0 && n <= 2000 && dc >= 0 && dg>0 &&ld >= 1 && ld <= 600) || ( dg >= 0 && dc>0 && n > 0 && n <= 2000 && ld >= 1 && ld <= 600))
    	{
		    while (b <= dc) {
        		if (b == dc) {
            	isNum1Fibonacci = 1;
            	break;}
        	temp = a + b;
        	a = b;
        	b = temp;}
    	a = 0;
    	b = 1;
    		while (b <= dg) {
        		if (b == dg) {
            	isNum2Fibonacci = 1;
            	break;}
        	temp = a + b;
        	a = b;
        	b = temp;}
    		if (isNum1Fibonacci && isNum2Fibonacci) {
    			dc = dc /2;
				dg = dg /2;
    			ctbc = pow(dc, 2.5);
				ctbg = (pow(dg, 2) * PI) / 3;
				if (ctbc > ctbg) {
            		sbc = n / ctbc;
            		if (dc < 8) {
                		sldbc = 1;
            		}else if (dc >=8) {
                		sldbc = 2;}
            		tsldbc = sbc * sldbc;
            		if (tsldbc <= ld && dc < 8) {
                		bc = tsldbc;
                		ldsau = ld - tsldbc;
            		} else if (tsldbc <= ld && dc >= 8) {
                		bc = tsldbc / 2;
                		ldsau = ld - tsldbc;
            		} else if (tsldbc > ld && dc < 8) {
                		bc = ld;
            		} else if (tsldbc > ld && dc >= 8) {
                		bc = ld/2;
                		ldsau = ld- ( bc * 2 );}
            		if(ctbg > 0){
						sbg= ((n - (bc * ctbc)) / (ctbg));
					}else{
						sbg= 0;				}							
            		if (dg < 5) {
                		sldbg = 1;
            		}else if( dg >=5) {
                		sldbg = 2;}
            		tsldbg = sbg * sldbg;
            		if (tsldbg <= ldsau && dg < 5) {
                		bg = tsldbg;
            		} else if (tsldbg <= ldsau && dg >= 5) {
                		bg = tsldbg / 2;
            		} else if (tsldbg > ldsau && dg < 5) {
                		bg = ldsau;
            		} else if (tsldbg > ldsau && dg >= 5) {
                		bg = ldsau/2;}            
				}
				else if (ctbc < ctbg) {
					sbg = n / ctbg;
					if (dg < 5) {
                		sldbg = 1;
            		}else if( dg >=5) {
                		sldbg = 2;}
        			tsldbg = sbg * sldbg;
            		if (tsldbg <= ld && dg < 5) {
                		bg = tsldbg;
                		ldsau = ld - tsldbg;
            		} else if (tsldbg <= ld && dg >= 5) {
               			bg = tsldbg / 2;
                		ldsau = ld - tsldbg;
            		} else if (tsldbg > ld && dg < 5){
                		bg = ld;
                		ldsau = ld - tsldbg;
            		} else if (tsldbg > ld && dg >= 5) {
                		bg = ld/2;
                		ldsau = ld- ( bg * 2 );} 
            		if(ctbc > 0){
						sbc= ((n - (bg * ctbg)) / (ctbc));
					}else{
						sbc= 0;}
            		if (dc < 8) {
                		sldbc = 1;
            		}else if( dg >=8) {
                		sldbc = 2;}
            		tsldbc = sbc * sldbc;
            		if (tsldbc <= ldsau && dc < 8) {
                		bc = tsldbc;
            		} else if (tsldbc <= ldsau && dc >= 8) {
                		bc = tsldbc / 2;
            		} else if (tsldbc > ldsau && dc< 8) {
                		bc = ld;
            		} else if (tsldbc > ldsau && dc>= 8) {
                		bc = ld/2;
                		ldsau = ld- ( bc * 2 );}			
				}
			}
			else{	
    			dc = dc * 2;
				dg = dg * 2;
    			ctbc = pow(dc, 2.5);
				ctbg = (pow(dg, 2) * PI) / 3;
				if (ctbc > ctbg) {
            		sbc = n / ctbc;
            	if (dc < 8) {
                	sldbc = 1;
            	}else if (dc >=8) {
                	sldbc = 2;}
            	tsldbc = sbc * sldbc;
            	if (tsldbc <= ld && dc < 8) {
                	bc = tsldbc;
                	ldsau = ld - tsldbc;
            	} else if (tsldbc <= ld && dc >= 8) {
                	bc = tsldbc / 2;
                	ldsau = ld - tsldbc;
            	} else if (tsldbc > ld && dc < 8) {
               		bc = ld;
            	} else if (tsldbc > ld && dc >= 8) {
                	bc = ld/2;
                	ldsau = ld- ( bc * 2 );}
            	if(ctbg > 0){
					sbg= ((n - (bc * ctbc)) / (ctbg));
				}else{
					sbg= 0;}			
            	if (dg < 5) {
                	sldbg = 1;
            	}else if( dg >=5) {
                	sldbg = 2;}
            	tsldbg = sbg * sldbg; 
            	if (tsldbg <= ldsau && dg < 5) {
                	bg = tsldbg;
            	} else if (tsldbg <= ldsau && dg >= 5) {
                	bg = tsldbg / 2;
            	} else if (tsldbg > ldsau && dg < 5) {
                	bg = ldsau;
            	} else if (tsldbg > ldsau && dg >= 5) {
                	bg = ldsau/2;}            
				}
				else if (ctbc < ctbg) {
					sbg = n / ctbg;
					if (dg < 5) {
                		sldbg = 1;
            		}else if( dg >=5) {
                		sldbg = 2;}
        			tsldbg = sbg * sldbg;
            		if (tsldbg <= ld && dg < 5) {
                		bg = tsldbg;
                		ldsau = ld - tsldbg;
            		} else if (tsldbg <= ld && dg >= 5) {
               			bg = tsldbg / 2;
                		ldsau = ld - tsldbg;
            		} else if (tsldbg > ld && dg < 5){
                		bg = ld;
                		ldsau = ld - tsldbg;
            		} else if (tsldbg > ld && dc >= 5) {
                		bg = ld/2;
                		ldsau = ld- ( bg * 2 );} 
            		if(ctbc > 0){
						sbc= ((n - (bg * ctbg)) / (ctbc));
					}else{
						sbc= 0;}
            		if (dc < 8){
                		sldbc = 1;
            		}else if( dc >=8){
                		sldbc = 2;}
            		tsldbc = sbc * sldbc;
           			if (tsldbc <= ldsau && dc < 8) {
                		bc = tsldbc;
            		} else if (tsldbc <= ldsau && dc >= 8) {
                		bc = tsldbc / 2;
            		} else if (tsldbc > ldsau && dc< 8) {
                		bc = ld;
            		} else if (tsldbc > ldsau && dc>= 8) {
                		bc = ld/2;
                		ldsau = ld- ( bc * 2 );}			
				}
			}
	nd = n - (bc*ctbc+bg*ctbg);
	fptr = fopen("output.out", "w");
	//write values to file
	fprintf(fptr,"%d %d %.3f",bc,bg,nd);
							
	fclose(fptr); 
						  
	return 0; 	

		}
	else 
	{
		fptr = fopen("output.out", "w");
	   	//write values to file
		fprintf(fptr,"-1 -1 %d",n);
							
		fclose(fptr); 
						  
		return 0;

	}}//////////////////////
//Cloudddddddddddddddddd
	else if ((strcmp(w,"Cloud")) == 0 )
	{
		if 	((n > 0 && n <= 2000 && dc >= 0 && dg>0 &&ld >= 1 && ld <= 600) || ( dg >= 0 && dc>0 && n > 0 && n <= 2000 && ld >= 1 && ld <= 600))
		{
    		for ( i = 2; i <= sqrt(n); i++) {
        		if (n % i == 0) {
            		if (n / i == i)
                		sum_a += n / i;
            		else
                		sum_a += (n/ i) + i;}}

    		for ( i = 2; i <= sqrt(ld); i++) {
        		if (ld % i == 0) {
            		if (ld / i == i)
                		sum_b += ld / i;
            		else
                		sum_b += (ld / i) + i;}}
   			ctbc = pow(dc, 2.5);
			ctbg = (pow(dg, 2) * PI) / 3;
			sbgcheck = n / ctbg;	
    		if (dg < 5) {
        		sldbgcheck = 1;
    		}else if (dg >=5) {
        		sldbgcheck = 2;}	
			tsldbg1 = sbgcheck * sldbgcheck;
    		if (sum_a == ld && sum_b == n){
    			fptr = fopen("output.out", "w");
			   	//write values to file
				fprintf(fptr,"0 0 %d",n);
								
				fclose(fptr); 
							  
				return 0;
}
			else{
				if(ctbc>ctbg && tsldbg1 > ld){
					sbc = n / ctbc;
					if (dc < 8) {
                		sldbc = 1;
            		}else if( dc >=8) {
                		sldbc = 2;}
        			tsldbc = sbc * sldbc;
            		if (tsldbc <= ld && dc < 8) {
                		bc = tsldbc;
                		ldsau = ld - tsldbc;
            		} else if (tsldbc <= ld && dc >= 8) {
               			bc = tsldbc / 2;
                		ldsau = ld - tsldbc;
            		} else if (tsldbc > ld && dc < 8){
                		bc = ld;
                		ldsau = ld - tsldbc;
            		} else if (tsldbc > ld && dc >= 8) {
                		bc = ld/2;
                		ldsau = ld - ( bc * 2 );} 
            		if(ctbg > 0){
						sbg= ((n - (bc * ctbc)) / (ctbg));	
					}else{
						sbg= 0;}		
            		if (dg < 5) {
                		sldbg = 1;
            		}else if( dg >=5) {
                		sldbg = 2;}
            		tsldbg = sbg * sldbg;   
            		if (tsldbg <= ldsau && dg < 5) {
                		bg = tsldbg;
            		} else if (tsldbg <= ldsau && dg >= 5) {
                		bg = tsldbg / 2;
            		} else if (tsldbg > ldsau && dg< 5) {
                		bg= ldsau;
            		} else if (tsldbg> ldsau && dg>= 5) {
                		bg = ldsau/2;}
                		
                	nd = n - (bc*ctbc+ bg*ctbg)	;
                	fptr = fopen("output.out", "w");
				   	//write values to file
					fprintf(fptr,"%d %d %.3f",bc,bg,nd);
									
					fclose(fptr); 
								  
					return 0;
		
						
				}
				else if( dc == 0 ){
					bc=0;
					sbg = n / ctbg;
					if (dg < 5) {
	            		sldbg = 1;
	        		}else if( dg >=5) {
	            		sldbg = 2;}
	        		tsldbg = sbg * sldbg;
	        
					if(tsldbg<=ld && dg < 5){
						bg = tsldbg; 
					}else if(tsldbg<=ld && dg >= 5){
						bg = tsldbg/2;
					}else if(tsldbg>ld && dg < 5){
						bg = ld;
					}else if(tsldbg>ld && dg >= 5){
						bg = ld/2;}
						
					nd = n - (bc*ctbc+ bg*ctbg)	;
					fptr = fopen("output.out", "w");
				   	//write values to file
					fprintf(fptr,"%d %d %.3f",bc,bg,nd);
									
					fclose(fptr); 
								  
					return 0;
	
				}
				else if( dg == 0 ){
					bg=0;
					sbc = n / ctbc;
					if (dc < 8) {
	            	sldbc = 1;
	        		}else if( dc >=8) {
	            	sldbc = 2;}
	        		tsldbc = sbc * sldbc;
	        
					if(tsldbc<=ld && dc < 8)
					{
						bc = tsldbc; 
					}else if(tsldbc<=ld && dc >= 8)
					{
						bc =tsldbc/2;
					}else if(tsldbc>ld && dc < 8)
					{
						bc = ld;
					}else if(tsldbc>ld && dc >= 8)
					{
						bc = ld/2;
					}
					nd = n - (bc*ctbc+ bg*ctbg)	;
					fptr = fopen("output.out", "w");
				   	//write values to file
					fprintf(fptr,"%d %d %.3f",bc,bg,nd);
									
					fclose(fptr); 
								  
					return 0;

					}						
				else{
					sbg = n / ctbg;
					if (dg < 5) {
                		sldbg = 1;
            		}else if( dg >=5) {
                		sldbg = 2;}
        			tsldbg = sbg * sldbg;
            		if (tsldbg <= ld && dg < 5) {
                		bg = tsldbg;
                		ldsau = ld - tsldbg;
            		} else if (tsldbg <= ld && dg >= 5) {
               			bg = tsldbg / 2;
                		ldsau = ld - tsldbg;
            		} else if (tsldbg > ld && dg < 5){
                		bg = ld;
                		ldsau = ld - tsldbg;
            		} else if (tsldbg > ld && dg >= 5) {
                		bg = ld/2;
                		ldsau = ld - ( bg * 2 );} 
            		if(ctbc > 0){
						sbc= ((n - (bg * ctbg)) / (ctbc));	
					}else{
						sbc= 0;}		
            		if (dc < 8) {
                		sldbc = 1;
            		}else if( dc >=8) {
                		sldbc = 2;}
            		tsldbc = sbc * sldbc;            
            		if (tsldbc <= ldsau && dc < 8) {
                		bc = tsldbc;
            		} else if (tsldbc <= ldsau && dc >= 8) {
                		bc = tsldbc / 2;
            		} else if (tsldbc > ldsau && dc< 8) {
                		bc = ldsau;
            		} else if (tsldbc > ldsau && dc>= 8) {
                		bc = ldsau/2;}			 
				}
			nd = n - (bc*ctbc+ bg*ctbg)	;
			fptr = fopen("output.out", "w");
		   	//write values to file
			fprintf(fptr,"%d %d %.3f",bc,bg,nd);
							
			fclose(fptr); 
						  
			return 0;
			}
		}
	else
	{
		fptr = fopen("output.out", "w");
		//write values to file
		fprintf(fptr,"-1 -1 %d",n);
							
		fclose(fptr); 
						  
		return 0;

		
	}}//////////////////////////
	
    else if ((strcmp(w,"Sun")) == 0 )
	{
		H = ld % 5;
		G = dc % 6; 
    	int array[5][6] = {
			{5,7,10,12,15,20},
			{20,5,7,10,12,15},
			{15,20,5,7,10,12},
			{12,15,20,5,7,10},
			{10,12,15,20,5,7},	
	};
    	z = array[H][G];
		float nepmoi = n + (n*z/100);
		int ldmoi = ld - z;	
		if ((nepmoi - (int)nepmoi) != 0) 
		{
			cf = nepmoi;
			fptr = fopen("output.out", "w");
		   	//write values to file
			fprintf(fptr,"-1 -1 %d",cf);
							
 			fclose(fptr); 
						  
			return 0;

		}else
		{
			int duy;
			duy = nepmoi;
			if((dc+dg)%3 == 1)
			{
		    	if((nepmoi > 0&&  dc >= 0 && dg>0 &&ldmoi >= 1&& nepmoi<2001&&ldmoi<601   ) || ( dg >= 0 && dc>0 && nepmoi > 0  && ldmoi >= 1 && nepmoi<2001&&ldmoi<601 ))
				{
			    	ctbc = pow(dc, 2.5);
					ctbg = (pow(dg, 2) * PI) / 3;
					sbccheck = nepmoi / ctbc;
		    		if (dc < 8) {
		        		sldbccheck = 1;
		    		}else if (dc >=8) {
		        		sldbccheck = 2;}
					tsldbc1 = sbccheck * sldbccheck;
					if(ctbg>ctbc && tsldbc1 > ldmoi){
						sbg = nepmoi / ctbg;
						if (dg < 5) {
		            		sldbg = 1;
		        		}else if( dg >=5) {
		            		sldbg = 2;}
		        		tsldbg = sbg * sldbg;
		        		if (tsldbg <= ldmoi && dg < 5) {
		            		bg = tsldbg;
		            		ldsau = ldmoi - tsldbg;
		        		}else if (tsldbg <= ldmoi && dg >= 5){
		            		bg = tsldbg / 2;
		            		ldsau = ldmoi - tsldbg;
		        		}else if (tsldbg > ldmoi && dg < 5){
		            		bg = ldmoi;
		            		ldsau = ldmoi - ldmoi;
		        		}else if (tsldbg > ldmoi && dg >= 5){
		        			bg = ldmoi/2;
		            		ldsau = ldmoi - ( bg * 2 );}       
		        		if(ctbc > 0){
							sbc= ((nepmoi - (bg * ctbg)) / (ctbc));	
						}else{
							sbc= 0;}
		        		if (dc < 8) {
		            		sldbc = 1;
		        		}else if( dc >=8) {
		            		sldbc = 2;}
		            
		        		tsldbc = sbc * sldbc;  
		        		if (tsldbc <= ldsau && dc < 8){
		            		bc = tsldbc;
		        		}else if (tsldbc <= ldsau && dc >= 8){
							bc = tsldbc / 2;
		        		}else if (tsldbc > ldsau && dc< 8){
		            		bc = ldsau;
		        		}else if (tsldbc > ldsau && dc>= 8){
		            		bc = ldsau/2;}			 
					}
					else if( dc == 0 ){
						bc=0;
						sbg = nepmoi / ctbg;
						if (dg < 5) {
		            		sldbg = 1;
		        		}else if( dg >=5) {
		            		sldbg = 2;}
		        		tsldbg = sbg * sldbg;
		        
						if(tsldbg<=ldmoi && dg < 5){
							bg = tsldbg; 
						}else if(tsldbg<=ldmoi && dg >= 5){
							bg = tsldbg/2;
						}else if(tsldbg>ldmoi && dg < 5){
							bg = ldmoi;
						}else if(tsldbg>ldmoi && dg >= 5){
							bg = ldmoi/2;}
					}
					else if( dg == 0 ){
						bg=0;
						sbc = nepmoi / ctbc;
						if (dc < 8) {
		            	sldbc = 1;
		        		}else if( dc >=8) {
		            	sldbc = 2;}
		        		tsldbc = sbc * sldbc;
		        
						if(tsldbc<=ldmoi && dc < 8)
						{
							bc = tsldbc; 
						}else if(tsldbc<=ldmoi && dc >= 8)
						{
							bc = tsldbc/2;
						}else if(tsldbc>ldmoi && dc < 8)
						{
							bc = ldmoi;
						}else if(tsldbc>ldmoi && dc >= 8)
						{
							bc = ldmoi/2;
						}}		
					else{
		        		sbc = nepmoi / ctbc;
		        		if (dc < 8) {
		            		sldbc = 1;
		        		}else if (dc >=8) {
		            		sldbc = 2;}
		        		tsldbc = sbc * sldbc;
		        		if (tsldbc <= ldmoi && dc < 8) {
		            		bc = tsldbc;
		            		ldsau = ldmoi - tsldbc;
		        		}else if (tsldbc <= ldmoi && dc >= 8) {
		            		bc = tsldbc / 2;
		            		ldsau = ldmoi - tsldbc;
		        		} else if (tsldbc > ldmoi && dc < 8) {
		            		bc = ldmoi;
		        		} else if (tsldbc > ldmoi && dc >= 8) {
		            		bc = ldmoi/2;
		            		ldsau = ldmoi- ( bc * 2 );}
		        		if(ctbg > 0){
							sbg= ((nepmoi - (bc * ctbc)) / (ctbg));
						}else{
							sbg= 0;}							
		        		if (dg < 5) {
		            		sldbg = 1;
		        		}else if( dg >=5) {
		            		sldbg = 2;}
		        		tsldbg = sbg * sldbg;  
		        		if (tsldbg <= ldsau && dg < 5) {
		            		bg = tsldbg;
		        		}else if (tsldbg <= ldsau && dg >= 5) {
		            		bg = tsldbg / 2;
		        		} else if (tsldbg > ldsau && dg < 5) {
		            		bg = ldsau;
		        		} else if (tsldbg > ldsau && dg >= 5) {
		            		bg = ldsau/2;}            
					}
				nd = nepmoi - (bc*ctbc+bg*ctbg);
				fptr = fopen("output.out", "w");
			   	//write values to file
				fprintf(fptr,"%d %d %.3f",bc,bg,nd);
							
				fclose(fptr); 
						  
				return 0;

				}else
				{
					fptr = fopen("output.out", "w");
				 	//write values to file
					fprintf(fptr,"-1 -1 %d",n);
							
					fclose(fptr); 
						  
					return 0;

				}
			}///////////////////////////////
			else if((dc+dg)%3 == 2)
			{
				if 	((nepmoi > 0 && dc >= 0 && dg>0 &&ldmoi > 0 ) || ( dg >= 0 && dc > 0 && nepmoi > 0 && ldmoi > 0 ))
				{
		    		for ( i = 2; i <= sqrt(qw); i++) {
		        		if (qw % i == 0) {
		            		if (qw / i == i)
		                		sum_a += qw / i;
		            		else
		                		sum_a += (qw/ i) + i;}}
		
		    		for ( i = 2; i <= sqrt(qw); i++) {
		        		if (ldmoi % i == 0) {
		            		if (ldmoi / i == i)
		                		sum_b += ldmoi / i;
		            		else
		                		sum_b += (ldmoi / i) + i;}}
		   			ctbc = pow(dc, 2.5);
					ctbg = (pow(dg, 2) * PI) / 3;
					sbgcheck = nepmoi / ctbg;	
		    		if (dg < 5) {
		        		sldbgcheck = 1;
		    		}else if (dg >=5) {
		        		sldbgcheck = 2;}	
					tsldbg1 = sbgcheck * sldbgcheck;
		    		if (sum_a == ldmoi && sum_b == qw){
		    			fptr = fopen("output.out", "w");
						//write values to file
						fprintf(fptr,"0 0 %d",duy);
							
						fclose(fptr); 
						  
						return 0;
}
					else{
						if(ctbc>ctbg && tsldbg1 > ldmoi){
							sbc = nepmoi / ctbc;
							if (dc < 8) {
		                		sldbc = 1;
		            		}else if( dc >=8) {
		                		sldbc = 2;}
		        			tsldbc = sbc * sldbc;
		            		if (tsldbc <= ldmoi && dc < 8) {
		                		bc = tsldbc;
		                		ldsau = ldmoi - tsldbc;
		            		} else if (tsldbc <= ldmoi && dc >= 8) {
		               			bc = tsldbc / 2;
		                		ldsau = ldmoi - tsldbc;
		            		} else if (tsldbc > ldmoi && dc < 8){
		                		bc = ldmoi;
		                		ldsau = ldmoi - tsldbc;
		            		} else if (tsldbc > ldmoi && dc >= 8) {
		                		bc = ldmoi/2;
		                		ldsau = ldmoi - ( bc * 2 );} 
		            		if(ctbg > 0){
								sbg= ((nepmoi - (bc * ctbc)) / (ctbg));	
							}else{
								sbg= 0;}		
		            		if (dg < 5) {
		                		sldbg = 1;
		            		}else if( dg >=5) {
		                		sldbg = 2;}
		            		tsldbg = sbg * sldbg;   
		            		if (tsldbg <= ldsau && dg < 5) {
		                		bg = tsldbg;
		            		} else if (tsldbg <= ldsau && dg >= 5) {
		                		bg = tsldbg / 2;
		            		} else if (tsldbg > ldsau && dg< 5) {
		                		bg= ldsau;
		            		} else if (tsldbg> ldsau && dg>= 5) {
		                		bg = ldsau/2;}	
		                	nd = nepmoi - (bc*ctbc+ bg*ctbg)	;			
						}
						else if( dc == 0 ){
							bc=0;
							sbg = nepmoi / ctbg;
							if (dg < 5) {
			            		sldbg = 1;
			        		}else if( dg >=5) {
			            		sldbg = 2;}
			        		tsldbg = sbg * sldbg;
			        
							if(tsldbg<=ldmoi && dg < 5){
								bg = tsldbg; 
							}else if(tsldbg<=ldmoi && dg >= 5){
								bg = tsldbg/2;
							}else if(tsldbg>ldmoi && dg < 5){
								bg = ldmoi;
							}else if(tsldbg>ldmoi && dg >= 5){
								bg = ldmoi/2;}	
							nd = nepmoi - (bc*ctbc+ bg*ctbg)	;
						}
						else if( dg == 0 ){
							bg=0;
							sbc = nepmoi / ctbc;
							if (dc < 8) {
			            	sldbc = 1;
			        		}else if( dc >=8) {
			            	sldbc = 2;}
			        		tsldbc = sbc * sldbc;
			        
							if(tsldbc<=ldmoi && dc < 8)
							{
								bc =tsldbc; 
							}else if(tsldbc<=ldmoi && dc >= 8)
							{
								bc = tsldbc/2;
							}else if(tsldbc>ldmoi && dc < 8)
							{
								bc = ldmoi;
							}else if(tsldbc>ldmoi && dc >= 8)
							{
								bc = ldmoi/2;
							}
							nd = nepmoi - (bc*ctbc+ bg*ctbg)	;
							}						
						else{
							sbg = nepmoi / ctbg;
							if (dg < 5) {
		                		sldbg = 1;
		            		}else if( dg >=5) {
		                		sldbg = 2;}
		        			tsldbg = sbg * sldbg;
		            		if (tsldbg <= ldmoi && dg < 5) {
		                		bg = tsldbg;
		                		ldsau = ldmoi - tsldbg;
		            		} else if (tsldbg <= ldmoi && dg >= 5) {
		               			bg = tsldbg / 2;
		                		ldsau = ldmoi - tsldbg;
		            		} else if (tsldbg > ldmoi && dg < 5){
		                		bg = ldmoi;
		                		ldsau = ldmoi - tsldbg;
		            		} else if (tsldbg > ldmoi && dg >= 5) {
		                		bg = ldmoi/2;
		                		ldsau = ldmoi - ( bg * 2 );} 
		            		if(ctbc > 0){
								sbc= ((nepmoi - (bg * ctbg)) / (ctbc));	
							}else{
								sbc= 0;}		
		            		if (dc < 8) {
		                		sldbc = 1;
		            		}else if( dc >=8) {
		                		sldbc = 2;}
		            		tsldbc = sbc * sldbc;            
		            		if (tsldbc <= ldsau && dc < 8) {
		                		bc = tsldbc;
		            		} else if (tsldbc <= ldsau && dc >= 8) {
		                		bc = tsldbc / 2;
		            		} else if (tsldbc > ldsau && dc< 8) {
		                		bc = ldsau;
		            		} else if (tsldbc > ldsau && dc>= 8) {
		                		bc = ldsau/2;}			 
						}	
						nd = nepmoi - (bc*ctbc+ bg*ctbg);
						fptr = fopen("output.out", "w");
					   	//write values to file
						fprintf(fptr,"%d %d %.3f",bc,bg,nd);
							
						fclose(fptr); 
						  
						return 0;	
		
				}	
				}else
				{
					fptr = fopen("output.out", "w");
				   	//write values to file
					fprintf(fptr,"-1 -1 %d",duy);
					
					fclose(fptr); 
				  
					return 0;

				}
			}///////////////////////
			else if((dc+dg)%3 == 0)
			{
				if(nepmoi > 0 && dc > 0 && dg>0 &&ldmoi >= 1 && nepmoi <2001 && ldmoi<601 )
	    		{
			    	ctbc = pow(dc, 2.5);
					ctbg = (pow(dg, 2) * PI) / 3;
			    	if (dc < 8) {
			    		sldbc = 1;
			    	}else if (dc >=8) {
			    		sldbc = 2;}
			   		if (dg < 5) {
			    		sldbg = 1;
			    	}else if( dg >=5) {
			    		sldbg = 2;}
				    nep1capbanh = ctbc + ctbg;
				    tsld1cap = sldbc + sldbg;
					capbanhtheonep = nepmoi / nep1capbanh;
					capldtheold = ldmoi / tsld1cap;
					if(capbanhtheonep <= capldtheold){
						neptheocap1 = (capbanhtheonep * nep1capbanh );
						nepsau = nepmoi - neptheocap1;
						ldconlai = ldmoi - (capbanhtheonep*tsld1cap);
						if (ctbc>ctbg) {
				            sbc = nepsau / ctbc;
				            if (dc < 8) {
				                sldbc = 1;
				            }else if (dc >=8) {
				                sldbc = 2;}
				            tsldbc = sbc * sldbc;
				            if (tsldbc <= ldconlai && dc < 8) {
				                bc = tsldbc;
				                ldsau = ldconlai - tsldbc;
				            } else if (tsldbc <= ldconlai && dc >= 8) {
				                bc = tsldbc / 2;
				                ldsau = ldconlai - tsldbc;
				            } else if (tsldbc > ldconlai && dc < 8) {
				                bc = ldconlai;
				            } else if (tsldbc > ldconlai && dc >= 8) {
				                bc = ldconlai/2;
				                ldsau = ldconlai- ( bc * 2 );}
				            if(ctbg > 0){
								sbg= ((nepsau - (bc * ctbc)) / (ctbg));
							}else{
								sbg= 0;}
				            if (dg < 5) {
				                sldbg = 1;
				            }else if( dg >=5){
				                sldbg = 2;}
				            tsldbg = sbg * sldbg;
				            if (tsldbg <= ldsau && dg < 5) {
				                bg = tsldbg;
				            } else if (tsldbg <= ldsau && dg >= 5) {
				                bg = tsldbg / 2;
				            } else if (tsldbg > ldsau && dg < 5) {
				                bg = ldsau;
				            } else if (tsldbg > ldsau && dg >= 5) {
				                bg = ldsau/2;}            
						}
						else if (ctbc<ctbg) {
							sbg = nepsau / ctbg;
							if (dg < 5) {
				                sldbg = 1;
				            }else if( dg >=5) {
				                sldbg = 2;}
				        	tsldbg = sbg * sldbg;
				            if (tsldbg <= ldconlai && dg < 5) {
				                bg = tsldbg;
				                ldsau = ldconlai - tsldbg;
				            } else if (tsldbg <= ldconlai && dg >= 5) {
				                bg = tsldbg / 2;
				                ldsau = ldconlai - tsldbg;
				            } else if (tsldbg > ldconlai && dg < 5){
				                bg = ldconlai;
				                ldsau = ldconlai - ldconlai;
				            } else if (tsldbg > ldconlai && dg >= 5) {
				                bg = ldconlai/2;
				                ldsau = ldconlai - ( bg * 2 );} 
				            if(ctbc > 0){
								sbc= ((nepsau - (bg * ctbg)) / (ctbc));	
							}else{
								sbc= 0;}
				            if (dc < 8) {
				                sldbc = 1;
				            }else if( dc >=8) {
				                sldbc = 2;}            
				            tsldbc = sbc * sldbc;
				            if (tsldbc <= ldsau && dc < 8) {
				                bc = tsldbc;
				            } else if (tsldbc <= ldsau && dc >= 8) {
				                bc = tsldbc / 2;
				            } else if (tsldbc > ldsau && dc< 8) {
				                bc = ldsau;
				            } else if (tsldbc > ldsau && dc>= 8) {
				                bc = ldsau/2;}			                    
						}
							bcend = bc + capbanhtheonep;
							bgend = bg + capbanhtheonep;
							nd = nepmoi - (bcend* ctbc + bgend*ctbg);
							fptr = fopen("output.out", "w");
						   	//write values to file
							fprintf(fptr,"%d %d %.3f",bcend,bgend,nd);
							
							fclose(fptr); 
						  
							return 0;

					}
					else if (capbanhtheonep > capldtheold){
						neptheocap1 = (capldtheold * nep1capbanh );
						nepsau = nepmoi - neptheocap1;
						ldconlai = ldmoi - (capldtheold*tsld1cap);
						if (ctbc>ctbg) {
				            sbc = nepsau / ctbc;
				            if (dc < 8) {
				                sldbc = 1;
				            }else if (dc >=8){
				                sldbc = 2;}
				            tsldbc = sbc * sldbc;
				            if (tsldbc <= ldconlai && dc < 8) {
				                bc = tsldbc;
				                ldsau = ldconlai - tsldbc;
				            } else if (tsldbc <= ldconlai && dc >= 8) {
				                bc = tsldbc / 2;
				                ldsau = ldconlai - tsldbc;
				            } else if (tsldbc > ldconlai && dc < 8) {
				                bc = ldconlai;
				            } else if (tsldbc > ldconlai && dc >= 8) {
				                bc = ldconlai/2;
				                ldsau = ldconlai- ( bc * 2 );}
				            if(ctbg > 0){
								sbg= ((nepsau - (bc * ctbc)) / (ctbg));
							}else{
								sbg= 0;}							
				            if (dg < 5) {
				                sldbg = 1;
				            }else if( dg >=5) {
				                sldbg = 2;}
				            tsldbg = sbg * sldbg;
				            if (tsldbg <= ldsau && dg < 5) {
				                bg = tsldbg;
				            } else if (tsldbg <= ldsau && dg >= 5) {
				                bg = tsldbg / 2;
				            } else if (tsldbg > ldsau && dg < 5) {
				                bg = ldsau;
				            } else if (tsldbg > ldsau && dg >= 5) {
				                bg = ldsau/2;}            
						}
						else if (ctbc<ctbg) {
							sbg = nepsau / ctbg;
							if (dg < 5) {
				                sldbg = 1;
				            }else if( dg >=5) {
				                sldbg = 2;}
				        	tsldbg = sbg * sldbg;
				            if (tsldbg <= ldconlai && dg < 5) {
				                bg = tsldbg;
				                ldsau = ldconlai - tsldbg;
				            } else if (tsldbg <= ldconlai && dg >= 5) {
				                bg = tsldbg / 2;
				                ldsau = ldconlai - tsldbg;
				            } else if (tsldbg > ldconlai && dg < 5){
				                bg = ldconlai;
				                ldsau = ldconlai - bg;
				            } else if (tsldbg > ldconlai && dg >= 5) {
				                bg = ldconlai/2;
				                ldsau = ldconlai - ( bg * 2 );} 
				            if(ctbc > 0){
								sbc= ((nepsau - (bg * ctbg)) / (ctbc));	
							}else{
								sbc= 0;}
				            if (dc < 8) {
				                sldbc = 1;
				            }else if( dc >=8) {
				                sldbc = 2;}
				            tsldbc = sbc * sldbc;
				            if (tsldbc <= ldsau && dc < 8) {
				                bc = tsldbc;
				            } else if (tsldbc <= ldsau && dc >= 8) {
				                bc = tsldbc / 2;
				            } else if (tsldbc > ldsau && dc< 8) {
				                bc = ldsau;
				            } else if (tsldbc > ldsau && dc>= 8) {
				                bc = ldsau/2;}			                    		
		
					bcend = bc + capldtheold;
					bgend = bg + capldtheold;
					nd = nepmoi - bcend*ctbc + bgend*ctbg;
					
						fptr = fopen("output.out", "w");
					   	//write values to file
						fprintf(fptr,"%d %d %.3f",bcend,bgend,nd);
						
						fclose(fptr); 
					  
						return 0;
}}
					
				}else if (nepmoi > 0 && dc == 0 && dg>0 &&ld >= 1 && nepmoi <2001&&ldmoi<601)
				{
			    	ctbc = pow(dc, 2.5);
					ctbg = (pow(dg, 2) * PI) / 3;
					bc = 0 ;
					sbg = nepmoi / ctbg;
		            if (dg < 5) {
		                sldbg = 1;
		            }else if( dg >=5) {
		                sldbg = 2;}
		            tsldbg = sbg * sldbg;
		            
					if(tsldbg<=ldmoi && dg < 5)
					{
						bg = tsldbg; 
					}else if(tsldbg<=ldmoi && dg >= 5)
					{
						bg = tsldbg/2;
					}else if(tsldbg>ldmoi && dg < 5)
					{
						bg = ldmoi;
					}else if(tsldbg>ldmoi && dg >= 5)
					{
						bg =ldmoi/2;
					}		
							nd = nepmoi - bg* ctbg;	
								fptr = fopen("output.out", "w");
							   	//write values to file
								fprintf(fptr,"%d %d %.3f", bc, bg, nd);
								
								fclose(fptr); 
							  
								return 0;

				}else if (nepmoi > 0  && dg == 0 && dc>0 &&ld >= 1&& nepmoi <2001&&ldmoi<601)
				{
					ctbc = pow(dc, 2.5);
					ctbg = (pow(dg, 2) * PI) / 3;
					bg = 0 ;
					sbc = nepmoi / ctbc;
		            if (dc < 8) {
		                sldbc = 1;
		            }else if( dc >=8) {
		                sldbc = 2;}
		            tsldbc = sbc * sldbc;
					if(tsldbc<=ldmoi && dc < 8)
					{
						bc = tsldbc; 
					}else if(tsldbc<=ldmoi && dc >= 8)
					{
						bc = tsldbc/2;
					}else if(tsldbc>ldmoi && dc < 8)
					{
						bc = ldmoi;
					}else if(tsldbc>ld&& dc >= 8)
					{
						bc=ldmoi/2;
					}
							nd = nepmoi - bc* ctbc;
								fptr = fopen("output.out", "w");
							   	//write values to file
								fprintf(fptr,"%d %d %.3f", bc, bg, nd);
								
								fclose(fptr); 
							  
								return 0;
				}
			else
			{
				printf("-1 -1 %d",duy);
			}////////////////////////////////////////////////////
}}}//////////////////////
	else 
	{
	fptr = fopen("output.out", "w");
   	if(fptr == NULL)
   	{
      	printf("Error!");
      	exit(1);
   	}
   
   	//write values to file
	fprintf(fptr,"%d %d %.3f", bc, bg, nd);
	
	fclose(fptr); 
  
	return 0;
	}
	}
		//write output.out file
	fptr = fopen("output.out", "w");
   	if(fptr == NULL)
   	{
      	printf("Error!");
      	exit(1);
   	}

   	//write values to file
	fprintf(fptr,"%d %d %.3f", bc, bg, nd);
	
	fclose(fptr); 
  
	return 0;
}


	
	
	
	
