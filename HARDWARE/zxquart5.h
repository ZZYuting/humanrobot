#ifndef __USART1_H
#define __USART1_H
#include <stm32f10x.h>
#include "stdio.h"	 
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//Mini STM32开发板
//串口1初始化		   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2010/5/27
//版本：V1.3
//版权所有，盗版必究。
//Copyright(C) 正点原子 2009-2019
//All rights reserved
//********************************************************************************
//V1.3修改说明 
//支持适应不同频率下的串口波特率设置.
//加入了对printf的支持
//增加了串口接收命令功能.
//修正了printf第一个字符丢失的bug
////////////////////////////////////////////////////////////////////////////////// 	  
 
	  	
extern u8 USART_RX_BUF[64];     //接收缓冲,最大63个字节.末字节为换行符 
extern u8 USART_RX_STA;		 //接收状态标记
//extern int x=0,y=0,f=0,z=0;        	

//如果想串口中断接收，请不要注释以下宏定义
#define EN_USART1_RX 1//使能串口1接收
void uart5_init(u32 bound);
void SetServoPosition(unsigned char id,unsigned short int position,unsigned short int velocity);
void SetServoLimit(unsigned char id,unsigned short int cw_limit,unsigned short int ccw_limit);
void Send_turn(u8 ch);
void zhuaqu(int x,int f,int z);
#endif	   