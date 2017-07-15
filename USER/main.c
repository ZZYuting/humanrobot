#include "stm32f10x.h"
#include "sys.h"
#include "action.h"
extern uint8_t Ov7725_vsync;
char result=4;
u8 go_flag=0;
u8 i=0;
void jiance(void);
void ceshi(void);

//whole
void go_ahead_left();
void go_ahead_right();
void xiao_leftturn();
void xiao_rightturn();
void x_left();
void x_right();
void big_rightturn();
void big_leftturn();
void hand_move1(void);
void hand_move2(void);
void PWM_OUTPUT(void);

int main(void)
{	
	unsigned char i=0;
	usart1_init(72,9600);
	/* 液晶初始化 */
	LCD_Init();	
  //while(1);
  //#if 1
	/* ov7725 gpio 初始化 */
	Ov7725_GPIO_Config();	
	/* ov7725 寄存器配置初始化 */
	while(Ov7725_Init() != SUCCESS);	
	delay_init();
	NVIC_Configuration();
	uart5_init(1000000);				//与舵机通信
	arm_init();	
	VSYNC_Init();	
	Ov7725_vsync = 0;
	go_flag=0;
	Key_GPIO_Config();
//	LED_GPIO_Config();
	//TIM3_GPIO_Config();
	PWM_OUTPUT();
	while(1)
	{		
zhili();
jiance();
delay_ms(1000);
jiance();
delay_ms(1000);
		

l_first_tai0();
l_first_tai1();
l_mai();
l_luo0();
l_luo1();
r_tai0();
r_tai1();
r_mai();
r_luo0();
r_luo1();
jiance();	
l_second_tai0();
l_second_tai1();
//开始走一步	

//l_mai();
//l_luo0();
//l_luo1();
//r_tai0();
//r_tai1();
//r_mai();
//r_luo0();
//r_luo1();
//jiance();
//l_second_tai0();
//l_second_tai1();
//go_flag=0;
//开始走第二步	
while(1)
{	//go_flag       left=0  right=1
	
	if(result==1)//  1左拐
	{
		if(go_flag==1) 
		  {
			r_mai();
			r_luo0();
			r_luo1();	
				hand_move2();
		 	l_second_tai0();
	    l_second_tai1();
				
      }   
	  xiao_leftturn();
	}
	if(result==2)//  2_bigleftturn
	{
		if(go_flag==1) 
		  {
			r_mai();
			r_luo0();
			r_luo1();	
				hand_move1();
		 	l_second_tai0();
	    l_second_tai1();
      }   
	 big_leftturn();
	}
  if(result==3) //直行
	{
		if(go_flag==0)  {hand_move1();go_ahead_left();}
		else           { hand_move2();go_ahead_right(); } 

	}
	if(result==4)   //4 右拐  
	{
			if(go_flag==0) 
		  {
			l_mai();
			l_luo0();
			l_luo1();	
				hand_move1();
		  r_tai0();
		  r_tai1();
      }   
		xiao_rightturn();
	}
	if(result==5)   //5 大右拐
	{
			if(go_flag==0) 
		  {
			l_mai();
			l_luo0();
			l_luo1();	
				hand_move2();
		  r_tai0();
		  r_tai1();
      }   
		big_rightturn();
}
 }  
  }
}
void jiance(void)
{
	if( Ov7725_vsync == 2 )
	{
		FIFO_PREPARE;  			/*FIFO准备*/					
		result=biaozhun();		/*采集并显示*/
		printf("/r/n result = %d ", result);
		Ov7725_vsync = 0;			
	}
}
void ceshi(void)
{
	while(1)
	{
		TIM3_Mode_Config(100);
			delay_ms(500);
		TIM3_Mode_Config(200);
			delay_ms(500);
		TIM3_Mode_Config(300);
			delay_ms(500);
		TIM3_Mode_Config(400);
			delay_ms(500);
		TIM3_Mode_Config(500);
			delay_ms(500);
		TIM3_Mode_Config(600);
			delay_ms(500);
		TIM3_Mode_Config(500);
			delay_ms(500);
		TIM3_Mode_Config(400);
			delay_ms(500);
		TIM3_Mode_Config(300);
			delay_ms(500);
		TIM3_Mode_Config(200);
			delay_ms(500);
	}		
}


