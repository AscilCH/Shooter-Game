#include <MLV/MLV_all.h>/

    int x=1280;
    int y=960;
int random(int min,int max)
{
    int res;
    do
    {
          res=rand();
    }while(res<min  || res>max);
    return res;
}
void back_remover(int x,int y) // supprimer des cercles
{
     MLV_draw_filled_circle( x+60, y+60, 38, MLV_COLOR_BLACK );
}
void back_remover2(int x,int y)
{
     MLV_draw_filled_circle( x+80, y+60, 38, MLV_COLOR_BLACK );
}
void back_remover1(int x,int y)
{
     MLV_draw_filled_circle( x+15, y+14, 15, MLV_COLOR_BLACK );
}
void back_remover3(int x,int y)
{
     MLV_draw_filled_circle( x+45, y+60, 38, MLV_COLOR_BLACK );
}

void crash_remover(int x,int y)
{
          MLV_clear_window(MLV_COLOR_BLACK);
}
void clean_back() //dessiner un rectangle jaune pour effacer les amos
{
     MLV_draw_filled_rectangle(0,0,y+500,70,MLV_COLOR_YELLOW);
}
void down_clean() //effacer les traces de l'avion lorsqu'elle se déplace
{
     MLV_draw_filled_rectangle(0,y*9.15/10,y+500,100,MLV_COLOR_BLACK);
}
void aff(MLV_Image *amo,MLV_Image *heal,int c,int health) // affichage  le nombre d'amo et des coueurs restants
{
                       int P=(y*9/10)-250;
                          if(c==0)
                      {
                      back_remover1(5,P);
                      back_remover1(5,P+40);
                      back_remover1(5,P+80);
                      back_remover1(5,P+120);
                      }
                      if (c==1)
                      {MLV_draw_image(amo,5,P+120);
                      back_remover1(5,P+80);
                      
					  }
                      if(c==2)
                      {
                      	MLV_draw_image(amo,5,P+120);
                      	MLV_draw_image(amo,5,P+80);
                      	back_remover1(5,P+40);
					  }
					  if(c==3)
					  {
					  	  MLV_draw_image(amo,5,P+120);
					  	  MLV_draw_image(amo,5,P+80); 
                          MLV_draw_image(amo,5,P+40);
                          back_remover1(5,P);
					  }
					  if(c==4)
					  {
					  	MLV_draw_image(amo,5,P);
					  	MLV_draw_image(amo,5,P+40);
					  	MLV_draw_image(amo,5,P+80);
					  	MLV_draw_image(amo,5,P+120);
					  }
					  //---------------------------------------//
					  P-=50;
                      if(health==0)
                      {
                      back_remover1(5,P-40);
                      back_remover1(5,P-80);
                      back_remover1(5,P-120);
                      back_remover1(5,P-160);
                      }
                      if (health==1)
                      {MLV_draw_image(heal,5,P-160);
                      back_remover1(5,P-120);
                      
					  }
                      if(health==2)
                      {
                      	MLV_draw_image(heal,5,P-160);
                      	MLV_draw_image(amo,5,P-120);
                      	back_remover1(5,P-120);
					  }
					  if(health==3)
					  {
					  	  MLV_draw_image(heal,5,P-160);
					  	  MLV_draw_image(heal,5,P-120); 
                          MLV_draw_image(heal,5,P-80);
                          back_remover1(5,P-40);
					  }
					  if(health==4)
					  {
					  	MLV_draw_image(heal,5,P-160);
					  	MLV_draw_image(heal,5,P-120);
					  	MLV_draw_image(heal,5,P-80);
					  	MLV_draw_image(heal,5,P-40);
					  }
}
int main( int argc, char *argv[] ){ //importer tout les images nécessaires pour jouer et les positionner
	MLV_create_window( "beginner - 1 - hello world", "hello world",x,y);
    MLV_Image* momo = MLV_load_image("./data/img/momo.png");
    MLV_Image* plane = MLV_load_image("./data/img/plane.png");
	MLV_Image* alien = MLV_load_image("./data/img/alien.png");
	MLV_Image* rock = MLV_load_image("./data/img/rock.png");
	MLV_Image* fireball = MLV_load_image("./data/img/fireball.png");
   	MLV_Image* amo = MLV_load_image("./data/img/der der.png");
   	MLV_Image* heal = MLV_load_image("./data/img/heal.png");
   	MLV_resize_image(heal,28,28);
    MLV_resize_image(amo,28,28);
    MLV_resize_image(plane,100,100);
	MLV_resize_image(alien,120,100);
	MLV_resize_image(fireball,80,50);
	MLV_resize_image(rock,80,50);
    MLV_init_audio( );
	MLV_change_number_of_parallel_sounds ( 	4	);
    MLV_Sound* sound;
    MLV_Sound* expo = MLV_load_sound( "./data/img/expo.ogg" ); ;
    MLV_Music* beb = MLV_load_music( "./data/img/fugue.ogg" );
        MLV_play_music( beb, 1.0, -1 );
    int quit=0;int q=0;
	int xplane=x/2;
	int yfireball=y*9/10;
	int k=0;int j;
	int yalien=0;
	int xalien,i;
	int tx[40];
	int ty[40];
	int veriff[40];
	int veriff1[40];
	int vx[40];
	int vy[40];
	int vt[40];
	int kk=0;

	int b=0;
	int xtarget;
	int delaishoot=0;
	int dx=0;
	int dy=0;
	int r;
	int health=4;
	int xfireball;
	int pass=0;
	int verif;
	int compteur=0;
	int constanttemp=0;
	int reload=0;
	int deltax=0;
	int deltay=0;
	int nb_alien_alive=0;
	int c=4, n=1,P=(y*90/100)-200;
    int d=P;
    int fullscreen=0;
    int nfullscreen=0;
    int play=0;
    MLV_Keyboard_button touche; 
	const char *start="PRESS K TO START";
	const char *exit="PRESS ANY KEY TO EXIT ";
	const char *tuto=" TUTO:PRESS'<-'to go left/PRESS'->'to go right/ PRESS 'LCTRL' TO SHOOT / YOU HAVE TO DODGE ENEMY SHOOTS & U HAVE TO SLAIN ENNEMIES BEFORE GETTING OUT OF THE WINDOW";
    const char *window="PRESS ESCAPE TO DISABLE FULLSCREEN / PRESS TAB TO ENABLE FULLSCREEN (IN GAME) ";
	while(play==0)
	{
                  MLV_enable_full_screen();

                  MLV_clear_window(MLV_COLOR_BLACK);
    // sommaire pour pouvoir jouer
    MLV_draw_image(momo,0,0); 
    MLV_draw_adapted_text_box(x/3,y*2/5,start,25,MLV_COLOR_GREEN,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
	MLV_draw_adapted_text_box(x/2,y*2/5,exit,25,MLV_COLOR_GREEN,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
	MLV_draw_adapted_text_box(-30,y*3/5,tuto,25,MLV_COLOR_GREEN,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_LEFT);
	MLV_draw_adapted_text_box(x/4.5,y*4/5,window,25,MLV_COLOR_GREEN,MLV_COLOR_BLUE,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
	
	MLV_actualise_window();
	
	 MLV_wait_keyboard (&touche, NULL, NULL);
  
	
	
	
	 
	
	if(touche != MLV_KEYBOARD_k)
	{
              MLV_free_window();
    }
	if (touche==MLV_KEYBOARD_k) //commencer à jouer
	{
        
        xplane=x/2;
        quit=0;
        health=4;
        MLV_stop_music();
        MLV_free_music(beb);
        MLV_Music* jed = MLV_load_music( "./data/img/BB.ogg" );
        MLV_play_music( jed, 100.0, -1 );
	   
        MLV_enable_full_screen();
       
        for (i=0;i<40;i++)
        	{
        	vt[i]=0;
        	vx[i]=-900;
        	vy[i]=0;
        	veriff[i]=0;
        	veriff1[i]=0;
            tx[i]=random(0,x*9/10);
            ty[i]=0;}
        k=0;
        verif=0;
        compteur=0;
          
        MLV_enable_full_screen();
       
      
    
        while(quit==0) //condition d'echec
    	{
                      down_clean();
                      
                         
                      if (MLV_get_keyboard_state(MLV_KEYBOARD_ESCAPE)==MLV_PRESSED) 
                      {
                       MLV_disable_full_screen();
                      }
                      if (MLV_get_keyboard_state(MLV_KEYBOARD_TAB)==MLV_PRESSED)
                      {
                       MLV_enable_full_screen();
                      }
                    if ((MLV_get_time()%850)==0 && k<36 ) // le delai de l'apparition des ennemis et condition sur le nombre d'ennemis envoyés
                      {
                           if ((MLV_get_time()/850)<=1)
                           {r=2;}
                           else
                           {r=random(1,2);}
                           for (i=k;i<k+r;i++)
                               {
                                   if (ty[i]<=1)
                                       {
                                       ty[i]+=1;
                                       }

                               }
                               k+=r;
                               
                      }
                      else if(k>=36)
                      {
                                    k=0;
                      }
    
                      if (MLV_get_keyboard_state(MLV_KEYBOARD_LEFT)==MLV_PRESSED && xplane>0)
                        {
                        xplane-=2;
                        }
                      else if(MLV_get_keyboard_state(MLV_KEYBOARD_RIGHT)==MLV_PRESSED && xplane<x*9/10)
                        {
                        xplane+=2;
                        }
                        MLV_draw_image(plane,xplane,y*90/100);
                          
                          
                      if (MLV_get_keyboard_state(MLV_KEYBOARD_LCTRL)==MLV_PRESSED && b==0 && c!=0&& (MLV_get_time()/500-reload)!=0) //controler fireball
                        {
						   c-=1; 
						   reload=MLV_get_time()/500;
                           MLV_draw_image(fireball,xplane,yfireball-40);
                          sound = MLV_load_sound( "./data/img/shot.ogg" );
                        	MLV_play_sound( sound, 1.0 );
                        	
                        
                           xfireball=xplane;
                           b=1;
                        }
                      if (b==1 && yfireball>0)
                      {
                       yfireball-=3;
                       MLV_draw_image(fireball,xfireball,yfireball);
                       if (yfireball>=0 && yfireball<=10)
                        {
                        b=0;
                        yfireball=y*9/10;
                        }
                      else if( yfireball<=(y*90/100)-40)
                        {
                             back_remover3(xfireball,yfireball);
                        }
                       
                       
                      }
                      clean_back(); // effacer les fireballs qui sont arrivés 

                          for (j=0;j<40;j++)
                          {
                              if (compteur%7==0 && ty[j]%2==1 && ty[j]<y*9/10)
                              {   ty[j]+=2*random(1,3);
                                  MLV_draw_image(alien,tx[j],ty[j]);
                               } 
                              
                          
                               // hitbox
                              if   ((yfireball<=ty[j]+10 && yfireball>=ty[j]-10)&&(xfireball <= tx[j]+80 &&xfireball >= tx[j]-80))
                                   {  
                                       
                                  	   MLV_play_sound( expo, 1000.0 );
                                       crash_remover(tx[j]+40,ty[j]+40);//effacer l'avion et l'ennemi lorsqu'ils se croisent
                                       aff(amo,heal,c,health);
                                       b=0;
                                       yfireball=y*9/10;
                                       ty[j]=0;
                                       veriff[i]=0;
                                       tx[j]=random(0,x*9/10);
                                       
                                   }
                              if (ty[j]>=y*9/10)
                              {
                               ty[j]=0;
                               tx[j]=random(0,x*9/10);
                               MLV_play_sound( expo, 1000.0 );
                               health-=1;
                              }
                        }
                       for (i=0;i<40;i++) 
                            {
                              if (ty[i]<=y*9/10 && ty[i]>y/40 && verif==0) //positionner les bals des ennemis
                              {
                                      vx[i]=tx[i];
                                      vy[i]=ty[i];
                                      vt[i]=xplane;//avoir la position du cible
                                      verif=1;  
                              }
                              dx=vt[i]-40-vx[i];
                              dy=(y*9/10)-vy[i];
                              
                              
                              if (vx[i]!=-900 && vy[i]<y*9/10)
                                {
                                   if (dx!=0)
                                   {q=(dy/dx);}
                                   else
                                   {back_remover(vx[i],vy[i]);} 
                                   
                                   vy[i]+=1; 
                                   if (q<0)
                                   {  q=-q;
                                      if((MLV_get_time()*5)%q==0)
                                          {vx[i]-=1;
                                          back_remover2(vx[i]+20,vy[i]+10);
                                          }
                                   }
                                   else if(q>0)
                                   {
                                        if(MLV_get_time()%q==0)
                                        {vx[i]+=1;
                                        back_remover(vx[i]+20,vy[i]+10);
                                        }
                                   }
                                      
                                } 
                              if(vy[i]==y*9/10)
                              {
                                verif=0;
                                if (vx[i]>=xplane-50 && vx[i]<=xplane+50) //hitbox pour l'avion
                                   {health-=1;}
                              vx[i]=-900;
                              vy[i]=0;
                              } 
                              MLV_draw_image(rock,vx[i]+50,vy[i]+80);
                              
                            }
                        
                        
                        
                        compteur+=1;
                        if (compteur==100)
                        {compteur=0;}
                        
 
					  if ((MLV_get_time()%400)==0 && c<4)
						{
							c+=1; // augmenter le nb d'amo au cours du temps
						} 
                      if ((MLV_get_time()%15000)==0 && health<4)
						{
							health+=1; //augmenter le nb de coeur de l'avion
						}
						aff(amo,heal,c,health);
	                  if(health==0)
	                  {quit=1;
                   MLV_stop_music();
                   MLV_free_music(jed);
                   MLV_Music* beb = MLV_load_music( "./data/img/menu.ogg" );
                    MLV_play_music( beb, 100.0, -1 );}
					   
                          
                        MLV_actualise_window();
                        
        }
          
  }
}

  
  
  
  
  
}

	
	


