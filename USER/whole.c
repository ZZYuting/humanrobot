#include "uart5.h"
#include "action.h"
void jiance(void);
extern u8 go_flag;  //left=0  right=1

void go_ahead_left()
{
	l_mai();
	l_luo0();
	l_luo1();
	jiance();
	r_tai0();
	r_tai1();
	go_flag=1;
}
void go_ahead_right()
{
	r_mai();
	r_luo0();
	r_luo1();
	jiance();
	l_second_tai0();
	l_second_tai1();
	go_flag=0;
}

void xiao_leftturn()
{
	xiao_leftturn_mai(); //×ó½Å×ª
	xiao_leftturn_luo();
	xiao_leftturn_right_tai0();
	xiao_leftturn_right_tai0_tiaozheng();
	xiao_leftturn_right_tai1();
	r_mai();
	r_luo0();
	r_luo1();
	jiance();
	
	l_second_tai0();
	l_second_tai1();
	go_flag=0;
	
}

void xiao_rightturn()
{
	xiao_rightturn_mai();
	xiao_rightturn_luo();
	xiao_rightturn_left_tai0();
	xiao_rightturn_left_tai0_tiaozheng();
	xiao_rightturn_left_tai1();
	l_mai();
	l_luo0();
	l_luo1();
	jiance();
	r_tai0();
	r_tai1();
	go_flag=1;
}
void big_leftturn()
{
//	xiao_leftturn_mai(); //×ó½Å×ª
//	xiao_leftturn_luo();
//	xiao_leftturn_right_tai0();
//	xiao_leftturn_right_tai0_tiaozheng();
//	xiao_leftturn_right_tai1();
//	r_mai();
//	r_luo0();
//	r_luo1();
//		l_second_tai0();
//	l_second_tai1();

	
	/* 
	×ó¹ÕÒ»´Î*/
	xiao_leftturn_mai(); //×ó½Å×ª
	xiao_leftturn_luo();
	xiao_leftturn_right_tai0();
	xiao_leftturn_right_tai0_tiaozheng();
	xiao_leftturn_right_tai1();
	r_mai();
	r_luo0();
	r_luo1();
		jiance();
	l_second_tai0();
	l_second_tai1();



			/* 
	×ó¹ÕÈ2--´Î²¢¼ì²â*/
	go_flag=0;
}
void big_rightturn()
{
	xiao_rightturn_mai();
	xiao_rightturn_luo();
	xiao_rightturn_left_tai0();
	xiao_rightturn_left_tai0_tiaozheng();
	xiao_rightturn_left_tai1();
	l_mai();
	l_luo0();
	l_luo1();
	r_tai0();
	r_tai1();
	/*
ÓÒ×ªÒ»´Î	
	*/
	
	
//	xiao_rightturn_mai();
//	xiao_rightturn_luo();
//	xiao_rightturn_left_tai0();
//	xiao_rightturn_left_tai0_tiaozheng();
//	xiao_rightturn_left_tai1();
//	l_mai();
//	l_luo0();
//	l_luo1();
//	r_tai0();
//	r_tai1();
			//2
	xiao_rightturn_mai();
	xiao_rightturn_luo();
	xiao_rightturn_left_tai0();
	xiao_rightturn_left_tai0_tiaozheng();
	xiao_rightturn_left_tai1();
	l_mai();
	l_luo0();
	l_luo1();
	jiance();
	r_tai0();
	r_tai1();		
			/*
ÓÒ×ªÈý-´Î²¢¼ì²â	
	*/
	go_flag=1;
}
void x_left()
{
	x_l_mai();
	x_l_luo0();
	x_l_luo1();
	jiance();
	x_r_tai0();
	x_r_tai1();
	go_flag=1;

}

void x_right()
{
	x_r_mai();
	x_r_luo0();
	x_r_luo1();
	jiance();
	x_l_second_tai0();
	x_l_second_tai1();
	go_flag=0;

}
