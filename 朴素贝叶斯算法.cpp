 #include "stdio.h"
#include "stdlib.h"
#include "data.h"

#define m TRAIN_NUM//m-估计的m值等于训练样例数

//计算训练样例集的正样本数和负样本数
//输入训练样例集
//输出训练样例集的正样本数和负样本数
void CalcPosAndNegNum(int *pPosNum,int *pNegNum){
	int i;
	//取出训练样例
	//初始化为0
	*pPosNum=0;
	*pNegNum=0;
	
	for(i=0;i<TRAIN_NUM;i++){
		//trainSample为训练样例首地址，每个训练样本共有ATTR_NUM个属性
		//根据目标属性地址存储的yes或no值来增加pPosNum或pNegNum
		if(trainSample[i][ATTR_NUM]==yes){
			(*pPosNum)++;
		} 
		else{
			(*pNegNum)++;
		}
	}
	return; 
} 

//朴素贝叶斯学习器算法程序
void NaiveBayes(void){
	
//	int newSample[]={sunny,cool,high,strong};
//	int preP[]={(float)0.333,(float)0.333,(float)0.50,(float)0.50};
	int i,j,cntY,cntN;
	//存储训练样例目标属性为yes和no的样本数
	int posNum,negNum; 
	//存储目标值yes和no的概率
	float PVyes,PVno,PVyesTemp,PVnoTemp;
	//存储目标值为yes时需分类的每个属性的概率
	float PAttrYes[ATTR_NUM];
	//存储目标值为no时需分类的每个属性的概率
	float PAttrNo[ATTR_NUM];
	//计算训练样例集的正样本数和负样本数
	CalcPosAndNegNum(&posNum,&negNum);
	
	//计算目标值yes和no的概率
	PVyes=(float)posNum/(float)TRAIN_NUM;
	PVno=(float)negNum/(float)TRAIN_NUM; 
	//printf("%f,%f\n\n",PVyes,PVno);
	for(j=0;j<ATTR_NUM;j++){
		cntY=0;
		cntN=0;
		//计算训练样例中在yes或no的条件下目标实例属性发生的次数 
		for(i=0;i<TRAIN_NUM;i++){
			//统计目标值为yes时各个需分类的属性在训练样例中的个数
			if(trainSample[i][ATTR_NUM]==yes){
				//如果训练样例的目标属性是yes
				//并且该训练样例的属性值和需要分类的样例的属性值相等进行+1
				if(trainSample[i][j]==newSample[j]){
					cntY++;
				} 
			} 
			//统计目标值为no时各个需分类的属性在训练样例中的个数
			else if(trainSample[i][ATTR_NUM]==no){
				if(trainSample[i][j]==newSample[j]){
					cntN++; 
				}
			} 
		}
		//计算目标值为yes和no时需分类的各个属性的概率 
		PAttrYes[j]=((float)cntY+((float)m)*preP[j])/((float)(posNum+m));
		
		PAttrNo[j]=((float)cntN+((float)m)*preP[j])/((float)(negNum+m));
		//printf("%f,%f\n",PAttrYes[j],PAttrNo[j]);
		
	} 
	printf("\n"); 
	//分别计算需要分类的样例的目标值为yes和no的概率 
	for(i=0;i<ATTR_NUM;i++){
		PVyes=PVyes*PAttrYes[i];
		PVno=PVno*PAttrNo[i];
		//printf("%f,%f\n",PVyes,PVno);
	}
	
	//归一化处理
	PVyesTemp=PVyes/(PVyes+PVno); 
	PVnoTemp=PVno/(PVyes+PVno);
	//输出结果
	printf("数据的输入与定义在data文件中进行！\n\n");
	printf("对data数据进行贝叶斯处理后，对当前实例得出以下结论：\n");
	printf("实例分类为yes的概率：%f\n",PVyesTemp); 
	printf("实例分类为no的概率：%f\n",PVnoTemp);
	if(PVyesTemp>PVnoTemp){
		printf("实例被分类为：yes\n");
	} 
	else if(PVyesTemp-PVnoTemp<0.1){
		printf("历史数据暂时无法判断，请继续增加训练数据！\n");
	}
	else{
		printf("实例被分类为：no\n");
	}
	return;	 
} 

int main(void){
	NaiveBayes();
	return 0;
}
