//训练样本:做好数据的采集后，根据数据设定相应的样本数、属性值 

/**************属性定义区***************/

//设定训练样本数：
#define TRAIN_NUM  20
//设定属性总数： 
#define ATTR_NUM 5

//定义属性

// A:起床时天气 
typedef enum A{ 
	A1,//下雨 
	A2,//晴朗 
	A3,//阴天 
	NUM_A=3
}A;

//B:昨晚入睡时间（11点-凌晨2点） 
typedef enum B{
	B1,//11：00-12：00 
	B2,//12：00-1：00 
	B3,//1：00-2：00 
	B4,//2：00-3：00 
	NUM_B=4
}B;

//C:次日上课时间(仅针对上午) 
typedef enum C{
	C1,//1-2
	C2,//3-4
	NUM_C=2
}C;

//D:实际起床时间 
typedef enum D{
	D1,//7：00-7：30 
	D2,//7：30-8:00 
	D3,//8：00-8：30 
	D4,//8：30-9: 00 
	NUM_D=4
}D;

//E:对应的课程 
typedef enum E{
	E1,//计算机组成原理 
	E2,//计算机操作系统 
	E3,//概论 
	E4,//英语 
	E5,//毛概 
	NUM_E=5
}E;

//相应条件下的决策 
typedef enum _targetAttribute{
	yes,
	no
}_targetAttribute;

//m-估计的每个属性对应的先验概率
float preP[ATTR_NUM]={1/(float)NUM_A,1/(float)NUM_B,1/(float)NUM_C,1/(float)NUM_D,1/(float)NUM_E};




/**************数据输入区域 ********************/ 

//存放训练样例的二维数组 
int trainSample[][ATTR_NUM+1]={
	{A1,B1,C1,D2,E4,no},
	{A3,B2,C2,D4,E5,no},
	{A1,B3,C1,D3,E1,no},
	{A2,B1,C1,D2,E4,no},
	{A3,B3,C2,D4,E5,yes},
	{A1,B3,C2,D3,E1,yes},
	{A1,B1,C1,D3,E4,no},
	{A3,B2,C2,D4,E1,yes},
	{A1,B3,C1,D3,E1,no},
	{A1,B1,C1,D2,E5,no},
	{A3,B2,C2,D3,E5,yes},
	{A1,B3,C2,D3,E1,yes},
	{A1,B2,C1,D2,E4,no},
	{A2,B2,C2,D4,E5,yes},
	{A1,B1,C1,D3,E1,yes},
	{A1,B1,C2,D2,E4,no},
	{A3,B2,C2,D1,E5,yes},
	{A1,B3,C1,D3,E2,yes},
	{A1,B1,C1,D2,E4,yes},
	{A3,B2,C2,D4,E1,yes},
}; 
 
 
 

/******************输入新实例*******************/

int newSample[ATTR_NUM]={A2,B3,C1,D4,E2};

